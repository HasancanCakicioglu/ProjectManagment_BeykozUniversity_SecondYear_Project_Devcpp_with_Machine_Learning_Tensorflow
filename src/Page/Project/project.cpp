#include "project.h"
#include "../../Database/DatabaseSql.h"
#include "../../Account/account.h"
#include <vector>
#include "../../Language/ILanguage.cpp"
#include <Windows.h>  
#include <math.h>
#include <string>
#include <iterator>
#include <map>
#include <sstream>
#include "../../Utils/Time/helperTime.h"
#include "../../Utils/UI/UIhelper.h"


using namespace std;


void ProjectMonitoring::showModels(){
	
	vector<map<string,string>> my_vector;
	
	Account * account = Account::getInstance();
	
	//cout<<ILanguage::monitorAsk1;
	
	
	
	
	
	if(account->loginStatus == 0){
	
		cout<<ILanguage::monitorAsk2;
		return ;
	}
	
	
	
	if(account->admin == true){
	
		my_vector = DatabaseSql::selectAll(DatabaseSql::mydb);
		
		
		
		
		for(int i =0;i<my_vector.size();i++){
		
		
			
		
		cout<<my_vector[i]["id"]<<endl;
		cout<<my_vector[i]["programmer"]<<endl;
		cout<<my_vector[i]["page"]<<endl;
		cout<<my_vector[i]["os"]<<endl;
		cout<<my_vector[i]["host"]<<endl;
		cout<<my_vector[i]["translate"]<<endl;
		cout<<my_vector[i]["inAppPurchase"]<<endl;
		cout<<my_vector[i]["localDB"]<<endl;
		cout<<my_vector[i]["remoteDB"]<<endl;
		cout<<my_vector[i]["UIdesigner"]<<endl;
		cout<<my_vector[i]["token"]<<endl;
		
		cout<<endl<<endl;
		
}
		
	}else{
		
	
	string token = account->token;
	
	
	my_vector = DatabaseSql::selectProjectWithWhereToken(DatabaseSql::mydb,token);
	
	int x;
	map<string, int> my_map;
	
	for(int i =0 ;i<my_vector.size();i++){
		string a = i+1+". "+my_vector[i]["name"];
		UIhelper::anachose(a);
		//cout<<i+1<<". "<<my_vector[i]["name"]<<endl;
	}
	
	cin>>x;
	int i = x-1;			
			my_map = this->voidTimeCalculate(stoi(my_vector[i]["UIdesigner"]),stoi(my_vector[i]["localDB"]),stoi(my_vector[i]["remoteDB"]),stoi(my_vector[i]["inAppPurchase"]),stoi(my_vector[i]["translate"]),stoi(my_vector[i]["host"]),stoi(my_vector[i]["os"]),stoi(my_vector[i]["page"]),stoi(my_vector[i]["programmer"]),stoi(my_vector[i]["day"]),stoi(my_vector[i]["price"]));
			this->writeTable(my_map["UIdesign"],my_map["localDB"],my_map["remoteDB"],my_map["InAppPurchase"],my_map["translate"],my_map["host"],my_map["os"],my_map["page"],my_map["code"],my_map["day"],my_map["price"],my_vector[i]["startedTime"],my_vector[i]["name"]);
	
	
//	for(int i =0;i<my_vector.size();i++){
//		
//		cout<<my_vector[i]["id"]<<endl;
//		cout<<my_vector[i]["programmer"]<<endl;
//		cout<<my_vector[i]["page"]<<endl;
//		cout<<my_vector[i]["os"]<<endl;
//		cout<<my_vector[i]["host"]<<endl;
//		cout<<my_vector[i]["translate"]<<endl;
//		cout<<my_vector[i]["inAppPurchase"]<<endl;
//		cout<<my_vector[i]["localDB"]<<endl;
//		cout<<my_vector[i]["remoteDB"]<<endl;
//		cout<<my_vector[i]["UIdesigner"]<<endl;
//		cout<<my_vector[i]["token"]<<endl;
//		
//		cout<<endl<<endl;
//		
//}
		
		
	}

}


void ProjectMonitoring::writeSlash(int x,char color){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(color){
		
		case 'r':
			SetConsoleTextAttribute(hConsole, 12);
			break;
		case 'w':
			SetConsoleTextAttribute(hConsole, 15);
			break;
		case 'g':
			SetConsoleTextAttribute(hConsole, 10);
			break;
		
	}
	
	for(int i =0;i<x;i++){
		cout<<"/";
	}
	
}


void ProjectMonitoring::setWhite(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
}

void ProjectMonitoring::emptySpace(int x){
	for(int i =0;i<x;i++){
		cout<<" ";
	}
}

int ProjectMonitoring:: basamak(int x){
	if(x ==0){
		return 1;
	}
	int sayac=0;
	while(x>=1){
		x=x/10;
		sayac++;
	}
	return sayac;
}

void ProjectMonitoring::tire(){
	cout<<" --------------------------------------------------------------------------------------"<<endl;
}

void ProjectMonitoring::writeTable(int UIdesign,int localDB,int remoteDB,int InAppPurchase,int translate,int host,int os,int page,int code,int day,int price,string startedTime,string name){
	int ui=0,loc=0,rem=0,in = 0,tr=0,ho=0,o=0,pag=0,cod=0;
	//1 - red
	//2 - white
	//3 - green
	

	
	int len1 = UIdesign + page + translate + max(host,os);
	
	
	helperTime ht = helperTime();
	timeStructre timeS = ht.getCurrentTime();
	
	string timeNow = ht.structToString(timeS);
	
	int fark = ht.substractStringTime(timeNow,startedTime);
	
	int sizeName = name.size();
	
	for (int i = 0; i < len1; i++) {
		
	setWhite();
	tire();
	cout<<"|";
	emptySpace(37);
	cout<<name;
	emptySpace(48-sizeName);
	cout<<"|"<<endl;	
	
		
		
    setWhite();
    tire();
    cout<<"| UI Design         :  ";
    writeSlash(ui,'r');
    setWhite();
    emptySpace(64-ui);
    cout<<"|"<<endl;
    tire();
    
    
	
    
    if(ui==UIdesign){
    	setWhite();
    	cout<<"| Local DB          :  ";
    	emptySpace(ui);
    	writeSlash(loc,'r');
    	setWhite();
    	emptySpace(64-(ui+loc));
    	cout<<"|"<<endl;
    	tire();
    	loc != localDB ? loc++ : loc;
    	
	}else{
		setWhite();
    	cout<<"| Local DB          :  ";
    	emptySpace(64);
    	cout<<"|"<<endl;
    	tire();
		
	}
    
    
    
    
    if(ui==UIdesign){
    	setWhite();
    	cout<<"| Remote DB         :  ";
    	emptySpace(ui);
    	writeSlash(rem,'r');
    	setWhite();
    	emptySpace(64-(ui+rem));
    	cout<<"|"<<endl;
    	tire();
    	rem != remoteDB ? rem++ : rem;
    	
	}else{
		setWhite();
    	cout<<"| Remote DB         :  ";
    	emptySpace(64);
    	cout<<"|"<<endl;
    	tire();
	}
    
    
    
    if(ui==UIdesign){
    	setWhite();
    	cout<<"| Code              :  ";
    	emptySpace(ui);
    	writeSlash(cod,'r');
    	setWhite();
    	emptySpace(64-(ui+cod));
    	cout<<"|"<<endl;
    	tire();
    	cod != code ? cod++ : cod;
    	
	}else{
		setWhite();
    	cout<<"| Code              :  ";
    	emptySpace(64);
    	cout<<"|"<<endl;
    	tire();
	}
    
    
    if(tr==translate){
    	setWhite();
    	cout<<"| Host              :  ";
    	emptySpace(pag+ui + tr);
    	writeSlash(ho,'r');
    	setWhite();
    	emptySpace(64-(ui+page+tr+ho));
    	cout<<"|"<<endl;
    	tire();
    	ho != host ? ho++ : ho;
    	
	}else{
		setWhite();
    	cout<<"| Host              :  ";
    	
    	emptySpace(64);
    	cout<<"|"<<endl;
    	tire();
		
	}
	
	
	if(tr==translate){
		setWhite();
    	cout<<"| Operating System  :  ";
    	emptySpace(pag+ui+tr);
    	writeSlash(o,'r');
    	setWhite();
    	emptySpace(64-(ui+page+tr+o));
    	cout<<"|"<<endl;
    	tire();
    	o != os ? o++ : o;
    	
	}else{
		setWhite();
    	cout<<"| Operating System  :  ";

    	emptySpace(64);
    	cout<<"|"<<endl;
    	tire();
		
	}
	
    
    if(pag==page){
    	setWhite();
    	cout<<"| Translate         :  ";
    	emptySpace(pag+ui);
    	writeSlash(tr,'r');
    	setWhite();
    	emptySpace(64-(ui+tr+pag));
    	cout<<"|"<<endl;
    	tire();
    	tr != translate ? tr++ : tr;
    	
	}else{
		setWhite();
    	cout<<"| Translate         :  ";
    	
    	emptySpace(64);
    	cout<<"|"<<endl;
    	tire();
		
	}
	
    
    if(ui==UIdesign){
    	setWhite();
    	cout<<"| Page              :  ";
    	emptySpace(ui);
    	writeSlash(pag,'r');
    	setWhite();
    	emptySpace(64-(ui+pag));
    	cout<<"|"<<endl;
    	tire();
    	pag != page ? pag++ : pag;
    	
	}else{
		setWhite();
    	cout<<"| Page              :  ";
    	emptySpace(64);
    	cout<<"|"<<endl;
    	tire();
	}
    
    
    if(ui==UIdesign){
    	setWhite();
    	cout<<"| InAppPurchase     :  ";
    	emptySpace(ui);
    	writeSlash(in,'r');
    	setWhite();
    	emptySpace(64-(ui+in));
    	cout<<"|"<<endl;
    	tire();
    	in != InAppPurchase ? in++ : in;
    	
	}else{
		
		setWhite();
    	cout<<"| InAppPurchase     :  ";
    	
    	emptySpace(64);
    	cout<<"|"<<endl;
    	tire();
	}
	
	
	
    
    setWhite();
    cout<<"|";
    emptySpace(6);
    	cout<<" Price  :  "<<price;
    	emptySpace(12-basamak(price));
    	cout<<"|";
    	emptySpace(5);
    	cout<<"Day  : "<<0;
    	emptySpace(9 - basamak(0));
    	cout<<"|";
    	emptySpace(6);
    	cout<<"    Finish Day  : "<<day;
    	emptySpace(10-basamak(day));
    	cout<<"|"<<endl;
    	tire();
    
    cout<<endl;
    
    
   
    
    //Sleep(10);
    
    
    if(i+1 == len1 && fark == 0){
    	
	}else{
		system("cls");
	}
    
   
	ui != UIdesign ? ui++ : ui;
  }
  
  
  
  //////////////////////////////////////////////////////////////////////
 
  
  	int uiDay = day - UIdesign;
  	int uig = 0;
  	int locg = 0;
  	int remg = 0;
  	int codg = 0;
  	int pagg = 0;
  	int ing = 0;
  	int trg = 0;
  	int hog = 0;
  	int og = 0;
  	
  	
	

  
  
  	for (int i = 0; i < fark; i++) {
    
    setWhite();
	tire();
	cout<<"|";
	emptySpace(37);
	cout<<name;
	emptySpace(48-sizeName);
	cout<<"|"<<endl;

  
    
    //writeSlash(b,'w');
    if(ui>i){
    		setWhite();
    		tire();
    		cout<<"| UI Design         :  ";
			writeSlash(uig,'g');
			writeSlash(ui-uig,'r');
			setWhite();
    		emptySpace(64-ui);
    		cout<<"|"<<endl;
    		tire();
		
    	ui != UIdesign ? ui++ : ui;
    	uig != uiDay ? uig++ : uig;
    	
	}else{
		setWhite();
    		tire();
    		cout<<"| UI Design         :  ";
			writeSlash(uig,'g');
			writeSlash(ui-uig,'r');
			setWhite();
    		emptySpace(64-ui);
    		cout<<"|"<<endl;
    		tire();
	}
    
    
    
    if(i>=UIdesign){
    	
    	//emptySpace(ui);
    		setWhite();
    		cout<<"| Local DB          :  ";
    		emptySpace(ui);
			writeSlash(locg,'g');
			writeSlash(loc-locg,'r');
			setWhite();
    		emptySpace(64-(ui+loc));
    		cout<<"|"<<endl;
    		tire();
		
    	loc != localDB ? loc++ : loc;
    	locg != localDB ? locg++ : locg;
    	
	}else{
		setWhite();
    	cout<<"| Local DB          :  ";
    	emptySpace(ui);
		writeSlash(loc,'r');
		setWhite();
    	emptySpace(64-(ui+loc));
    	cout<<"|"<<endl;
    	tire();
	}
    
    
    if(i>=UIdesign){
    	
    	setWhite();
    	cout<<"| Remote DB         :  ";
    	emptySpace(ui);
    	
			writeSlash(remg,'g');
			writeSlash(rem-remg,'r');
			setWhite();
    	emptySpace(64-(ui+rem));
    	cout<<"|"<<endl;
    	tire();
		
    	rem != remoteDB ? rem++ : rem;
    	remg != remoteDB ? remg++ : remg;
    	
	}else{
		setWhite();
    	cout<<"| Remote DB         :  ";
		emptySpace(ui);
		writeSlash(rem,'r');
		setWhite();
		emptySpace(64-(ui+rem));
    	cout<<"|"<<endl;
    	tire();
	}
	
    
    
    if(i>=UIdesign){
    	
    setWhite();
    	cout<<"| Code              :  ";
    	emptySpace(ui);
    	
			writeSlash(codg,'g');
			writeSlash(cod-codg,'r');
			setWhite();
    	emptySpace(64-(ui+cod));
    	cout<<"|"<<endl;
    	tire();
		
    	cod != code ? cod++ : cod;
    	codg != code ? codg++ : codg;
    	
	}else{
		setWhite();
    	cout<<"| Code              :  ";
		emptySpace(ui);
		writeSlash(cod,'r');
		setWhite();
    	emptySpace(64-(ui+cod));
    	cout<<"|"<<endl;
    	tire();
	}

	
	if(i>=UIdesign + page + translate){
    	
    	setWhite();
    	cout<<"| Host              :  ";
    	emptySpace(pag+ui + tr);
    	
			writeSlash(hog,'g');
			writeSlash(ho-hog,'r');
			setWhite();
    	emptySpace(64-(ui+page+tr+ho));
    	cout<<"|"<<endl;
    	tire();
		
    	ho != host ? ho++ : ho;
    	hog != host ? hog++ : hog;
    	
	}else{
		setWhite();
    	cout<<"| Host              :  ";
		emptySpace(ui+page+tr);
		writeSlash(ho,'r');
		setWhite();
    	emptySpace(64-(ui+page+tr+ho));
    	cout<<"|"<<endl;
    	tire();
	}
	
	
	if(i>=UIdesign + page + translate){
    	
    	setWhite();
    	cout<<"| Operating System  :  ";
    	emptySpace(pag+ui+tr);
    	
			writeSlash(og,'g');
			writeSlash(o-og,'r');
			setWhite();
    	emptySpace(64-(ui+page+tr+o));
    	cout<<"|"<<endl;
    	tire();
		
    	o != os ? o++ : o;
    	og != os ? og++ : og;
    	
	}else{
		setWhite();
    	cout<<"| Operating System  :  ";
		emptySpace(ui+page+translate);
		writeSlash(o,'r');
		setWhite();
    	emptySpace(64-(ui+page+tr+o));
    	cout<<"|"<<endl;
    	tire();
	}

	

	
	if(i>=UIdesign + page){
    	
    	setWhite();
    	cout<<"| Translate         :  ";
    	emptySpace(pag+ui);
    	
			writeSlash(trg,'g');
			writeSlash(tr-trg,'r');
			setWhite();
    	emptySpace(64-(ui+tr+pag));
    	cout<<"|"<<endl;
    	tire();
		
    	tr != translate ? tr++ : tr;
    	trg != translate ? trg++ : trg;
    	
	}else{
		setWhite();
    	cout<<"| Translate         :  ";
    	emptySpace(pag+ui);
		
		writeSlash(tr,'r');
		setWhite();
    	emptySpace(64-(ui+tr+pag));
    	cout<<"|"<<endl;
    	tire();
	}
	
    
    if(i>=UIdesign){
    	
    	setWhite();
    	cout<<"| Page              :  ";
    	emptySpace(ui);
    	
			writeSlash(pagg,'g');
			writeSlash(pag-pagg,'r');
			
			setWhite();
    	emptySpace(64-(ui+pag));
    	cout<<"|"<<endl;
    	tire();
		
    	pag != page ? pag++ : pag;
    	pagg != page ? pagg++ : pagg;
    	
	}else{
		setWhite();
    	cout<<"| Page              :  ";
    	emptySpace(ui);
		emptySpace(ui);
		writeSlash(pag,'r');
		setWhite();
    	emptySpace(64-(ui+pag));
    	cout<<"|"<<endl;
    	tire();
	}
	    
    
    if(i>=UIdesign){
    	
    	setWhite();
    	cout<<"| InAppPurchase     :  ";
    	emptySpace(ui);
    	
			writeSlash(ing,'g');
			writeSlash(in-ing,'r');
			setWhite();
    	emptySpace(64-(ui+in));
    	cout<<"|"<<endl;
    	tire();
		
    	in != InAppPurchase ? in++ : in;
    	ing != InAppPurchase ? ing++ : ing;
    	
	}else{
		setWhite();
    	cout<<"| InAppPurchase     :  ";
    	emptySpace(ui);
		writeSlash(in,'r');
		setWhite();
    	emptySpace(64-(ui+in));
    	cout<<"|"<<endl;
    	tire();
	}
	
	
	
	
	 setWhite();
    cout<<"|";
    emptySpace(6);
    	cout<<" Price  :  "<<price;
    	emptySpace(12-basamak(price));
    	cout<<"|";
    	emptySpace(5);
    	cout<<"Day  : "<<i+1;
    	emptySpace(9 - basamak(i+1));
    	cout<<"|";
    	emptySpace(6);
    	cout<<"    Finish Day  : "<<day;
    	emptySpace(10-basamak(day));
    	cout<<"|"<<endl;
    	tire();
    
    cout<<endl;

	
   

    Sleep(200);
    if(i+1!=fark){
    	system("cls");
	}
    
    ui != UIdesign ? ui++ : ui;
    
    
	
  }
  
  
  
  
  
}

map<string,int> ProjectMonitoring::voidTimeCalculate(int UIdesign,int localDB,int remoteDB,int InAppPurchase,int translate,int host,int os,int page,int code,int day,int price){
	
	map<string, int> my_map;
	
	int ui = day * 10 / 100;
	int loc = day * 10 / 100;
	int rem = day * 22 / 100;
	int in = day * 9 / 100;
	int tr = day * 5 / 100;
	int ho = day * 13 / 100;
	int o = day * 25 / 100;
	int pag = day * 45 / 100;
	int cod = (day * 70 / 100 ) - (code * (day / 20));
  
    // insert elements in random order
    my_map.insert(pair<string, int>("UIdesign", ui));
    my_map.insert(pair<string, int>("localDB", loc));
    my_map.insert(pair<string, int>("remoteDB", rem));
    my_map.insert(pair<string, int>("InAppPurchase", in));
    my_map.insert(pair<string, int>("translate", tr));
    my_map.insert(pair<string, int>("host", ho));
    my_map.insert(pair<string, int>("os", o));
    my_map.insert(pair<string, int>("page", pag));
    my_map.insert(pair<string, int>("code", cod));
    my_map.insert(pair<string, int>("day", day));
    my_map.insert(pair<string, int>("price", price));
    
    
    return my_map;
    
	
}



