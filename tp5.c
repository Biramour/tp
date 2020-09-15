#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "tp5.h"
#define prl {printf("\n");}

/***************************************************/

coord_t coordinate(double x, double y)
{
    coord_t new;
    new.x = x;
    new.y = y;

    return new;
}

void print_coord(coord_t coord)
{
    printf("(%f | %f)",coord.x,coord.y);
}

coord_t inv_translate_point(coord_t p, coord_t v)
{
    return coordinate(p.x-v.x,p.y-v.y);
}

coord_t inv_rotate_point(coord_t p, double t)
{
    return coordinate(p.x*cos(-t)-p.y*sin(-t), p.x*sin(-t)+p.y*cos(-t) );
}

/**************************************************/

int main() {
  coord_t pt = coordinate(10,20);
  print_coord(pt); prl;
  print_coord(inv_translate_point(pt,pt)); prl;
  print_coord(inv_rotate_point(pt,M_PI_2)); prl;
  print_coord(inv_rotate_point(pt,-M_PI_4)); prl;
  return EXIT_SUCCESS;
}