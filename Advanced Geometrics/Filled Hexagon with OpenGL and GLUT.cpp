#include<GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// intialize constant
const double TWO_PI = 6.2831853;
// intial values
int edgeLength = 150;
int num_of_vertex = 6;
GLdouble theta;
// intialize window size
GLsizei winWidth = 400, winHeight = 400;
// intialze circle center as window center
int center_x = winWidth/2;
int center_y = winHeight/2;


// (or others, depending on the system in use)
void init (void)
{
glClearColor (1.0, 1.0, 1.0, 0.0);
// Set display-window color to white.
glMatrixMode (GL_PROJECTION);
// Set projection parameters.
gluOrtho2D (0.0, (GLdouble) winWidth, 0.0, (GLdouble) winHeight);
}
void filledHexagon(int x_corr, int y_corr ,int len)
{
glBegin (GL_POLYGON); // Specify line-segment geometry.
for (int i =0 ; i < num_of_vertex ; i++) {
theta = TWO_PI * i / num_of_vertex;
glVertex2i(x_corr + len * cos(theta), y_corr + 150 * sin(theta));
}
glEnd ( );
glFlush ( );
}
void display (void)
{
glClear (GL_COLOR_BUFFER_BIT);// Clear display window.
glColor3f (0.25, 0.25, 0.25); // Set line segment color to green.
filledHexagon(center_x,center_y,edgeLength);
// Process all OpenGL routines as quickly as possible.
}

int main (int argc, char** argv)
{
glutInit (&argc, argv);
// Initialize GLUT.
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
// Set display mode.
glutInitWindowPosition (100, 100);
// Set top-left display-window position.
glutInitWindowSize (winHeight, winWidth);
// Set display-window width and height.
glutCreateWindow ("Hexagon"); // Create display window.
init ( );// Execute initialization procedure.
glutDisplayFunc (display);// Send graphics to display window.
glutMainLoop ( );// Display everything and wait.
}
