#include "Composite_Board.h"

#include <iostream>

using std::cout;
using std::endl;

// Стоимость.
int Composite_Board::Cost()
{
	int cost{13000};
	for (Component* component : m_components)
	{
		cost = cost + component->Cost();
	}
	return cost;
}

// Отобразить компонент.
void Composite_Board::Display()
{
	cout << m_name << endl;
	for (Component* component : m_components)
	{
		component->Display();
	}
}