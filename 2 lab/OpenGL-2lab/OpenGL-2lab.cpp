//#include <GLFW/glfw3.h>
//#include <Windows.h>
//#include <math.h>
//
//static float al;
//static float persp = 1;
//static float scale = 1;
//
//void Triangle() {
//    glBegin(GL_TRIANGLES);
//    glColor3f(1.0, 1.0, 0.0);
//    glVertex2f(-0.25f, -0.25f);
//    glColor3f(0.0, 0.0, 1.0);
//    glVertex2f(0.0f, 0.25f);
//    glColor3f(1.0, 1.0, 1.0);
//    glVertex2f(0.25f, -0.25f);
//    glEnd();
//}
//
//void Points() {
//    glPointSize(4);
//
//    glBegin(GL_POINTS);
//    glColor3f(0.0, 1.0, 0.0);
//    glVertex2f(0.0f, 0.5f);
//    glColor3f(0.0, 0.0, 1.0);
//    glVertex2f(0.5f, -0.5f);
//    glEnd();
//}
//
////void Circle() {
////    float c = 0.01;
////    float x, y;
////    float x1, y1;
////    float pnts = 40;
////    float l = 0.5;
////    float a = 3.14159265359 * 2 / pnts;
////    al -= 1;  //отвечает за угол поворота
////    persp -= 0.1; //отвечает за отдаление
////    //glRotatef(95, 0, 0, 1);
////    glPushMatrix();     //сохраняем текущую сист коорд в центре экрана
////        glTranslatef(0, -0.3, 0);  //сместили вниз
////        glRotatef(al, 0, 0, 1); //динамически поворачиваем
////        glTranslatef(0.3, 0, 0);    //после поворота в новой системе коорд смещаем вправо
////        glBegin(GL_TRIANGLE_FAN); //соединяет все последующие точки с первой
////        glColor3f(1, 1, 0);
////        glVertex2f(0, 0);
////        for (int i = -1; i < pnts; i++) {
////            if ( i<36) {
////                glColor3f(1, 1, 0);
////                x = sin(a * i) * l;
////                y = cos(a * i) * l;
////
////                glVertex3f(x, y, persp);
////            }
////            else {
////                glColor3f(0, 0, 0);
////                x = sin(a * i) * l;
////                y = cos(a * i) * l;
////                glVertex3f(x, y, persp);
////            }
////        }
////    glEnd();
////    glPopMatrix();
////
////}
////
//
////void CircleLitLit() {
////    float x, y;
////    float pnts = 40;
////    float l = 0.07;
////    float a = 3.14159265359 * 2 / pnts;
////    glPushMatrix();
////        glTranslatef(0, -0.25, 0);
////        glRotatef(al, 0, 0, 1);
////        glTranslatef(0.5, 0, 0);
////        glBegin(GL_TRIANGLE_FAN); //соединяет все последующие точки с первой
////        glColor3f(0, 0, 0);
////        glVertex2f(0, 0);
////        for (int i = -1; i < pnts; i++) {
////       
////            x = sin(a * i) * l;
////            y = cos(a * i) * l;
////            glVertex3f(x, y, persp);
////        }
////    glEnd();
////    glPopMatrix();
////}
//
//void Circle() {
//    float c = 0.01;
//    float x, y;
//    float x1, y1;
//    float pnts = 40;
//    float l = 0.3;
//    float a = 3.14159265359 * 2 / pnts;
//    al -= 1;  //отвечает за угол поворота
//    persp -= 0.1; //отвечает за отдаление
//    //glRotatef(95, 0, 0, 1);
//    glPushMatrix();     //сохраняем текущую сист коорд в центре экрана
//    glTranslatef(0, -0.3, 0);  //сместили вниз
//    glRotatef(al, 0, 0, 1); //динамически поворачиваем
//    glTranslatef(0.3, 0, 0);    //после поворота в новой системе коорд смещаем вправо
//    glBegin(GL_TRIANGLE_FAN); //соединяет все последующие точки с первой
//    glColor3f(1, 1, 0);
//    glVertex2f(0, 0);
//    for (int i = -1; i < pnts; i++) {
//        if (i < 36) {
//            glColor3f(1, 1, 0);
//            x = sin(a * i) * l;
//            y = cos(a * i) * l;
//
//            glVertex3f(x, y, 1);
//        }
//        else {
//            glColor3f(0, 0, 0);
//            x = sin(a * i) * l;
//            y = cos(a * i) * l;
//            glVertex3f(x, y, 1);
//        }
//    }
//    glEnd();
//    glPopMatrix();
//
//}
//
//void CircleLitLit() {
//    float x, y;
//    float pnts = 40;
//    float l = 0.05;
//    float a = 3.14159265359 * 2 / pnts;
//    glPushMatrix();
//    glTranslatef(0, -0.25, 0);
//    glRotatef(al, 0, 0, 1);
//    glTranslatef(0.5, 0, 0);
//    glBegin(GL_TRIANGLE_FAN); //соединяет все последующие точки с первой
//    glColor3f(0, 0, 0);
//    glVertex2f(0, 0);
//    for (int i = -1; i < pnts; i++) {
//
//        x = sin(a * i) * l;
//        y = cos(a * i) * l;
//        glVertex3f(x, y, 1);
//    }
//    glEnd();
//    glPopMatrix();
//}
//void RoundAround() {
//    al -= 2;
//    glPushMatrix();
//    glTranslatef(0, 0.3, 0);
//    glRotatef(al, 0, 0, 1);
//    glTranslatef(1, 0, 0);
//    Circle();
//    CircleLitLit();
//
//    glPopMatrix();
//}
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) //1- указатель на окно, 2 - кнопка, 3 - действие над клавишей, 4 - модификаторы
//{
//    // Когда пользователь нажимает ESC, мы устанавливаем свойство WindowShouldClose в true, 
//    // и приложение после этого закроется
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, GL_TRUE);
//}
//
//
//int main(void)
//{
//    GLFWwindow* window;
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(800, 800, "World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    //glOrtho(-2, 2, -2, 2, -1, 1); // Обновление размера начальной матрицы
//    glEnable(GL_DEPTH_TEST); //включение буфера глубины
//    glLoadIdentity();
//    glFrustum(-1, 1, -1, 1, 2, 6); //крайний параметр - расстояние от камеры до дальнего положения Z, предпосл - ближняя плоскость отсечения по оси Z. первые 4  -границы ближней плоскости отсечнеие Х и У
//    // от 2 до 6 видимый объем по Z
//    glTranslatef(0, 0, -2);
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))  //цикл, работающий пока окно не закрыто
//    {
//        glClearColor(0.3f, 0.2f, 0.1f, 0.1f);  //цвет зачистки
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//       
//        glTranslatef(0, 0, -0.05);
//
//        glBegin(GL_TRIANGLES);
//        glColor3f(0.0, 1.0, 0.0);
//        glVertex2f(-0.5f, -0.5f);
//        glVertex2f(0.0f, 0.5f);
//        glVertex2f(0.5f, -0.5f);
//        glEnd();
//
//        glPushMatrix();
//        glTranslatef(0.9, 0, -1);
//
//        glBegin(GL_TRIANGLES);
//        glColor3f(1.0, 1.0, 0.0);
//        glVertex2f(-0.5f, -0.5f);
//        glVertex2f(0.0f, 0.5f);
//        glVertex2f(0.5f, -0.5f);
//        glEnd();
//
//        glPopMatrix();
//        
//        glPushMatrix();
//        glLoadIdentity();
//        glTranslatef(0.0, 0.3, 0);
//        RoundAround();
//        glPopMatrix();
//
//        glPushMatrix(); //динамическое уменьшение фигуры 
//        scale -= 0.01;
//        glLoadIdentity();
//        glTranslatef(0.75, 0.75, 0);
//        glScalef(scale, scale, scale);
//        Triangle();
//        glPopMatrix();
//
//        //glfwSetScrollCallback(window, scroll_callback);
//        glfwSetKeyCallback(window, key_callback); //ф-я выхода на Еск
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//        Sleep(150);
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//    glfwTerminate();
//    return 0;
//}



#include <GLFW/glfw3.h>
#include <Windows.h>
#include <math.h>

static float al;
static float persp = 1;
static float scale = 1;

void Triangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(-0.25f, -0.25f);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0f, 0.25f);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.25f, -0.25f);
    glEnd();
}

void Circle() {
    float c = 0.01;
    float x, y;
    float x1, y1;
    float pnts = 40;
    float l = 0.3;
    float a = 3.14159265359 * 2 / pnts;
    al -= 1;  //отвечает за угол поворота
    persp -= 0.1; //отвечает за отдаление
    //glRotatef(95, 0, 0, 1);
    glPushMatrix();     //сохраняем текущую сист коорд в центре экрана
    glTranslatef(0, -0.3, 0);  //сместили вниз
    glRotatef(al, 0, 0, 1); //динамически поворачиваем
    glTranslatef(0.3, 0, 0);    //после поворота в новой системе коорд смещаем вправо
    glBegin(GL_TRIANGLE_FAN); //соединяет все последующие точки с первой
    glColor3f(1, 1, 0);
    glVertex2f(0, 0);
    for (int i = -1; i < pnts; i++) {
        if (i < 36) {
            glColor3f(1, 1, 0);
            x = sin(a * i) * l;
            y = cos(a * i) * l;

            glVertex3f(x, y, 1);
        }
        else {
            glColor3f(0, 0, 0);
            x = sin(a * i) * l;
            y = cos(a * i) * l;
            glVertex3f(x, y, 1);
        }
    }
    glEnd();
    glPopMatrix();

}

void CircleLitLit() {
    float x, y;
    float pnts = 40;
    float l = 0.05;
    float a = 3.14159265359 * 2 / pnts;
    glPushMatrix();
    glTranslatef(0, -0.25, 0);
    glRotatef(al, 0, 0, 1);
    glTranslatef(0.5, 0, 0);
    glBegin(GL_TRIANGLE_FAN); //соединяет все последующие точки с первой
    glColor3f(0, 0, 0);
    glVertex2f(0, 0);
    for (int i = -1; i < pnts; i++) {

        x = sin(a * i) * l;
        y = cos(a * i) * l;
        glVertex3f(x, y, 1);
    }
    glEnd();
    glPopMatrix();
}
void RoundAround() {
    al -= 2;
    glPushMatrix();
    glTranslatef(0, 0.3, 0);
    glRotatef(al, 0, 0, 1);
    glTranslatef(1, 0, 0);
    Circle();
    CircleLitLit();

    glPopMatrix();
}

void Pyramid() {
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 2);
    glVertex3f(1, 1, 0);
    glVertex3f(1, -1, 0);
    glVertex3f(-1, -1, 0);
    glVertex3f(-1, 1, 0);
    glVertex3f(1, 1, 0);
    glEnd();
}

void ShowWorld() {
   // glPushMatrix();
    scale -= 0.01;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            glPushMatrix();
            if ((i + j) % 2 == 0) glColor3f(0, 0.5, 0);
            else glColor3f(1, 1, 1);
            glTranslatef(i * 2, j * 2, 0);
                glBegin(GL_TRIANGLE_FAN);
                glVertex3f(-1, 1, 0);
                glVertex3f(1, 1, 0);
                glVertex3f(1, -1, 0);
                glVertex3f(-1, -1, 0);
                glEnd();
            glPopMatrix();
        }
    }
    glPushMatrix();
    glTranslatef(5,5,0);
        glRotatef(45, 0, 0, 1);
        glColor3f(0.5, 0.1, 0);
        Pyramid();
    glPopMatrix();

    glPushMatrix();
    if (scale ==  0) scale =1;
    glTranslatef(10, 10, 0);
    //glRotatef(45, 0, 0, 1);
    glScalef(cos(scale), cos(scale), cos(scale));
    glColor3f(0.7, 0.1, 0.9);
        Pyramid();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15, 15, 0);
    //glRotatef(45, 0, 0, 1);
    glRotatef(al, 0, 0, 1);
    glColor3f(1, 1, 0);
        Pyramid();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sin(scale)*(-10)+10, 0, 0);
    //glRotatef(45, 0, 0, 1);
    glColor3f(0, 0, 0.6);
        Pyramid();
    glPopMatrix();
}

float Xalfa = 20;
float Zalfa = 0;
POINTFLOAT pos = { 0,0 };
void MoveCamera() {
    if (GetKeyState(VK_UP) < 0) Xalfa = ++Xalfa > 180 ? 180 : Xalfa;
    if (GetKeyState(VK_DOWN) < 0) Xalfa = --Xalfa < 0 ? 0 : Xalfa;
    if (GetKeyState(VK_LEFT) < 0) Zalfa++;
    if (GetKeyState(VK_RIGHT) < 0) Zalfa--;

    float ugol = -Zalfa / 180 * 3.14;
    float speed = 0;
    if (GetKeyState('W') < 0) speed=0.1;
    if (GetKeyState('S') < 0) speed=-0.1;
    if (GetKeyState('A') < 0) {
        speed = 0.1; ugol -= 3.14 * 0.5;
    }
    if (GetKeyState('D') < 0) {
        speed = -0.1; ugol -= 3.14 * 0.5;
    }
    if (speed != 0) {
        pos.x += sin(ugol) * speed;
        pos.y += cos(ugol) * speed;
    }

    glRotatef(-Xalfa, 1, 0, 0);
    glRotatef(-Zalfa, 0, 0, 1);
    glTranslatef(-pos.x, -pos.y, -3);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) //1- указатель на окно, 2 - кнопка, 3 - действие над клавишей, 4 - модификаторы
{
    // Когда пользователь нажимает ESC, мы устанавливаем свойство WindowShouldClose в true, 
    // и приложение после этого закроется
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}


int main(void)
{
    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //glOrtho(-2, 2, -2, 2, -1, 1); // Обновление размера начальной матрицы
    glEnable(GL_DEPTH_TEST); //включение буфера глубины
    glFrustum(-1, 1, -1, 1, 2, 80); //крайний параметр - расстояние от камеры до дальнего положения Z, предпосл - ближняя плоскость отсечения по оси Z. первые 4  -границы ближней плоскости отсечнеие Х и У
    // от 2 до 6 видимый объем по Z
   // glTranslatef(0, 0, -6);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))  //цикл, работающий пока окно не закрыто
    {
        glClearColor(0.3f, 0.2f, 0.1f, 0.1f);  //цвет зачистки
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();
            MoveCamera();
            ShowWorld();
        glPopMatrix();

        //glRotatef(2, 1, 0, 0);
        //glTranslatef(0, 0, -0.05);
        glPushMatrix();
        glTranslatef(0.9, 0, -6);
        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.9, 0, -7);
        
            glBegin(GL_TRIANGLES);
            glColor3f(1.0, 1.0, 0.0);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f(0.0f, 0.5f);
            glVertex2f(0.5f, -0.5f);
            glEnd();
        glPopMatrix();
                
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(0.0, 0.3, 0);
        RoundAround();
        glPopMatrix();
        
        //glPushMatrix(); //динамическое уменьшение фигуры 
        //scale -= 0.01;
        //glLoadIdentity();
        //glTranslatef(0.75, 0.75, 0);
        //glScalef(scale, scale, scale);
        //Triangle();
        //glPopMatrix();













        //glfwSetScrollCallback(window, scroll_callback);
        glfwSetKeyCallback(window, key_callback); //ф-я выхода на Еск

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        Sleep(1);
        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
