#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
const GLfloat twoPi = 6.283185;
class scrPt {
public:
GLint x, y;
};
GLsizei winWidth = 500, winHeight = 500;
// Initial display window size.
void init (void)
{
glClearColor (1.0, 1.0, 1.0, 1.0);
glMatrixMode (GL_PROJECTION);
gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}
//Midpoint routines for displaying a circle.
void pieChart (void)
{
scrPt circCtr;
scrPt piePt;
GLint radius = winWidth / 4;
// Circle radius.
GLdouble sliceAngle, previousSliceAngle = 0.0;
GLint k, nSlices = 12;
// Number of slices.
GLfloat dataValues[12] = {10.0, 7.0, 13.0, 5.0, 13.0, 14.0,
3.0, 16.0, 5.0, 3.0, 17.0, 8.0};
GLfloat dataSum = 0.0;
// Circle center position.
circCtr.x = winWidth / 2;
circCtr.y = winHeight / 2;
//circleMidpoint (circCtr, radius);

// Call a midpoint circle-plot routine.
for (k = 0; k < nSlices; k++)
    dataSum += dataValues[k];

for (k = 0; k < nSlices; k++) {
    sliceAngle = twoPi * dataValues[k] / dataSum + previousSliceAngle;
    piePt.x = circCtr.x + radius * cos (sliceAngle);
    piePt.y = circCtr.y + radius * sin (sliceAngle);
    glBegin (GL_LINES);
    glVertex2i (circCtr.x, circCtr.y);
    glVertex2i (piePt.x, piePt.y);
    glEnd ( );
    previousSliceAngle = sliceAngle;
}
}

void circle (int noOfLines)
{
scrPt circCtr;
GLint radius = winWidth / 4;
// Circle radius.
// Circle center position.
circCtr.x = winWidth / 2;
circCtr.y = winHeight / 2;

glBegin (GL_LINE_LOOP);
for (int j = 0; j < noOfLines; j++) {
    float angle = twoPi * float(j) / float(noOfLines);
    glVertex2i (circCtr.x + (radius * cosf(angle)), circCtr.y + (radius * sinf(angle)));
}
glEnd ( );
}
void displayFcn (void)
{
glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
glColor3f (0.0, 0.0, 1.0); // Set circle color to blue.
circle(5000000);
pieChart ( );
glFlush ( );
}
void winReshapeFcn (GLint newWidth, GLint newHeight)
{
glMatrixMode (GL_PROJECTION);
glLoadIdentity ( );
gluOrtho2D (0.0, GLdouble (newWidth), 0.0, GLdouble (newHeight));
glClear (GL_COLOR_BUFFER_BIT);
/* Reset display-window size parameters.*/
winWidth = newWidth;
winHeight = newHeight;

}
int main (int argc, char** argv)
{
glutInit (&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition (100, 100);
glutInitWindowSize (winWidth, winHeight);
glutCreateWindow ("Pie Chart");
init ( );
glutDisplayFunc (displayFcn);
glutReshapeFunc (winReshapeFcn);
glutMainLoop ( );
}
