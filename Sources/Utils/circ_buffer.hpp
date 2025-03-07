#pragma once

namespace Utils {

class CircBuffer {
private:

    const char* _buff;
    const unsigned _capacity;

    unsigned _size;
    unsigned _curr;

public:

    CircBuffer(char* buff, unsigned size)
        : _buff{buff}, _capacity{size} {

    } 

    unsigned GetCapacity() const;
    unsigned GetSize() const;
};

}