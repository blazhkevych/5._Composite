#include "Composite_PC.h"

#include <iostream>

using std::cout;
using std::endl;

// Стоимость.
int Composite_PC::Cost()
{
	int cost{10000};
	for (Component* component : m_components)
	{
		cost = cost + component->Cost();
	}
	return cost;
}

// Отобразить компонент.
void Composite_PC::Display()
{
	cout << m_name << endl;
	for (Component* component : m_components)
	{
		component->Display();
	}
}