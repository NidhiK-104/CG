#include<gl/glut.h>
#include<stdio.h>
float wid1, wid2, t;
static GLfloat spin = 0.0;

void myInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glClearColor(1.0, 1.0, 1.0, 1.0);
}
void display()
{
    glutSetWindow(t);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glRotatef(spin, 0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
      glColor3f(1, 0, 0);
      glVertex3f(-0.25, -0.25, 0.25);
      glColor3f(0, 1, 0);
      glVertex3f(0.25, -0.25, 0.25);
      glColor3f(0, 0, 1);
      glVertex3f(0.25, 0.10, 0.25);
      glColor3f(1, 0, 1);
      glVertex3f(-0.25, 0.10, 0.25);
    glEnd();
    glPopMatrix();
    if (t == wid1)
    {
        glFlush();
        t = wid2;
    }
    else
    {
        glutSwapBuffers();
        t = wid1;
    }
}
void spinDisplay(void)
{
    spin += 0.02;
    glutPostRedisplay();
}
void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(spinDisplay);
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(NULL);
}
void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    wid1 = glutCreateWindow("Single\n");
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutDisplayFunc(display);
    //glutMouseFunc(myMouse); // Onclick rotation
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(510, 0);
    wid1 = glutCreateWindow("Double\n");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    t = wid1;
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    myInit();
    glutMainLoop();
}
