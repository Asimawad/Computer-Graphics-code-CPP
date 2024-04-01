#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void display();
void reshape(int, int);
void timer(int);

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
}
int main(int argc , char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE| GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("Cube");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();
}

float x_pos =0.0;
int state=1;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
    glRotatef(30,1.f,1.f,0.f);

    //Draw
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glVertex3f( -0.5f, -0.5f, 0.5f);
    glVertex3f( -0.5f, 0.5f, 0.5f);


    glColor3f(1.0f, 1.0f, 0.0f);     // yellow
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( -0.5f, -0.5f, -0.5f);
    glVertex3f( -0.5f, 0.5f, -0.5f);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);     // Green
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f( -0.5f, 0.5f, -0.5f);
    glVertex3f( -0.5f, 0.5f, 0.5f);
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);     // Green
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);     // Green
    glVertex3f( -0.5f, 0.5f, 0.5f);
    glVertex3f( -0.5f, -0.5f, 0.5f);
    glVertex3f( -0.5f, -0.5f, -0.5f);
    glVertex3f( -0.5f, 0.5f, -0.5f);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);     // Green
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glVertex3f( -0.5f, -0.5f, 0.5f);
    glVertex3f( -0.5f, 0.5f, 0.5f);





// Bottom face (y = -1.0f)

    glEnd();

    glutSwapBuffers();
}

void reshape(int w , int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,2.0,50.0);
    glMatrixMode(GL_MODELVIEW);



}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
}
