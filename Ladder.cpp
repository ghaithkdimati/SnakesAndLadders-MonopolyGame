#include "Ladder.h"
#include "Snake.h"


int Ladder::LadderCount = 0;

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	LadderCount++;
	///TODO: Do the needed validation

}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}
int Ladder::GetLadderCount()
{
	return LadderCount;
}


bool Ladder::IsOverlapping(GameObject* newObj) const 
{
	Ladder* pLad = dynamic_cast<Ladder*>(newObj);
	if (pLad) 
	{
		if (pLad->GetEndPosition().VCell() <= GetPosition().VCell() && pLad->GetPosition().VCell() >= GetPosition().VCell()) 
		{
			return true;
		}
		if (GetEndPosition().VCell() <= newObj->GetPosition().VCell() && GetPosition().VCell() >= newObj->GetPosition().VCell()) 
		{
			return true;
		}
	}

	Snake* pSna = dynamic_cast<Snake*>(newObj);
	if (pSna)
	{
		if (GetEndPosition().GetCellNum() == pSna->GetPosition().GetCellNum())
			return true;
		if (GetPosition().GetCellNum() == pSna->GetEndPosition().GetCellNum())
			return true;
	}
	return false;
}

void Ladder::Save(ofstream& OutFile, int Type) 
{

	if (Type == 0) {
		GameObject::Save(OutFile, Type);
		OutFile << this->GetEndPosition().GetCellNum() << endl;

	}

}

void Ladder::Load(ifstream& Infile)
{
	int StartPos, EndPos;
	Infile >> StartPos >> EndPos;
	this->position = CellPosition::GetCellPositionFromNum(StartPos);
	this->endCellPos = CellPosition::GetCellPositionFromNum(EndPos);
}



Ladder::~Ladder()
{
	LadderCount--;
}