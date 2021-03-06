
#ifndef __cleErodeSphereKernel_h
#define __cleErodeSphereKernel_h

#include "cleKernel.h"

namespace cle
{
    
class ErodeSphereKernel : public Kernel
{

private:
    std::string source_2d = 
        #include "cle_erode_sphere_2d.h" 
        ;
    std::string source_3d = 
        #include "cle_erode_sphere_3d.h" 
        ;

public:
    ErodeSphereKernel(GPU& gpu) : 
        Kernel( gpu,
                "erode_sphere",
                {"src" , "dst"}
        )
    {
        m_Sources.insert({this->m_KernelName + "_2d", source_2d});
        m_Sources.insert({this->m_KernelName + "_3d", source_3d});
    }
    void SetInput(Buffer&);
    void SetOutput(Buffer&);
    void Execute();

};

} // namespace cle

#endif // __cleErodeSphereKernel_h
