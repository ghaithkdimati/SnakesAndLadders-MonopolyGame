#pragma once

#include "Action.h"
#include"Card.h"

class PasteCardAction : public Action
{
	CellPosition cardPos;
public:
	PasteCardAction(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();

};
