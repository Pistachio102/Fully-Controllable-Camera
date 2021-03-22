//#include<stdio.h>
//#include<stdlib.h>
#include<random>
#include<cmath>

//#include <windows.h>
#include <GL/glut.h>

#define pi (2 * acos(0.0))

#define LOWEST_SPEED 0.01

#define HIGHEST_SPEED 0.1

bool flag[5], pause;

double squareHalfSides, bigCircleRadius, smallCircleRadius;

struct point {
    double x, y, z;
} center[5], velocity[5], direction[5];

void drawHollowSquare(double a) {
    glBegin(GL_LINES);
    {
        glVertex3f(a, a, 0);
        glVertex3f(a, -a, 0);

        glVertex3f(a, -a, 0);
        glVertex3f(-a, -a, 0);

        glVertex3f(-a, -a, 0);
        glVertex3f(-a, a, 0);

        glVertex3f(-a, a, 0);
        glVertex3f(a, a, 0);
    }
    glEnd();
}

void drawCircle(double radius, int segments) {
    int i;
    struct point points[100];
    //glColor3f(0.7,0.7,0.7);

    //generate points
    for (i = 0; i <= segments; i++) {
        points[i].x = radius * cos(((double) i / (double) segments) * 2 * pi);
        points[i].y = radius * sin(((double) i / (double) segments) * 2 * pi);
    }

    //draw segments using generated points
    for (i = 0; i < segments; i++) {
        glBegin(GL_LINES);
        {
            glVertex3f(points[i].x, points[i].y, 0);
            glVertex3f(points[i + 1].x, points[i + 1].y, 0);
        }
        glEnd();
    }
}


void drawSmallCircle(point centerParam, double radius, int segments) {
    int i;
    struct point points[100];
    //glColor3f(0.7,0.7,0.7);

    //adjusting to new centre

    glPushMatrix();
    {
        glTranslatef(centerParam.x, centerParam.y, centerParam.z);
        //generate points
        for (i = 0; i <= segments; i++) {
            points[i].x = radius * cos(((double) i / (double) segments) * 2 * pi);
            points[i].y = radius * sin(((double) i / (double) segments) * 2 * pi);
        }

        //draw segments using generated points
        for (i = 0; i < segments; i++) {
            glBegin(GL_LINES);
            {
                glVertex3f(points[i].x, points[i].y, 0);
                glVertex3f(points[i + 1].x, points[i + 1].y, 0);
            }
            glEnd();
        }
    }
    glPopMatrix();

}

void drawSystem() {
    //draw boundary square
    glColor3f(0, 1, 0);
    drawHollowSquare(squareHalfSides);

    //draw inside big circle
    glColor3f(1, 0, 0);
    drawCircle(bigCircleRadius, 80);

    //draw small circles
    glColor3f(1, 0, 0.5);
    for (auto & i : center) {
        drawSmallCircle(i, smallCircleRadius, 50);
    }
}

void keyboardListener(unsigned char key, int x, int y) {
    switch (key) {
        case 'p':
            pause = !pause;

        default:
            break;
    }
}


void specialKeyListener(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_DOWN:
            for (int i = 0; i < 5; i++) {
                velocity[i].x -= 0.01;
                velocity[i].y -= 0.01;
                if (velocity[i].x < LOWEST_SPEED )
                {
                    velocity[i].x = LOWEST_SPEED;
                }
                if (velocity[i].y < LOWEST_SPEED )
                {
                    velocity[i].y = LOWEST_SPEED;
                }
            }
            break;
        case GLUT_KEY_UP:
            for (int i = 0; i < 5; i++) {
                velocity[i].x += 0.01;
                velocity[i].y += 0.01;
                if (velocity[i].x > HIGHEST_SPEED )
                {
                    velocity[i].x = HIGHEST_SPEED;
                }
                if (velocity[i].y > HIGHEST_SPEED )
                {
                    velocity[i].y = HIGHEST_SPEED;
                }

            }
            break;

        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_LEFT:
            break;

        case GLUT_KEY_PAGE_UP:
            break;
        case GLUT_KEY_PAGE_DOWN:
            break;

        case GLUT_KEY_INSERT:
            break;

        case GLUT_KEY_HOME:
            break;
        case GLUT_KEY_END:
            break;

        default:
            break;
    }
}


void mouseListener(int button, int state, int x, int y) {    //x, y is the x-y of the screen (2D)
    switch (button) {
        case GLUT_LEFT_BUTTON:
            break;

        case GLUT_RIGHT_BUTTON:
            //........
            break;

        case GLUT_MIDDLE_BUTTON:
            //........
            break;

        default:
            break;
    }
}


void display() {

    //clear the display
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);    //color black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /********************
    / set-up camera here
    ********************/
    //load the correct matrix -- MODEL-VIEW matrix
    glMatrixMode(GL_MODELVIEW);

    //initialize the matrix
    glLoadIdentity();

    //now give three info
    //1. where is the camera (viewer)?
    //2. where is the camera looking?
    //3. Which direction is the camera's UP direction?

    gluLookAt(0, 0, 200, 0, 0, 0, 0, 1, 0);


    //again select MODEL-VIEW
    glMatrixMode(GL_MODELVIEW);


    /****************************
    / Add your objects from here
    ****************************/

    drawSystem();

    //ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
    glutSwapBuffers();
}

void animate() {
    //codes for any changes in Models, Camera
    if (!pause)
    {
        for (int i = 0; i < 5; ++i) {
            point temp_direction = direction[i];

            if (!flag[i])
            {
                if (abs(center[i].x) > (squareHalfSides - smallCircleRadius))
                {
                    temp_direction.x *= -1;
                }
                if (abs(center[i].y) > (squareHalfSides - smallCircleRadius))
                {
                    temp_direction.y *= -1;
                }
                if ((sqrt(pow(center[i].x, 2) + pow(center[i].y, 2)) <= (bigCircleRadius - smallCircleRadius)))
                {
                    flag[i] = true;
                }
            }

            if (flag[i])
            {
                if (sqrt(pow(center[i].x, 2) + pow(center[i].y, 2)) > (bigCircleRadius - smallCircleRadius))
                {
                    point n = {};
                    n.x = - center[i].x;
                    n.y = - center[i].y;

                    n.x = (n.x / sqrt(pow(center[i].x, 2) + pow(center[i].y, 2)));
                    n.y = (n.y / sqrt(pow(center[i].x, 2) + pow(center[i].y, 2)));

                    double d_dot_n =  (temp_direction.x * n.x) + (temp_direction.y * n.y);

                    temp_direction.x = temp_direction.x - 2 * d_dot_n * n.x;
                    temp_direction.y = temp_direction.y - 2 * d_dot_n * n.y;

                }

            }

            direction[i].x = temp_direction.x;
            direction[i].y = temp_direction.y;

            for (int j = 0; j < 5; j++) {
                if (j == i)
                {
                    continue;
                }

                if (flag[i])
                {
                    temp_direction = direction[i];
                    if (sqrt(pow(center[i].x - center[j].x, 2) + pow(center[i].y - center[j].y, 2)) <= 2 * smallCircleRadius)
                    {
                        point temp_n = {};
                        point n = {};
                        temp_n.x = center[j].x - center[i].x;
                        temp_n.y = center[j].y - center[i].y;

                        n.x = (temp_n.x / sqrt(pow(temp_n.x, 2) + pow(temp_n.y, 2)));
                        n.y = (temp_n.y / sqrt(pow(temp_n.x, 2) + pow(temp_n.y, 2)));

                        double d_dot_n =  (temp_direction.x * n.x) + (temp_direction.y * n.y);

                        temp_direction.x = temp_direction.x - 2 * d_dot_n * n.x;
                        temp_direction.y = temp_direction.y - 2 * d_dot_n * n.y;
                    }

                    direction[i].x = temp_direction.x;
                    direction[i].y = temp_direction.y;
                }
            }
            center[i].x += velocity[i].x * direction[i].x;
            center[i].y += velocity[i].y * direction[i].y;
        }
    }
    glutPostRedisplay();
}

void init() {
    //codes for initialization

    squareHalfSides = 100;
    bigCircleRadius = 50;
    smallCircleRadius = 10;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist[5];

    pause = false;

    for(int i = 0; i < 5; i++)
    {
        dist[i] = std::uniform_real_distribution<double> (18 * i, 18 * (i + 1));
        double angle = dist[i](mt);
        direction[i].x = cos(angle * pi / 180);
        direction[i].y = sin(angle * pi / 180);

        flag[i] = false;

        velocity[i].x = 0.05;
        velocity[i].y = 0.05;

        center[i].x = -1 * (squareHalfSides - smallCircleRadius);
        center[i].y = -1 * (squareHalfSides - smallCircleRadius);
    }

    //clear the screen
    glClearColor(0, 0, 0, 0);

    /************************
    / set-up projection here
    ************************/
    //load the PROJECTION matrix
    glMatrixMode(GL_PROJECTION);

    //initialize the matrix
    glLoadIdentity();

    //give PERSPECTIVE parameters
    gluPerspective(80, 1, 1, 1000.0);
    //field of view in the Y (vertically)
    //aspect ratio that determines the field of view in the X direction (horizontally)
    //near distance
    //far distance
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);    //Depth, Double buffer, RGB color

    glutCreateWindow("My OpenGL Program");

    init();

    glEnable(GL_DEPTH_TEST);    //enable Depth Testing

    glutDisplayFunc(display);    //display callback function
    glutIdleFunc(animate);        //what you want to do in the idle time (when no drawing is occurring)

    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyListener);
    glutMouseFunc(mouseListener);

    glutMainLoop();        //The main loop of OpenGL

    return 0;
}
