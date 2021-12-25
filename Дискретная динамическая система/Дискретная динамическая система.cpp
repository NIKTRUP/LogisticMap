#include <iostream>
#include "Дискретная динамическая система.h"
#include <vector>
#include <GLFW/glfw3.h>
#include <fstream>
using namespace std;

int main(void)
{
    /* с- положительный параметр, характеризующий скорость размножения (роста) популяции.
    
    Xn - принимает значения от 0 до 1 и
    отражает отношение значения популяции в n-ом году к максимально возможному, 
    а X0 обозначает начальную численность (в год номер 0); 
    */
    system("chcp 1251>nul");
    double h = 1e-4;
    double c = 2.9;
    vector<double> x;
    vector<double> c_vector;
    vector<double> x_out;   

    for (double i = c; i < 4.0; i += h) {
        x.emplace_back(0.6);
        for (int j = 0; j < 200; j++) {
            x.emplace_back(i * x[j] * (1.0 - x[j]));
            if (j > 150) {
                x_out.emplace_back(x[j]);
                c_vector.emplace_back(i);
            }
        }
        x.clear();
    }
    GLFWwindow* window;
    if (!glfwInit())
        return -1;
    window = glfwCreateWindow(1200, 800, "Logistic display", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT); 
        glColor3d(1.0, 1.0, 1.0); 
        glPointSize(1.0);
        glBegin(GL_POINTS);
        for (int i = 0; i < x_out.size(); i++) {
            glVertex2d(1.8*c_vector[i]-6.2, 1.8*x_out[i]-0.9);
        }
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
        glClearColor(0.2, 0.2, 0.2, 1.0);
    }
    glfwTerminate();
    return 0;
}
