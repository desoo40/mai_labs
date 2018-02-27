#include "api.h"

#ifndef __ENGINE
#define __ENGINE

class Engine {
	GLsizei Height, Width;
	GLvoid SetProjectionMatrix(GLvoid);						// ������� ������������ ��������������
	GLvoid SetModelviewMatrix(GLvoid);						// ������� �������������� ������-����
public:
	GLvoid Resize(GLsizei width, GLsizei height);			// �������, ���������� ��� ��������� �������� ����
	GLvoid Init(GLvoid);									// �������, ��� ������� ��������� ����������
	GLvoid Draw(int NumberOfCircles, int NumberOfParabols, bool isCapOn, bool isWithTex, AUX_RGBImageRec *image);									// ��������� (render) �����
	GLfloat lightAmbient[3];
	GLfloat lightDiffuse[3];
	GLfloat lightSpecular[3];
    GLfloat materialDiffuse[4];
    GLfloat materialAmbient[4];
	GLfloat materialSpecular[4];
	GLfloat lightPosition[4];
};

#endif