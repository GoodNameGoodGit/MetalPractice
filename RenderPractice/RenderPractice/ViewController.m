//
//  ViewController.m
//  MetalPractice
//
//  Created by GoodName on 2022/7/3.
//

#import "ViewController.h"

#import "MetalViewRender.h"

@interface ViewController ()

@end

@implementation ViewController {
    MetalViewRender* metalView;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    metalView = [[MetalViewRender alloc] initWithView:self.view];
}


@end
