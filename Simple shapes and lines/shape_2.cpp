#include<GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// (or others, depending on the system in use)
void init (void)
{
glClearColor (1.0, 1.0, 1.0, 0.0);
// Set display-window color to white.
glMatrixMode (GL_PROJECTION);
// Set projection parameters.
gluOrtho2D (0.0, 300.0, 0.0, 300.0);
}
void lineSegment (void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.60, 0.40, 0.12);
glBegin (GL_LINE_STRIP);
glVertex2i (210, 160);
glVertex2i (100, 100);
glVertex2i (150, 200);
glVertex2i (200, 100);
glVertex2i (90, 160);
glEnd ( );
glFlush ( );
// Clear display window.
// Set line segment color to green.
// Specify line-segment geometry.
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
glutInitWindowSize (400, 400);
// Set display-window width and height.
glutCreateWindow ("An Example OpenGL Program"); // Create display window.
init ( );
glutDisplayFunc (lineSegment);
glutMainLoop ( );
// Execute initialization procedure.
// Send graphics to display window.
// Display everything and wait.
}
