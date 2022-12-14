#include "Composite_Reception.h"

#include <iostream>

using std::cout;
using std::endl;

// Стоимость.
int Composite_Reception::Cost()
{
	int cost{};
	for (Component* component : m_components)
	{
		cost = cost + component->Cost();
	}
	return cost;
}

// Отобразить компонент.
void Composite_Reception::Display()
{
	cout << m_name << endl;
	for (Component* component : m_components)
	{
		component->Display();
	}
}