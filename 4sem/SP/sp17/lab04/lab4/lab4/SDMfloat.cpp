//               xxxfloat.cpp
#include <iostream>
#include <iomanip>
#include "fsm.h"
using namespace std;

int main()
{
  tFSM Afloat;
///////////////////////

//......................

addstr(Afloat, 0, "+", 1);
addstr(Afloat, 0, "-", 1);
addstr(Afloat, 0, ".", 2);
addstr(Afloat, 0, " ", 0);
addrange(Afloat, 0, '0', '9', 1);

addrange(Afloat, 1, '0', '9', 1);
addstr(Afloat, 1, ".", 2);

addrange(Afloat, 2, '0', '9', 3);

addrange(Afloat, 3, '0', '9', 3);
addstr(Afloat, 3, "e", 4);
addstr(Afloat, 3, "E", 4);

addstr(Afloat, 4, "+", 5);
addstr(Afloat, 4, "-", 5);

addrange(Afloat, 5, '0', '9', 6);
addrange(Afloat, 6, '0', '9', 6);

Afloat.final(6);

///////////////////////
  cout << "*** SDM Afloat "
       << "size=" << Afloat.size()
       << " ***\n";
  cout << endl;

  while(true)
 {
  char input[81];
  cout << ">";
  cin.getline(input,81);
  if(!*input) break;
  int res = Afloat.apply(input);
  cout << setw(res?res+1:0) << "^"
       << endl;
 }
 return 0;
}

