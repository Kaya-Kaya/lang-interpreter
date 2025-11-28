#include "exception/runtime_exception.hpp"
#include "type/number.hpp"
#include "type/bool.hpp"
#include "value.hpp"

#include <gtest/gtest.h>

class NumberTypeTest : public ::testing::Test {
protected:
    NumberType num5{5.0};
    NumberType num3{3.0};
    NumberType num0{0.0};
    
    TypedValue tv5 = TypedValue(num5);
    TypedValue tv3 = TypedValue(num3);
    TypedValue tv0 = TypedValue(num0);
    TypedValue tvBool = TypedValue(BoolType(true));
};

// Arithmetic
TEST_F(NumberTypeTest, Add) {
    TypedValue res = num5.add(tv3); // 5 + 3
    EXPECT_DOUBLE_EQ(std::get<NumberType>(res.getValue()).getValue(), 8.0);
}
TEST_F(NumberTypeTest, Subtract) {
    TypedValue res = num5.subtract(tv3); // 5 - 3
    EXPECT_DOUBLE_EQ(std::get<NumberType>(res.getValue()).getValue(), 2.0);
}
TEST_F(NumberTypeTest, Multiply) {
    TypedValue res = num5.multiply(tv3); // 5 * 3
    EXPECT_DOUBLE_EQ(std::get<NumberType>(res.getValue()).getValue(), 15.0);
}
TEST_F(NumberTypeTest, Divide) {
    TypedValue res = num5.divide(tv5); // 5 / 5
    EXPECT_DOUBLE_EQ(std::get<NumberType>(res.getValue()).getValue(), 1.0);
}
TEST_F(NumberTypeTest, DivideByZero) {
    EXPECT_THROW(num5.divide(tv0), DivisionByZeroException);
}

// Comparisons
TEST_F(NumberTypeTest, IsEqual) {
    EXPECT_TRUE(std::get<BoolType>(num5.isEqual(tv5).getValue()).getValue());
    EXPECT_FALSE(std::get<BoolType>(num5.isEqual(tv3).getValue()).getValue());
}
TEST_F(NumberTypeTest, IsNotEqual) {
    EXPECT_TRUE(std::get<BoolType>(num5.isNotEqual(tv3).getValue()).getValue());
    EXPECT_FALSE(std::get<BoolType>(num5.isNotEqual(tv5).getValue()).getValue());
}
TEST_F(NumberTypeTest, IsLess) {
    EXPECT_TRUE(std::get<BoolType>(num3.isLess(tv5).getValue()).getValue());
    EXPECT_FALSE(std::get<BoolType>(num5.isLess(tv3).getValue()).getValue());
}
TEST_F(NumberTypeTest, IsGreater) {
    EXPECT_TRUE(std::get<BoolType>(num5.isGreater(tv3).getValue()).getValue());
    EXPECT_FALSE(std::get<BoolType>(num3.isGreater(tv5).getValue()).getValue());
}
TEST_F(NumberTypeTest, IsLessOrEqual) {
    EXPECT_TRUE(std::get<BoolType>(num3.isLessOrEqual(tv5).getValue()).getValue());
    EXPECT_TRUE(std::get<BoolType>(num5.isLessOrEqual(tv5).getValue()).getValue());
    EXPECT_FALSE(std::get<BoolType>(num5.isLessOrEqual(tv3).getValue()).getValue());
}
TEST_F(NumberTypeTest, IsGreaterOrEqual) {
    EXPECT_TRUE(std::get<BoolType>(num5.isGreaterOrEqual(tv3).getValue()).getValue());
    EXPECT_TRUE(std::get<BoolType>(num5.isGreaterOrEqual(tv5).getValue()).getValue());
    EXPECT_FALSE(std::get<BoolType>(num3.isGreaterOrEqual(tv5).getValue()).getValue());
}

// Invalid operations
TEST_F(NumberTypeTest, InvalidAdd) {
    EXPECT_THROW(num5.add(tvBool), InvalidOperationException);
}
TEST_F(NumberTypeTest, InvalidSubtract) {
    EXPECT_THROW(num5.subtract(tvBool), InvalidOperationException);
}
TEST_F(NumberTypeTest, InvalidMultiply) {
    EXPECT_THROW(num5.multiply(tvBool), InvalidOperationException);
}
TEST_F(NumberTypeTest, InvalidDivide) {
    EXPECT_THROW(num5.divide(tvBool), InvalidOperationException);
}
TEST_F(NumberTypeTest, LogicalOpsThrow) {
    EXPECT_THROW(num5.logicalNot(), InvalidOperationException);
    EXPECT_THROW(num5.logicalAnd(tv3), InvalidOperationException);
    EXPECT_THROW(num5.logicalOr(tv3), InvalidOperationException);
}
