#include <iostream>
#include <string>
#include <ctime>
#include "helperTime.h"
#include <math.h>

#include "../../Constants/Structre/timeStructre.cpp"
using namespace std;



timeStructre helperTime::getCurrentTime()
{
	
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    
    timeStructre timeS = timeStructre();
    
    timeS.year = now->tm_year + 1900;
    timeS.month = now->tm_mon + 1;
    timeS.day = now->tm_mday;
    timeS.hour = now->tm_hour + 3;
    timeS.minute = now->tm_min;
    timeS.second = now->tm_sec;
    
    
    
    return timeS;

}

string helperTime::getSubstring(const std::string& str, size_t start, size_t end)
{
    return str.substr(start, end - start + 1);
}


int helperTime::substractStringTime(string x,string y){
	
	
	
	int year = stoi(getSubstring(x, 6, 9)) - stoi(getSubstring(y, 6, 9));
	int month = stoi(getSubstring(x, 3, 4)) - stoi(getSubstring(y, 3, 4));
	int day = stoi(getSubstring(x, 0,1)) - stoi(getSubstring(y, 0,1));
	
	year = year * 12 * 30;
	month = month * 30;
	
	day = day + month + year;
	
	
	
	return day;
	
}

string helperTime::structToString(timeStructre time){
	
	string day = to_string(time.day);
	string month = to_string(time.month);
	string year = to_string(time.year);
	
	return day+"-"+month+"-"+year;
	
}


void helperTime::makeTime(int second,int minute,int hour,int day,int month,int year)
{
    second = abs(second);
    minute = abs(minute);
    hour = abs(hour);
    day = abs(day);
    month = abs(month);
    year = abs(year);
    
    
    if(second > 59){
        minute = minute + (second / 60);
        second = (second % 60);
    }
    if(minute > 59){
        hour = hour + (minute / 60);
        minute = (minute % 60 );
    }
    if(hour > 23){
        day = day + (hour / 24);
        hour = (hour % 24 );
    }
    if(day > 30){
        month = month + (day / 30);
        day = (day % 30 );
    }
    
    cout<<second<<" - "<<minute<<" - "<<hour<<" - "<<day<<" - "<<month<<" - "<<year<<endl;
    
	
	tm tm;
	tm.tm_sec = second;
	tm.tm_min = minute;
	tm.tm_hour = hour ;
    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year- 1900;
    
    
    
//    time_t tt = gmtime(&tm);
//    
//    tm.tm_sec= tm.tm_sec + 2;
//    
//    time_t tta = timegm(&tm*);
//    
//    substractTime(tt,tta);
//    
//    cout<<showTime(tt);
    

}

void helperTime::substractTime(time_t a,time_t b){
    double seconds;
    
    seconds = difftime(a,b);

    printf ("%.f seconds since new year in the current timezone.\n", seconds);
    
}


//convert time_t to string
string helperTime::showTime(time_t tt){
    
    return ctime(&tt);
}






