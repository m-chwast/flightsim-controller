#pragma once

#include "Utils/circ_buffer.hpp"

namespace Drivers {

class Usb {
    constexpr static unsigned _inBufferSize = 256;
    
    Utils::CircBuffer<_inBufferSize> _inBuffer;
};

}
