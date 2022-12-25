#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include "priceCalculator.h"
#include <list>
#include "../../Utils/String/helperString.h"
using namespace std;



priceCalculator::priceCalculator(){
    
}


void priceCalculator::setProgrammerCount(int programmerr=1)

{
    if(programmerr < 1){
        programmerr = 1;
    }
	
	programmer = programmerr;

}



void priceCalculator::setPageCount(int pagee = 1)
{
    if(pagee < 1){
        pagee = 1;
    }
    page = pagee;
}



void priceCalculator::setOSsupport(vector<int> osEnumPricee,vector<string> osEnumNamee)

{
    int sum=0;
    for (int i = 0; i < osEnumPricee.size(); i++){
        
        sum = sum + osEnumPricee[i];
        
        
    }
    
    OSPrice = sum;
    osEnumName = osEnumNamee;
    
 

}

void priceCalculator::setPrice(int p){
	
	price = p;
	
}

int priceCalculator::getPrice(){
	
	return price;
	
}

void priceCalculator::setDay(int d){
	
	day = d;
	
}

int priceCalculator::getDay(){
	
	return day;
	
}


void priceCalculator::setProjectName(string name){
	
	this->name = name;
	
}

string priceCalculator::getProjectName(){
	return name;
}

void priceCalculator::setHostSupport(Host hostEnumm,string hostNamee)
{

    hostName = hostNamee;
    hostEnum = hostEnumm;

}

void priceCalculator::setTranslate(bool t = false)
{
    
    translate = t;

}

void priceCalculator::setInAppPurchase(bool p = false)
{
    purchase = p;

}

void priceCalculator::setLocalDataBase(bool l = false)
{
   local = l;
}

void priceCalculator::setRemoteDataBase(bool r = false)
{
	
	remote = r;
}

void priceCalculator::setUIdesigner(bool d = false)
{
	
	designer = d;
}


// gets

int priceCalculator::getProgrammerCount()
{
    return programmer;
}

int priceCalculator::getPageCount()
{

    return page;
}



vector<string> priceCalculator::getOSsupportName()

{
    return osEnumName;

}

int priceCalculator::getOSsupportPrice()

{
    return OSPrice;

}

Host priceCalculator::getHostSupport()
{

    return hostEnum;

}

bool priceCalculator::getTranslate()
{
    
    return translate;


}

bool priceCalculator::getInAppPurchase()
{
    return purchase;

}

bool priceCalculator::getLocalDataBase()
{
    return local;
}

bool priceCalculator::getRemoteDataBase()
{
    return remote;
	
}

bool priceCalculator::getUIdesigner()
{
	return designer;
}

string priceCalculator::getToken(){
	
	return token;
}

string priceCalculator::getHostName(){
	
	return hostName;
}


void priceCalculator::coutAll()
{
    
    
    cout<<"Time = "<<localTime.day<<"/"<<localTime.month<<"/"<<localTime.year<<endl;
    
    
	cout<<"Programmer Count = "<<programmer<<endl;
	cout<<"Page Count = "<<page<<endl;
	cout<<"Operating System = [  ";
	for (int i = 0; i != osEnumName.size(); ++i)
        cout << osEnumName[i]<< "   ";
    cout<<"]";    
        
	cout<<endl<<"Host = "<<hostName<<endl;
	
	helperString help = helperString();
	
	
	cout<<"Translate = "<<help.coutTrueFalse(translate)<<endl;
	cout<<"Purchase = "<<help.coutTrueFalse(purchase)<<endl;
	cout<<"Local = "<<help.coutTrueFalse(local)<<endl;
	cout<<"Remote = "<<help.coutTrueFalse(remote)<<endl;
	cout<<"designer = "<<help.coutTrueFalse(designer)<<endl;
	

}

