#include "GameObject.h"


GameObject::GameObject(const CellPosition& pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

bool GameObject::IsOverlapping(GameObject* newObj) const
{
	return false;
}

void GameObject::Save(ofstream& OutFile, int Type)
{
	if (this->position.GetCellNum() < 10) 
	{
		OutFile << this->position.GetCellNum() << "  ";
	}
	else 
	{
		OutFile << this->position.GetCellNum() << " ";
	}
}

GameObject::~GameObject()
{
}