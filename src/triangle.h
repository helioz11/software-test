#ifndef TRIANGLE_H
#define TRIANGLE_H

#define triangle_min_edge 1
#define triangle_max_edge 200

#define TRIANGLE_INVALID_INPUT 0
#define NOT_A_TRIANGLE	1
#define EQUILATERAL_TRIANGLE 2
#define ISOSCELES_TRIANGLE 3
#define SCALENE_TRIANGLE 4

int triangle_type(int a,int b, int c);

#endif
