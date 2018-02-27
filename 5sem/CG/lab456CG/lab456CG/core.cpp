#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include "core.h"

using namespace std;

GLvoid Engine::SetProjectionMatrix(GLvoid){
	glMatrixMode(GL_PROJECTION);						// Действия будут производиться с матрицей проекции
	glLoadIdentity();									// Текущая матрица (проекции) сбрасывается на единичную
	glFrustum(-1, 1, -1, 1, 5, 30);						// Устанавливается перспективная проекция
	//glEnable(GL_LIGHT0);
}

GLvoid Engine::SetModelviewMatrix(){
	glMatrixMode(GL_MODELVIEW);							// Действия будут производиться с матрицей модели
	glLoadIdentity();									// Текущая матрица (модели) сбрасывается на единичную
	glTranslatef(0.0, 0.0, -24.0);						// Система координат переносится на 8 единиц вглубь сцены													
	//glRotatef(15.0, 1.0, 1.0, 0.0);						// и поворачивается на 30 градусов вокруг оси x,
	//glRotatef(-60.0, 1.0, 0.0, 0.0);						// а затем на 70 градусов вокруг оси y
}

GLvoid Engine::Resize(GLsizei width, GLsizei height){
	if (height == 0)									
	{
		height = 1;										
	}

	glViewport(0, 0, width, height);					// Устанавливается область просмотра

	Height = height;
	Width = width;

	SetProjectionMatrix();
	SetModelviewMatrix();
}

GLvoid Engine::Init(GLvoid){
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_LIGHTING);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_NORMALIZE);

	//glEnable(GL_TEXTURE_GEN_S);
	//glEnable(GL_TEXTURE_GEN_T);

	glClearColor(255.0f, 255.0f, 255.0f, 0.0f);				// Устанавливается черный фон
	glClearDepth(1.0f);									// Устанавливается значение для
														// заполнения буфера глубины по умолчанию
	glEnable(GL_DEPTH_TEST);							// Включается тест глубины
	glDepthFunc(GL_LEQUAL);								// Устанавливается значение, используемое
														// в сравнениях при использовании
														// буфера глубины


	glShadeModel(GL_SMOOTH);							// Включается плавное затенение
	glEnable(GL_LINE_SMOOTH);							// Включается сглаживание линий
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);				// Выбирается самый качественный
														// режим сглаживания для линий
	glEnable(GL_BLEND);									// Включается смешение цветов, необходимое
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// для работы сглаживания и задается
														// способ смешения
}

/*void DrawCube(GLfloat size, GLdouble h)
{
     glBegin(GL_QUADS);

	 double sizeOfstep = size / 200;
	 double massive[20][360][3];

	 for(int j = 0; j < 20; j++)
	 {
		 double r = j * sizeOfstep;

	 for(int i = 0; i < 360; i++)
	 {
		 massive[j][i][0] = r*cos(h*i);
		 massive[j][i][1] = r*r * 2;
		 massive[j][i][2] = r*sin(h*i);
	 }
	 }
	 
		 bool temp = true;

	 for(int j = 0; j < 19; j++)
	 {
		 for(int i = 0;  i < 360; i++) 
		 {
		 if(temp) { glColor3f(0.1f, 0.0f, 0.0f); temp = false; }
		 else { glColor3f(1.0f, 1.0f, 1.0f); temp = true; }

		 glVertex3f( massive[j][i][0], massive[j][i][1], massive[j][i][2] );
		 glVertex3f( massive[j][i+1][0], massive[j][i+1][1], massive[j][i+1][2] );
		 glVertex3f( massive[j+1][i+1][0], massive[j+1][i+1][1], massive[j+1][i+1][2] );
		 glVertex3f( massive[j+1][i][0], massive[j+1][i][1], massive[j+1][i][2] );


		 if(i == 399)
			 {
				glVertex3f( massive[j][359][0], massive[j][359][1], massive[j][359][2] );
				glVertex3f( massive[j][0][0], massive[j][0][1], massive[j][0][2] );
				glVertex3f( massive[j+1][0][0], massive[j+1][0][1], massive[0][i+1][2] );
				glVertex3f( massive[j+1][359][0], massive[j+1][359][1], massive[j+1][359][2] );
			 }
		 }
	 }
	 glEnd();
}*/

void calcParaboloid(GLfloat size, int NumberOfCircles, int NumberOfParabols, bool isCapOn, bool isWithTex)
        {
			glBegin(GL_TRIANGLES);

			//glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
			//glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);

			vector<double> tempPoint;

            double t0 = 0, tn =5 , dt = (tn - t0) / NumberOfCircles;
            vector<vector<double>> points;
            for (int i = 0; i < NumberOfCircles; ++i)
            {
                double x = t0 + i * dt;
                double z = sqrt(9 - x * x);
				vector<double> point;
				point.push_back(x);
				point.push_back(0);
				point.push_back(-z);
				points.push_back(point);
            }

            double u0 = 0, un = 2 * M_PI, du = (un - u0) / NumberOfParabols;
			
				bool temp = true;
            for (int j = 0; j < NumberOfParabols; ++j)
            {
                vector<vector<double>> curPoints;
                vector<vector<double>> nextPoints;

                double angle = u0 + j * du;
                double nextAngle = u0 + (j + 1) * du;

				double matrixR[3][3];
				double matrixRR[3][3];

				for(int n = 0; n < 3; ++n)
					for(int m = 0; m < 3; ++m)
					{
						matrixR[n][m] = 0;
						matrixRR[n][m] = 0;
					}

				matrixR[0][0] = matrixR[1][1] = cos(angle);
                matrixR[1][0] = -1 *(matrixR[0][1] = sin(angle));
                matrixR[2][2] = 1;

				matrixRR[0][0] = matrixRR[1][1] = cos(nextAngle);
                matrixRR[1][0] = -1 * (matrixRR[0][1] = sin(nextAngle));
                matrixRR[2][2] = 1;

                for (int i = 0; i < NumberOfCircles; ++i)
                {
					vector<double> t1;
					t1.push_back(0);
					t1.push_back(0);
					t1.push_back(0);

					vector<double> tp;
					tp.push_back(points[i][0]);
					tp.push_back(points[i][1]);
					tp.push_back(points[i][2]);

					for(int m = 0; m < 3; m++)
						for(int n = 0; n < 3; n++)
								t1[m] += matrixR[m][n] * tp[n];

					vector<double> t2;
					t2.push_back(0);
					t2.push_back(0);
					t2.push_back(0);
        
					for(int m = 0; m < 3; m++)
						for(int n = 0; n < 3; n++)
								t2[m] += matrixRR[m][n] * tp[n];

					curPoints.push_back(t1);
                    if (j == NumberOfParabols - 1)
                    {
                        nextPoints.push_back(points[i]);
                    }
                    else
                    {
                        nextPoints.push_back(t2);
                    }
                }

				int nn = curPoints.size();
                for (int i = 0; i < nn - 1; ++i)
                {
					
					if (i != nn - 2) glColor3f(1.0f, 1.0f, 1.0f);
					else glColor3f(1.0f, 0.0f, 0.0f);

                    glVertex3f(curPoints[i][0], curPoints[i][1], curPoints[i][2]);
					//glNormal3f(1, 1, 1);
					glVertex3f(nextPoints[i + 1][0], nextPoints[i + 1][1], nextPoints[i + 1][2]);
					//glNormal3f(1, 1, 1);
					glVertex3f(curPoints[i + 1][0], curPoints[i + 1][1], curPoints[i + 1][2]);
					//glNormal3f(1, 1, 1);

					if (i != nn - 2) glColor3f(0.1f, 0.0f, 0.0f);

					glVertex3f(curPoints[i][0], curPoints[i][1], curPoints[i][2]);
					glVertex3f(nextPoints[i][0], nextPoints[i][1], nextPoints[i][2]);
					glVertex3f(nextPoints[i + 1][0], nextPoints[i + 1][1], nextPoints[i + 1][2]);
                }

				double center[3] = { 0, 0, 0 };
				
				if(temp) { glColor3f(1.0f, 1.0f, 1.0f); temp = false; }
				else { glColor3f(0.1f, 0.0f, 0.0f); temp = true; }

				if(isCapOn)
				{
					double numberOfParabolsDouble = NumberOfParabols;
					double jDouble = j;
					if(isWithTex)
					{
					if(jDouble <= numberOfParabolsDouble/4) 
						glTexCoord2d( (4/numberOfParabolsDouble)*jDouble ,0); 
					if(numberOfParabolsDouble/4 < jDouble && jDouble <= numberOfParabolsDouble/2) 
						glTexCoord2d(1,(4/numberOfParabolsDouble)*(jDouble-numberOfParabolsDouble/4)); 
					if(numberOfParabolsDouble/2 < jDouble && jDouble <= 3*numberOfParabolsDouble/4) 
						glTexCoord2d(1-(4/numberOfParabolsDouble)*(jDouble-numberOfParabolsDouble/2),1);
					if(3*numberOfParabolsDouble/4 < jDouble && jDouble < numberOfParabolsDouble) 
						glTexCoord2d(0, 1-(4/numberOfParabolsDouble)*(jDouble-3*numberOfParabolsDouble/4));
					}
					glVertex3f(curPoints[nn - 1][0], curPoints[nn - 1][1], curPoints[nn - 1][2]);
					
					if(isWithTex)
					{
					if(jDouble < numberOfParabolsDouble/4) 
						glTexCoord2d( (4/numberOfParabolsDouble)*(jDouble+1),0); 
					if(numberOfParabolsDouble/4 <= jDouble && jDouble < numberOfParabolsDouble/2) 
						glTexCoord2d(1,(4/numberOfParabolsDouble)*(jDouble-numberOfParabolsDouble/4 + 1)); 
					if(numberOfParabolsDouble/2 <= jDouble && jDouble < 3*numberOfParabolsDouble/4) 
						glTexCoord2d(1-(4/numberOfParabolsDouble)*(jDouble-numberOfParabolsDouble/2 + 1),1);
					if(3*numberOfParabolsDouble/4 <= jDouble && jDouble < numberOfParabolsDouble) 
						glTexCoord2d(0, 1-(4/numberOfParabolsDouble)*(jDouble-3*numberOfParabolsDouble/4 + 1));
					}
					glVertex3f(nextPoints[nn - 1][0], nextPoints[nn - 1][1], nextPoints[nn - 1][2]);

					glTexCoord2d(0.5, 0.5); glVertex3f(center[0], center[1], center[2]);

					//if(j > 0) {
					//glVertex3f(tempPoint[0], tempPoint[1], tempPoint[2]);
					//glVertex3f(curPoints[nn - 1][0], curPoints[nn - 1][1], curPoints[nn - 1][2]);
					//glVertex3f(center[0], center[1], center[2]);
					//}
				}
				
            }
			
		//glDisable(GL_TEXTURE_GEN_S);
		//glDisable(GL_TEXTURE_GEN_T);
		//glDisable(GL_TEXTURE_2D);

			glEnd();
        }

/*void DrawCube1(GLfloat size)
{
     glBegin(GL_TRIANGLES);

	 /*double x[54], y[54], z[54];
	 double sizeOfstep = size / 100;
	 double h = 20;
	 double massive[10][180][3];

	 for(int j = 0; j < 10; j++)
	 {
		 double r = j * sizeOfstep;

	 for(int i = 0; i < 180; i++)
	 {
		 massive[j][i][0] = r*cos(h*i);
		 massive[j][i][1] = r*r * 2;
		 massive[j][i][2] = r*sin(h*i);
	 }
	 }
		 for(int i = 0;  i < 180; i++) 
		 {
		 glVertex3f( massive[8][i][0], massive[8][i][1], massive[8][i][2] );
		 glVertex3f( massive[8][i+1][0], massive[8][i+1][1], massive[8][i+1][2] );
		 glVertex3f( massive[9][i+1][0], massive[9][i+1][1], massive[9][i+1][2] );
		 glVertex3f( massive[9][i][0], massive[9][i][1], massive[9][i][2] );
		 }*//*

	 glVertex3f( -size / 2, -size / 2, -size / 2); 
     glVertex3f( -size / 2,  size / 2, -size / 2);
     glVertex3f( -size / 2,  size / 2,  size / 2);

     glVertex3f( -size / 2 + 2 * size, -size / 2 + 2 * size, -size / 2 + 2 * size); 
     glVertex3f( -size / 2 + 2 * size,  size / 2 + 2 * size, -size / 2 + 2 * size);
     glVertex3f( -size / 2 + 2 * size,  size / 2 + 2 * size,  size / 2 + 2 * size);


	 glEnd();
}*/

GLvoid Engine::Draw(int NumberOfCircles, int NumberOfParabols, bool isCapOn, bool isWithTex, AUX_RGBImageRec *image)									
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(isWithTex)
	{
	glEnable(GL_TEXTURE_2D);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	 glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	
		glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		         image->sizeX,
				 image->sizeY,
				 0, GL_RGB, GL_UNSIGNED_BYTE,
				 image->data);
	}
	else glDisable(GL_TEXTURE_2D);

      // свойства материала
      glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
      glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
      glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);


            glEnable(GL_LIGHT1);
            glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
            glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
            glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular);
            glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
            glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.0);
            glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.2);
            glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.4);

	glPushMatrix();										// Запоминается матрица модели								// Рисуется проволочный куб со стороной 2
	calcParaboloid(1.0f, NumberOfCircles, NumberOfParabols, isCapOn, isWithTex);

	glPopMatrix();										// Восстанавливается матрица модели
}
