#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Оперативная память.
class Leaf_RAM : public Component
{
public:
	Leaf_RAM(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(700, 5000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};