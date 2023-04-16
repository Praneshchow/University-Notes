// bresenham rectangle.
#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float x1,y1,x2,y2,x3,y3,x4,y4, x, y;
float R, Xc, Yc;
void horizontal(float ax, float ay, float bx, float by){
    float dx= bx-ax;
    float dy=by-ay;
    glBegin(GL_POINTS);
    glVertex2f(ax,ay);
    glEnd();
    float di=2*dy-dx;
    int i=0;
    for(i=0;i<abs(dx);i++)
    {
        if (di<0){
            y=ay;
            x=ax+1;
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();
            di=di+2*dy;
        }
        else{
            y=ay+1;
            x=ax;
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();
            di=di+2*dy-2*dx;
        }
        ax=x,ay=y;
    }
    glBegin(GL_POINTS);
    glVertex2f(bx,by);
    glEnd();

    glFlush();
}
void vertical(float ax, float ay, float bx, float by){
    float dx= bx-ax;
    float dy=by-ay;
    glBegin(GL_POINTS);
    glVertex2f(ax,ay);
    glEnd();
    float di=2*dx-dy;
    int i=0;
    for(i=0;i<abs(dy);i++)
    {
        if (di<0){
            y=ay+1;
            x=ax;
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();
            di=di+2*dx;
        }
        else{
            y=ay;
            ax=ax+1;
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();
            di=di+2*dx-2*dy;
        }
        ax=x,ay=y;
    }
    glBegin(GL_POINTS);
    glVertex2f(bx,by);
    glEnd();

    glFlush();
}
void circle (float Xc, float Yc, float R){
    x=0;
    y=R;
    float P=1-R;
    for(x=0; x<=y; x++)
    {
        glVertex2f(Xc+x,Yc+y);
        glVertex2f(Xc+y,Yc+x);
        glVertex2f(Xc-y,Yc+x);
        glVertex2f(Xc-x,Yc+y);
        glVertex2f(Xc-x,Yc-y);
        glVertex2f(Xc-y,Yc-x);
        glVertex2f(Xc+y,Yc-x);
        glVertex2f(Xc+x,Yc-y);

        if(P<0)
        {
            P=P+(2*x)+3;
        }
        else
        {
            y--;
            P=P+2*(x-y)+5;
        }

    }
    glEnd();

    glFlush();
}

void display(void)
{
    glBegin(GL_POINTS);

    circle (Xc, Yc, R);

     horizontal(x1, y1, x2, y2);
    vertical(x2, y2, x3, y3);
     horizontal(x4, y4, x3, y3);
    vertical(x1, y1, x4, y4);


}
void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv)
{
    printf("Enter the value of the points:\n");
    scanf("%f %f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    printf("Enter the value of the radius and points\n");
    scanf("%f %f %f",&R, &Xc, &Yc);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Pranesh");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

