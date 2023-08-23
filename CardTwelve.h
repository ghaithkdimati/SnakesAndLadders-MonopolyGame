#pragma once
#include "Card.h"
class CardTwelve :public Card
{
public:
	CardTwelve(const CellPosition& cellposition);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid, Player* pPlayer);
	void Save(ofstream& OutFile, int Type);
	virtual void Load(ifstream& Infile);
};

