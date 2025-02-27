#pragma once

namespace Utils {

class CircBuffer {
private:

    const char* _buff;
    const unsigned _capacity;
    
public:

    CircBuffer(char* buff, unsigned size)
        : _buff{buff}, _capacity{size} {

    } 

    unsigned GetCapacity() const;

};

}