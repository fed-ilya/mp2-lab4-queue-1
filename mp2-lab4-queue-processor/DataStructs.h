#pragma once
struct Processor
{
	int taskId;		   //id выполняемой задачи
	int ccCount;	   //Число тактов - всего
	int ccForTaskCount;//Число тактов - данная задача
	int waitingTime;   //Число тактов простоя

	bool isWaiting;	   //Флаг - занят или свободен
};

struct Task
{
	int id;			//id
	int stepCount;	//Число сделанных тактов
	int allSteps;	//Общее число тактов
	int procCount;	//Число процессоров
};