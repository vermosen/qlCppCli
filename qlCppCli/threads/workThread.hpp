#ifndef WORK_THREAD_HPP
#define WORK_THREAD_HPP

#include "stdafx.h"

public ref class workThread abstract
{
protected:
	workThread() {}
	
	virtual ~workThread() {};

public: 
	void work()
	{
		// preliminary operations
		workImpl();
	}

protected:
	virtual void workImpl() = 0;

};

#endif