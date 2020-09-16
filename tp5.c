#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "tp5.h"
#define prl {printf("\n");}
#define square(a)  (a)*(a)

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


figure_t circle(double radius)
{
    figure_t new;
    new.angle = 0;
    new.shape = CIRCLE;
    new.color = '+';
    new.caracteristic.circle.radius = radius;

    return new;
}

figure_t rectangle(double width, double height)
{
    figure_t new;
    new.angle = 0;
    new.shape = RECTANGLE;
    new.color = '+';
    new.caracteristic.rectangle.width = width;
    new.caracteristic.rectangle.height = height;

    return new;
}

figure_t line(double length)
{
    figure_t new;
    new.angle = 0;
    new.shape = LINE;
    new.color = '+';
    new.caracteristic.line.length = length;

    return new;
}

figure_t color(figure_t f, color_t c)
{
    f.color = c;
    return f;
}

coord_t coord_translate(coord_t p, coord_t v)
{
    return coordinate(p.x+v.x,p.y+v.y);
}

figure_t translate(figure_t f, double dx, double dy)
{
    f.center = coord_translate(f.center,coordinate(dx,dy));
    return f;
}

figure_t rotate(figure_t f, double dt)
{
    f.angle = f.angle + dt;
    return f;
}

color_t intersect(coord_t p, figure_t f, double grain)
{
    p = inv_translate_point(p,f.center);
    p = inv_rotate_point(p,f.angle);

    switch (f.shape)
    {
    case CIRCLE:
        if(square(p.x)+square(p.y) <= f.caracteristic.circle.radius)
        {
            return f.color;
        }
        return  0;
    break;
    case RECTANGLE:
        if(fabs(p.x)<=f.caracteristic.rectangle.width && fabs(p.y) <= f.caracteristic.rectangle.height)
        {
            return f.color;
        }
        return 0;
    break;
    case LINE:
        if(fabs(p.x)<= f.caracteristic.line.length && fabs(p.y) <= grain)
        {
            return f.color;
        }
        return 0;
    break;
    default:
        break;
    }

}
/**************************************************/

int main() {
  figure_t f;
  color_t c;
 
  f = rectangle(10,7);
  f = translate(f, 10, 8);
  f = rotate(f, 45 * M_PI / 180);

  printf("h= %f et w =%f",f.caracteristic.rectangle.height, f.caracteristic.rectangle.width);
  prl;
 
  c = intersect(coordinate(5,5),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(10,10),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(18,18),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
 
  f = circle(12);
  f = translate(f, 20, 13);
  f = color(f, 'O');
 
  c = intersect(coordinate(5,5),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(10,10),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(18,18),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
 
  f = line(20);
  f = translate(f, 18, 18);
  f = rotate(f, -60 * M_PI / 180);
  f = color(f, '*');
 
  c = intersect(coordinate(5,5),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(10,10),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(18,18),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
 
  return EXIT_SUCCESS;
}