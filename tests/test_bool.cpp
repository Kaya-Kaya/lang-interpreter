#include <gtest/gtest.h>

#include "type/bool.hpp"
#include "type/number.hpp"
#include "exception/runtime_exception.hpp"
#include "value.hpp"

class BoolTypeTest : public ::testing::Test {
protected:
    BoolType bTrue{true};
    BoolType bFalse{false};
    
    TypedValue tvTrue = TypedValue(bTrue);
    TypedValue tvFalse = TypedValue(bFalse);
    TypedValue tvNum = TypedValue(NumberType(1));
};

// Logical operations
TEST_F(BoolTypeTest, LogicalNot) {
    EXPECT_FALSE(std::get<BoolType>(bTrue.logicalNot().getValue()).getValue());
    EXPECT_TRUE(std::get<BoolType>(bFalse.logicalNot().getValue()).getValue());
}
TEST_F(BoolTypeTest, LogicalAnd) {
    // T && T -> T
    EXPECT_TRUE(std::get<BoolType>(bTrue.logicalAnd(tvTrue).getValue()).getValue());
    // T && F -> F
    EXPECT_FALSE(std::get<BoolType>(bTrue.logicalAnd(tvFalse).getValue()).getValue());
    // F && T -> F
    EXPECT_FALSE(std::get<BoolType>(bFalse.logicalAnd(tvTrue).getValue()).getValue());
    // F && F -> F
    EXPECT_FALSE(std::get<BoolType>(bFalse.logicalAnd(tvFalse).getValue()).getValue());
}
TEST_F(BoolTypeTest, LogicalOr) {
    // T || T -> T
    EXPECT_TRUE(std::get<BoolType>(bTrue.logicalOr(tvTrue).getValue()).getValue());
    // T || F -> T
    EXPECT_TRUE(std::get<BoolType>(bTrue.logicalOr(tvFalse).getValue()).getValue());
    // F || T -> T
    EXPECT_TRUE(std::get<BoolType>(bFalse.logicalOr(tvTrue).getValue()).getValue());
    // F || F -> F
    EXPECT_FALSE(std::get<BoolType>(bFalse.logicalOr(tvFalse).getValue()).getValue());
}

// Comparisons
TEST_F(BoolTypeTest, IsEqual) {
    EXPECT_TRUE(std::get<BoolType>(bTrue.isEqual(tvTrue).getValue()).getValue());
    EXPECT_FALSE(std::get<BoolType>(bTrue.isEqual(tvFalse).getValue()).getValue());
}
TEST_F(BoolTypeTest, IsNotEqual) {
    EXPECT_TRUE(std::get<BoolType>(bTrue.isNotEqual(tvFalse).getValue()).getValue());
    EXPECT_FALSE(std::get<BoolType>(bTrue.isNotEqual(tvTrue).getValue()).getValue());
}

// Invalid operations
TEST_F(BoolTypeTest, InvalidLogicalAnd) { 
    EXPECT_THROW(bTrue.logicalAnd(tvNum), InvalidOperationException);
}
TEST_F(BoolTypeTest, InvalidLogicalOr) {
    EXPECT_THROW(bTrue.logicalOr(tvNum), InvalidOperationException);
}
TEST_F(BoolTypeTest, ArithmeticThrows) {
    EXPECT_THROW(bTrue.add(tvTrue), InvalidOperationException);
    EXPECT_THROW(bTrue.subtract(tvTrue), InvalidOperationException);
    EXPECT_THROW(bTrue.multiply(tvTrue), InvalidOperationException);
    EXPECT_THROW(bTrue.divide(tvTrue), InvalidOperationException);
}
TEST_F(BoolTypeTest, ComparisonThrows) {
    EXPECT_THROW(bTrue.isLess(tvTrue), InvalidOperationException);
    EXPECT_THROW(bTrue.isGreater(tvTrue), InvalidOperationException);
}
