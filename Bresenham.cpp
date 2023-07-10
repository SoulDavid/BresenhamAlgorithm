#include <iostream>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <cmath>

//Implementación de los modulos
void Plot(int ix, int iy)
{
  glBegin(GL_POINTS); //Inicio de dibujo de una primitiva
  glVertex2i(ix, iy); //Dibujo un punto
  glEnd(); //Termina el dibujo de una primitiva
}

void Swap(int*x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

//Implementación del modulo Bresenham+
void Bresenham(int x0, int x1, int y0, int y1)
{
  int dy, x, y, error;
  int delta_x, delta_y;
  bool steep = abs(y1 - y0) > abs(x1 - x0);
  if(steep)
  {
    swap(&x0, &y0);
    swap(&x1, &y1);
  }
  if(x0 > x1)
  {
    swap(&x0, &x1);
    swap(&y0, &y1);
  }
  if(y0 > y1)
  {
    dy = -1;
  }
  else
  {
    dy = 1;
  }
  
  delta_x = x1 - x0;
  delta_y = y1 - y0;
  
  y = y0;
  
  error = 0;
  
  for(x = x0; x <= x1; x++)
  {
    if (steep)
      Plot(y,x);
    else
      Plot(x, y);
      
    error = error + delta_y;
    if(2 * error >= delta_x)
    {
      y = y + dy;
      error = error - delta_x;
    }
  }
}

void Inicializer()
{
  glClear(GL_COLOR_BUFFER_BIT);
  Bresenham(200, 170, 400, 500);
  glFlush();
}

void myInit()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main()
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(0,0);
  glutCreateWindow("ALGORITMO BRESENHAM");
  glutDisplayFunc(Inicializer);
  myInit();
  gluMainLoop();
	return 0;
}
