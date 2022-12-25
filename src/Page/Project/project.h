#ifndef ProjectMonitoring_H
#define ProjectMonitoring_H
#include <iostream>
#include <string>
#include <Windows.h>  
#include <math.h>
#include <vector>
#include <iterator>
#include <map>
using namespace std;




class ProjectMonitoring
{
	public:
		

		
		
		
		void showModels();
		void setWhite();
		void emptySpace(int x);
	    int basamak(int x);
		void tire();
		void writeTable(int UIdesign,int localDB,int remoteDB,int InAppPurchase,int translate,int host,int os,int page,int code,int day,int price,string startedTime,string name);
		void writeSlash(int x,char color);
		map<string,int> voidTimeCalculate(int UIdesign,int localDB,int remoteDB,int InAppPurchase,int translate,int host,int os,int page,int code,int day,int price);
		
		bool getAdmin(){
			return isAdmin;
		}
		void setAdmin(bool admin){
			
			isAdmin = admin;
			
		}
		
	
	private:
		bool isAdmin;	

};

#endif
