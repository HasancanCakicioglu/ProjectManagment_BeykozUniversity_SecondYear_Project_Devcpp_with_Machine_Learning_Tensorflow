#include <iostream>
#include <string>
#include <ctime>
#include "timeController.h"
#include "../../Constants/Structre/timeStructre.cpp"
using namespace std;




void timeController::setStartedTime(time_t start)
{
	
	startedTime = start;

}


void timeController::setLastChangedTime(time_t change)

{
	
	lastChangedTime = change;

}


void timeController::setFinishTime(time_t finish)

{
	
	finishTime = finish;

}

void timeController::setTimeAsStructure(timeStructre localTimee)

{
	
	localTime = localTimee;

}


time_t timeController::getStartedTime()

{
	
	return startedTime;

}

time_t timeController::getLastChangedTime()

{
	
	return lastChangedTime;

}


time_t timeController::getFinishTime()

{
	
	return finishTime;

}
