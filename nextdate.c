#include <stdio.h>
#include "nextdate.h"

const int max_day[month_max + 1] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; 
const int leap_year_max_day[month_max + 1] = {0,31,29,31,30,31,30,31,31,30,31,30,31}; 

int leap_year = 0;

int nextdate( int y, int m, int d)
{
	d++;
	if(((y%4==0) && (y%100!=0)) || (y%400==0)) leap_year = 1;
	else leap_year = 0;

	if((leap_year && d > leap_year_max_day[m]) || (d > max_day[m] && !leap_year) )
	{
		d = 1;	m++;
	}
	if(m>month_max)
	{
		m = month_min;
		y++;
	}
	
	return (y*10000)+(m*100)+d;
}
