//
//  MetalRenderImpl.cpp
//  MetalPractice
//
//  Created by GoodName on 2022/7/4.
//

#include "MetalRenderImpl.h"

#define NS_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#define MTK_PRIVATE_IMPLEMENTATION
#include <Metal/Metal.hpp>
#include <MetalKit/MetalKit.hpp>

#pragma region RenderInternal {
class RenderInternal : public MTK::ViewDelegate {
public:
    RenderInternal(void* view);
    ~RenderInternal();

    // MTK::ViewDelegate
    void drawInMTKView(MTK::View* pView) override;

private:
    void render();
    
private:
    struct {
        MTL::Device* device;
        MTL::CommandQueue* queue;
        MTK::View* view;
    } _metalcore;
};

RenderInternal::RenderInternal(void* view) {
    _metalcore.device = MTL::CreateSystemDefaultDevice();
    _metalcore.queue = _metalcore.device->newCommandQueue();
    _metalcore.view = static_cast<MTK::View*>(view);
    _metalcore.view->setDevice(_metalcore.device);
    _metalcore.view->setDelegate(this);
    _metalcore.view->setColorPixelFormat( MTL::PixelFormat::PixelFormatBGRA8Unorm_sRGB );
    _metalcore.view->setClearColor( MTL::ClearColor::Make( 1.0, 0.0, 0.0, 1.0 ) );
}

RenderInternal::~RenderInternal() {
    if (_metalcore.queue) {
        _metalcore.queue->release();
        _metalcore.queue = nullptr;
    }
    if (_metalcore.device) {
        _metalcore.device->release();
        _metalcore.device = nullptr;
    }
}

void RenderInternal::render() {
    NS::AutoreleasePool* releasePool = NS::AutoreleasePool::alloc()->init();

    MTL::CommandBuffer* cmdBuf = _metalcore.queue->commandBuffer();
    MTL::RenderPassDescriptor* desc = _metalcore.view->currentRenderPassDescriptor();
    if (desc == nullptr) {
        assert(!"Error occur!");
        printf("currentRenderPassDescriptor return nullptr\n");
        return;
    }
    MTL::RenderCommandEncoder* encoder = cmdBuf->renderCommandEncoder(desc);
    encoder->endEncoding();
    cmdBuf->presentDrawable(_metalcore.view->currentDrawable());
    cmdBuf->commit();

    releasePool->release();
}

// MTK::ViewDelegate
void RenderInternal::drawInMTKView(MTK::View* pView) {
    render();
}
#pragma endregion RenderInternal }

#pragma region MetalRenderImpl {
MetalRenderImpl::MetalRenderImpl(void* view) {
    _core.render = std::make_shared<RenderInternal>(view);
}

MetalRenderImpl::~MetalRenderImpl() {
    _core.render.reset();
}
#pragma endregion MetalRenderImpl }
