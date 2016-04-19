#include <GL\glut.h>

GLfloat Rotated,cRotated;
float i,j;
void car()
{
    glPushMatrix();
    glTranslatef(-0.8,-0.8,-1);
    glColor3f(0.137255,0.556863,0.419608);
    glRotatef(90,0.0,1.0,0.0);
    glRotatef(cRotated,0.0,0.0,1.0);
    GLUquadricObj* q = gluNewQuadric ();
    gluCylinder (q, .1, .1, 1.6, 50, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,-.5,-1.8);
    glColor3f(0.137255,0.556863,0.419608);
    glRotatef(90,0.0,1.0,0.0);
    glRotatef(cRotated,0.0,0.0,1.0);
    gluCylinder (q, .2, .2, 2, 50, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-1,-2.7);
    glColor3f(0.35,0.35,0.35);
    glRotatef(90,0.0,1.0,0.0);
    glRotatef(90,1.0,0.0,0.0);
    glRotatef(45,0.0,0.0,1.0);
    glutSolidTorus(.4,1.1,150,4);
	glPopMatrix();

    glutSwapBuffers();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(i=25,j=23; i<=25; i=i+.001,j=j-.002)
    {
        glPushMatrix();
        glTranslatef(-10,-j,-i);
        glColor3f(0,1,0);
        glRotatef(90,0.0,1.0,0.0);
        glRotatef(Rotated,0.0,0.0,1.0);
        GLUquadricObj* q = gluNewQuadric ();
        gluCylinder (q, 25, 25, 20, 60, 1);
        glPopMatrix();
    }

    car();
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(140.0,(GLdouble)x/(GLdouble)y,0.5,16.0);
    glViewport(0,0,x,y);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void idle(void)
{
    Rotated+=.12;
    cRotated+=.5;
    display();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("Car Driving");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glClearColor(1,1,0.9,1);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
}
