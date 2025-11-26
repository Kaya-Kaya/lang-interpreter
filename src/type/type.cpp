#include "type/type.hpp"

template <typename T>
BaseType<T>::BaseType(T value) : _value(value) {}

template <typename T>
T BaseType<T>::getValue() const {
    return _value;
}

