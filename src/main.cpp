#define GLEW_STATIC
#include <iostream>
#include <GL\glew.h>
#include <Shar\headers\sharinit.h>
#include <Shar\headers\sharfun.h>
#include <GLFW\glfw3.h>


#include <sh_shapes.h>
#include <sh_circle.h>
#include <sh_camera3D.h>
#include <grid.h>

#include <cmath>

#define SCREEN_SIZE_X 500
#define SCREEN_SIZE_Y 500


using namespace std;

//functions
GLFWwindow* init();
bool colid(sh_rect &a, sh_rect &b);
void keys(GLFWwindow *window, int key, int action, int state, int some);

int main(int argc, char ** argv) {
    GLFWwindow *window = init();
    
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    vec2 cnet(0, 0);
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec2), &cnet, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    // glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    sh_circle t;
    sh_rect l;
    while(!glfwWindowShouldClose(window)) {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        glClear(GL_COLOR_BUFFER_BIT);
        // glDrawArrays(GL_POINTS, 0, 1);
        // t.render();
        l.render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}


GLFWwindow* init() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);



    GLFWwindow *window = glfwCreateWindow(SCREEN_SIZE_X, SCREEN_SIZE_Y, "Shape Test", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    glewExperimental = true;
    glewInit();

    GLuint vrt = shamkshader(GL_VERTEX_SHADER, "vrt.vert");
    GLuint frg = shamkshader(GL_FRAGMENT_SHADER, "fgt.frag");

    GLuint prog = shamkprogram(vrt, frg);
    glUseProgram(prog);

    glUniformMatrix4fv(2, 1, GL_TRUE, shaortho(SCREEN_SIZE_X/2, -SCREEN_SIZE_X/2,
                                               SCREEN_SIZE_Y/2, -SCREEN_SIZE_Y/2, -1, 1)
                                            );
    return window;
}

bool colid(sh_rect &a, sh_rect &b) {
    vec2 _a = a.get_position();
    vec2 _b = b.get_position();

    if(_a.x + a.get_size().x/2 > _b.x - b.get_size().x/2 &&
       _a.x - a.get_size().x/2 < _b.x + b.get_size().x/2 &&
       _a.y - a.get_size().y/2 < _b.x + b.get_size().y/2 && 
       _a.y + a.get_size().y/2 > _b.x - b.get_size().y/2)
        return true;
    else
        return false;
}
