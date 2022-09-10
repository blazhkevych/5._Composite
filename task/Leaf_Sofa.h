#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Диван.
class Leaf_Sofa : public Component
{
public:
	Leaf_Sofa(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(5000, 25000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};