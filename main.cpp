#include <iostream>
#include <string>
#include "src/Model/price/priceCalculator.h"
#include "src/Account/account.h"
#include "src/Utils/Time/helperTime.h"
#include "src/Model/Time/timeController.h"
#include "time.h"
#include <vector>
#include <ctime>
#include "src/Database/DatabaseSql.h"
#include <typeinfo>

#include "src/Constants/Enum/Host.h"
#include "src/Constants/Enum/OS.h"

#include "src/Utils/String/helperString.h"

#include "src/Constants/Language/Initialize.h"


#include "src/Keyboard/keyboard.h"

#include "src/Page/Project/project.h"
#include <locale.h>
#define UNICODE

#include "src/Language/Turkish.cpp"
#include "src/Language/English.cpp"
#include "src/Language/Italy.cpp"

#include "src/Utils/UI/UIhelper.h"

#include "AI/model/AI.h"
#include <tuple>

#include <locale>
#include <codecvt>
using namespace std;





DatabaseSql* DatabaseSql::instance = NULL; // initialize sqlite3 database as Singleton
Account* Account::instance = NULL; // initialize Account class as Singleton
Keyboard* Keyboard::instance = nullptr;


void login(char * mydb);
void registerr(char * mydb);
//void loginRegister(char * mydb);
void setProjectName(priceCalculator * pricecalculator,string nam);
void setProgrammerCount(priceCalculator * pricecalculator,int programmerCount);
void setPageCount(priceCalculator * pricecalculator,int pageCount);
void setOperatingSystem(priceCalculator * pricecalculator,OS osEnum);
void setHostingService(priceCalculator * pricecalculator,Host hostEnum,int hostInt);
void setTranslate(priceCalculator * pricecalculator,int translate,helperString help);
void setInAppPurchase(priceCalculator * pricecalculator,int purchase,helperString help);
void setLocal(priceCalculator * pricecalculator,int local,helperString help);
void setRemote(priceCalculator * pricecalculator,int remote,helperString help);
void setDesigner(priceCalculator * pricecalculator,int designer,helperString help);



int main()
{
	
	
	English en = English();
	en.generateCode();
	
	
	Account * account = Account::getInstance();
	Keyboard* k = Keyboard::getInstance();

	bool contin = false;

	while(contin==false || account->loginStatus == false){

		contin = k->pageController();
	}


	DatabaseSql* db = DatabaseSql::getInstance();



	char* mydb = DatabaseSql::mydb;


    db->createDB(mydb);
    db->createTable(mydb,"ACCOUNT");
//    db->insertData(mydb,"ACCOUNT","USERNAME,PASSWORD,TOKEN,ADMIN","'alim', 'sifre123', 'abcd', 'true'");
//
//    db->selectData(mydb,"MODEL");



    /* The addresses will be the same. */






    helperTime helpTime = helperTime();
    helperString helpString = helperString();
    //Account * account = Account::getInstance();
    priceCalculator p = priceCalculator();
    timeStructre timeS = timeStructre();
    timeS = helpTime.getCurrentTime();
    
    
    p.setTimeAsStructure(timeS);

    int progremmerCount;
    int pageCount;
    OS osEnum;
    Host hostEnum;
    int hostInt;
    int translate;
    int purchase;
	int local;
	int remote;
    int designer;
    string nam;






    //loginRegister(mydb);
    setProjectName(&p,nam);
    setProgrammerCount(&p,progremmerCount);
    setPageCount(&p,pageCount);
    setOperatingSystem(&p,osEnum);
    setHostingService(&p,hostEnum,hostInt);
    setTranslate(&p,translate,helpString);
    setInAppPurchase(&p,purchase,helpString);
    setLocal(&p,local,helpString);
    setRemote(&p,remote,helpString);
    setDesigner(&p,designer,helpString);



    //p.coutAll();
    
    string program = ""+to_string(p.getProgrammerCount());
    string pag = ""+to_string(p.getPageCount());
    string os = ""+to_string(p.getOSsupportPrice());
    string hos = ""+to_string(p.getHostSupport());
    string trans = ""+to_string(p.getTranslate());
    string purch = ""+to_string(p.getInAppPurchase());
    string loc = ""+to_string(p.getLocalDataBase());
    string rem = ""+to_string(p.getRemoteDataBase());
    string des = ""+to_string(p.getUIdesigner());
    string projectName = p.getProjectName();
    
    vector<string> osVec;
    
    osVec = p.getOSsupportName();
    
    
    int an=0,io=0,win=0,lin=0,we=0,ma=0;
    
    for(int i = 0;i<osVec.size();i++){
    	
    	if(osVec[i]== "Android"){
    		an = 1;
		}else if(osVec[i]== "IOS"){
			io = 1;
		}
		else if(osVec[i]== "Windows"){
			win = 1;
		}
		else if(osVec[i]== "Linux"){
			lin = 1;
		}
		else if(osVec[i]== "WEB"){
			we = 1;
		}
		else if(osVec[i]== "MAC"){
			ma = 1;
		}
		
    	
	}
	string hostum = p.getHostName();
	
	int beg = hostum == "beginner" ? 1 : 0;
	int mid = hostum == "middle" ? 1 : 0;
	int pr = hostum == "prof" ? 1 : 0;
	int bus = hostum == "business" ? 1 : 0;
    
    
    
    string token = account->token;
    //Programmer,Page,Android,IOS,Windows,Linux,WEB,Mac,Beginner,Middle,Prof,Business,Purchase,LocalData,RemoteData,Designer,TotalPrice,Time
	double predictModel[1][16]={{p.getProgrammerCount(),p.getPageCount(),an,io,win,lin,we,ma,beg,mid,pr,bus,p.getInAppPurchase(),p.getLocalDataBase(),p.getRemoteDataBase(),p.getUIdesigner()}};


	AI ai = AI();
	auto [pricePredict,timePredict] = ai.predict(predictModel);
	
	p.setPrice(pricePredict);
	p.setDay(timePredict);
	
	
	cout<<pricePredict<<endl;
	string pri = ""+to_string(pricePredict);
	string ti = ""+to_string(timePredict);
	
	
	string time = to_string(timeS.day)+"-"+to_string(timeS.month)+"-"+to_string(timeS.year);

	db->insertData(mydb,"MODEL","PROGRAMMER,PAGE,OS,HOST,TRANSLATE,INAPPPURCHASE,LOCALDB,REMOTEDB,UIDESIGNER,TOKEN,TIME,PRICE,NAME,STARTEDTIME","'"+program+"', '"+pag+"', '"+os+"', '"+hos+"', '"+trans+"', '"+purch+"', '"+loc+"', '"+rem+"', '"+des+"', '"+token+"', '"+ti+"', '"+pri+"','"+projectName+"','"+time+"'");


	k->pageController();

}


void setProjectName(priceCalculator * priceCalculator,string name){
	
	UIhelper::ana(ILanguage::nameAsk);
	cin>>name;
	
	priceCalculator->setProjectName(name);
    system("cls");
}



void setProgrammerCount(priceCalculator * priceCalculator,int programmerCount){
	
	UIhelper::ana(ILanguage::programmerAsk);
	cin>>programmerCount;
	
	
	//cout<<endl<<ILanguage::programmerAsk;
    //cin>>programmerCount;
    priceCalculator->setProgrammerCount(programmerCount);
    system("cls");
}
void setPageCount(priceCalculator * pricecalculator,int pageCount){

	UIhelper::ana(ILanguage::pageAsk);
    cin>>pageCount;
    pricecalculator->setPageCount(pageCount);
    system("cls");

}
void setOperatingSystem(priceCalculator * priceCalculator,OS osEnum){

	UIhelper::ana(ILanguage::opAsk);

    string osDizi[6]={" "," "," "," "," "," "};
    int os;
    bool osChosen = false;

    string osNames[6] = {"Android","IOS","Windows","Linux","WEB","MAC"};

    vector<int> vecPrice;
    vector<string> vecName;

    cout<<endl;

    while(osChosen == false){
        system("cls");
        
        UIhelper::anachose("   ( "+osDizi[0]+" ) 1 - Android");
        UIhelper::anachose("( "+osDizi[1]+" ) 2 - IOS");
        UIhelper::anachose("   ( "+osDizi[2]+" ) 3 - Windows");
        UIhelper::anachose("  ( "+osDizi[3]+" ) 4 - Linux");
        UIhelper::anachose("( "+osDizi[4]+" ) 5 - WEB");
        UIhelper::anachose("( "+osDizi[5]+" ) 6 - MAC");
        
//        cout<<"( "<<osDizi[0]<<" ) 1 - Android"<<endl;
//        cout<<"( "<<osDizi[1]<<" ) 2 - IOS"<<endl;
//        cout<<"( "<<osDizi[2]<<" ) 3 - Windows"<<endl;
//        cout<<"( "<<osDizi[3]<<" ) 4 - Linux"<<endl;
//        cout<<"( "<<osDizi[4]<<" ) 5 - WEB"<<endl;
//        cout<<"( "<<osDizi[5]<<" ) 6 - MAC"<<endl;
		UIhelper::empty(40);
        cout<<endl<<"Add operating system = ";
        cin>>os;
        switch(os){
            case 0:
                osChosen = true;
            break;

            case 1:
                if(osDizi[0]==" "){
                    osDizi[0]="X";
                }else{
                    osDizi[0]=" ";
                }
            break;

            case 2:
                if(osDizi[1]==" "){
                    osDizi[1]="X";
                }else{
                    osDizi[1]=" ";
                }
            break;

            case 3:
                if(osDizi[2]==" "){
                    osDizi[2]="X";
                }else{
                    osDizi[2]=" ";
                }
            break;

            case 4:
                if(osDizi[3]==" "){
                    osDizi[3]="X";
                }else{
                    osDizi[3]=" ";
                }
            break;

            case 5:
                if(osDizi[4]==" "){
                    osDizi[4]="X";
                }else{
                    osDizi[4]=" ";
                }
            break;

            case 6:
                if(osDizi[5]==" "){
                    osDizi[5]="X";
                }else{
                    osDizi[5]=" ";
                }
            break;

            default:

            break;
        }


    }

    for(int i =0;i<6;i++){

        if(osDizi[i]=="X"){
            vecName.push_back(osNames[i]);

            if(i==1){
                vecPrice.push_back(osEnum=Android);
            }else if(i==2){
                vecPrice.push_back(osEnum=IOS);
            }
            else if(i==3){
                vecPrice.push_back(osEnum=Windows);
            }
            else if(i==4){
                vecPrice.push_back(osEnum=Linux);
            }
            else if(i==5){
                vecPrice.push_back(osEnum=WEB);
            }
            else if(i==6){
                vecPrice.push_back(osEnum=MAC);
            }

        }
    }

    priceCalculator->setOSsupport(vecPrice,vecName);
    system("cls");

    // for (auto i = vecName.begin(); i != vecName.end(); ++i)
    //     cout << *i << " ";

}
void setHostingService(priceCalculator * priceCalculator,Host hostEnum,int hostInt){

	UIhelper::emptyUp(8);
	UIhelper::anachose(ILanguage::hostAsk);
	UIhelper::anachose(ILanguage::hostAsk1);
	UIhelper::anachose(ILanguage::hostAsk2);
	UIhelper::anachose(ILanguage::hostAsk3);
	UIhelper::anachose(ILanguage::hostAsk4);
	
//	cout<<endl<<ILanguage::hostAsk;
//    cout<<endl<<ILanguage::hostAsk1<<endl;
//    cout<<ILanguage::hostAsk2<<endl;
//    cout<<ILanguage::hostAsk3<<endl;
//    cout<<ILanguage::hostAsk4<<endl;

    cin>>hostInt;

    string hostName;

    switch(hostInt){
        case 1:
            hostName = "beginner";
            hostEnum = beginner;
        break;
        case 2:
            hostName = "middle";
            hostEnum = middle;
        break;
        case 3:
            hostName = "prof";
            hostEnum = prof;
        break;
        case 4:
            hostName = "business";
            hostEnum = business;
        break;
    }

    priceCalculator->setHostSupport(hostEnum,hostName);
    system("cls");

}
void setTranslate(priceCalculator * pricecalculator,int translate,helperString help){


	UIhelper::ana(ILanguage::languageAsk);
    cout<<"1 -"<<ILanguage::yesA<<endl;
    UIhelper::empty(52);
    cout<<"0 -"<<ILanguage::noA<<endl;
    UIhelper::empty(52);
    cin>>translate;

    pricecalculator->setTranslate(help.trueFalse(translate));
    system("cls");

}
void setInAppPurchase(priceCalculator * pricecalculator,int purchase,helperString help){
	
	UIhelper::ana(ILanguage::purchaseAsk);
	
    cout<<"1 -" <<ILanguage::yesA<<endl;
    UIhelper::empty(52);
    cout<<"0 -" <<ILanguage::noA<<endl;
    UIhelper::empty(52);
    cin>>purchase;
    pricecalculator->setInAppPurchase(help.trueFalse(purchase));
    system("cls");
}
void setLocal(priceCalculator * pricecalculator,int local,helperString help){
	UIhelper::ana(ILanguage::localAsk);
    cout<<"1 -"<<ILanguage::yesA<<endl;
    UIhelper::empty(52);
    cout<<"0 -"<<ILanguage::noA<<endl;
    UIhelper::empty(52);
    cin>>local;
    pricecalculator->setLocalDataBase(help.trueFalse(local));
    system("cls");
}
void setRemote(priceCalculator * pricecalculator,int remote,helperString help){

	UIhelper::ana(ILanguage::remoteAsk);
    cout<<"1 -"<<ILanguage::yesA<<endl;
    UIhelper::empty(52);
    cout<<"0 -"<<ILanguage::noA<<endl;
    UIhelper::empty(52);
    cin>>remote;


    pricecalculator->setRemoteDataBase(help.trueFalse(remote));
    system("cls");

}
void setDesigner(priceCalculator * pricecalculator,int designer,helperString help){

	UIhelper::ana(ILanguage::designerAsk);
    cout<<"1 -"<<ILanguage::yesA<<endl;
    UIhelper::empty(52);
    cout<<"0 -"<<ILanguage::noA<<endl;
    UIhelper::empty(52);
    cin>>designer;


    pricecalculator->setUIdesigner(help.trueFalse(designer));

    system("cls");

}

