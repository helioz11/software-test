#include "commission.h"
#include <stdio.h>


double commission(int lock, int stock, int barrel)
{
	double commission = 0;

	if(lock<min_lock || lock>max_lock || stock<min_stock || stock>max_stock || barrel<min_barrel || barrel>max_barrel) return INVALID_SALE;

	int total_sales = (lock*lock_price) + (stock*stock_price) + (barrel*barrel_price);
	if(total_sales>1800.0)
	{
		commission = 0.10 * 1000.0;
		commission = commission + 0.15 * 800.0;
		commission = commission + 0.2 * (total_sales - 1800.0);
	}
	else if(total_sales>1000.0)
	{
		commission = 0.10 * 1000.0;
		commission = commission + 0.15 * (total_sales - 1000.0);
	}
	else commission = 0.10 * total_sales;
	
	return commission;
}
