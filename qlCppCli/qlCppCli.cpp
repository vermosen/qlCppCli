// qlCppCli.cpp : fichier projet principal.

#include "stdafx.h"

void writeConsole(String ^ message)
{
	Console::WriteLine(message);
}

int main(array<System::String ^> ^args)
{
	// a managed calendar !!
	qlCalendar ^ ptr = gcnew qlCalendar;

	// closest business date
	QuantLib::Date pricingDate = ptr->nextBusinessDay(QuantLib::Date::todaysDate());
	QuantLib::Calendar cdr = QuantLib::TARGET();

	// get the number of cores
	int coreNumber = Environment::ProcessorCount;

	writeLogDelegate ^ logDlg = gcnew writeLogDelegate(writeConsole);

	// create the listening thread
	writerThread ^ writer = gcnew writerThread(logDlg);

	// create the writing delegate
	writeDataBaseDelegate ^ writeDlg = gcnew writeDataBaseDelegate(writer, &writerThread::write);

	Thread ^ listener = gcnew Thread(gcnew ThreadStart(writer, &writerThread::work));

	listener->Start();

	// thread pool
	array<Thread ^> ^ pool = gcnew array < Thread ^>(coreNumber);

	for (int i = 0; i < coreNumber; i++)
	{
		pricingDate = cdr.advance(pricingDate, 1 * Days);
		pool[i] = gcnew Thread(gcnew ThreadStart(gcnew pricingThread(pricingDate, logDlg, writeDlg), &pricingThread::work));
		pool[i]->Start();
	}

	for (int i = 0; i < coreNumber; i++)
		pool[i]->Join();
	
	Console::ReadLine();
	return 0;

}
