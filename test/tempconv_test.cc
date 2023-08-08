#include <gtest/gtest.h>
#include "tempconv.cc"

TEST(ConvertCToF, When0Expect32) {
  TempConv converter;

  int result = converter.ConvertCToF(0);

  ASSERT_EQ(result, 32);
}

TEST(ConvertCToF, When100Expect212) {
  TempConv converter;

  int result = converter.ConvertCToF(100);

  ASSERT_EQ(result, 212);
}

TEST(ConvertCToF, WhenNeg40ExpectNeg40) {
  TempConv converter;

  int result = converter.ConvertCToF(-40);

  ASSERT_EQ(result, -40);
}