#include "SaveGridAction.h"

#include"Grid.h"
#include "CardNine.h"
#include "CardEleven.h"
#include "CardTen.h"


SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp) 
{

}

SaveGridAction:: ~SaveGridAction() 
{

}

void SaveGridAction::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please enter the name of the file ...");
	FileName = pIn->GetSrting(pOut);
	FileName = FileName + ".txt";
	pOut->ClearStatusBar();
}

void SaveGridAction::Execute() 
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();

	ofstream GridSave(FileName);
	CardNine::SetIsSavedF();
	CardTen::SetIsSavedF();
	CardEleven::SetIsSavedF();

	GridSave << pGrid->GetLadderCount() << endl;
	pGrid->SaveAll(GridSave, 0);
	GridSave << pGrid->GetSnakeCount() << endl;
	pGrid->SaveAll(GridSave, 1);
	GridSave << pGrid->GetCardCount() << endl;
	pGrid->SaveAll(GridSave, 2);
	GridSave.close();
}

