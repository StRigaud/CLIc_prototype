
#ifndef __cleSetKernel_h
#define __cleSetKernel_h

#include "cleKernel.h"

namespace cle
{
    
class SetKernel : public Kernel
{

private:
    std::string source_2d = 
        #include "cle_set_2d.h" 
        ;
    std::string source_3d = 
        #include "cle_set_3d.h" 
        ;

public:
    SetKernel(GPU& gpu) : 
        Kernel( gpu,
                "set",
                {"dst", "value"}
        )
    {
        m_Sources.insert({this->m_KernelName + "_2d", source_2d});
        m_Sources.insert({this->m_KernelName + "_3d", source_3d});
    }
    void SetInput(Buffer&);
    void SetValue(float);
    void Execute();
};

} // namespace cle

#endif // __cleSetKernel_h
