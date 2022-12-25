#include "ILanguage.cpp"
using namespace std;


class Turkish : public ILanguage
{
public:
    // Override the generateCode() method
    void generateCode() override
    {
        // Set the language to Turkish
        ILanguage::language = "Turkish";
        ILanguage::nameAsk = "Proje isminiz = ";
        ILanguage::programmerAsk = "Kac programci calisacak ?";
        ILanguage::pageAsk = "Kac sayfa olacak?";
        ILanguage::opAsk = "Hangi isletim sistemleri ile uyumlu olacak?";
        ILanguage::hostAsk = "Hangi seviye barındırma hizmetini kullanacaksiniz? =";
        ILanguage::languageAsk = "Dil seçeneği olsun mu?";
        ILanguage::purchaseAsk = "Uygulama ici satın alma eklensin mi?";
        ILanguage::localAsk = "Yerel veritabani kullanilacak mı?";
        ILanguage::remoteAsk = "Uzakt veritabani kullanilacak mı?";
        ILanguage::designerAsk = "UI tasarimcisini kullanmak istiyor musunuz?";
        
        ILanguage::hostAsk1 = "1 - Baslangic";
        ILanguage::hostAsk2 = "2 - Orta";
        ILanguage::hostAsk3 = "3 - Prof";
        ILanguage::hostAsk4 = "4 - Ust seviye";
        
        
        ILanguage::loginAsk1 = "Lutfen kullanıcı adınızı giriniz =";
        ILanguage::loginAsk2 = "Lutfen sifrenizi giriniz =";
        ILanguage::loginAsk3 = "Kullanıcı ismi veya parola yanlış!";
        
        ILanguage::registerAsk1 = "Lütfen kullanıcı adınızı giriniz =";
        ILanguage::registerAsk2 = "Lütfen şifrenizi giriniz =";
        ILanguage::registerAsk3 = "Kayıt Başarılı";
        ILanguage::registerAsk4 = "Kullanıcı ismi veya parola yanlış!";
        
        ILanguage::settingAsk = "Ayarlar";
        ILanguage::keyboardAsk1 = "Giris Yap";
        ILanguage::keyboardAsk2 = "Kayit ol";
        ILanguage::keyboardAsk3 = "Cikis yap";
        ILanguage::keyboardAsk4 = "Dil degistir";
        ILanguage::keyboardAsk5 = "Projeler";
        ILanguage::keyboardAsk6 = "Proje olustur";
        
        ILanguage::langAsk1 = "Turkce";
        ILanguage::langAsk2 = "Ingilizce";
        ILanguage::langAsk3 = "Italyanca";
        
        ILanguage::monitorAsk1 = "Giriyor";
        ILanguage::monitorAsk2 = "!!! Once Giris Yapin !!!";
        
        ILanguage::calcAsk1 = "Programcı Sayisi = ";
        ILanguage::calcAsk2 = "Sayfa Sayisi =";
        ILanguage::calcAsk3 = "Isletim Sistemi =";
        ILanguage::calcAsk4 = "Ceviri =";
        ILanguage::calcAsk5 = "Satın al =";
        ILanguage::calcAsk6 = "Yerel =";
        ILanguage::calcAsk7 = "Uzak =";
        ILanguage::calcAsk8 = "Tasarimci =";
    
        ILanguage::yesA = "Evet";
		ILanguage::noA = "Hayir";  

        cout << "Generating Turkish code..." << endl;
    }
};
