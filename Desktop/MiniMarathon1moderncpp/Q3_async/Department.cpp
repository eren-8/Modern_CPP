#include "Department.h"

int Department::totalemp=0;
Department::Department(std::string id)
    :_id{id}
{
    totalemp++;
    _size = totalemp;
}
std::ostream &operator<<(std::ostream &os, const Department &rhs) {
    os << "_id: " << rhs._id
       << " _size: " << rhs._size;
    return os;
}
