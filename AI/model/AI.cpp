#include <tuple>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "AI.h"
#include "../Math/ProjectManagmentWeightsBias.h"
#include "../Random/randomInitialize.h"
#include <cstdio>
#include  <cmath>
#include <limits>
#include <tuple>

using namespace std;


float truncateTo3Decimals(float value) {
  return floorf(value * 1000) / 1000;
}


tuple<double,double> AI::predict(double predictModel[1][16]){
   
	
   double myC[1][32];
   double myS[1][64];
   double myT[1][128];
   double myF[1][2];
  
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 32; j++) {
    	myC[i][j] = 0;
      for (int k = 0; k < 16; k++) {
        myC[i][j] += predictModel[i][k] * weights1[k][j];
      }
    }
  }
  
  for(int i =0;i<32;i++){
  	
  	myC[0][i] = myC[0][i] + bias1[i];
  }
  
  
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 64; j++) {
    	myS[i][j] =0;
      for (int k = 0; k < 32; k++) {
        myS[i][j] += myC[i][k] * weights2[k][j];
      }
    }
  }
  
  for(int i =0;i<64;i++){
  	
  	myS[0][i] = myS[0][i] + bias2[i];
  }
  
  
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 128; j++) {
    	myT[i][j] =0;
      for (int k = 0; k < 64; k++) {
        myT[i][j] += myS[i][k] * weights3[k][j];
        
  }
}}
  
  for(int i =0;i<128;i++){
  	
  	myT[0][i] = myT[0][i] + bias3[i];

  }
  
  
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 2; j++) {
    	myF[i][j] =0;
      for (int k = 0; k < 128; k++) {
       
        myF[i][j] +=myT[i][k] * weights4[k][j]; 

      }
    }
  }
  
  for(int i =0;i<2;i++){
  	
  	myF[0][i] = myF[0][i] + bias4[i];
  
  	
  }
  
  
  cout<<endl<<myF[0][0]<<" - "<<myF[0][1]<<endl;
	
	return make_tuple(myF[0][0],myF[0][1]);
	
}


void AI::createCSV(string word1, string word2, string word3, string word4, string word5, string word6, string word7, string word8, string word9, string word10, string word11, string word12, string word13, string word14, string word15, string word16, string word17, string word18){
	
	int dizi[16][2] = {{random::programmerDown,random::programmerUp},{random::pageDown, random::pageUp},{random::androidDown, random::androidUp},{random::iosDown, random::iosUp},{random::windowsDown, random::windowsUp},{random::linuxDown, random::linuxUp},{random::webDown, random::webUp},{random::macDown, random::macUp},{random::beginnerDown, random::beginnerUp},{random::middleDown, random::middleUp},{random::profDown, random::profUp},{random::businessDown, random::businessUp},{random::purchaseDown, random::purchaseUp},{random::localDataBaseDown, random::localDataBaseUp},{random::remoteDataBaseDown, random::remoteDataBaseUp},{random::designerDown, random::designerUp}}; 
	
	ofstream outfile("output.csv");

  // Write the column names to the file
  outfile << word1 << ";" << word2 << ";" << word3 << ";" << word4 << ";" << word5 << ";" << word6 << ";" << word7 << ";" << word8 << ";" << word9 << ";" << word10 << ";" << word11 << ";" << word12 << ";" << word13 << ";" << word14 << ";" << word15 << ";" << word16 << ";" << word17 << ";" << word18 <<"\n";

  // Seed the random number generator
  srand(time(NULL));


  // Write 5 rows of random integers to the file
  for (int i = 0; i < 1000; i++) {
    int num1 = (rand() % (dizi[0][1] - dizi[0][0])) + dizi[0][0];
    int num2 = (rand() % (dizi[1][1] - dizi[1][0])) + dizi[1][0];
    int num3 = (rand() % (dizi[2][1] - dizi[2][0])) + dizi[2][0];
    int num4 = (rand() % (dizi[3][1] - dizi[3][0])) + dizi[3][0];
    int num5 = (rand() % (dizi[4][1] - dizi[4][0])) + dizi[4][0];
    int num6 = (rand() % (dizi[5][1] - dizi[5][0])) + dizi[5][0];
    int num7 = (rand() % (dizi[6][1] - dizi[6][0])) + dizi[6][0];
    int num8 = (rand() % (dizi[7][1] - dizi[7][0])) + dizi[7][0];
    int num9 = (rand() % (dizi[8][1] - dizi[8][0])) + dizi[8][0];
    int num10 = (rand() % (dizi[9][1] - dizi[9][0])) + dizi[9][0];
    int num11 = (rand() % (dizi[10][1] - dizi[10][0])) + dizi[10][0];
    int num12 = (rand() % (dizi[11][1] - dizi[11][0])) + dizi[11][0];
    int num13 = (rand() % (dizi[12][1] - dizi[12][0])) + dizi[12][0];
    int num14 = (rand() % (dizi[13][1] - dizi[13][0])) + dizi[13][0];
    int num15 = (rand() % (dizi[14][1] - dizi[14][0])) + dizi[14][0];
    int num16 = (rand() % (dizi[15][1] - dizi[15][0])) + dizi[15][0];
    
    int programmerC = rand() % 10 + 1;
    int pageC = rand() % 50 + 1;
	int androidC = rand() % 2;
	int iosC = rand() % 2;
	int windowsC = rand() % 2;
	int linuxC = rand() % 2;
	int webC = rand() % 2;
	int macC = rand() % 2;
    int purchaseC = rand() % 2; 
	int localDataC = rand() % 2;
	int remoteDataC = rand() % 2;
	int designerC = rand() % 2;
	
	int levelC = rand() % 4 + 1;
	
	int beginnerC = levelC == 1 ? 1 : 0;
	int middleC = levelC == 2 ? 1 : 0;
	int profC = levelC == 3 ? 1 : 0;
	int businessC = levelC == 4 ? : 0; 
	
	int price = (num1 * programmerC) + (num2 * pageC) + (num3 * androidC) + (num4 * iosC) + (num5 * windowsC) + (num6 * linuxC) + (num7 * webC) + (num8 * macC) + (num9 * beginnerC) + (num10 * middleC) + (num11 * profC) + (num12 * businessC) + (num13 * purchaseC) + (num14 * localDataC) + (num15 * remoteDataC) + (num16 * designerC);
		
    //int price = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10 + num11 + num12 + num13 + num14 + num15 + num16;
    double time = price / 500;
    
    
    outfile << programmerC << ";" << pageC << ";" << androidC << ";" << iosC << ";" << windowsC << ";" << linuxC << ";" << webC << ";" << macC << ";" << beginnerC << ";" << middleC << ";" << profC << ";" << businessC << ";" << purchaseC << ";" << localDataC << ";" << remoteDataC << ";" << designerC << ";" << price << ";" << time << "\n ";
  }

  outfile.close();
	
}

