#ifndef TYPE_H
#define TYPE_H

class TypedValue;

template <typename T>
class BaseType {
private:
    T _value;

public:
    BaseType<T>(T value);

    virtual TypedValue logicalNot() const;
    virtual TypedValue logicalOr(const TypedValue& other) const;
    virtual TypedValue logicalAnd(const TypedValue& other) const;

    virtual TypedValue add(const TypedValue& other) const;
    virtual TypedValue subtract(const TypedValue& other) const;
    virtual TypedValue multiply(const TypedValue& other) const;
    virtual TypedValue divide(const TypedValue& other) const;

    T getValue() const;
};

#endif
