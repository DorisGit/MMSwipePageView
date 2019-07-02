//
//  MMPageScrollView.m
//  MMSwipePageView
//
//  Created by Mikasa on 2019/7/2.
//  Copyright © 2019 Mikasa. All rights reserved.
//

#import "MMPageView.h"

@interface MMPageView ()<UIGestureRecognizerDelegate>

@end

@implementation MMPageView

#pragma mark - init
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        
    }
    return self;
}

#pragma mark - UIGestureRecognizerDelegate
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer {
    
    return ![self isSupportInteractivePop:gestureRecognizer];
}

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer {
    
    return [self isSupportInteractivePop:gestureRecognizer];
}

/**
 是否支持侧滑返回

 @param gesture 当前收拾
 @return 侧滑返回支持
 */
- (BOOL)isSupportInteractivePop:(UIGestureRecognizer *)gesture {
    
    CGFloat leftWidth = MM_SCREEN_WIDTH * 0.15;
    if (gesture == self.panGestureRecognizer) {
        // 当前手势触摸位置
        CGPoint localPoint = [self.panGestureRecognizer translationInView:self];
        if (gesture.state == UIGestureRecognizerStatePossible || gesture.state == UIGestureRecognizerStateBegan)  {
            // 开始识别的位置在侧边栏 && 移动是右移
            CGPoint startPoint = [gesture locationInView:self];
            if (startPoint.x < leftWidth && localPoint.x > startPoint.x) {
                return YES;
            }
        }
    }
    return NO;
}

@end
