#ifndef CUECOLOURCLASS_H
#define CUECOLOURCLASS_H
#include <cstdint>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>

class CUEColourClass
{
public:
    CUEColourClass()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created CUEColourClass" << std::endl;
#endif
    }
    // Colours are possibly in format 0xRRGGBBAA
    // FIXME: verify that the above is true
    uint32_t first;
    uint32_t second;
    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(CEREAL_NVP(first), CEREAL_NVP(second));
    }
};

#endif // CUECOLOURCLASS_H
