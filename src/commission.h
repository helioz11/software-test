#ifndef COMMISION_H
#define COMMISION_H

#define lock_price 45.0
#define stock_price 30.0
#define barrel_price 25.0

#define min_lock 1
#define max_lock 70

#define min_stock 1
#define max_stock 80

#define min_barrel 1
#define max_barrel 90

#define INVALID_SALE 0.0

double commission(int lock, int stock, int barrel);

#endif
