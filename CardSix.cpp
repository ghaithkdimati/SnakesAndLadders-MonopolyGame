#include "CardSix.h"




CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (1 here)
}


CardSix::~CardSix(void)
{
}


void CardSix::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// reads the cell that the player will move to after standing on the card

	pOut->PrintMessage("New CardSix: Click on the cell to move to  ...");
	CellToMoveTo = pIn->GetCellClicked();
	while (CellToMoveTo.GetCellNum() == this->position.GetCellNum()||!CellToMoveTo.IsValidCell()) 
	{
		pOut->PrintMessage("You cannot choose this cell, Try Again");
		CellToMoveTo = pIn->GetCellClicked();
	}

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{

	Output* pOut = pGrid->GetOutput();

	//  Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	pOut->ClearStatusBar();
	pGrid->PrintErrorMessage("Move to cell number : " + to_string(CellToMoveTo.GetCellNum())+" click to continue");
	// Move the player
	pGrid->UpdatePlayerCell(pPlayer, CellToMoveTo);
	
	GameObject* pObj = pPlayer->GetCell()->GetGameObject();
	if(pObj)
	{
		pObj->Apply(pGrid, pPlayer);
	}

}


void  CardSix::Save(ofstream& OutFile, int Type) 
{
	if (Type == 2) 
	{
		Card::Save(OutFile, Type);
		OutFile << this->CellToMoveTo.GetCellNum() << endl;
	}
}


void CardSix::Load(ifstream& Infile) 
{
	Card::Load(Infile);
	int CellNum;
	Infile >> CellNum;
	CellToMoveTo = CellPosition::GetCellPositionFromNum(CellNum);
}
