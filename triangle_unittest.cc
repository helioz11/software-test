#include "triangle.h"
#include <gtest/gtest.h>

/*********** Input Specification *************/
TEST(TriangleInputSpecTest , NegativeEdge)
{
	// one neg edge
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(-1,1,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(1,-1,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(1,1,-1));
	// two neg edge
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(-1,-1,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(-1,-1,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(1,-1,-1));
	// all neg edge	
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(-1,-1,-1));
}
TEST(TriangleInputSpecTest , OverMaxEdge)
{
	// one over max edge
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(201,1,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(1,201,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(1,1,201));
	// two over max edge
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(201,201,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(1,201,201));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(201,1,201));
	// all over max edge
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(201,201,201));
}
