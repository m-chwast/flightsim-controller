#pragma once

#include <array>

namespace Utils {

template <unsigned size>
class CircBuffer {
    std::array<char, size> _data;

};

}