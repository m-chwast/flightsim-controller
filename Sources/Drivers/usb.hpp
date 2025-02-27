#pragma once

#include <array>

namespace Drivers {

class Usb {
    constexpr static unsigned _inBufferSize = 256;
    std::array<char, _inBufferSize> _inBuffer;
};

}
