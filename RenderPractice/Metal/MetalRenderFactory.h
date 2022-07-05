//
//  MetalRenderFactory.h
//  MetalPractice
//
//  Created by GoodName on 2022/7/4.
//

#ifndef MetalRenderFactory_h
#define MetalRenderFactory_h

#include <memory>

#include "MetalRender.h"

class MetalRenderFactory {
public:
    static std::shared_ptr<MetalRender> createMetalRender(void* view);
};

#endif /* MetalRenderFactory_h */
