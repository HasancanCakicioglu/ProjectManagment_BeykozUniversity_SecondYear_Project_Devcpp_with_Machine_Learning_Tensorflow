#include <iostream>
#include <string>
#include <ctime>
#include "keyboard.h"
#include <conio.h>
#include <stdio.h>
#include "../Constants/Keyboard/define.h"
#include "../Page/Project/project.h"

#include "../Page/Language/languagePage.cpp"
#include "../Account/account.h"
#include "../Language/ILanguage.cpp"
#include "../Utils/UI/UIhelper.h"
using namespace std;





bool Keyboard::pageController(){
	
	
	
	Keyboard* k = Keyboard::getInstance();
	Account * account = Account::getInstance();
	ProjectMonitoring monitor = ProjectMonitoring();
	bool contin = false;
	this->func();
	
	
	char key = getch();
	int value;
	value = k->key;
	
	             
	while(value != KEY_X){
		
		switch(value = getch()){
			case KEY_UP:
				k->key--;
				k->keyControl();
				k->func();
				
			break;
			case KEY_DOWN:
				k->key++;
				k->keyControl();
				k->func();
			break;	
			case ESC:
				cout<<"ayarlar";
			break;
			case ENTER:
				system("cls");
				switch(k->key){
					
					case 1:
						if(account->login(DatabaseSql::mydb)){
							value = KEY_X;
							account->loginStatus = true;
						}
						break;
					case 2:
						if(account->registerr(DatabaseSql::mydb)){
							account->loginStatus = true;
							value = KEY_X;
						}
						break;
					case 3:
						exit(0);
						break;
					case 4:
						system("cls");
						languagePage().languageSettings();
						break;
					case 5:
						monitor.showModels();
						break;
					case 6:
						value = KEY_X;
						contin = true;
						break;
					
				}
				
				
			break;		
			
		}
		
		
		
		
	}
	
	return contin;
}



void Keyboard::func()
{
	int x = 45;
	
	system("cls");
	UIhelper::anachose(this->key == 1 ? " --> "+ILanguage::keyboardAsk1 : "     "+ILanguage::keyboardAsk1);
	UIhelper::anachose(this->key == 2 ? " --> "+ILanguage::keyboardAsk2 : "     "+ILanguage::keyboardAsk2);
	UIhelper::anachose(this->key == 3 ? " --> "+ILanguage::keyboardAsk3 : "     "+ILanguage::keyboardAsk3);
	UIhelper::anachose(this->key == 4 ? " --> "+ILanguage::keyboardAsk4 : "     "+ILanguage::keyboardAsk4);
	UIhelper::anachose(this->key == 5 ? " --> "+ILanguage::keyboardAsk5 : "     "+ILanguage::keyboardAsk5);
	UIhelper::anachose(this->key == 6 ? " --> "+ILanguage::keyboardAsk6 : "     "+ILanguage::keyboardAsk6);
	
	


}


void Keyboard::keyControl()

{
	int x = this->key;
	
	if(x<1){
			this->key = 6;
		}else if(x>6){
			 this->key = 1;
		}	
	
}

void Keyboard::keyControlLanguage()

{
	int x = this->keyLanguage;
	
	if(x<1){
			this->keyLanguage = 3;
		}else if(x>3){
			 this->keyLanguage = 1;
		}	
	
}
void Keyboard::ayarlarLanguage()
{
	
	system("cls");
	this->keyLanguage == 1 ? cout<<" -->  "<<ILanguage::langAsk1<<endl : cout<<"     "<<ILanguage::langAsk1<<endl;
	this->keyLanguage == 2 ? cout<<" -->  "<<ILanguage::langAsk2<<endl : cout<<"     "<<ILanguage::langAsk2<<endl;
	this->keyLanguage == 3 ? cout<<" -->  "<<ILanguage::langAsk3<<endl : cout<<"     "<<ILanguage::langAsk3<<endl;
	

}


