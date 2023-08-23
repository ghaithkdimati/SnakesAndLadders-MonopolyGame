#include "CutCardAction.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{

}
void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("CutCardAction: Click on the source card !");
	cardPos = pIn->GetCellClicked();
}
void CutCardAction::Execute()
{
		ReadActionParameters();
	if (cardPos.IsValidCell())
	{
		Grid* pGrid = pManager->GetGrid();
		if (pGrid->GetClipboard())
			if (pGrid->GetGameObjectOfCell(pGrid->GetClipboard()->GetPosition()) != pGrid->GetClipboard())
			{
				pGrid->AddObjectToCell(pGrid->GetClipboard());
				pGrid->SetClipboard(nullptr);
			}
		GameObject* pObj = pGrid->GetGameObjectOfCell(cardPos);
		if (dynamic_cast<Card*>(pObj))
		{
			pObj = pGrid->RemoveObjectFromCell(cardPos);
			pGrid->SetClipboard((Card*)pObj);
			Card::SetCardCount(Card::GetCardCount() -1);
			pGrid->PrintErrorMessage("Cut to clipboard, click to continue...");
		}
	}
}