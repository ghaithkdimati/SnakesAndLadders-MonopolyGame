#pragma once
#include"Card.h"
#include"Ladder.h"
class CardTwo : public Card
{

public:
	CardTwo(const CellPosition& cellposition);

	virtual void Apply(Grid* pGrid,Player*pPlayer);

	virtual void Save(ofstream& OutFile, int Type);

	virtual void Load(ifstream& Infile);
};

