#ifndef helperTime_H
#define helperTime_H
#include <iostream>
#include <string>
#include <ctime>
#include "../../Constants/Structre/timeStructre.cpp"
using namespace std;



class helperTime
{
	public:
		timeStructre getCurrentTime();
		void makeTime(int second,int minute,int hour,int month,int day,int year);
		string showTime(time_t tt);
		void substractTime(time_t a,time_t b);
		int substractStringTime(string x,string y);
		string getSubstring(const std::string& str,size_t start, size_t end);
		string structToString(timeStructre time);

		
		
};

#endif
