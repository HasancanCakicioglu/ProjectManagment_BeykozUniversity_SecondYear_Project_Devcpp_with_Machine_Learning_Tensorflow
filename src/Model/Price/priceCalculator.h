#ifndef priceCalculator_H
#define priceCalculator_H
#include "../Time/timeController.h"
#include <iostream>
#include <string>
#include <vector>
#include "../../Constants/Enum/Host.h"
#include <vector>
using namespace std;




class priceCalculator : public timeController
{
	public:
		

		explicit priceCalculator();

	
		void setProgrammerCount(int programmer);
		void setPageCount(int page);
		void setOSsupport(vector<int> osEnumPrice,vector<string> osEnumName);
		void setHostSupport(Host hostEnum,string hostName);
		void setProjectName(string name);
		
		void setTranslate(bool t);
		void setInAppPurchase(bool purchase);
		void setLocalDataBase(bool local);
		void setRemoteDataBase(bool remote);
		void setUIdesigner(bool designer);
		void setPrice(int p);
		int getPrice();
		
		void setDay(int d);
		int getDay();
		
		//get 
		
		int getProgrammerCount();
		int getPageCount();
		vector<string> getOSsupportName();
		int getOSsupportPrice();
		
	    Host getHostSupport();
		
		bool getTranslate();
		bool getInAppPurchase();
		bool getLocalDataBase();
		bool getRemoteDataBase();
		bool getUIdesigner();
		string getToken();
		
		string getProjectName();
		
		string getHostName();
		
		
		
		
		void coutAll();
		
		
		
	private:
		//data members
	
		int programmer;
		int page;
		int OSPrice;
		vector<string> osEnumName;
		Host hostEnum;
		string hostName;
		bool translate;
		bool purchase;
		bool local;
		bool remote;
		bool designer;
		string token;
		string name;
		int price;
		int day;
		
		
};

#endif
