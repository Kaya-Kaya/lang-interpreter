#ifndef RUNTIME_EXCEPTION_H
#define RUNTIME_EXCEPTION_H

#include "interpreter_exception.hpp"
#include <string>

class RuntimeException : public InterpreterException {
public:
    RuntimeException(const std::string &message) : InterpreterException(message) {}
};

class UndefinedVariableException : public RuntimeException {
public:
    UndefinedVariableException(const std::string &name) : RuntimeException("Undefined variable: '" + name + "'") {}
};

class InvalidOperationException : public RuntimeException {
public:
    InvalidOperationException(const std::string &message) : RuntimeException(message) {}
};

class DivisionByZeroException : public RuntimeException {
public:
    DivisionByZeroException() : RuntimeException("Division by zero") {}
};

#endif
