#ifndef MANAGED_CALENDAR_HPP
#define MANAGED_CALENDAR_HPP

#include <ql/time/date.hpp>
#include <ql/time/calendars/target.hpp>

ref class qlCalendar
{
public:

	qlCalendar()
	{
		c_ = new QuantLib::TARGET();
	}

	~qlCalendar()
	{
		delete c_;
	}

	bool isBusinessDay(const QuantLib::Date & dt)
	{
		return c_->isBusinessDay(dt);
	}

	QuantLib::Date nextBusinessDay(const QuantLib::Date & dt)
	{	
		return c_->adjust(dt, QuantLib::Following);
	}

private:
	QuantLib::Calendar * c_;

};
#endif