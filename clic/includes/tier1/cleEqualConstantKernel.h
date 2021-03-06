
#ifndef __cleEqualConstantKernel_h
#define __cleEqualConstantKernel_h

#include "cleKernel.h"

namespace cle
{
    
class EqualConstantKernel : public Kernel
{

private:
    std::string source_2d = 
        #include "cle_equal_constant_2d.h" 
        ;
    std::string source_3d = 
        #include "cle_equal_constant_3d.h" 
        ;

public:
    EqualConstantKernel(GPU& gpu) : 
        Kernel( gpu, 
                "equal_constant",
                {"src1", "scalar", "dst"}
        )
    {
        m_Sources.insert({this->m_KernelName + "_2d", source_2d});
        m_Sources.insert({this->m_KernelName + "_3d", source_3d});
    }
    void SetInput(Buffer&);
    void SetOutput(Buffer&);
    void SetScalar(float);
    void Execute();
};

} // namespace cle

#endif // __cleEqualConstantKernel_h
