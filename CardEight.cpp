#include"CardEight.h"

CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
	cardNumber = 8;
	Amount = 0;
}

CardEight::~CardEight()
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New CardEight: Enter its amount ...");
	int Coins;
	bool Test = false;
	
	do
	{
		Coins = pIn->GetInteger(pOut);
		if (!(Coins > 0)) 
		{
			pOut->PrintMessage("Invalid number try again...");
		}
		else
		{
			Test = true;
			Amount = Coins;
		}
	} while (!Test);

	pOut->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);

	if (pPlayer->GetWallet() < Amount)
	{
		pOut->PrintMessage("Not enough coins! Go to prison");
		pPlayer->SetTurnsDisabled(3);
		return;
	}

	pOut->PrintMessage("Now choose whether paying " + to_string(Amount) + "coins (type 1) or going to prison(type 2)...");
	int Choice;
	bool Test = false;
	Choice = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();

	do
	{
		switch (Choice)
		{
		case 1:
		{
			pPlayer->SetWallet(pPlayer->GetWallet() - Amount);
			Test = true;
		}
		break;

		case 2:
		{
			pPlayer->SetTurnsDisabled(3);
			Test = true;
		}
		break;

		default:
		{
			pOut->PrintMessage("Invalid number try again...");
			Choice = pIn->GetInteger(pOut);
		}
		break;
		}

	} while (!Test);

}


void CardEight::Save(ofstream& OutFile, int Type)
{
	if (Type == 2)
	{
		Card::Save(OutFile, Type);
		OutFile << Amount << endl;
	}
}


void CardEight::Load(ifstream& Infile)
{
	Card::Load(Infile);
	Infile >> Amount;
}
