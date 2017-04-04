//                 lexer.h 2017
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
//********************************************
//*        Developed by  xxx		     *
//*             (c)  2017                    *
//********************************************
class tLexer:public tBaseLexer{
public:
// персональный код разработчика
 std::string Authentication()const{
                     return "xxx"
                +std::string("17");}
//конструктор
 tLexer():tBaseLexer(){
//создать автоматы:

//  ноль Azero
    addstr  (Azero,0,"+-", 2);
    addstr  (Azero,0,"0",  1);
    addstr  (Azero,2,"0",  1);
    addstr  (Azero,1,"0",  1);
  Azero.final(1);

//________________________________________

// целое число
    addrange(Aint,0,'1','9',1);
  Aint.final(1);
//________________________________________

// вещественное
    addrange(Afloat,0,'0','9',1);
    addstr  (Afloat,1,".",   2);
    addrange(Afloat,2,'0','9',2);
  Afloat.final(2);
//________________________________________

// строка
//  –≈јЋ»«ќ¬ј“№ escape-последовательности:
// \'  \"  \?  \\  \a  \b  \f  \n  \r  \t  \v
    const char SP=' ';// пробел
    addstr  (Astr,0,"\"",   1);
    addstr  (Astr,1,"\"",   2);
    addrange(Astr,1,SP,'!',1);
    addrange(Astr,1,'#','~',1);
    addrange(Astr,1,'\x80','\xff',1);// русские буквы
  Astr.final(2);
//________________________________________

// идентификатор
    addrange(Aid,0,'a','z',1);
    addrange(Aid,1,'a','z',1);
    addstr  (Aid,1,"!-",   1);
  Aid.final(1);
//________________________________________

// идентификатор предиката
    addstr  (Aidq,0,"?",   1);
    addrange(Aidq,0,'a','z',1);
    addrange(Aidq,1,'a','z',1);
    addstr  (Aidq,1,"?-",   1);
  Aidq.final(1);
//________________________________________

// оператор
    addstr  (Aoper,0,"+-*/<=>",   1);
  Aoper.final(1);
//________________________________________

// булевские константы
    addstr  (Abool,0,"#",   1);
    addstr  (Abool,1,"tf",  2);
  Abool.final(2);
//________________________________________
}
};
#endif

