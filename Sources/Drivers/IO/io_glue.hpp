#include <cstdint>

namespace Drivers::Glue {

class GPIO {
public:

    static void SetBit(void* gpio, uint16_t pin, bool val);
    static bool ReadBit(void* gpio, uint16_t pin);  

};

}