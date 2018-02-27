#include "api.h"

#ifndef __ENGINE
#define __ENGINE

class Engine {
	GLsizei Height, Width;
	GLvoid SetProjectionMatrix(GLvoid);						// Задание проективного преобразования
	GLvoid SetModelviewMatrix(GLvoid);						// Задание преобразования модели-вида
public:
	GLvoid Resize(GLsizei width, GLsizei height);			// Функция, вызываемая при изменении размеров окна
	GLvoid Init(GLvoid);									// Функция, для задания начальных параметров
	GLvoid Draw(int NumberOfCircles, int NumberOfParabols, bool isCapOn, bool isWithTex, AUX_RGBImageRec *image);									// Отрисовка (render) сцены
	GLfloat lightAmbient[3];
	GLfloat lightDiffuse[3];
	GLfloat lightSpecular[3];
    GLfloat materialDiffuse[4];
    GLfloat materialAmbient[4];
	GLfloat materialSpecular[4];
	GLfloat lightPosition[4];
};

#endif