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
    double length;
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

coord_t coordinate(double x, double y);
void print_coord(coord_t coord);
coord_t inv_translate_point(coord_t p, coord_t v);
coord_t inv_rotate_point(coord_t p, double t);



#endif 