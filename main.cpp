
#include<cstdio>
#include<iostream>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>

using namespace std;

float x,y,i;
float PI=3.1416;

float counter1=0.0;


GLfloat position = 0.0f;
GLfloat speed = 0.001f;

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.00015f;

GLfloat position3 = 0.0f;
GLfloat speed3 = 0.0001f;


void update(int value)
{

    if(position > 2.5)
        position = 0.0f;

    position += speed;

    if(position < 0)
        position = 2.5f;

    position += speed;

    if(position2 >1.0)
        position2 =-1.0f;

    position2 += speed2;

    if(position2 <-1.0)
        position2 =1.0f;

    position2 += speed2;

    if(position3 >1.0)
        position3 =-1.0f;

    position3 += speed3;

    if(position3 <-1.0)
        position3 =1.0f;

    position3 += speed3;
glutPostRedisplay();


	glutTimerFunc(10, update, 0);
}
void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void sunset()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

//Weather//*******************************
    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(-1,1);
    glVertex2f(-0.5,1);
    glVertex2f(0,1);
    glVertex2f(0.5,1);
    glVertex2f(1,1);
    glVertex2f(1,0.5);
    glVertex2f(1,0);
    glVertex2f(1,-0.5);

    glColor3ub(255, 223, 130);
    glVertex2f(1,-1);
    glVertex2f(0.5,-1);
    glVertex2f(0,-1);
    glVertex2f(-0.5,-1);
    glVertex2f(-1,-1);
    glVertex2f(-1,-0.5);
    glVertex2f(-1,0);
    glVertex2f(-1,0.5);
    glEnd();

//Stars//*******************************
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3ub(253, 254, 254);
     glVertex2f(-0.36f,0.43f);
    glVertex2f(-0.18f,0.44f);
    glVertex2f(-0.12f,0.51f);
    glVertex2f(0.34f,0.46f);
    glVertex2f(0.67f,0.46f);

    glVertex2f(0.13f,0.61f);
    glVertex2f(0.52f,0.75f);
    glVertex2f(0.2,0.8);
    glVertex2f(0.84f,0.70f);
    glVertex2f(-0.28f,0.73f);
    glVertex2f(-0.02f,0.90f);
    glVertex2f(0.38f,0.91f);
    glVertex2f(0.71f,0.88f);


    glVertex2f(-0.66f,0.63f);
    glVertex2f(-0.78f,0.74f);
    glVertex2f(-0.62f,0.41f);
    glVertex2f(-0.44f,0.66f);
    glVertex2f(-0.90f,0.76f);

    glVertex2f(0.13f,0.61f);
    glVertex2f(0.52f,0.75f);
    glVertex2f(0.4,0.9);
    glVertex2f(-0.89f,0.40f);
    glVertex2f(-0.28f,0.73f);
    glVertex2f(-0.02f,0.90f);
    glVertex2f(-0.45f,0.81f);
    glVertex2f(-0.71f,0.88f);
    glEnd();

//Moon//*******************************
    glPushMatrix();
    glTranslatef(position2,-position2,0);

    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount =40;
    GLfloat twicePi = 2.0 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=0.5;
    y=0.7;
    radius =0.1;
    twicePi = -1.5 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 175, 129);

    x=0.525;
    y=0.72;
    radius =0.1;
    twicePi = 2.0 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();


//Big Clouds//*******************************
     glBegin(GL_POLYGON);
    glColor3ub(255, 240, 214);
    glVertex2f(-1,0);
    glVertex2f(-1,0.34);
    glVertex2f(-0.975f,0.340f);
    glVertex2f(-0.951f,0.348f);
    glVertex2f(-0.9273f,0.366f);
    glVertex2f(-0.916f,0.335f);
    glVertex2f(-0.886f,0.309f);
    glVertex2f(-0.850f,0.297f);
    glVertex2f(-0.833f,0.292f);
    glVertex2f(-0.803f,0.273f);
    glVertex2f(-0.775f,0.232f);
    glVertex2f(-0.716f,0.237f);
    glVertex2f(-0.671f,0.209f);
    glVertex2f(-0.629f,0.151f);
    glVertex2f(-0.63,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 240, 214);
    glVertex2f(-0.63,0);
    glVertex2f(-0.629f,0.151f);
    glVertex2f(-0.420f,0.206f);
    glVertex2f(-0.391f,0.214f);
    glVertex2f(-0.39,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 240, 214);
    glVertex2f(-0.39,0);
    glVertex2f(-0.391f,0.214f);
    glVertex2f(-0.36,0.24);
    glVertex2f(-0.340f,0.262f);
    glVertex2f(-0.3,0.24);
    glVertex2f(-0.28,0.24);
    glVertex2f(-0.229f,0.233f);
    glVertex2f(0.42,0.22);
    glVertex2f(0.448f,0.209f);
    glVertex2f(0.45,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 240, 214);
    glVertex2f(0.45,0);
    glVertex2f(0.448f,0.209f);
    glVertex2f(0.4855f,0.229f);
    glVertex2f(0.52,0.24);
    glVertex2f(0.552f,0.243f);
    glVertex2f(0.584f,0.258f);
    glVertex2f(0.631f,0.273f);
    glVertex2f(0.7,0.28);
    glVertex2f(0.740f,0.292f);
    glVertex2f(0.74,0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 240, 214);
    glVertex2f(0.74,0);
    glVertex2f(0.740f,0.292f);
    glVertex2f(0.755f,0.327f);
    glVertex2f(0.772f,0.290f);
    glVertex2f(0.804f,0.273f);
    glVertex2f(0.833f,0.259f);
    glVertex2f(0.86,0.26);
    glVertex2f(0.88,0.26);
    glVertex2f(1,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.9757040231414;
    y=0.3406027243728;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.9273877659783;
    y=0.3661613243145;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.9161839962013;
    y=0.335701075069;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.8867741005368;
    y=0.3090921217051;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.85071196656728;
    y=0.2971881162528;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.8332060762907;
    y=0.2929867025638;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.8037961806261;
    y=0.2730299875408;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.7754366383782;
    y=0.2327664396876;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.7169669648547;
    y=0.2376680889914;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.6714178225042;
    y=0.2096303292507;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.4201291065783;
    y=0.2066569857006;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.3917621566006;
    y=0.2140279254984;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.36;
    y=0.24;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.3406123019165;
    y=0.262944162338;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.3;
    y=0.24;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.28;
    y=0.24;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=-0.2291757854668;
    y=0.2332287373813;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.42;
    y=0.22;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.4855824282033;
    y=0.229350055792;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.52;
    y=0.24;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.5524499056254;
    y=0.2436461219255;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.5847946751289;
    y=0.2581288546171;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.6310995352551;
    y=0.2739267779875;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.7;
    y=0.28;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.7402463341114;
    y=0.2926506343388;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.7558165910881;
    y=0.3276837127253;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.7728465596563;
    y=0.290217781673;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.8041473954174;
    y=0.2733771788998;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.8339701434758;
    y=0.2597348579059;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.86;
    y=0.26;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 240, 214);
    x=0.88;
    y=0.26;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();





//Back Mountain//*******************************
//Left Mountain
    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-1,0.06);
    glVertex2f(-0.755f,0.175f);
    glVertex2f(-0.738f,0.183f);
    glVertex2f(-0.717f,0.190f);
    glVertex2f(-0.696f,0.193f);
    glVertex2f(-0.639f,0.199f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-0.639f,0.199f);
    glVertex2f(-0.598f,0.211f);
    glVertex2f(-0.569f,0.223f);
    glVertex2f(-0.525f,0.241f);
    glEnd();




//Left Mountain Light Shadow
    glBegin(GL_QUADS);
    glColor3ub(255, 209, 173);
    glVertex2f(-0.3,0);
    glVertex2f(-1,0);
    glVertex2f(-0.676f,0.135f);
    glVertex2f(-0.501f,0.157f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 173);
    glVertex2f(-0.450f,0.203f);
    glVertex2f(-0.501f,0.157f);
    glVertex2f(-0.3,0);
    glVertex2f(-0.328f,0.176f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(-0.628f,0.200f);
    glVertex2f(-0.709f,0.187f);
    glVertex2f(-0.723f,0.176f);
    glVertex2f(-0.680f,0.163f);
    glVertex2f(-0.676f,0.135f);
    glVertex2f(-0.501f,0.157f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(-0.450f,0.203f);
    glVertex2f(-0.501f,0.157f);
    glVertex2f(-0.55,0.2);
    glVertex2f(-0.523f,0.216f);
    glVertex2f(-0.531f,0.229f);
    glVertex2f(-0.523f,0.240f);
    glEnd();
//Right Mountain
    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(1,0.06);
    glVertex2f(0.683f,0.06);
    glVertex2f(0.567f,0.118f);
    glVertex2f(0.464f,0.176f);
    glVertex2f(0.543f,0.212f);
    glVertex2f(0.569f,0.204f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(1,0.06);
    glVertex2f(0.569f,0.204f);
    glVertex2f(0.592f,0.218f);
    glVertex2f(0.623f,0.237f);
    glVertex2f(0.661f,0.264f);
    glVertex2f(0.688f,0.266f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 249, 233);
    glVertex2f(0.688f,0.266f);
    glVertex2f(0.724f,0.290f);
    glVertex2f(0.747f,0.257f);
    glVertex2f(0.772f,0.211f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(0.772f,0.211f);
    glVertex2f(0.747f,0.257f);
    glVertex2f(0.774f,0.238f);
    glVertex2f(0.807f,0.220f);
    glVertex2f(0.831f,0.205f);
    glVertex2f(1,0.06);
    glEnd();
//Right Mountain Light Shadow
    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(1,0);
    glVertex2f(0.5,0);
    glVertex2f(0.476f,0.172f);
    glVertex2f(0.502f,0.178f);
    glVertex2f(0.574f,0.187f);
    glVertex2f(0.683f,0.178f);
    glVertex2f(0.834f,0.203f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(0.683f,0.178f);
    glVertex2f(0.574f,0.187f);
    glVertex2f(0.553f,0.197f);
    glVertex2f(0.557f,0.200f);
    glVertex2f(0.542f,0.205f);
    glVertex2f(0.544f,0.210f);
    glVertex2f(0.566f,0.204f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(0.834f,0.203f);
    glVertex2f(0.683f,0.178f);
    glVertex2f(0.682f,0.187f);
    glVertex2f(0.663f,0.204f);
    glVertex2f(0.682f,0.232f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(0.834f,0.203f);
    glVertex2f(0.682f,0.232f);
    glVertex2f(0.682f,0.232f);
    glVertex2f(0.722f,0.233f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(0.834f,0.203f);
    glVertex2f(0.682f,0.232f);
    glVertex2f(0.771f,0.238f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(0.682f,0.232f);
    glVertex2f(0.657f,0.256f);
    glVertex2f(0.663f,0.264f);
    glVertex2f(0.689f,0.266f);
    glVertex2f(0.702f,0.251f);
    glVertex2f(0.713f,0.252f);
    glVertex2f(0.715f,0.244f);
    glVertex2f(0.722f,0.233f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(0.747f,0.256f);
    glVertex2f(0.771f,0.238f);
    glVertex2f(0.73,0.23);
    glVertex2f(0.728f,0.241f);
    glVertex2f(0.729f,0.248f);
    glVertex2f(0.723f,0.268f);
    glVertex2f(0.722f,0.281f);
    glVertex2f(0.725f,0.288f);
    glEnd();

//Tallest Mountain//*******************************
//Small Part
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 249, 233);
    glVertex2f(-0.566088631084, -0.1);
    glVertex2f(-1,-0.1);
    glVertex2f(-0.549f,0.062f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 249, 233);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-0.566f, -0.1);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-0.403f,0.134f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 249, 233);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-0.403f,0.134f);
    glVertex2f(-0.339f,0.178f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-0.339f,0.178f);
    glVertex2f(-0.277f,0.221f);
    glVertex2f(-0.261f,0.227f);
    glVertex2f(-0.243f,0.232f);
    glVertex2f(-0.228f,0.225f);
    glVertex2f(-0.213f,0.219f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 249, 233);
    glVertex2f(1,-0.1);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-0.213f,0.219f);
    glEnd();
//Medium Part
    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(-0.566088631084, -0.1);
    glVertex2f(1,-0.1);
    glVertex2f(-0.147f,0.299f);
    glEnd();
//Large Part
    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(0.35, -0.1);
    glVertex2f(0.010f,0.417f);
    glVertex2f(-0.012f,0.453f);
    glVertex2f(-0.073f,0.353f);
    glVertex2f(-0.129f,0.293f);
    glVertex2f(-0.147f,0.299f);
    glEnd();

//Largest Part
    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(0.5260591841453,-0.1);
    glVertex2f(0.35, -0.1);
    glVertex2f(0.0109402659646,0.4177046828709);
    glVertex2f(0.0910975259066,0.492842705702);
    glVertex2f(0.3347341480158,0.2904671244338);
    glVertex2f(0.4339571271813,0.1941913624713);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(1, -0.1);
    glVertex2f(0.35, -0.1);
    glVertex2f(0.334f,0.290f);
    glVertex2f(0.567f,0.118f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 249, 233);
    glVertex2f(1, -0.1);
    glVertex2f(0.35, -0.1);
    glVertex2f(0.334f,0.290f);
    glVertex2f(0.567f,0.118f);
    glEnd();
//Light Shadow
    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(-0.266f,0.225f);
    glVertex2f(-0.253f,0.230f);
    glVertex2f(-0.241f,0.229f);
    glVertex2f(-0.225f,0.223f);
    glVertex2f(-0.207f,0.217f);
    glVertex2f(-0.208f,0.158f);
    glVertex2f(-0.213f,0.111f);
    glVertex2f(-0.266f,0.126f);
    glVertex2f(-0.322f,0.116f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(-0.208f,0.158f);
    glVertex2f(-0.207f,0.217f);
    glVertex2f(-0.181f,0.217f);
    glVertex2f(-0.156f,0.210f);
    glVertex2f(-0.131f,0.204f);
    glVertex2f(-0.147f,0.162f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 173);
    glVertex2f(-0.147f,0.162f);
    glVertex2f(-0.131f,0.204f);
    glVertex2f(-0.036f,0.160f);
    glVertex2f(-0.085f,0.125f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(0.003f,0.244f);
    glVertex2f(-0.06,0.28);
    glVertex2f(-0.089f,0.281f);
    glVertex2f(-0.147f,0.298f);
    glVertex2f(-0.150f,0.287f);
    glVertex2f(-0.143f,0.276f);
    glVertex2f(-0.127f,0.260f);
    glVertex2f(-0.117f,0.233f);
    glVertex2f(-0.129f,0.219f);
    glVertex2f(-0.131f,0.204f);
    glVertex2f(-0.036f,0.160f);
    glVertex2f(-0.002f,0.136f);
    glVertex2f(0.007f,0.213f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(0.072f,0.251f);
    glVertex2f(0.054f,0.186f);
    glVertex2f(0.007f,0.213f);
    glVertex2f(0.003f,0.244f);
    glVertex2f(-0.006f,0.320f);
    glVertex2f(-0.013f,0.345f);
    glVertex2f(-0.027f,0.382f);
    glVertex2f(-0.026f,0.405f);
    glVertex2f(-0.015f,0.422f);
    glVertex2f(-0.010f,0.450f);
    glVertex2f(0.008f,0.419f);
    glVertex2f(0.039f,0.397f);
    glVertex2f(0.062f,0.395f);
    glVertex2f(0.081f,0.397f);
    glVertex2f(0.129f,0.368f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 209, 173);
    glVertex2f(0.072f,0.251f);
    glVertex2f(0.115f,0.225f);
    glVertex2f(0.114f,0.193f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 173);
    glVertex2f(0.072f,0.251f);
    glVertex2f(0.152f,0.252f);
    glVertex2f(0.171f,0.196f);
    glVertex2f(0.115f,0.225f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 209, 173);
    glVertex2f(0.152f,0.252f);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.237f,0.202f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 209, 173);
    glVertex2f(0.129f,0.368f);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.152f,0.252f);
    glVertex2f(0.072f,0.251f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 209, 173);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.307f,0.158f);
    glVertex2f(0.317f,0.200f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.331f,0.244f);
    glVertex2f(0.381f,0.200f);
    glVertex2f(0.365f,0.177f);
    glVertex2f(0.317f,0.200f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 173);
    glVertex2f(0.431f,0.235f);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.129f,0.368f);
    glVertex2f(0.096f,0.418f);
    glVertex2f(0.099f,0.447f);
    glVertex2f(0.089f,0.460f);
    glVertex2f(0.094f,0.475f);
    glVertex2f(0.091f,0.491f);
    glVertex2f(0.150f,0.444f);
    glEnd();
//Sun Light
    glBegin(GL_POLYGON);
    glColor3ub(255, 238, 194);
    glVertex2f(-0.386f,-0.110f);
    glVertex2f(-1,-0.1);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-0.416f,0.077f);
    glVertex2f(-0.361f,0.014f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 238, 194);
    glVertex2f(-0.416f,0.077f);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-0.497f,0.088f);
    glVertex2f(-0.477f,0.087f);
    glVertex2f(-0.413f,0.118f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 238, 194);
    glVertex2f(-0.354f,0.114f);
    glVertex2f(-0.341f,0.084f);
    glVertex2f(-0.361f,0.014f);
    glVertex2f(-0.416f,0.077f);
    glVertex2f(-0.354f,0.114f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 238, 194);
    glVertex2f(-0.341f,0.084f);
    glVertex2f(-0.354f,0.114f);
    glVertex2f(-0.311f,0.153f);
    glVertex2f(-0.322f,0.116f);
    glEnd();

//Dark Shadow

    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(-0.386f,-0.110f);
    glVertex2f(-0.361f,0.014f);
    glVertex2f(-0.341f,0.084f);
    glVertex2f(-0.322f,0.116f);
    glVertex2f(-0.266f,0.126f);
    glVertex2f(-0.213f,0.111f);
    glVertex2f(0.106f, -0.064f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(0.106f, -0.064f);
    glVertex2f(-0.213f,0.111f);
    glVertex2f(-0.208f,0.158f);
    glVertex2f(-0.147f,0.162f);
    glVertex2f(-0.085f,0.125f);
    glVertex2f(0.021f,-0.043f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(0.021f,-0.043f);
    glVertex2f(-0.085f,0.125f);
    glVertex2f(-0.036f,0.160f);
    glVertex2f(-0.002f,0.136f);
    glVertex2f(0.125f,-0.086f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(0.125f,-0.086f);
    glVertex2f(-0.002f,0.136f);
    glVertex2f(0.007f,0.213f);
    glVertex2f(0.054f,0.186f);
    glVertex2f(0.231f,-0.077f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(0.231f,-0.077f);
    glVertex2f(0.054f,0.186f);
    glVertex2f(0.072f,0.251f);
    glVertex2f(0.114f,0.193f);
    glVertex2f(0.310f,-0.058f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(0.310f,-0.058f);
    glVertex2f(0.114f,0.193f);
    glVertex2f(0.115f,0.225f);
    glVertex2f(0.171f,0.196f);
    glVertex2f(0.399f,-0.052f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(0.399f,-0.052f);
    glVertex2f(0.171f,0.196f);
    glVertex2f(0.152f,0.252f);
    glVertex2f(0.237f,0.202f);
    glVertex2f(0.512f,-0.034f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 175, 129);
    glVertex2f(0.512f,-0.034f);
    glVertex2f(0.237f,0.202f);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.307f,0.158f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(0.512f,-0.034f);
    glVertex2f(0.307f,0.158f);
    glVertex2f(0.317f,0.200f);
    glVertex2f(0.365f,0.177f);
    glVertex2f(0.613f,-0.015f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 175, 129);
    glVertex2f(0.613f,-0.015f);;
    glVertex2f(0.365f,0.177f);
    glVertex2f(0.381f,0.200f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(0.613f,-0.015f);
    glVertex2f(0.381f,0.200f);
    glVertex2f(0.331f,0.244f);
    glVertex2f(0.431f,0.235f);
    glVertex2f(0.497f,0.193f);
    glVertex2f(1,0);
    glEnd();



//Mountain Forests//*******************************
//4th Forest
     glBegin(GL_POLYGON);
    glColor3ub(67, 103, 126);
    glVertex2f(-0.05,-1);
    glVertex2f(-0.049f,-0.060f);
    glVertex2f(0.200f,-0.020f);
    glVertex2f(0.442f,0.079f);
    glVertex2f(0.532f,0.093f);
    glVertex2f(0.587f,0.127f);
    glVertex2f(0.728f,0.135f);
    glVertex2f(0.825f,0.193f);
    glVertex2f(0.888f,0.271f);
    glVertex2f(0.95,0.3);
    glVertex2f(1,0.35);
    glVertex2f(1,-1);
    glEnd();
//3rd Forest
    glBegin(GL_POLYGON);
    glColor3ub(76, 100, 115);
    glVertex2f(0.520f,-0.023f);
    glVertex2f(0.687f,0.048f);
    glVertex2f(0.792f,0.051f);
    glVertex2f(0.898f,0.092f);
    glVertex2f(1,0.07);
    glVertex2f(1,-1);
    glVertex2f(0.68,-1);
    glEnd();


    //tower
glBegin(GL_LINES);
glColor3f(0,0,0);

glVertex2f( 0.9,-0.5 );
glVertex2f( 0.9,0.07 );
glEnd();


//towerlm
glBegin(GL_LINES);
glColor3f(0,0,0);

glVertex2f( 0.8,-0.5 );
glVertex2f( 0.9,0.07 );
glEnd();


//towerrm
glBegin(GL_LINES);
glColor3f(0,0,0);

glVertex2f( 1,-0.5 );
glVertex2f( 0.9,0.07 );
glEnd();



glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    x=0.9;
    y=0.07;
    radius =0.005;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();








//2rd Forest
    glBegin(GL_POLYGON);
    glColor3ub(36, 83, 115);
    glVertex2f(0.057f,-0.120f);
    glVertex2f(0.057f,-0.120f);
    glVertex2f(0.520f,-0.023f);
    glVertex2f(0.718f,-0.043f);
    glVertex2f(0.869f,-0.049f);
    glVertex2f(1,-0.04);
    glVertex2f(1,-1);
    glVertex2f(0.42,-1);
    glVertex2f(-0.05,-1);
    glEnd();
//1st Forest
    glBegin(GL_POLYGON);


    glVertex2f(-1,-1);
     glColor3ub(27, 64, 89);
    glVertex2f(-1,0.3);

    glVertex2f(-0.981f,0.320f);
    glVertex2f(-0.849f,0.207f);
    glVertex2f(-0.832f,0.164f);

    glVertex2f(-0.835,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.832f,0.164f);
    glVertex2f(-0.660f,0.113f);
    glVertex2f(-0.6,0.1);
    glVertex2f(-0.582f,0.076f);
    glVertex2f(-0.585,-1);
    glVertex2f(-0.835,-1);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(-0.585,-1);
     glColor3ub(10, 48, 70);
    glVertex2f(-0.05,-1);
      glColor3ub(27, 64, 89);
    glVertex2f(-0.0495381320471,-0.0605962800007);

    glVertex2f(-0.2036190238643,-0.0653130419951);

    glVertex2f(-0.5154958923208,0.0441953783772);

    glVertex2f(-0.5824784481087,0.0763478604323);
    glEnd();



    //house1roof
    glBegin(GL_TRIANGLES);
    glColor3ub(76, 100, 115);
    glVertex2f(0.45f,-0.17);
    glVertex2f(0.50,-0.17);
    glVertex2f(0.475,-0.14);
    glEnd();

//house2roof
    glBegin(GL_TRIANGLES);
    glColor3ub(76, 100, 115);
    glVertex2f(0.45f,-0.20);
    glVertex2f(0.50,-0.17);
    glVertex2f(0.525,-0.14);
    glEnd();


    //house3
    glBegin(GL_QUADS);
    glColor3ub(127, 140, 141);
    glVertex2f(0.50,-0.22);
    glVertex2f(0.57f,-0.22);
    glVertex2f(0.57f,-0.16);
    glVertex2f(0.50,-0.16);
    glEnd();


     //house2
    glBegin(GL_QUADS);
    glColor3ub(127, 140, 141);
    glVertex2f(0.45,-0.20);
    glVertex2f(0.50f,-0.20);
    glVertex2f(0.50f,-0.17);
    glVertex2f(0.45,-0.17);
    glEnd();

    //house2windows
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.49,-0.20);
    glVertex2f(0.535f,-0.20);
    glVertex2f(0.535f,-0.18);
    glVertex2f(0.49,-0.18);
    glEnd();



     //house1
    glBegin(GL_QUADS);
    glColor3ub(127, 140, 141);
    glVertex2f(0.50,-0.25);
    glVertex2f(0.53f,-0.26);
    glVertex2f(0.53f,-0.15);
    glVertex2f(0.50,-0.15);
    glEnd();

//house1windows
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.465,-0.20);
    glVertex2f(0.485f,-0.20);
    glVertex2f(0.485f,-0.18);
    glVertex2f(0.465,-0.18);
    glEnd();



//house2windows
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.51,-0.20);
    glVertex2f(0.525f,-0.20);
    glVertex2f(0.525f,-0.18);
    glVertex2f(0.51,-0.18);
    glEnd();

//house1windows
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.475,-0.20);
    glVertex2f(0.485f,-0.20);
    glVertex2f(0.485f,-0.18);
    glVertex2f(0.475,-0.18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.05,-1);
    glVertex2f(0.42,-1);
    glVertex2f(0.414f,-0.191f);
    glVertex2f(0.244f,-0.132f);
    glVertex2f(0.074f,-0.114f);
    glVertex2f(-0.049f,-0.060f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.42,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.2);
    glVertex2f(0.825f,-0.204f);
    glVertex2f(0.585f,-0.212f);
    glVertex2f(0.414f,-0.191f);
    glEnd();





//Blue Lake//*******************************
    glBegin(GL_QUADS);
    glColor3ub(98, 167, 206);
    glVertex2f(1,-0.32);
    glVertex2f(-1,-0.32);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glEnd();


    //lighthouse.body
    glBegin(GL_QUADS);
    glColor3ub(105, 109, 110);
    glVertex2f(-0.325f,-0.90);
    glVertex2f(-0.23,-0.90);
    glColor3ub(204, 204, 204);
    glVertex2f(-0.24,-0.68);
    glVertex2f(-0.31f,-0.68);
    glEnd();

    //housewindows2
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.30,-0.80);
    glVertex2f(-0.29,-0.80);
    glVertex2f(-0.29,-0.78);
    glVertex2f(-0.30,-0.78);
    glEnd();
    //housewindows1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.26,-0.75);
    glVertex2f(-0.25,-0.75);
    glVertex2f(-0.25,-0.73);
    glVertex2f(-0.26,-0.73);
    glEnd();

    //housewindows1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.26,-0.85);
    glVertex2f(-0.25,-0.85);
    glVertex2f(-0.25,-0.83);
    glVertex2f(-0.26,-0.83);
    glEnd();

//lighthouse.line
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.34f,-0.70);
    glVertex2f(-0.21,-0.70);
    glVertex2f(-0.21,-0.69);
    glVertex2f(-0.34f,-0.69);
    glEnd();


    //lighthouse.box
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(-0.32f,-0.68);
    glVertex2f(-0.23,-0.68);
    glVertex2f(-0.23,-0.61);
    glVertex2f(-0.32f,-0.61);
    glEnd();


    //lines
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f( -0.32f,-0.68 );
glVertex2f( -0.23,-0.68 );
glEnd();



 //lines
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f( -0.23,-0.61 );
glVertex2f( -0.32f,-0.61 );
glEnd();

    //lighthouse.boxwindow
    glBegin(GL_QUADS);
    glColor3ub(203,242,237);
    glVertex2f(-0.31f,-0.67);
    glVertex2f(-0.24,-0.67);
    glVertex2f(-0.24,-0.62);
    glVertex2f(-0.31f,-0.62);
    glEnd();



    //lines
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f( -0.31f,-0.62 );
glVertex2f( -0.31f,-0.67 );
glEnd();

    //lines
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f( -0.24,-0.67 );
glVertex2f( -0.24,-0.62 );
glEnd();


    //lines
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f( -0.31f,-0.67 );
glVertex2f( -0.24,-0.67 );
glEnd();

  //lines
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f( -0.24,-0.62 );
glVertex2f( -0.31f,-0.62 );
glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(203,242,237);
    x=-0.275;
    y=-0.645;
    radius =0.023;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    //lighthouse.roof
    glBegin(GL_TRIANGLES);
    glColor3ub(55, 0, 0);
    glVertex2f(-0.335f,-0.61);
    glColor3ub(85,0,0);
    glVertex2f(-0.215,-0.61);
    glVertex2f(-0.275,-0.55);
    glEnd();


//Stone//*******************************
     glBegin(GL_QUADS);
    glColor3ub(87, 87, 86);
    glVertex2f(-0.354f,-0.906f);
    glVertex2f(-0.32,-0.88);
    glVertex2f(-0.279f,-0.888f);
    glVertex2f(-0.314f,-0.905f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(-0.314f,-0.905f);
    glVertex2f(-0.279f,-0.888f);
    glVertex2f(-0.227f,-0.878f);
    glVertex2f(-0.170f,-0.903f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(0.760f,-0.956f);
    glVertex2f(0.796f,-0.932f);
    glVertex2f(0.827f,-0.937f);
    glVertex2f(0.857f,-0.956f);
    glEnd();

//Train//*******************************
//Train Engine
    glPushMatrix();

    glTranslatef(-position,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.009f,-0.341f);
    glVertex2f(1.003f,-0.341f);
    glVertex2f(1.004f,-0.336f);
    glVertex2f(1.009f,-0.336f);
    glVertex2f(1.011f,-0.338f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 1, 1);
    glVertex2f(1.018f,-0.338f);
    glVertex2f(1.011f,-0.338f);
    glVertex2f(1.009f,-0.336f);
    glVertex2f(1.017f,-0.335f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 1, 1);
    glVertex2f(1.020f,-0.341f);
    glVertex2f(1.018f,-0.338f);
    glVertex2f(1.017f,-0.335f);
    glVertex2f(1.019f,-0.335f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.019f,-0.333f);
    glVertex2f(1.062f,-0.332f);
    glVertex2f(1.062f,-0.334f);
    glVertex2f(1.057f,-0.334f);
    glVertex2f(1.048f,-0.334f);
    glVertex2f(1.043f,-0.334f);
    glVertex2f(1.033f,-0.334f);
    glVertex2f(1.030f,-0.341f);
    glVertex2f(1.020f,-0.341f);
    glVertex2f(1.019f,-0.335f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 1, 1);
    glVertex2f(1.043f,-0.334f);
    glVertex2f(1.048f,-0.334f);
    glVertex2f(1.045f,-0.340f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 1, 1);
    glVertex2f(1.057f,-0.334f);
    glVertex2f(1.060f,-0.339f);
    glVertex2f(1.062f,-0.334f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.062f,-0.332f);
    glVertex2f(1.089f,-0.332f);
    glVertex2f(1.089f,-0.334f);
    glVertex2f(1.088f,-0.334f);
    glVertex2f(1.070f,-0.334f);
    glVertex2f(1.062f,-0.334f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.088f,-0.334f);
    glVertex2f(1.088f,-0.341f);
    glVertex2f(1.073f,-0.341f);
    glVertex2f(1.073f,-0.337f);
    glVertex2f(1.073f,-0.337f);
    glVertex2f(1.070f,-0.334f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.089f,-0.332f);
    glVertex2f(1.089f,-0.317f);
    glVertex2f(1.062f,-0.317f);
    glVertex2f(1.062f,-0.332f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.017f,-0.335f);
    glVertex2f(1.009f,-0.336f);
    glVertex2f(1.009f,-0.333f);
    glVertex2f(1.017f,-0.333f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.010f,-0.319f);
    glVertex2f(1.010f,-0.307f);
    glVertex2f(1.015f,-0.307f);
    glVertex2f(1.015f,-0.319f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(219, 162, 60);
    glVertex2f(1.015f,-0.307f);
    glVertex2f(1.010f,-0.307f);
    glVertex2f(1.010f,-0.306f);
    glVertex2f(1.015f,-0.306f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(219, 162, 60);
    glVertex2f(1.009f,-0.303f);
    glVertex2f(1.016f,-0.303f);
    glVertex2f(1.015f,-0.306f);
    glVertex2f(1.010f,-0.306f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.027f,-0.319f);
    glVertex2f(1.024f,-0.319f);
    glVertex2f(1.024f,-0.313f);
    glVertex2f(1.027f,-0.313f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.043f,-0.319f);
    glVertex2f(1.034f,-0.319f);
    glVertex2f(1.034f,-0.310f);
    glVertex2f(1.043f,-0.310f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.057f,-0.319f);
    glVertex2f(1.050f,-0.319f);
    glVertex2f(1.050f,-0.314f);
    glVertex2f(1.057f,-0.314f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.062f,-0.319f);
    glVertex2f(1.062f,-0.332f);
    glVertex2f(1.007f,-0.333f);
    glVertex2f(1.005f,-0.331f);

    glVertex2f(1.005f,-0.327f);
    glVertex2f(1.005f,-0.324f);
    glVertex2f(1.005f,-0.320f);
    glVertex2f(1.007f,-0.319f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.005f,-0.327f);
    glVertex2f(1.004f,-0.327f);
    glVertex2f(1.005,-0.325);
    glVertex2f(1.005f,-0.324f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.028f,-0.319f);
    glVertex2f(1.028f,-0.318f);
    glVertex2f(1.032f,-0.318f);
    glVertex2f(1.032f,-0.319f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.045f,-0.319f);
    glVertex2f(1.045f,-0.318f);
    glVertex2f(1.049f,-0.318f);
    glVertex2f(1.049f,-0.319f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(68, 66, 64);
    glVertex2f(1.084f,-0.317f);
    glVertex2f(1.062f,-0.317f);
    glVertex2f(1.062f,-0.306f);
    glVertex2f(1.084f,-0.306f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(68, 66, 64);
    glVertex2f(1.085f,-0.306f);
    glVertex2f(1.060f,-0.306f);
    glVertex2f(1.060f,-0.304f);
    glVertex2f(1.061f,-0.303f);
    glVertex2f(1.084f,-0.303f);
    glVertex2f(1.085f,-0.305f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.069f,-0.315f);
    glVertex2f(1.065f,-0.315f);
    glVertex2f(1.065f,-0.309f);
    glVertex2f(1.069f,-0.309f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(87, 87, 86);
    glVertex2f(1.081f,-0.331f);
    glVertex2f(1.074f,-0.331f);
    glVertex2f(1.074f,-0.310f);
    glVertex2f(1.075f,-0.309f);
    glVertex2f(1.080f,-0.309f);
    glVertex2f(1.081f,-0.310f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.091f,-0.330f);
    glVertex2f(1.089f,-0.330f);
    glVertex2f(1.089f,-0.327f);
    glVertex2f(1.091f,-0.327f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.091f,-0.320f);
    glVertex2f(1.089f,-0.320f);
    glVertex2f(1.089f,-0.318f);
    glVertex2f(1.091f,-0.318f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.096f,-0.341f);
    glVertex2f(1.088f,-0.341f);
    glVertex2f(1.088f,-0.339f);
    glVertex2f(1.096f,-0.339f);
    glEnd();
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);
    x=1.014f;
    y=-0.343f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.014f;
    y=-0.343f;
    radius =0.00215;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x=1.014f;
    y=-0.343f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.0384f;
    y=-0.341f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.038f;
    y=-0.341f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.053f;
    y=-0.341f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.053f;
    y=-0.341f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//4th Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.067f;
    y=-0.341f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.067f;
    y=-0.341f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//Coal Cart
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.111f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.111f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.136f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.136f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1615f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.1615f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.103f,-0.341f);
    glVertex2f(1.096f,-0.341f);
    glVertex2f(1.096f,-0.339f);
    glVertex2f(1.102f,-0.339f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.103f,-0.341f);
    glVertex2f(1.102f,-0.339f);
    glVertex2f(1.102f,-0.337f);
    glVertex2f(1.104,-0.338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.115f,-0.340f);
    glVertex2f(1.106f,-0.340f);
    glVertex2f(1.107f,-0.337f);
    glVertex2f(1.115f,-0.337f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.120f,-0.341f);
    glVertex2f(1.117f,-0.341f);
    glVertex2f(1.117f,-0.337f);
    glVertex2f(1.120f,-0.337f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.140f,-0.340f);
    glVertex2f(1.132,-0.34);
    glVertex2f(1.131f,-0.336f);
    glVertex2f(1.140f,-0.336f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.165f,-0.340f);
    glVertex2f(1.157f,-0.340f);
    glVertex2f(1.157f,-0.337f);
    glVertex2f(1.165f,-0.337f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.173f,-0.339f);
    glVertex2f(1.171f,-0.341f);
    glVertex2f(1.171f,-0.336f);
    glVertex2f(1.173f,-0.336f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(1.118f,-0.318f);
    glVertex2f(1.136f,-0.313f);
    glVertex2f(1.157f,-0.318f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.098f,-0.318f);
    glVertex2f(1.176f,-0.318f);
    glVertex2f(1.176f,-0.336f);
    glVertex2f(1.175f,-0.338f);
    glVertex2f(1.099f,-0.338f);
    glVertex2f(1.098f,-0.337f);
    glEnd();
//1st Passenger Cart
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.198f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.198f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.224f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.2248f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1615f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.251f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.185f,-0.317f);
    glVertex2f(1.184f,-0.337f);
    glVertex2f(1.185f,-0.338f);
    glVertex2f(1.265f,-0.337f);
    glVertex2f(1.266f,-0.336f);
    glVertex2f(1.266f,-0.316f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97, 106, 107);
    glVertex2f(1.183,-0.317);
    glVertex2f(1.183,-0.3135);
    glVertex2f(1.184f,-0.312f);
    glVertex2f(1.266f,-0.312f);
    glVertex2f(1.268f,-0.3135f);
    glVertex2f(1.268f,-0.317f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.187f,-0.319f);
    glVertex2f(1.197f,-0.319f);
    glVertex2f(1.197f,-0.329f);
    glVertex2f(1.187f,-0.329f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.201f,-0.319f);
    glVertex2f(1.210f,-0.319f);
    glVertex2f(1.210f,-0.329f);
    glVertex2f(1.201f,-0.329f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.215f,-0.319f);
    glVertex2f(1.224f,-0.319f);
    glVertex2f(1.224f,-0.329f);
    glVertex2f(1.215f,-0.329f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.229f,-0.319f);
    glVertex2f(1.238f,-0.319f);
    glVertex2f(1.238f,-0.329f);
    glVertex2f(1.229f,-0.329f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.243f,-0.319f);
    glVertex2f(1.252f,-0.319f);
    glVertex2f(1.252f,-0.329f);
    glVertex2f(1.243f,-0.329f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 86);
    glVertex2f(1.258f,-0.32f);
    glVertex2f(1.263f,-0.32);
    glVertex2f(1.263f,-0.337f);
    glVertex2f(1.257f,-0.337f);
    glEnd();
//2nd Passenger Cart
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.289f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.289f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.315f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.315f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.341f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.341f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.276f,-0.338f);
    glVertex2f(1.275f,-0.337f);
    glVertex2f(1.275f,-0.317f);
    glVertex2f(1.357f,-0.317f);
    glVertex2f(1.357f,-0.337f);
    glVertex2f(1.356f,-0.338f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97, 106, 107);
    glVertex2f(1.2735,-0.317);
    glVertex2f(1.2735,-0.314);
    glVertex2f(1.275,-0.3125);
    glVertex2f(1.3578,-0.3124);
    glVertex2f(1.3592,-0.3138);
    glVertex2f(1.3592,-0.317);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.2785,-0.32);
    glVertex2f(1.2875,-0.32);
    glVertex2f(1.2875,-0.329);
    glVertex2f(1.2785,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.2925,-0.32);
    glVertex2f(1.3015,-0.32);
    glVertex2f(1.3015,-0.329);
    glVertex2f(1.2925,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.3065,-0.32);
    glVertex2f(1.315,-0.32);
    glVertex2f(1.315,-0.329);
    glVertex2f(1.3065,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.32,-0.32);
    glVertex2f(1.329,-0.32);
    glVertex2f(1.329,-0.329);
    glVertex2f(1.32,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.334,-0.32);
    glVertex2f(1.343,-0.32);
    glVertex2f(1.343,-0.329);
    glVertex2f(1.334,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 86);
    glVertex2f(1.348,-0.32);
    glVertex2f(1.355,-0.32);
    glVertex2f(1.355,-0.338);
    glVertex2f(1.348,-0.338);
    glEnd();

    glPopMatrix();

//Train Bridge//*******************************
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.044f,-0.344f);
    glVertex2f(0.645f,-0.344f);
    glVertex2f(0.645f,-0.361f);
    glVertex2f(-0.044f,-0.361f);
    glEnd();
//1st Pillar
    glBegin(GL_POLYGON);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.044f,-0.361f);
    glVertex2f(-0.037f,-0.362f);
    glVertex2f(-0.031f,-0.364f);
    glVertex2f(-0.008f,-0.364f);
    glVertex2f(-0.001f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.031f,-0.364f);
    glVertex2f(-0.028f,-0.369f);
    glVertex2f(-0.012f,-0.369f);
    glVertex2f(-0.008f,-0.364f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.028f,-0.369f);
    glVertex2f(-0.012f,-0.369f);
    glVertex2f(-0.012f,-0.479f);
    glVertex2f(-0.028f,-0.479f);
    glEnd();
//2nd Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.001f,-0.361f);
    glVertex2f(0.005f,-0.364f);
    glVertex2f(0.029f,-0.363f);
    glVertex2f(0.036f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.005f,-0.364f);
    glVertex2f(0.029f,-0.363f);
    glVertex2f(0.025f,-0.369f);
    glVertex2f(0.01,-0.37);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.01,-0.37);
    glVertex2f(0.025f,-0.37);
    glVertex2f(0.026f,-0.479f);
    glVertex2f(0.01,-0.479f);
    glEnd();
//3rd Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.036f,-0.361f);
    glVertex2f(0.044f,-0.364f);
    glVertex2f(0.068f,-0.364f);
    glVertex2f(0.075f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.044f,-0.364f);
    glVertex2f(0.068f,-0.364f);
    glVertex2f(0.064f,-0.369f);
    glVertex2f(0.048f,-0.369f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.048f,-0.369f);
    glVertex2f(0.064f,-0.369f);
    glVertex2f(0.064f,-0.479f);
    glVertex2f(0.048f,-0.479f);
    glEnd();
//4th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.075f,-0.361f);
    glVertex2f(0.083f,-0.364f);
    glVertex2f(0.105f,-0.365f);
    glVertex2f(0.113f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.083f,-0.364f);
    glVertex2f(0.105f,-0.365f);
    glVertex2f(0.102f,-0.370f);
    glVertex2f(0.087f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.087f,-0.370f);
    glVertex2f(0.102f,-0.370f);
    glVertex2f(0.102f,-0.479f);
    glVertex2f(0.087f,-0.479f);
    glEnd();
//5th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.113f,-0.361f);
    glVertex2f(0.120f,-0.365f);
    glVertex2f(0.143f,-0.365f);
    glVertex2f(0.150f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.120f,-0.365f);
    glVertex2f(0.143f,-0.365f);
    glVertex2f(0.139f,-0.370f);
    glVertex2f(0.124f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.124f,-0.370f);
    glVertex2f(0.139f,-0.370f);
    glVertex2f(0.139f,-0.480f);
    glVertex2f(0.124f,-0.480f);
    glEnd();
//6th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.150f,-0.361f);
    glVertex2f(0.158f,-0.365f);
    glVertex2f(0.180f,-0.365f);
    glVertex2f(0.188f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.158f,-0.365f);
    glVertex2f(0.180f,-0.365f);
    glVertex2f(0.177f,-0.370f);
    glVertex2f(0.162f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.162f,-0.370f);
    glVertex2f(0.177f,-0.370f);
    glVertex2f(0.177f,-0.480f);
    glVertex2f(0.162f,-0.480f);
    glEnd();
//7th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.188f,-0.361f);
    glVertex2f(0.195f,-0.365f);
    glVertex2f(0.219f,-0.365f);
    glVertex2f(0.226f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.195f,-0.365f);
    glVertex2f(0.219f,-0.365f);
    glVertex2f(0.215f,-0.370f);
    glVertex2f(0.199f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.199f,-0.370f);
    glVertex2f(0.215f,-0.370f);
    glVertex2f(0.215f,-0.480f);
    glVertex2f(0.199f,-0.480f);
    glEnd();
//8th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.226f,-0.361f);
    glVertex2f(0.234f,-0.365f);
    glVertex2f(0.257f,-0.365f);
    glVertex2f(0.264f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.234f,-0.365f);
    glVertex2f(0.257f,-0.365f);
    glVertex2f(0.253f,-0.371f);
    glVertex2f(0.238f,-0.371f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.238f,-0.371f);
    glVertex2f(0.253f,-0.371f);
    glVertex2f(0.253f,-0.480f);
    glVertex2f(0.238f,-0.480f);
    glEnd();
//9th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.264f,-0.361f);
    glVertex2f(0.272f,-0.365f);
    glVertex2f(0.296f,-0.365f);
    glVertex2f(0.303f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.272f,-0.365f);
    glVertex2f(0.296f,-0.365f);
    glVertex2f(0.292f,-0.370f);
    glVertex2f(0.276f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.276f,-0.370f);
    glVertex2f(0.292f,-0.370f);
    glVertex2f(0.292f,-0.480f);
    glVertex2f(0.276f,-0.480f);
    glEnd();
//10th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.303f,-0.361f);
    glVertex2f(0.311f,-0.365f);
    glVertex2f(0.333f,-0.365f);
    glVertex2f(0.340f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.311f,-0.365f);
    glVertex2f(0.333f,-0.365f);
    glVertex2f(0.329f,-0.370f);
    glVertex2f(0.315f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.315f,-0.370f);
    glVertex2f(0.329f,-0.370f);
    glVertex2f(0.329f,-0.480f);
    glVertex2f(0.315f,-0.480f);
    glEnd();
//11th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.340f,-0.361f);
    glVertex2f(0.347f,-0.365f);
    glVertex2f(0.371f,-0.365f);
    glVertex2f(0.378f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.347f,-0.365f);
    glVertex2f(0.371f,-0.365f);
    glVertex2f(0.367f,-0.371f);
    glVertex2f(0.351f,-0.371f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.351f,-0.371f);
    glVertex2f(0.367f,-0.371f);
    glVertex2f(0.367f,-0.480f);
    glVertex2f(0.351f,-0.480f);
    glEnd();
//12th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.378f,-0.361f);
    glVertex2f(0.386f,-0.365f);
    glVertex2f(0.408f,-0.365f);
    glVertex2f(0.416f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.386f,-0.365f);
    glVertex2f(0.408f,-0.365f);
    glVertex2f(0.405f,-0.372f);
    glVertex2f(0.390f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.390f,-0.370f);
    glVertex2f(0.405f,-0.370f);
    glVertex2f(0.405f,-0.482f);
    glVertex2f(0.390f,-0.482f);
    glEnd();
//13th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.416f,-0.361f);
    glVertex2f(0.425f,-0.365f);
    glVertex2f(0.447f,-0.365f);
    glVertex2f(0.456f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.425f,-0.365f);
    glVertex2f(0.447f,-0.365f);
    glVertex2f(0.444f,-0.372f);
    glVertex2f(0.428f,-0.372f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.428f,-0.372f);
    glVertex2f(0.444f,-0.372f);
    glVertex2f(0.444f,-0.482f);
    glVertex2f(0.428f,-0.482f);
    glEnd();
//14th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.456f,-0.361f);
    glVertex2f(0.464f,-0.366f);
    glVertex2f(0.482f,-0.366f);
    glVertex2f(0.490f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.464f,-0.366f);
    glVertex2f(0.482f,-0.366f);
    glVertex2f(0.479f,-0.372f);
    glVertex2f(0.467f,-0.372f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.467f,-0.372f);
    glVertex2f(0.479f,-0.372f);
    glVertex2f(0.479f,-0.482f);
    glVertex2f(0.467f,-0.482f);
    glEnd();
//15th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.490f,-0.361f);
    glVertex2f(0.502f,-0.365f);
    glVertex2f(0.520f,-0.366f);
    glVertex2f(0.528f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.502f,-0.365f);
    glVertex2f(0.520f,-0.366f);
    glVertex2f(0.516f,-0.372f);
    glVertex2f(0.502f,-0.372f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.502f,-0.372f);
    glVertex2f(0.516f,-0.372f);
    glVertex2f(0.516f,-0.482f);
    glVertex2f(0.502f,-0.482f);
    glEnd();

//16th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.528f,-0.361f);
    glVertex2f(0.537f,-0.366f);
    glVertex2f(0.558f,-0.366f);
    glVertex2f(0.567f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.537f,-0.366f);
    glVertex2f(0.558f,-0.366f);
    glVertex2f(0.556f,-0.373f);
    glVertex2f(0.539f,-0.373f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.539f,-0.373f);
    glVertex2f(0.556f,-0.373f);
    glVertex2f(0.556f,-0.482f);
    glVertex2f(0.539f,-0.482f);
    glEnd();
//17th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.567f,-0.361f);
    glVertex2f(0.576f,-0.366f);
    glVertex2f(0.597f,-0.366f);
    glVertex2f(0.605f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.576f,-0.366f);
    glVertex2f(0.597f,-0.366f);
    glVertex2f(0.594f,-0.373f);
    glVertex2f(0.578f,-0.373f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.578f,-0.373f);
    glVertex2f(0.594f,-0.373f);
    glVertex2f(0.594f,-0.482f);
    glVertex2f(0.578f,-0.482f);
    glEnd();

//18th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.605f,-0.361f);
    glVertex2f(0.614f,-0.366f);
    glVertex2f(0.635f,-0.367f);
    glVertex2f(0.645f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.614f,-0.366f);
    glVertex2f(0.635f,-0.367f);
    glVertex2f(0.633f,-0.373f);
    glVertex2f(0.617f,-0.373f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.617f,-0.373f);
    glVertex2f(0.633f,-0.373f);
    glVertex2f(0.633f,-0.482f);
    glVertex2f(0.617f,-0.482f);
    glEnd();

//Sides of Blue Lake//*******************************
//Land
    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-1,-1);
    glVertex2f(-0.899f,-0.886f);
    glVertex2f(-0.436f,-0.940f);
    glVertex2f(-0.142f,-0.986f);
    glVertex2f(0.06,-1);
    glEnd();
//Fence
    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.453f,-0.940f);
    glVertex2f(-0.453f,-0.914f);
    glVertex2f(-0.449f,-0.912f);
    glVertex2f(-0.441f,-0.912f);
    glVertex2f(-0.443f,-0.940f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.347f,-0.961f);
    glVertex2f(-0.348f,-0.914f);
    glVertex2f(-0.344f,-0.912f);
    glVertex2f(-0.336f,-0.912f);
    glVertex2f(-0.336f,-0.962f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.215f,-0.982f);
    glVertex2f(-0.216f,-0.922f);
    glVertex2f(-0.212f,-0.919f);
    glVertex2f(-0.204f,-0.919f);
    glVertex2f(-0.205f,-0.982f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.102f,-0.990f);
    glVertex2f(-0.102f,-0.922f);
    glVertex2f(-0.097f,-0.920f);
    glVertex2f(-0.091f,-0.920f);
    glVertex2f(-0.091f,-0.991f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.020f,-0.997f);
    glVertex2f(0.021f,-0.939f);
    glVertex2f(0.025f,-0.936f);
    glVertex2f(0.032f,-0.936f);
    glVertex2f(0.032f,-0.998f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.135,-1);
    glVertex2f(0.135f,-0.947f);
    glVertex2f(0.138f,-0.945f);
    glVertex2f(0.146f,-0.945f);
    glVertex2f(0.146f,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.259,-1);
    glVertex2f(0.259f,-0.954f);
    glVertex2f(0.262f,-0.952f);
    glVertex2f(0.270f,-0.952f);
    glVertex2f(0.2706,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.383,-1);
    glVertex2f(0.382f,-0.968f);
    glVertex2f(0.386f,-0.966f);
    glVertex2f(0.393f,-0.967f);
    glVertex2f(0.394,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.512,-1);
    glVertex2f(0.512f,-0.955f);
    glVertex2f(0.516f,-0.953f);
    glVertex2f(0.523f,-0.953f);
    glVertex2f(0.5237,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.632,-1);
    glVertex2f(0.632f,-0.956f);
    glVertex2f(0.635f,-0.953f);
    glVertex2f(0.643f,-0.953f);
    glVertex2f(0.6435,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.7768,-1);
    glVertex2f(0.776f,-0.976f);
    glVertex2f(0.78,-0.975);
    glVertex2f(0.787f,-0.974f);
    glVertex2f(0.788,-1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.469f,-0.925f);
    glVertex2f(-0.469f,-0.919f);
    glVertex2f(-0.342f,-0.922f);
    glVertex2f(-0.342f,-0.931f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.342f,-0.931f);
    glVertex2f(-0.342f,-0.922f);
    glVertex2f(-0.210f,-0.933f);
    glVertex2f(-0.210f,-0.942f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.210f,-0.942f);
    glVertex2f(-0.210f,-0.933f);
    glVertex2f(-0.096f,-0.935f);
    glVertex2f(-0.096f,-0.945f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.096f,-0.945f);
    glVertex2f(-0.096f,-0.935f);
    glVertex2f(0.027f,-0.949f);
    glVertex2f(0.027f,-0.958f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.027f,-0.958f);
    glVertex2f(0.027f,-0.949f);
    glVertex2f(0.141f,-0.957f);
    glVertex2f(0.141f,-0.966f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.141f,-0.966f);
    glVertex2f(0.141f,-0.957f);
    glVertex2f(0.265f,-0.970f);
    glVertex2f(0.265f,-0.980f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.265f,-0.980f);
    glVertex2f(0.265f,-0.970f);
    glVertex2f(0.387f,-0.979f);
    glVertex2f(0.388f,-0.991f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.388f,-0.991f);
    glVertex2f(0.387f,-0.979f);
    glVertex2f(0.517f,-0.975f);
    glVertex2f(0.517f,-0.986f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.517f,-0.986f);
    glVertex2f(0.517f,-0.975f);
    glVertex2f(0.638f,-0.973f);
    glVertex2f(0.638f,-0.982f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.638f,-0.982f);
    glVertex2f(0.638f,-0.973f);
    glVertex2f(0.782f,-0.988f);
    glVertex2f(0.782f,-0.997f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.782f,-0.997f);
    glVertex2f(0.782f,-0.988f);
    glVertex2f(0.88,-1);
    glVertex2f(0.793,-1);
    glEnd();




//tree wood2
    glBegin(GL_QUADS);
    glColor3ub(45, 21, 11);
    glVertex2f(-0.69,-1);
    glVertex2f(-0.56,-1);
    glVertex2f(-0.56,-0.80);
    glVertex2f(-0.69,-0.80);
    glEnd();


    //tree wood
    glBegin(GL_QUADS);
    glColor3ub(45, 21, 11);
    glVertex2f(-0.85,-1);
    glVertex2f(-0.72,-1);
    glVertex2f(-0.72,-0.70);
    glVertex2f(-0.85,-0.70);
    glEnd();


    //tree2 leaf1
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.78,-0.85);
    glVertex2f(-0.47,-0.85);
    glVertex2f(-0.625,-0.70);
    glEnd();

//Dark Rock close
    glBegin(GL_POLYGON);
    glColor3ub(41, 54, 62);
    glVertex2f(-1,-1);
    glVertex2f(-0.8995326838053,-0.84);
    glVertex2f(-0.7632128497935,-0.82);
    glVertex2f(-0.4699186614649,-0.9193418854794);
    glVertex2f(-0.365,-1);
    glEnd();




    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.2101515676724,-0.9424292170789);
    glVertex2f(-0.2106543761129,-0.9338814735457);
    glVertex2f(-0.3428929959411,-0.9223168793538);
    glVertex2f(-0.3423901875007,-0.9318702397732);
    glEnd();

//1st Side Forest of Blue Lake
    glBegin(GL_POLYGON);
     glColor3ub(10, 48, 70);
    glVertex2f(-1,-0.4482623769432);
    glVertex2f(0.08032289841543,-0.4482623769432);
glColor3ub(20, 77, 110);
    glVertex2f(-0.1320390596915,-0.2541253303839);
    glVertex2f(-0.4734288362521,-0.2041253303839);

    glVertex2f(-0.6594300061514,-0.1800843628459);

    glVertex2f(-0.8707374576695,-0.1408596263365);
    glVertex2f(-1,-0.11);

    glEnd();

//2st Side Forest of Blue Lake
    glBegin(GL_POLYGON);


    glVertex2f(0.5422429702315,-0.4482623769432);
    glVertex2f(0.607145421979,-0.3349593212472);
    glColor3ub(20, 77, 110);
    glVertex2f(0.8327249542509,-0.2174623167401);
    glColor3ub(10, 48, 70);
    glVertex2f(0.8369149833822,-0.4482623769432);
    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(20, 77, 110);
    glVertex2f(0.8327249542509,-0.2174623167401);
    glVertex2f(0.8359102149068,-0.2072473867747);
    glColor3ub(20, 77, 110);
    glVertex2f(0.9996368118879,-0.1695879140117);
     glColor3ub(10, 48, 70);
    glVertex2f(1.0000691863567,-0.4482623769432);
    glVertex2f(0.8369149833822,-0.4482623769432);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(20, 77, 110);
    glVertex2f(0.8359102149068,-0.2072473867747);
    glVertex2f(0.8188751805996,-0.1846506759137);
    glVertex2f(0.8157897474026,-0.1630526435341);
    glVertex2f(0.8260745247262,-0.1385748735038);
    glVertex2f(0.8532263368606,-0.1385748735038);

    glVertex2f(0.8914857085046,-0.1389862645967);
    glVertex2f(0.9188432161855,-0.1315812249237);
    glVertex2f(1,-0.11);
    glVertex2f(0.9996368118879,-0.1695879140117);
    glEnd();


      //tree leaf9
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.86,-0.41);
    glVertex2f(-0.70,-0.41);
    glVertex2f(-0.785,-0.31);
    glEnd();

//tree leaf8
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.87,-0.46);
    glVertex2f(-0.69,-0.46);
    glVertex2f(-0.785,-0.31);
    glEnd();


    //tree leaf7
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.89,-0.51);
    glVertex2f(-0.67,-0.51);
    glVertex2f(-0.785,-0.36);
    glEnd();


    //tree leaf5
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.90,-0.56);
    glVertex2f(-0.66,-0.56);
    glVertex2f(-0.785,-0.35);
    glEnd();


    //tree leaf4
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.91,-0.60);
    glVertex2f(-0.65,-0.60);
    glVertex2f(-0.785,-0.30);
    glEnd();

    //tree leaf3
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.92,-0.66);
    glVertex2f(-0.64,-0.66);
    glVertex2f(-0.785,-0.38);
    glEnd();


    //tree leaf2
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.93,-0.72);
    glVertex2f(-0.63,-0.72);
    glVertex2f(-0.785,-0.40);
    glEnd();

//tree leaf1
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.94,-0.78);
    glVertex2f(-0.63,-0.78);
    glVertex2f(-0.785,-0.55);
    glEnd();



    //tree2 leaf5
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.725,-0.62);
    glVertex2f(-0.506,-0.62);
    glVertex2f(-0.625,-0.38);
    glEnd();


    //tree2 leaf5
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.735,-0.65);
    glVertex2f(-0.506,-0.65);
    glVertex2f(-0.625,-0.42);
    glEnd();


    //tree2 leaf4
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.745,-0.70);
    glVertex2f(-0.496,-0.70);
    glVertex2f(-0.625,-0.45);
    glEnd();

    //tree2 leaf3
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.755,-0.75);
    glVertex2f(-0.486,-0.75);
    glVertex2f(-0.625,-0.50);
    glEnd();


    //tree2 leaf2
    glBegin(GL_TRIANGLES);
    glColor3ub(12, 39, 33);
    glVertex2f(-0.765,-0.80);
    glVertex2f(-0.476,-0.80);
    glVertex2f(-0.625,-0.60);
    glEnd();

//Cover Bridge Using Blue Lake//*******************************
    glBegin(GL_QUADS);
    glColor3ub(98, 167, 206);
    glVertex2f(-0.080f,-0.448f);
    glVertex2f(0.842f,-0.448f);
    glVertex2f(0.842f,-0.848f);
    glVertex2f(-0.080f,-0.848f);
    glEnd();

    glPushMatrix();
    glTranslatef(-position3, 0,0);
//Fishing Boat//*******************************
//Boat
    glBegin(GL_QUADS);
    glColor3ub(36, 74, 100);
    glVertex2f(0.496f,-0.890f);
    glVertex2f(0.496f,-0.888f);
    glVertex2f(0.494f,-0.886f);
    glVertex2f(0.492f,-0.888f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.514f,-0.911f);
    glVertex2f(0.515f,-0.896f);
    glVertex2f(0.505f,-0.894f);
    glVertex2f(0.498f,-0.892f);
    glVertex2f(0.492f,-0.888f);
    glVertex2f(0.492f,-0.890f);
    glVertex2f(0.493f,-0.893f);
    glVertex2f(0.496f,-0.900f);
    glVertex2f(0.500f,-0.904f);
    glVertex2f(0.505f,-0.910f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.514f,-0.911f);
    glVertex2f(0.515f,-0.896f);
    glVertex2f(0.535f,-0.898f);
    glVertex2f(0.554f,-0.899f);
    glVertex2f(0.575f,-0.898f);
    glVertex2f(0.569f,-0.912f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.569f,-0.912f);
    glVertex2f(0.575f,-0.898f);
    glVertex2f(0.585f,-0.897f);
    glVertex2f(0.595f,-0.895f);
    glVertex2f(0.605f,-0.892f);
    glVertex2f(0.577f,-0.912f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.577f,-0.912f);
    glVertex2f(0.607f,-0.890f);
    glVertex2f(0.611f,-0.890f);
    glVertex2f(0.611f,-0.894f);
    glVertex2f(0.609f,-0.900f);
    glVertex2f(0.605f,-0.905f);
    glVertex2f(0.600f,-0.910f);
    glVertex2f(0.595f,-0.912f);
    glVertex2f(0.585f,-0.912f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.607f,-0.890f);
    glVertex2f(0.608f,-0.889f);
    glVertex2f(0.608f,-0.887f);
    glVertex2f(0.609f,-0.887f);
    glVertex2f(0.610f,-0.888f);
    glVertex2f(0.611f,-0.890f);
    glEnd();
//Human
    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.542f,-0.899f);
    glVertex2f(0.538f,-0.899f);
    glVertex2f(0.538f,-0.894f);
    glVertex2f(0.537f,-0.893f);
    glVertex2f(0.542f,-0.889f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.543f,-0.879f);
    glVertex2f(0.544f,-0.882f);
    glVertex2f(0.543f,-0.884f);
    glVertex2f(0.542f,-0.889f);
    glVertex2f(0.537f,-0.893f);
    glVertex2f(0.537f,-0.887f);
    glVertex2f(0.535f,-0.884f);
    glVertex2f(0.53f,-0.880f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.543f,-0.879f);
    glVertex2f(0.535f,-0.880f);
    glVertex2f(0.535f,-0.879f);
    glVertex2f(0.535f,-0.875f);
    glVertex2f(0.535f,-0.872f);
    glVertex2f(0.537f,-0.870f);
    glVertex2f(0.538f,-0.866f);
    glVertex2f(0.542f,-0.865f);
    glVertex2f(0.545f,-0.873f);
    glVertex2f(0.546f,-0.879f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(36, 74, 100);
    glVertex2f(0.538f,-0.866f);
    glVertex2f(0.537f,-0.864f);
    glVertex2f(0.541f,-0.863f);
    glVertex2f(0.542f,-0.865f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.541f,-0.863f);
    glVertex2f(0.537f,-0.864f);
    glVertex2f(0.536f,-0.864f);
    glVertex2f(0.535f,-0.861f);
    glVertex2f(0.536f,-0.860f);
    glVertex2f(0.534f,-0.859f);
    glVertex2f(0.537f,-0.858f);
    glVertex2f(0.538f,-0.857f);

    glVertex2f(0.540f,-0.856f);
    glVertex2f(0.542f,-0.858f);
    glVertex2f(0.543f,-0.860f);
    glVertex2f(0.542f,-0.861f);
    glEnd();
//Fishing Pol
    glBegin(GL_QUADS);
    glColor3ub(36, 74, 100);
    glVertex2f(0.535f,-0.879f);
    glVertex2f(0.490f,-0.846f);
    glVertex2f(0.490f,-0.843f);
    glVertex2f(0.535f,-0.877f);
    glEnd();

    glPopMatrix();

    glFlush();


}


















//....................................................................................................
//...................................................................................................
//....................................................................................................










void night()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


//Weather//*******************************
    glBegin(GL_POLYGON);
    glColor3ub(0, 24, 111);
    glVertex2f(-1,1);
    glVertex2f(-0.5,1);
    glVertex2f(0,1);
    glVertex2f(0.5,1);
    glVertex2f(1,1);
    glVertex2f(1,0.5);
    glVertex2f(1,0);
    glVertex2f(1,-0.5);

    glColor3ub(23, 91, 191);
    glVertex2f(1,-1);
    glVertex2f(0.5,-1);
    glVertex2f(0,-1);
    glVertex2f(-0.5,-1);
    glVertex2f(-1,-1);
    glVertex2f(-1,-0.5);
    glVertex2f(-1,0);
    glVertex2f(-1,0.5);
    glEnd();

//Stars//*******************************
    glPointSize(3.5);
    glBegin(GL_POINTS);
    glColor3ub(253, 254, 254);
     glVertex2f(-0.36f,0.43f);
    glVertex2f(-0.18f,0.44f);
    glVertex2f(-0.12f,0.51f);
    glVertex2f(0.34f,0.46f);
    glVertex2f(0.67f,0.46f);

    glVertex2f(0.13f,0.61f);
    glVertex2f(0.52f,0.75f);
    glVertex2f(0.2,0.8);
    glVertex2f(0.84f,0.70f);
    glVertex2f(-0.28f,0.73f);
    glVertex2f(-0.02f,0.90f);
    glVertex2f(0.38f,0.91f);
    glVertex2f(0.71f,0.88f);


    glVertex2f(-0.66f,0.63f);
    glVertex2f(-0.78f,0.74f);
    glVertex2f(-0.62f,0.41f);
    glVertex2f(-0.44f,0.66f);
    glVertex2f(-0.90f,0.76f);

    glVertex2f(0.13f,0.61f);
    glVertex2f(0.52f,0.75f);
    glVertex2f(0.4,0.9);
    glVertex2f(-0.89f,0.40f);
    glVertex2f(-0.28f,0.73f);
    glVertex2f(-0.02f,0.90f);
    glVertex2f(-0.45f,0.81f);
    glVertex2f(-0.71f,0.88f);
    glEnd();










//Moon//*******************************
    glPushMatrix();
    glTranslatef(position2,-position2,0);

    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount =40;
    GLfloat twicePi = 2.0 * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=0.5;
    y=0.7;
    radius =0.1;
    twicePi = -1.5 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 24, 111);

    x=0.525;
    y=0.72;
    radius =0.1;
    twicePi = 2.0 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();

//Big Clouds//*******************************
    glBegin(GL_POLYGON);
    glColor3ub(69, 125, 207);
    glVertex2f(-1,0);
    glVertex2f(-1,0.34);
    glVertex2f(-0.975f,0.340f);
    glVertex2f(-0.951f,0.348f);
    glVertex2f(-0.927f,0.366f);
    glVertex2f(-0.916f,0.335f);
    glVertex2f(-0.886f,0.309f);
    glVertex2f(-0.850f,0.297f);
    glVertex2f(-0.833f,0.292f);
    glVertex2f(-0.803f,0.273f);
    glVertex2f(-0.775f,0.232f);
    glVertex2f(-0.716f,0.237f);
    glVertex2f(-0.671f,0.209f);
    glVertex2f(-0.629f,0.151f);
    glVertex2f(-0.63,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(69, 125, 207);
    glVertex2f(-0.63,0);
    glVertex2f(-0.629f,0.151f);
    glVertex2f(-0.420f,0.206f);
    glVertex2f(-0.391f,0.214f);
    glVertex2f(-0.39,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(69, 125, 207);
    glVertex2f(-0.39,0);
    glVertex2f(-0.391f,0.214f);
    glVertex2f(-0.36,0.24);
    glVertex2f(-0.340f,0.262f);
    glVertex2f(-0.3,0.24);
    glVertex2f(-0.28,0.24);
    glVertex2f(-0.229f,0.233f);
    glVertex2f(0.42,0.22);
    glVertex2f(0.448f,0.209f);
    glVertex2f(0.45,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(69, 125, 207);
    glVertex2f(0.45,0);
    glVertex2f(0.448f,0.209f);
    glVertex2f(0.485f,0.229f);
    glVertex2f(0.52,0.24);
    glVertex2f(0.552f,0.243f);
    glVertex2f(0.584f,0.258f);
    glVertex2f(0.631f,0.273f);
    glVertex2f(0.7,0.28);
    glVertex2f(0.740f,0.292f);
    glVertex2f(0.74,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(69, 125, 207);
    glVertex2f(0.74,0);
    glVertex2f(0.740f,0.292f);
    glVertex2f(0.755f,0.327f);
    glVertex2f(0.772f,0.290f);
    glVertex2f(0.804f,0.273f);
    glVertex2f(0.833f,0.259f);
    glVertex2f(0.86,0.26);
    glVertex2f(0.88,0.26);
    glVertex2f(1,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.975f;
    y=0.340f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.927f;
    y=0.366f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.916f;
    y=0.335f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.886f;
    y=0.309f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.850f;
    y=0.297f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.833f;
    y=0.2929f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.803f;
    y=0.273f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.775f;
    y=0.232f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.716f;
    y=0.2376f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.671f;
    y=0.209f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.420f;
    y=0.206f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.391f;
    y=0.214f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.36;
    y=0.24;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.340f;
    y=0.262f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.3;
    y=0.24;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.28;
    y=0.24;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=-0.229f;
    y=0.233f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.42;
    y=0.22;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.485f;
    y=0.229f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.52;
    y=0.24;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.552f;
    y=0.243f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.584f;
    y=0.258f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.631f;
    y=0.273f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.7;
    y=0.28;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.740f;
    y=0.292f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.755f;
    y=0.327f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.772f;
    y=0.290f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.804f;
    y=0.273f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.833f;
    y=0.259f;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.86;
    y=0.26;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(69, 125, 207);
    x=0.88;
    y=0.26;
    radius =0.035;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

//Back Mountain//*******************************
//Left Mountain
    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-1,0.06);
    glVertex2f(-0.755f,0.175f);
    glVertex2f(-0.738f,0.183f);
    glVertex2f(-0.717f,0.190f);
    glVertex2f(-0.696f,0.193f);
    glVertex2f(-0.639f,0.199f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-0.639f,0.199f);
    glVertex2f(-0.598f,0.211f);
    glVertex2f(-0.569f,0.223f);
    glVertex2f(-0.525f,0.241f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-0.525f,0.241f);
    glVertex2f(-0.473f,0.216f);
    glVertex2f(-0.434f,0.200f);
    glVertex2f(-0.389f,0.188f);
    glVertex2f(-0.403f,0.134f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(236, 240, 241);
    glVertex2f(-0.403f,0.134f);
    glVertex2f(-0.389f,0.188f);
    glVertex2f(-0.339f,0.178f);
    glEnd();
//Left Mountain Light Shadow
    glBegin(GL_QUADS);
    glColor3ub(178, 186, 187);
    glVertex2f(-0.3,0);
    glVertex2f(-1,0);
    glVertex2f(-0.676f,0.135f);
    glVertex2f(-0.501f,0.157f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(178, 186, 187);
    glVertex2f(-0.450f,0.203f);
    glVertex2f(-0.501f,0.157f);
    glVertex2f(-0.3,0);
    glVertex2f(-0.328f,0.176f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(-0.628f,0.200f);
    glVertex2f(-0.709f,0.187f);
    glVertex2f(-0.723f,0.176f);
    glVertex2f(-0.680f,0.163f);
    glVertex2f(-0.676f,0.135f);
    glVertex2f(-0.501f,0.157f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(-0.450f,0.203f);
    glVertex2f(-0.501f,0.157f);
    glVertex2f(-0.55,0.2);
    glVertex2f(-0.523f,0.216f);
    glVertex2f(-0.531f,0.229f);
    glVertex2f(-0.523f,0.240f);
    glEnd();
//Right Mountain
    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(1,0.06);
    glVertex2f(0.683f,0.06);
    glVertex2f(0.567f,0.118f);
    glVertex2f(0.464f,0.176f);
    glVertex2f(0.543f,0.212f);
    glVertex2f(0.569f,0.204f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(1,0.06);
    glVertex2f(0.569f,0.204f);
    glVertex2f(0.592f,0.218f);
    glVertex2f(0.623f,0.237f);
    glVertex2f(0.661f,0.264f);
    glVertex2f(0.688f,0.266f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(236, 240, 241);
    glVertex2f(0.688f,0.266f);
    glVertex2f(0.724f,0.290f);
    glVertex2f(0.747f,0.257f);
    glVertex2f(0.772f,0.211f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(0.772f,0.211f);
    glVertex2f(0.747f,0.257f);
    glVertex2f(0.774f,0.238f);
    glVertex2f(0.807f,0.220f);
    glVertex2f(0.831f,0.205f);
    glVertex2f(1,0.06);
    glEnd();
//Right Mountain Light Shadow
    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(1,0);
    glVertex2f(0.5,0);
    glVertex2f(0.476f,0.172f);
    glVertex2f(0.502f,0.178f);
    glVertex2f(0.574f,0.187f);
    glVertex2f(0.683f,0.178f);
    glVertex2f(0.834f,0.203f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(0.683f,0.178f);
    glVertex2f(0.574f,0.187f);
    glVertex2f(0.553f,0.197f);
    glVertex2f(0.557f,0.200f);
    glVertex2f(0.542f,0.205f);
    glVertex2f(0.544f,0.210f);
    glVertex2f(0.566f,0.204f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(0.834f,0.203f);
    glVertex2f(0.683f,0.178f);
    glVertex2f(0.682f,0.187f);
    glVertex2f(0.663f,0.204f);
    glVertex2f(0.682f,0.232f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(0.834f,0.203f);
    glVertex2f(0.682f,0.232f);
    glVertex2f(0.682f,0.232f);
    glVertex2f(0.722f,0.233f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(0.834f,0.203f);
    glVertex2f(0.682f,0.232f);
    glVertex2f(0.771f,0.238f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(0.682f,0.232f);
    glVertex2f(0.657f,0.256f);
    glVertex2f(0.663f,0.264f);
    glVertex2f(0.689f,0.266f);
    glVertex2f(0.702f,0.251f);
    glVertex2f(0.713f,0.252f);
    glVertex2f(0.715f,0.244f);
    glVertex2f(0.722f,0.233f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(0.747f,0.256f);
    glVertex2f(0.771f,0.238f);
    glVertex2f(0.73,0.23);
    glVertex2f(0.728f,0.241f);
    glVertex2f(0.729f,0.248f);
    glVertex2f(0.723f,0.268f);
    glVertex2f(0.722f,0.281f);
    glVertex2f(0.725f,0.288f);
    glEnd();

//Tallest Mountain//*******************************
//Small Part
    glBegin(GL_TRIANGLES);
    glColor3ub(236, 240, 241);
    glVertex2f(-0.566f, -0.1);
    glVertex2f(-1,-0.1);
    glVertex2f(-0.549f,0.062f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(236, 240, 241);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-0.566f, -0.1);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-0.403f,0.134f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(236, 240, 241);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-0.403f,0.134f);
    glVertex2f(-0.339f,0.178f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-0.339f,0.178f);
    glVertex2f(-0.277f,0.221f);
    glVertex2f(-0.261f,0.227f);
    glVertex2f(-0.243f,0.232f);
    glVertex2f(-0.228f,0.225f);
    glVertex2f(-0.213f,0.219f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(236, 240, 241);
    glVertex2f(1,-0.1);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-0.213f,0.219f);
    glEnd();
//Medium Part
    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(-0.566f, -0.1);
    glVertex2f(1,-0.1);
    glVertex2f(-0.147f,0.299f);
    glEnd();
//Large Part
    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(0.35, -0.1);
    glVertex2f(0.010f,0.417f);
    glVertex2f(-0.012f,0.453f);
    glVertex2f(-0.073f,0.353f);
    glVertex2f(-0.129f,0.293f);
    glVertex2f(-0.147f,0.299f);
    glEnd();
//Largest Part
    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(0.526f,-0.1);
    glVertex2f(0.35, -0.1);
    glVertex2f(0.010f,0.417f);
    glVertex2f(0.091f,0.492f);
    glVertex2f(0.334f,0.290f);
    glVertex2f(0.433f,0.194f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(1, -0.1);
    glVertex2f(0.35, -0.1);
    glVertex2f(0.334f,0.290f);
    glVertex2f(0.567f,0.118f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(236, 240, 241);
    glVertex2f(1, -0.1);
    glVertex2f(0.35, -0.1);
    glVertex2f(0.334f,0.290f);
    glVertex2f(0.567f,0.118f);
    glEnd();
//Light Shadow
    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(-0.266f,0.225f);
    glVertex2f(-0.253f,0.230f);
    glVertex2f(-0.241f,0.229f);
    glVertex2f(-0.225f,0.223f);
    glVertex2f(-0.207f,0.217f);
    glVertex2f(-0.208f,0.158f);
    glVertex2f(-0.213f,0.111f);
    glVertex2f(-0.266f,0.126f);
    glVertex2f(-0.322f,0.116f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(-0.208f,0.158f);
    glVertex2f(-0.207f,0.217f);
    glVertex2f(-0.181f,0.217f);
    glVertex2f(-0.156f,0.210f);
    glVertex2f(-0.131f,0.204f);
    glVertex2f(-0.147f,0.162f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(178, 186, 187);
    glVertex2f(-0.147f,0.162f);
    glVertex2f(-0.131f,0.204f);
    glVertex2f(-0.036f,0.160f);
    glVertex2f(-0.085f,0.125f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(0.003f,0.244f);
    glVertex2f(-0.06,0.28);
    glVertex2f(-0.089f,0.281f);
    glVertex2f(-0.147f,0.298f);
    glVertex2f(-0.150f,0.287f);
    glVertex2f(-0.143f,0.276f);
    glVertex2f(-0.127f,0.260f);
    glVertex2f(-0.117f,0.233f);
    glVertex2f(-0.129f,0.219f);
    glVertex2f(-0.131f,0.204f);
    glVertex2f(-0.036f,0.160f);
    glVertex2f(-0.002f,0.136f);
    glVertex2f(0.007f,0.213f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(0.072f,0.251f);
    glVertex2f(0.054f,0.186f);
    glVertex2f(0.007f,0.213f);
    glVertex2f(0.003f,0.244f);
    glVertex2f(-0.006f,0.320f);
    glVertex2f(-0.013f,0.345f);
    glVertex2f(-0.027f,0.382f);
    glVertex2f(-0.026f,0.405f);
    glVertex2f(-0.015f,0.422f);
    glVertex2f(-0.010f,0.450f);
    glVertex2f(0.008f,0.419f);
    glVertex2f(0.039f,0.397f);
    glVertex2f(0.062f,0.395f);
    glVertex2f(0.081f,0.397f);
    glVertex2f(0.129f,0.368f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(178, 186, 187);
    glVertex2f(0.072f,0.251f);
    glVertex2f(0.115f,0.225f);
    glVertex2f(0.114f,0.193f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(178, 186, 187);
    glVertex2f(0.072f,0.251f);
    glVertex2f(0.152f,0.252f);
    glVertex2f(0.171f,0.196f);
    glVertex2f(0.115f,0.225f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(178, 186, 187);
    glVertex2f(0.152f,0.252f);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.237f,0.202f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(178, 186, 187);
    glVertex2f(0.129f,0.368f);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.152f,0.252f);
    glVertex2f(0.072f,0.251f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(178, 186, 187);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.307f,0.158f);
    glVertex2f(0.317f,0.200f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.331f,0.244f);
    glVertex2f(0.381f,0.200f);
    glVertex2f(0.365f,0.177f);
    glVertex2f(0.317f,0.200f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(0.431f,0.235f);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.129f,0.368f);
    glVertex2f(0.096f,0.418f);
    glVertex2f(0.099f,0.447f);
    glVertex2f(0.089f,0.460f);
    glVertex2f(0.094f,0.475f);
    glVertex2f(0.091f,0.491f);
    glVertex2f(0.150f,0.444f);
    glEnd();
//Sun Light
    glBegin(GL_POLYGON);
    glColor3ub(251, 252, 252);
    glVertex2f(-0.386f,-0.110f);
    glVertex2f(-1,-0.1);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-0.416f,0.077f);
    glVertex2f(-0.361f,0.014f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(251, 252, 252);
    glVertex2f(-0.416f,0.077f);
    glVertex2f(-0.549f,0.062f);
    glVertex2f(-0.497f,0.088f);
    glVertex2f(-0.477f,0.087f);
    glVertex2f(-0.413f,0.118f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(251, 252, 252);
    glVertex2f(-0.354f,0.114f);
    glVertex2f(-0.341f,0.084f);
    glVertex2f(-0.361f,0.014f);
    glVertex2f(-0.416f,0.077f);
    glVertex2f(-0.354f,0.114f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(251, 252, 252);
    glVertex2f(-0.341f,0.084f);
    glVertex2f(-0.354f,0.114f);
    glVertex2f(-0.311f,0.153f);
    glVertex2f(-0.322f,0.116f);
    glEnd();
//Dark Shadow
    glBegin(GL_POLYGON);
    glColor3ub(127, 140, 141);
    glVertex2f(-0.386f,-0.110f);
    glVertex2f(-0.361f,0.014f);
    glVertex2f(-0.341f,0.084f);
    glVertex2f(-0.322f,0.116f);
    glVertex2f(-0.266f,0.126f);
    glVertex2f(-0.213f,0.111f);
    glVertex2f(0.106f, -0.064f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(127, 140, 141);
    glVertex2f(0.106f, -0.064f);
    glVertex2f(-0.213f,0.111f);
    glVertex2f(-0.208f,0.158f);
    glVertex2f(-0.147f,0.162f);
    glVertex2f(-0.085f,0.125f);
    glVertex2f(0.021f,-0.043f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(127, 140, 141);
    glVertex2f(0.021f,-0.043f);
    glVertex2f(-0.085f,0.125f);
    glVertex2f(-0.036f,0.160f);
    glVertex2f(-0.002f,0.136f);
    glVertex2f(0.125f,-0.086f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(127, 140, 141);
    glVertex2f(0.125f,-0.086f);
    glVertex2f(-0.002f,0.136f);
    glVertex2f(0.007f,0.213f);
    glVertex2f(0.054f,0.186f);
    glVertex2f(0.231f,-0.077f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(127, 140, 141);
    glVertex2f(0.231f,-0.077f);
    glVertex2f(0.054f,0.186f);
    glVertex2f(0.072f,0.251f);
    glVertex2f(0.114f,0.193f);
    glVertex2f(0.310f,-0.058f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(127, 140, 141);
    glVertex2f(0.310f,-0.058f);
    glVertex2f(0.114f,0.193f);
    glVertex2f(0.115f,0.225f);
    glVertex2f(0.171f,0.196f);
    glVertex2f(0.399f,-0.052f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(127, 140, 141);
    glVertex2f(0.399f,-0.052f);
    glVertex2f(0.171f,0.196f);
    glVertex2f(0.152f,0.252f);
    glVertex2f(0.237f,0.202f);
    glVertex2f(0.512f,-0.034f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(127, 140, 141);
    glVertex2f(0.512f,-0.034f);
    glVertex2f(0.237f,0.202f);
    glVertex2f(0.223f,0.250f);
    glVertex2f(0.307f,0.158f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(127, 140, 141);
    glVertex2f(0.512f,-0.034f);
    glVertex2f(0.307f,0.158f);
    glVertex2f(0.317f,0.200f);
    glVertex2f(0.365f,0.177f);
    glVertex2f(0.613f,-0.015f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(127, 140, 141);
    glVertex2f(0.613f,-0.015f);;
    glVertex2f(0.365f,0.177f);
    glVertex2f(0.381f,0.200f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(127, 140, 141);
    glVertex2f(0.613f,-0.015f);
    glVertex2f(0.381f,0.200f);
    glVertex2f(0.331f,0.244f);
    glVertex2f(0.431f,0.235f);
    glVertex2f(0.497f,0.193f);
    glVertex2f(1,0);
    glEnd();

//Mountain Forests//*******************************
//4th Forest
    glBegin(GL_POLYGON);
    glColor3ub(67, 103, 126);
    glVertex2f(-0.05,-1);
    glVertex2f(-0.049f,-0.060f);
    glVertex2f(0.200f,-0.020f);
    glVertex2f(0.442f,0.079f);
    glVertex2f(0.532f,0.093f);
    glVertex2f(0.587f,0.127f);
    glVertex2f(0.728f,0.135f);
    glVertex2f(0.825f,0.193f);
    glVertex2f(0.888f,0.271f);
    glVertex2f(0.95,0.3);
    glVertex2f(1,0.35);
    glVertex2f(1,-1);
    glEnd();
//3rd Forest
    glBegin(GL_POLYGON);
    glColor3ub(76, 100, 115);
    glVertex2f(0.520f,-0.023f);
    glVertex2f(0.687f,0.048f);
    glVertex2f(0.792f,0.051f);
    glVertex2f(0.898f,0.092f);
    glVertex2f(1,0.07);
    glVertex2f(1,-1);
    glVertex2f(0.68,-1);
    glEnd();


    //tower
glBegin(GL_LINES);
glColor3f(0,0,0);

glVertex2f( 0.9,-0.5 );
glVertex2f( 0.9,0.07 );
glEnd();


//towerlm
glBegin(GL_LINES);
glColor3f(0,0,0);

glVertex2f( 0.8,-0.5 );
glVertex2f( 0.9,0.07 );
glEnd();


//towerrm
glBegin(GL_LINES);
glColor3f(0,0,0);

glVertex2f( 1,-0.5 );
glVertex2f( 0.9,0.07 );
glEnd();



glBegin(GL_TRIANGLE_FAN);
    glColor3ub(248, 255, 86);
    x=0.9;
    y=0.07;
    radius =0.005;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();


//2rd Forest
    glBegin(GL_POLYGON);
    glColor3ub(36, 83, 115);
    glVertex2f(0.057f,-0.120f);
    glVertex2f(0.057f,-0.120f);
    glVertex2f(0.520f,-0.023f);
    glVertex2f(0.718f,-0.043f);
    glVertex2f(0.869f,-0.049f);
    glVertex2f(1,-0.04);
    glVertex2f(1,-1);
    glVertex2f(0.42,-1);
    glVertex2f(-0.05,-1);
    glEnd();;

    //house1roof
    glBegin(GL_TRIANGLES);
    glColor3ub(76, 100, 115);
    glVertex2f(0.45f,-0.17);
    glVertex2f(0.50,-0.17);
    glVertex2f(0.475,-0.14);
    glEnd();

//house2roof
    glBegin(GL_TRIANGLES);
    glColor3ub(76, 100, 115);
    glVertex2f(0.45f,-0.20);
    glVertex2f(0.50,-0.17);
    glVertex2f(0.525,-0.14);
    glEnd();


    //house3
    glBegin(GL_QUADS);
    glColor3ub(127, 140, 141);
    glVertex2f(0.50,-0.22);
    glVertex2f(0.57f,-0.22);
    glVertex2f(0.57f,-0.16);
    glVertex2f(0.50,-0.16);
    glEnd();


     //house2
    glBegin(GL_QUADS);
    glColor3ub(127, 140, 141);
    glVertex2f(0.45,-0.20);
    glVertex2f(0.50f,-0.20);
    glVertex2f(0.50f,-0.17);
    glVertex2f(0.45,-0.17);
    glEnd();

    //house2windows
    glBegin(GL_QUADS);
    glColor3ub(248, 255, 86);
    glVertex2f(0.49,-0.20);
    glVertex2f(0.535f,-0.20);
    glVertex2f(0.535f,-0.18);
    glVertex2f(0.49,-0.18);
    glEnd();



     //house1
    glBegin(GL_QUADS);
    glColor3ub(127, 140, 141);
    glVertex2f(0.50,-0.25);
    glVertex2f(0.53f,-0.26);
    glVertex2f(0.53f,-0.15);
    glVertex2f(0.50,-0.15);
    glEnd();

//house1windows
    glBegin(GL_QUADS);
    glColor3ub(248, 255, 86);
    glVertex2f(0.465,-0.20);
    glVertex2f(0.485f,-0.20);
    glVertex2f(0.485f,-0.18);
    glVertex2f(0.465,-0.18);
    glEnd();



//house2windows
    glBegin(GL_QUADS);
    glColor3ub(248, 255, 86);
    glVertex2f(0.51,-0.20);
    glVertex2f(0.525f,-0.20);
    glVertex2f(0.525f,-0.18);
    glVertex2f(0.51,-0.18);
    glEnd();

//house1windows
    glBegin(GL_QUADS);
    glColor3ub(248, 255, 86);
    glVertex2f(0.475,-0.20);
    glVertex2f(0.485f,-0.20);
    glVertex2f(0.485f,-0.18);
    glVertex2f(0.475,-0.18);
    glEnd();


//1st Forest
    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-1,-1);
    glVertex2f(-1,0.3);
    glVertex2f(-0.981f,0.320f);
    glVertex2f(-0.849f,0.207f);
    glVertex2f(-0.832f,0.164f);
    glVertex2f(-0.835,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.832f,0.164f);
    glVertex2f(-0.660f,0.113f);
    glVertex2f(-0.6,0.1);
    glVertex2f(-0.582f,0.076f);
    glVertex2f(-0.585,-1);
    glVertex2f(-0.835,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.585,-1);
    glVertex2f(-0.05,-1);
    glVertex2f(-0.049f,-0.060f);
    glVertex2f(-0.203f,-0.065f);
    glVertex2f(-0.515f,0.044f);
    glVertex2f(-0.582f,0.076f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.05,-1);
    glVertex2f(0.42,-1);
    glVertex2f(0.414f,-0.191f);
    glVertex2f(0.244f,-0.132f);
    glVertex2f(0.074f,-0.114f);
    glVertex2f(-0.049f,-0.060f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.42,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.2);
    glVertex2f(0.825f,-0.204f);
    glVertex2f(0.585f,-0.212f);
    glVertex2f(0.414f,-0.191f);
    glEnd();

//Blue Lake//*******************************
    glBegin(GL_QUADS);
    glColor3ub(64, 154, 202);
    glVertex2f(1,-0.32);
    glVertex2f(-1,-0.32);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glEnd();


    //lighthouse.body
    glBegin(GL_QUADS);
    glColor3ub(105, 109, 110);
    glVertex2f(-0.325f,-0.90);
    glVertex2f(-0.23,-0.90);
    glColor3ub(178,186,187);
    glVertex2f(-0.24,-0.68);
    glVertex2f(-0.31f,-0.68);
    glEnd();



    //housewindows2
    glBegin(GL_QUADS);
    glColor3ub(239, 224, 81);
    glVertex2f(-0.30,-0.80);
    glVertex2f(-0.29,-0.80);
    glVertex2f(-0.29,-0.78);
    glVertex2f(-0.30,-0.78);
    glEnd();
    //housewindows1
    glBegin(GL_QUADS);
    glColor3ub(239, 224, 81);
    glVertex2f(-0.26,-0.75);
    glVertex2f(-0.25,-0.75);
    glVertex2f(-0.25,-0.73);
    glVertex2f(-0.26,-0.73);
    glEnd();

    //housewindows1
    glBegin(GL_QUADS);
    glColor3ub(239, 224, 81);
    glVertex2f(-0.26,-0.85);
    glVertex2f(-0.25,-0.85);
    glVertex2f(-0.25,-0.83);
    glVertex2f(-0.26,-0.83);
    glEnd();

//lighthouse.line
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.34f,-0.70);
    glVertex2f(-0.21,-0.70);
    glVertex2f(-0.21,-0.69);
    glVertex2f(-0.34f,-0.69);
    glEnd();


    //lighthouse.box
    glBegin(GL_QUADS);
    glColor3ub(178,186,187);
    glVertex2f(-0.32f,-0.68);
    glVertex2f(-0.23,-0.68);
    glVertex2f(-0.23,-0.61);
    glVertex2f(-0.32f,-0.61);
    glEnd();


 //lines
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f( -0.32f,-0.68 );
glVertex2f( -0.23,-0.68 );
glEnd();



 //lines
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f( -0.23,-0.61 );
glVertex2f( -0.32f,-0.61 );
glEnd();


    //lighthouse.boxwindow
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.31f,-0.67);
    glVertex2f(-0.24,-0.67);
    glVertex2f(-0.24,-0.62);
    glVertex2f(-0.31f,-0.62);
    glEnd();

    //lines
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f( -0.31f,-0.67 );
glVertex2f( -0.24,-0.67 );
glEnd();

  //lines
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f( -0.24,-0.62 );
glVertex2f( -0.31f,-0.62 );
glEnd();


glBegin(GL_QUADS);
    glColor3ub(251, 238, 99);
    glVertex2f(-0.24f,-0.655);


    glColor3ub(64, 154, 202);
    glVertex2f(-0.10,-0.69);
    glVertex2f(-0.10,-0.60);


    glColor3ub(251, 238, 99);
    glVertex2f(-0.24f,-0.635);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(251, 238, 99);
    glVertex2f(-0.31f,-0.655);

    glColor3ub(64, 154, 202);
    glVertex2f(-0.45,-0.69);
    glVertex2f(-0.45,-0.60);

    glColor3ub(251, 238, 99);
    glVertex2f(-0.31f,-0.635);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251, 238, 99);
    x=-0.275;
    y=-0.645;
    radius =0.022;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();



    //lighthouse.roof
    glBegin(GL_TRIANGLES);
    glColor3ub(55, 0, 0);
    glVertex2f(-0.335f,-0.61);
    glColor3ub(85,0,0);
    glVertex2f(-0.215,-0.61);
    glVertex2f(-0.275,-0.55);
    glEnd();




//Stone//*******************************
    glBegin(GL_QUADS);
    glColor3ub(87, 87, 86);
    glVertex2f(-0.354f,-0.906f);
    glVertex2f(-0.32,-0.88);
    glVertex2f(-0.279f,-0.888f);
    glVertex2f(-0.314f,-0.905f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(-0.314f,-0.905f);
    glVertex2f(-0.279f,-0.888f);
    glVertex2f(-0.227f,-0.878f);
    glVertex2f(-0.170f,-0.903f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(0.760f,-0.956f);
    glVertex2f(0.796f,-0.932f);
    glVertex2f(0.827f,-0.937f);
    glVertex2f(0.857f,-0.956f);
    glEnd();

//Train//*******************************
//Train Engine
    glPushMatrix();

    glTranslatef(-position,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.009f,-0.341f);
    glVertex2f(1.003f,-0.341f);
    glVertex2f(1.004f,-0.336f);
    glVertex2f(1.009f,-0.336f);
    glVertex2f(1.011f,-0.338f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 1, 1);
    glVertex2f(1.018f,-0.338f);
    glVertex2f(1.011f,-0.338f);
    glVertex2f(1.009f,-0.336f);
    glVertex2f(1.017f,-0.335f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 1, 1);
    glVertex2f(1.020f,-0.341f);
    glVertex2f(1.018f,-0.338f);
    glVertex2f(1.017f,-0.335f);
    glVertex2f(1.019f,-0.335f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.019f,-0.333f);
    glVertex2f(1.062f,-0.332f);
    glVertex2f(1.062f,-0.334f);
    glVertex2f(1.057f,-0.334f);
    glVertex2f(1.048f,-0.334f);
    glVertex2f(1.043f,-0.334f);
    glVertex2f(1.033f,-0.334f);
    glVertex2f(1.030f,-0.341f);
    glVertex2f(1.020f,-0.341f);
    glVertex2f(1.019f,-0.335f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 1, 1);
    glVertex2f(1.043f,-0.334f);
    glVertex2f(1.048f,-0.334f);
    glVertex2f(1.045f,-0.340f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 1, 1);
    glVertex2f(1.057f,-0.334f);
    glVertex2f(1.060f,-0.339f);
    glVertex2f(1.062f,-0.334f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.062f,-0.332f);
    glVertex2f(1.089f,-0.332f);
    glVertex2f(1.089f,-0.334f);
    glVertex2f(1.088f,-0.334f);
    glVertex2f(1.070f,-0.334f);
    glVertex2f(1.062f,-0.334f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.088f,-0.334f);
    glVertex2f(1.088f,-0.341f);
    glVertex2f(1.073f,-0.341f);
    glVertex2f(1.073f,-0.337f);
    glVertex2f(1.073f,-0.337f);
    glVertex2f(1.070f,-0.334f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.089f,-0.332f);
    glVertex2f(1.089f,-0.317f);
    glVertex2f(1.062f,-0.317f);
    glVertex2f(1.062f,-0.332f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.017f,-0.335f);
    glVertex2f(1.009f,-0.336f);
    glVertex2f(1.009f,-0.333f);
    glVertex2f(1.017f,-0.333f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.010f,-0.319f);
    glVertex2f(1.010f,-0.307f);
    glVertex2f(1.015f,-0.307f);
    glVertex2f(1.015f,-0.319f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(219, 162, 60);
    glVertex2f(1.015f,-0.307f);
    glVertex2f(1.010f,-0.307f);
    glVertex2f(1.010f,-0.306f);
    glVertex2f(1.015f,-0.306f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(219, 162, 60);
    glVertex2f(1.009f,-0.303f);
    glVertex2f(1.016f,-0.303f);
    glVertex2f(1.015f,-0.306f);
    glVertex2f(1.010f,-0.306f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.027f,-0.319f);
    glVertex2f(1.024f,-0.319f);
    glVertex2f(1.024f,-0.313f);
    glVertex2f(1.027f,-0.313f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.043f,-0.319f);
    glVertex2f(1.034f,-0.319f);
    glVertex2f(1.034f,-0.310f);
    glVertex2f(1.043f,-0.310f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.057f,-0.319f);
    glVertex2f(1.050f,-0.319f);
    glVertex2f(1.050f,-0.314f);
    glVertex2f(1.057f,-0.314f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.062f,-0.319f);
    glVertex2f(1.062f,-0.332f);
    glVertex2f(1.007f,-0.333f);
    glVertex2f(1.005f,-0.331f);

    glVertex2f(1.005f,-0.327f);
    glVertex2f(1.005f,-0.324f);
    glVertex2f(1.005f,-0.320f);
    glVertex2f(1.007f,-0.319f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.005f,-0.327f);
    glVertex2f(1.004f,-0.327f);
    glVertex2f(1.005,-0.325);
    glVertex2f(1.005f,-0.324f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.028f,-0.319f);
    glVertex2f(1.028f,-0.318f);
    glVertex2f(1.032f,-0.318f);
    glVertex2f(1.032f,-0.319f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.045f,-0.319f);
    glVertex2f(1.045f,-0.318f);
    glVertex2f(1.049f,-0.318f);
    glVertex2f(1.049f,-0.319f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(68, 66, 64);
    glVertex2f(1.084f,-0.317f);
    glVertex2f(1.062f,-0.317f);
    glVertex2f(1.062f,-0.306f);
    glVertex2f(1.084f,-0.306f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(68, 66, 64);
    glVertex2f(1.085f,-0.306f);
    glVertex2f(1.060f,-0.306f);
    glVertex2f(1.060f,-0.304f);
    glVertex2f(1.061f,-0.303f);
    glVertex2f(1.084f,-0.303f);
    glVertex2f(1.085f,-0.305f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.069f,-0.315f);
    glVertex2f(1.065f,-0.315f);
    glVertex2f(1.065f,-0.309f);
    glVertex2f(1.069f,-0.309f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(87, 87, 86);
    glVertex2f(1.081f,-0.331f);
    glVertex2f(1.074f,-0.331f);
    glVertex2f(1.074f,-0.310f);
    glVertex2f(1.075f,-0.309f);
    glVertex2f(1.080f,-0.309f);
    glVertex2f(1.081f,-0.310f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.091f,-0.330f);
    glVertex2f(1.089f,-0.330f);
    glVertex2f(1.089f,-0.327f);
    glVertex2f(1.091f,-0.327f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.091f,-0.320f);
    glVertex2f(1.089f,-0.320f);
    glVertex2f(1.089f,-0.318f);
    glVertex2f(1.091f,-0.318f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.096f,-0.341f);
    glVertex2f(1.088f,-0.341f);
    glVertex2f(1.088f,-0.339f);
    glVertex2f(1.096f,-0.339f);
    glEnd();
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);
    x=1.014f;
    y=-0.343f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.014f;
    y=-0.343f;
    radius =0.00215;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x=1.014f;
    y=-0.343f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.038f;
    y=-0.341f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.038f;
    y=-0.341f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.053f;
    y=-0.341f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.053f;
    y=-0.341f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//4th Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.067f;
    y=-0.341f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.067f;
    y=-0.341f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//Coal Cart
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.111f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.111f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.136f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.136f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.161f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.161f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.103f,-0.341f);
    glVertex2f(1.096f,-0.341f);
    glVertex2f(1.096f,-0.339f);
    glVertex2f(1.102f,-0.339f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.103f,-0.341f);
    glVertex2f(1.102f,-0.339f);
    glVertex2f(1.102f,-0.337f);
    glVertex2f(1.104,-0.338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.115f,-0.340f);
    glVertex2f(1.106f,-0.340f);
    glVertex2f(1.107f,-0.337f);
    glVertex2f(1.115f,-0.337f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.120f,-0.341f);
    glVertex2f(1.117f,-0.341f);
    glVertex2f(1.117f,-0.337f);
    glVertex2f(1.120f,-0.337f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.140f,-0.340f);
    glVertex2f(1.132,-0.34);
    glVertex2f(1.131f,-0.336f);
    glVertex2f(1.140f,-0.336f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.165f,-0.340f);
    glVertex2f(1.157f,-0.340f);
    glVertex2f(1.157f,-0.337f);
    glVertex2f(1.165f,-0.337f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.173f,-0.339f);
    glVertex2f(1.171f,-0.341f);
    glVertex2f(1.171f,-0.336f);
    glVertex2f(1.173f,-0.336f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(1.118f,-0.318f);
    glVertex2f(1.136f,-0.313f);
    glVertex2f(1.157f,-0.318f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.098f,-0.318f);
    glVertex2f(1.176f,-0.318f);
    glVertex2f(1.176f,-0.336f);
    glVertex2f(1.175f,-0.338f);
    glVertex2f(1.099f,-0.338f);
    glVertex2f(1.098f,-0.337f);
    glEnd();
//1st Passenger Cart
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.198f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.198f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.224f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.224f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.161f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.251f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.185,-0.317);
    glVertex2f(1.184f,-0.337f);
    glVertex2f(1.185f,-0.338f);
    glVertex2f(1.265f,-0.337f);
    glVertex2f(1.266f,-0.336f);
    glVertex2f(1.266f,-0.316f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97, 106, 107);
    glVertex2f(1.183,-0.317);
    glVertex2f(1.183,-0.3135);
    glVertex2f(1.184f,-0.312f);
    glVertex2f(1.266f,-0.312f);
    glVertex2f(1.268,-0.3135);
    glVertex2f(1.268,-0.317);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.1875,-0.3195);
    glVertex2f(1.197,-0.3195);
    glVertex2f(1.197,-0.329);
    glVertex2f(1.1875,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.2015,-0.3195);
    glVertex2f(1.2105,-0.3195);
    glVertex2f(1.2105,-0.329);
    glVertex2f(1.2015,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.2155,-0.3195);
    glVertex2f(1.2245,-0.3195);
    glVertex2f(1.2245,-0.329);
    glVertex2f(1.2155,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.229,-0.3195);
    glVertex2f(1.2385,-0.3195);
    glVertex2f(1.2385,-0.329);
    glVertex2f(1.229,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.243,-0.3195);
    glVertex2f(1.2525,-0.3195);
    glVertex2f(1.2525,-0.329);
    glVertex2f(1.243,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 86);
    glVertex2f(1.258,-0.32);
    glVertex2f(1.2635,-0.32);
    glVertex2f(1.263f,-0.337f);
    glVertex2f(1.257f,-0.337f);
    glEnd();
//2nd Passenger Cart
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.289f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.289f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.315f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.315f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.341f;
    y=-0.342f;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.341f;
    y=-0.342f;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.2768,-0.338);
    glVertex2f(1.2757,-0.337);
    glVertex2f(1.2756,-0.317);
    glVertex2f(1.3575,-0.317);
    glVertex2f(1.3575,-0.337);
    glVertex2f(1.3565,-0.338);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97, 106, 107);
    glVertex2f(1.2735,-0.317);
    glVertex2f(1.2735,-0.314);
    glVertex2f(1.275,-0.3125);
    glVertex2f(1.3578,-0.3124);
    glVertex2f(1.3592,-0.3138);
    glVertex2f(1.3592,-0.317);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.2785,-0.32);
    glVertex2f(1.2875,-0.32);
    glVertex2f(1.2875,-0.329);
    glVertex2f(1.2785,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.2925,-0.32);
    glVertex2f(1.3015,-0.32);
    glVertex2f(1.3015,-0.329);
    glVertex2f(1.2925,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.3065,-0.32);
    glVertex2f(1.315,-0.32);
    glVertex2f(1.315,-0.329);
    glVertex2f(1.3065,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.32,-0.32);
    glVertex2f(1.329,-0.32);
    glVertex2f(1.329,-0.329);
    glVertex2f(1.32,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.334,-0.32);
    glVertex2f(1.343,-0.32);
    glVertex2f(1.343,-0.329);
    glVertex2f(1.334,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 86);
    glVertex2f(1.348,-0.32);
    glVertex2f(1.355,-0.32);
    glVertex2f(1.355,-0.338);
    glVertex2f(1.348,-0.338);
    glEnd();

    glPopMatrix();

//Train Bridge//*******************************
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.044f,-0.344f);
    glVertex2f(0.645f,-0.344f);
    glVertex2f(0.645f,-0.361f);
    glVertex2f(-0.044f,-0.361f);
    glEnd();
//1st Pillar
    glBegin(GL_POLYGON);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.044f,-0.361f);
    glVertex2f(-0.037f,-0.362f);
    glVertex2f(-0.031f,-0.364f);
    glVertex2f(-0.008f,-0.364f);
    glVertex2f(-0.001f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.031f,-0.364f);
    glVertex2f(-0.028f,-0.369f);
    glVertex2f(-0.012f,-0.369f);
    glVertex2f(-0.008f,-0.364f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.028f,-0.369f);
    glVertex2f(-0.012f,-0.369f);
    glVertex2f(-0.012f,-0.479f);
    glVertex2f(-0.028f,-0.479f);
    glEnd();
//2nd Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.001f,-0.361f);
    glVertex2f(0.005f,-0.364f);
    glVertex2f(0.029f,-0.363f);
    glVertex2f(0.036f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.005f,-0.364f);
    glVertex2f(0.029f,-0.363f);
    glVertex2f(0.025f,-0.369f);
    glVertex2f(0.01,-0.37);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.01,-0.37);
    glVertex2f(0.025f,-0.37);
    glVertex2f(0.026f,-0.479f);
    glVertex2f(0.01,-0.479f);
    glEnd();
//3rd Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.036f,-0.361f);
    glVertex2f(0.044f,-0.364f);
    glVertex2f(0.068f,-0.364f);
    glVertex2f(0.075f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.044f,-0.364f);
    glVertex2f(0.068f,-0.364f);
    glVertex2f(0.064f,-0.369f);
    glVertex2f(0.048f,-0.369f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.048f,-0.369f);
    glVertex2f(0.064f,-0.369f);
    glVertex2f(0.064f,-0.479f);
    glVertex2f(0.048f,-0.479f);
    glEnd();
//4th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.075f,-0.361f);
    glVertex2f(0.083f,-0.364f);
    glVertex2f(0.105f,-0.365f);
    glVertex2f(0.113f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.083f,-0.364f);
    glVertex2f(0.105f,-0.365f);
    glVertex2f(0.102f,-0.370f);
    glVertex2f(0.087f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.087f,-0.370f);
    glVertex2f(0.102f,-0.370f);
    glVertex2f(0.102f,-0.479f);
    glVertex2f(0.087f,-0.479f);
    glEnd();
//5th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.113f,-0.361f);
    glVertex2f(0.120f,-0.365f);
    glVertex2f(0.143f,-0.365f);
    glVertex2f(0.150f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.120f,-0.365f);
    glVertex2f(0.143f,-0.365f);
    glVertex2f(0.139f,-0.370f);
    glVertex2f(0.124f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.124f,-0.370f);
    glVertex2f(0.139f,-0.370f);
    glVertex2f(0.139f,-0.480f);
    glVertex2f(0.124f,-0.480f);
    glEnd();
//6th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.150f,-0.361f);
    glVertex2f(0.158f,-0.365f);
    glVertex2f(0.180f,-0.365f);
    glVertex2f(0.188f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.158f,-0.365f);
    glVertex2f(0.180f,-0.365f);
    glVertex2f(0.177f,-0.370f);
    glVertex2f(0.162f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.162f,-0.370f);
    glVertex2f(0.177f,-0.370f);
    glVertex2f(0.177f,-0.480f);
    glVertex2f(0.162f,-0.480f);
    glEnd();
//7th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.188f,-0.361f);
    glVertex2f(0.195f,-0.365f);
    glVertex2f(0.219f,-0.365f);
    glVertex2f(0.226f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.195f,-0.365f);
    glVertex2f(0.219f,-0.365f);
    glVertex2f(0.215f,-0.370f);
    glVertex2f(0.199f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.199f,-0.370f);
    glVertex2f(0.215f,-0.370f);
    glVertex2f(0.215f,-0.480f);
    glVertex2f(0.199f,-0.480f);
    glEnd();
//8th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.226f,-0.361f);
    glVertex2f(0.234f,-0.365f);
    glVertex2f(0.257f,-0.365f);
    glVertex2f(0.264f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.234f,-0.365f);
    glVertex2f(0.257f,-0.365f);
    glVertex2f(0.253f,-0.371f);
    glVertex2f(0.238f,-0.371f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.238f,-0.371f);
    glVertex2f(0.253f,-0.371f);
    glVertex2f(0.253f,-0.480f);
    glVertex2f(0.238f,-0.480f);
    glEnd();
//9th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.264f,-0.361f);
    glVertex2f(0.272f,-0.365f);
    glVertex2f(0.296f,-0.365f);
    glVertex2f(0.303f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.272f,-0.365f);
    glVertex2f(0.296f,-0.365f);
    glVertex2f(0.292f,-0.370f);
    glVertex2f(0.276f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.276f,-0.370f);
    glVertex2f(0.292f,-0.370f);
    glVertex2f(0.292f,-0.480f);
    glVertex2f(0.276f,-0.480f);
    glEnd();
//10th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.303f,-0.361f);
    glVertex2f(0.311f,-0.365f);
    glVertex2f(0.333f,-0.365f);
    glVertex2f(0.340f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.311f,-0.365f);
    glVertex2f(0.333f,-0.365f);
    glVertex2f(0.329f,-0.370f);
    glVertex2f(0.315f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.315f,-0.370f);
    glVertex2f(0.329f,-0.370f);
    glVertex2f(0.329f,-0.480f);
    glVertex2f(0.315f,-0.480f);
    glEnd();
//11th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.340f,-0.361f);
    glVertex2f(0.347f,-0.365f);
    glVertex2f(0.371f,-0.365f);
    glVertex2f(0.378f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.347f,-0.365f);
    glVertex2f(0.371f,-0.365f);
    glVertex2f(0.367f,-0.371f);
    glVertex2f(0.351f,-0.371f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.351f,-0.371f);
    glVertex2f(0.367f,-0.371f);
    glVertex2f(0.367f,-0.480f);
    glVertex2f(0.351f,-0.480f);
    glEnd();
//12th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.378f,-0.361f);
    glVertex2f(0.386f,-0.365f);
    glVertex2f(0.408f,-0.365f);
    glVertex2f(0.416f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.386f,-0.365f);
    glVertex2f(0.408f,-0.365f);
    glVertex2f(0.405f,-0.372f);
    glVertex2f(0.390f,-0.370f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.390f,-0.370f);
    glVertex2f(0.405f,-0.370f);
    glVertex2f(0.405f,-0.482f);
    glVertex2f(0.390f,-0.482f);
    glEnd();
//13th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.416f,-0.361f);
    glVertex2f(0.425f,-0.365f);
    glVertex2f(0.447f,-0.365f);
    glVertex2f(0.456f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.425f,-0.365f);
    glVertex2f(0.447f,-0.365f);
    glVertex2f(0.444f,-0.372f);
    glVertex2f(0.428f,-0.372f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.428f,-0.372f);
    glVertex2f(0.444f,-0.372f);
    glVertex2f(0.444f,-0.482f);
    glVertex2f(0.428f,-0.482f);
    glEnd();
//14th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.456f,-0.361f);
    glVertex2f(0.464f,-0.366f);
    glVertex2f(0.482f,-0.366f);
    glVertex2f(0.490f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.464f,-0.366f);
    glVertex2f(0.482f,-0.366f);
    glVertex2f(0.479f,-0.372f);
    glVertex2f(0.467f,-0.372f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.467f,-0.372f);
    glVertex2f(0.479f,-0.372f);
    glVertex2f(0.479f,-0.482f);
    glVertex2f(0.467f,-0.482f);
    glEnd();
//15th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.490f,-0.361f);
    glVertex2f(0.502,-0.365f);
    glVertex2f(0.520f,-0.366f);
    glVertex2f(0.528f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.502,-0.365f);
    glVertex2f(0.520f,-0.366f);
    glVertex2f(0.516f,-0.372f);
    glVertex2f(0.502f,-0.372f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.502,-0.372f);
    glVertex2f(0.516f,-0.372f);
    glVertex2f(0.516f,-0.482f);
    glVertex2f(0.502,-0.482f);
    glEnd();

//16th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.528f,-0.361f);
    glVertex2f(0.537f,-0.366f);
    glVertex2f(0.558f,-0.366f);
    glVertex2f(0.567f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.537f,-0.366f);
    glVertex2f(0.558f,-0.366f);
    glVertex2f(0.556f,-0.373f);
    glVertex2f(0.539f,-0.373f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.539f,-0.373f);
    glVertex2f(0.556f,-0.373f);
    glVertex2f(0.556f,-0.482f);
    glVertex2f(0.539f,-0.482f);
    glEnd();
//17th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.567f,-0.361f);
    glVertex2f(0.576f,-0.366f);
    glVertex2f(0.597f,-0.366f);
    glVertex2f(0.605f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.576f,-0.366f);
    glVertex2f(0.597f,-0.366f);
    glVertex2f(0.594f,-0.373f);
    glVertex2f(0.578f,-0.373f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.578f,-0.373f);
    glVertex2f(0.594f,-0.373f);
    glVertex2f(0.594f,-0.482f);
    glVertex2f(0.578f,-0.482f);
    glEnd();

//18th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.605f,-0.361f);
    glVertex2f(0.614f,-0.366f);
    glVertex2f(0.635f,-0.367f);
    glVertex2f(0.645f,-0.361f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.614f,-0.366f);
    glVertex2f(0.635f,-0.367f);
    glVertex2f(0.633f,-0.373f);
    glVertex2f(0.617f,-0.373f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.617f,-0.373f);
    glVertex2f(0.633f,-0.373f);
    glVertex2f(0.633f,-0.482f);
    glVertex2f(0.617f,-0.482f);
    glEnd();

//Sides of Blue Lake//*******************************
//Land
    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-1,-1);
    glVertex2f(-0.899f,-0.886f);
    glVertex2f(-0.436f,-0.940f);
    glVertex2f(-0.142f,-0.986f);
    glVertex2f(0.06,-1);
    glEnd();
//Fence
    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.453f,-0.940f);
    glVertex2f(-0.453f,-0.914f);
    glVertex2f(-0.449f,-0.912f);
    glVertex2f(-0.441f,-0.912f);
    glVertex2f(-0.443f,-0.940f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.347f,-0.961f);
    glVertex2f(-0.348f,-0.914f);
    glVertex2f(-0.344f,-0.912f);
    glVertex2f(-0.336f,-0.912f);
    glVertex2f(-0.336f,-0.962f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.215f,-0.982f);
    glVertex2f(-0.216f,-0.922f);
    glVertex2f(-0.212f,-0.919f);
    glVertex2f(-0.204f,-0.919f);
    glVertex2f(-0.205f,-0.982f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.102f,-0.990f);
    glVertex2f(-0.102f,-0.922f);
    glVertex2f(-0.097f,-0.920f);
    glVertex2f(-0.091f,-0.920f);
    glVertex2f(-0.091f,-0.991f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.020f,-0.997f);
    glVertex2f(0.021f,-0.939f);
    glVertex2f(0.025f,-0.936f);
    glVertex2f(0.032f,-0.936f);
    glVertex2f(0.032f,-0.998f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.135,-1);
    glVertex2f(0.135f,-0.947f);
    glVertex2f(0.138f,-0.945f);
    glVertex2f(0.146f,-0.945f);
    glVertex2f(0.1465,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.259,-1);
    glVertex2f(0.259f,-0.954f);
    glVertex2f(0.262f,-0.952f);
    glVertex2f(0.270f,-0.952f);
    glVertex2f(0.2706,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.383,-1);
    glVertex2f(0.382f,-0.968f);
    glVertex2f(0.386f,-0.966f);
    glVertex2f(0.393f,-0.967f);
    glVertex2f(0.394,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.512,-1);
    glVertex2f(0.512f,-0.955f);
    glVertex2f(0.516f,-0.953f);
    glVertex2f(0.523f,-0.953f);
    glVertex2f(0.5237,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.632,-1);
    glVertex2f(0.632f,-0.956f);
    glVertex2f(0.635f,-0.953f);
    glVertex2f(0.643f,-0.953f);
    glVertex2f(0.6435,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.7768,-1);
    glVertex2f(0.776f,-0.976f);
    glVertex2f(0.78,-0.975);
    glVertex2f(0.787f,-0.974f);
    glVertex2f(0.788,-1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.469f,-0.925f);
    glVertex2f(-0.469f,-0.919f);
    glVertex2f(-0.342f,-0.922f);
    glVertex2f(-0.342f,-0.931f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.342f,-0.931f);
    glVertex2f(-0.342f,-0.922f);
    glVertex2f(-0.210f,-0.933f);
    glVertex2f(-0.210f,-0.942f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.210f,-0.942f);
    glVertex2f(-0.210f,-0.933f);
    glVertex2f(-0.096f,-0.935f);
    glVertex2f(-0.096f,-0.945f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.096f,-0.945f);
    glVertex2f(-0.096f,-0.935f);
    glVertex2f(0.027f,-0.949f);
    glVertex2f(0.027f,-0.958f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.027f,-0.958f);
    glVertex2f(0.027f,-0.949f);
    glVertex2f(0.141f,-0.957f);
    glVertex2f(0.141f,-0.966f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.141f,-0.966f);
    glVertex2f(0.141f,-0.957f);
    glVertex2f(0.265f,-0.970f);
    glVertex2f(0.265f,-0.980f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.265f,-0.980f);
    glVertex2f(0.265f,-0.970f);
    glVertex2f(0.387f,-0.979f);
    glVertex2f(0.388f,-0.991f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.388f,-0.991f);
    glVertex2f(0.387f,-0.979f);
    glVertex2f(0.517f,-0.975f);
    glVertex2f(0.517f,-0.986f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.517f,-0.986f);
    glVertex2f(0.517f,-0.975f);
    glVertex2f(0.638f,-0.973f);
    glVertex2f(0.638f,-0.982f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.638f,-0.982f);
    glVertex2f(0.638f,-0.973f);
    glVertex2f(0.782f,-0.988f);
    glVertex2f(0.782f,-0.997f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.782f,-0.997f);
    glVertex2f(0.782f,-0.988f);
    glVertex2f(0.88,-1);
    glVertex2f(0.793,-1);
    glEnd();


    //tree wood2
    glBegin(GL_QUADS);
    glColor3ub(29, 6, 0);
    glVertex2f(-0.69,-1);
    glVertex2f(-0.56,-1);
    glVertex2f(-0.56,-0.80);
    glVertex2f(-0.69,-0.80);
    glEnd();


    //tree wood
    glBegin(GL_QUADS);
    glColor3ub(29, 6, 0);
    glVertex2f(-0.85,-1);
    glVertex2f(-0.72,-1);
    glVertex2f(-0.72,-0.70);
    glVertex2f(-0.85,-0.70);
    glEnd();


    //tree2 leaf1
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.78,-0.85);
    glVertex2f(-0.47,-0.85);
    glVertex2f(-0.625,-0.70);
    glEnd();




//Dark Rock close
    glBegin(GL_POLYGON);
    glColor3ub(41, 54, 62);
    glVertex2f(-1,-1);
    glVertex2f(-0.8995326838053,-0.84);
    glVertex2f(-0.7632128497935,-0.82);
    glVertex2f(-0.4699186614649,-0.9193418854794);
    glVertex2f(-0.365,-1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.2101515676724,-0.9424292170789);
    glVertex2f(-0.2106543761129,-0.9338814735457);
    glVertex2f(-0.3428929959411,-0.9223168793538);
    glVertex2f(-0.3423901875007,-0.9318702397732);
    glEnd();

//1st Side Forest of Blue Lake
    glBegin(GL_POLYGON);
     glColor3ub(10, 48, 70);
    glVertex2f(-1,-0.4482623769432);
    glVertex2f(0.08032289841543,-0.4482623769432);
glColor3ub(20, 77, 110);
    glVertex2f(-0.1320390596915,-0.2541253303839);
    glVertex2f(-0.4734288362521,-0.2041253303839);

    glVertex2f(-0.6594300061514,-0.1800843628459);

    glVertex2f(-0.8707374576695,-0.1408596263365);
    glVertex2f(-1,-0.11);

    glEnd();

//2st Side Forest of Blue Lake
    glBegin(GL_POLYGON);


    glVertex2f(0.5422429702315,-0.4482623769432);
    glVertex2f(0.607145421979,-0.3349593212472);
    glColor3ub(20, 77, 110);
    glVertex2f(0.8327249542509,-0.2174623167401);
    glColor3ub(10, 48, 70);
    glVertex2f(0.8369149833822,-0.4482623769432);
    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(20, 77, 110);
    glVertex2f(0.8327249542509,-0.2174623167401);
    glVertex2f(0.8359102149068,-0.2072473867747);
    glColor3ub(20, 77, 110);
    glVertex2f(0.9996368118879,-0.1695879140117);
     glColor3ub(10, 48, 70);
    glVertex2f(1.0000691863567,-0.4482623769432);
    glVertex2f(0.8369149833822,-0.4482623769432);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(20, 77, 110);
    glVertex2f(0.8359102149068,-0.2072473867747);
    glVertex2f(0.8188751805996,-0.1846506759137);
    glVertex2f(0.8157897474026,-0.1630526435341);
    glVertex2f(0.8260745247262,-0.1385748735038);
    glVertex2f(0.8532263368606,-0.1385748735038);

    glVertex2f(0.8914857085046,-0.1389862645967);
    glVertex2f(0.9188432161855,-0.1315812249237);
    glVertex2f(1,-0.11);
    glVertex2f(0.9996368118879,-0.1695879140117);
    glEnd();





    //tree leaf9
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.86,-0.41);
    glVertex2f(-0.70,-0.41);
    glVertex2f(-0.785,-0.31);
    glEnd();

//tree leaf8
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.87,-0.46);
    glVertex2f(-0.69,-0.46);
    glVertex2f(-0.785,-0.31);
    glEnd();


    //tree leaf7
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.89,-0.51);
    glVertex2f(-0.67,-0.51);
    glVertex2f(-0.785,-0.36);
    glEnd();


    //tree leaf5
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.90,-0.56);
    glVertex2f(-0.66,-0.56);
    glVertex2f(-0.785,-0.35);
    glEnd();


    //tree leaf4
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.91,-0.60);
    glVertex2f(-0.65,-0.60);
    glVertex2f(-0.785,-0.30);
    glEnd();

    //tree leaf3
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.92,-0.66);
    glVertex2f(-0.64,-0.66);
    glVertex2f(-0.785,-0.38);
    glEnd();


    //tree leaf2
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.93,-0.72);
    glVertex2f(-0.63,-0.72);
    glVertex2f(-0.785,-0.40);
    glEnd();

//tree leaf1
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.94,-0.78);
    glVertex2f(-0.63,-0.78);
    glVertex2f(-0.785,-0.55);
    glEnd();



    //tree2 leaf5
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.725,-0.62);
    glVertex2f(-0.506,-0.62);
    glVertex2f(-0.625,-0.38);
    glEnd();


    //tree2 leaf5
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.735,-0.65);
    glVertex2f(-0.506,-0.65);
    glVertex2f(-0.625,-0.42);
    glEnd();


    //tree2 leaf4
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.745,-0.70);
    glVertex2f(-0.496,-0.70);
    glVertex2f(-0.625,-0.45);
    glEnd();

    //tree2 leaf3
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.755,-0.75);
    glVertex2f(-0.486,-0.75);
    glVertex2f(-0.625,-0.50);
    glEnd();


    //tree2 leaf2
    glBegin(GL_TRIANGLES);
    glColor3ub(11, 19, 30);
    glVertex2f(-0.765,-0.80);
    glVertex2f(-0.476,-0.80);
    glVertex2f(-0.625,-0.60);
    glEnd();



//Cover Bridge Using Blue Lake//*******************************
    glBegin(GL_QUADS);
    glColor3ub(64, 154, 202);
    glVertex2f(-0.080f,-0.448f);
    glVertex2f(0.842f,-0.448f);
    glVertex2f(0.842f,-0.848f);
    glVertex2f(-0.080f,-0.848f);
    glEnd();

    glPushMatrix();
    glTranslatef(-position3, 0,0);
//Fishing Boat//*******************************
//Boat
    glBegin(GL_QUADS);
    glColor3ub(36, 74, 100);
    glVertex2f(0.496f,-0.890f);
    glVertex2f(0.496f,-0.888f);
    glVertex2f(0.494f,-0.886f);
    glVertex2f(0.492f,-0.888f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.514f,-0.911f);
    glVertex2f(0.515f,-0.896f);
    glVertex2f(0.505f,-0.894f);
    glVertex2f(0.498f,-0.892f);
    glVertex2f(0.492f,-0.888f);
    glVertex2f(0.492f,-0.890f);
    glVertex2f(0.493f,-0.893f);
    glVertex2f(0.496f,-0.900f);
    glVertex2f(0.500f,-0.904f);
    glVertex2f(0.505f,-0.910f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.514f,-0.911f);
    glVertex2f(0.515f,-0.896f);
    glVertex2f(0.535f,-0.898f);
    glVertex2f(0.554f,-0.899f);
    glVertex2f(0.575f,-0.898f);
    glVertex2f(0.569f,-0.912f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.569f,-0.912f);
    glVertex2f(0.575f,-0.898f);
    glVertex2f(0.585f,-0.897f);
    glVertex2f(0.595f,-0.895f);
    glVertex2f(0.605f,-0.892f);
    glVertex2f(0.577f,-0.912f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.577f,-0.912f);
    glVertex2f(0.607f,-0.890f);
    glVertex2f(0.611f,-0.890f);
    glVertex2f(0.611f,-0.894f);
    glVertex2f(0.609f,-0.900f);
    glVertex2f(0.605f,-0.905f);
    glVertex2f(0.600f,-0.910f);
    glVertex2f(0.595f,-0.912f);
    glVertex2f(0.585f,-0.912f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.607f,-0.890f);
    glVertex2f(0.608f,-0.889f);
    glVertex2f(0.608f,-0.887f);
    glVertex2f(0.609f,-0.887f);
    glVertex2f(0.610f,-0.888f);
    glVertex2f(0.611f,-0.890f);
    glEnd();
//Human
    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.542f,-0.899f);
    glVertex2f(0.538f,-0.899f);
    glVertex2f(0.538f,-0.894f);
    glVertex2f(0.537f,-0.893f);
    glVertex2f(0.542f,-0.889f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.543f,-0.879f);
    glVertex2f(0.544f,-0.882f);
    glVertex2f(0.543f,-0.884f);
    glVertex2f(0.542f,-0.889f);
    glVertex2f(0.537f,-0.893f);
    glVertex2f(0.537f,-0.887f);
    glVertex2f(0.535f,-0.884f);
    glVertex2f(0.535f,-0.880f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.543f,-0.879f);
    glVertex2f(0.535f,-0.880f);
    glVertex2f(0.535f,-0.879f);
    glVertex2f(0.535f,-0.875f);
    glVertex2f(0.535f,-0.872f);
    glVertex2f(0.537f,-0.870f);
    glVertex2f(0.538f,-0.866f);
    glVertex2f(0.542f,-0.865f);
    glVertex2f(0.545f,-0.873f);
    glVertex2f(0.546f,-0.879f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(36, 74, 100);
    glVertex2f(0.538f,-0.866f);
    glVertex2f(0.537f,-0.864f);
    glVertex2f(0.541f,-0.863f);
    glVertex2f(0.542f,-0.865f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.541f,-0.863f);
    glVertex2f(0.537f,-0.864f);
    glVertex2f(0.536f,-0.864f);
    glVertex2f(0.535f,-0.861f);
    glVertex2f(0.536f,-0.860f);
    glVertex2f(0.534f,-0.859f);
    glVertex2f(0.537f,-0.858f);
    glVertex2f(0.538f,-0.857f);

    glVertex2f(0.540f,-0.856f);
    glVertex2f(0.542f,-0.858f);
    glVertex2f(0.543f,-0.860f);
    glVertex2f(0.542f,-0.861f);
    glEnd();
//Fishing Pol
    glBegin(GL_QUADS);
    glColor3ub(36, 74, 100);
    glVertex2f(0.535f,-0.879f);
    glVertex2f(0.490f,-0.846f);
    glVertex2f(0.490f,-0.843f);
    glVertex2f(0.535f,-0.877f);
    glEnd();

    glPopMatrix();

    glFlush();
}

void sound()
{
    PlaySound("train.wav", NULL, SND_ASYNC|SND_FILENAME);
}



void handleKeypress(unsigned char key, int x, int y)
{

	switch (key)
	{
        case 'w':
	    glLoadIdentity();
        glutDisplayFunc(night);
        glutPostRedisplay();
        break;

        case 's':
	    glLoadIdentity();
        glutDisplayFunc(sunset);
        glutPostRedisplay();
        break;

         case 'e':
            speed = 0.0f;
            break;

            case 'g':
            speed = 0.001f;
            break;

        case 27:     // ESC key
            exit(0);
            break;

        glutPostRedisplay();
	}
}


int main(int argc, char** argv)
{
    cout<<"\n            *************INSTRUCTIONS*************             \n";
    cout<<"Start Train: G \n";
    cout<<"Stop Train: E \n";

    cout<<"Select Night: W \n";
    cout<<"Select Sunset: S \n";

    cout<<"Exit Program: Esc ";

    glutInit(&argc, argv);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Sunset & Midnight Scenery");
    glutDisplayFunc(sunset);
    init();
    sound();
    glutKeyboardFunc(handleKeypress);

    glutTimerFunc(1000, update, 0);

    glutMainLoop();
    return 0;
}
