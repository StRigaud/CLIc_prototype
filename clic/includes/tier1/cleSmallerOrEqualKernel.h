

#ifndef __cleSmallerOrEqualKernel_h
#define __cleSmallerOrEqualKernel_h

#include "cleKernel.h"

namespace cle
{
    
class SmallerOrEqualKernel : public Kernel
{

private:
    std::string source_2d = 
        #include "cle_smaller_or_equal_2d.h" 
        ;
    std::string source_3d = 
        #include "cle_smaller_or_equal_3d.h" 
        ;

public:
    SmallerOrEqualKernel(GPU& gpu) : 
        Kernel( gpu,
                "smaller_or_equal",
                {"src1" , "src2", "dst"}
        )
    {
        m_Sources.insert({this->m_KernelName + "_2d", source_2d});
        m_Sources.insert({this->m_KernelName + "_3d", source_3d});
    }
    void SetInput1(Buffer&);
    void SetInput2(Buffer&);
    void SetOutput(Buffer&);
    void Execute();

};

} // namespace cle

#endif // __cleSmallerKernel_h
