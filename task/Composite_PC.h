#pragma once

#include "Component.h"

#include <vector>

using std::vector;

// Компьютер.
class Composite_PC : public Component
{
	vector <Component*> m_components;
public:
	Composite_PC(string name) :Component(name) {	}

	//Добавление компонента.
	void Add(Component* component) override
	{
		m_components.push_back(component);
	}

	// Стоимость массива компонентов.
	int Cost() override;

	// Отобразить компонент.
	void Display() override;
};