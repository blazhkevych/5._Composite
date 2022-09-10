#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// HDD.
class Leaf_HDD : public Component
{
public:
	Leaf_HDD(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(900, 10000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};