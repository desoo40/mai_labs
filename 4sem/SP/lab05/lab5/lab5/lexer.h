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

    addstr  (Astr,1,"\"",   3);
    addrange(Astr,1,SP,'!',1);
    addrange(Astr,1,'#','[',1);
    addrange(Astr, 1, ']', '~', 1);
    addrange(Astr,1,'\x80','\xff',1);// русские буквы

    addstr(Astr, 1, "\\", 2);
    addstr(Astr, 2, "'", 1);
    addstr(Astr, 2, "\"", 1);
    addstr(Astr, 2, "?", 1);
    addstr(Astr, 2, "\\", 1);
    addstr(Astr, 2, "a", 1);
    addstr(Astr, 2, "b", 1);
    addstr(Astr, 2, "f", 1);
    addstr(Astr, 2, "n", 1);
    addstr(Astr, 2, "r", 1);
    addstr(Astr, 2, "t", 1);
    addstr(Astr, 2, "v", 1);

  Astr.final(3);
//________________________________________

// идентификатор
    addrange(Aid,0,'a','z',1);
    addstr(Aid, 0, "!", 1);
    addstr(Aid, 0, "-", 2);
    addrange(Aid, 0, 'A', 'Z', 1);
    

    addstr(Aid, 2, "!", 1);
    addrange(Aid, 2, 'a', 'z', 1);
    addrange(Aid, 2, 'A', 'Z', 1);
    addrange(Aid, 2, '0', '9', 3);
   

    addrange(Aid, 3, '0', '9', 3);
    addrange(Aid, 3, 'a', 'z', 1);
    addrange(Aid, 3, 'A', 'Z', 1);

    addstr(Aid, 3, "!", 1);
    addstr(Aid, 3, "-", 1);

    addstr(Aid, 4, "!", 1);
    addrange(Aid, 4, '0', '9', 1);
    addrange(Aid, 4, 'a', 'z', 1);
    addrange(Aid, 4, 'A', 'Z', 1);
    
    addstr(Aid, 1, "!", 1);
    addstr(Aid, 1, "-", 4);
    addrange(Aid,1,'a','z',1);
    addrange(Aid, 1, 'A', 'Z', 1);
    addrange(Aid, 1, '0', '9', 1);
    
    
    Aid.final(1);
    Aid.final(4);
//________________________________________

// идентификатор предиката
    addstr(Aidq, 0, "?", 3);
    addstr(Aidq, 0, "-", 2);
    addrange(Aidq, 0, 'a', 'z', 1);
    addrange(Aidq, 0, 'A', 'Z', 1);

    addstr(Aidq, 1, "?", 3);
    addstr(Aidq, 1, "-", 1);
    addrange(Aidq, 1, 'a', 'z', 1);
    addrange(Aidq, 1, 'A', 'Z', 1);
    addrange(Aidq, 1, '0', '9', 1);

    addstr(Aidq, 2, "?", 3);
    addrange(Aidq, 2, '0', '9', 2);
    addrange(Aidq, 2, 'a', 'z', 1);
    addrange(Aidq, 2, 'A', 'Z', 1);

    addstr(Aidq, 3, "-", 1);
    addrange(Aidq, 3, '0', '9', 1);
    addrange(Aidq, 3, 'a', 'z', 1);
    addrange(Aidq, 3, 'A', 'Z', 1);

  Aidq.final(3);
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

