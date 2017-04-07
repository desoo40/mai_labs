//                 baselexer.h 2017
#ifndef BASELEXER_H
#define BASELEXER_H
#include <iostream>
#include <fstream>
#include <string>
#include "fsm.h"

class tBaseLexer{
 std::ifstream fsource;//�����
//               ����� �� �����
 int         line;//������� �����
 char        buf[1000];//����� ������
 static const size_t bufsize=1000;
 char*       start;//��������� ������
//                   ������� � ������
 char*       end;//��������� �����
//                 ������� � ������
 std::string lexeme;//�������

public:
//�����������
 tBaseLexer();
//����������
 ~tBaseLexer() {}
//�������-�����
 bool Begin(const char* filename);//���-
//            ������� � ������ � ������
 void End(){fsource.close();}//����������
//                        ������ � ������

 std::string GetToken();//��������� ��
//                 ������ ��������� �����
 std::string GetLexeme()const{return lexeme;}
 int GetLineCount()const{return line;}
 int GetStartPos()const{return start-buf;}
 int GetEndPos()const{return end-buf;}
 std::string GetLineText()const{
                     return std::string(buf);}

protected:
//��������
  tFSM Azero;//����
  tFSM Aint; //�����
  tFSM Afloat; //������������
  tFSM Aid;  //�������������
  tFSM Aidq; //������������� ���������
  tFSM Aoper;//��������
  tFSM Abool;//��������� ���������
  tFSM Astr; //������
};
#endif

