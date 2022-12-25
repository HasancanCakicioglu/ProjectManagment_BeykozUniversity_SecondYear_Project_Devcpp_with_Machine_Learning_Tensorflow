#include <iostream>
#include <string>
#include <ctime>
#include "UIhelper.h"
#include <math.h>
using namespace std;



void UIhelper::tire(int x){

	
	for(int i =0;i<x;i++){
		
		cout<<"-";
	}
	
	return ;
	
}

void UIhelper::middle(int x,int y,int z,string s){
	int space1,space2;
	
	if(s.length()%2 == 0){
		space1 = s.length()/2;
		space2 = s.length()/2;
	}else{
		space1 = s.length()/2;
		space2 = s.length()/2+1;
	}
	
	cout<<"|";
	empty(y-space1);
	cout<<s;
	empty(z-space2);
	cout<<"|";
		return ;
}

void UIhelper::empty(int x){
	for(int i =0;i<x;i++){
		cout<<" ";
	}
	
		return ;
}

void UIhelper::emptyUp(int x){
	for(int i =0;i<x;i++){
		cout<<endl;
	}
	
		return ;
}

void UIhelper::ana(string s){
	
	UIhelper::emptyUp(5);
	UIhelper::empty(30);
	UIhelper::tire(50);
	cout<<endl;
	UIhelper::empty(30);
	UIhelper::middle(10,24,25,s);
	
	
	cout<<endl;
	UIhelper::empty(30);
	UIhelper::tire(50);
	cout<<endl<<endl;
	UIhelper::empty(52);
	
		return ;
}

void UIhelper::anachose(string s){
	
	
	UIhelper::empty(30);
	UIhelper::tire(50);
	cout<<endl;
	UIhelper::empty(30);
	UIhelper::middle(10,24,25,s);
	
	
	cout<<endl;
	UIhelper::empty(30);
	UIhelper::tire(50);
	cout<<endl;
	//UIhelper::empty(52);
	
		return ;
}