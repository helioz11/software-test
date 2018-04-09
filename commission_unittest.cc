#include "commission.h"
#include <gtest/gtest.h>

TEST(CommisionSpecTest, NormalBoundaryTest)
{
	EXPECT_DOUBLE_EQ(10.0, commission(1, 1, 1));
	EXPECT_DOUBLE_EQ(1420.0, commission(max_lock,max_stock,max_barrel));
}

TEST(CommisionSpecTest, WeakNormalTest)
{
	EXPECT_DOUBLE_EQ(20.0, commission(2, 2, 2));
	EXPECT_DOUBLE_EQ(97.5, commission(10, 10, 9));
	EXPECT_DOUBLE_EQ(100.0, commission(10, 10, 10));

	EXPECT_DOUBLE_EQ(103.75, commission(10, 10, 11));
	EXPECT_DOUBLE_EQ(160.0, commission(14, 14, 14));
	EXPECT_DOUBLE_EQ(213.25, commission(17, 18, 18));

	EXPECT_DOUBLE_EQ(225.0, commission(18, 18, 19));
	EXPECT_DOUBLE_EQ(820.0, commission(48, 48, 48));
	EXPECT_DOUBLE_EQ(1400.0, commission(69, 79, 89));
}

TEST(CommisionSpecTest, WeakRobustTest)
{
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock, 1, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, min_stock, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, 1, min_barrel));
	
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock, 1, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, max_stock, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, 1, max_barrel));
}

TEST(CommisionSpecTest, StrongRobustTest)
{
	//one min-1
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1, 1, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, min_stock-1, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, 1, min_barrel-1));
	//two min-1
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1, min_stock-1, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1, 1, min_barrel-1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, min_stock-1, min_barrel-1));
	//all min-1
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1, min_stock-1, min_barrel-1));
	//one max+1
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock+1, 1, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, max_stock+1, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, 1, max_barrel+1));
	//two max+1
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock+1, max_stock+1, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock+1, 1, max_barrel+1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, max_stock+1, max_barrel+1));
	//all max+1
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock+1, max_stock+1, max_barrel+1));

	//one min-1, one max+1, one normal
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1, max_stock+1, 1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock+1, min_stock-1, 1));

	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1, 1, max_barrel+1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock+1, 1, min_barrel-1));
	
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, min_stock-1, max_barrel+1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1, max_stock+1, min_barrel-1));

	//one min-1, two max+1
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1, max_stock+1, max_barrel+1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock+1, min_stock-1, max_barrel+1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock+1, max_stock+1, min_barrel-1));
	//two min-1, one max+1
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1, min_stock-1, max_barrel+1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1, max_stock+1, min_barrel-1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock+1, min_stock-1, min_barrel-1));	
}
