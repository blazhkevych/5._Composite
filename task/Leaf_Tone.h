#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Тон.
class Leaf_Tone : public Component
{
public:
	Leaf_Tone(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(1000, 3000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};