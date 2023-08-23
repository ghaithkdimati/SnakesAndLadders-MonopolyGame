#include "InputDiceValueAction.h"
#include "Grid.h"

#include "Player.h"


InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
	
}

InputDiceValueAction::~InputDiceValueAction()
{
}


void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Input Dice Value: Enter Dice Value...");
	bool Test = false;
	while (!Test)
	{
	InputNumber = pIn->GetInteger(pOut);
	if (InputNumber > 6 || InputNumber < 1)
		pOut->PrintMessage("Input Dice Value: You entered invalid Dice value try another one...");
	else
		Test = true;
	}
	pOut->ClearStatusBar();
}

void InputDiceValueAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	ReadActionParameters();

	if (!pGrid->GetEndGame())
	{
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pPlayer->Move(pGrid, InputNumber);

		pGrid->AdvanceCurrentPlayer();

	}
	else
		pOut->PrintMessage("Game Finished");
}



