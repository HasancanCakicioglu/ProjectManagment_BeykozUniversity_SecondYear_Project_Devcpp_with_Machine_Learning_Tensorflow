#ifndef AI_H
#define AI_H
#include <iostream>
#include <string>
#include <tuple>
using namespace std;




class AI
{
	public:
		tuple<double,double> predict(double predictModel[1][16]);
		void createCSV(string word1, string word2, string word3, string word4, string word5, string word6, string word7, string word8, string word9, string word10, string word11, string word12, string word13, string word14, string word15, string word16, string word17, string word18);
		
		
};

#endif