#include <GLFW/glfw3.h>
#include <Windows.h>
#include <math.h>

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

void Points() {
    glPointSize(4);

    glBegin(GL_POINTS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.5f, -0.5f);
    glEnd();
}

void Circle() {
    float c = 0.01;
    float x, y;
    float x1, y1;
    float pnts = 40;
    float l = 0.5;
    float a = 3.14159265359 * 2 / pnts;
    glRotatef(95, 0, 0, 1);
   // glPushMatrix();
    glBegin(GL_TRIANGLE_FAN); //соединяет все последующие точки с первой
        //glColor3f(1, 1, 0);
        glVertex2f(0, 0);
        for (int i = -1; i < pnts; i++) {
            glColor3f(c + 0.01 * i, c + 0.01 * i, c + 0.01 * i);
            x = sin(a * i) * l;
            y = cos(a * i) * l;
            glVertex2f(x, y);
        }
    glEnd();
    //// glLoadIdentity();
    //glPopMatrix();
    //glClear(GL_COLOR_BUFFER_BIT);
    //// glPushMatrix();
    //glBegin(GL_TRIANGLE_FAN); //соединяет все последующие точки с первой
    //glColor3f(1, 1, 0);
    //glVertex2f(0, 0);
    //for (int i = 1; i < pnts; i++) {
    //    x1 = sin(a * i) * l;
    //    y1 = cos(a * i) * l;
    //    glVertex2f(x1, y1);
    //}
    //glEnd();
    //glPopMatrix();
    //glClear(GL_COLOR_BUFFER_BIT);
}

void CircleLitLit() {
    float x, y;
    float pnts = 40;
    float l = 0.07;
    float a = 3.14159265359 * 2 / pnts;
    glTranslatef(0.25, 0, 0);
    glBegin(GL_TRIANGLE_FAN); //соединяет все последующие точки с первой
    glColor3f(0, 0, 0);
    glVertex2f(0, 0);
    for (int i = -1; i < pnts; i++) {
        x = sin(a * i) * l;
        y = cos(a * i) * l;
        glVertex2f(x, y);
    }
    glEnd();
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
    window = glfwCreateWindow(800, 800, "World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))  //цикл, работающий пока окно не закрыто
    {

        glClearColor(0.9f, 0.6f, 0.5f, 1.0f);  //цвет зачистки
        glClear(GL_COLOR_BUFFER_BIT);

     

       glRotatef(45, 0, 0, 1);
       // glTranslatef(-0.01, 0, 0);
        
        glPushMatrix();
        Circle();
        CircleLitLit();
        //glLoadIdentity();
        glTranslatef(0.01, 0, 0);
        glPushMatrix();
      

        /*glPushMatrix();*/
        //glLoadIdentity();
        
        //glRotatef(45, 0, 0, 1);
        //glTranslatef(-0.5, -0.5, 0);
        //CircleLitLit();
        glPopMatrix();




        glfwSetKeyCallback(window, key_callback); //ф-я выхода на Еск

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        Sleep(100);
        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

//glPolygonMode(GL_FRONT, GL_FILL);  //обратные грани в виде линий по границе
//glPolygonMode(GL_BACK, GL_LINE); //лицевые грани в виде заливки
// 
//glLoadIdentity();  //единичная матрица, к-я возвращет с-му коорд в исх состояние

//glRotatef(45 * i, 0, 0, 1); //1 - угол, 2-4 --- X,Y,Z