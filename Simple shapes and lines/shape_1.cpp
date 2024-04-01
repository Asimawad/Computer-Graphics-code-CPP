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
glClear (GL_COLOR_BUFFER_BIT);// Clear display window.
glColor3f (0.25, 0.25, 0.25); // Set line segment color to green.
glBegin (GL_LINES); // Specify line-segment geometry.
glVertex2i (230, 140);
glVertex2i (60, 65);
glVertex2i (135, 215);
glVertex2i (230, 65);
glEnd ( );
glFlush ( );
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
glutInitWindowSize (500, 500);
// Set display-window width and height.
glutCreateWindow ("An Example OpenGL Program"); // Create display window.
init ( );// Execute initialization procedure.
glutDisplayFunc (lineSegment);// Send graphics to display window.
glutMainLoop ( );// Display everything and wait.
}
