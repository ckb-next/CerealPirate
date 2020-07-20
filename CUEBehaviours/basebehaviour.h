#ifndef BASEBEHAVIOUR_H
#define BASEBEHAVIOUR_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>

class BaseBehaviour
{
public:
    BaseBehaviour(){}
    QString m_typeBehavior;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(m_typeBehavior));
    }
    virtual void Dummy() = 0;
};
CEREAL_CLASS_VERSION(BaseBehaviour, 200)
#endif // BASEBEHAVIOUR_H
