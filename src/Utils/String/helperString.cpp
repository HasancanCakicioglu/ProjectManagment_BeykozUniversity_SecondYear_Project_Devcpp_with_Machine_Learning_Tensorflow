#include <iostream>
#include <string>
#include <ctime>
#include "helperString.h"
#include <math.h>
#include "../../Constants/Structre/timeStructre.cpp"
#include <random>
using namespace std;



bool helperString::trueFalse(int x){
    
    if(x==1){
        return true;
    }else{
        return false;
    }
}

string helperString::coutTrueFalse(bool b){
    
    return b ? "true" : "false";
}

string helperString::generateToken(){
  	string characters = "abcdefghijklmnopqrstuvwxyzABC";
  string result;

  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<> distribution(0, characters.length() - 1);

  for (int i = 0; i < 29; i++) {
    result += characters[distribution(generator)];
  }

  return result;
}
		







