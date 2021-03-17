//Minh HUynh
//CS 4301
//lab 04

#include <fsa.h>
using namespace std;

FSA::FSA()
{
	name = "Minh Huynh";
	labNumber = 4;
	description = "{x | x is in {0, 1}+, and the number of 0's preceding each 1 in x is odd}";
}
 
void FSA::initializeMachine()
{
    // Example from notes
  /*
   *----------------------------------------------next state
   *-----------------------------------------input symbol  |
   *-----------------------current state                |  | */
  machine.insert(pair<uint, TableEntry>(1, TableEntry('0', 2)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('%', -1)));  
  machine.insert(pair<uint, TableEntry>(2, TableEntry('%', 0)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('1', 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('0', 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('%', 0)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('0', 4)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('1', -1)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('%', 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('0', 3)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('1', 3)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('1', 2)));

}