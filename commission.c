#include "commission.h"
#include <stdio.h>


double commission(int lock, int stock, int barrel)
{
	int commission = 0;
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
		commission = commission * 0.15 * (total_sales - 1000.0);
	}
	else commission = 0.10 * total_sales;
	
	return commission;
}
