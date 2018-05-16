#include "triangle.h"
#include <gtest/gtest.h>


/***************Code Based Testing*************************/
TEST( TriangleCodeTest, C0_Test )
{
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(-1,1,1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(1,2,3));
	EXPECT_EQ(EQUILATERAL_TRIANGLE, triangle_type(10,10,10));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(10,10,15));
	EXPECT_EQ(SCALENE_TRIANGLE, triangle_type(3,4,5));
}

TEST( TriangleCodeTest, C1_Test ) 
{
	// InvalidInput branch
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(-1,1,1));
	// IsTriangle branch
	EXPECT_EQ(EQUILATERAL_TRIANGLE, triangle_type(1,1,1)); 
	EXPECT_EQ(SCALENE_TRIANGLE, triangle_type(2,3,4));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(2,2,3));
	
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(1,2,3));
}

TEST( TriangleCodeTest, C2_test )
{
	// same as C1, no loop in the code
	// InvalidInput branch
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(-1,1,1));
	// IsTriangle branch
	EXPECT_EQ(EQUILATERAL_TRIANGLE, triangle_type(1,1,1)); 
	EXPECT_EQ(SCALENE_TRIANGLE, triangle_type(2,3,4));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(2,2,3));
	
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(1,2,3));
}

TEST( TriangleCodeTest, C_MCDC_Test )
{
	// InvalidInput branch
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(0,1,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(201,1,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(1,0,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(1,201,1));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(1,1,0));
	EXPECT_EQ(TRIANGLE_INVALID_INPUT, triangle_type(1,1,201));

	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(1,2,3));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(2,3,1));
	EXPECT_EQ(NOT_A_TRIANGLE, triangle_type(3,2,1));

	EXPECT_EQ(EQUILATERAL_TRIANGLE, triangle_type(1,1,1));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(2,2,3));
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(3,2,2));	
	EXPECT_EQ(ISOSCELES_TRIANGLE, triangle_type(2,3,2));
	EXPECT_EQ(SCALENE_TRIANGLE, triangle_type(2,3,4));
}
