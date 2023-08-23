#pragma once

#include "Action.h"

#include <fstream>

class OpenAction : public Action
{
	string FileName;

public:

	OpenAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~OpenAction(); // Virtual Destructor
};

