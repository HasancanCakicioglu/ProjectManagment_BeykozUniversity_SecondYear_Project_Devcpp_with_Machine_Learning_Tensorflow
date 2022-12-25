#ifndef Keyboard_H
#define Keyboard_H
#include <iostream>
#include <string>
#include <ctime>
//#include "../Constants/Keyboard/define.h"
using namespace std;




class Keyboard {
private:
    static Keyboard* instance;
    

    // Private constructor to prevent creating instances from outside the class
    Keyboard() : key(1) , keyLanguage(1) {}

public:
    static Keyboard* getInstance() {
        if (instance == nullptr) {
            instance = new Keyboard();
        }
        return instance;
    }
    
    bool pageController();
    void keyControl();
    void keyControlLanguage();
    void ayarlarLanguage();
    void func();

    int key;
    int keyLanguage;
};

#endif