#ifndef __TP5_H__
#define __TP5_H__

// Définir le type coord_t permettant de représenter coordonnées en 2D de la forme $(x,y)$ ; on utilisera le type double pour représenter chaque coordonnée.
typedef struct 
{
    double x;
    double y;
}coord_t;

coord_t coordinate(double x, double y);
void print_coord(coord_t coord);
coord_t inv_translate_point(coord_t p, coord_t v);
coord_t inv_rotate_point(coord_t p, double t);



#endif 