#include"triangle.h"
#include<stdio.h>

int triangle_type(int a, int b, int c)
{
	if(a<triangle_min_edge || a>triangle_max_edge || b<triangle_min_edge || b>triangle_max_edge
|| c<triangle_min_edge || c>triangle_max_edge) return 0;
	else return -1;
}
