#include <iostream>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
#include <time.h>
#include <string>
#include <cstring>
const GLfloat tam_x = 50.0f;
const GLfloat tam_y = 50.0f;
const GLint sy = 30;
const GLint my = 25;
const GLint hy = 20;
int hour;
int minute;
int second;
int c;
void RenderString(float x, float y, void *font, const unsigned char
*str) {
char *c;
glColor3ub(183, 28, 28);
glRasterPos2f(x, y);
glutBitmapString(font, str);
}
void circle(GLfloat xc, GLfloat yc, GLfloat raio, bool fill) {
const GLfloat c = 3.14169f / 180.0f;
GLint i;
glBegin(fill ? GL_TRIANGLE_FAN : GL_LINE_LOOP);
for (i = 0; i <= 360; i += 2) {
float a = i * c;
glVertex2f(xc + sin(a) * raio, yc + cos(a) * raio);
}
glEnd();
}
void draw(void) {
glClear(GL_COLOR_BUFFER_BIT);
glColor3ub(29, 128, 37);
circle(0, 0, tam_x, true);
glColor3f(0.0f, 0.0f, 0.0f);
unsigned char time_1[4] = "1";
unsigned char time_2[4] = "2";
unsigned char time_3[4] = "3";
unsigned char time_4[4] = "4";
unsigned char time_5[4] = "5";
unsigned char time_6[4] = "6";
unsigned char time_7[4] = "7";
unsigned char time_8[4] = "8";
unsigned char time_9[4] = "9";
unsigned char time_10[4] = "10";
unsigned char time_11[4] = "11";
unsigned char time_12[4] = "12";
RenderString(-2, 40, GLUT_BITMAP_TIMES_ROMAN_24, time_12);
RenderString(0, -40, GLUT_BITMAP_TIMES_ROMAN_24, time_6);
RenderString(40, 0, GLUT_BITMAP_TIMES_ROMAN_24, time_3);
RenderString(-40, 0, GLUT_BITMAP_TIMES_ROMAN_24, time_9);
RenderString(-35, 20, GLUT_BITMAP_TIMES_ROMAN_24, time_10);
RenderString(35, 20, GLUT_BITMAP_TIMES_ROMAN_24, time_2);
RenderString(35, -20, GLUT_BITMAP_TIMES_ROMAN_24, time_4);
RenderString(-35, -20, GLUT_BITMAP_TIMES_ROMAN_24, time_8);
RenderString(-20, 35, GLUT_BITMAP_TIMES_ROMAN_24, time_11);
RenderString(20, 35, GLUT_BITMAP_TIMES_ROMAN_24, time_1);
RenderString(20, -35, GLUT_BITMAP_TIMES_ROMAN_24, time_5);
RenderString(-20, -35, GLUT_BITMAP_TIMES_ROMAN_24, time_7);
glColor3ub(0, 0, 0);
glRasterPos2f(-6, -20);
const unsigned char ND[]="NEW DELHI";
const unsigned char NY[]="NEW YORK";
const unsigned char LD[]="LONDON";
const unsigned char TK[]="TOKYO";
const unsigned char SY[]="SYDNEY";
const unsigned char MW[]="MOSCOW";
const unsigned char DE[]="UTC";
const unsigned char ST[]="Stay tuned for more time zones.";
switch(c) {
case 1:
glRasterPos2f(-7, -20);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, ND);
break;
case 2:
glRasterPos2f(-7, -20);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, NY);
break;
case 3:
glRasterPos2f(-5, -20);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, LD);
break;
case 4:
glRasterPos2f(-4, -20);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, TK);
break;
case 5:
glRasterPos2f(-5, -20);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, SY);
break;
case 6:
glRasterPos2f(-5, -20);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, MW);
break;
default:
glRasterPos2f(-3, -20);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, DE);
glRasterPos2f(-75, 40);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, ST);
}
const unsigned char AL[]="Made by: AKASH RP";
const unsigned char AN[]=" AMBARISH BN";
glRasterPos2f(50, -40);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, AL);
glRasterPos2f(56, -45);
glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, AN);
// Second
float angle_s = second * 6;
glRotatef(-angle_s, 0.0f, 0.0f, 1.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2i(0, 0);
glVertex2i(0, sy);
glEnd();
glLoadIdentity();
//minute
float angle_m = minute * 6;
glRotatef(-angle_m, 0.0f, 0.0f, 1.0f);
glLineWidth(5);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2i(0, 0);
glVertex2i(0, my);
glEnd();
glLoadIdentity();
//hour
float angle_h = (hour + minute / 60.0) * 30;
glRotatef(-angle_h, 0.0f, 0.0f, 1.0f);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2i(0, 0);
glVertex2i(0, hy);
glEnd();
glLoadIdentity();
glFlush();
}
void resize(GLsizei width, GLsizei height) {
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (width <= height)
gluOrtho2D(-tam_x, tam_x, -tam_y * height / width, tam_y
* height / width);
else
gluOrtho2D(-tam_x * width / height, tam_x * width /
height, -tam_y, tam_y);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void add(int hz,int mz) {
hour=hour+hz;
minute=minute+mz;
if(minute>=60) {
hour=hour + (minute)/60;
minute=minute%60;
}
}
void sub(int hz,int mz) {
int m,h;
if(minute< mz) {
--hour;
minute+= 60;
}
m = minute-mz;
h = hour - hz;
hour=h;
minute=m;
}
void move(int n) {
time_t agora = time(0);
struct tm *datahour = localtime(&agora);
hour = datahour->tm_hour;
minute = datahour->tm_min;
second = datahour->tm_sec;
switch(c) {
case 1:
break;
case 2:
sub(9,30);
break;
case 3:
sub(4,30);
break;
case 4:
add(3,30);
break;
case 5:
add(4,30);
break;
case 6:
sub(2,30);
break;
default:
sub(5,30);
}
glutPostRedisplay();
glutTimerFunc(1000, move, 0);
}
void initialize(void) {
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
int main(int argc, char **argv) {
printf("Welcome to The Analog clock\n");
printf("Choose any 1 time zones from\n");
printf("\t1.New Delhi\n");
printf("\t2.New York\n");
printf("\t3.London\n");
printf("\t4.Tokyo\n");
printf("\t5.Sydney\n");
printf("\t6.Moscow\n");
printf("Enter your choice: ");
scanf("%d",&c);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1300, 1300);
glutCreateWindow("Clock");
glutDisplayFunc(draw);
glutReshapeFunc(resize);
glutTimerFunc(1000, move, 0);
initialize();
glutMainLoop();
return 0;
}
