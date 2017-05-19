//                 BASE-COMPILER.cpp 2016
#include <sstream>
#include "base-compiler.h"
using namespace std;

tGramma::tSymb tBC::getTerm(){
 std::string token=lex.GetToken();
 tGramma::tSymb term = gr.encode(token);

//  �� ������ $id ����������� �������� �����
 if(token == "$id"){
   std::string ident = lex.GetLexeme();
   tGramma::tSymb keyword=gr.encode(ident);//����� � ��������
// ���� ������������� ������ � �������� ����������,
   if(keyword && gr.terminal(keyword))
//                        ��� �������� �����
                          term = keyword;
  }
 return term;
}

 tBC::tBC(const char* gramma_name)
 {
  S1=S2=S3=S4=S5=S6=0;
  PARSER_DEBUG=false;
//                      ??
  gr.loadFromFile(gramma_name);
  prc.build(gr);
  if(!prc){ferror_message=prc.getError();
           return; }             
  make_links();
}
 tBC::~tBC(){return;}

int tBC::rewrite(const char* source_name){
//+++++++++++++++++++
  fobject.clear();//+
//+++++++++++++++++++
  ferror_message.clear();
  if(!prc) return 1;
  ferror_message.clear();

   if(!lex.Begin(source_name)){
    ferror_message = string("Can't open file ")+
                                     source_name;
    return 1;
    }
//++++++++++++++++++++++
   init();           //+
   ast.clear();      //+
   int stepcount=0;
//++++++++++++++++++++++

   std::ostringstream buf;
  if(PARSER_DEBUG){
      cout << lex.Authentication()<<endl;
      cout << "______________________\n";
     
      }
   enum tState {stShift,stReduce};
   vector<tGramma::tSymb> stack;
   tState state = stShift;
   tGramma::tSymb a,b,term = 1;// ������
   int rel;
//++++++++++++
   tSA atr;//+
//++++++++++++
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   while(true){
    switch (state){
     case stShift:
         stack.push_back(term);
//+++++++++++++++++++++++++++++
         ast.push_back(atr);//+
//+++++++++++++++++++++++++++++
  if(PARSER_DEBUG){
   if(term!=1){
    cout<< "  <-  "<<gr.decode(term)<<endl;
    cout<< setw(3)<< ++stepcount;
    atr.print();
   }
  }
         term = getTerm();
         if (!term){
                    buf << "Syntax: unknown token!";
                    goto LERROR;
                    }
//+++++++++++++++++++++++++++++++++++++
         atr = tSA(lex.GetLexeme());//+
//+++++++++++++++++++++++++++++++++++++
         break;
     case stReduce:
// �������� ���������� ������
      tGramma::tSymbstr reverse_right_part;
      a = stack.back();
      do{
        reverse_right_part += a;
        b = a;
        stack.pop_back();
        a = stack.back();
        rel = prc.rel(a,b);
      }while(rel != 1);

// ����� ����� ����� ���������
      tGramma::tRule descr =
               prc.reduce(reverse_right_part);

  if(PARSER_DEBUG)
        out_prod(cout,gr,descr);

      tGramma::tSymb left = descr.left;
      if (left == 0){ //��������� �� �������
                    buf <<
                     "Syntax: chain '";
                    tGramma::tSymbstr chain(reverse_right_part);
                    tGramma::reverse(chain);
                    out_chain(buf,gr,chain);
                    buf << "' is not a right part of any production ! ";
                    goto LERROR;
                   }
// �������� ������ �������� ����� �����
      stack.push_back(left);
// ��������� ��������� �����
// ������������� ������ ������ ����� �
// �������� ����� ����� ���������
      rel = prc.rel(a,left);
      if (rel == 0){
                    buf <<
                     "Syntax: symbol '"
                  << gr.decode(a)
                  << "' can't precede nonterminal '"
                  << gr.decode(left)
                  << "' !";
                    goto LERROR;
      }
//+++++++++++++++++++++++++++++++++++++++++++++++++
// ����� ������������� ������������       	//+
  S1=S2=S3=S4=S5=S6=0;
  int k = reverse_right_part.size(); 		//+
  int base = ast.size()-k;
  switch(k){
  case 6: S6 = &ast[base+5];
  case 5: S5 = &ast[base+4];
  case 4: S4 = &ast[base+3];
  case 3: S3 = &ast[base+2];
  case 2: S2 = &ast[base+1];
  case 1: S1 = &ast[base];
  }
   size_t production = gr.getAlt(descr).hndl;                //+
   if(call_sem(production)) goto LERROR;        //+
  --k;						//+
   for(int i=0; i< k; ++i) ast.pop_back();	//+
//+++++++++++++++++++++++++++++++++++++++++++++++++

// ��������� ������� ������������ �������
      if(stack.size() == 2 &&
         stack[1] == (tGramma::tSymb)gr.getStart() &&
         term == 1){
//++++++++++++++++++++++++++++++++++++
          fobject = ast.back().obj;//+
//++++++++++++++++++++++++++++++++++++
          lex.End();
          return 0;
        }
     if(PARSER_DEBUG){
      cout<< setw(3)<< ++stepcount;
      ast.back().print();
      }
    }//switch...
// ������� ��������� ���������
   a = stack.back();
   b = term;
   rel = prc.rel(a,b);
   if (rel == 0){
                    buf <<
                     "Syntax: symbol '"
                  << gr.decode(a)
                  << "' can't precede terminal '"
                  << gr.decode(b)
                  << "' !";
                    break;
                  }
    state = (rel == 4) ? stReduce : stShift;
 }//while...
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
   LERROR:
// �������� � ��������� �� ������ �����
// ������ � ��������
     buf<< endl;
     buf<< setw(4) << 
         lex.GetLineCount()<<"|"<<
         lex.GetLineText()<< endl;
     buf<< "     " << 
          setw(1+lex.GetStartPos()) << "^"
        << endl;
     ferror_message += buf.str();

  if(PARSER_DEBUG){
    cout <<   "Stack:";
    for( size_t i=0; i<stack.size(); ++i)
                  cout<<" "<<gr.decode(stack[i]);
    cout<<" <- "<<gr.decode(term)<<endl;
    }
     lex.End();
     return 1;
}
