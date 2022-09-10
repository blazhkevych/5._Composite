#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Кофейный автомат.
class Leaf_CoffeeMachine : public Component
{
public:
	Leaf_CoffeeMachine(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(9000, 25000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};