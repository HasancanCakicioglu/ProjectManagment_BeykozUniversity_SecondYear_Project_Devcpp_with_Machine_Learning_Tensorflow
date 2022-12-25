#include <iostream>
#include <string>
#include <ctime>
#include "account.h"
#include "../Database/databaseSQL.h"
#include <map>
#include "../Utils/UI/UIhelper.h"
#include "../Utils/String/helperString.h"
using namespace std;



bool Account::loginWithUsernameAndPassword(string user,string pass,string tableName,char* mydb)
{
	
	map<string,string> myMap = DatabaseSql::selectDataWithWhere(mydb,tableName,user,pass);
	
	
	
	if((myMap["username"] == user) && (myMap["password"] == pass)){
	    
	    
	    
	    setInfo(user,pass,myMap["token"],false,true);
	    
	    return true;
	    
	}
	
	return false;



}

bool Account::registerWithUsernameAndPassword(string user,string pass)
{
	
	this->userName = user;
	this->password = pass;
	
	return true;

}

void Account::setInfo(string userName,string password,string token,bool admin,bool loginStatus)
{
	
	this->userName = userName;
	this->password = password;
	this->admin = admin;
	this->token = token;
	this->loginStatus=loginStatus;

}


bool Account::login(char * mydb){
	
		DatabaseSql * db = DatabaseSql::getInstance();
	Account * account = Account::getInstance();
	
	bool login=false;
	
	string u="",p="";
   
    while(login==false){
              
       
        
        
        	UIhelper::anachose("Please enter your username = ");
            //cout<<"Please enter your username = ";
            UIhelper::empty(45);
            cin>>u;
            
            UIhelper::anachose("Please enter your password = ");
            //cout<<endl<<"Please enter your password = ";
            UIhelper::empty(45);
            cin>>p;
            
            
            if(account->loginWithUsernameAndPassword(u,p,"Account",mydb)){
            	system("cls");
            	
               
               login = true;
                
            }else{
                system("cls");
                UIhelper::anachose("!!! Username or Password is wrong !!!");
               // cout<<"Username or Password is wrong"<<endl<<endl;
            }
            
    }
    
    auto myMap = db->selectDataWithWhere(mydb,"ACCOUNT",u,p);

    
    account->id = stoi(myMap["id"]);
    account->userName = myMap["username"];
    account->password = myMap["password"];
    account->admin = myMap["admin"] == "true" ? true : false;
    account->token = myMap["token"];
    account->loginStatus = true;
	
	
	return true;
	
}

bool Account::registerr(char * mydb){
	
		DatabaseSql * db = DatabaseSql::getInstance();
	Account * account = Account::getInstance();
	
	bool login=false;
	
	string u="",p="";
    
    while(login==false){
        
			UIhelper::anachose("Please enter your username = ");
   
            UIhelper::empty(50);
            cin>>u;

            
            UIhelper::anachose("Please enter your password = ");
      
            UIhelper::empty(50);
            cin>>p;

            
            
            if(account->registerWithUsernameAndPassword(u,p)){
            	system("cls");
            	UIhelper::anachose("Register is Succesful");
            	account->loginStatus = true;
            	string token = helperString().generateToken();
                
                db->insertData(mydb,"ACCOUNT","USERNAME,PASSWORD,TOKEN,ADMIN","'"+ u +"','"+ p +"', '"+ token +"', 'false'");
                login = true;
            }else{
                system("cls");
                UIhelper::anachose("Username or Password is wrong");
            }
        
        
        
    }
        
    
    
    auto myMap = db->selectDataWithWhere(mydb,"ACCOUNT",u,p);

    
    
    account->id = stoi(myMap["id"]);
    account->userName = myMap["username"];
    account->password = myMap["password"];
    account->admin = myMap["admin"] == "true" ? true : false;
    account->token = myMap["token"];
    account->loginStatus = true;
    
    return true;
	
}





