#ifndef __TP5_H__
#define __TP5_H__

typedef struct 
{
    double x;
    double y;
}coord_t;

typedef struct 
{
    double radius;
} circle_t;

typedef struct 
{
    double height;
    double width;
} rectangle_t;

typedef struct 
{
    double length;
}line_t;

typedef enum 
{
    LINE,
    RECTANGLE,
    CIRCLE
}shape_t;

typedef char color_t;

typedef union
{
   rectangle_t rectangle;
   line_t line;
   circle_t circle;
}caracteristic_t;


typedef struct
{
    color_t color;
    coord_t center;
    double angle;
    shape_t shape;
    caracteristic_t caracteristic;

}figure_t;


coord_t coordinate(double x, double y);
void print_coord(coord_t coord);
coord_t inv_translate_point(coord_t p, coord_t v);
coord_t inv_rotate_point(coord_t p, double t);
coord_t coord_translate(coord_t p, coord_t v);
figure_t circle(double radius);
figure_t rectangle(double width, double height);
figure_t line(double length);
figure_t color(figure_t f, color_t c);
figure_t translate(figure_t f, double dx, double dy);
figure_t rotate(figure_t f, double dt);
color_t intersect(coord_t p, figure_t f, double grain);




#endif 