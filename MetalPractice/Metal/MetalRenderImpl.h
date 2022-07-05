//
//  MetalRenderImpl.h
//  MetalPractice
//
//  Created by GoodName on 2022/7/4.
//

#ifndef MetalRenderImpl_h
#define MetalRenderImpl_h

#include <memory>

#include "MetalRender.h"

class RenderInternal;
class MetalRenderImpl : public MetalRender {
public:
    MetalRenderImpl(void* view);
    ~MetalRenderImpl();
private:
    struct {
        std::shared_ptr<RenderInternal> render;
    } _core;
};


#endif /* MetalRenderImpl_h */
