#pragma once
#include"Card.h"
class CardFour :public Card
{
public:
   CardFour(const CellPosition& cellposition); 
   virtual void Apply(Grid* pGrid, Player* pPlayer);
   virtual void Save(ofstream& OutFile, int Type);
   virtual void Load(ifstream& Infile);

};

