#ifndef TYPE_H
#define TYPE_H

class TypedValue;

template <typename T>
class BaseType {
private:
    T _value;

public:
    BaseType(T value) : _value(value) {}
    virtual ~BaseType() = default;

    virtual TypedValue logicalNot() const = 0;
    virtual TypedValue logicalOr(const TypedValue other) const = 0;
    virtual TypedValue logicalAnd(const TypedValue other) const = 0;

    virtual TypedValue add(const TypedValue other) const = 0;
    virtual TypedValue subtract(const TypedValue other) const = 0;
    virtual TypedValue multiply(const TypedValue other) const = 0;
    virtual TypedValue divide(const TypedValue other) const = 0;

    T getValue() const {
        return _value;
    }
};

#endif
