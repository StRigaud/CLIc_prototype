

#ifndef __cleMinimumXProjectionKernel_h
#define __cleMinimumXProjectionKernel_h

#include "cleKernel.h"

namespace cle
{
    
class MinimumXProjectionKernel : public Kernel
{

private:
    std::string source = 
        #include "cle_minimum_x_projection.h" 
        ;

public:
    MinimumXProjectionKernel(GPU& gpu) : 
        Kernel( gpu,
                "minimum_x_projection",
                {"dst_min", "src"}
        )
    {
        m_Sources.insert({this->m_KernelName + "", source});
    }
    void SetInput(Buffer&);
    void SetOutput(Buffer&);
    void Execute();
};

} // namespace cle

#endif // __cleMinimumXProjectionKernel_h
