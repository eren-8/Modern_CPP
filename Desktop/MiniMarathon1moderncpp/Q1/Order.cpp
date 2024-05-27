#include "Order.h"

Order::Order(std::string id, float value, OrderType type, float discount)
    :_orderId{id}, _value{value}, _type{type}, _discount{discount}
{
}
std::ostream &operator<<(std::ostream &os, const Order &rhs) {
    os << "_orderId: " << rhs._orderId
       << " _value: " << rhs._value
       << " _type: ";
        if(static_cast<int>(rhs._type)==0){
            os<<"PAID";
        }
        else if(static_cast<int>(rhs._type)==1){
            os<<"COD";
        }
        else if(static_cast<int>(rhs._type)==2){
            os<<"PROMOTION";
        }
    os << " _discount: " << rhs._discount;
    return os;
}
