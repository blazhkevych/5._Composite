#pragma once

#include "Component.h"

#include <iostream>

using std::cout;
using std::endl;

// Офисный инструментарий.
class Leaf_OfficeToolkit : public Component
{
public:
	Leaf_OfficeToolkit(string name) : Component(name) {}

	// Стоимость.
	int Cost() override { return GetRandomNumber(30, 10000); }

	// Отобразить компонент.
	void Display() override
	{
		cout << m_name << endl;
	}
};