#include "ILanguage.cpp"
using namespace std;


class Italy : public ILanguage
{
public:
    // Override the generateCode() method
    void generateCode() override
    {
        // Set the language to Japanese
        ILanguage::language = "Italy";
        ILanguage::nameAsk = "Cos'è il nome del progetto = ";
        ILanguage::programmerAsk = "Quanti programmatori funzioneranno? ";
        ILanguage::pageAsk = "Quante pagine saranno?";
        ILanguage::opAsk = "Con quali sistemi operativi sarà compatibile?";
        ILanguage::hostAsk = "Quale servizio di hosting utilizzerai? =";
        ILanguage::languageAsk = "C'e un'opzione di lingua?";
        ILanguage::purchaseAsk = "Aggiungere l'acquisto in-app?";
        ILanguage::localAsk = "Verrà utilizzato il database locale?";
        ILanguage::remoteAsk = "Verrà utilizzato il database remoto?";
        ILanguage::designerAsk = "Vuoi utilizzare il designer dell'interfaccia utente?";
        
        ILanguage::hostAsk1 = "1 - Principiante";
        ILanguage::hostAsk2 = "2 - Medio";
        ILanguage::hostAsk3 = "3 - Prof";
        ILanguage::hostAsk4 = "4 - Affari";
        
        
        ILanguage::loginAsk1 = "Inserisci il tuo nome utente =";
        ILanguage::loginAsk2 = "Inserisci la tua password =";
        ILanguage::loginAsk3 = "Il nome utente o la password sono errati!";
        
        ILanguage::registerAsk1 = "Inserisci il tuo nome utente =";
        ILanguage::registerAsk2 = "Inserisci la tua password =";
        ILanguage::registerAsk3 = "La registrazione ha successo";
        ILanguage::registerAsk4 = "Il nome utente o la password sono errati!";
        
        ILanguage::settingAsk = "Impostazioni";
        ILanguage::keyboardAsk1 = "Accedi";
        ILanguage::keyboardAsk2 = "Registrati";
        ILanguage::keyboardAsk3 = "Disconnessione";
        ILanguage::keyboardAsk4 = "Linguaggio";
        ILanguage::keyboardAsk5 = "Progetti";
        ILanguage::keyboardAsk6 = "Crea un progetto";
        
        ILanguage::langAsk1 = "Turca";
        ILanguage::langAsk2 = "Inglese";
        ILanguage::langAsk3 = "Italiano";
        
        ILanguage::monitorAsk1 = "Sta entrando";
        ILanguage::monitorAsk2 = "!!! Accedi prima !!!";
        
        ILanguage::calcAsk1 = "Conteggio programmatore =";
        ILanguage::calcAsk2 = "Conteggio pagine =";
        ILanguage::calcAsk3 = "Sistema operativo =";
        ILanguage::calcAsk4 = "Traduci =";
        ILanguage::calcAsk5 = "Acquisto =";
        ILanguage::calcAsk6 = "Locale =";
        ILanguage::calcAsk7 = "Remoto =";
        ILanguage::calcAsk8 = "Progettista =";
        
        ILanguage::yesA = "Si";
		ILanguage::noA = "No";  
    
        

        cout << "Generating Italian code..." << endl;
    }
};
