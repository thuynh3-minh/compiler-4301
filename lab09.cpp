//Minh Huynh
//lab09
#include <turing.h>

using namespace std;

Turing::Turing(){
  name = "Minh Huynh";
  labNumber = 9;
  description = "{(x=, x=x^R==pal) | x is in {a,b}*,\n"
  "                    x^R = reverse of x,\n"
  "                    pal = 0 if x is not a palindrome, and\n"
  "                    pal = 1 if x is a palindrome}";
}

void Turing::initializeMachine() {
    machine.insert(pair<uint, TableEntry>(1, TableEntry(' ', ' ', 1, 1)));
    machine.insert(pair<uint, TableEntry>(1, TableEntry('a', 'a', 1, 2)));
    machine.insert(pair<uint, TableEntry>(1, TableEntry('b', 'b', 1, 2)));
    machine.insert(pair<uint, TableEntry>(1, TableEntry('=', '=', -1, 3)));

    machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 'a', 1, 2)));
    machine.insert(pair<uint, TableEntry>(2, TableEntry('b', 'b', 1, 2)));
    machine.insert(pair<uint, TableEntry>(2, TableEntry('=', '=', -1, 3)));

    machine.insert(pair<uint, TableEntry>(3, TableEntry('a', 'x', 1, 4)));
    machine.insert(pair<uint, TableEntry>(3, TableEntry('b', 'y', 1, 5)));
    machine.insert(pair<uint, TableEntry>(3, TableEntry(' ', ' ', 1, 7)));

    machine.insert(pair<uint, TableEntry>(4, TableEntry('a', 'a', 1, 4)));
    machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 'b', 1, 4)));
    machine.insert(pair<uint, TableEntry>(4, TableEntry('=', '=', 1, 4)));
    machine.insert(pair<uint, TableEntry>(4, TableEntry(' ', 'a', -1, 6)));

    machine.insert(pair<uint, TableEntry>(5, TableEntry('a', 'a', 1, 5)));
    machine.insert(pair<uint, TableEntry>(5, TableEntry('b', 'b', 1, 5)));
    machine.insert(pair<uint, TableEntry>(5, TableEntry('=', '=', 1, 5)));
    machine.insert(pair<uint, TableEntry>(5, TableEntry(' ', 'b', -1, 6)));

    machine.insert(pair<uint, TableEntry>(6, TableEntry('a', 'a', -1, 6)));
    machine.insert(pair<uint, TableEntry>(6, TableEntry('b', 'b', -1, 6)));
    machine.insert(pair<uint, TableEntry>(6, TableEntry('=', '=', -1, 6)));
    machine.insert(pair<uint, TableEntry>(6, TableEntry('x', 'a', -1, 3)));
    machine.insert(pair<uint, TableEntry>(6, TableEntry('y', 'b', -1, 3)));

    machine.insert(pair<uint, TableEntry>(7, TableEntry('a', 'x', 1, 8)));
    machine.insert(pair<uint, TableEntry>(7, TableEntry('b', 'y', 1, 9)));
    machine.insert(pair<uint, TableEntry>(7, TableEntry('=', '=', 1, 18)));

    machine.insert(pair<uint, TableEntry>(8, TableEntry('a', 'a', 1, 8)));
    machine.insert(pair<uint, TableEntry>(8, TableEntry('b', 'b', 1, 8)));
    machine.insert(pair<uint, TableEntry>(8, TableEntry('=', '=', 1, 10)));

    machine.insert(pair<uint, TableEntry>(9, TableEntry('a', 'a', 1, 9)));
    machine.insert(pair<uint, TableEntry>(9, TableEntry('b', 'b', 1, 9)));
    machine.insert(pair<uint, TableEntry>(9, TableEntry('=', '=', 1, 11)));

    machine.insert(pair<uint, TableEntry>(10, TableEntry('x', 'x', 1, 10)));
    machine.insert(pair<uint, TableEntry>(10, TableEntry('y', 'y', 1, 10)));
    machine.insert(pair<uint, TableEntry>(10, TableEntry('a', 'x', -1, 12))); 
    machine.insert(pair<uint, TableEntry>(10, TableEntry('b', 'b', -1, 14))); 

    machine.insert(pair<uint, TableEntry>(11, TableEntry('x', 'x', 1, 11)));
    machine.insert(pair<uint, TableEntry>(11, TableEntry('y', 'y', 1, 11)));
    machine.insert(pair<uint, TableEntry>(11, TableEntry('b', 'y', -1, 12))); 
    machine.insert(pair<uint, TableEntry>(11, TableEntry('a', 'a', -1, 14))); 
    
    machine.insert(pair<uint, TableEntry>(12, TableEntry('x', 'x', -1, 12)));
    machine.insert(pair<uint, TableEntry>(12, TableEntry('y', 'y', -1, 12)));
    machine.insert(pair<uint, TableEntry>(12, TableEntry('=', '=', -1, 13)));

    machine.insert(pair<uint, TableEntry>(13, TableEntry('a', 'a', -1, 13)));
    machine.insert(pair<uint, TableEntry>(13, TableEntry('b', 'b', -1, 13)));
    machine.insert(pair<uint, TableEntry>(13, TableEntry('x', 'a', 1, 7)));
    machine.insert(pair<uint, TableEntry>(13, TableEntry('y', 'b', 1, 7)));

    machine.insert(pair<uint, TableEntry>(14, TableEntry('x', 'x', -1, 14)));
    machine.insert(pair<uint, TableEntry>(14, TableEntry('y', 'y', -1, 14)));
    machine.insert(pair<uint, TableEntry>(14, TableEntry('b', 'b', -1, 14)));
    machine.insert(pair<uint, TableEntry>(14, TableEntry('a', 'a', -1, 14)));
    machine.insert(pair<uint, TableEntry>(14, TableEntry('=', '=', -1, 14)));
    machine.insert(pair<uint, TableEntry>(14, TableEntry(' ', ' ', 1, 15)));

    machine.insert(pair<uint, TableEntry>(15, TableEntry('a', 'a', 1, 15)));
    machine.insert(pair<uint, TableEntry>(15, TableEntry('b', 'b', 1, 15)));
    machine.insert(pair<uint, TableEntry>(15, TableEntry('x', 'a', 1, 15)));
    machine.insert(pair<uint, TableEntry>(15, TableEntry('y', 'b', 1, 15)));
    machine.insert(pair<uint, TableEntry>(15, TableEntry('=', '=', 1, 15)));
    machine.insert(pair<uint, TableEntry>(15, TableEntry(' ', '=', 1, 16)));

    machine.insert(pair<uint, TableEntry>(16, TableEntry(' ', '=', 1, 17)));

    machine.insert(pair<uint, TableEntry>(17, TableEntry(' ', '0', 0, 0)));

    machine.insert(pair<uint, TableEntry>(18, TableEntry('x', 'a', 1, 18)));
    machine.insert(pair<uint, TableEntry>(18, TableEntry('y', 'b', 1, 18)));
    machine.insert(pair<uint, TableEntry>(18, TableEntry(' ', '=', 1, 19)));

    machine.insert(pair<uint, TableEntry>(19, TableEntry(' ', '=', 1, 20)));

    machine.insert(pair<uint, TableEntry>(20, TableEntry(' ', '1', 0, 0)));
}