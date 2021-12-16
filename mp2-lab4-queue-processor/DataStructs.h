#pragma once
struct Processor
{
	int taskId;		   //id выполняемой задачи
	int ccCount;	   //Всего тактов работы
	int waitingTime;   //Всего тактов простоя

	int ccOfTaskCount; //Число тактов - данная задача

	bool isWaiting;	   //Флаг - занят или свободен
};

struct Task
{
	int id;			   //id
	int procCount;	   //Число процессоров
	int ccTotal;	   //Общее число тактов
	int ccCompleted;   //Число выполненных тактов
};

struct Stat {
	//Текущая нагрузка
	int currentLoad = 0;
	//Выполняется задач
	int tasksActive = 0;

	//Суммарное число тактов работы (всех процессоров)
	int totalCCs = 0;
	//Суммарное число тактов простоя (всех процессоров)
	int totalWaitingCCs = 0;
	//Суммарно задач получено
	int tasksReceived = 0;
	//Суммарно задач выполнено
	int tasksCompleted = 0;
	//В среднем нагружено процессоров
	int averageLoad = 0;

	void Clear()
	{
		totalCCs = totalWaitingCCs = 0;
		tasksReceived = tasksCompleted = 0;
		averageLoad = 0;
	}
};