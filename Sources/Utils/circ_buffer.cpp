#include "circ_buffer.hpp"

namespace Utils {

unsigned CircBuffer::GetCapacity() const {
    return _capacity;
}

unsigned CircBuffer::GetSize() const {
    return _size;
}

bool CircBuffer::Append(char c) {
    _buff[_size] = c;
    _size++;
    return false;
}

char CircBuffer::Peek() const {
    return 0;
}

char CircBuffer::GetNext() {
    return 0;
}

}