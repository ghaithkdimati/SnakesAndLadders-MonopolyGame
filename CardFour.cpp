#include "CardFour.h"

CardFour::CardFour(const CellPosition& cellposition) : Card(cellposition){
	cardNumber = 4;
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer) {
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You've reached card 4 ! prevents you from rolling next turn...");
	pPlayer->SetTurnsDisabled(1);

}
void CardFour::Save(ofstream& OutFile, int Type)
{
	if (Type == 2) {
		Card::Save(OutFile, Type);
		OutFile << endl;
	}
}

void CardFour::Load(ifstream& Infile)
{
	Card::Load(Infile);
}