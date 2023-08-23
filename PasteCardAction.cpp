#include "PasteCardAction.h"
#include"AddCardAction.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{

}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("PasteCardAction: Click on the desired cell !");
	cardPos = pIn->GetCellClicked();
}
void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (cardPos.IsValidCell())
	{
		if (!pGrid->GetGameObjectOfCell(cardPos))
		{
			Card* Clip = pGrid->GetClipboard();
			Card  temp(cardPos);
			if ((bool)Clip)
			{
				Card* Pasted;
				switch (Clip->GetCardNumber())
				{

				case 1:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardOne(cardPos);
						temp = *Pasted;
						*((CardOne*)Pasted) = *((CardOne*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = (Card)temp;
						Clip->SetCardNumber(1);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 2:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardTwo(cardPos);
						temp = *Pasted;
						*((CardTwo*)Pasted) = *((CardTwo*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(2);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 3:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardThree(cardPos);
						temp = *Pasted;
						*((CardThree*)Pasted) = *((CardThree*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(3);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 4:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardFour(cardPos);
						temp = *Pasted;
						*((CardFour*)Pasted) = *((CardFour*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(4);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 5:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardFive(cardPos);
						temp = *Pasted;
						*((CardFive*)Pasted) = *((CardFive*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(5);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 6:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardSix(cardPos);
						temp = *Pasted;
						*((CardSix*)Pasted) = *((CardSix*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(6);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 7:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardSeven(cardPos);
						temp = *Pasted;
						*((CardSeven*)Pasted) = *((CardSeven*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(7);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 8:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardEight(cardPos);
						temp = *Pasted;
						*((CardEight*)Pasted) = *((CardEight*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(8);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 9:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardNine(cardPos);
						temp = *Pasted;
						*((CardNine*)Pasted) = *((CardNine*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(9);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 10:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardTen(cardPos);
						temp = *Pasted;
						*((CardTen*)Pasted) = *((CardTen*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(10);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 11:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardEleven(cardPos);
						temp = *Pasted;
						*((CardEleven*)Pasted) = *((CardEleven*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(11);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				case 12:
					if (pGrid->GetGameObjectOfCell(Clip->GetPosition()) == Clip)
					{
						Pasted = new CardTwelve(cardPos);
						temp = *Pasted;
						*((CardTwelve*)Pasted) = *((CardTwelve*)Clip);
						*Pasted = temp;
						if (!pGrid->AddObjectToCell(Pasted))
							delete Pasted;
					}
					else
					{
						*Clip = temp;
						Clip->SetCardNumber(12);
						pGrid->AddObjectToCell(Clip);
						pGrid->SetClipboard(nullptr);
						Card::SetCardCount(Card::GetCardCount() + 1);
					}
					break;
				}
			}
		}
		else
			pGrid->PrintErrorMessage("Invalid card position, click to continue...");
	}
	else pGrid->PrintErrorMessage("Invalid card position, click to continue...");
}