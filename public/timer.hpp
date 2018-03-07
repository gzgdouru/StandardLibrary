#ifndef _TIMER_HPP
#define _TIMER_HPP

#include <chrono>
using namespace std;
using namespace std::chrono;

enum TimeType
{
	e_nan = 0,
	e_mic = 1,
	e_mil = 2,
	e_sec = 3,
	e_min = 4,
	e_hour = 5
};

class timer
{
public:
	timer(TimeType eType = e_sec) : 
		m_Begin(chrono::high_resolution_clock::now()),
		m_Type(eType)
	{

	}
	
	void reset()
	{
		m_Begin = chrono::high_resolution_clock::now();
	}

	int64_t elapsed() const
	{
		int64_t diff = -1;

		switch (m_Type)
		{
		case e_nan:
			diff = elapsed_nan();
			break;
		case e_mic:
			diff = elapsed_mic();
			break;
		case e_mil:
			diff = elapsed_mil();
			break;
		case e_sec:
			diff = elapsed_sec();
			break;
		case e_min:
			diff = elapsed_min();
			break;
		case e_hour:
			diff = elapsed_hour();
			break;
		default:
			cout << "不支持的输出类型!" << endl;
			break;
		}
		return diff;
	}

	int64_t elapsed_sec() const
	{
		return duration_cast<chrono::seconds>(high_resolution_clock::now() - m_Begin).count();
	}

	int64_t elapsed_mil() const
	{
		return duration_cast<chrono::milliseconds>(high_resolution_clock::now() - m_Begin).count();
	}

	int64_t elapsed_mic() const 
	{
		return duration_cast<chrono::microseconds>(high_resolution_clock::now() - m_Begin).count();
	}

	int64_t elapsed_nan() const
	{
		return duration_cast<chrono::nanoseconds>(high_resolution_clock::now() - m_Begin).count();
	}

	int64_t elapsed_min() const
	{
		return duration_cast<chrono::minutes>(high_resolution_clock::now() - m_Begin).count();
	}
	int64_t elapsed_hour() const
	{
		return duration_cast<chrono::hours>(high_resolution_clock::now() - m_Begin).count();
	}

private:
	time_point<chrono::high_resolution_clock> m_Begin;
	TimeType m_Type;
};

#endif // _TIMER_HPP