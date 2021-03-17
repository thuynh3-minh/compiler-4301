// Minh Huynh
// CS 4301
// FSA for Int
 
#include <fsa.h>
#include <cctype>
 
using namespace std;
 
FSA::FSA()
{
  name = "Minh Huynh";
  labNumber = 5;
  description = "{x | x is a valid hexadecimal integer constant in MASM}";
}
 
void FSA::initializeMachine()
{
  /*
   *----------------------------------------------next state
   *-----------------------------------------input symbol  |
   *-----------------------current state                |  |
  machine.insert(pair<uint, TableEntry>(1, TableEntry('a', 2)));
  */
 /*
for (unsigned char ch = 'A'; ch < 'z'; ++ch)
    {
    machine.insert(pair<uint, TableEntry>(1, TableEntry(ch, 1)));
    machine.insert(pair<uint, TableEntry>(3, TableEntry(ch, 4)));
    machine.insert(pair<uint, TableEntry>(4, TableEntry(ch, 4)));
    }
*/

machine.insert(pair<uint, TableEntry>(1, TableEntry('h', -1)));
machine.insert(pair<uint, TableEntry>(2, TableEntry('h', -1)));
machine.insert(pair<uint, TableEntry>(4, TableEntry('h', 5)));
machine.insert(pair<uint, TableEntry>(3, TableEntry('h', 5)));
machine.insert(pair<uint, TableEntry>(5, TableEntry('h', -1)));

machine.insert(pair<uint, TableEntry>(1, TableEntry('H', -1)));
machine.insert(pair<uint, TableEntry>(2, TableEntry('H', -1)));
machine.insert(pair<uint, TableEntry>(4, TableEntry('H', 5)));
machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 5)));
machine.insert(pair<uint, TableEntry>(5, TableEntry('H', -1)));

machine.insert(pair<uint, TableEntry>(1, TableEntry('%', -1)));
machine.insert(pair<uint, TableEntry>(2, TableEntry('%', -1)));
machine.insert(pair<uint, TableEntry>(3, TableEntry('%', -1)));
machine.insert(pair<uint, TableEntry>(4, TableEntry('%', -1)));
machine.insert(pair<uint, TableEntry>(5, TableEntry('%', 0)));
	
machine.insert(pair<uint, TableEntry>(1, TableEntry('+', 2)));
machine.insert(pair<uint, TableEntry>(1, TableEntry('-', 2)));
machine.insert(pair<uint, TableEntry>(4, TableEntry('+', -1)));
machine.insert(pair<uint, TableEntry>(4, TableEntry('-', -1)));
machine.insert(pair<uint, TableEntry>(3, TableEntry('+', -1)));
machine.insert(pair<uint, TableEntry>(3, TableEntry('-', -1)));
machine.insert(pair<uint, TableEntry>(2, TableEntry('+', -1)));
machine.insert(pair<uint, TableEntry>(2, TableEntry('-', -1)));
machine.insert(pair<uint, TableEntry>(5, TableEntry('+', -1)));
machine.insert(pair<uint, TableEntry>(5, TableEntry('-', -1)));
 
for (char ch = '0'; ch <= '9'; ++ch)
  {
    machine.insert(pair<uint, TableEntry>(1, TableEntry(ch, 3)));
    machine.insert(pair<uint, TableEntry>(2, TableEntry(ch, 3)));
    machine.insert(pair<uint, TableEntry>(3, TableEntry(ch, 3)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry(ch, -1)));
    machine.insert(pair<uint, TableEntry>(5, TableEntry(ch, -1)));
  }
for (char ch = 'A' ; ch <= 'F'; ++ch)
{
	machine.insert(pair<uint, TableEntry>(1, TableEntry(ch, -1)));
    machine.insert(pair<uint, TableEntry>(2, TableEntry(ch, -1)));
    machine.insert(pair<uint, TableEntry>(3, TableEntry(ch, 4)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry(ch, 4)));
    machine.insert(pair<uint, TableEntry>(5, TableEntry(ch, -1)));
}
for (char ch = 'a' ; ch <= 'f'; ++ch)
{
	machine.insert(pair<uint, TableEntry>(1, TableEntry(ch, -1)));
    machine.insert(pair<uint, TableEntry>(2, TableEntry(ch, -1)));
    machine.insert(pair<uint, TableEntry>(3, TableEntry(ch, 4)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry(ch, 4)));
    machine.insert(pair<uint, TableEntry>(5, TableEntry(ch, -1)));
}
 
//machine.insert(pair<uint, TableEntry>(3, TableEntry('%', 0)));
//machine.insert(pair<uint, TableEntry>(4, TableEntry('%', 0)));





}
