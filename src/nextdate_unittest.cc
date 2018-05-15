#include "nextdate.h"
#include <gtest/gtest.h>

TEST( NextDateSpecTest, BoundaryTest)
{
	EXPECT_EQ( 18120102, nextdate( year_min, month_min, 1));
	EXPECT_EQ( 20130101, nextdate( year_max, month_max, 31));
}

TEST( NextDateTest, WeakNormalMonth)
{
	EXPECT_EQ(20090111, nextdate(2009, JAN, 10));
	EXPECT_EQ(20100131, nextdate(2010, JAN, 30));
	EXPECT_EQ(20110201, nextdate(2011, JAN, 31));

	EXPECT_EQ(20090211, nextdate(2009, FEB, 10));
	EXPECT_EQ(20100228, nextdate(2010, FEB, 27));
	EXPECT_EQ(20110301, nextdate(2011, FEB, 28));

	EXPECT_EQ(20090311, nextdate(2009, MAR, 10));
	EXPECT_EQ(20100331, nextdate(2010, MAR, 30));
	EXPECT_EQ(20110401, nextdate(2011, MAR, 31));

	EXPECT_EQ(20090411, nextdate(2009, APR, 10));
	EXPECT_EQ(20100430, nextdate(2010, APR, 29));
	EXPECT_EQ(20110501, nextdate(2011, APR, 30));

	EXPECT_EQ(20090511, nextdate(2009, MAY, 10));
	EXPECT_EQ(20100531, nextdate(2010, MAY, 30));
	EXPECT_EQ(20110601, nextdate(2011, MAY, 31));

	EXPECT_EQ(20090611, nextdate(2009, JUN, 10));
	EXPECT_EQ(20100630, nextdate(2010, JUN, 29));
	EXPECT_EQ(20110701, nextdate(2011, JUN, 30));

	EXPECT_EQ(20090711, nextdate(2009, JUL, 10));
	EXPECT_EQ(20100731, nextdate(2010, JUL, 30));
	EXPECT_EQ(20110801, nextdate(2011, JUL, 31));

	EXPECT_EQ(20090811, nextdate(2009, AUG, 10));
	EXPECT_EQ(20100831, nextdate(2010, AUG, 30));
	EXPECT_EQ(20110901, nextdate(2011, AUG, 31));

	EXPECT_EQ(20090911, nextdate(2009, SEP, 10));
	EXPECT_EQ(20100930, nextdate(2010, SEP, 29));
	EXPECT_EQ(20111001, nextdate(2011, SEP, 30));

	EXPECT_EQ(20091011, nextdate(2009, OCT, 10));
	EXPECT_EQ(20101031, nextdate(2010, OCT, 30));
	EXPECT_EQ(20111101, nextdate(2011, OCT, 31));

	EXPECT_EQ(20091111, nextdate(2009, NOV, 10));
	EXPECT_EQ(20101130, nextdate(2010, NOV, 29));
	EXPECT_EQ(20111201, nextdate(2011, NOV, 30));

	EXPECT_EQ(20091211, nextdate(2009, DEC, 10));
	EXPECT_EQ(20101231, nextdate(2010, DEC, 30));
	EXPECT_EQ(20120101, nextdate(2011, DEC, 31));
}
TEST(NextDateTest , WeakRobust)
{
	//min boundary - 1
	EXPECT_EQ(INVALID_DATE, nextdate(year_min - 1, 1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_min - 1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, 1, 0));
	//max boundary + 1
	EXPECT_EQ(INVALID_DATE, nextdate(year_max + 1, 1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_max + 1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, JAN, 31 + 1));
	//LeapYear Feb 29 days and NonLeap Feb 28 days
	EXPECT_EQ(INVALID_DATE, nextdate(2000, FEB, 29 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, FEB, 28 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, APR, 30 + 1));
}
TEST(NextDateTest , StrongRobust)
{
	//two parameter boundary_min - 1 test
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_min-1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, 1, 0));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_min-1, 0));
	//all boundary_min - 1 test
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_min-1, 0));
	
	//two parameter boundary_max + 1 test
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, month_max+1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, JAN, 31 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, FEB, 28 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, FEB, 29 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, APR, 30 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_max+1, 31 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_max+1, 28 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_max+1, 29 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_max+1, 30 + 1));
	//all boundary_max + 1 test
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, month_max+1, 31 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, month_max+1, 28 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, month_max+1, 29 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, month_max+1, 30 + 1));

	//one max+1, one min-1, one normal
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_max+1, 0));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_min-1, 31 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_min-1, 28 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_min-1, 29 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(2001, month_min-1, 30 + 1));

	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, 1, 0));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, 1, 31 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, 1, 28 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, 1, 29 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, 1, 30 + 1));

	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_max+1, 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, month_min-1, 1));

	//one max+1, two min-1
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, month_min-1, 0));
	
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_max+1, 0));
	
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_min-1, 31 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_min-1, 28 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_min-1, 29 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_min-1, 30 + 1));
	
	//two max+1, one min-1
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, month_max+1, 0));
	
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, 1, 31 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, 1, 28 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, 1, 29 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_max+1, 1, 30 + 1));
	
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_max+1, 31 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_max+1, 28 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_max+1, 29 + 1));
	EXPECT_EQ(INVALID_DATE, nextdate(year_min-1, month_max+1, 30 + 1));

}
TEST(NextDateTest, LeapYearTest)
{
	EXPECT_EQ(INVALID_DATE, nextdate(1900,FEB,29));
	EXPECT_EQ(20000301, nextdate(2000,FEB,29));
	EXPECT_EQ(INVALID_DATE, nextdate(2002,FEB,29));
	EXPECT_EQ(20040301, nextdate(2004,FEB,29));
}

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
	
	EXPECT_EQ(20000301, nextdate(2000, FEB, 29));
	EXPECT_EQ(20010301, nextdate(2001, FEB, 28));
	
	EXPECT_EQ(20010101, nextdate(2000, DEC, 31));

}
