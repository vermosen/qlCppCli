#ifndef PRICING_THREAD_HPP
#define PRICING_THREAD_HPP

#include "stdafx.h"

int QuantLib::sessionId(void)
{
	return System::Threading::Thread::CurrentThread->ManagedThreadId;
}

using namespace QuantLib;

// enable ql session

public ref class pricingThread : public workThread
{
public:
	pricingThread(const Date & pricingDate,
		writeLogDelegate ^ log,
		writeDataBaseDelegate ^ dlg);
	
	virtual void pricingThread::workImpl() override;

private:
	const Date & pricingDate_;
	writeDataBaseDelegate ^ dlg_ ;
};

#endif