#pragma once
#include"Card.h"

class CardFive : public Card
{

public:
	CardFive(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, int Type);
	virtual void Load(ifstream& Infile);
	virtual ~CardFive();

};
