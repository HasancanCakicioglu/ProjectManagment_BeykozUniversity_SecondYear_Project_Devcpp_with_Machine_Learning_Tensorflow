#include "ILanguage.cpp"
using namespace std;

class English : public ILanguage
{
public:
    // Override the generateCode() method
    void generateCode() override
    {
        // Set the language to English
        ILanguage::language = "English";
        ILanguage::nameAsk = "What is Project Name = "; 
        ILanguage::programmerAsk = "How many programmers will work ? ";
        ILanguage::pageAsk = "How many pages will there be?";
        ILanguage::opAsk = "Which operating systems will it be compatible with?";
        ILanguage::hostAsk = "Which hosting service will you use? = ";
        ILanguage::languageAsk = "Is there a language option?";
        ILanguage::purchaseAsk = "Add in-app purchase?";
        ILanguage::localAsk = "Will the local database be used?";
        ILanguage::remoteAsk = "Will the remote database be used?";
        ILanguage::designerAsk = "Do you want to use UI designer?";
        
        ILanguage::hostAsk1 = "1 - Beginner";
        ILanguage::hostAsk2 = "2 - Middle";
        ILanguage::hostAsk3 = "3 - Prof";
        ILanguage::hostAsk4 = "4 - Business";
        
        
        ILanguage::yesA = "Yes";
		ILanguage::noA = "No";  

        ILanguage::loginAsk1 = "Please enter your username = ";
        ILanguage::loginAsk2 = "Please enter your password = ";
        ILanguage::loginAsk3 = "Username or Password is wrong!";
        
        ILanguage::registerAsk1 = "Please enter your username = ";
        ILanguage::registerAsk2 = "Please enter your password = ";
        ILanguage::registerAsk3 = "Register is Succesful";
        ILanguage::registerAsk4 = "Username or Password is wrong";
        
        ILanguage::settingAsk = "Settings";
        ILanguage::keyboardAsk1 = "Login in";
        ILanguage::keyboardAsk2 = "Register";
        ILanguage::keyboardAsk3 = "Sign out";
        ILanguage::keyboardAsk4 = "Language";
        ILanguage::keyboardAsk5 = "Projects";
        ILanguage::keyboardAsk6 = "Create a project";
        
        ILanguage::langAsk1 = "Turkish";
        ILanguage::langAsk2 = "English";
        ILanguage::langAsk3 = "Italy";
        
        ILanguage::monitorAsk1 = "It is entering";
        ILanguage::monitorAsk2 = "!!! Sign in first !!!";
        
        ILanguage::calcAsk1 = "Programmer Count = ";
        ILanguage::calcAsk2 = "Page Count = ";
        ILanguage::calcAsk3 = "Operating System =";
        ILanguage::calcAsk4 = "Translate =";
        ILanguage::calcAsk5 = "Purchase = ";
        ILanguage::calcAsk6 = "Local = ";
        ILanguage::calcAsk7 = "Remote = ";
        ILanguage::calcAsk8 = "Designer = ";
        
        
    

        cout << "Generating English code..." << endl;
    }
};
