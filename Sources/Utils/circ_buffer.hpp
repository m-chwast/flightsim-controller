#pragma once

namespace Utils {

class CircBuffer {
private:

    char* const _buff;
    const unsigned _capacity;

    unsigned _size = 0;
    unsigned _curr = 0;

public:

    CircBuffer(char* buff, unsigned size)
        : _buff{buff}, _capacity{size} {
        Clear();
    } 

    unsigned GetCapacity() const;
    unsigned GetSize() const;

    bool Append(char c);

    char Peek() const;
    char GetNext();

    void Clear();
};

}