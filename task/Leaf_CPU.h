#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Процессор.
class Leaf_CPU : public Component
{
public:
	Leaf_CPU(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(12000, 50000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};