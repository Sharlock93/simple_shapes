#ifndef GRID_H
#define GRID_H
#define GLEW_STATIC
#include <GL\glew.h>
#include <shar.h>

class grid {

public:
    grid(float width, float height, int rect_size);
    grid();
    ~grid();

    void render();
    vec3* get_points();
    int get_point_size();

    void seed_height_map(float* x);
private:
    GLuint _vbo;
    int _drawpoint;
    float _width;
    float _height;
    int _rect_num;

    float _rect_width;
    float _rect_height;


    vec3 *_points;

};

#endif // GRID_H
