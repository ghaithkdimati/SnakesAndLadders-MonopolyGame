#include "Card.h"

int Card::CardCount = 0;

Card::Card(const CellPosition& pos) : GameObject(pos) // sets the cell position of the GameObject
{
	CardCount++;
}

void Card::SetCardNumber(int cnum)
{
	if (cnum >= 1 && cnum <= 12)
		cardNumber = cnum;      // needs validation
	else cardNumber = 2;
}
void Card::SetCardCount(int Count)
{
	CardCount = (Count >= 0)? Count: 0;
}
int Card::GetCardCount() 
{
	return CardCount;
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{
	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);
}

void Card::ReadCardParameters(Grid* pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer)
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click
	
	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& OutFile, int Type) 
{
	if (cardNumber < 10) {
		OutFile << this->cardNumber << "  ";
	}
	else {
		OutFile << this->cardNumber << " ";
	}
	OutFile << this->position.GetCellNum() << " ";
}

void Card::Load(ifstream& Infile)
{
	int StartPos;
	Infile >> StartPos;
	this->position = CellPosition::GetCellPositionFromNum(StartPos);
}

Card::~Card()
{
	CardCount--;
}
