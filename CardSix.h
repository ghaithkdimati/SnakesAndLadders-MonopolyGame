#pragma once

#include "Card.h"

class CardSix : public Card
{
private:

	CellPosition CellToMoveTo;

public:

	CardSix(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, int Type);

	virtual void Load(ifstream& Infile);

	virtual ~CardSix(); // A Virtual Destructor

};

