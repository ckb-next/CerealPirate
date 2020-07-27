#ifndef ACTIONEVENTBASE_H
#define ACTIONEVENTBASE_H

class ActionEventBase
{
public:
    ActionEventBase()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created ActionEventBase" << std::endl;
#endif
    }
    virtual void Dummy() = 0;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        (void)ar;
    }
};
CEREAL_CLASS_VERSION(ActionEventBase, 200)
#endif // ACTIONEVENTBASE_H
