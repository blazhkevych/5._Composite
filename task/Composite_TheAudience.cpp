#include "Composite_TheAudience.h"

#include <iostream>

using std::cout;
using std::endl;

// Стоимость.
int Composite_TheAudience::Cost()
{
	int cost{};
	for (Component* component : m_components)
	{
		cost = cost + component->Cost();
	}
	return cost;
}

// Отобразить компонент.
void Composite_TheAudience::Display()
{
	cout << m_name << endl;
	for (Component* component : m_components)
	{
		component->Display();
	}
}