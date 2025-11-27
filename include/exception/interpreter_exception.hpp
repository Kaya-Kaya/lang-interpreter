#ifndef INTERPRETER_EXCEPTION_H
#define INTERPRETER_EXCEPTION_H

#include <stdexcept>
#include <string>

class InterpreterException : public std::runtime_error {
public:
    InterpreterException(const std::string &message) : std::runtime_error(message) {}
};

#endif