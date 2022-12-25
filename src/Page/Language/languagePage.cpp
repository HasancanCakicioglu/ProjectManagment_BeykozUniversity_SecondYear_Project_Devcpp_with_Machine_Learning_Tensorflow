#include <conio.h>
#include <stdio.h>
#include "../../Constants/Keyboard/define.h"
#include "../../Language/Turkish.cpp"
#include "../../Language/English.cpp"
#include "../../Language/Italy.cpp"
#include "../../Utils/UI/UIhelper.h"




class languagePage{
	
	public:
	void ayarlarLanguageL(int x)
{
	
	system("cls");
//	x == 1 ? cout<<" --> "<<ILanguage::langAsk1<<endl : cout<<"     "<<ILanguage::langAsk1<<endl;
//	x == 2 ? cout<<" --> "<<ILanguage::langAsk2<<endl : cout<<"     "<<ILanguage::langAsk2<<endl;
//	x == 3 ? cout<<" --> "<<ILanguage::langAsk3<<endl : cout<<"     "<<ILanguage::langAsk3<<endl;
	
	UIhelper::anachose(x == 1 ? " --> "+ILanguage::langAsk1 : "     "+ILanguage::langAsk1);
	UIhelper::anachose(x == 2 ? " --> "+ILanguage::langAsk2 : "     "+ILanguage::langAsk2);
	UIhelper::anachose(x == 3 ? " --> "+ILanguage::langAsk3 : "     "+ILanguage::langAsk3);
	

}


int keyControlLanguageL(int x)

{
	
	
	if(x<1){
			x = 3;
		}else if(x>3){
			 x = 1;
		}	
	
	return x;
}



void languageSettings(){
	
	
	
	int x=1;
	
	Turkish turkish;
	English english;
	Italy italy;
	
//	x == 1 ? cout<<" --> "<<ILanguage::langAsk1<<endl : cout<<"     "<<ILanguage::langAsk1<<endl;
//	x == 2 ? cout<<" --> "<<ILanguage::langAsk2<<endl : cout<<"     "<<ILanguage::langAsk2<<endl;
//	x == 3 ? cout<<" --> "<<ILanguage::langAsk3<<endl : cout<<"     "<<ILanguage::langAsk3<<endl;
	
	UIhelper::anachose(x == 1 ? " --> "+ILanguage::langAsk1 : "     "+ILanguage::langAsk1);
	UIhelper::anachose(x == 2 ? " --> "+ILanguage::langAsk2 : "     "+ILanguage::langAsk2);
	UIhelper::anachose(x == 3 ? " --> "+ILanguage::langAsk3 : "     "+ILanguage::langAsk3);
	
	char key = getch();
	int value;
	value = x;
	
	             
	while(value != KEY_X){
		
		switch(value = getch()){
			case KEY_UP:
				x--;
				x= keyControlLanguageL(x);
				ayarlarLanguageL(x);
				
			break;
			case KEY_DOWN:
				x++;
				x= keyControlLanguageL(x);
				ayarlarLanguageL(x);
			break;	
			case ESC:
				cout<<"ayarlar";
			break;
			case ENTER:
				
				switch(x){
					case 1:
							turkish.generateCode();
							
					break;
					case 2:
							english.generateCode();
					break;
					case 3:
							italy.generateCode();
						break;
					
					
				}
				
			break;		
			
		}
		
		
		
		
	}
	
	
	
}
	
	
	
};





