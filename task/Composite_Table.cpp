#include "Composite_Table.h"

#include <iostream>

using std::cout;
using std::endl;

// Стол.
int Composite_Table::Cost()
{
	int cost{1000};
	for (Component* component : m_components)
	{
		cost = cost + component->Cost();
	}
	return cost;
}

// Отобразить компонент.
void Composite_Table::Display()
{
	cout << m_name << endl;
	for (Component* component : m_components)
	{
		component->Display();
	}
}