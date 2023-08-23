#include "DeleteGameObject.h"

#include "Input.h"
#include "Output.h"
#include "GameObject.h"

DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp) {

}

DeleteGameObject:: ~DeleteGameObject() {

}
void DeleteGameObject::ReadActionParameters() {
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
void DeleteGameObject::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetGameObjectOfCell(Pos) == (GameObject*) pGrid->GetClipboard())
	{
		pGrid->SetClipboard(nullptr);
	}
	delete pGrid->RemoveObjectFromCell(Pos);

}
