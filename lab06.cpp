//Minh Huynh
//CS 4301
//lab06

#include <pda.h>

using namespace std;

PDA::PDA()
{
	name = "Minh Huynh";
	labNumber = 6;
	description = "{a^ib^jc^k | i + k = j}";
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
	
	machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '%', " *", 0)));
	machine.insert(pair<uint, TableEntry>(1, TableEntry('*', 'a', "+a", 2)));
	machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'b', "+b", 4)));
	
	machine.insert(pair<uint, TableEntry>(2, TableEntry('*', 'a', "+a", 2)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 'b', "-a", 3)));
	
	machine.insert(pair<uint, TableEntry>(3, TableEntry('@', 'b', "+b", 4)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('a', 'b', "-a", 3)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('@', '%', " *", 0)));
	
	machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 'b', "+b", 4)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 'c', "-b", 5)));
	machine.insert(pair<uint, TableEntry>(5, TableEntry('b', 'c', "-b", 5)));
	machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '%', " *", 0)));

	
}
