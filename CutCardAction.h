#pragma once
#include "Action.h"
#include"Card.h"
class CutCardAction :  public Action
{
	CellPosition cardPos;
public:
	CutCardAction(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
};

