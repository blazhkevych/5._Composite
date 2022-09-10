/*
						Composite
	Требуется реализовать программу для организации, которая
занимается обустройством офисов.
	Приложение должно предлагать клиенту организации составить
список необходимых в офисе предметов в виде дерева, после чего
организация, которая занимается обустройством офисов, произведет
расчёт суммарной стоимости всех предметов офиса.
	Пример списка, который составил пользователь.
1. Приемная																   1. Reception
		a. Должна быть выполнена в теплых тонах							   a. Should be done in warm colors
		b. Журнальный столик											   b. Coffee table
				i. 10-20 журналов типа «компьютерный мир»				   i. 10-20 magazines like "computer world"
		c. Мягкий диван													   c. Soft sofa
		d. Стол секретаря												   d. Secretary's desk
				i. Компьютер											   i. Computer
						1. Важно наличие большого объема жесткого диска	   1. It is important to have a large hard drive
				ii. Офисный инструментарий								   ii. office toolkit
		e. Кулер с теплой и холодной водой								   e. Cooler with warm and cold water
2. Аудитория 1															   2. Audience 1
		a. 10 столов													   a. 10 tables
		b. Доска														   b. Board
		c. Стол учителя													   c. Teacher's table
				i. Компьютер											   i. A computer
		d. Плакаты великих математиков									   d. Posters of great mathematicians
3. Аудитория 2															   3. Audience 2
		a. 20 столов													   a. 20 tables
				i. Столы черного цвета									   i. Black tables
				ii. Столы выставлены в овал или круг					   ii. Tables are set in an oval or circle
		b. Доска														   b. Board
		c. Мягкий диван													   c. Soft sofa
4. Компьютерная аудитория												   4. Computer room
		a. 10 компьютерных столов										   a. 10 computer tables
				i. Компьютер на каждом столе							   i. Computer on every table
						1. Процессор 2.2ГРц								   1. Processor 2.2GHz
						2. Винчестер на 80ГБ							   2. Winchester 80GB
						3. Оперативная память 1024МБ					   3. RAM 1024MB
				ii. Розетка возле каждого стола							   ii. Power outlet at every table
		b. Доска														   b. Board
				i. Набор разноцветных маркеров							   i. Set of multi-colored markers
5. Столовая																   5. Dining room
		a. Кофейный автомат												   a. Coffee machine
		b. Стол															   b. Table
				i. 4 стула												   i. 4 chairs
		c. Холодильник													   c. Fridge
		d. Умывальник													   d. Wash basin
	Каждый пункт списка будет объектом, который может содержать
внутри себя дочерний элемент.
	Для разработки архитектуры приложения необходимо
использовать паттерн «Composite».
	Кроме того, в объекты списка следует добавить поля, которые
будут отвечать за цену этого элемента.
*/

#include <iostream>
#include <Windows.h>

#include "Composite_Board.h"
#include "Composite_PC.h"
#include "Composite_Reception.h"
#include "Composite_Table.h"
#include "Composite_TheAudience.h"
#include "Leaf_Chair.h"
#include "Leaf_CoffeeMachine.h"
#include "Leaf_Cooler.h"
#include "Leaf_CPU.h"
#include "Leaf_Fridge.h"
#include "Leaf_HDD.h"
#include "Leaf_Magazine.h"
#include "Leaf_OfficeToolkit.h"
#include "Leaf_Poster.h"
#include "Leaf_RAM.h"
#include "Leaf_Socket.h"
#include "Leaf_Sofa.h"
#include "Leaf_Tone.h"
#include "Leaf_WashBasin.h"

/*
 *  Паттерн проектирования, объединяет объекты в древовидную структуру для представления иерархии от частного к целому.
 *  Позволяет клиентам единообразно трактовать индивидуальные и составные объекты.
	Паттерн определяет иерархию классов, которые могут состоять из примитивных и сложных объектов, упрощает архитектуру клиента,
 *  делает процесс добавления новых видов объекта более простым.
 *
 *  Одна из целей паттерна компоновщик - избавить клиентов от необходимости знать, работают ли они с листовым или составным объектом.
 *  Для достижения этой цели класс Component должен сделать как можно больше операций общими для классов Composite и Leaf.
 *  Обычно класс Component предоставляет для этих операций реализации по умолчанию, а подклассы Composite и Leaf замещают их.
 *
 * Результаты:
 * - определяет иерархии классов, состоящие из примитивных и составных объектов.
 * - упрощает архитектуру клиента.
 * - облегчает добавление новых видов компонентов.
 * - способствует созданию общего дизайна.
*/

// Генерируем рандомное число между значениями min и max.
// Предполагается, что функцию srand() уже вызывали.
int GetRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне.
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
	/*
	Composite:
Приемная		 Reception
Аудитория		 The audience
Стол			 Table
Компьютер		 A computer
Кулер			 Cooler
Доска			 Board

	Leaf:
Тон					   Tone
Журнал				   Magazine
Плакат				   Poster
HDD					   HDD
Диван				   Sofa
Процессор			   CPU
Оперативная память	   RAM
Розетка				   Socket
Кофейный автомат	   Coffee machine
Стул				   Chair
Холодильник			   Fridge
Умывальник			   Wash basin
Офисный инструментарий	office toolkit
 */

	SetConsoleOutputCP(1251);
	/*
	Задает выходную кодовую страницу, используемую консолью, связанной с вызывающим процессом.
	Консоль использует свою кодовую страницу вывода для преобразования символьных значений,
	записанных различными функциями вывода, в изображения, отображаемые в окне консоли.
	*/

	srand(static_cast<unsigned int>(time(0)));

	// 1. Приемная.
	{
		/*
		 1. Приемная													   1. Reception
		a. Должна быть выполнена в теплых тонах							   a. Should be done in warm colors
		b. Журнальный столик											   b. Coffee table
				i. 10-20 журналов типа «компьютерный мир»				   i. 10-20 magazines like "computer world"
		c. Мягкий диван													   c. Soft sofa
		d. Стол секретаря												   d. Secretary's desk
				i. Компьютер											   i. Computer
						1. Важно наличие большого объема жесткого диска	   1. It is important to have a large hard drive
				ii. Офисный инструментарий								   ii. office toolkit
		e. Кулер с теплой и холодной водой								   e. Cooler with warm and cold water
		 */

		 /* 1. Приемная.*/
		Component* composite_reception = new Composite_Reception("1. Приемная:");
		/* a. Должна быть выполнена в теплых тонах.*/
		composite_reception->Add(new Leaf_Tone("a. Теплые тона."));
		/* b. Журнальный столик.*/
		Component* composite_coffeetable = new Composite_Table("b. Журнальный столик.");
		/* i. 10 - 20 журналов типа «компьютерный мир».*/
		int random = GetRandomNumber(10, 20);
		for (int i = 0; i < random; i++)
			composite_coffeetable->Add(new Leaf_Magazine("\ti. 10 - 20 журналов типа «компьютерный мир»."));
		composite_reception->Add(composite_coffeetable);
		/* c. Мягкий диван.*/
		composite_reception->Add(new Leaf_Sofa("c. Мягкий диван."));
		/* d. Стол секретаря.*/
		Component* composite_secretarysdesk = new Composite_Table("d. Стол секретаря.");
		/* i. Компьютер.*/
		Component* composite_computer = new Composite_PC("\ti. Компьютер.");
		/* 1. Важно наличие большого объема жесткого диска.*/
		composite_computer->Add(new Leaf_HDD("\t\t1. Важно наличие большого объема жесткого диска."));
		composite_secretarysdesk->Add(composite_computer);
		/* ii. Офисный инструментарий.*/
		composite_secretarysdesk->Add(new Leaf_OfficeToolkit("\tii. Офисный инструментарий."));
		composite_reception->Add(composite_secretarysdesk);
		/* e. Кулер с теплой и холодной водой.*/
		composite_reception->Add(new Leaf_Cooler("Кулер с теплой и холодной водой."));

		composite_reception->Display();
		cout << endl << "Итоговая стоимость: " << composite_reception->Cost();
		cout << endl << "###########################################################################" << endl;
	}

	// 2. Аудитория 1.
	{
		/*
		2. Аудитория 1													   2. Audience 1
		a. 10 столов													   a. 10 tables
		b. Доска														   b. Board
		c. Стол учителя													   c. Teacher's table
				i. Компьютер											   i. A computer
		d. Плакаты великих математиков									   d. Posters of great mathematicians*/

		// 2. Аудитория 1.
		Component* composite_theaudience_1 = new Composite_TheAudience("2. Аудитория 1:");
		// a. 10 столов.
		for (int i = 0; i < 10; i++)
			composite_theaudience_1->Add(new Composite_Table("a. 10 столов."));
		// b. Доска.
		composite_theaudience_1->Add(new Composite_Board("b. Доска"));
		// c. Стол учителя.
		Component* composite_table = new Composite_Table("c. Стол учителя.");
		// i. Компьютер.
		composite_table->Add(new Composite_PC("\ti. Компьютер."));
		composite_theaudience_1->Add(composite_table);
		// d. Плакаты великих математиков.
		composite_theaudience_1->Add(new Leaf_Poster("d. Плакаты великих математиков."));

		composite_theaudience_1->Display();
		cout << endl << "Итоговая стоимость: " << composite_theaudience_1->Cost();
		cout << endl << "###########################################################################" << endl;
	}

	// 3. Аудитория 2.
	{
		/*3. Аудитория 2												   3. Audience 2
		a. 20 столов													   a. 20 tables
				i. Столы черного цвета									   i. Black tables
				ii. Столы выставлены в овал или круг					   ii. Tables are set in an oval or circle
		b. Доска														   b. Board
		c. Мягкий диван													   c. Soft sofa*/

		// 3. Аудитория 2.
		Component* composite_theaudience_2 = new Composite_TheAudience("3. Аудитория 2:");
		// a. 20 столов.
		// i. Столы черного цвета.
		// ii. Столы выставлены в овал или круг.
		for (int i = 0; i < 20; i++)
		{
			composite_theaudience_2->Add(new Composite_Table("\ti. Столы черного цвета."));
			composite_theaudience_2->Add(new Composite_Table("\tii. Столы выставлены в овал или круг."));
		}
		// b. Доска.
		composite_theaudience_2->Add(new Composite_Board("b. Доска"));
		// c. Мягкий диван.
		composite_theaudience_2->Add(new Leaf_Sofa("c. Мягкий диван."));

		composite_theaudience_2->Display();
		cout << endl << "Итоговая стоимость: " << composite_theaudience_2->Cost();
		cout << endl << "###########################################################################" << endl;
	}

	// 4. Компьютерная аудитория.
	{
		/*4. Компьютерная аудитория										   4. Computer room
		a. 10 компьютерных столов										   a. 10 computer tables
				i. Компьютер на каждом столе							   i. Computer on every table
						1. Процессор 2.2ГРц								   1. Processor 2.2GHz
						2. Винчестер на 80ГБ							   2. Winchester 80GB
						3. Оперативная память 1024МБ					   3. RAM 1024MB
				ii. Розетка возле каждого стола							   ii. Power outlet at every table
		b. Доска														   b. Board
				i. Набор разноцветных маркеров							   i. Set of multi-colored markers
		*/

		//4. Компьютерная аудитория.				
		Component* computer_audience_3 = new Composite_TheAudience("3. Аудитория 2:");
		// a. 10 компьютерных столов.	
			// i.Компьютер на каждом столе.
		for (int i = 0; i < 10; i++)
		{
			Component* composite_pc = new Composite_PC("\tКомпьютер на каждом столе.");
			// 1. Процессор 2.2ГРц.				
			composite_pc->Add(new Leaf_CPU("\t\t1. Процессор 2.2ГРц."));
			// 2. Винчестер на 80ГБ.				
			composite_pc->Add(new Leaf_HDD("\t\t2. Винчестер на 80ГБ."));
			// 3. Оперативная память 1024МБ.	
			composite_pc->Add(new Leaf_RAM("\t\t3. Оперативная память 1024МБ"));
			Component* composite_table = new Composite_Table("Компьютерный стол.");
			composite_table->Add(composite_pc);
			// ii.Розетка возле каждого стола.
			composite_table->Add(new Leaf_Socket("\tii.Розетка возле каждого стола."));
			computer_audience_3->Add(composite_table);
		}
		// b.Доска.
		Component* composite_board = new Composite_Board("b. Доска.");
		// i. Набор разноцветных маркеров.
		composite_board->Add(new Leaf_OfficeToolkit("i. Набор разноцветных маркеров."));
		computer_audience_3->Add(composite_board);

		computer_audience_3->Display();
		cout << endl << "Итоговая стоимость: " << computer_audience_3->Cost();
		cout << endl << "###########################################################################" << endl;
	}

	// 5. Столовая.
	{
		/*5. Столовая													   5. Dining room
		a. Кофейный автомат												   a. Coffee machine
		b. Стол															   b. Table
				i. 4 стула												   i. 4 chairs
		c. Холодильник													   c. Fridge
		d. Умывальник													   d. Wash basin
		*/

		// 5. Столовая.													 
		Component* composite_theaudience_4 = new Composite_TheAudience("5. Столовая:");
		// a. Кофейный автомат.										
		composite_theaudience_4->Add(new Leaf_CoffeeMachine("a. Кофейный автомат."));
		// b. Стол.													
		Component* composite_table = new Composite_Table("b. Стол.");
		// i. 4 стула.											 
		for (int i = 0; i < 4; i++)
		{
			composite_table->Add(new Leaf_Chair("\ti. 4 стула."));
		}
		composite_theaudience_4->Add(composite_table);
		// c. Холодильник.										
		composite_theaudience_4->Add(new Leaf_Fridge("c. Холодильник."));
		// d. Умывальник.
		composite_theaudience_4->Add(new Leaf_WashBasin("d. Умывальник."));


		composite_theaudience_4->Display();
		cout << endl << "Итоговая стоимость: " << composite_theaudience_4->Cost();
		cout << endl << "###########################################################################" << endl;
	}
}