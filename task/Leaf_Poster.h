#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Плакат.
class Leaf_Poster : public Component
{
public:
	Leaf_Poster(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(50, 250); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};