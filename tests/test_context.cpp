#include "context.hpp"
#include "exception/runtime_exception.hpp"
#include "type/number.hpp"
#include "value.hpp"

#include <gtest/gtest.h>

TEST(ContextTest, AssignAndLookup) {
    Context ctx;
    TypedValue val(NumberType(100));
    
    ctx.assign("myVar", val);
    TypedValue result = ctx.lookup("myVar");
    
    EXPECT_EQ(result.getType(), Type::NUMBER);
    EXPECT_DOUBLE_EQ(std::get<NumberType>(result.getValue()).getValue(), 100.0);
}

TEST(ContextTest, OverwriteVariable) {
    Context ctx;
    TypedValue val1(NumberType(1));
    TypedValue val2(NumberType(2));
    
    ctx.assign("x", val1);
    EXPECT_DOUBLE_EQ(std::get<NumberType>(ctx.lookup("x").getValue()).getValue(), 1.0);
    
    ctx.assign("x", val2);
    EXPECT_DOUBLE_EQ(std::get<NumberType>(ctx.lookup("x").getValue()).getValue(), 2.0);
}

TEST(ContextTest, LookupUndefinedThrows) {
    Context ctx;
    EXPECT_THROW(ctx.lookup("undefined"), UndefinedVariableException);
}
