#include "commission.h"
#include <gtest/gtest.h>


TEST(CommisionCodeTest, C0_Test)
{
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1,1,1));
	EXPECT_DOUBLE_EQ(1400.0, commission(69,79,89));
}

TEST(CommisionCodeTest, C1_Test)
{
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1,1,1));
	EXPECT_DOUBLE_EQ(100.0, commission(10,10,10));
	EXPECT_DOUBLE_EQ(160.0, commission(14,14,14));
	EXPECT_DOUBLE_EQ(1400.0, commission(69,79,89));
}

TEST(CommisionCodeTest, C2_Test)
{
	//No loop in the code, same as C1
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1,1,1));
	EXPECT_DOUBLE_EQ(100.0, commission(10,10,10));
	EXPECT_DOUBLE_EQ(160.0, commission(14,14,14));
	EXPECT_DOUBLE_EQ(1400.0, commission(69,79,89));
}

TEST(CommisionCodeTest, C_MCDC_Test)
{
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(min_lock-1,1,1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(max_lock+1,1,1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1,min_stock-1,1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1,max_stock+1,1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1,1,min_barrel-1));
	EXPECT_DOUBLE_EQ(INVALID_SALE, commission(1,1,max_barrel+1));

	EXPECT_DOUBLE_EQ(100.0, commission(10,10,10));
	EXPECT_DOUBLE_EQ(213.25, commission(17,18,18));
	EXPECT_DOUBLE_EQ(820.0, commission(48,48,48));
}

