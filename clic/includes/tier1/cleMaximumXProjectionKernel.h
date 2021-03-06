    
#ifndef __cleMaximumXProjectionKernel_h
#define __cleMaximumXProjectionKernel_h

#include "cleKernel.h"

namespace cle
{
    
class MaximumXProjectionKernel : public Kernel
{

private:
    std::string source = 
        #include "cle_maximum_x_projection.h" 
        ;

public:

    MaximumXProjectionKernel(GPU& gpu) : 
        Kernel( gpu,
                "maximum_x_projection",
                {"dst_max", "src"}
        )
    {
        m_Sources.insert({this->m_KernelName + "", source});
    }
    void SetInput(Buffer&);
    void SetOutput(Buffer&);
    void Execute();
};

} // namespace cle

#endif // __cleMaximumXProjectionKernel_h
