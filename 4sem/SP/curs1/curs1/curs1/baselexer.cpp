//                 baselexer.cpp 2017
#include "baselexer.h"
using namespace std;

tBaseLexer::tBaseLexer():start(buf),end(buf),
                       line(0){
 *buf = 0;
}

bool tBaseLexer::Begin(const char* filename){
   line = 0;
   start = buf;
   end = buf;
   *buf = 0;
   lexeme = "";
   fsource.clear();
   fsource.open(filename);
   return bool(fsource);//false - ������ ��������
//                  �����
  }

string tBaseLexer::GetToken(){
  lexeme = "";
// ���������� ���������� ������� � �����������
  for (;;){
   if(*end==0 || *end==';'){
     fsource.getline(buf,bufsize);
     end = buf;
     ++line;
     if(!fsource) {
                  *end=0;
                   start=end;
                   return "#";//����� �����
                  }
// skip Racket metadata
  if(*buf=='#'&&!(*(buf+1)=='t'||*(buf+1)=='f'))*buf=0;
     continue;
   }
   if(!isspace(*end)) break;// ��-
//                    ���������� ������
   ++end;
  }//for...

   start = end;// ������ �������
// ������
   if(*start == '('|| *start == ')'){
     lexeme = string(1,*start);//������ ��
//                   ������ �������
     ++end;// ���������� �� ������
     return lexeme;
   }
// ������
  if(*start == '"'){
   int lstr=Astr.apply(start);
   if(lstr != 0){
    end += lstr;
   lexeme = string(start,end);
   return "$str";
   }
// ������ � ������ ������, lstr==0
   lexeme = string(start);
   end += lexeme.length();
   return "?";
  }
// ����
//         end ������������ �� ����� �����
   while(*(++end)!=0){
    if(isspace(*end)||
       *end == ';'||
       *end == '"'||
       *end == '('||
       *end == ')' ) break;
    }//while...
   lexeme = string(start,end);//������ ��
//            ������������������ ��������

// �������� ���������� ����� ������ �����
   int total        =lexeme.length();
   const char* input=lexeme.c_str();
   if(Aid.apply(input)==total) return "$id";
   if(Afloat.apply(input)==total) return "$float";
   if(Aint.apply(input)==total) return "$int";
   if(Azero.apply(input)==total) return "$zero";
   if(Abool.apply(input)==total) return "$bool";
   if(Aidq.apply(input)==total) return "$idq";
   if(Aoper.apply(input)==total) return lexeme;
   return "?";// ����������� �����
 }

