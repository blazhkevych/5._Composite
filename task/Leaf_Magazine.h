#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Журнал.
class Leaf_Magazine : public Component
{
public:
	Leaf_Magazine(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(30, 150); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};