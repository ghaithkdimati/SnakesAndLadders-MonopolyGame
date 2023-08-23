#include "CardThree.h"
CardThree::CardThree(const CellPosition& cellposition) : Card(cellposition) {
	cardNumber = 3;
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->DecrementCurrPlayer();
	pGrid->PrintErrorMessage("You've reached card 3 ! You get another turn, click anywhere to continue...");
 }
void CardThree::Save(ofstream& OutFile, int Type)
{
	if (Type == 2) {
		Card::Save(OutFile, Type);
		OutFile << endl;
	}
}

void CardThree::Load(ifstream& Infile)
{
	Card::Load(Infile);
}