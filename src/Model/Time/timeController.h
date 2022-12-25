#ifndef timeController_H
#define timeController_H
#include <iostream>
#include <string>
#include <ctime>
#include "../../Constants/Structre/timeStructre.cpp"
using namespace std;




class timeController
{
	public:
		void setStartedTime(time_t start);
		void setLastChangedTime(time_t change);
		void setFinishTime(time_t finish);
		void setTimeAsStructure(timeStructre ltime);
		
		
	
		time_t getStartedTime();
		time_t getLastChangedTime();
		time_t getFinishTime();
		
		timeStructre localTime;
		
	private:
		//data members
		
		time_t startedTime;
		time_t lastChangedTime;
		time_t finishTime;
		
		
};

#endif
