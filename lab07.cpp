//Minh Huynh
//CS 4301
//lab07 
#include <pda.h>

using namespace std;

PDA::PDA()
{
	name = "Minh Huynh";
	labNumber = 7;
	description = "{w | w in {a, b}* and w has twice as many a's as b's}";
}

void PDA::initializeMachine()
{
	// Example from notes
	/*
	 *---------------------------------------------------------next state
	 *--------------------------------------------------------push pop  |
	 *----------------------------------------------input symbol     |  |
	 *-----------------------------------------stack symbol    |     |  |
	 *------------------------current state               |    |     |  |  */
	/*
	machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '%', " *", 0)));
	machine.insert(pair<uint, TableEntry>(1, TableEntry('*', 'a', "+a", 2)));
	//machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'b', "+b", 4)));
	
	machine.insert(pair<uint, TableEntry>(2, TableEntry('*', 'a', "+a", 2)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 'b', "-a", 3)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('a', '*', "-a", 4)));
	
	//machine.insert(pair<uint, TableEntry>(3, TableEntry('@', 'b', "+b", 4)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('a', '*', "+b", 6)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('a', '*', " *", 2)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '*', " *", 1)));
	
	
	
	machine.insert(pair<uint, TableEntry>(1, TableEntry('*', 'b', "+b", 5)));
	machine.insert(pair<uint, TableEntry>(5, TableEntry('*', '*', "+b", 6)));
	machine.insert(pair<uint, TableEntry>(6, TableEntry('*', 'b', "+b", 5)));
	machine.insert(pair<uint, TableEntry>(6, TableEntry('b', 'a', "-b", 7)));
	machine.insert(pair<uint, TableEntry>(7, TableEntry('b', 'a', "-b", 7)));
	machine.insert(pair<uint, TableEntry>(7, TableEntry('*', 'b', "+b", 5)));
	//machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '%', " *", 0)));
	//machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 'b', "+b", 4)));
	//machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 'c', "-b", 5)));
	//machine.insert(pair<uint, TableEntry>(5, TableEntry('b', 'c', "-b", 5)));
	//machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '%', " *", 0)));*/
	/*
	machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '%', " *", 0)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '%', " *", 0)));
	machine.insert(pair<uint, TableEntry>(1, TableEntry('*', 'a', "+a", 2)));
	//machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'b', "+b", 4)));
	
	machine.insert(pair<uint, TableEntry>(2, TableEntry('*', 'a', "+a", 2)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('*', 'b', "-a", 3)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('*', '*', "-a", 2)));*/
	
	
	machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '%', " *", 0)));
	machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'a', "+a", 1)));
	machine.insert(pair<uint, TableEntry>(1, TableEntry('a', 'a', "+a", 1)));
	
	machine.insert(pair<uint, TableEntry>(1, TableEntry('a', 'b', "-a", 2)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('a', '*', "-a", 1)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '*', "+b", 1)));
	
	machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'b', "+b", 3)));
	machine.insert(pair<uint, TableEntry>(1, TableEntry('b', 'b', "+b", 3)));
	
	machine.insert(pair<uint, TableEntry>(3, TableEntry('*', '*', "+b", 1)));
	
	machine.insert(pair<uint, TableEntry>(1, TableEntry('b', 'a', "-b", 1)));
	
	//machine.insert(pair<uint, TableEntry>(2, TableEntry('*', '*', "-a", 1)));
	//machine.insert(pair<uint, TableEntry>(3, TableEntry('@', 'b', "+b", 4)));
	//machine.insert(pair<uint, TableEntry>(1, TableEntry('*', 'b', "%",2)));
	//machine.insert(pair<uint, TableEntry>(4, TableEntry('a', '*', " *", 2)));
	//machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '*', " *", 1)));

	
}