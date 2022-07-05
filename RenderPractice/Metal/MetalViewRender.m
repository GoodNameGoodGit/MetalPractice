//
//  MetalViewDelegate.m
//  MetalPractice
//
//  Created by GoodName on 2022/7/4.
//

#import "MetalViewRender.h"

#include "MetalRenderFactory.h"

@implementation MetalViewRender {
    struct {
        MTKView* mtkView;
        std::shared_ptr<MetalRender> render;
    } _core;
}

- (instancetype)initWithView:(nonnull UIView*)view {
    if (self = [super init]) {
        _core.mtkView = [[MTKView alloc] initWithFrame:CGRectZero];
        _core.mtkView.frame = view.bounds;
        [view addSubview:_core.mtkView];
        _core.render = MetalRenderFactory::createMetalRender((__bridge void*)_core.mtkView);
    }
    return self;
}

@end
