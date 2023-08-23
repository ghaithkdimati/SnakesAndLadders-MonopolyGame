#pragma once


#include "Action.h"

#include <fstream>


class SaveGridAction : public Action
{

	string FileName;


public:

	SaveGridAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SaveGridAction(); // Virtual Destructor

};

