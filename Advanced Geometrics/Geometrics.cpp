
#include<GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// intialize window size
GLsizei winWidth = 300, winHeight = 300;
//--------------------------------------------------------------------------------------------------------------------------------
// Shape -1 : Hexagon
//--------------------------------------------------------------------------------------------------------------------------------
// intialize constant
const double TWO_PI = 6.2831853;
// intial values
int edgeLength = 150;
int num_of_vertex = 6;
GLdouble theta;
// intialze circle center as window center
int center_x = winWidth/2;
int center_y = winHeight/2;
// (or others, depending on the system in use)
void init_1 (void)
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
void display_Hex (void)
{
glClear (GL_COLOR_BUFFER_BIT);// Clear display window.
glColor3f (0.25, 0.25, 0.25); // Set line segment color to green.
filledHexagon(center_x,center_y,edgeLength);
// Process all OpenGL routines as quickly as possible.
}
//--------------------------------------------------------------------------------------------------------------------------------
// Shape -2 : Pie Chart
//--------------------------------------------------------------------------------------------------------------------------------
const GLfloat twoPi = 6.283185;
class scrPt {
public:
GLint x, y;
};
// Initial display window size.
void init_2 (void)
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
    sliceAngle = TWO_PI * dataValues[k] / dataSum + previousSliceAngle;
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
void display_Pie (void)
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
//--------------------------------------------------------------------------------------------------------------------------------
// Shape -3 : Cube
//--------------------------------------------------------------------------------------------------------------------------------
void init_3 (void)
{
glClearColor (1.0, 1.0, 1.0, 0.0);
glMatrixMode (GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}
void cube (void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.25, 0.25, 0.25);
glBegin (GL_POLYGON);
glVertex3f (0.1,0.1,0.0);
glVertex3f (0.4,0.1,0.0);
glVertex3f (0.4,0.5,0.0);
glVertex3f (0.1,0.5,0.0);
glEnd ( );
glColor3f (0.0, 0.0, 0.0);
glBegin (GL_POLYGON);
glVertex3f (0.1,0.5,0.0);
glVertex3f (0.4,0.5,0.0);
glVertex3f (0.5,0.65,0.0);
glVertex3f (0.2,0.65,0.0);
glEnd ( );
glColor3f (0.1, 0.0, 0.0);
glBegin (GL_POLYGON);
glVertex3f (0.4,0.1,0.0);
glVertex3f (0.5,0.25,0.0);
glVertex3f (0.5,0.65,0.0);
glVertex3f (0.4,0.5,0.0);
glEnd ( );
glFlush ( );
}
//--------------------------------------------------------------------------------------------------------------------------------
// Shape -4 : limacon , cardioid, threeLeaf, fourLeaf, spiral
//--------------------------------------------------------------------------------------------------------------------------------
struct screenPt
{
GLint x;
GLint y;
};
typedef enum { limacon = 1, cardioid, threeLeaf, fourLeaf, spiral } curveName;
void init_4 (void)
{
glClearColor (1.0, 1.0, 1.0, 1.0);
glMatrixMode (GL_PROJECTION);
gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}
void lineSegment (screenPt pt1, screenPt pt2)
{
glBegin (GL_LINES);
glVertex2i (pt1.x, pt1.y);
glVertex2i (pt2.x, pt2.y);
glEnd ( );
}
void drawCurve (GLint curveNum)
{
const GLint a = 75, b = 60;
GLfloat r, theta, dtheta = 1.0 / float (a);
GLint x0 = 150, y0 = 150; // Set an initial screen position.
screenPt curvePt[2];
glColor3f (0.0, 0.0, 0.0); // Set curve color to black.
curvePt[0].x = x0; // Initialize curve position.
curvePt[0].y = y0;
// Graphics Output Primitives;

switch (curveNum) {
case limacon: curvePt[0].x += a + b; break;
case cardioid: curvePt[0].x += a + a; break;
case threeLeaf: curvePt[0].x += a; break;
case fourLeaf: curvePt[0].x += a; break;
case spiral: break;
default: break;
}
theta = dtheta;
while (theta < TWO_PI) {
switch (curveNum) {
case limacon:
r = a * cos (theta) + b; break;
case cardioid:
r = a * (1 + cos (theta)); break;
case threeLeaf:
r = a * cos (3 * theta); break;
case fourLeaf:
r = a * cos (2 * theta); break;
case spiral:
r = (a / 4.0) * theta; break;
default: break;
}
curvePt[1].x = x0 + r * cos (theta);
curvePt[1].y = y0 + r * sin (theta);
lineSegment (curvePt[0], curvePt[1]);
curvePt[0].x = curvePt[1].x;
curvePt[0].y = curvePt[1].y;
theta += dtheta;
}
}

void winReshapeFcn_2 (GLint newWidth, GLint newHeight)
{
glMatrixMode (GL_PROJECTION);
glLoadIdentity ( );
gluOrtho2D (0.0, (GLdouble) newWidth, 0.0, (GLdouble) newHeight);
glClear (GL_COLOR_BUFFER_BIT);
}
void display_Shapes_1 ()
{
GLint curveNum;
glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
curveNum = 1 ;
drawCurve (curveNum);

glFlush ( );

}
void display_Shapes_2 ()
{
GLint curveNum;
glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
curveNum = 2 ;
drawCurve (curveNum);

glFlush ( );

}
void display_Shapes_3 ()
{
GLint curveNum;
glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
curveNum = 3 ;
drawCurve (curveNum);

glFlush ( );

}
void display_Shapes_4 ()
{
GLint curveNum;
glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
curveNum = 4 ;
drawCurve (curveNum);

glFlush ( );

}
void display_Shapes_5 ()
{
GLint curveNum;
glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
curveNum = 5 ;
drawCurve (curveNum);

glFlush ( );

}

int main (int argc, char** argv)
{
glutInit (&argc, argv);
// Initialize GLUT.
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
// Set display mode.

// Shape :1
glutInitWindowPosition (0, 0);
// Set top-left display-window position.
glutInitWindowSize (winHeight, winWidth);
// Set display-window width and height.
glutCreateWindow ("Hexagon");
init_1 ( );// Execute initialization procedure.
glutDisplayFunc (display_Hex);
//Shape :2
glutInitWindowPosition (310, 0);
glutInitWindowSize (winWidth, winHeight);
glutCreateWindow ("Pie Chart");
init_2 ( );
glutDisplayFunc (display_Pie);
glutReshapeFunc (winReshapeFcn);// Send graphics to display window.
//Shape 3:
glutInitWindowPosition (615, 0);
glutInitWindowSize (400, 300);
glutCreateWindow ("Cube shape");
init_3 ( );
glutDisplayFunc (cube);
// Shape 4:
glutInitWindowPosition (1020, 0);
glutInitWindowSize (winWidth, winHeight);
glutCreateWindow ("Limacon");
init_4 ( );
glutDisplayFunc (display_Shapes_1);
glutReshapeFunc (winReshapeFcn_2);
// Shape 5:
glutInitWindowPosition (0, 350);
glutInitWindowSize (winWidth, winHeight);
glutCreateWindow ("Cardioid");
init_4 ( );
glutDisplayFunc (display_Shapes_2);
glutReshapeFunc (winReshapeFcn_2);
// Shape 6:
glutInitWindowPosition (310, 350);
glutInitWindowSize (winWidth, winHeight);
glutCreateWindow ("ThreeLeaf");
init_4 ( );
glutDisplayFunc (display_Shapes_3);
glutReshapeFunc (winReshapeFcn_2);
// Shape 7:
glutInitWindowPosition (615, 350);
glutInitWindowSize (winWidth, winHeight);
glutCreateWindow ("FourLeaf");
init_4 ( );
glutDisplayFunc (display_Shapes_4);
glutReshapeFunc (winReshapeFcn_2);
// Shape 8:
glutInitWindowPosition (1020, 350);
glutInitWindowSize (winWidth, winHeight);
glutCreateWindow ("Spiral");
init_4 ( );
glutDisplayFunc (display_Shapes_5);
glutReshapeFunc (winReshapeFcn_2);
glutMainLoop ( );// Display everything and wait.
}

