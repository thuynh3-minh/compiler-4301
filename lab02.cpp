//Minh Huynh
//CS 4301
//lab 02
#include <iostream>
#include <cstdlib>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
bool isValid(string str){
	deque<char> d = {};
	for(uint i = 0; i< str.length(); i++){
		d.push_back(str[i]);
	}
	for(uint i = 0; i< str.length(); i++){
		if(d[0] == 'a' && d[1] == 'a'){
			d.pop_front();
		}
		if(d[0] == 'a' && d[1] == 'b'){
			d.pop_front();
			d.pop_front();
		}
		if(d[0] == 'b' && d[1] == 'a'){
			d.pop_front();
			d.pop_front();
		}
	}
	char b = 'b';
	if(find(d.begin(), d.end(), b) != d.end()){
		return false;
	}
	else
		return true;
	
	
	//if i = a and j = a popfront once to keep an a
	//id i =a and j = b pop front twice to delete ab
	//if i = b and j = a pop front twice to delete ba
	
	
	
	
	
/* 	int n = str.length();
	int i;
	int numA = 0;
	int numB = 0;
	for (int j =0; j< n; j++){
		if (j == 'a')
			numA+=1;
		else 
			numB += 1;
	}
	if(numB> numA)
		return false;
	
	if(n==0){
		return true;
	}
	else if(n==1){
		return (str[0] == 'a');
	}
	else{
		for (i = 0; i< n; i++){
			if(str[i] == 'b'){
				if(str[i-1] != 'a' && str[i+1] != 'a')
					return false;
			}
			if(str[i] == 'a'){
				if(str[i+1] == 'b' && str[i-1] == 'b'){
					if(str[i+2] == 'b' || str[i-2]== 'b')
						return false;
				}
			}
		}
		return true;
	} */
	
	
}
