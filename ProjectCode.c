#include <Windows.h>
#include <iostream>
#include<Windows.h>
#define STB_IMAGE_IMPLEMENTATION
#define GLUT_DISABLE_ATEXIT_HACK
#include <gl/glut.h>
#include"stb_image.h"
#include<math.h>
float cx=93, cy=-90;
const double PI = 3.141592654;
int frameNumber = 0, frameNumber1 = 0, frameNumber2 = 0;
int d = 0;
static int submenu_id;
static int menu_id;
static int window;
static int value = 0;
int speed = 0,speed1=0, speed2 = 0;
int temp2 = 0,temp3=0;
int width, height, nrc;
unsigned int texture;
char fname[2][20] = { "bg.jpg","last.jpg" };
void setImage(int index) 
{
	unsigned char* data = stbi_load(fname[index], &width, &height, &nrc, 0);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		//glGeneratedMipmap(GL_TEXTURE_2D);
	}
	else printf("Error");
	stbi_image_free(data);
}
void doFrame(int v)
{
	switch (v)
	{
	case 1:
		frameNumber++;
		glutPostRedisplay();
		glutTimerFunc(30, doFrame, 1);
		break;
	case 2:
		frameNumber1++;
		glutPostRedisplay();
		glutTimerFunc(30, doFrame, 2);
		break;
	case 3:
		frameNumber2++;
		glutPostRedisplay();
		glutTimerFunc(30, doFrame, 3);
		break;
	}
}

void drawText(float x, float y, int r, int g, int b, int d, const char* string)
{
	int j = strlen(string);
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
		for (int k = d; k > 0; k--)
		{
			glFlush();
		}
	}
}
void circle(GLfloat x, GLfloat y, GLdouble radius) {
	float x2, y2;
	float angle;
	glPointSize(2.0);
	glBegin(GL_TRIANGLE_FAN);
	for (angle = 0.0; angle < 6.3; angle += 0.01)
	{
		x2 = x + sin(angle) * radius;
		y2 = y + cos(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();
	glPointSize(2.0);

}
void clouds(float x, float y)
{
	glColor3f(1.0, 1.0, 1.0);
	circle(x + 0.0, y + 2.5, 3);
	circle(x + 5.5, y + 4.0, 3);
	circle(x + 8.5, y + 2.5, 3);
	circle(x + 3.5, y + 0.5, 3);
	circle(x + 5.5, y + 0.0, 3);
	circle(x + 8.5, y + 0.5, 3);
	circle(x + 10.5, y + 2.0, 3);
}
void drawSun()
{
	int i;
	glColor3f(1, 1, 0);
	for (i = 0; i < 13; i++)
	{
		glLineWidth(3);				  // Draw 13 rays, with different rotations.
		glRotatef(360 / 13, 0, 0, 1); // Note that the rotations accumulate!
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(15, 0);
		glEnd();
	}
	glColor3f(0, 0, 0);
}
void wheels()
{
	glColor3f(0.0, 0.0, 0.0);
	circle(cx + 8, cy - 2, 2.5);
	circle(cx + 20, cy - 2, 2.5);
}
void car()
{

	glBegin(GL_POLYGON);
	glVertex2f(cx, cy);
	glVertex2f(cx + 1, cy + 8);
	glVertex2f(cx + 8, cy + 8);
	glVertex2f(cx + 10, cy + 12.5);

	glVertex2f(cx + 19, cy + 12.5);
	glVertex2f(cx + 21, cy + 8);
	glVertex2f(cx + 28, cy + 8);
	glVertex2f(cx + 29, cy);
	glEnd();
}

void hospital()
{
	//Ground
	glBegin(GL_QUADS);
	glColor3f(0.34, 0.49, 0.28);
	glVertex3f(-125.0, -74.0, 0.0);
	glVertex3f(-125.0, -45.0, 0.0);
	glVertex3f(125.0, -45.0, 0.0);
	glVertex3f(125.0, -74.0, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.6, 0.0);
	glVertex3f(-80.0, -60.0, 0.0);
	glVertex3f(-80.0, 75.0, 0.0);
	glVertex3f(80.0, 75.0, 0.0);
	glVertex3f(80.0, -60.0, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.6, 0.0);
	glVertex3f(-80.0, -60.0, 0.0);
	glVertex3f(-85.0, -55.0, 0.0);
	glVertex3f(-85.0, 80.0, 0.0);
	glVertex3f(-80.0, 75.0, 0.0);
	//glEnd();

	glColor3f(1.0, 0.6, 0.0);
	glVertex3f(-79.0, -56.0, 0.0);
	glVertex3f(-79.0, -17.5, 0.0);
	glVertex3f(-59.0, -17.5, 0.0);
	glVertex3f(-59.0, -56.0, 0.0);

	glVertex3f(68.0, -56.0, 0.0);
	glVertex3f(68.0, -17.5, 0.0);
	glVertex3f(79.0, -17.5, 0.0);
	glVertex3f(-79.0, -56.0, 0.0);

	glVertex3f(-81.25, -56.0, 0.0);
	glVertex3f(-84.5, -53.5, 0.0);
	glVertex3f(-84.5, -13.5, 0.0);
	glVertex3f(-81.25, -17.0, 0.0);
	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-44.0, -40.0, 0.0);
	glVertex3f(-44.0, -20.0, 0.0);
	glVertex3f(-32.0, -20.0, 0.0);
	glVertex3f(-32.0, -40.0, 0.0);

	glVertex3f(-30.0, -40.0, 0.0);
	glVertex3f(-30.0, -20.0, 0.0);
	glVertex3f(-18.0, -20.0, 0.0);
	glVertex3f(-18.0, -40.0, 0.0);

	glVertex3f(-44.0, -40.0, 0.0);
	glVertex3f(-44.0, -20.0, 0.0);
	glVertex3f(-32.0, -20.0, 0.0);
	glVertex3f(-32.0, -40.0, 0.0);

	glVertex3f(-64.0, -40.0, 0.0);
	glVertex3f(-64.0, -20.0, 0.0);
	glVertex3f(-52.0, -20.0, 0.0);
	glVertex3f(-52.0, -40.0, 0.0);

	glVertex3f(20.0, -40.0, 0.0);
	glVertex3f(20.0, -20.0, 0.0);
	glVertex3f(32.0, -20.0, 0.0);
	glVertex3f(32.0, -40.0, 0.0);

	glVertex3f(34.0, -40.0, 0.0);
	glVertex3f(34.0, -20.0, 0.0);
	glVertex3f(46.0, -20.0, 0.0);
	glVertex3f(46.0, -40.0, 0.0);

	glVertex3f(52.0, -40.0, 0.0);
	glVertex3f(52.0, -20.0, 0.0);
	glVertex3f(64.0, -20.0, 0.0);
	glVertex3f(64.0, -40.0, 0.0);

	glVertex3f(-44.0, 5.0, 0.0);
	glVertex3f(-44.0, 25.0, 0.0);
	glVertex3f(-32.0, 25.0, 0.0);
	glVertex3f(-32.0, 5.0, 0.0);

	//changed

	glVertex3f(-30.0, 5.0, 0.0);
	glVertex3f(-30.0, 25.0, 0.0);
	glVertex3f(-18.0, 25.0, 0.0);
	glVertex3f(-18.0, 5.0, 0.0);

	glVertex3f(-64.0, 5.0, 0.0);
	glVertex3f(-64.0, 25.0, 0.0);
	glVertex3f(-52.0, 25.0, 0.0);
	glVertex3f(-52.0, 5.0, 0.0);

	glVertex3f(20.0, 5.0, 0.0);
	glVertex3f(20.0, 25.0, 0.0);
	glVertex3f(32.0, 25.0, 0.0);
	glVertex3f(32.0, 5.0, 0.0);

	glVertex3f(34.0, 5.0, 0.0);
	glVertex3f(34.0, 25.0, 0.0);
	glVertex3f(46.0, 25.0, 0.0);
	glVertex3f(46.0, 5.0, 0.0);

	glVertex3f(52.0, 5.0, 0.0);
	glVertex3f(52.0, 25.0, 0.0);
	glVertex3f(64.0, 25.0, 0.0);
	glVertex3f(64.0, 5.0, 0.0);

	glVertex3f(-44.0, 50.0, 0.0);
	glVertex3f(-44.0, 70.0, 0.0);
	glVertex3f(-32.0, 70.0, 0.0);
	glVertex3f(-32.0, 50.0, 0.0);

	glVertex3f(-30.0, 50.0, 0.0);
	glVertex3f(-30.0, 70.0, 0.0);
	glVertex3f(-18.0, 70.0, 0.0);
	glVertex3f(-18.0, 50.0, 0.0);

	glVertex3f(-64.0, 50.0, 0.0);
	glVertex3f(-64.0, 70.0, 0.0);
	glVertex3f(-52.0, 70.0, 0.0);
	glVertex3f(-52.0, 50.0, 0.0);

	glVertex3f(-78.0, 50.0, 0.0);
	glVertex3f(-78.0, 70.0, 0.0);
	glVertex3f(-66.0, 70.0, 0.0);
	glVertex3f(-66.0, 50.0, 0.0);

	glVertex3f(-78.0, 5.0, 0.0);
	glVertex3f(-78.0, 25.0, 0.0);
	glVertex3f(-66.0, 25.0, 0.0);
	glVertex3f(-66.0, 5.0, 0.0);

	glVertex3f(20.0, 50.0, 0.0);
	glVertex3f(20.0, 70.0, 0.0);
	glVertex3f(32.0, 70.0, 0.0);
	glVertex3f(32.0, 50.0, 0.0);

	glVertex3f(34.0, 50.0, 0.0);
	glVertex3f(34.0, 70.0, 0.0);
	glVertex3f(46.0, 70.0, 0.0);
	glVertex3f(46.0, 50.0, 0.0);

	glVertex3f(52.0, 50.0, 0.0);
	glVertex3f(52.0, 70.0, 0.0);
	glVertex3f(64.0, 70.0, 0.0);
	glVertex3f(64.0, 50.0, 0.0);

	glVertex3f(66.0, 50.0, 0.0);
	glVertex3f(66.0, 70.0, 0.0);
	glVertex3f(78.0, 70.0, 0.0);
	glVertex3f(78.0, 50.0, 0.0);

	glVertex3f(66.0, 5.0, 0.0);
	glVertex3f(66.0, 25.0, 0.0);
	glVertex3f(78.0, 25.0, 0.0);
	glVertex3f(78.0, 5.0, 0.0);
	glEnd();

	glLineWidth(3);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);

	glVertex3f(-42.0, -40.0, 0.0);
	glVertex3f(-42.0, -20.0, 0.0);
	glVertex3f(-39.0, -40.0, 0.0);
	glVertex3f(-39.0, -20.0, 0.0);
	glVertex3f(-36.0, -40.0, 0.0);
	glVertex3f(-36.0, -20.0, 0.0);
	glVertex3f(-33.0, -40.0, 0.0);
	glVertex3f(-33.0, -20.0, 0.0);

	glVertex3f(-62.0, -40.0, 0.0);
	glVertex3f(-62.0, -20.0, 0.0);
	glVertex3f(-59.0, -40.0, 0.0);
	glVertex3f(-59.0, -20.0, 0.0);
	glVertex3f(-56.0, -40.0, 0.0);
	glVertex3f(-56.0, -20.0, 0.0);
	glVertex3f(-53.0, -40.0, 0.0);
	glVertex3f(-53.0, -20.0, 0.0);

	glVertex3f(54.0, -40.0, 0.0);
	glVertex3f(54.0, -20.0, 0.0);
	glVertex3f(57.0, -40.0, 0.0);
	glVertex3f(57.0, -20.0, 0.0);
	glVertex3f(60.0, -40.0, 0.0);
	glVertex3f(60.0, -20.0, 0.0);
	glVertex3f(63.0, -40.0, 0.0);
	glVertex3f(63.0, -20.0, 0.0);

	glVertex3f(22.0, -40.0, 0.0);
	glVertex3f(22.0, -20.0, 0.0);
	glVertex3f(25.0, -40.0, 0.0);
	glVertex3f(25.0, -20.0, 0.0);
	glVertex3f(28.0, -40.0, 0.0);
	glVertex3f(28.0, -20.0, 0.0);
	glVertex3f(31.0, -40.0, 0.0);
	glVertex3f(31.0, -20.0, 0.0);

	glVertex3f(36.0, -40.0, 0.0);
	glVertex3f(36.0, -20.0, 0.0);
	glVertex3f(39.0, -40.0, 0.0);
	glVertex3f(39.0, -20.0, 0.0);
	glVertex3f(42.0, -40.0, 0.0);
	glVertex3f(42.0, -20.0, 0.0);
	glVertex3f(45.0, -40.0, 0.0);
	glVertex3f(45.0, -20.0, 0.0);

	glVertex3f(-28.0, -40.0, 0.0);
	glVertex3f(-28.0, -20.0, 0.0);
	glVertex3f(-25.0, -40.0, 0.0);
	glVertex3f(-25.0, -20.0, 0.0);
	glVertex3f(-28.0, -40.0, 0.0);
	glVertex3f(-28.0, -20.0, 0.0);
	glVertex3f(-25.0, -40.0, 0.0);
	glVertex3f(-25.0, -20.0, 0.0);
	glEnd();

	//BUILDING CEILING

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(-85.0, 80.0, 0.0);
	glVertex3f(75.0, 80.0, 0.0);
	glVertex3f(80.0, 75.0, 0.0);
	glVertex3f(-80.0, 75.0, 0.0);

	glVertex3f(-16.0, 45.0, 0.0);
	glVertex3f(-16.0, 74.0, 0.0);
	glVertex3f(16.0, 74.0, 0.0);
	glVertex3f(16.0, 45.0, 0.0);

	glVertex3f(-16.0, 0.0, 0.0);
	glVertex3f(-16.0, 27.5, 0.0);
	glVertex3f(16.0, 27.5, 0.0);
	glVertex3f(16.0, 0.0, 0.0);

	glVertex3f(-16.0, -60.0, 0.0);
	glVertex3f(-16.0, -15.0, 0.0);
	glVertex3f(16.0, -15.0, 0.0);
	glVertex3f(16.0, -60.0, 0.0);
	glEnd();

	//BUILDING PARTITION

	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);

	glVertex3f(-85.0, 80.0, 0.0);
	glVertex3f(75.0, 80.0, 0.0);
	glVertex3f(-48.0, -60.0, 0.0);
	glVertex3f(-48.0, 75.0, 0.0);
	glVertex3f(-16.0, -60.0, 0.0);
	glVertex3f(-16.0, 75.0, 0.0);
	glVertex3f(16.0, -60.0, 0.0);
	glVertex3f(16.0, 75.0, 0.0);
	glVertex3f(48.0, -60.0, 0.0);
	glVertex3f(48.0, 75.0, 0.0);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
	glVertex3f(-16.0, -17.0, 0.0);
	glVertex3f(16.0, -17.0, 0.0);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-85.0, 80.0, 0.0);
	glVertex3f(-80.0, 75.0, 0.0);
	glVertex3f(-80.0, -60.0, 0.0);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-85.0, -10.0, 0.0);
	glVertex3f(-80.0, -15.0, 0.0);
	glVertex3f(80.0, -15.0, 0.0);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-85.0, 35.0, 0.0);
	glVertex3f(-80.0, 30.0, 0.0);
	glVertex3f(80.0, 30.0, 0.0);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(75.0, 80.0, 0.0);
	glVertex3f(80.0, 75.0, 0.0);
	glVertex3f(80.0, -60.0, 0.0);
	glEnd();

	glLineWidth(20);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-85.0, -55.0, 0.0);
	glVertex3f(-80.0, -60.0, 0.0);
	glVertex3f(-15.0, -60.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(15.25, -60.0, 0.0);
	glVertex3f(81.0, -60.0, 0.0);
	glEnd();

	//main door

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-12.0, -60.0, 0.0);
	glVertex3f(-12.0, -24.0, 0.0);
	glVertex3f(12.0, -24.0, 0.0);
	glVertex3f(12.0, -60.0, 0.0);


	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-11.5, -38.0, 0.0);
	glVertex3f(-11.5, -25.0, 0.0);
	glVertex3f(4.0, -25.0, 0.0);
	glVertex3f(4.0, -38.0, 0.0);


	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(4.5, -59.0, 0.0);
	glVertex3f(4.5, -25.0, 0.0);
	glVertex3f(11.5, -25.0, 0.0);
	glVertex3f(-11.5, -59.0, 0.0);

	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-11.5, -59.0, 0.0);
	glVertex3f(-11.5, -38.5, 0.0);
	glVertex3f(4.0, -38.5, 0.0);
	glVertex3f(4.0, -59.0, 0.0);

	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(4.0, 0.0, 0.0);
	glVertex3f(4.0, 26.0, 0.0);
	glVertex3f(12.0, 26.0, 0.0);
	glVertex3f(12.0, 0.0, 0.0);

	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(4.5, 0.5, 0.0);
	glVertex3f(4.5, 25.5, 0.0);
	glVertex3f(11.5, 25.5, 0.0);
	glVertex3f(11.5, 0.5, 0.0);

	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-10.0, 10.0, 0.0);
	glVertex3f(-10.0, 26.0, 0.0);
	glVertex3f(3.0, 26.0, 0.0);
	glVertex3f(3.0, 10.0, 0.0);

	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-9.5, 10.5, 0.0);
	glVertex3f(-9.5, 25.5, 0.0);
	glVertex3f(2.5, 25.5, 0.0);
	glVertex3f(2.5, 10.5, 0.0);

	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(4.0, 45.0, 0.0);
	glVertex3f(4.0, 71.0, 0.0);
	glVertex3f(12.0, 71.0, 0.0);
	glVertex3f(12.0, 45.0, 0.0);

	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(4.5, 45.5, 0.0);
	glVertex3f(4.5, 70.5, 0.0);
	glVertex3f(11.5, 70.5, 0.0);
	glVertex3f(11.5, 45.5, 0.0);

	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-10.0, 55.0, 0.0);
	glVertex3f(-10.0, 71.0, 0.0);
	glVertex3f(3.0, 71.0, 0.0);
	glVertex3f(3.0, 55.0, 0.0);

	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-9.5, 55.5, 0.0);
	glVertex3f(-9.5, 70.5, 0.0);
	glVertex3f(2.5, 70.5, 0.0);
	glVertex3f(2.5, 55.5, 0.0);
	glEnd();

	//Road

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-125.0, -1250.0, 0.0);
	glVertex3f(-125.0, -74.0, 0.0);
	glVertex3f(125.0, -74.0, 0.0);
	glVertex3f(125.0, -125.0, 0.0);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.8, 0.8);
	glVertex3f(-125.0, -98.0, 0.0);
	glVertex3f(125.0, -98.0, 0.0);
	glVertex3f(-125.0, -74.0, 0.0);
	glVertex3f(125.0, -74.0, 0.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.0, 45.0, 0.0);
	glVertex3f(16.0, 45.0, 0.0);
	glVertex3f(-16.0, 0.0, 0.0);
	glVertex3f(16.0, 0.0, 0.0);
	glEnd();

	//ROAD INNER BROCKEN LINE

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(5, 0x0f0f);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-125.0, -100.0, 0.0);
	glVertex3f(125.0, -100.0, 0.0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	//character writing

	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2i(-8, -18);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');	
}

void treebody(float x, float y)
{
	glBegin(GL_QUADS);
	glVertex2f(x + 1.0, 21.0);
	glVertex2f(x + 5.0, 21.0);
	glVertex2f(x + 3.5, y + 71.0);
	glVertex2f(x + 2.5, y + 71.0);
	glEnd();
	glLineWidth(0.7);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 1.0, 21.0);
	glVertex2f(x + 5.0, 21.0);
	glVertex2f(x + 3.5, y + 71.0);
	glVertex2f(x + 2.5, y + 71.0);
	glEnd();
}

void christmastree()
{
	glColor3f(0.545, 0.27, 0.074);
	treebody(0.0, -25.0);
	glColor3f(0.302, 0.72, 0.227);
	glBegin(GL_POLYGON);
	glVertex2f(2.95, 61.0);
	glVertex2f(7.95, 46.0);
	glVertex2f(5.95, 46.0);
	glVertex2f(7.95, 42.0);
	glVertex2f(5.95, 42.0);
	glVertex2f(7.95, 38.0);
	glVertex2f(5.95, 38.0);
	glVertex2f(7.95, 34.0);
	glVertex2f(5.95, 34.0);
	glVertex2f(7.95, 30.0);
	glVertex2f(-2.05, 30.0);
	glVertex2f(-0.05, 34.0);
	glVertex2f(-2.05, 34.0);
	glVertex2f(-0.05, 38.0);
	glVertex2f(-2.05, 38.0);
	glVertex2f(-0.05, 42.0);
	glVertex2f(-2.05, 42.0);
	glVertex2f(-0.05, 46.0);
	glVertex2f(-2.05, 46.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_LOOP);

	glVertex2f(2.95, 61.0);
	glVertex2f(7.95, 46.0);
	glVertex2f(5.95, 46.0);
	glVertex2f(7.95, 42.0);
	glVertex2f(5.95, 42.0);
	glVertex2f(7.95, 38.0);
	glVertex2f(5.95, 38.0);
	glVertex2f(7.95, 34.0);
	glVertex2f(5.95, 34.0);
	glVertex2f(7.95, 30.0);
	glVertex2f(-2.05, 30.0);
	glVertex2f(-0.05, 34.0);
	glVertex2f(-2.05, 34.0);
	glVertex2f(-0.05, 38.0);
	glVertex2f(-2.05, 38.0);
	glVertex2f(-0.05, 42.0);
	glVertex2f(-2.05, 42.0);
	glVertex2f(-0.05, 46.0);
	glVertex2f(-2.05, 46.0);
	glEnd();
}

void interior()
{
	glBegin(GL_QUADS);
	//Front Wall
	glColor3f(0.917647, 0.678431, 0.917647);
	glVertex3f(80.0, -125.0, 30);
	glVertex3f(125.0, -125.0, 30);
	glVertex3f(125.0, 125.0, 30);
	glVertex3f(80.0, 125.0, 30);

	//Front Wall Door
	glColor3f(0.90, 0.91, 0.98);
	glVertex3f(95.0, -125.0, 30);
	glVertex3f(150.0, -125.0, 30);
	glVertex3f(150.0, 50.0, 30);
	glVertex3f(95.0, 50.0, 30);

	//Right Wall
	glColor3f(0.917647, 0.678431, 0.917647);
	glVertex3f(80.0, -125.0, 30);
	glVertex3f(80.0, 125.0, 30);
	glVertex3f(40.0, 125.0, -50);
	glVertex3f(40.0, -20.0, -50);

	//depth wall
	glColor3f(0.917647, 0.678431, 0.917647);
	glVertex3f(40.0, 125.0, -50);
	glVertex3f(40.0, -20.0, -50);
	glVertex3f(-50.0, -20.0, -50);
	glVertex3f(-50.0, 125.0, -50);

	//left wall
	glColor3f(0.917647, 0.678431, 0.917647);
	glVertex3f(-125.0, 125.0, 30);
	glVertex3f(-50.0, 125.0, -50);
	glVertex3f(-50.0, -20.0, -50);
	glVertex3f(-125.0, -125.0, 30);

	//left wall door 1
	glColor3f(0.90, 0.91, 0.98);
	glVertex3f(-90.0, -77.142, 15);
	glVertex3f(-90.0, 22.86, 15);
	glVertex3f(-100.0, 9.58, 20);
	glVertex3f(-100.0, -91.42, 20);

	//left wall door 2
	glColor3f(0.90, 0.91, 0.98);
	glVertex3f(-59.0, -33.06, 5);
	glVertex3f(-59.0, 54.94, 5);
	glVertex3f(-65.0, 47.58, 10);
	glVertex3f(-65.0, -41.42, 10);
	//depth wall door
	glColor3f(0.90, 0.91, 0.98);
	glVertex3f(10.0, 60.0, -50);
	glVertex3f(10.0, -20.0, -50);
	glVertex3f(-15.0, -20.0, -50);
	glVertex3f(-15.0, 60.0, -50);
	//board
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 75.0, -50);
	glVertex3f(20.0, 85.0, -50);
	glVertex3f(-25.0, 85.0, -50);
	glVertex3f(-25.0, 75.0, -50);

	//knob
	glColor3f(0.2, 0.55, 0.55);
	glVertex3f(7.0, 15.0, -50);
	glVertex3f(7.0, 10.0, -50);
	glVertex3f(8.0, 10.0, -50);
	glVertex3f(8.0, 15.0, -50);
	glEnd();

	//detailing
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(0.5);
	glBegin(GL_LINES);
	glVertex3f(80.0, -125.0, 30);
	glVertex3f(125.0, -125.0, 30);
	glVertex3f(125.0, 125.0, 30);
	glVertex3f(80.0, 125.0, 30);

	//Front Wall Door
	glVertex3f(95.0, -125.0, 30);
	glVertex3f(150.0, -125.0, 30);
	glVertex3f(150.0, 50.0, 30);
	glVertex3f(95.0, 50.0, 30);

	//Right Wall
	glVertex3f(80.0, -125.0, 30);
	glVertex3f(80.0, 125.0, 30);
	glVertex3f(40.0, 125.0, -50);
	glVertex3f(40.0, -20.0, -50);

	//depth wall
	glVertex3f(40.0, 125.0, -50);
	glVertex3f(40.0, -20.0, -50);
	glVertex3f(-50.0, -20.0, -50);
	glVertex3f(-50.0, 125.0, -50);

	//left wall
	glVertex3f(-125.0, 125.0, 30);
	glVertex3f(-50.0, 125.0, -50);
	glVertex3f(-50.0, -20.0, -50);
	glVertex3f(-125.0, -125.0, 30);

	//left wall door 1
	glVertex3f(-90.0, -77.142, 15);
	glVertex3f(-90.0, 22.86, 15);
	glVertex3f(-100.0, 9.58, 20);
	glVertex3f(-100.0, -91.42, 20);

	//left wall door 2
	glVertex3f(-59.0, -33.06, 5);
	glVertex3f(-59.0, 54.94, 5);
	glVertex3f(-65.0, 47.58, 10);
	glVertex3f(-65.0, -41.42, 10);
	//depth wall door
	glVertex3f(10.0, 60.0, -50);
	glVertex3f(10.0, -20.0, -50);
	glVertex3f(-15.0, -20.0, -50);
	glVertex3f(-15.0, 60.0, -50);
	//board
	glVertex3f(20.0, 75.0, -50);
	glVertex3f(20.0, 85.0, -50);
	glVertex3f(-25.0, 85.0, -50);
	glVertex3f(-25.0, 75.0, -50);

	//knob
	glVertex3f(7.0, 15.0, -50);
	glVertex3f(7.0, 10.0, -50);
	glVertex3f(8.0, 10.0, -50);
	glVertex3f(8.0, 15.0, -50);
	glEnd();
}
void human()
{
	glPushMatrix();
	glTranslated(65,-65,0);
	glScaled(3.5, 3.5, 0.0);
	glColor3f(0.0,0.0,0.0);
	circle(1.0,0.35,1.25);

	//head
	glBegin(GL_QUADS);
	glColor3f(1.0,0.88,0.77);
	glVertex2f(0.0,0.5);
	glVertex2f(2.0, 0.5);
	glVertex2f(2.0, -2.5);
	glVertex2f(0.0, -2.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(2.0, 0.5);
	glVertex2f(2.0, -2.5);
	glVertex2f(0.0, -2.5);
	glEnd();

	//Eyes, nose and mouth
	glColor3f(1.0, 1.0, 1.0);
	circle(0.5, -0.30, 0.30);
	circle(1.5, -0.30, 0.30);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glPointSize(2.25);
	glVertex2f(0.5, -0.30);
	glVertex2f(1.5, -0.30);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	glVertex2f(1.0, -0.63);
	glVertex2f(0.45, -1.25);
	glVertex2f(1.0, -1.25);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.35, -1.65);
	glVertex2f(1.2, -1.65);
	
	glEnd();


	//Neck
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.88, 0.77);
	glVertex2f(0.55, -2.5);
	glVertex2f(1.45, -2.5);
	glVertex2f(1.45, -3.0);
	glVertex2f(0.55, -3.0);
	glColor3f(0.0,0.0,1.0);
	glEnd(); 
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.55, -2.5);
	glVertex2f(1.45, -2.5);
	glVertex2f(1.45, -3.0);
	glVertex2f(0.55, -3.0);
	glEnd();

	//Body
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-1.0, -3.0);
	glVertex2f(3.0, -3.0);
	glVertex2f(3.0, -11.0);
	glVertex2f(-1.0, -11.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-1.0, -3.0);
	glVertex2f(3.0, -3.0);
	glVertex2f(3.0, -11.0);
	glVertex2f(-1.0, -11.0);
	glEnd();

	//Hand
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(1.0, -4.0);
	glVertex2f(2.0, -4.5);
	glVertex2f(0.0, -9.5);
	glVertex2f(-1.0, -9.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(1.0, -4.0);
	glVertex2f(2.0, -4.5);
	glVertex2f(0.0, -9.5);
	glVertex2f(-1.0, -9.0);
	glEnd();
	//palm
	glColor3f(1.0, 0.88, 0.77);
	circle(-0.25,-8.7,0.8);
	glPopMatrix();
}

void legs1()
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.0, -10.0);
	glVertex2f(1.0, -10.5);
	glVertex2f(-1.0, -16.25);
	glVertex2f(-2.0, -15.75);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.0, -10.0);
	glVertex2f(1.0, -10.5);
	glVertex2f(-1.0, -16.25);
	glVertex2f(-2.0, -15.75);
	glEnd();
	//Shoe1
	glColor3f(0.0, 0.0, 0.0);
	circle(-1.8, -16.0, 0.9);
}
void legs2()
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(2.0, -10.0);
	glVertex2f(1.0, -10.5);
	glVertex2f(1.5, -16.0);
	glVertex2f(2.5, -16.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(2.0, -10.0);
	glVertex2f(1.0, -10.5);
	glVertex2f(1.5, -16.0);
	glVertex2f(2.5, -16.0);
	glEnd();
	//shoe2
	glColor3f(0.0, 0.0, 0.0);
	circle(1.5, -16.0, 0.9);
}
void frown()
{
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glTranslated(65, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0.35, -1.65);
	glVertex2f(0.20, -1.70);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.2, -1.65);
	glVertex2f(1.35, -1.70);
	glPopMatrix();
	glEnd();
}
void smile()
{
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glTranslated(65, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0.35, -1.65);
	glVertex2f(0.20, -1.50);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.2, -1.65);
	glVertex2f(1.35, -1.50);
	glPopMatrix();
	glEnd();
}
void nurse()
{
	glPushMatrix();
	glTranslated(-5,25,0);
	glScaled(2.5,2.5,0);
	glColor3f(0.0,0.0,0.0);
	circle(1.0, 0.15, 1.25);
	circle(0.2, 0.0, 1.25);
	circle(1.8, 0.0, 1.25);
	//cap
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,2.0);
	glVertex2f(1.0,1.5);
	glVertex2f(2.0,2.0);
	glVertex2f(2.0,0.0);
	glEnd();
	//head
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.88, 0.77);
	glVertex2f(0.0, 0.5);
	glVertex2f(2.0, 0.5);
	glVertex2f(2.0, -2.5);
	glVertex2f(0.0, -2.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(2.0, 0.5);
	glVertex2f(2.0, -2.5);
	glVertex2f(0.0, -2.5);
	glEnd();

	//Eyes, nose and mouth
	glColor3f(1.0, 1.0, 1.0);
	circle(0.5, -0.30, 0.30);
	circle(1.5, -0.30, 0.30);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glPointSize(2.25);
	glVertex2f(0.5, -0.30);
	glVertex2f(1.5, -0.30);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(0.2,-1.1);
	glVertex2f(1.8, -1.1);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	glVertex2f(1.0, -0.63);
	glVertex2f(0.45, -1.25);
	glVertex2f(1.0, -1.25);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.35, -1.65);
	glVertex2f(1.2, -1.65);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.35, -1.65);
	glVertex2f(0.20, -1.50);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.2, -1.65);
	glVertex2f(1.35, -1.50);
	glEnd();
	//Neck
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.88, 0.77);
	glVertex2f(0.55, -2.5);
	glVertex2f(1.45, -2.5);
	glVertex2f(1.45, -3.0);
	glVertex2f(0.55, -3.0);
	glColor3f(0.0, 0.0, 1.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.55, -2.5);
	glVertex2f(1.45, -2.5);
	glVertex2f(1.45, -3.0);
	glVertex2f(0.55, -3.0);
	glEnd();

	//Body
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-1.0, -3.0);
	glVertex2f(3.0, -3.0);
	glVertex2f(3.0, -11.0);
	glVertex2f(-1.0, -11.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-1.0, -3.0);
	glVertex2f(3.0, -3.0);
	glVertex2f(3.0, -11.0);
	glVertex2f(-1.0, -11.0);
	glEnd();
	//palms
	glColor3f(1.0, 0.88, 0.77);
	circle(-1.5, -8.5, 0.8);
	circle(3.5, -8.5, 0.8);
	//hands
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-2.0, -3.0);
	glVertex2f(-1.0, -3.0);
	glVertex2f(-1.0, -8.0);
	glVertex2f(-2.0, -8.0);

	glVertex2f(3.0, -3.0);
	glVertex2f(4.0, -3.0);
	glVertex2f(4.0, -8.0);
	glVertex2f(3.0, -8.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-2.0, -3.0);
	glVertex2f(-1.0, -3.0);
	glVertex2f(-1.0, -8.0);
	glVertex2f(-2.0, -8.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(3.0, -3.0);
	glVertex2f(4.0, -3.0);
	glVertex2f(4.0, -8.0);
	glVertex2f(3.0, -8.0);
	glEnd();
	//scirt
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(-1.0, -11.0);
	glVertex2f(3.0, -11.0);
	glVertex2f(5.0, -15.0);
	glVertex2f(-3.0, -15.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-1.0, -11.0);
	glVertex2f(3.0, -11.0);
	glVertex2f(5.0, -15.0);
	glVertex2f(-3.0, -15.0);
	glEnd();
	//legs
	glColor3f(1.0, 0.88, 0.77);
	glBegin(GL_QUADS);
	glVertex2f(-0.5, -15.0);
	glVertex2f(0.5, -15.0);
	glVertex2f(0.5, -18.0);
	glVertex2f(-0.5, -18.0);

	glVertex2f(1.5, -15.0);
	glVertex2f(2.5, -15.0);
	glVertex2f(2.5, -18.0);
	glVertex2f(1.5, -18.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.5, -15.0);
	glVertex2f(0.5, -15.0);
	glVertex2f(0.5, -18.0);
	glVertex2f(-0.5, -18.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(1.5, -15.0);
	glVertex2f(2.5, -15.0);
	glVertex2f(2.5, -18.0);
	glVertex2f(1.5, -18.0);
	glEnd();
	//shoes
	glColor3f(0.0,0.0,0.0);
	circle(-0.75,-18.0,0.9);
	circle(2.75, -18.0,0.9);

	glPopMatrix();
}
void frnd()
{
	glPushMatrix();
	glTranslated(90, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	circle(1.0, 0.35, 1.25);

	//head
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.88, 0.77);
	glVertex2f(0.0, 0.5);
	glVertex2f(2.0, 0.5);
	glVertex2f(2.0, -2.5);
	glVertex2f(0.0, -2.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(2.0, 0.5);
	glVertex2f(2.0, -2.5);
	glVertex2f(0.0, -2.5);
	glEnd();

	//Eyes, nose and mouth
	glColor3f(1.0, 1.0, 1.0);
	circle(0.5, -0.30, 0.30);
	circle(1.5, -0.30, 0.30);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glPointSize(2.25);
	glVertex2f(0.5, -0.30);
	glVertex2f(1.5, -0.30);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	glVertex2f(1.0, -0.63);
	glVertex2f(0.45, -1.25);
	glVertex2f(1.0, -1.25);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.35, -1.65);
	glVertex2f(1.2, -1.65);

	glEnd();


	//Neck
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.88, 0.77);
	glVertex2f(0.55, -2.5);
	glVertex2f(1.45, -2.5);
	glVertex2f(1.45, -3.0);
	glVertex2f(0.55, -3.0);
	glColor3f(0.0, 0.0, 1.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.55, -2.5);
	glVertex2f(1.45, -2.5);
	glVertex2f(1.45, -3.0);
	glVertex2f(0.55, -3.0);
	glEnd();

	//Body
	glBegin(GL_QUADS);
	glColor3f(0.2, 0.4, 0.7);
	glVertex2f(-1.0, -3.0);
	glVertex2f(3.0, -3.0);
	glVertex2f(3.0, -11.0);
	glVertex2f(-1.0, -11.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-1.0, -3.0);
	glVertex2f(3.0, -3.0);
	glVertex2f(3.0, -11.0);
	glVertex2f(-1.0, -11.0);
	glEnd();

	//Hand
	glBegin(GL_QUADS);
	glColor3f(0.2, 0.4, 0.7);
	glVertex2f(1.0, -4.0);
	glVertex2f(2.0, -4.5);
	glVertex2f(0.0, -9.5);
	glVertex2f(-1.0, -9.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(1.0, -4.0);
	glVertex2f(2.0, -4.5);
	glVertex2f(0.0, -9.5);
	glVertex2f(-1.0, -9.0);
	glEnd();
	//palm
	glColor3f(1.0, 0.88, 0.77);
	circle(-0.25, -8.7, 0.8);
	glPopMatrix();
}
void tile()
{
	glColor3f(0.90, 0.91, 0.98);
	for (int j=0;j<250;j=j+10)
	{
		glPushMatrix();
		glTranslated(0,j,-10);
		for (int i = 0; i < 250; i = i + 10)
		{
			glPushMatrix();
			glTranslated(i, 0, 0);
			glBegin(GL_POLYGON);
			glVertex2f(-125, -120);
			glVertex2f(-120, -115);
			glVertex2f(-115, -120);
			glVertex2f(-120, -125);
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
	}
}

void win1()
{
	glClearColor(0.1, 0.6, 0.9, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	hospital();
	//trees
	for(int i=1;i<=4;i++)
	{
		glPushMatrix();
		int a = -86 - (i * 9);
		glTranslated(a, -75, 0);
		christmastree();
		glPopMatrix();
	}

	for (int i = 1; i <= 4; i++)
	{
		glPushMatrix();
		int a = 77 + (i * 9);
		glTranslated(a, -75, 0);
		christmastree();
		glPopMatrix();
	}
	for (int i = 1; i <= 3; i++)
	{
		glPushMatrix();
		int a = -90.5 - (i * 9);
		glTranslated(a, -80, 0);
		christmastree();
		glPopMatrix();
	}

	for (int i = 1; i <= 3; i++)
	{
		glPushMatrix();
		int a = 81.5 + (i * 9);
		glTranslated(a, -80, 0);
		christmastree();
		glPopMatrix();
	}
	//sun
	glColor3f(1.0,1.0,0.0);
	circle(-105.0, 100.0, 10.0);
	glPushMatrix();
	glTranslated(-105, 100, 0);
	glRotated(-frameNumber * 0.7, 0, 0, 1);
	drawSun();
	glPopMatrix();
	//clouds
	glPushMatrix();
	glTranslated(145.0 - (frameNumber / 2) % 125, 0, 0);
	clouds(-60, 100);
	clouds(-130, 120);
	clouds(-120, 85);
	clouds(-75, 125);
	clouds(-90, 95);
	clouds(-20, 90);
	clouds(-40, 105);
	clouds(-100, 110);
	clouds(-160, 100);
	glPopMatrix();
	//car1
	glPushMatrix();
	glTranslated(-275+(frameNumber)%325, 0, 0);
	wheels();
	glColor3f(0.13, 0.42, 0.56);
	car();
	glPopMatrix();
	//car2
	glPushMatrix();
	glTranslated(+50 - (frameNumber) % 325, -20, 0);
	wheels();
	glColor3f(0.556863, 0.137255, 0.419608);
	car();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void win2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-125, 125, -125, 125, -50, 50);
	tile();
	interior();
	if (65 + 50 - (frameNumber1 / 2) % 325 >= -95 && temp2==0)
	{
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(-24, 78);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'G');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
		glPushMatrix();
		glTranslated(- (frameNumber1 / 2) % 325, 0, 0);
		glTranslated(64, -65, 0);
		glRotatef((frameNumber1) % 25, 370.25, -400.875, 50);
		glScaled(3.5, 3.5, 0.0);
		legs1();
		glPopMatrix();
		glPushMatrix();
		glTranslated(- (frameNumber1 / 2) % 325, 0, 0);
		glTranslated(66, -65, 0);
		glRotatef(-(frameNumber1) % 25, 370.25, -400.875, 50);
		glScaled(3.5, 3.5, 0.0);
		legs2();
		glPopMatrix();
		glPushMatrix();
		glTranslated(- (frameNumber1 / 2) % 325, 0, 0);
		human();
		glColor3f(1.0, 1.0, 1.0);
		circle(60, -65, 1);
		circle(57, -62, 1.5);
		circle(52, -57, 2);
		glPushMatrix();
		glScaled(1.5, 1.5, 0);
		clouds(19, -33);
		glPopMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(27, -48);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'H');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'P');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'E');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'B');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'Y');
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
		glScaled(-1,1,1);
		glTranslated(62, -65, 0);
		glScaled(3.5, 3.5, 0.0);
		legs1();
		glPopMatrix();
		glPushMatrix();
		glScaled(-1, 1, 1);
		glTranslated(66, -65, 0);
		glScaled(3.5, 3.5, 0.0);
		legs2();
		glPopMatrix();
		glPushMatrix();
		glScaled(-1, 1, 1);
		human();
		//dialog2
		glColor3f(1.0, 1.0, 1.0);
		circle(60, -65, 1);
		circle(57, -62, 1.5);
		circle(52, -57, 2);
		glPushMatrix();
		glScaled(1.5, 1.5, 0);
		clouds(19, -33);
		glPopMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(38, -48);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'H');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '.');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '.');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '.');
		glPopMatrix();
		temp2=1;
	}
	if(temp2==1)
	{ 
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(-24, 78);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
		nurse();
		//dialog1
		glColor3f(1.0, 1.0, 1.0);
		circle(2,32,1);
		circle(5, 35, 1.5);
		circle(10, 40, 2);
		glPushMatrix();
		glScaled(1.5, 1.5, 0);
		clouds(10,28);
		glPopMatrix();

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(16, 44);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'G');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'R');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'L');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '!');
		
	}
	glFlush();
}

void win3()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-125, 125, -125, 125, -50, 50);
	tile();
	interior();
	if (10+50 - (frameNumber2 / 2) % 325 >= 20 && temp3==0)
	{
		if (10 + 50 - (frameNumber2 / 2) % 325 <= 20)
			temp3 = 1;
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(-24, 78);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
		glPushMatrix();
		glTranslated(-(frameNumber2 / 2) % 325, 0, 0);
		glTranslated(89, -65, 0);
		glRotatef((frameNumber2) % 25, 370.25, -400.875, 50);
		glScaled(3.5, 3.5, 0.0);
		legs1();
		glPopMatrix();
		glPushMatrix();
		glTranslated(-(frameNumber2 / 2) % 325, 0, 0);
		glTranslated(91, -65, 0);
		glRotatef(-(frameNumber2) % 25, 370.25, -400.875, 50);
		glScaled(3.5, 3.5, 0.0);
		legs2();
		glPopMatrix();
		glPushMatrix();
		glTranslated(-(frameNumber2 / 2) % 325, 0, 0);
		frnd();
		glColor3f(1.0, 1.0, 1.0);
		circle(60, -65, 1);
		circle(57, -62, 1.5);
		circle(52, -57, 2);
		glPushMatrix();
		glTranslated(20,0,0);
		glPushMatrix();
		glScaled(1.5, 1.5, 0);
		clouds(19, -33);
		glPopMatrix();
		glPopMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(43, -48);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'C');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'N');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'G');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'R');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'M');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'Y');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'F');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'R');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'E');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'N');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'D');
		glPopMatrix();
		glPushMatrix();
		glScaled(-1, 1, 1);
		glTranslated(62, -65, 0);
		glScaled(3.5, 3.5, 0.0);
		legs1();
		glPopMatrix();
		glPushMatrix();
		glScaled(-1, 1, 1);
		glTranslated(66, -65, 0);
		glScaled(3.5, 3.5, 0.0);
		legs2();
		glPopMatrix();
		glPushMatrix();
		glScaled(-1, 1, 1);
		human();
		glPopMatrix();
	}
	else if(temp3==1)
	{
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(-24, 78);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	//human
	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(62, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	legs1();
	glPopMatrix();
	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(66, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	legs2();
	glPopMatrix();
	glPushMatrix();
	glScaled(-1, 1, 1);
	human();

	//dialog2
	glColor3f(1.0, 1.0, 1.0);
	circle(60, -65, 1);
	circle(57, -62, 1.5);
	circle(52, -57, 2);
	glPushMatrix();
	glScaled(1.5, 1.5, 0);
	clouds(19, -33);
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(47, -48);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '`');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'G');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'L');
	//friend
	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(34, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	legs1();
	glPopMatrix();
	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(36, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	legs2();
	glPopMatrix();
	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(-55,0,0);
	frnd();
	//dialog2
	glColor3f(1.0, 1.0, 1.0); 
	glPushMatrix();
	glTranslated(20, 0, 0);
	circle(60, -65, 1);
	circle(57, -62, 1.5);
	circle(52, -57, 2);
	glPushMatrix();
	glScaled(1.5, 1.5, 0);
	clouds(19, -33);
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(44, -48);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'W');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'H');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '?');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'D');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '`');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'R');
	glPopMatrix();
	glPopMatrix();
	}
	else if (temp3 == 2)
	{
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(-24, 78);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	//human
	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(62, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	legs1();
	glPopMatrix();
	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(66, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	legs2();
	glPopMatrix();
	glPushMatrix();
	glScaled(-1, 1, 1);
	human();

	//dialog2
	glColor3f(1.0, 1.0, 1.0);
	circle(60, -65, 1);
	circle(57, -62, 1.5);
	circle(52, -57, 2);
	glPushMatrix();
	glScaled(1.5, 1.5, 0);
	clouds(19, -33);
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(47, -48);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'V');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'Y');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'D');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'F');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'F');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	//friend
	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(34, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	legs1();
	glPopMatrix();
	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(36, -65, 0);
	glScaled(3.5, 3.5, 0.0);
	legs2();
	glPopMatrix();
	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(-55, 0, 0);
	frnd();
	//dialog2
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(20, 0, 0);
	circle(60, -65, 1);
	circle(57, -62, 1.5);
	circle(52, -57, 2);
	glPushMatrix();
	glScaled(1.5, 1.5, 0);
	clouds(19, -33);
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(44, -48);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'Y');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '.');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'H');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'K');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'H');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'G');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'V');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glPopMatrix();
	glPopMatrix();
	glutPostRedisplay();
	}
	glFlush();
}
void win4()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	setImage(0);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex2f(-125, -40);
	glTexCoord2f(0, 1);
	glVertex2f(-125, 125);
	glTexCoord2f(1, 1);
	glVertex2f(125, 125);
	glTexCoord2f(1, 0);
	glVertex2f(125, -40);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	drawText(-40, -60, 1, 0, 0.2, d, "PROJECT THEME: ");
	drawText(10, -60, 0.8, 0, 0.2, d, "GOVERNMENT POLICIES AND SCHEMES");
	drawText(-40, -80, 1, 0, 0.2, d, "PROJECT TITLE: ");
	drawText(10, -80, 0.8, 0, 0.2, d, "SUKANYA SAMRIDDHI YOJANA");
	drawText(-40, -100, 1, 0, 0.2, d, "PROJECT MEMBERS:");
	drawText(10, -100, 0.5, 0, 0.1, d, "S SHADHRUSH");
	drawText(10, -110, 0.5, 0, 0.1, d, "(1BI16CS124)");
	drawText(-40.0, -120.0, 1, 0, 0, d, "UNDER THE GUIDENCE OF:");
	drawText(10.0, -120.0, 0, 0, 0, d, "PROF.BHANUSHREE.K.J");
	drawText(10.0, -130.0, 0, 0, 0, d, "ASSISTANT PROFESSOR, DEPT. OF CSE");
	drawText(10.0, -140, 0, 0, 0, d, "BIT, BANGALORE");
}
void win5()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	setImage(1);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex2f(-125, -125);
	glTexCoord2f(0, 1);
	glVertex2f(-125, 125);
	glTexCoord2f(1, 1);
	glVertex2f(125, 125);
	glTexCoord2f(1, 0);
	glVertex2f(125, -125);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void menu(int num)
{
	if (num == 0)
	{
		glutDestroyWindow(window);
		exit(0);
	}
	else
	{
		value = num;
	}
}

void createMenu(void)
{
	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Front Pg", 4);
	glutAddMenuEntry("Scene1", 1);
	glutAddMenuEntry("Scene2", 2);
	glutAddMenuEntry("Scene3", 3);
	glutAddMenuEntry("Last Pg", 5);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Normalkey(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'n':
		temp3++;
		break;
	case 'b':
		temp3--;
		break;
	}
}
void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-125, 125, -125, 125, -50, 50);
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	/*setImage(0);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex2f(-125, -40);
	glTexCoord2f(0, 1);
	glVertex2f(-125, 125);
	glTexCoord2f(1, 1);
	glVertex2f(125, 125);
	glTexCoord2f(1, 0);
	glVertex2f(125, -40);
	glEnd();
	glDisable(GL_TEXTURE_2D);*/
	// drawText(500, 150, 0, 1, 0, d, "PRESS '1' TO START");
	switch (value)
	{
	case 1:
		if (speed == 0)
		{
			glutTimerFunc(2, doFrame, 1);
			speed+=1000;
		}
		init();
		win1();
		break;
	case 2:
		if (speed1 == 0)
		{
			glutTimerFunc(200, doFrame, 2);
			speed1++;
		}
		init();
		win2();
		break;
	case 3:
		if (speed2 == 0)
		{
			glutTimerFunc(200, doFrame, 3);
			speed2++;
		}
		init();
		win3();
		break;
	case 4:
		init();
		win4();
		break;
	case 5:
		init();
		win5();
	}

	glFlush();

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1380, 800);
	glutCreateWindow("Documentry");
	glutSetCursor(GLUT_CURSOR_CYCLE);
	init();
	glutDisplayFunc(display);
	createMenu();
	glutKeyboardFunc(Normalkey);
	glutFullScreen();
	glutMainLoop();
}
