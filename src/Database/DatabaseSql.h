#ifndef DatabaseSql_H
#define DatabaseSql_H
#include <iostream>
#include <string>
#include <ctime>
#include <memory>
#include <map>
#include <vector>
using namespace std;



class DatabaseSql
{
	
	
	private:

    	DatabaseSql() { }

   		static DatabaseSql* instance;

	public:

		static DatabaseSql* getInstance()
    	{
        	if (!instance)
        	{
            	instance = new DatabaseSql();
       	 	}
        	return instance;
    	}

    
    int createDB(const char* s);
	int createTable(const char* s,string tableName);
	int deleteData(const char* s,string tableName);
	int insertData(const char* s,string tableName,string columns,string values);
	int updateData(const char* s);
	int selectData(const char* s,string tabloName);
	static map<string,string> selectDataWithWhere(const char* s,string tabloName,string userName,string password);
	static vector<map<string,string>> selectProjectWithWhereToken(const char* s,string token);
	static vector<map<string,string>> selectAll(const char* s);
	static int callback(void* NotUsed, int argc, char** argv, char** azColName);
	static int callbackLogin(void* NotUsed, int argc, char** argv, char** azColName);

	//member
	
	static constexpr char * mydb = "C:\\Users\\Yonet\\Desktop\\workshopFinalHasancanMehmet\\databaseSQL.db";
		
};

#endif
