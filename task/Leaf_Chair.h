#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Стул.
class Leaf_Chair : public Component
{
public:
	Leaf_Chair(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(200, 30000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};