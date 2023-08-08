#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "tempconv.cc"

using cucumber::ScenarioScope;

struct ConverterContext {
    TempConv converter;
    int result;
};

GIVEN("^an instance of the converter class$") {
    ScenarioScope<ConverterContext> context;
}

WHEN("^the Celsius value is (-?\\d+)$") {
    ScenarioScope<ConverterContext> context;
    REGEX_PARAM(int, tempInC);

    context->result = context->converter.ConvertCToF(tempInC);
}

THEN("^it should return (-?\\d+)$") {
    ScenarioScope<ConverterContext> context;
    REGEX_PARAM(int, tempInF);

    ASSERT_EQ(tempInF, context->result);
}