//
//  MetalRenderFactory.cpp
//  MetalPractice
//
//  Created by GoodName on 2022/7/4.
//

#include "MetalRenderFactory.h"

#include "MetalRenderImpl.h"

std::shared_ptr<MetalRender> MetalRenderFactory::createMetalRender(void* view) {
    return std::make_shared<MetalRenderImpl>(view);
}
