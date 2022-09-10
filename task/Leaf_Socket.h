#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Розетка.
class Leaf_Socket : public Component
{
public:
	Leaf_Socket(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(50, 1000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};