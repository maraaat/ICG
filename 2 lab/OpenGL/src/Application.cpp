#include <GLFW/glfw3.h>

void Triangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.25f, -0.25f);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0f, 0.25f);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.25f, -0.25f);
    glEnd();
}
void Points() {
     glPointSize(5);

     glBegin(GL_POINTS);
     glColor3f(0.0, 1.0, 0.0);
     glVertex2f(0.0f, 0.5f);
     glColor3f(0.0, 0.0, 1.0);
     glVertex2f(0.5f, -0.5f);
     glColor3f(1.0, 0.0, 1.0);
     glVertex2f(-0.5f, -0.5f);
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
    window = glfwCreateWindow(800, 600, "World", NULL, NULL);
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
        //Points();
        //Triangle();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  //цвет зачистки
        glClear(GL_COLOR_BUFFER_BIT);
       
        //for (int i = 0; i < 10; i++) {
        //    
        //    //glLoadIdentity();  //единичная матрица, к-я возвращет с-му коорд в исх состояние
        //    
        //   // glPushMatrix(); //сохраняем текущую матрицу в стек
        //    glRotatef(45*i, 0, 0, 1);
        //    glTranslatef(0.5, 0, 0);
        //    Triangle();
        //    Points();
        //    //glPopMatrix(); //загружаем состояние матрицы, к-ое было в начале цикла
        //}


        //for (int i = 0; i < 10; i++) {

        //    //glLoadIdentity();  //единичная матрица, к-я возвращет с-му коорд в исх состояние

        //   // glPushMatrix(); //сохраняем текущую матрицу в стек
        //    //glRotatef(45 * i, 0, 0, 1);
        //    Triangle();
        //    glTranslatef(0.5, 0, 0);
        //   // Triangle();
        //   // Points();
        //    //glPopMatrix(); //загружаем состояние матрицы, к-ое было в начале цикла
        //}

       // glTranslatef(0.5, 0.0, 0.0);
        //Triangle();
        

        glRotatef(45, 0, 0, 1);
        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.1f, -0.25f);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.5f, 0.25f);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(0.25f, -0.25f);
        glEnd();
        glRotatef(1, 0, 0, 10);
        glPopMatrix();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.1f, -0.25f);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.5f, 0.25f);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(0.25f, -0.25f);
        glEnd();










        glfwSetKeyCallback(window, key_callback); //ф-я выхода на Еск
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Проверяет, были ли вызваны какие-либо события*/
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

