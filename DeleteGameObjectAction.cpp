#include "DeleteGameObjectAction.h"

#include "Input.h"
#include "Output.h"
#include "GameObject.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp) {

}

DeleteGameObjectAction:: ~DeleteGameObjectAction() {

}
void DeleteGameObjectAction::ReadActionParameters() {
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the object you want to delete...");
	Pos = pIn->GetCellClicked();
	if (Pos.IsValidCell()) {
		if (pGrid->GetGameObjectOfCell(Pos) == NULL) {
			pGrid->PrintErrorMessage("Error Cell Has No Object...");
		}
	}

	pOut->ClearStatusBar();
}
void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	delete pGrid->RemoveObjectFromCell(Pos);

}
