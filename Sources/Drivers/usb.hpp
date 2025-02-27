#pragma once

#include "Utils/circ_buffer.hpp"

namespace Drivers {

class Usb {
    constexpr static unsigned _inBufferSize = 256;
    
    char _inBufferStorage[_inBufferSize];

    Utils::CircBuffer _inBuffer{_inBufferStorage, sizeof(_inBufferStorage)};
};

}
