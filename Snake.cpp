#include "Snake.h"
#include "Ladder.h"

int Snake::SnakeCount = 0;

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	SnakeCount++;
	///TODO: Do the needed validation

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	// 2- Apply the Snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}


bool Snake::IsOverlapping(GameObject* newObj) const 
{

	Snake* pSna = dynamic_cast <Snake*> (newObj);

	if (pSna) 
	{
		if (GetEndPosition().VCell() >= newObj->GetPosition().VCell() && GetPosition().VCell() <= newObj->GetPosition().VCell()) 
		{
			return true;
		}
		if (pSna->GetEndPosition().VCell() >= GetPosition().VCell() && pSna->GetPosition().VCell() <= GetPosition().VCell()) 
		{
			return true;
		}
	}

	Ladder* pLad = dynamic_cast<Ladder*>(newObj);
	if (pLad)
	{
		if (GetEndPosition().GetCellNum() == pLad->GetPosition().GetCellNum())
			return true;
		if (GetPosition().GetCellNum() == pLad->GetEndPosition().GetCellNum())
			return true;
	}
	return false;
}



CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}
int Snake::GetSnakeCount()
{
	return SnakeCount;
}


void Snake::Save(ofstream& OutFile, int Type)
{

	if (Type == 1) {
		GameObject::Save(OutFile, Type);
		//OutFile << this->GetPosition().GetCellNum() << " " << this->GetEndPosition().GetCellNum()<<endl;
		OutFile << this->GetEndPosition().GetCellNum() << endl;
	}
}

void Snake::Load(ifstream& Infile) 
{
	int StartPos, EndPos;
	Infile >> StartPos >> EndPos;
	this->position = CellPosition::GetCellPositionFromNum(StartPos);
	this->endCellPos = CellPosition::GetCellPositionFromNum(EndPos);
}



Snake::~Snake()
{
	SnakeCount--;
}
