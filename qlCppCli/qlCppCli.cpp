// qlCppCli.cpp : fichier projet principal.

#include "stdafx.h"

#include <managedCalendar/managedCalendar.hpp>
#include <threads/writerThread.hpp>
#include <threads/pricingThread.hpp>

using namespace System;
using namespace System::Threading;

int main(array<System::String ^> ^args)
{
	// a calendar
	managedCalendar ^ ptr = gcnew managedCalendar;

	// closest business date
	QuantLib::Date pricingDate = ptr->nextBusinessDay(QuantLib::Date::todaysDate());

	// get the number of cores
	int coreNumber = Environment::ProcessorCount;
	
	// leaves one out
	coreNumber--;

	// create the listening thread
	writerThread ^ writer = gcnew writerThread();

	// create the xriting delegate
	writeDataBaseDelegate ^ dlg = gcnew writeDataBaseDelegate(writer, &writerThread::write);

	Thread ^ listener = gcnew Thread(gcnew ThreadStart(writer, &writerThread::work));

	listener->Start();

	// thread pool
	array<Thread ^> ^ pool = gcnew array < Thread ^ >(coreNumber);

	for (int i = 0; i < coreNumber; i++)
	{
		pool[i] = gcnew Thread(gcnew ThreadStart(gcnew pricingThread(pricingDate++, dlg), &pricingThread::work));
		pool[i]->Start();
	}

	for (int i = 0; i < coreNumber; i++)
		pool[i]->Join();
	
	Console::ReadLine();
	return 0;

}
