#include "commission.h"
#include <gtest/gtest.h>

TEST(CommisionSpecTest, NormalBoundaryTest)
{
	EXPECT_DOUBLE_EQ(10.0, commission(1, 1, 1));
	EXPECT_DOUBLE_EQ(1420.0, commission(max_lock,max_stock,max_barrel));
}
