#pragma once
#include "Randomex.h"
#include "DataStructs.h"
#include "..\mp2-lab4-queue\TQueue.h"

ref class ProcFarm
{
private:
	Randomex^ randomex;

	//Процессоры и их статистика
	int n;
	Processor* processors;
	Stat* stat;

	//Последний заданный id
	int lastTaskId = 0;

	//Очередь задач
	TQueue<Task>* qTasks = new TQueue<Task>(256);

public:
	ProcFarm(int _n)
	{
		randomex = gcnew Randomex();
		n = _n;
		processors = new Processor[n];
		stat = new Stat();
	}

	~ProcFarm()
	{
		delete[] processors;
		delete stat;
	}

	int GetCurrentLoad()
	{
		return stat->currentLoad;
	}

	int GetActiveTasksCount()
	{
		return stat->tasksActive;
	}

	int GetQueueTasksCount()
	{
		return qTasks->GetCount();
	}

	int GetTotalCCs()
	{
		return stat->totalCCs;
	}

	int GetTotalWaitingCCs()
	{
		return stat->totalWaitingCCs;
	}

	int GetReceivedTasksCount()
	{
		return stat->tasksReceived;
	}

	int GetCompletedTasksCount()
	{
		return stat->tasksCompleted;
	}

	int GetAverageLoad()
	{
		return stat->averageLoad;
	}

	int i = 0;

	void Tick(cli::array<System::Windows::Forms::Button^>^ procViews,
		System::Windows::Forms::DataGridView^ dgLogs,
		System::Windows::Forms::DataGridView^ dgActive,
		System::Windows::Forms::DataGridView^ dgQueue)
	{
		//Обновление прогресса текущих заданий на процессорах, удаление завершённых
		dgLogs->Rows->Add("Hello" + i);
		dgLogs->FirstDisplayedScrollingRowIndex = dgLogs->RowCount - 1;

		dgLogs->Rows[i]->DefaultCellStyle->ForeColor = Randomex::RandColor();

		i++;

		dgActive->Rows->Add("Hello" + i);
		dgActive->FirstDisplayedScrollingRowIndex = dgLogs->RowCount - 1;

		dgQueue->Rows->Add("Hello" + i);
		dgQueue->FirstDisplayedScrollingRowIndex = dgLogs->RowCount - 1;

		//Для случайного цвета


		for (int i = 0; i < n; i++)
		{
			if (processors[i].isWaiting)
			{
				stat->totalWaitingCCs++;
			}
			else
			{
				stat->currentLoad++;
				stat->totalCCs++;
			}
		}

		//Получение задания из очереди и обработка

		//Поступление нового с вероятностью P
		/*bool isNewTask = randomex->RandBool(newTaskP);
		if (isNewTask)
		{
			Task newTask{};
			newTask.id = ++lastTaskId;
			newTask.procCount = randomex->RandInt(minProcForTask, maxProcForTask);
			newTask.ccTotal = randomex->RandInt(minCC, maxCC);
			newTask.ccCompleted = 0;
			qTasks.Push(newTask);
			//TODO Insert to UI
		}*/
	}
};