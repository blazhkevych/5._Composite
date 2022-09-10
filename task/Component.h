#pragma once

#include <string>

using std::string;

/*
 Component
	- объявляет интерфейс для компонуемых объектов.
	- предоставляет подходящую реализацию операций по умолчанию, общую для всех классов.
	- объявляет интерфейс для доступа к потомкам и управления ими.
	- определяет интерфейс для доступа к родителю компонента в рекурсивной структуре и при необходимости реализует его.
 */
class Component abstract
{
protected:
	// Имя компонента.
	string m_name;
public:
	Component(string name)
	{
		this->m_name = name;
	}

	//Добавление компонента.
	virtual void Add(Component* component) {}

	// Стоимость.
	virtual int Cost() abstract;

	// Отобразить компонент.
	virtual void Display() abstract;

	// Генерируем рандомное число между значениями min и max.
	// Предполагается, что функцию srand() уже вызывали.
	virtual int GetRandomNumber(int min, int max);
};