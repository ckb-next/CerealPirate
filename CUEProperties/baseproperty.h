#ifndef BASEPROPERTY_H
#define BASEPROPERTY_H
#include <cereal/cereal.hpp>
#include <cereal/archives/xml.hpp>

class BaseProperty
{
public:
    BaseProperty() {}
    virtual void Dummy() = 0;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
       // ar();
        (void)ar;
    }
};
CEREAL_CLASS_VERSION(BaseProperty, 200)

#endif // BASEPROPERTY_H
