#ifndef account_H
#define account_H
#include <iostream>
#include <string>
#include <ctime>
//#include "timeStructre.cpp"
#include "../Constants/Structre/timeStructre.cpp"
#include "../Database/databaseSQL.h"
using namespace std;



class Account
{

	
	private:

    	Account() { }

   		static Account* instance;

	public:

		static Account* getInstance()
    	{
        	if (!instance)
        	{
            	instance = new Account();
       	 	}
        	return instance;
    	}
	
	bool loginWithUsernameAndPassword(string user,string pass,string tableName,char* mydb);
	bool registerWithUsernameAndPassword(string userName,string password);
	void setInfo(string userName,string password,string token,bool admin,bool loginStatus);
	bool login(char * mydb);
	bool registerr(char * mydb);
	
		
	string userName;
	string password;
	bool admin;
	string token;
	int id;
	bool loginStatus = false;
	
	
		
		
};

#endif
