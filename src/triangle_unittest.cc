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

/*************** Boundary Test *****************/
TEST(Triangle_Boundary_Test, NormalBoundary)
{
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(100,100,triangle_min_edge));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(100,100,triangle_min_edge+1));
	EXPECT_EQ(EQUILATERAL_TRIANGLE, triangle_type(100,100,100));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(100,100,triangle_max_edge-1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(100,100,triangle_max_edge));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(100,triangle_min_edge,100));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(100,triangle_min_edge+1,100));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(100,triangle_max_edge-1,100));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(100,triangle_max_edge,100));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(triangle_min_edge,100,100));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(triangle_min_edge+1,100,100));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(triangle_max_edge-1,100,100));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_max_edge,100,100));
}
TEST(Triangle_Boundary_Test, WorstCaseBoundaryValueTest)
{
	EXPECT_EQ(EQUILATERAL_TRIANGLE, triangle_type(triangle_min_edge,triangle_min_edge,triangle_min_edge));	
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_min_edge,triangle_min_edge+1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_min_edge,100));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_min_edge,triangle_max_edge-1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_min_edge,triangle_max_edge));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_min_edge+1,triangle_min_edge));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(triangle_min_edge,triangle_min_edge+1,triangle_min_edge+1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_min_edge+1,100));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_min_edge+1,triangle_max_edge-1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_min_edge+1,triangle_max_edge));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,100,triangle_min_edge));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,100,triangle_min_edge+1));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(triangle_min_edge,100,100));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,100,triangle_max_edge-1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,100,triangle_max_edge));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_max_edge-1,triangle_min_edge));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_max_edge-1,triangle_min_edge+1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_max_edge-1,100));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(triangle_min_edge,triangle_max_edge-1,triangle_max_edge-1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_max_edge-1,triangle_max_edge));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_max_edge,triangle_min_edge));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_max_edge,triangle_min_edge+1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_max_edge,100));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(triangle_min_edge,triangle_max_edge,triangle_max_edge-1));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(1,triangle_max_edge,triangle_max_edge));
}

/********************EQUIVALENCE TEST**********************/
TEST(Triangle_Equivalence_Test, Weak_Normal)
{
	EXPECT_EQ(EQUILATERAL_TRIANGLE, triangle_type(5,5,5));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(2,2,3));
	EXPECT_EQ(SCALENE_TRIANGLE, triangle_type(3,4,5));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(4,1,2));
}

