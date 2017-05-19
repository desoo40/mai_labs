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
   return bool(fsource);//false - ошибка открытия
//                  файла
  }

string tBaseLexer::GetToken(){
  lexeme = "";
// пропустить пробельные символы и комментарии
  for (;;){
   if(*end==0 || *end==';'){
     fsource.getline(buf,bufsize);
     end = buf;
     ++line;
     if(!fsource) {
                  *end=0;
                   start=end;
                   return "#";//конец файла
                  }
// skip Racket metadata
  if(*buf=='#'&&!(*(buf+1)=='t'||*(buf+1)=='f'))*buf=0;
     continue;
   }
   if(!isspace(*end)) break;// не-
//                    пробельный символ
   ++end;
  }//for...

   start = end;// начало лексемы
// скобки
   if(*start == '('|| *start == ')'){
     lexeme = string(1,*start);//строка из
//                   одного символа
     ++end;// продвинуть за скобку
     return lexeme;
   }
// строка
  if(*start == '"'){
   int lstr=Astr.apply(start);
   if(lstr != 0){
    end += lstr;
   lexeme = string(start,end);
   return "$str";
   }
// ошибка в записи строки, lstr==0
   lexeme = string(start);
   end += lexeme.length();
   return "?";
  }
// атом
//         end продвигается за конец атома
   while(*(++end)!=0){
    if(isspace(*end)||
       *end == ';'||
       *end == '"'||
       *end == '('||
       *end == ')' ) break;
    }//while...
   lexeme = string(start,end);//строка из
//            последовательности символов

// автоматы распознают токен внутри атома
   int total        =lexeme.length();
   const char* input=lexeme.c_str();
   if(Aid.apply(input)==total) return "$id";
   if(Afloat.apply(input)==total) return "$float";
   if(Aint.apply(input)==total) return "$int";
   if(Azero.apply(input)==total) return "$zero";
   if(Abool.apply(input)==total) return "$bool";
   if(Aidq.apply(input)==total) return "$idq";
   if(Aoper.apply(input)==total) return lexeme;
   return "?";// неизвестный токен
 }

