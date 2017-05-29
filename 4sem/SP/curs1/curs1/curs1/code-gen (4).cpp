/* $d04 */
#include "code-gen.h"
using namespace std;
int tCG::p01(){ // S -> PROG
  string header ="/*  " + lex.Authentication()+"   */\n";
  header += "#include \"mlisp.h\"\n";
  header += declarations;
  header += "//________________ \n";
  S1->obj = header + S1->obj;
	return 0;}
int tCG::p02()
{
    //   CALC -> E1
    S1->obj = "display(" + S1->obj + "); newline();\n";
	return 0;
}
int tCG::p03()
{
    //   CALC -> BOOL
    S1->obj = "display(" + S1->obj + "); newline();\n";
	return 0;
}
int tCG::p04()
{
    //   CALC -> STR
    S1->obj = "display(" + S1->obj + "); newline();\n";
	return 0;
}
int tCG::p05()
{
    //   CALC -> SET
    S1->obj += "; newline();\n";
	return 0;
}
int tCG::p06()
{
    //   CALC -> DISP
    S1->obj += "; newline();\n";
	return 0;
}
int tCG::p07()
{
    //   DISP -> ( display E1 )
    S1->obj = "display(" + S3->obj + ")";
	return 0;
}
int tCG::p08()
{
    //   DISP -> ( display BOOL )
    S1->obj = "display(" + S3->obj + ")";
	return 0;
}
int tCG::p09()
{
    //   DISP -> ( display STR )
    S1->obj = "display(" + S3->obj + ")";
	return 0;
}
int tCG::p10()
{
    //   DISP -> ( newline )
    S1->obj = "newline()";
	return 0;
}
int tCG::p11()
{
    //   PRED -> HPRED BOOL )
    S1->obj += S2->obj + ";\n}}\n";
	return 0;
}
int tCG::p12()
{
    //  HPRED -> PDPAR )
    S1->obj += ")";
	declarations += S1->obj + ";\n";
	S1->obj += "\n{{\nreturn ";
	return 0;
}
int tCG::p13()
{
    //  PDPAR -> ( define ( $idq
    S1->obj = "bool " + decor(S4->name) + "(";
	S1->count = 0;
	return 0;
}
int tCG::p14()
{
    //  PDPAR -> PDPAR $id
    if (S1->count > 0)
		S1->obj += ", ";

	S1->obj += "double " + decor(S2->name);
	++S1->count;
	return 0;
}
int tCG::p15()
{
    //  CONST -> $int
    S1->obj = S1->name+".";
	return 0;
}
int tCG::p16()
{
    //  CONST -> $float
    S1->obj = S1->name;
	return 0;
}
int tCG::p17()
{
    //      E -> $id
    S1->obj = decor(S1->name);
	return 0;
}
int tCG::p18()
{
    //      E -> $zero
	return 0;
}
int tCG::p19()
{
    //      E -> ADD
	return 0;
}
int tCG::p20()
{
    //      E -> SUB
	return 0;
}
int tCG::p21()
{
    //      E -> DIV
	return 0;
}
int tCG::p22()
{
    //      E -> MUL
	return 0;
}
int tCG::p23()
{
    //      E -> COND
	return 0;
}
int tCG::p24()
{
    //      E -> CPROC
	return 0;
}
int tCG::p25()
{
    //    ADD -> HADD E1 )
    S1->obj+=S2->obj+")";
	return 0;
}
int tCG::p26()
{
    //   HADD -> ( +
    S1->obj="(";
	return 0;
}
int tCG::p27()
{
    //   HADD -> HADD E1
    S1->obj += S2->obj + " + ";
    ++S1->count;
	return 0;
}
int tCG::p28()
{
    //    MUL -> HMUL E1 )
    S1->obj+=S2->obj+")";
	return 0;
}
int tCG::p29()
{
    //   HMUL -> ( *
    S1->obj ="(";
	return 0;
}
int tCG::p30()
{
    //   HMUL -> HMUL E1
    S1->obj+=S2->obj+"*";
	return 0;
}
int tCG::p31()
{
    //    SUB -> HSUB E1 )
    if(S1->count == 1) {
        S1->obj+="-"+S2->obj+")";
    } else {
        S1->obj+=S2->obj+")";
    }
    S1->count++;
	return 0;
}
int tCG::p32()
{
    //   HSUB -> ( - E1
    S1->obj= "("+S3->obj+ "-";
    S1->count = 0;
	return 0;
}
int tCG::p33()
{
    //    DIV -> HDIV E1 )
    if(S1->count == 1){
        S1->obj="1/"+S2->obj+")";
    }
    else {
        S1->obj+=S2->obj+")";
    }
	return 0;
}
int tCG::p34()
{
    //   HDIV -> ( /
    S1->obj = "((double)";
	S1->count = 1;

	return 0;
}
int tCG::p35()
{
    //   HDIV -> HDIV E1
    S1->obj += S2->obj + " / ";
	++S1->count;

	return 0;
}
int tCG::p36()
{
    //  CPROC -> HCPROC )
    S1->obj += ")";
	return 0;
}
int tCG::p37()
{
    // HCPROC -> ( $id
    S1->obj = decor(S2->name) + "(";
	S1->count = 0;
	return 0;
}
int tCG::p38()
{
    // HCPROC -> HCPROC E
    if (S1->count > 0)
		S1->obj += ", ";

	S1->obj += S2->obj;
	++S1->count;
	return 0;
}
int tCG::p39()
{
    //  CPRED -> HCPRED )
    S1->obj += ")";
	return 0;
}
int tCG::p40()
{
    // HCPRED -> ( $idq
    S1->obj = decor(S2->name) + "(";
	S1->count = 0;
	return 0;
}
int tCG::p41()
{
    // HCPRED -> HCPRED E
    if (S1->count > 0)
		S1->obj += ", ";

	S1->obj += S2->obj;
	++S1->count;
	return 0;
}
int tCG::p42()
{
    //   COND -> HCOND ELSE )
    S1->obj += S2->obj;
	return 0;
}
int tCG::p43()
{
    //  HCOND -> ( cond CLAUS
	return 0;
}
int tCG::p44()
{
    //  CLAUS -> HCLAUS E1 )
    S1->obj+="(" + S2->obj+"): \n";
	return 0;
}
int tCG::p45()
{
    // HCLAUS -> ( BOOL
    S1->obj = "(" + S2->obj + ") ? ";
	return 0;
}
int tCG::p46()
{
    // HCLAUS -> HCLAUS SET
	return 0;
}
int tCG::p47()
{
    // HCLAUS -> HCLAUS DISP
	return 0;
}
int tCG::p48()
{
    //   ELSE -> HELSE E1 )
    if (S1->count > 0)
		S1->obj += ",\n";

	S1->obj += S2->obj + ")";
	return 0;
}
int tCG::p49()
{
    //  HELSE -> ( else
    S1->obj = "(";
	S1->count = 0;
	return 0;
}
int tCG::p50()
{
    //  HELSE -> HELSE SET
	return 0;
}
int tCG::p51()
{
    //  HELSE -> HELSE DISP
    if(S1->count >0){
        S1->obj+=", ";
    }
    S1->obj+=S2->obj;
    ++(S1->count);
	return 0;}
int tCG::p52()
{
    //    STR -> $str
    S1->obj = S1->name;
	return 0;
}
int tCG::p53()
{
    //   BOOL -> $bool
    if(S1->name =="#t"){
        S1->obj = "true";
    }
    else {
        S1->obj = "false";
    }
	return 0;
}
int tCG::p54()
{
    //   BOOL -> CPRED
	return 0;
}
int tCG::p55()
{
    //   BOOL -> REL
	return 0;
}
int tCG::p56()
{
    //   BOOL -> OR
	return 0;
}
int tCG::p57()
{
    //   BOOL -> ( not BOOL )
    S1->obj= "!("+S3->obj + ")";
	return 0;
}
int tCG::p58()
{
    //    REL -> HREL E1 )
    S1->obj+=S2->obj+")";
	return 0;
}
int tCG::p59()
{
    //   HREL -> ( >= E
    S1->obj= "("+ S3->obj+">=";
	return 0;
}
int tCG::p60()
{
    //     OR -> HOR BOOL )
    if(S1->count ==0){
        S1->obj += S2->obj+")";
    }
    else
    {
        S1->obj= S1->obj+S2->obj+")";
    }
	return 0;
}
int tCG::p61()
{
    //    HOR -> ( or BOOL
    S1->obj = "("+S3->obj+"||";
	return 0;
}
int tCG::p62()
{
    //     E1 -> E
	return 0;
}
int tCG::p63()
{
    //    SET -> HSET E1 )
    S1->obj+=S2->obj+";\n";
	return 0;
}
int tCG::p64()
{
    //   HSET -> ( set! $id
    S1->obj =" "+ decor(S3->name)+"=";
	return 0;
}
int tCG::p65()
{
    //    VAR -> VARINI )
	return 0;
}
int tCG::p66()
{
    // VARINI -> HVAR CONST
    S1->obj+=S2->obj+";\n";
	return 0;
}
int tCG::p67()
{
    // VARINI -> HVAR $zero
	return 0;
}
int tCG::p68()
{
    //   HVAR -> ( define $id
    S1->obj = "double "+decor(S3->name)+"=";
	return 0;
}
int tCG::p69()
{
    //   PROC -> PRBODY )
    S1->obj+=";\n}}\n";
	return 0;
}
int tCG::p70()
{
    // PRBODY -> HPROC E
    S1->obj+= "return " +S2->obj;
	return 0;
}
int tCG::p71()
{
    //  HPROC -> PCPAR )
    S1->obj+=")";
    declarations+=S1->obj+";\n";
    S1->obj +="\n{{\n";
	return 0;
}
int tCG::p72()
{
    //  HPROC -> HPROC VAR
    S1->obj+=S2->obj;
	return 0;
}
int tCG::p73()
{
    //  HPROC -> HPROC SET
    S1->obj+=S2->obj;
	return 0;
}
int tCG::p74()
{
    //  HPROC -> HPROC DISP
    S1->obj+=S2->obj+";\n";
	return 0;
}
int tCG::p75()
{
    //  PCPAR -> ( define ( $id
    S1->obj = "double "+decor(S4->name)+"(";
    S1->count = 0;
	return 0;
}
int tCG::p76()
{
    //  PCPAR -> PCPAR $id
    if(S1->count >0){
        S1->obj+=",";
    }
    S1->obj+="double "+ decor(S2->name);
    ++(S1->count);
	return 0;
}
int tCG::p77()
{
    //    DEF -> PRED
	return 0;
}
int tCG::p78()
{
    //    DEF -> VAR
    int position = static_cast<int>(S1->obj.find("="))-1;
    while(position >= 0 && S1->obj[position]==' ') {
        --position;
    }
    declarations += "extern "+S1->obj.substr(0,position+1)+ ";\n";
	return 0;
}
int tCG::p79()
{
    //    DEF -> PROC
	return 0;
}
int tCG::p80()
{
    //   DEFS -> DEF
	return 0;
}
int tCG::p81()
{
    //   DEFS -> DEFS DEF
    S1->obj+=S2->obj;
	return 0;
}
int tCG::p82()
{
    //  CALCS -> CALC
	return 0;
}
int tCG::p83()
{
    //  CALCS -> CALCS CALC
    S1->obj+=S2->obj;
	return 0;
}
int tCG::p84()
{
    // CALCS1 -> CALCS
	return 0;
}
int tCG::p85()
{
    //   PROG -> CALCS1
    S1->obj ="int main()\n{\n"+S1->obj+"return 0;\n}\n";
	return 0;
}
int tCG::p86()
{
    //   PROG -> DEFS
    S1->obj += "int main()\n{\ndisplay(\"No calculations!\\n\");\nreturn 0;\n}\n";
	return 0;
}
int tCG::p87()
{
    //   PROG -> DEFS CALCS1
    S1->obj+="int main()\n{\n"+S2->obj+"return 0;\n}\n";
	return 0;
}
//_____________________
int tCG::p88(){return 0;} int tCG::p89(){return 0;}
int tCG::p90(){return 0;} int tCG::p91(){return 0;}
int tCG::p92(){return 0;} int tCG::p93(){return 0;}
int tCG::p94(){return 0;} int tCG::p95(){return 0;}
int tCG::p96(){return 0;} int tCG::p97(){return 0;}
int tCG::p98(){return 0;} int tCG::p99(){return 0;}
int tCG::p100(){return 0;} int tCG::p101(){return 0;}
int tCG::p102(){return 0;} int tCG::p103(){return 0;}
int tCG::p104(){return 0;} int tCG::p105(){return 0;}
int tCG::p106(){return 0;} int tCG::p107(){return 0;}
int tCG::p108(){return 0;} int tCG::p109(){return 0;}
int tCG::p110(){return 0;}
