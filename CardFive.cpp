#include "CardFive.h"

#include "Player.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos)
{
	cardNumber = 5;
}

CardFive::~CardFive()
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Card::Apply(pGrid, pPlayer);
	pOut->PrintMessage("Move backward with the rolled dice number...");
	CellPosition NewPosition = pPlayer->GetCell()->GetCellPosition();
	NewPosition.AddCellNum(-2 * pPlayer->GetjustRolledDiceNum());
	
	pGrid->UpdatePlayerCell(pPlayer, NewPosition);
}

void CardFive::Save(ofstream& OutFile, int Type)
{
	if (Type == 2) {
		Card::Save(OutFile, Type);
		OutFile << endl;
	}
}


void CardFive::Load(ifstream& Infile)
{
	Card::Load(Infile);
}