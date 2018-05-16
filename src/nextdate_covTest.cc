#include "nextdate.h"
#include <gtest/gtest.h>


//***********Code Coverage Test**********//
TEST(NextDateCodeTest, C0_Test)
{
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_max+1, 31 + 1));
	EXPECT_EQ(20120101, nextdate(2011, DEC, 31));
}
TEST(NextDateCodeTest, C1_Test)
{
	EXPECT_EQ(INVALID_DATE, nextdate(2000, JAN, 31 + 1));
	EXPECT_EQ(20000229, nextdate(2000, FEB, 28));
	EXPECT_EQ(20000301, nextdate(2000, FEB, 29));
	EXPECT_EQ(20010101, nextdate(2000, DEC, 31));

	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, JAN, 31 + 1));
	EXPECT_EQ(20010228, nextdate(2001, FEB, 27));
	EXPECT_EQ(20010301, nextdate(2001, FEB, 28));
	EXPECT_EQ(20020101, nextdate(2001, DEC, 31));
}
TEST(NextDateCodeTest, C2_Test)
{
	//No loop in the code, same as C1
	EXPECT_EQ(INVALID_DATE, nextdate(2000, JAN, 31 + 1));
	EXPECT_EQ(20000229, nextdate(2000, FEB, 28));
	EXPECT_EQ(20000301, nextdate(2000, FEB, 29));
	EXPECT_EQ(20010101, nextdate(2000, DEC, 31));

	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, JAN, 31 + 1));
	EXPECT_EQ(20010228, nextdate(2001, FEB, 27));
	EXPECT_EQ(20010301, nextdate(2001, FEB, 28));
	EXPECT_EQ(20020101, nextdate(2001, DEC, 31));
}
TEST(NextDateCodeTest, C_MCDC_Test)
{
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, 1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, 1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2000, month_max+1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2000, month_min-1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, 2, 28 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2000, 2, 29 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2000, 1, 31 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2000, 1, 1 - 1));
	
	EXPECT_EQ(20000301, nextdate(2000, FEB, 29));
	EXPECT_EQ(20010301, nextdate(2001, FEB, 28));
	
	EXPECT_EQ(20010101, nextdate(2000, DEC, 31));
	EXPECT_EQ(19040301, nextdate(1904, FEB, 29));
}
