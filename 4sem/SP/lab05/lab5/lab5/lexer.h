//                 lexer.h 2017
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
//********************************************
//*        Developed by  SDM		     *
//*             (c)  2017                    *
//********************************************
class tLexer:public tBaseLexer{
public:
// персональный код разработчика
 std::string Authentication()const{
                     return "SDM"
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
	addrange(Aint, 0, '1', '9', 3);
	addstr(Aint, 0, "0", 2);
	addstr(Aint, 0, "+", 1);
	addstr(Aint, 0, "-", 1);

	addrange(Aint, 1, '1', '9', 3);
	addstr(Aint, 1, "0", 2);

	addrange(Aint, 2, '1', '9', 3);
	addstr(Aint, 2, "0" , 2);

	addrange(Aint, 3, '0', '9', 3);

  Aint.final(3);
//________________________________________

// вещественное
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
    addstr  (Aid,1,"!",   1);
  Aid.final(1);
//________________________________________

// идентификатор предиката
    addstr  (Aidq,0,"?",   1);
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

