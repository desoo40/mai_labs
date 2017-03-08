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
addrange(Afloat,0,'0','9',2);
addstr(Afloat,0,"+",1);
addstr(Afloat,0,"-",1);
addrange(Afloat,1 ,'0','9',2);
addrange(Afloat,2 ,'0','9',2);
addstr(Afloat,2,".",3);
addrange(Afloat,3 ,'0','9',3);
addstr(Afloat,3,"e",4);
addstr(Afloat,3,"E",4);
addstr(Afloat,4,"+", 5);
addstr(Afloat,4 ,"-",5);
addrange(Afloat,5 ,'0','9',6);
addrange(Afloat,4 ,'0','9',6);
addrange(Afloat,6 ,'0','9',6);
Afloat.final(6);





///////////////////////
  cout << "*** xxx Afloat "
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

