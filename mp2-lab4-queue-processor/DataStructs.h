#pragma once
struct ProcInfo
{
	int taskId;     //id задачи
	int stepCount;  //Число тактов - всего
	int taskCount;  //Число тактов - данная задача
	int waitingTime;//Число тактов простоя

	bool waiting;   //Флаг - занят или свободен
};

struct TaskInfo
{
	int id;			//id
	int stepCount;	//Число сделанных тактов
	int allSteps;	//Общее число тактов
	int procCount;	//Число процессоров
};