#include "Player.h"
#include "GameObject.h"
int Player::EqualWallets = -1; // initializing it with -1 refers to that until now no players have the same amount of money

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	this->SetTurnsDisabled(0);
	// Make all the needed initialization or validations
	SetCell(pCell);

}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	
	// Make any needed validations
	if (this->wallet < 0)
	{
		this->wallet = 0;
	}
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::SetTurnCount(int t)
{
	if (t<5 && t>-1)
		turnCount = t;
	else
		turnCount = 0;
}

void Player::SetTurnsDisabled(int t) 
{
	TurnsDisabled = (t >= 0) ? t : 0;
}

int Player::getTurnsDisabled() const 
{
	return TurnsDisabled;
}

int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}

int Player::GetEqualWallets()const
{
	return EqualWallets;
}

int Player::getPlayerNum() const 
{
	return playerNum;
}

Player* Player::GetPoor(Player* P2)
{
	if (GetWallet() < P2->GetWallet())
		return this;
	else if (GetWallet() > P2->GetWallet())
		return P2;
	else // They have the same amount of money
	{
		EqualWallets = GetWallet();  
		return this;
	}
}

bool Player::IsEqualWallets()
{
	if (EqualWallets == -1)
		return false;
	else
	{
		EqualWallets = -1;
		return true;
	}
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Output* pOut = pGrid->GetOutput();
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	this->turnCount++;

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (this->turnCount == 4)
	{
		wallet += 10 * diceNumber;
		this->turnCount = 0;
		pOut->PrintMessage("Fourth time to roll ! Wallet increased by  " + to_string(10 * diceNumber));
		return;
	}

	// 3- Set the justRolledDiceNum with the passed diceNumber
	if (getTurnsDisabled() == 0)			
	{
		justRolledDiceNum = diceNumber;

		// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
		//    Using the appropriate function of CellPosition class to update "pos"

		CellPosition pos(pCell->GetCellPosition());
		pos.AddCellNum(diceNumber);
		
		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

		pGrid->UpdatePlayerCell(this, pos);
	     
		// 6- Apply() the game object of the reached cell (if any)

		if (pCell->GetCellPosition().GetCellNum()+justRolledDiceNum== 100)
		{
			pGrid->SetEndGame(true);
			pOut->PrintMessage("Game Finished, P("+to_string(playerNum)+ ") won!");
			pGrid->UpdatePlayerCell(this, 99);
		}

		CellPosition BeforeObj = pCell->GetCellPosition();
		GameObject* pObj = this->pCell->GetGameObject();
		if (pObj&&!pGrid->GetEndGame())
		{
			pObj->Apply(pGrid, this);
			while (BeforeObj.GetCellNum() != pCell->GetCellPosition().GetCellNum() && this->pCell->GetGameObject() != NULL)
			{
				pObj = this->pCell->GetGameObject();
				BeforeObj = pCell->GetCellPosition();
				pObj->Apply(pGrid, this);
			}
		}

		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)

	}
	else
	{
		pOut->PrintMessage("Dice roll prevented ! Wait for the next turn..");
		SetTurnsDisabled(TurnsDisabled - 1);

	}
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}