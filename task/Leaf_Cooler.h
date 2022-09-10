#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Кулер с теплой и холодной водой.
class Leaf_Cooler : public Component
{
public:
	Leaf_Cooler(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(12000, 50000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};