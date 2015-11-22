#ifndef WRITER_THREAD_HPP
#define WRITER_THREAD_HPP

#include "stdafx.h"

#include <threads/workThread.hpp>

using namespace System;
using namespace System::Threading;

public delegate void writeDataBaseDelegate(String ^ str);

// TODO: replace waitone by a monitor and create some termination callback
public ref class writerThread : public workThread
{
public:
	writerThread(writeLogDelegate ^ log) : workThread(log) {}

	virtual void workImpl() override
	{
		// set the connection then wait for data

		// wait for 
		AutoResetEvent ^ autoEvent = gcnew AutoResetEvent(false);
		autoEvent->WaitOne();
	}

	// write some data in the database
	void write(String ^ data)
	{
		// write the database
		Console::WriteLine(data);
	}


private:
	
};

#endif