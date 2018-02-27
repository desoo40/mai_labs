#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include "core.h"

#define por10 1
#define okr10 2
#define por100 3
#define okr100 4

using namespace std;

//AUX_RGBImageRec *image;

Engine *engine;
GLfloat thisLightAmbient[3] = {3.0, 0.0, 0.0};
GLfloat thisLightDiffuse[3] = {1.0, 0.0, 0.0};
GLfloat thisLightSpecular[3] = {0.2, 0.0, 0.0};

GLfloat thisMaterialAmbient[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat thisMaterialDiffuse[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat thisMaterialSpecular[4] = {1.0, 1.0, 1.0, 1.0};


GLfloat thisLightPosition[4] = {5.0, 5.0, 0.0, 1.0};

int fotoNum = 1;

bool isCapOn = false;
bool isWithTex = true;
bool isWithAnimation = false;
double mx = 0, my = 0, px = 0, py = 0;
int NumberOfCircles = 20, NumberOfParabols = 20;
double actualAngle = 0;

std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

GLvoid display(GLvoid)
{

	engine->lightAmbient[0] =  thisLightAmbient[0]; engine->lightAmbient[1] =  thisLightAmbient[1]; engine->lightAmbient[2] =  thisLightAmbient[2];
	engine->lightDiffuse[0] =  thisLightDiffuse[0]; engine->lightDiffuse[1] =  thisLightDiffuse[1]; engine->lightDiffuse[2] =  thisLightDiffuse[2];
	engine->lightSpecular[0] =  thisLightSpecular[0]; engine->lightSpecular[1] =  thisLightSpecular[1]; engine->lightSpecular[2] =  thisLightSpecular[2];

	engine->materialAmbient[0] =  thisMaterialAmbient[0]; engine->materialAmbient[1] =  thisMaterialAmbient[1]; engine->materialAmbient[2] =  thisMaterialAmbient[2]; engine->materialAmbient[3] =  thisMaterialAmbient[3];
	engine->materialDiffuse[0] =  thisMaterialDiffuse[0]; engine->materialDiffuse[1] =  thisMaterialDiffuse[1]; engine->materialDiffuse[2] =  thisMaterialDiffuse[2]; engine->materialDiffuse[3] =  thisMaterialDiffuse[3];
	engine->materialSpecular[0] =  thisMaterialSpecular[0]; engine->materialSpecular[1] =  thisMaterialSpecular[1]; engine->materialSpecular[2] =  thisMaterialSpecular[2]; engine->materialSpecular[3] =  thisMaterialSpecular[3];

	engine->lightPosition[0] =  thisLightPosition[0]; engine->lightPosition[1] =  thisLightPosition[1]; engine->lightPosition[2] =  thisLightPosition[2]; engine->lightPosition[3] =  thisLightPosition[3];

	AUX_RGBImageRec *image;

	std::stringstream ss;
    ss<<fotoNum;
    std::string str;
    ss>>str;

	string photoNum = "photo";
	photoNum += str;
	photoNum += ".bmp";
	std::wstring stemp = s2ws(photoNum);
	LPCWSTR result = stemp.c_str();
	image = auxDIBImageLoad(result);

	engine->Draw(NumberOfCircles, NumberOfParabols, isCapOn, isWithTex, image);
	
	glutSwapBuffers();
}

GLvoid reshape(GLsizei width, GLsizei height)
{
	engine->Resize(width, height);
}

/*void MouseFunc(int x, int y)
{
    static int delta_x, delta_y;
    if ( py == -1 ) {
        delta_x = 0;
        delta_y = 0;
    } else {
		delta_x = x - px;
        delta_y = y - py;
    }
	px = x;
    py = y;

	
	glutReshapeFunc(reshape);

	

	glRotatef(- mx * 0.01, 0.0, 1.0, 0.0);
	glRotatef(- my * 0.01, 0.0, 0.0, 1.0);

	mx += delta_x;
    my += delta_y;

    glRotatef(mx * 0.01, 0.0, 1.0, 0.0);
	//glRotatef(my * 0.025, 0.0, 0.0, 1.0);
	glRotatef(my * 0.01, 0.0, 0.0, 1.0);
	//else glRotatef(- delta_y * 0.25, 0.0, 0.0, 1.0);

	
    glutPostRedisplay();
}*/

void MyKeyboard(int key, int a, int b) 
{
    switch(key)
    {
    case GLUT_KEY_UP: glRotatef(-5, 1.0, 0.0, 0.0); break;
    case GLUT_KEY_LEFT: glRotatef(-5, 0.0, 1.0, 0.0); break;
    case GLUT_KEY_DOWN: glRotatef(5, 1.0, 0.0, 0.0); break;
    case GLUT_KEY_RIGHT: glRotatef(5, 0.0, 1.0, 0.0); break;
	case GLUT_KEY_PAGE_UP: glRotatef(5, 0.0, 0.0, 1.0); break;
	case GLUT_KEY_PAGE_DOWN: glRotatef(-5, 0.0, 0.0, 1.0); break;

	case GLUT_KEY_F1: glScalef( 0.99f, 0.99f, 0.99f ); break; // MessageBox( NULL, L"Could Not Unregister Class.", L"SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
	case GLUT_KEY_F2: glScalef( 1.01f, 1.01f, 1.01f ); break;

	case GLUT_KEY_F3: thisLightPosition[0] -= 5; break;
	case GLUT_KEY_F4: thisLightPosition[0] += 5; break;

	case GLUT_KEY_F5: thisLightPosition[1] -= 5; break;
	case GLUT_KEY_F6: thisLightPosition[1] += 5; break;

	case GLUT_KEY_F7: thisLightPosition[2] -= 5; break;
	case GLUT_KEY_F8: thisLightPosition[2] += 5; break;
    }
    glutPostRedisplay();
}

void TimerFunction(int value){
	glTranslatef(0.02, 0.02, 0.02);
    if(isWithAnimation) glutTimerFunc(50,TimerFunction,1);  
    glutPostRedisplay();
}

void processMenuEventsPlus(int option) {
 
	switch (option) {
		case por10 :
			NumberOfParabols += 12; break;
		case okr10 :
			NumberOfCircles += 12; break;
		case por100 :
			NumberOfParabols += 100; break;
		case okr100 :
			NumberOfCircles += 100; break;
	}
    glutPostRedisplay();
}

void processMenuEventsMinus(int option) {
 
	switch (option) {
		case por10 :
			if(NumberOfParabols > 12) NumberOfParabols -= 12; else NumberOfParabols = 2; break;
		case okr10 :
			if(NumberOfCircles > 12) NumberOfCircles -= 12; else NumberOfCircles = 2; break;
		case por100 :
			if(NumberOfParabols > 100) NumberOfParabols -= 100; else NumberOfParabols = 0; break;
		case okr100 :
			if(NumberOfCircles > 100) NumberOfCircles -= 100; else NumberOfCircles = 1; break;
	}
    glutPostRedisplay();
}


void processfotoChooseMenu(int option) 
	{
		fotoNum = option;
		glutPostRedisplay();
	}

void processMainMenu(int option) 
	{
		switch (option) {
		case 1 :
			if(isCapOn) isCapOn = false;
			else isCapOn = true; break;
		case 2 :
			if(isWithAnimation) isWithAnimation = false;
			else { isWithAnimation = true; glutTimerFunc(5,TimerFunction,1); } break;
		case 3 :
			if(isWithTex) isWithTex = false;
			else isWithTex = true;  break;
		}
		glutPostRedisplay();
	}

void processLightSourseAmbientR(int option) 
	{
		switch (option) {
		case 1 :
			thisLightAmbient[0]++; break;
		case 2 :
			if(thisLightAmbient[0] > 1)  thisLightAmbient[0]--; else thisLightAmbient[0] = 0; break;
		}
		glutPostRedisplay();
	}

void processLightSourseAmbientG(int option) 
	{
		switch (option) {
		case 1 :
			thisLightAmbient[1]++; break;
		case 2 :
			if(thisLightAmbient[1] > 1)  thisLightAmbient[1]--; else thisLightAmbient[1] = 0; break;
		}
		glutPostRedisplay();
	}

void processLightSourseAmbientB(int option) 
	{
		switch (option) {
		case 1 :
			thisLightAmbient[2]++; break;
		case 2 :
			if(thisLightAmbient[2] > 1)  thisLightAmbient[2]--; else thisLightAmbient[2] = 0; break;
		}
		glutPostRedisplay();
	}

void processLightSourseDiffuseR(int option) 
	{
		switch (option) {
		case 1 :
			thisLightDiffuse[0]++; break;
		case 2 :
			if(thisLightDiffuse[0] > 1)  thisLightDiffuse[0]--; else thisLightDiffuse[0] = 0; break;
		}
		glutPostRedisplay();
	}

void processLightSourseDiffuseG(int option) 
	{
		switch (option) {
		case 1 :
			thisLightDiffuse[1]++; break;
		case 2 :
			if(thisLightDiffuse[1] > 1)  thisLightDiffuse[1]--; else thisLightDiffuse[1] = 0; break;
		}
		glutPostRedisplay();
	}

void processLightSourseDiffuseB(int option) 
	{
		switch (option) {
		case 1 :
			thisLightDiffuse[2]++; break;
		case 2 :
			if(thisLightDiffuse[2] > 1)  thisLightDiffuse[2]--; else thisLightDiffuse[2] = 0; break;
		}
		glutPostRedisplay();
	}

void processLightSourseSpecularR(int option) 
	{
		switch (option) {
		case 1 :
			thisLightSpecular[0]++; break;
		case 2 :
			if(thisLightSpecular[0] > 1)  thisLightSpecular[0]--; else thisLightSpecular[0] = 0; break;
		}
		glutPostRedisplay();
	}

void processLightSourseSpecularG(int option) 
	{
		switch (option) {
		case 1 :
			thisLightSpecular[1]++; break;
		case 2 :
			if(thisLightSpecular[1] > 1)  thisLightSpecular[1]--; else thisLightSpecular[1] = 0; break;
		}
		glutPostRedisplay();
	}

void processLightSourseSpecularB(int option) 
	{
		switch (option) {
		case 1 :
			thisLightSpecular[2]++; break;
		case 2 :
			if(thisLightSpecular[2] > 1)  thisLightSpecular[2]--; else thisLightSpecular[2] = 0; break;
		}
		glutPostRedisplay();
	}

void processMaterialAmbientR(int option) 
	{
		switch (option) {
		case 1 :
			thisMaterialAmbient[0]++; break;
		case 2 :
			if(thisMaterialAmbient[0] > 1)  thisMaterialAmbient[0]--; else thisMaterialAmbient[0] = 0; break;
		}
		glutPostRedisplay();
	}

void processMaterialAmbientG(int option) 
	{
		switch (option) {
		case 1 :
			thisMaterialAmbient[1]++; break;
		case 2 :
			if(thisMaterialAmbient[1] > 1)  thisMaterialAmbient[1]--; else thisMaterialAmbient[1] = 0; break;
		}
		glutPostRedisplay();
	}

void processMaterialAmbientB(int option) 
	{
		switch (option) {
		case 1 :
			thisMaterialAmbient[2]++; break;
		case 2 :
			if(thisMaterialAmbient[2] > 1)  thisMaterialAmbient[2]--; else thisMaterialAmbient[2] = 0; break;
		}
		glutPostRedisplay();
	}

void processMaterialDiffuseR(int option) 
	{
		switch (option) {
		case 1 :
			thisMaterialDiffuse[0]++; break;
		case 2 :
			if(thisMaterialDiffuse[0] > 1)  thisMaterialDiffuse[0]--; else thisMaterialDiffuse[0] = 0; break;
		}
		glutPostRedisplay();
	}

void processMaterialDiffuseG(int option) 
	{
		switch (option) {
		case 1 :
			thisMaterialDiffuse[1]++; break;
		case 2 :
			if(thisMaterialDiffuse[1] > 1)  thisMaterialDiffuse[1]--; else thisMaterialDiffuse[1] = 0; break;
		}
		glutPostRedisplay();
	}

void processMaterialDiffuseB(int option) 
	{
		switch (option) {
		case 1 :
			thisMaterialDiffuse[2]++; break;
		case 2 :
			if(thisMaterialDiffuse[2] > 1)  thisMaterialDiffuse[2]--; else thisMaterialDiffuse[2] = 0; break;
		}
		glutPostRedisplay();
	}

void processMaterialSpecularR(int option) 
	{
		switch (option) {
		case 1 :
			thisMaterialSpecular[0]++; break;
		case 2 :
			if(thisMaterialSpecular[0] > 1)  thisMaterialSpecular[0]--; else thisMaterialSpecular[0] = 0; break;
		}
		glutPostRedisplay();
	}

void processMaterialSpecularG(int option) 
	{
		switch (option) {
		case 1 :
			thisMaterialSpecular[1]++; break;
		case 2 :
			if(thisMaterialSpecular[1] > 1)  thisMaterialSpecular[1]--; else thisMaterialSpecular[1] = 0; break;
		}
		glutPostRedisplay();
	}

void processMaterialSpecularB(int option) 
	{
		switch (option) {
		case 1 :
			thisMaterialSpecular[2]++; break;
		case 2 :
			if(thisMaterialSpecular[2] > 1)  thisMaterialSpecular[2]--; else thisMaterialSpecular[2] = 0; break;
		}
		glutPostRedisplay();
	}
void createGLUTMenus() {
	int MaterialAmbientR = glutCreateMenu(processMaterialAmbientR);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int MaterialAmbientG = glutCreateMenu(processMaterialAmbientG);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int MaterialAmbientB = glutCreateMenu(processMaterialAmbientB);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int MaterialAmbient = glutCreateMenu(processMainMenu);
	glutAddSubMenu("R", MaterialAmbientR);
	glutAddSubMenu("G", MaterialAmbientG);
	glutAddSubMenu("B", MaterialAmbientB);

	int MaterialDiffuseR = glutCreateMenu(processMaterialDiffuseR);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int MaterialDiffuseG = glutCreateMenu(processMaterialDiffuseG);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int MaterialDiffuseB = glutCreateMenu(processMaterialDiffuseB);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int MaterialDiffuse = glutCreateMenu(processMainMenu);
	glutAddSubMenu("R", MaterialDiffuseR);
	glutAddSubMenu("G", MaterialDiffuseG);
	glutAddSubMenu("B", MaterialDiffuseB);
	
	int MaterialSpecularR = glutCreateMenu(processMaterialSpecularR);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int MaterialSpecularG = glutCreateMenu(processMaterialSpecularG);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int MaterialSpecularB = glutCreateMenu(processMaterialSpecularB);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int MaterialSpecular = glutCreateMenu(processMainMenu);
	glutAddSubMenu("R", MaterialSpecularR);
	glutAddSubMenu("G", MaterialSpecularG);
	glutAddSubMenu("B", MaterialSpecularB);

	int Material = glutCreateMenu(processMainMenu);
	glutAddSubMenu("Ambient", MaterialAmbient);
	glutAddSubMenu("Diffuse", MaterialDiffuse);
	glutAddSubMenu("Specular", MaterialSpecular);

	int LightSourseAmbientR = glutCreateMenu(processLightSourseAmbientR);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int LightSourseAmbientG = glutCreateMenu(processLightSourseAmbientG);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int LightSourseAmbientB = glutCreateMenu(processLightSourseAmbientB);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int LightSourseAmbient = glutCreateMenu(processMainMenu);
	glutAddSubMenu("R", LightSourseAmbientR);
	glutAddSubMenu("G", LightSourseAmbientG);
	glutAddSubMenu("B", LightSourseAmbientB);

	int LightSourseDiffuseR = glutCreateMenu(processLightSourseDiffuseR);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int LightSourseDiffuseG = glutCreateMenu(processLightSourseDiffuseG);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int LightSourseDiffuseB = glutCreateMenu(processLightSourseDiffuseB);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int LightSourseDiffuse = glutCreateMenu(processMainMenu);
	glutAddSubMenu("R", LightSourseDiffuseR);
	glutAddSubMenu("G", LightSourseDiffuseG);
	glutAddSubMenu("B", LightSourseDiffuseB);
	
	int LightSourseSpecularR = glutCreateMenu(processLightSourseSpecularR);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int LightSourseSpecularG = glutCreateMenu(processLightSourseSpecularG);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int LightSourseSpecularB = glutCreateMenu(processLightSourseSpecularB);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);
	int LightSourseSpecular = glutCreateMenu(processMainMenu);
	glutAddSubMenu("R", LightSourseSpecularR);
	glutAddSubMenu("G", LightSourseSpecularG);
	glutAddSubMenu("B", LightSourseSpecularB);

	int LightSourse = glutCreateMenu(processMainMenu);
	glutAddSubMenu("Ambient", LightSourseAmbient);
	glutAddSubMenu("Diffuse", LightSourseDiffuse);
	glutAddSubMenu("Specular", LightSourseSpecular);


	int menuPlus;
	int menuMinus;
	int mainMenu;

	menuPlus = glutCreateMenu(processMenuEventsPlus);
	glutAddMenuEntry("+12 порабол", por10);
	glutAddMenuEntry("+12 окружностей", okr10);
	glutAddMenuEntry("+100 порабол", por100);
	glutAddMenuEntry("+100 окружностей", okr100);
 
	menuMinus = glutCreateMenu(processMenuEventsMinus);
	glutAddMenuEntry("-12 порабол", por10);
	glutAddMenuEntry("-12 окружностей", okr10);
	glutAddMenuEntry("-100 порабол", por100);
	glutAddMenuEntry("-100 окружностей", okr100);
 
	mainMenu = glutCreateMenu(processMainMenu);
	glutAddSubMenu("Увеличить точность", menuPlus);
	glutAddSubMenu("Уменьшить точность", menuMinus);
	glutAddSubMenu("Источник света", LightSourse);
	glutAddSubMenu("Материал", Material);
	glutAddMenuEntry("Одеть/снять крышку", 1);
	glutAddMenuEntry("Включить/выключить движение", 2);
	glutAddMenuEntry("Включить/выключить текстуру", 3);

	// прикрепить меню правой кнопки
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Lab4, 5, 6");
	engine = new Engine();
	engine->Init();
	glutSpecialFunc(MyKeyboard);
	createGLUTMenus();
	glutTimerFunc(5,TimerFunction,1);
	//image = auxDIBImageLoad(L"photo.bmp");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
    //glutMotionFunc(MouseFunc);
	glutMainLoop();
	return 0;
}
