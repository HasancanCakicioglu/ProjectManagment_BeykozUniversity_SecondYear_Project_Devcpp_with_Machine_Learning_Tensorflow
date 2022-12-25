
#include <iostream>
using namespace std;
#ifndef ILanguage_H
#define ILanguage_H


// Define the Language abstract class
class ILanguage
{
public:
    // Static string member to hold the language
    static string language;
    
    //main.cpp tekrar dönn
    static string nameAsk; 
    static string programmerAsk; 
    static string pageAsk;
    static string opAsk;
    static string hostAsk;
    static string languageAsk;
    static string purchaseAsk;
    static string localAsk;
    static string remoteAsk;
    static string designerAsk;
    
    static string hostAsk1;
    static string hostAsk2;
    static string hostAsk3;
    static string hostAsk4;
    
    static string yesA;
    static string noA;
    
    //account.cpp
    static string loginAsk1;
    static string loginAsk2;
    static string loginAsk3;
    static string registerAsk1;
    static string registerAsk2;
    static string registerAsk3;
    static string registerAsk4;
    
    //keyboard.cpp
    static string settingAsk;
    static string keyboardAsk1;
    static string keyboardAsk2;
    static string keyboardAsk3;
    static string keyboardAsk4;
    static string keyboardAsk5;  
    static string keyboardAsk6;
    
    static string langAsk1;
    static string langAsk2;
    static string langAsk3;
    
    //project.cpp
    static string monitorAsk1;
    static string monitorAsk2;
    
    //priceCalculator.cpp
    static string calcAsk1;
    static string calcAsk2;
    static string calcAsk3;
    static string calcAsk4;
    static string calcAsk5;
    static string calcAsk6;
    static string calcAsk7;
    static string calcAsk8;
    

    // Pure virtual method to generate the code
    virtual void generateCode() = 0;
};

#endif
