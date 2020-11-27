#include <GL\glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include "iostream"
#include <time.h>
using namespace std;

bool flag = true;
GLfloat xRotated, yRotated, zRotated;

void check(int value)
{
    if (flag == true)
    {
        flag = false;
    }
    else if (flag == false)
    {
        flag = true;
    }
    cout << flag << "\n";
    glutPostRedisplay();
    glutTimerFunc(1000, check, 0);
}

void highlight_lines(float x, float y, float z, float live_transparency_line, float dead_transparency_line)
{
    float a, b, c;
    for (a = 0; a <= 0.5; a = a + 0.1)
    {
        for (b = 0; b <= 0.5; b = b + 0.1)
        {
            for (c = 0; c <= 0.5; c = c + 0.1)
            {
                //First Hidden Layer Plane 1 
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, live_transparency_line);
                glVertex3f(x, y, z);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glEnd();

                //First Hidden Layer Plane 4
                if (c < 0.44)
                {
                    glPointSize(3.0);
                    glBegin(GL_POINTS);
                    glVertex3f(x, y, z);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                    glColor4f(1.0, 1.0, 1.0, live_transparency_line);
                    glVertex3f(x, y, z);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glEnd();
                }

                //Second Hidden Layer Plane 1 
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, live_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.4);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glEnd();

                //output layer 
                glPointSize(20.0);
                glBegin(GL_POINTS);
                glColor4f(0.0, 0.0, 1.0, 1.0);
                glVertex3f(0.2, 0.35, 1.2);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, live_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.8);
                glVertex3f(0.2, 0.35, 1.2);
                glVertex3f(0.2, 0.35, 1.2);
                glEnd();

            }
        }
    }
}

void displayTorus(void)
{
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(-1.0, -0.75, -3.5); // -1.6 for scaling of 2.3
    // Red color used to draw.
    glColor3f(0.8, 0.2, 0.1);
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    glScalef(2.0, 2.0, 2.0);

    float dead_transparency_line = 0.08;
    float live_transparency_line = 0.15;
    float a, b, c;
    for (a = 0; a <= 0.5; a = a + 0.1)
    {
        for (b = 0; b <= 0.5; b = b + 0.1)
        {
            for (c = 0; c <= 0.5; c = c + 0.1)
            {
                //Input Layer 
                glPointSize(15.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.1 + a, 0.0);
                glEnd();

                //First Hidden Layer Plane 1 
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.0);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glEnd();

                //First Hidden Layer Plane 2
                if (c < 0.47)
                {
                    glPointSize(3.0);
                    glBegin(GL_POINTS);
                    glVertex3f(0.1 + b, 0.1 + a, 0.0);
                    glVertex3f(0.13 + b, 0.13 + c, 0.42);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                    glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                    glVertex3f(0.1 + b, 0.1 + a, 0.0);
                    glVertex3f(0.13 + b, 0.13 + c, 0.42);
                    glVertex3f(0.13 + b, 0.13 + c, 0.42);
                    glEnd();
                }

                //First Hidden Layer Plane 3
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glVertex3f(0.1 + b, 0.1 + a, 0.0);
                glVertex3f(0.07 + b, 0.07 + c, 0.42);
                glVertex3f(0.07 + b, 0.07 + c, 0.42);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.0);
                glVertex3f(0.07 + b, 0.07 + c, 0.42);
                glVertex3f(0.07 + b, 0.07 + c, 0.42);
                glEnd();

                //First Hidden Layer Plane 4
                if (c < 0.44)
                {
                    glPointSize(3.0);
                    glBegin(GL_POINTS);
                    glVertex3f(0.1 + b, 0.1 + a, 0.0);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                    glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                    glVertex3f(0.1 + b, 0.1 + a, 0.0);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glEnd();
                }

                //Second Hidden Layer Plane 1 
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.4);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glEnd();

                //Second Hidden Layer Plane 2
                if (c < 0.47)
                {
                    glPointSize(3.0);
                    glBegin(GL_POINTS);
                    glVertex3f(0.1 + b, 0.1 + a, 0.42);
                    glVertex3f(0.13 + b, 0.13 + c, 0.82);
                    glVertex3f(0.13 + b, 0.13 + c, 0.82);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                    glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                    glVertex3f(0.1 + b, 0.1 + a, 0.0);
                    glVertex3f(0.13 + b, 0.13 + c, 0.82);
                    glVertex3f(0.13 + b, 0.13 + c, 0.82);
                    glEnd();
                }

                //Output Layer
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.35, 1.2);
                glVertex3f(0.1 + b, 0.35, 1.2);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + a, 0.35, 1.2);
                glVertex3f(0.1 + a, 0.35, 1.2);
                glEnd();
            }
        }
    }

    if (flag == true)
    {
        //Inut image '1'
        glPointSize(15.0);
        glBegin(GL_POINTS);
        glColor4f(0.0, 0.0, 1.0, 1.0);
        glVertex3f(0.3, 0.2, 0.0);
        glVertex3f(0.3, 0.3, 0.0);
        glVertex3f(0.3, 0.4, 0.0);
        glVertex3f(0.3, 0.5, 0.0);
        glVertex3f(0.3, 0.6, 0.0);
        glVertex3f(0.4, 0.5, 0.0);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.3, 0.2, 0.0);
        glVertex3f(0.4, 0.2, 0.0);
        glEnd();

        //Highlighting the active neurons 
        highlight_lines(0.3, 0.2, 0.0, live_transparency_line, dead_transparency_line);
        highlight_lines(0.3, 0.3, 0.0, live_transparency_line, dead_transparency_line);
        highlight_lines(0.3, 0.4, 0.0, live_transparency_line, dead_transparency_line);
        highlight_lines(0.3, 0.5, 0.0, live_transparency_line, dead_transparency_line);
        highlight_lines(0.3, 0.6, 0.0, live_transparency_line, dead_transparency_line);
        highlight_lines(0.4, 0.5, 0.0, live_transparency_line, dead_transparency_line);
        highlight_lines(0.2, 0.2, 0.0, live_transparency_line, dead_transparency_line);
        highlight_lines(0.3, 0.2, 0.0, live_transparency_line, dead_transparency_line);
        highlight_lines(0.4, 0.2, 0.0, live_transparency_line, dead_transparency_line);
    }
    //Flushing the whole output
    glFlush();
    // sawp buffers called because we are using double buffering 
    glutSwapBuffers();
}

void reshapeTorus(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
    glViewport(0, 0, x, y);  //Use the whole window for rendering
}

void idleTorus(void)
{
    yRotated += 0.05;
    displayTorus();
}


int main(int argc, char** argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // window size
    glutInitWindowSize(1350, 950);
    glutInitWindowPosition(0, 0);
    // create the window 
    glutCreateWindow("Torus Rotating Animation");
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    xRotated = yRotated = zRotated = 30.0;
    xRotated = 33;
    yRotated = 40;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //Assign  the function used in events
    glutDisplayFunc(displayTorus);
    glutReshapeFunc(reshapeTorus);
    glutIdleFunc(idleTorus);
    //Let start glut loop
    glutTimerFunc(100, check, 0);
    glutMainLoop();
    return 0;
}