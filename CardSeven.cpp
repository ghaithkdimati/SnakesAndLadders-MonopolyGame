#include "CardSeven.h"


CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (1 here)
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{

}


void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();


	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	pOut->ClearStatusBar();

	pGrid->PrintErrorMessage("Restarts the game for the first player whose cell is after the current player in the grid. ");


	int changeCellNum = 0;
	int Diff = NumHorizontalCells * NumVerticalCells;
	int cellnumcurrplayer = pPlayer->GetCell()->GetCellPosition().GetCellNum();
	for (int i = 0; i < MaxPlayerCount; i++) {
		if (((pGrid->GetCellNumOfPlayer(i))) > cellnumcurrplayer) {
			if (pGrid->GetCellNumOfPlayer(i) - cellnumcurrplayer < Diff) {
				Diff = pGrid->GetCellNumOfPlayer(i) - cellnumcurrplayer;
				changeCellNum = pGrid->GetCellNumOfPlayer(i);
			}
		}
	}
	if (Diff != NumHorizontalCells * NumVerticalCells) {
		for (int i = 0; i < MaxPlayerCount; i++) {
			if (pGrid->GetCellNumOfPlayer(i) == changeCellNum) {
				pGrid->RestartPlayerWithNum(i);
			}
		}
	}
	else {
		pGrid->PrintErrorMessage("No Players Found...");
	}
}


void CardSeven::Save(ofstream& OutFile, int Type) 
{
	if (Type == 2) {
		Card::Save(OutFile, Type);
		OutFile << endl;

	}
}
void CardSeven::Load(ifstream& Infile)
{
	Card::Load(Infile);
}
