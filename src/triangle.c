#include"triangle.h"
#include<stdio.h>

int IsTriangle = 0;

int triangle_type(int a, int b, int c)
{
	if(a<triangle_min_edge || a>triangle_max_edge || b<triangle_min_edge || b>triangle_max_edge
|| c<triangle_min_edge || c>triangle_max_edge) return TRIANGLE_INVALID_INPUT;
	else if( (a+b)>c && (a+c)>b && (b+c)>a )
	{
		IsTriangle = 1;
	}
	else IsTriangle = 0;
	
	if(IsTriangle)
	{
		if((a==b) && (b==c)) return EQUILATERAL_TRIANGLE;
		else if((a!=b) && (a!=c) && (b!=c)) return SCALENE_TRIANGLE;
		else return ISOSCELES_TRIANGLE;
	}
	else return NOT_A_TRIANGLE;
}
