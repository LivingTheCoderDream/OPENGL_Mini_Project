#include <iostream>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h> 

// Anikate Kumar

// Atharv Jaju


#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;



vector<string> left_bank = { "M1", "M2", "M3", "C1", "C2", "C3" };
vector<string> right_bank(6, "");
vector<string> boat(2, "");

#define Z_LENGTH 40
#define SCENE_CENTER_X 0.0
#define SCENE_CENTER_Y 0.0
#define SCENE_CENTER_Z -40.0

#define FACING_RIGHT_BANK 1.0
#define FACING_LEFT_BANK -1.0

double rot = 0.0;
double radius_sphere = 40.0; // Change it
double theta_y = 0.0;
double theta_z = 0.0;
double theta_x = 0.0;

double x_c = 0.0;
double y_c = 0.0;
double z_c = 0.0;

double up_x = 0.0;
double up_y = 0.0;
double up_z = 0.0;

void Boat(double px, double py, double pz)
{
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(58.8 / 100, 29.4 / 100, 0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(90.0, 1, 0, 0);
	glScalef(2.0, 1.0, 1.0);
	glutWireTorus(7.0, 20.0, 100.0, 100.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(58.8 / 100, 29.4 / 100, 0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X , SCENE_CENTER_Y - 7, SCENE_CENTER_Z);
	glScalef(2.0, 0.0, 1.0);
	glutWireSphere(20.0, 100.0, 100.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();
}

void Tree(double px, double py, double pz)
{
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(-90.0, 1, 0, 0);
	glutWireCone(30.0, 30.0, 8.0, 8.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(0.0, 10.0, 0.0);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(-90.0, 1, 0, 0);
	glutWireCone(27.0, 30.0, 8.0, 8.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(0.0, 20.0, 0.0);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(-90.0, 1, 0, 0);
	glutWireCone(24.0, 30.0, 8.0, 8.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(0.0, 30.0, 0.0);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(-90.0, 1, 0, 0);
	glutWireCone(21.0, 30.0, 8.0, 8.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(0.0, 40.0, 0.0);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(-90.0, 1, 0, 0);
	glutWireCone(18.0, 30.0, 8.0, 8.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(0.0, 50.0, 0.0);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(-90.0, 1, 0, 0);
	glutWireCone(15.0, 30.0, 8.0, 8.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(58.8 / 100, 29.4 / 100, 0);
	glTranslatef(px, py, pz);
	glTranslatef(0.0, -10.0, 0.0);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(-90.0, 1, 0, 0);
	glutWireCylinder(5.0, 40.0, 10, 10);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

}

void Bed(double px, double py, double pz)
{
	// Body
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(58.8 / 100, 29.4 /100, 0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glScalef(3*240.0, 40.0, Z_LENGTH);
	glutWireCube(1.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();
}

void Right_bank(double px, double py, double pz)
{
	// Body
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glScalef(240.0, 20.0, Z_LENGTH);
	glutWireCube(1.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();
}

void Left_bank(double px, double py, double pz)
{
	// Body
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glScalef(240.0, 20.0, Z_LENGTH);
	glutWireCube(1.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();
}

void River(double px, double py, double pz)
{
	// Body
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glScalef (240.0, 15.0, Z_LENGTH);
	glutSolidCube(1.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();
}

void Man(double px, double py, double pz, double facing_direction) {

	// Leg 2
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, -19.0, 0.0);
	glTranslatef(0.0, -(6.75 + 5.0), 1.7 * 3.375);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(-30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glutSolidCube(4.5);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	// Leg 1
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, -19.0, 0.0);
	glTranslatef(0.0, -(6.75 + 5.0), -3.375 * 1.7);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glutSolidCube(4.5);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	// Hand 2
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 0.0);
	//glTranslatef(-2.0, 0.0, 0.0);
	glTranslatef(0.0, -(6.75 + 5.0), 1.7 * 3.375);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	//glRotatef(-30.0, 0.0, 0.0, 1.0);
	glRotatef(-30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glutSolidCube(4.5);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	// Hand 1
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 0.0);
	//glTranslatef(2.0, 0.0, 0.0);
	glTranslatef(0.0, -(6.75 + 5.0), -3.375 * 1.7);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	//glRotatef(30.0, 0.0, 0.0, 1.0);
	glRotatef(30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glutSolidCube(4.5);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	// Body
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, -(10.50 + 5.0), 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glScalef(1.0, 3.0, 1.0);
	glutSolidCube(7.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	// Head
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glutWireSphere(5.0, 30.0, 30.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();
}

void Cannibal(double px, double py, double pz, double facing_direction) {

	// Leg 2
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, -19.0, 0.0);
	glTranslatef(0.0, -(6.75 + 5.0), 1.7 * 3.375);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(-30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glutSolidCube(4.5);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	// Leg 1
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, -19.0, 0.0);
	glTranslatef(0.0, -(6.75 + 5.0), -3.375 * 1.7);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glRotatef(30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glutSolidCube(4.5);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	// Hand 2
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 0.0);
	//glTranslatef(-2.0, 0.0, 0.0);
	glTranslatef(0.0, -(6.75 + 5.0), 1.7 * 3.375);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	//glRotatef(-30.0, 0.0, 0.0, 1.0);
	glRotatef(-30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glutSolidCube(4.5);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	// Hand 1
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 0.0);
	//glTranslatef(2.0, 0.0, 0.0);
	glTranslatef(0.0, -(6.75 + 5.0), -3.375 * 1.7);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	//glRotatef(30.0, 0.0, 0.0, 1.0);
	glRotatef(30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glutSolidCube(4.5);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	// Body
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, -(10.50 + 5.0), 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glScalef(1.0, 3.0, 1.0);
	glutSolidCube(7.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

	// Head
	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(px, py, pz);
	glTranslatef(SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z);
	glutWireSphere(5.0, 30.0, 30.0);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();
}

void drawScene(void)
{

	glColor3f(0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glLoadIdentity();
	if (rot == 0.0)
	{
		gluLookAt(0, 0, 0, SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z, 0.0, 1.0, 0.0);
	}

	if (rot == 1.0) {
		gluLookAt(x_c + SCENE_CENTER_X, y_c + SCENE_CENTER_Y, z_c + SCENE_CENTER_Z, SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z, up_x, up_y, up_z);
	}

	if (rot == 2.0) {
		gluLookAt(x_c + SCENE_CENTER_X, y_c + SCENE_CENTER_Y, z_c + SCENE_CENTER_Z, SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z, up_x, up_y, up_z);
	}

	if (rot == 3.0) {
		gluLookAt(x_c + SCENE_CENTER_X, y_c + SCENE_CENTER_Y, z_c + SCENE_CENTER_Z, SCENE_CENTER_X, SCENE_CENTER_Y, SCENE_CENTER_Z, 0.0, 1.0, 0.0);
	}

	
	River(0.0, -20.0, 0.0);
	Right_bank(240.0, -20.0 + 2.5, 0.0);
	Left_bank(-240.0, -20.0 + 2.5, 0.0);
	Bed(0.0, -20.0 - 27.5, 0.0);
	Tree(0, 0, 0);
	Man(0, 21, 0, 0);
	Boat(0.0, 0.0, 0.0);

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-10.0, 10.0, -10.0, 10.0, 5.0, 1000.0);

	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	if (key == 'x')
	{
		rot = 2.0;
		theta_x = theta_x - 2 * 3.14 / 180.0;

		x_c = 30.0 * sin(theta_x) * cos(theta_y);
		z_c = 30.0 * sin(theta_x) * sin(theta_y);
		y_c = 30.0 * cos(theta_x);

		up_x = cos(theta_x) * cos(theta_y);
		up_z = cos(theta_x) * sin(theta_y);
		up_y = -sin(theta_x);
		glutPostRedisplay();
		//printf("x");
	}
	if (key == 'y' || key == 's' || key == 'w')
	{
		if (key == 's') {
			rot = 1.0;
			radius_sphere = radius_sphere + 2.0;
			printf("s");
		}
		else if (key == 'w')
		{
			rot = 1.0;
			radius_sphere = radius_sphere - 2.0;
			printf("w");
		}
		else {
			rot = 1.0;
			theta_y = theta_y + 2 * 3.14 / 180.0;
		}

		x_c = radius_sphere * sin(theta_x) * cos(theta_y);
		z_c = radius_sphere * sin(theta_x) * sin(theta_y);
		y_c = radius_sphere * cos(theta_x);

		up_x = cos(theta_x) * cos(theta_y);
		up_z = cos(theta_x) * sin(theta_y);
		up_y = -sin(theta_x);
		glutPostRedisplay();
		//printf("y");
	}
	if (key == 'z' || key == 's' || key == 'w')
	{
		if (key == 's') {
			rot = 3.0;
			radius_sphere = radius_sphere + 2.0;
			printf("s");
		}
		else if (key == 'w')
		{
			rot = 3.0;
			radius_sphere = radius_sphere - 2.0;
			printf("w");
		}
		else {
			rot = 3.0;
			theta_z = theta_z + 2 * 3.14 / 180.0;
			//printf("z");
		}
		x_c = radius_sphere * sin(theta_z);
		y_c = 0.0;
		z_c = radius_sphere * cos(theta_z);
		glutPostRedisplay();

	}
	if (key == 'w')
	{
		radius_sphere = radius_sphere - 2.0;
		glutPostRedisplay();
	}

	if (key == 'M')
	{
		printf("M");
	}
	if (key == 'C')
	{
		printf("C");
	}
	if (key == 'B')
	{
		printf("B");
	}

	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{

	for (auto i : left_bank)
		cout << i << " ";

	cout << "\n";

	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1080, 1080);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("experimentRelativePlacement.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}