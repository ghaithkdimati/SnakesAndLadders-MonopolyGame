#include "OpenAction.h"
#include "NewGameAction.h"

#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

OpenAction::OpenAction(ApplicationManager* pApp) : Action(pApp) 
{

}

OpenAction::~OpenAction() 
{

}

void OpenAction::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please enter the name of the file you want to open...");
	FileName = pIn->GetSrting(pOut);
	FileName = FileName + ".txt";
	pOut->ClearStatusBar();
}

void OpenAction::Execute() 
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pManager->ExecuteAction(NEW_GAME);
	pGrid->ClearGridArea();
	CardNine::SetIsReadF();
	CardTen::SetIsReadF();
	CardEleven::SetIsReadF();
	ifstream GridOpen(FileName);
	if (GridOpen.is_open()) 
	{
		int numoflad;
		GridOpen >> numoflad;
		for (int i = 0; i < numoflad; i++)
		{
			Ladder* pLadder = new Ladder(CellPosition(0), CellPosition(0));
			pLadder->Load(GridOpen);
			pGrid->AddObjectToCell(pLadder);
		}
		int numofsnakes;
		GridOpen >> numofsnakes;
		for (int i = 0; i < numofsnakes; i++)
		{
			Snake* pSnake = new Snake(CellPosition(0), CellPosition(0));
			pSnake->Load(GridOpen);
			pGrid->AddObjectToCell(pSnake);
		}
		int numofCards;
		GridOpen >> numofCards;
		for (int i = 0; i < numofCards; i++)
		{
			int CardNum;
			Card* pCard;
			GridOpen >> CardNum;
			switch (CardNum) 
			{
			case 1:
				pCard = new CardOne(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 2:
				pCard = new CardTwo(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 3:
				pCard = new CardThree(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 4:
				pCard = new CardFour(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 5:
				pCard = new CardFive(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 6:
				pCard = new CardSix(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 7:
				pCard = new CardSeven(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 8:
				pCard = new CardEight(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 9:
				pCard = new CardNine(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 10:
				pCard = new CardTen(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 11:
				pCard = new CardEleven(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;

			case 12:
				pCard = new CardTwelve(0);
				pCard->Load(GridOpen);
				pGrid->AddObjectToCell(pCard);
				break;
			}
		}
		GridOpen.close();
	}

	else
		pGrid->PrintErrorMessage("Error: Could not Find the file!");
}

