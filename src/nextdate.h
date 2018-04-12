#ifndef NEXTDATE_H
#define NEXTDATE_H

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

#define INVALID_DATE 0

#define year_min 1812
#define year_max 2012

#define month_min 1
#define month_max 12

int nextdate(int y, int m, int d);

#endif
