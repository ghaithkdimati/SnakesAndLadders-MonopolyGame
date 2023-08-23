#pragma once
#include "Card.h"
class CardNine : public Card
{
	static int CardPrice;
	static int Fees;
	static Player* Owner;
	static bool IsSaved;
	static bool IsRead;
	static int NumberOfCards;
public:
	CardNine(const CellPosition & cellposition);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid,Player* pPlayer);
	Player* GetOwner();
	void SetOwner(Player* pNew);
	int GetCardPrice();
	virtual void Save(ofstream& OutFile, int Type);
	virtual void Load(ifstream& Infile);
	void static SetIsSavedF();
	void static SetIsReadF();
	~CardNine();
};

