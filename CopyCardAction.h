#pragma once

#include "Action.h"
#include"Card.h"

class CopyCardAction : public Action
{  
	CellPosition cardPos;
public:
	CopyCardAction(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();

};
