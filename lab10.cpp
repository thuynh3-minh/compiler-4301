//Minh Huynh
//lab10
#include <turing.h>

using namespace std;

Turing::Turing(){
  name = "Minh Huynh";
  labNumber = 10;
  description = "{(x=, x=y) | x is in {0,1}+ and\n"
                  "             y is x in base 4}";
}

void Turing::initializeMachine() {
    machine.insert(pair<uint, TableEntry>(1, TableEntry(' ', ' ', 1, 1)));
    machine.insert(pair<uint, TableEntry>(1, TableEntry('0', '0', 1, 2)));
    machine.insert(pair<uint, TableEntry>(1, TableEntry('1', '1', 1, 2)));
    machine.insert(pair<uint, TableEntry>(1, TableEntry('=', '=', -1, 4)));

    machine.insert(pair<uint, TableEntry>(2, TableEntry('0', '0', 1, 1)));
    machine.insert(pair<uint, TableEntry>(2, TableEntry('1', '1', 1, 1)));
    machine.insert(pair<uint, TableEntry>(2, TableEntry('=', '=', -1, 3)));

    machine.insert(pair<uint, TableEntry>(3, TableEntry('0', '0', -1, 3)));
    machine.insert(pair<uint, TableEntry>(3, TableEntry('1', '1', -1, 3)));
    machine.insert(pair<uint, TableEntry>(3, TableEntry(' ', ' ', 1, 6)));

    machine.insert(pair<uint, TableEntry>(4, TableEntry('1', '1', -1, 4)));
    machine.insert(pair<uint, TableEntry>(4, TableEntry('0', '0', -1, 4)));
    machine.insert(pair<uint, TableEntry>(4, TableEntry(' ', ' ', 1, 5)));

    machine.insert(pair<uint, TableEntry>(5, TableEntry('0', '0', 1, 6)));
    machine.insert(pair<uint, TableEntry>(5, TableEntry('1', '1', 1, 7)));
    machine.insert(pair<uint, TableEntry>(5, TableEntry('=', '=', 0, 0)));

    machine.insert(pair<uint, TableEntry>(6, TableEntry('1', '=', 1, 9)));
    machine.insert(pair<uint, TableEntry>(6, TableEntry('0', ' ', 1, 8)));

    machine.insert(pair<uint, TableEntry>(7, TableEntry('1', '=', 1, 11)));
    machine.insert(pair<uint, TableEntry>(7, TableEntry('0', ' ', 1, 10)));

    machine.insert(pair<uint, TableEntry>(8, TableEntry('3', '3', 1, 8)));
    machine.insert(pair<uint, TableEntry>(8, TableEntry('2', '2', 1, 8)));
    machine.insert(pair<uint, TableEntry>(8, TableEntry('1', '1', 1, 8)));
    machine.insert(pair<uint, TableEntry>(8, TableEntry('0', '0', 1, 8)));
    machine.insert(pair<uint, TableEntry>(8, TableEntry('=', '=', 1, 8)));
    machine.insert(pair<uint, TableEntry>(8, TableEntry(' ', '0', -1, 12)));

    machine.insert(pair<uint, TableEntry>(9, TableEntry('3', '3', 1, 9)));
    machine.insert(pair<uint, TableEntry>(9, TableEntry('2', '2', 1, 9)));
    machine.insert(pair<uint, TableEntry>(9, TableEntry('1', '1', 1, 9)));
    machine.insert(pair<uint, TableEntry>(9, TableEntry('0', '0', 1, 9)));
    machine.insert(pair<uint, TableEntry>(9, TableEntry('=', '=', 1, 9)));
    machine.insert(pair<uint, TableEntry>(9, TableEntry(' ', '1', -1, 12)));

    machine.insert(pair<uint, TableEntry>(10, TableEntry('3', '3', 1, 10)));
    machine.insert(pair<uint, TableEntry>(10, TableEntry('2', '2', 1, 10)));
    machine.insert(pair<uint, TableEntry>(10, TableEntry('1', '1', 1, 10)));
    machine.insert(pair<uint, TableEntry>(10, TableEntry('0', '0', 1, 10)));
    machine.insert(pair<uint, TableEntry>(10, TableEntry('=', '=', 1, 10)));
    machine.insert(pair<uint, TableEntry>(10, TableEntry(' ', '2', -1, 12)));

    machine.insert(pair<uint, TableEntry>(11, TableEntry('3', '3', 1, 11)));
    machine.insert(pair<uint, TableEntry>(11, TableEntry('2', '2', 1, 11)));
    machine.insert(pair<uint, TableEntry>(11, TableEntry('1', '1', 1, 11)));
    machine.insert(pair<uint, TableEntry>(11, TableEntry('0', '0', 1, 11)));
    machine.insert(pair<uint, TableEntry>(11, TableEntry('=', '=', 1, 11)));
    machine.insert(pair<uint, TableEntry>(11, TableEntry(' ', '3', -1, 12)));

    machine.insert(pair<uint, TableEntry>(12, TableEntry('0', '0', -1, 12)));
    machine.insert(pair<uint, TableEntry>(12, TableEntry('1', '1', -1, 12)));
    machine.insert(pair<uint, TableEntry>(12, TableEntry('2', '2', -1, 12)));
    machine.insert(pair<uint, TableEntry>(12, TableEntry('3', '3', -1, 12)));
    machine.insert(pair<uint, TableEntry>(12, TableEntry('=', '=', -1, 13)));

    machine.insert(pair<uint, TableEntry>(13, TableEntry('1', '1', -1, 13)));
    machine.insert(pair<uint, TableEntry>(13, TableEntry('0', '0', -1, 13)));
    machine.insert(pair<uint, TableEntry>(13, TableEntry('=', '1', 1, 5)));
    machine.insert(pair<uint, TableEntry>(13, TableEntry(' ', '0', 1, 5)));
}