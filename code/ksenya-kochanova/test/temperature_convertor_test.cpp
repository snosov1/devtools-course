/* Copyright 2013 Ksenya Kochanova */
#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "library/TemperatureConverter.h"

class TempConvTest : public ::testing::Test {
 protected:
    TemperatureConvertor tempconv;
};

TEST_F(TempConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong) {
    EXPECT_THROW(tempconv.Convert({-300, Celsius}, Newton), std::string);
}
TEST_F(TempConvTest, Do_Throw_Exception_When_Value_For_Kelvin_Is_Wrong) {
    EXPECT_THROW(tempconv.Convert({-3, Kelvin}, Newton), std::string);
}
TEST_F(TempConvTest, Do_Throw_Exception_When_Value_For_Newton_Is_Wrong) {
    EXPECT_THROW(tempconv.Convert({-100, Newton}, Kelvin), std::string);
}
TEST_F(TempConvTest, Do_Throw_Exception_When_Value_For_Fahrenheit_Is_Wrong) {
    EXPECT_THROW(tempconv.Convert({-500, Fahrenheit}, Newton), std::string);
}

TEST_F(TempConvTest, Can_Convert_Kelvin_To_Celsius) {
    Temperature KtoC;
    KtoC.value = 0 - 273.15;
    EXPECT_EQ(KtoC.value, tempconv.Convert({0, Kelvin}, Celsius).value);
}

TEST_F(TempConvTest, Can_Convert_Celsius_To_Newton) {
    Temperature CtoF;
    CtoF.value =  5 *  1 / 3.030303030302;
    EXPECT_EQ(CtoF.value, tempconv.Convert({5, Celsius}, Newton).value);
}

TEST_F(TempConvTest, Can_Convert_Fahrenheit_To_Celsius) {
    Temperature FtoC;
    FtoC.value = 0.5555555555555556 * 10 - 32;
    EXPECT_EQ(FtoC.value, tempconv.Convert({10, Fahrenheit}, Celsius).value);
}

TEST_F(TempConvTest, Can_Convert_Newton_To_Fahrenheit) {
    Temperature NtoF;
    NtoF.value = 1 / 0.5555555555555556 * 32;
    EXPECT_EQ(NtoF.value, tempconv.Convert({0, Newton}, Fahrenheit).value);
}
