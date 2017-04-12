//                 code-gen.cpp 2017
#include "code-gen.h"
using namespace std;

// S -> PRED
int tCG::p01(){
 S1->obj = declarations + S1->obj;
 return 0;
}
// PRED -> HPRED BOOL )
int tCG::p02(){
 S1->obj += S2->obj+";\n}}\n";
 return 0;
}
// HPRED -> PDPAR )
int tCG::p03(){
 S1->obj += ")";
 declarations += S1->obj + ";\n"; //!!!
 S1->obj += "{{\n  return ";
 S1->count = 0;
 return 0;
}
// PDPAR -> ( define ( $idq
int tCG::p04(){
 S1->obj = "bool " + decor(S4->name) + "(";

 S1->count = 0;
 return 0;
}
// PDPAR -> PDPAR $id
int tCG::p05(){
 if(S1->count)S1->obj += ", ";// не первый параметр
 S1->obj += "double " + decor(S2->name);
 ++(S1->count);
 return 0;
}
// BOOL -> $bool
int tCG::p06(){
 S1->obj = (S1->name=="#t" ? "true" : "false");
 return 0;
}
// BOOL -> REL
  int tCG::p07(){return 0;}
// BOOL -> ( not BOOL )
  int tCG::p08()
{
	return 0;
}//?????????
// REL -> HREL E1 )
  int tCG::p09(){return 0;}//?????????
// HREL -> ( = E
  int tCG::p10()
{
	S1->obj += S1->name + S2->name + decor(S3->name);
	return 0;
}//?????????
// E -> $id
int tCG::p11(){
 S1->obj = decor(S1->name);
 return 0;
}
// E -> CONST
  int tCG::p12(){return 0;}
// E -> CPROC
  int tCG::p13(){return 0;}
// E1 -> E
  int tCG::p14(){return 0;}
// CPROC -> HCPROC )
  int tCG::p15(){return 0;}//?????????
// HCPROC -> ( $id
  int tCG::p16(){return 0;}//?????????
// HCPROC -> HCPROC E
  int tCG::p17(){return 0;}//?????????
// CONST -> $int
  int tCG::p18()
{
	S1->obj = S1->name;
	return 0;
}//?????????
// CONST -> $float
int tCG::p19(){
 S1->obj = S1->name;
 return 0;
}
// CONST -> $zero
int tCG::p20(){
 S1->obj = S1->name;
 return 0;
}
//____________________________________________________
  int tCG::p21(){return 0;}  int tCG::p22(){return 0;}
  int tCG::p23(){return 0;}  int tCG::p24(){return 0;}
  int tCG::p25(){return 0;}  int tCG::p26(){return 0;}
  int tCG::p27(){return 0;}  int tCG::p28(){return 0;}
  int tCG::p29(){return 0;}  int tCG::p30(){return 0;}
  int tCG::p31(){return 0;}  int tCG::p32(){return 0;}
  int tCG::p33(){return 0;}  int tCG::p34(){return 0;}
  int tCG::p35(){return 0;}  int tCG::p36(){return 0;}
  int tCG::p37(){return 0;}  int tCG::p38(){return 0;}
  int tCG::p39(){return 0;}  int tCG::p40(){return 0;}
  int tCG::p41(){return 0;}  int tCG::p42(){return 0;}
  int tCG::p43(){return 0;}  int tCG::p44(){return 0;}
  int tCG::p45(){return 0;}  int tCG::p46(){return 0;}
  int tCG::p47(){return 0;}  int tCG::p48(){return 0;}
  int tCG::p49(){return 0;}  int tCG::p50(){return 0;}
  int tCG::p51(){return 0;}  int tCG::p52(){return 0;}
  int tCG::p53(){return 0;}  int tCG::p54(){return 0;}
  int tCG::p55(){return 0;}  int tCG::p56(){return 0;}
  int tCG::p57(){return 0;}  int tCG::p58(){return 0;}
  int tCG::p59(){return 0;}  int tCG::p60(){return 0;}
  int tCG::p61(){return 0;}  int tCG::p62(){return 0;}
  int tCG::p63(){return 0;}  int tCG::p64(){return 0;}
  int tCG::p65(){return 0;}  int tCG::p66(){return 0;}
  int tCG::p67(){return 0;}  int tCG::p68(){return 0;}
  int tCG::p69(){return 0;}  int tCG::p70(){return 0;}
  int tCG::p71(){return 0;}  int tCG::p72(){return 0;}
  int tCG::p73(){return 0;}  int tCG::p74(){return 0;}
  int tCG::p75(){return 0;}  int tCG::p76(){return 0;}
  int tCG::p77(){return 0;}  int tCG::p78(){return 0;}
  int tCG::p79(){return 0;}  int tCG::p80(){return 0;}
  int tCG::p81(){return 0;}  int tCG::p82(){return 0;}
  int tCG::p83(){return 0;}  int tCG::p84(){return 0;}
  int tCG::p85(){return 0;}  int tCG::p86(){return 0;}
  int tCG::p87(){return 0;}  int tCG::p88(){return 0;}
  int tCG::p89(){return 0;}  int tCG::p90(){return 0;}
  int tCG::p91(){return 0;}  int tCG::p92(){return 0;}
  int tCG::p93(){return 0;}  int tCG::p94(){return 0;}
  int tCG::p95(){return 0;}  int tCG::p96(){return 0;}
  int tCG::p97(){return 0;}  int tCG::p98(){return 0;}
  int tCG::p99(){return 0;}  int tCG::p100(){return 0;}
 int tCG::p101(){return 0;} int tCG::p102(){return 0;}
 int tCG::p103(){return 0;} int tCG::p104(){return 0;}
 int tCG::p105(){return 0;} int tCG::p106(){return 0;}
 int tCG::p107(){return 0;} int tCG::p108(){return 0;}
 int tCG::p109(){return 0;} int tCG::p110(){return 0;}
