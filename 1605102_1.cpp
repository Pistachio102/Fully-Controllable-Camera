#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <GL/glut.h>

#define pi (2*acos(0.0))


double angle;
int draw_axes;

struct point {
    double x, y, z;
};


struct pos {
    double x, y, z;
} camera_pos;


struct unit {
    double x, y, z;
} u, r, l;

void drawAxes() {
    if (draw_axes == 1) {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        {
            glVertex3f(100, 0, 0);
            glVertex3f(-100, 0, 0);

            glVertex3f(0, -100, 0);
            glVertex3f(0, 100, 0);

            glVertex3f(0, 0, 100);
            glVertex3f(0, 0, -100);
        }
        glEnd();
    }
}

void keyboardListener(unsigned char key, int x, int y) {
    switch (key) {

        case '1':
            l.x = l.x * cos(-angle) + r.x * sin(-angle);
            l.y = l.y * cos(-angle) + r.y * sin(-angle);
            l.z = l.z * cos(-angle) + r.z * sin(-angle);
            break;

        case '2':
            l.x = l.x * cos(angle) + r.x * sin(angle);
            l.y = l.y * cos(angle) + r.y * sin(angle);
            l.z = l.z * cos(angle) + r.z * sin(angle);
            break;

        case '3':
            unit prev_u;

            prev_u.x = u.x;
            prev_u.y = u.y;
            prev_u.z = u.z;

            u.x = u.x * cos(angle) + l.x * sin(angle);
            u.y = u.y * cos(angle) + l.y * sin(angle);
            u.z = u.z * cos(angle) + l.z * sin(angle);

            l.x = l.x * cos(angle) + prev_u.x * sin(angle);
            l.y = l.y * cos(angle) + prev_u.y * sin(angle);
            l.z = l.z * cos(angle) + prev_u.z * sin(angle);

            break;

        case '4':
            prev_u.x = u.x;
            prev_u.y = u.y;
            prev_u.z = u.z;

            u.x = u.x * cos(-angle) + l.x * sin(-angle);
            u.y = u.y * cos(-angle) + l.y * sin(-angle);
            u.z = u.z * cos(-angle) + l.z * sin(-angle);

            l.x = l.x * cos(-angle) + prev_u.x * sin(-angle);
            l.y = l.y * cos(-angle) + prev_u.y * sin(-angle);
            l.z = l.z * cos(-angle) + prev_u.z * sin(-angle);

            break;

        case '5':
            prev_u.x = u.x;
            prev_u.y = u.y;
            prev_u.z = u.z;

            u.x = u.x * cos(angle) + r.x * sin(angle);
            u.y = u.y * cos(angle) + r.y * sin(angle);
            u.z = u.z * cos(angle) + r.z * sin(angle);

            r.x = r.x * cos(angle) + prev_u.x * sin(angle);
            r.y = r.y * cos(angle) + prev_u.y * sin(angle);
            r.z = r.z * cos(angle) + prev_u.z * sin(angle);

            break;

        case '6':
            prev_u.x = u.x;
            prev_u.y = u.y;
            prev_u.z = u.z;

            u.x = u.x * cos(-angle) + r.x * sin(-angle);
            u.y = u.y * cos(-angle) + r.y * sin(-angle);
            u.z = u.z * cos(-angle) + r.z * sin(-angle);

            r.x = r.x * cos(-angle) + prev_u.x * sin(-angle);
            r.y = r.y * cos(-angle) + prev_u.y * sin(-angle);
            r.z = r.z * cos(-angle) + prev_u.z * sin(-angle);

            break;

        default:
            break;
    }
}


void specialKeyListener(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            camera_pos.y -= 1;
            break;
        case GLUT_KEY_DOWN:
            camera_pos.y += 1;
            break;
        case GLUT_KEY_RIGHT:
            camera_pos.x -= 1;
            break;
        case GLUT_KEY_LEFT:
            camera_pos.x += 1;
            break;

        case GLUT_KEY_PAGE_UP:
            camera_pos.z += 1;
            break;
        case GLUT_KEY_PAGE_DOWN:
            camera_pos.z -= 1;
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
            if (state == GLUT_DOWN) {        // 2 times?? in ONE click? -- solution is checking DOWN or UP
                draw_axes = 1 - draw_axes;
            }
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

void drawSquare(double a) {
    //glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    {
        glVertex3f(a, a, 2);
        glVertex3f(a, -a, 2);
        glVertex3f(-a, -a, 2);
        glVertex3f(-a, a, 2);
    }
    glEnd();
}

void drawCircle(double radius, int segments) {
    int i;
    struct point points[100];
    glColor3f(0.7, 0.7, 0.7);
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


void drawQuarterCircle(double radius, int segments) {
    int i;
    struct point points[100];
    glColor3f(0.7, 0.7, 0.7);
    //generate points

    for (int degree = 0; degree < 360; degree+= 3) {
        glPushMatrix();
        {
            glRotatef(degree, 0, 1, 0);

            glPushMatrix();
            {
                glRotatef(180, 0, 0, 1);
                for (i = 0; i <= segments; i++) {
                    points[i].x = radius * cos(((double) - i / (double) segments) * 2 * pi);
                    points[i].y = radius * sin(((double) - i / (double) segments) * 2 * pi);
                }
                //draw segments using generated points
                for (i = 0; i < segments / 4; i++) {
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
        glPopMatrix();
    }
}


void drawSphere(double radius, int slices, int stacks) {
    struct point points[100][100];
    int i, j;
    double h, r;
    //generate points
    for (i = 0; i <= stacks; i++) {
        h = radius * sin(((double) i / (double) stacks) * (pi / 2));
        r = radius * cos(((double) i / (double) stacks) * (pi / 2));
        for (j = 0; j <= slices; j++) {
            points[i][j].x = r * cos(((double) j / (double) slices) * 2 * pi);
            points[i][j].y = r * sin(((double) j / (double) slices) * 2 * pi);
            points[i][j].z = h;
        }
    }
    //draw quads using generated points
    for (i = 0; i < stacks; i++) {
        if (i % 2 == 0)
            glColor3f(1, 1, 1);
        else glColor3f(0, 0, 0);
        for (j = 0; j < slices; j++) {
            glBegin(GL_QUADS);
            {
                //upper hemisphere
                glVertex3f(points[i][j].x, points[i][j].y, points[i][j].z);
                glVertex3f(points[i][j + 1].x, points[i][j + 1].y, points[i][j + 1].z);
                glVertex3f(points[i + 1][j + 1].x, points[i + 1][j + 1].y, points[i + 1][j + 1].z);
                glVertex3f(points[i + 1][j].x, points[i + 1][j].y, points[i + 1][j].z);
                //lower hemisphere
                glVertex3f(points[i][j].x, points[i][j].y, -points[i][j].z);
                glVertex3f(points[i][j + 1].x, points[i][j + 1].y, -points[i][j + 1].z);
                glVertex3f(points[i + 1][j + 1].x, points[i + 1][j + 1].y, -points[i + 1][j + 1].z);
                glVertex3f(points[i + 1][j].x, points[i + 1][j].y, -points[i + 1][j].z);
            }
            glEnd();
        }
    }
}

void drawHalfSphere(double radius, int slices, int stacks) {
    struct point points[100][100];
    int i, j;
    double h, r;
    //generate points
    for (i = 0; i <= stacks; i++) {
        h = radius * sin(((double) i / (double) stacks) * (pi / 2));
        r = radius * cos(((double) i / (double) stacks) * (pi / 2));
        for (j = 0; j <= slices; j++) {
            points[i][j].x = r * cos(((double) j / (double) slices) * 2 * pi);
            points[i][j].y = r * sin(((double) j / (double) slices) * 2 * pi);
            points[i][j].z = h;
        }
    }
    //draw quads using generated points
    for (i = 0; i < stacks; i++) {
        if (i % 2 == 0)
            glColor3f(1, 1, 1);
        else glColor3f(0, 0, 0);
        for (j = 0; j < slices / 2; j++) {
            glBegin(GL_QUADS);
            {
                //upper hemisphere
                glVertex3f(points[i][j].x, points[i][j].y, points[i][j].z);
                glVertex3f(points[i][j + 1].x, points[i][j + 1].y, points[i][j + 1].z);
                glVertex3f(points[i + 1][j + 1].x, points[i + 1][j + 1].y, points[i + 1][j + 1].z);
                glVertex3f(points[i + 1][j].x, points[i + 1][j].y, points[i + 1][j].z);
                //lower hemisphere
                glVertex3f(points[i][j].x, points[i][j].y, -points[i][j].z);
                glVertex3f(points[i][j + 1].x, points[i][j + 1].y, -points[i][j + 1].z);
                glVertex3f(points[i + 1][j + 1].x, points[i + 1][j + 1].y, -points[i + 1][j + 1].z);
                glVertex3f(points[i + 1][j].x, points[i + 1][j].y, -points[i + 1][j].z);
            }
            glEnd();
        }
    }

}

void drawCylinder(double radius, double height, int slices, int stacks) {
    struct point points[100][100];
    int i, j;
    double h, r;
    //generate points

    r = radius;
    for (i = 0; i <= stacks; i++) {
        h = height * sin(((double) i / (double) stacks) * (pi / 2));

        for (j = 0; j <= slices; j++) {
            points[i][j].x = r * cos(((double) j / (double) slices) * 2 * pi);
            points[i][j].y = r * sin(((double) j / (double) slices) * 2 * pi);
            points[i][j].z = h;
        }
    }
    //draw quads using generated points
    for (i = 0; i < stacks; i++) {

        for (j = 0; j < slices; j++) {
            if (j % 2 == 0)
                glColor3f(1, 1, 1);
            else glColor3f(0, 0, 0);
            glBegin(GL_QUADS);
            {
                //upper hemisphere
                glVertex3f(points[i][j].x, points[i][j].y, points[i][j].z);
                glVertex3f(points[i][j + 1].x, points[i][j + 1].y, points[i][j + 1].z);
                glVertex3f(points[i + 1][j + 1].x, points[i + 1][j + 1].y, points[i + 1][j + 1].z);
                glVertex3f(points[i + 1][j].x, points[i + 1][j].y, points[i + 1][j].z);
                //lower hemisphere
                glVertex3f(points[i][j].x, points[i][j].y, -points[i][j].z);
                glVertex3f(points[i][j + 1].x, points[i][j + 1].y, -points[i][j + 1].z);
                glVertex3f(points[i + 1][j + 1].x, points[i + 1][j + 1].y, -points[i + 1][j + 1].z);
                glVertex3f(points[i + 1][j].x, points[i + 1][j].y, -points[i + 1][j].z);
            }
            glEnd();
        }
    }
}


void drawSS() {


    drawSphere(40,100,30);

    glTranslatef(0, 60, 0);
    glRotatef(180, 1, 0,0);
    drawHalfSphere(20, 100, 30);
    glRotatef(90, 1, 0,0);
    glTranslatef(0,0,60);
    drawCylinder(20,60,100,60);
//    glRotatef(90, 0, 1, 0);
//    glTranslatef(0, 40, 80);
//    drawQuarterCircle(20, 30);

//    glColor3f(1,0,0);

//    glRotatef(angle,0,0,1);
//    glTranslatef(110,0,0);
//    glRotatef(2*angle,0,0,1);
//    glColor3f(0,1,0);
//    drawSquare(15);
//
//    glPushMatrix();
//    {
//        glRotatef(angle,0,0,1);
//        glTranslatef(60,0,0);
//        glRotatef(2*angle,0,0,1);
//        glColor3f(0,0,1);
//        drawSquare(10);
//    }
//    glPopMatrix();
//
//    glRotatef(3*angle,0,0,1);
//    glTranslatef(40,0,0);
//    glRotatef(4*angle,0,0,1);
//    glColor3f(1,1,0);
//    drawSquare(5);
//
//    drawCircle(10, 50);
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

    gluLookAt(camera_pos.x, camera_pos.y, camera_pos.z, camera_pos.x + l.x, camera_pos.y + l.y, camera_pos.z + l.z, u.x,
              u.y, u.z);


    //again select MODEL-VIEW
    glMatrixMode(GL_MODELVIEW);


    /****************************
    / Add your objects from here
    ****************************/
    //add objects

    drawAxes();


    drawSS();
    //ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
    glutSwapBuffers();
}


void animate() {
    //codes for any changes in Models, Camera

    glutPostRedisplay();
}

void init() {
    //codes for initialization

    angle = 0.03;
    draw_axes = 1;
    camera_pos = {100, 100, 0};
    u = {0, 0, 1};
    r = {-1 * cos(pi / 4), cos(pi / 4), 0};
    l = {-1 * cos(pi / 4), -1 * cos(pi / 4), 0};

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
