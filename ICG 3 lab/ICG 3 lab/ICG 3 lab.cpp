#include <GLFW/glfw3.h>
#include <Windows.h>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include "C:/Users/Asus/source/repos/stb-master/stb_image.h"

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

unsigned int texture, texture2, white;

void LoadTexture(const char *filename, unsigned int *textureID) {
    int wi, hi, cnt;

    //загрузка фото, со считыванием всех данных
    unsigned char* data = stbi_load(filename, &wi, &hi, &cnt, 0); 

    glGenTextures(1, textureID); //создаем указ-ое кол-во текстур
    glBindTexture(GL_TEXTURE_2D, *textureID); //делаем текстуру активной, 1 -тип текстуры, 2 - номер текстуры
    
    //задаем как текстура д.б. наложена:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, cnt==4? GL_RGBA : GL_RGB, wi, hi, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); 
    //позволяет загрузить текстуры из массива в видеокарту

    glBindTexture(GL_TEXTURE_2D, 0); //нет активных текстур
    stbi_image_free(data); //o4istka video
}


void UseTextures() {

    LoadTexture("sand.png", &texture);
    LoadTexture("stone.png", &texture2);
    LoadTexture("01.png", &white);

}

float vertex[] = { 0,0,5, 3,3,0, 3,-3,0,  -3,-3,0, -3,3,0, 3,3,0 };  //задание координат фигуры - тут пирамида
float texCoord[] = { 1,0, 0,1, 1,1, 0,1, 1,1 }; //текстурные координаты
GLuint texInd[] = {0,1,2, 0,2,3, 0,3,4, 0,4,1};
int texIndCnt = sizeof(texInd) / sizeof(GLuint);

float vertex2[] = { 0,0,2, 1,1,0, 1,-1,0,  -1,-1,0, -1,1,0, 1,1,0 };

float vertextobase[] = { 0,0,0, 0,0,0, 0,0,0,  0,0,0, 0,0,0, 0,0,0 };

void Texture(unsigned int textureID, float vertex[], float texCoord[], GLuint texInd[], int texIndCnt) {
    glEnable(GL_TEXTURE_2D); //включает текстурирование
    glColor3f(1, 1, 1);

    glPushMatrix();

    glEnableClientState(GL_VERTEX_ARRAY); //вкл режима 
    //работа с массивом текстурных координат
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);


    glVertexPointer(3, GL_FLOAT, 0, vertex);
    //указывает адрес масива, откуда брать текстурные коорд
    glTexCoordPointer(2, GL_FLOAT, 0, texCoord);


    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, textureID);
        glDrawElements(GL_TRIANGLE_FAN, texIndCnt, GL_UNSIGNED_INT, texInd);
    glPopMatrix();


    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glPopMatrix();

}


float X_alfa = 20;
float Z_alfa = 0;
POINTFLOAT pos = { 0,0 };
void MoveCamera() {
    if (GetKeyState(VK_UP) < 0) X_alfa = ++X_alfa > 180 ? 180 : X_alfa;
    if (GetKeyState(VK_DOWN) < 0) X_alfa = --X_alfa < 0 ? 0 : X_alfa;
    if (GetKeyState(VK_LEFT) < 0) Z_alfa++;
    if (GetKeyState(VK_RIGHT) < 0) Z_alfa--;

    float ugol = -Z_alfa / 180 * 3.14;
    float speed = 0;
    if (GetKeyState('W') < 0) speed = 0.1;
    if (GetKeyState('S') < 0) speed = -0.1;
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

    glRotatef(-X_alfa, 1, 0, 0);
    glRotatef(-Z_alfa, 0, 0, 1);
    glTranslatef(-pos.x, -pos.y, -3);
}

void ShowWorld() {
    // glPushMatrix();
    glNormal3f(0, 0, 1);
    scale -= 0.01;

    for (int i = 0; i < 25; i++) { //создание плоского пространства в клеточку
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


    glPushMatrix();  //статическая пирамида
        glTranslatef(0, 5, 0);
        glRotatef(45, 0, 0, 1);
        glColor3f(0.5, 0.1, 0);
        Pyramid();
    glPopMatrix();

    glPushMatrix();  //пирамида, с меняющимся масштабом
        if (scale == 0) scale = 1;
        glTranslatef(0, 10, 0);
        glScalef(cos(scale), cos(scale), cos(scale));
        glColor3f(0.7, 0.1, 0.9);
        Pyramid();
    glPopMatrix();

    glPushMatrix(); //вращающаяся пирамида
        glTranslatef(0, 15, 0);
        glRotatef(al, 0, 0, 1);
        glColor3f(1, 1, 0);
        glBegin(GL_TRIANGLE_FAN); //задано без функции для палитры
        glVertex3f(0, 0, 2);
        glColor3f(0.1, 0.7, 0);
        glVertex3f(1, 1, 0);
        glColor3f(1, 0, 0.7);
        glVertex3f(1, -1, 0);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-1, -1, 0);
        glColor3f(0, 0, 0.3);
        glVertex3f(-1, 1, 0);
        glColor3f(0.3, 0, 0);
        glVertex3f(1, 1, 0);
        glEnd();
    glPopMatrix();

    glPushMatrix(); //движущаяся пирамида
        glTranslatef(0, 0, 0);
        glTranslatef(0, sin(scale) * (-10) + 10, 0);
        glColor3f(0, 0, 0.6);
        Pyramid();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5, 0, 0);
        Texture(texture2, vertex2, texCoord, texInd, texIndCnt);
    glPopMatrix();

    glPushMatrix(); 
    
        glTranslatef(10, 10, 0);
        Texture(texture, vertex, texCoord, texInd, texIndCnt);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 0, -2);
        Texture(white, vertextobase, texCoord, texInd, texIndCnt);
    glPopMatrix();

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

    glEnable(GL_DEPTH_TEST); //включение буфера глубины
    glFrustum(-1, 1, -1, 1, 2, 80); //крайний параметр - расстояние от камеры до дальнего положения Z, предпосл - ближняя плоскость отсечения по оси Z. первые 4  -границы ближней плоскости отсечнеие Х и У
    // от 2 до 80 видимый объем по Z

    GLfloat lmodel_ambient[] = { 0.2,0.2,0.2,1.0 };  //back color 
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

    glEnable(GL_LIGHTING); //разрешаем работу с освещением
    glEnable(GL_LIGHT0); //вкл нулевой источник света
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    UseTextures();
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))  //цикл, работающий пока окно не закрыто
    {
        glClearColor(0.3f, 0.2f, 0.1f, 0.1f);  //цвет зачистки
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 
        static float theta = 0;

        theta += 0.3;
        if (theta > 180) theta -= 360;

        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
         
            MoveCamera();
            ShowWorld();
            glPushMatrix();
                glRotatef(theta, 0, 1, 0);
                float position[] = { 0,1,1,0 }; //источник света
                glLightfv(GL_LIGHT0, GL_POSITION, position); //параметры для нулевого источника света
            glPopMatrix();
                

            glPushMatrix(); //point light

                GLfloat light2_diffuse[] = { 0.4, 0.7, 0.2 };
                GLfloat light2_position[] = { 17.0, 8.0, 1.0, 1.0 };
                GLfloat spec[] = { 0,1,1.0,1.0 };
                GLfloat specdop[] = { 1.0,1.0,1.0,1.0 };
                glEnable(GL_LIGHT1);

                glLightfv(GL_LIGHT1, GL_DIFFUSE, light2_diffuse);
                glLightfv(GL_LIGHT1, GL_POSITION, light2_position);
                glLightfv(GL_LIGHT1, GL_SPECULAR, spec);
                glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.2);
                glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 3);
                glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.05);
                glMateriali(GL_FRONT, GL_SHININESS, 1);
                glMaterialfv(GL_FRONT, GL_SPECULAR, specdop);

                glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
            glPopMatrix();

            glPushMatrix();
            

                GLfloat light5_diffuse[] = { 1.0, 0.0, 0.0 };
                GLfloat light5_position[] = { 5, 13, 1.0, 1.0 };
                glEnable(GL_LIGHT5);
   
                glLightfv(GL_LIGHT5, GL_DIFFUSE, light5_diffuse);
                glLightfv(GL_LIGHT5, GL_POSITION, light5_position);
                glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, 0.0);
                glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 3);
                glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 0.1);

            glPopMatrix();

            glPushMatrix(); //projector


                GLfloat light4_diffuse[] = { 0.4, 0.7, 0.2 };
                GLfloat light4_position[] = { 3.0, 3.0, 1.0, 1.0 };
                GLfloat light4_spot_direction[] = { 0, 0, -1 };

                glEnable(GL_LIGHT4);
                glLightfv(GL_LIGHT4, GL_DIFFUSE, light4_diffuse); //color
                glLightfv(GL_LIGHT4, GL_POSITION, light4_position); //light pos
                glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 80); //угол между осью и стороной конуса (он же половина угла при вершине)
                glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light4_spot_direction); // направление прожектора (ось ограничивающего конуса
                glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 30); //	экспонента убывания интенсивности
            glPopMatrix();



        glPopMatrix();
        
        
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
