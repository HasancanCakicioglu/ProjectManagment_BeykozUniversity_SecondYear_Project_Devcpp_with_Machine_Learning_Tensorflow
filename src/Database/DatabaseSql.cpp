#include "DatabaseSql.h"
#include <stdio.h>
#include <iostream>
#include "../../sqlite3.h"
#include <string>
#include "../Account/account.h"
#include <map>

using namespace std;


typedef std::basic_string <unsigned char> ustring;

int DatabaseSql::createDB(const char* s){
	
	sqlite3* DB;
	
	int exit = 0;
	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB);

	return 0;
}

int DatabaseSql::createTable(const char* s,string tableName){
	
	sqlite3 *DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS GRADES("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"NAME      TEXT NOT NULL, "
		"LNAME     TEXT NOT NULL, "
		"AGE       INT  NOT NULL, "
		"ADDRESS   CHAR(50), "
		"GRADE     CHAR(1) );";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}

	return 0;
}

int DatabaseSql::insertData(const char* s,string tableName,string columns,string values){
	
	sqlite3* DB;
	char* messageError;
	
	string sql("INSERT INTO " + tableName + " ( " + columns + " ) VALUES("+ values + ");");
	

	int exit = sqlite3_open(s, &DB);

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in insertData function." << endl;
		cout<<"error = "<<messageError<<endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records inserted Successfully!" << endl;

	return 0;
}

int DatabaseSql::updateData(const char* s){
	
	sqlite3* DB;
	char* messageError;

	string sql("UPDATE GRADES SET GRADE = 'A' WHERE LNAME = 'Cooper'");

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in updateData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records updated Successfully!" << endl;

	return 0;
}

int DatabaseSql::deleteData(const char* s,string tableName){
	
	sqlite3* DB;
	char* messageError;

	string sql = "DELETE FROM "+tableName+";";

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in deleteData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records deleted Successfully!" << endl;

	return 0;
}

int DatabaseSql::selectData(const char* s,string tabloName){
	
	sqlite3* DB;
	char* messageError;

	string sql = "SELECT * FROM "+tabloName+";";

	int exit = sqlite3_open(s, &DB);
	
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "Error in selectData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records selected Successfully!" << endl;

	return 0;
}

map<string,string> DatabaseSql::selectDataWithWhere(const char* s,string tabloName,string userName,string password){
	
	
	
	sqlite3* DB;
	sqlite3_stmt *stmt;
	char* messageError;
	std::map<string, string> my_map = {	};

	string sql = "SELECT * FROM "+tabloName+" WHERE username = '"+userName+"' AND password = '"+password+"';";
	

	



	int exit = sqlite3_open(s, &DB);
	
//	exit = sqlite3_exec(DB, sql.c_str(), callbackLogin, NULL, &messageError);
	exit = sqlite3_prepare_v2(DB, sql.c_str(), -1,&stmt, NULL);

	if (exit != SQLITE_OK) {
		cerr << "Error in selectWithWhere function." << endl;
		cout<<"error = "<<messageError<<endl;
		sqlite3_free(messageError);
	}
	else{
		
		
		
		
		while((exit = sqlite3_step(stmt)==SQLITE_ROW)){
			
			
			
			string id = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 0)));
      					
      		string username = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 1)));
			
			string password = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 2)));
			string token = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 3)));
			string admin = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 4)));		
			
			
			
			my_map["id"] =id;
			my_map["username"] =username;
			my_map["password"] =password;
			my_map["token"] =token;
			my_map["admin"] =admin;
			
			
			
			
		}
		return my_map;
	}
		

	return my_map;
}



vector<map<string,string>> DatabaseSql::selectProjectWithWhereToken(const char* s,string token){
	
	
		
	
	sqlite3* DB;
	sqlite3_stmt *stmt;
	char* messageError;
	map<string, string> my_map = {	};
	
	vector<map<string,string>> myVector;
	
	string tabloName = "model";
	

	string sql = "SELECT * FROM "+tabloName+" WHERE token = '"+token+"';";
	
	int exit = sqlite3_open(s, &DB);
	
//	exit = sqlite3_exec(DB, sql.c_str(), callbackLogin, NULL, &messageError);
	exit = sqlite3_prepare_v2(DB, sql.c_str(), -1,&stmt, NULL);

	if (exit != SQLITE_OK) {
		cerr << "Error in selectWithWhere function." << endl;
		cout<<"error = "<<messageError<<endl;
		sqlite3_free(messageError);
	}
	else{
		
		
	
		
		while((exit = sqlite3_step(stmt)==SQLITE_ROW)){
			
			
			
			string id = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 0)));
      					
      		string programmer = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 1)));
			
			string page = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 2)));
			string os = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 3)));
      		string host = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 4)));
			string translate = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 5)));	
			
			string inAppPurchase = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 6)));
						  
			string localDB = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 7)));
			string remoteDB = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 8)));
			string UIdesigner = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 9)));
			string token = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 10)));
      		string time = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 11)));
      		string price = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 12)));
      		string name = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 13)));
      		string startedTime = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 14)));
			
			
			
			my_map["id"] =id;
			my_map["programmer"] =programmer;
			my_map["page"] =page;
			my_map["os"] =os;
			my_map["host"] =host;
			my_map["translate"] =translate;
			my_map["inAppPurchase"] =inAppPurchase;
			my_map["localDB"] =localDB;
			my_map["remoteDB"] =remoteDB;
			my_map["UIdesigner"] =UIdesigner;
			my_map["token"] =token;
			my_map["day"] =time;
			my_map["price"] =price;
			my_map["name"] =name;
			my_map["startedTime"] =startedTime;
			
			
			myVector.push_back(my_map);
			
			
			
			
		}
		return myVector;
	}
		

	return myVector;
	
}

vector<map<string,string>> DatabaseSql::selectAll(const char* s){
	
	
	sqlite3* DB;
	sqlite3_stmt *stmt;
	char* messageError;
	map<string, string> my_map = {	};
	
	vector<map<string,string>> myVector;
	
	string tabloName = "model";
	

	string sql = "SELECT * FROM "+tabloName+";";
	
	int exit = sqlite3_open(s, &DB);
	
//	exit = sqlite3_exec(DB, sql.c_str(), callbackLogin, NULL, &messageError);
	exit = sqlite3_prepare_v2(DB, sql.c_str(), -1,&stmt, NULL);

	if (exit != SQLITE_OK) {
		cerr << "Error in selectWithWhere function." << endl;
		cout<<"error = "<<messageError<<endl;
		sqlite3_free(messageError);
	}
	else{
		
		
	
		
		while((exit = sqlite3_step(stmt)==SQLITE_ROW)){
			
			
			
			string id = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 0)));
      					
      		string programmer = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 1)));
			
			string page = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 2)));
			string os = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 3)));
      		string host = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 4)));
			string translate = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 5)));	
			
			string inAppPurchase = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 6)));
						  
			string localDB = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 7)));
			string remoteDB = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 8)));
			string UIdesigner = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 9)));
			string token = std::string(reinterpret_cast<const char*>(
      					sqlite3_column_text(stmt, 10)));	
			
			
			
			my_map["id"] =id;
			my_map["programmer"] =programmer;
			my_map["page"] =page;
			my_map["os"] =os;
			my_map["host"] =host;
			my_map["translate"] =translate;
			my_map["inAppPurchase"] =inAppPurchase;
			my_map["localDB"] =localDB;
			my_map["remoteDB"] =remoteDB;
			my_map["UIdesigner"] =UIdesigner;
			my_map["token"] =token;
			
			myVector.push_back(my_map);
			
			
			
			
		}
		return myVector;
	}
		

	return myVector;
	
	
}




int DatabaseSql::callback(void* NotUsed, int argc, char** argv, char** azColName){
	
	

	for (int i = 0; i < argc; i++) {
		// column name and value
		cout << azColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;

	return 0;
}

int DatabaseSql::callbackLogin(void* NotUsed, int argc, char** argv, char** azColName){
	
	
	
	
	return 0;
}

