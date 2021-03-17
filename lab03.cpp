//Minh Huynh
//CS 4301
//lab 03
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


bool isValid(string s)
{
  int state = 0;
  string::iterator itr;
 
  for (itr = s.begin(); itr != s.end(); ++itr)
    switch (state)
    {
      case 0: if (*itr =='a')
                state = 1;
              else if (*itr == 'b'){
				  if( next(itr) == s.end())
					  return false;
				  else
					  state = 2;
			  }
              break;
      case 1: if (*itr == 'a')
                state = 1;    
              else if (*itr == 'b')
                state = 0;
              else
                return true;
              break;           
      case 2: if (*itr == 'b')
                return false;
              else if (*itr == 'a')
                state = 0;
              break;           
           
    }
 
  return true;
}