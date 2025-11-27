#ifndef TYPE_H
#define TYPE_H

class TypedValue;

template <typename T>
class BaseType {
private:
    T _value;

public:
    BaseType(T value) : _value(value) {}

    T getValue() const {
        return _value;
    }
};

#endif
