#include "circ_buffer.hpp"

namespace Utils {

unsigned CircBuffer::GetCapacity() const {
    return _capacity;
}

unsigned CircBuffer::GetSize() const {
    return _size;
}

}