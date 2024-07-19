#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "OrderType.h"

class Order 
{
private:
    std::string _orderId {"0"};
   float _value {0.0f};
   OrderType _type {OrderType::PAID};
   float _discount {0.0f};

public:
    Order() = default; // Default constructor
    Order(const Order&) = default; // Copy constructor
    Order& operator=(const Order&) = delete; // Copy assignment operator
    Order(Order&&) = delete; // Move constructor
    Order& operator=(Order&&) = delete; // Move assignment operator
    ~Order() = default; // Destructor

    Order(std::string id, float value, OrderType type, float discount);

    std::string orderId() const { return _orderId; }

    float value() const { return _value; }
    void setValue(float value) { _value = value; }

    OrderType type() const { return _type; }
    void setType(const OrderType &type) { _type = type; }

    float discount() const { return _discount; }
    void setDiscount(float discount) { _discount = discount; }

    friend std::ostream &operator<<(std::ostream &os, const Order &rhs);
};

#endif // ORDER_H
