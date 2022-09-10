#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Умывальник.
class Leaf_WashBasin : public Component
{
public:
	Leaf_WashBasin(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(500, 3000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};