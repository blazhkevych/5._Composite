#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Холодильник.
class Leaf_Fridge : public Component
{
public:
	Leaf_Fridge(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(9000, 45000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};