#ifndef PRICING_THREAD_HPP
#define PRICING_THREAD_HPP

#include "stdafx.h"

#include <iostream>

#include <ql/time/date.hpp>
#include <ql/patterns/singleton.hpp>
#include <ql/settings.hpp>

#include <threads/workThread.hpp>
#include <threads/writerThread.hpp>

// enable ql session
int QuantLib::sessionId(void)
{
	return System::Threading::Thread::CurrentThread->ManagedThreadId;
}

public ref class pricingThread : public workThread
{
public:
	pricingThread(const QuantLib::Date & pricingDate, const writeDataBaseDelegate ^ dlg) : workThread()
	{
		// set the evalualuation date
		pricingDate_ = new QuantLib::Date(pricingDate);
	}

	virtual void workImpl() override
	{
		// set the evaluation date
		QuantLib::Settings::instance().evaluationDate() = *pricingDate_;

		Console::WriteLine(
			L"In thread " +
			System::Threading::Thread::CurrentThread->ManagedThreadId +
			L" the evaluation Date has been set to:");

		std::cout << QuantLib::Settings::instance().evaluationDate() << std::endl;

		// price
		
		// send the results
		System::String ^ res = gcnew System::String(L"toto");

		dlg_(res);

	}

private:
	QuantLib::Date * pricingDate_;
	writeDataBaseDelegate ^ dlg_;

};

#endif