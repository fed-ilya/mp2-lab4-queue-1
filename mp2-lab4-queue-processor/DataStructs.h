#pragma once
struct Processor
{
	int taskId;		   //id выполняемой задачи
	int ccCount;	   //Всего тактов работы
	int ccWaiting;	   //Всего тактов простоя

	int ccOfTaskCount; //Тактов осталось по данной задаче

	bool isWaiting;	   //Флаг - занят или свободен
};

struct Task
{
	int id;			   //id
	int procCount;	   //Число процессоров
	int ccTotal;	   //Количество тактов для выполнения
};

struct Stat {
	//Текущая нагрузка
	int currentLoad = 0;
	//Выполняется задач
	int tasksActive = 0;
	//Задач в очереди
	int tasksQueue = 0;

	//Суммарное число тактов работы (всех процессоров)
	int totalCCs = 0;
	//Суммарное число тактов простоя (всех процессоров)
	int totalWaitingCCs = 0;
	//Суммарно задач получено
	int tasksReceived = 0;
	//Суммарно задач выполнено
	int tasksCompleted = 0;
	//В среднем нагружено процессоров
	double averageLoad = 0;
};