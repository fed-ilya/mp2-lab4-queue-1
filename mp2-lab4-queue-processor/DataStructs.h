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
	int ccTotal;	   //Общее число тактов
	int procCount;	   //Число процессоров

	int ccCompleted;   //Число сделанных тактов
};

struct Stat {

};