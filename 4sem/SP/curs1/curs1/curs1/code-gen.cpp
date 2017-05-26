/* $a15 */
#include "code-gen.h"
using namespace std;
int tCG::p01(){ // S -> PROG
  string header ="/*  " + lex.Authentication()+"   */\n";
  header += "#include \"mlisp.h\"\n";
  header += declarations;
  header += "//________________ \n";
  S1->obj = header + S1->obj;
	return 0;}

int tCG::p02(){ //   CALC -> E1
    S1->obj = " display(" + S1->obj + "); newline();\n";
    return 0;
}

int tCG::p03(){ //   CALC -> BOOL
    S1->obj = " display(" + S1->obj + "); newline();\n";
	return 0;}

int tCG::p04(){ //   CALC -> STR
    S1->obj = " display(" + S1->obj + "); newline();\n";
	return 0;}

int tCG::p05(){ //   CALC -> SET
	return 0;}

int tCG::p06(){ //   CALC -> DISP
	return 0;}

int tCG::p07(){ //   DISP -> ( display E1 )
    S1->obj = " display(" + S3->obj + ");\n";
	return 0;}

int tCG::p08(){ //   DISP -> ( display BOOL )
    S1->obj = " display(" + S3->obj + ");\n";
	return 0;}

int tCG::p09(){ //   DISP -> ( display STR )
    S1->obj = " display(" + S3->obj + ");\n";
	return 0;}

int tCG::p10(){ //   DISP -> ( newline )
    S1->obj += " newline();\n";
	return 0;}

int tCG::p11(){ //   PRED -> HPRED BOOL )
    S1->obj += S2->obj + ";\n}}\n";
	return 0;}

int tCG::p12(){ //  HPRED -> PDPAR )
    S1->obj += ")";
	declarations += S1->obj + ";\n"; //!!!
	S1->obj += "{{\n  return ";
	S1->count = 0;
	return 0;}

int tCG::p13(){ //  PDPAR -> ( define ( $idq
    S1->obj = "bool " + decor(S4->name) + "(";
    S1->count = 0;
	return 0;}

int tCG::p14(){ //  PDPAR -> PDPAR $id
    if (S1->count)S1->obj += ", ";
    S1->obj += "double " + decor(S2->name);
    ++(S1->count);
	return 0;}

int tCG::p15(){ //  CPROC -> HCPROC )
    S1->obj += ")";
	return 0;}

int tCG::p16(){ // HCPROC -> ( $id
    S1->obj += decor(S2->name);
	return 0;}

int tCG::p17(){ // HCPROC -> HCPROC E
    if (!S1->count)S1->obj += "(";
    if (S1->count)S1->obj += ", ";
    S1->obj += S2->obj;
    ++S1->count;
	return 0;}

int tCG::p18(){ //  CPRED -> HCPRED )
    S1->obj += ")";
	return 0;}

int tCG::p19(){ // HCPRED -> ( $idq
    S1->obj += decor(S2->name);
	return 0;}

int tCG::p20(){ // HCPRED -> HCPRED E
    if (!S1->count)S1->obj += "(";
    if (S1->count)S1->obj += ", ";
    S1->obj += S2->obj;
    ++S1->count;
	return 0;}

int tCG::p21(){ //      E -> $id
    S1->obj = decor(S1->name);
	return 0;}

int tCG::p22(){ //      E -> $zero
    S1->obj = S1->name;
	return 0;}

int tCG::p23(){ //      E -> ADD
	return 0;}

int tCG::p24(){ //      E -> SUB
	return 0;}

int tCG::p25(){ //      E -> DIV
	return 0;}

int tCG::p26(){ //      E -> MUL
	return 0;}

int tCG::p27(){ //      E -> COND
	return 0;}

int tCG::p28(){ //      E -> CPROC
	return 0;}

int tCG::p29(){ //    ADD -> HADD E1 )
    if (S1->count == 0)
        S1->obj = S2->obj;
    else
        S1->obj += S2->obj + ")";
    S1->count = 0;
	return 0;}

int tCG::p30(){ //   HADD -> ( +
    S1->obj = "(";
	return 0;}

int tCG::p31(){ //   HADD -> HADD E1
    S1->obj += S2->obj + " + ";
    ++S1->count;
	return 0;}

int tCG::p32(){ //    MUL -> HMUL E1 )
    if (S1->count == 0)
        S1->obj = S2->obj;
    else
        S1->obj += S2->obj;
    S1->count = 0;
	return 0;}

int tCG::p33(){ //   HMUL -> ( *
	return 0;}

int tCG::p34(){ //   HMUL -> HMUL E1
    S1->obj += S2->obj + " * ";
    ++S1->count;
	return 0;}

int tCG::p35(){ //   COND -> HCOND CLAUS )
	return 0;}

int tCG::p36(){ //  HCOND -> ( cond CLAUS
	return 0;}

int tCG::p37(){ //  CLAUS -> HCLAUS E1 )
	return 0;}

int tCG::p38(){ // HCLAUS -> ( BOOL
	return 0;}

int tCG::p39(){ //    STR -> $str
    S1->obj = S1->name;
	return 0;}

int tCG::p40(){ //    STR -> SIF
	return 0;}

int tCG::p41(){ //    SIF -> SIFTRUE STR )
    S1->obj += "\n\t\t:" + S2->obj;
	return 0;}

int tCG::p42(){ //SIFTRUE -> HIF STR
    S1->obj += S2->obj;
	return 0;}

int tCG::p43(){ //    HIF -> ( if BOOL
    S1->obj = S3->obj + " ? ";
	return 0;}

int tCG::p44(){ //     E1 -> E
	return 0;}

int tCG::p45(){ //    SET -> HSET E1 )
    S1->obj += " " + S2->obj;
	return 0;}

int tCG::p46(){ //   HSET -> ( set! $id
    S1->obj = decor(S3->name) + " = ";
	return 0;}

int tCG::p47(){ //  CONST -> $int
    S1->obj = S1->name;
	return 0;}

int tCG::p48(){ //  CONST -> $float
    S1->obj += S1->name + ".";
	return 0;}

int tCG::p49(){ //   PROC -> PRBODY )
    S1->obj += ";\n}}\n";
	return 0;}

int tCG::p50(){ // PRBODY -> HPROC E
    S1->obj += "\treturn (" + S2->obj + ")";
	return 0;}

int tCG::p51(){ // PRBODY -> HPROC CONST
	return 0;}
	
int tCG::p52(){ //  HPROC -> PCPAR )
    S1->obj += ")";
    declarations += S1->obj + ";\n"; //!!!
    S1->obj += "{{\n ";
    S1->count = 0;
	return 0;}
	
int tCG::p53(){ //  HPROC -> HPROC SET
    S1->obj += "\t" + S2->obj + ";\n";
	return 0;}
	
int tCG::p54(){ //  HPROC -> HPROC DISP
    S1->obj += "\t" + S2->obj;
	return 0;}
	
int tCG::p55(){ //  PCPAR -> ( define ( $id
    S1->obj = "double " + decor(S4->name) + "(";
    S1->count = 0;
	return 0;}
	
int tCG::p56(){ //  PCPAR -> PCPAR $id
    if (S1->count)S1->obj += ", ";
    S1->obj += "double " + decor(S2->name);
    ++(S1->count);
	return 0;}
	
int tCG::p57(){ //    DEF -> PRED
	return 0;}
	
int tCG::p58(){ //    DEF -> PROC
	return 0;}
	
int tCG::p59(){ //   DEFS -> DEF
	return 0;}
	
int tCG::p60(){ //   DEFS -> DEFS DEF
    S1->obj += S2->obj;
	return 0;}
	
int tCG::p61(){ //  CALCS -> CALC
	return 0;}
	
int tCG::p62(){ //  CALCS -> CALCS CALC
    S1->obj += S2->obj;
	return 0;}
	
int tCG::p63(){ // CALCS1 -> CALCS
	return 0;}
	
int tCG::p64(){ //   PROG -> CALCS1
    S1->obj = "int main(){\n" + S1->obj
        + " std::cin.get();\n return 0;\n}\n";
	return 0;}
	
int tCG::p65(){ //   PROG -> DEFS
    S1->obj += "int main(){\n"
        " display(\"No calculations!\");newline();\n"
        " std::cin.get();\nreturn 0;\n}\n";
	return 0;}

int tCG::p66(){ //   PROG -> DEFS CALCS1
    S1->obj += "int main(){\n" + S2->obj + " std::cin.get();\n return 0;\n}\n";
	return 0;}

int tCG::p67(){ //    SUB -> HSUB E1 )
	return 0;}

int tCG::p68(){ //   HSUB -> ( - E1
	return 0;}

int tCG::p69(){ //    DIV -> ( / E1 )
	return 0;}

int tCG::p70(){ //   BOOL -> $bool
	return 0;}

int tCG::p71(){ //   BOOL -> CPRED
	return 0;}

int tCG::p72(){ //   BOOL -> REL
	return 0;}

int tCG::p73(){ //   BOOL -> OR
	return 0;}

int tCG::p74(){ //   BOOL -> ( not BOOL )
	return 0;}

int tCG::p75(){ //   HREL -> ( > E
	return 0;}

int tCG::p76(){ //   HREL -> ( = E
	return 0;}

int tCG::p77(){ //     OR -> HOR BOOL )
	return 0;}

int tCG::p78(){ //    HOR -> ( or
	return 0;}

int tCG::p79(){ //    HOR -> HOR BOOL
	return 0;}

int tCG::p80(){ //    REL -> HREL E1 )
	return 0;}

//_____________________
int tCG::p81(){return 0;} int tCG::p82(){return 0;} 
int tCG::p83(){return 0;} int tCG::p84(){return 0;} 
int tCG::p85(){return 0;} int tCG::p86(){return 0;} 
int tCG::p87(){return 0;} int tCG::p88(){return 0;} 
int tCG::p89(){return 0;} int tCG::p90(){return 0;} 
int tCG::p91(){return 0;} int tCG::p92(){return 0;} 
int tCG::p93(){return 0;} int tCG::p94(){return 0;} 
int tCG::p95(){return 0;} int tCG::p96(){return 0;} 
int tCG::p97(){return 0;} int tCG::p98(){return 0;} 
int tCG::p99(){return 0;} int tCG::p100(){return 0;} 
int tCG::p101(){return 0;} int tCG::p102(){return 0;} 
int tCG::p103(){return 0;} int tCG::p104(){return 0;} 
int tCG::p105(){return 0;} int tCG::p106(){return 0;} 
int tCG::p107(){return 0;} int tCG::p108(){return 0;} 
int tCG::p109(){return 0;} int tCG::p110(){return 0;} 


