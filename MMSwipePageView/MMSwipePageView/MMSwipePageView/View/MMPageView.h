//
//  MMPageScrollView.h
//  MMSwipePageView
//
//  Created by Mikasa on 2019/7/2.
//  Copyright © 2019 Mikasa. All rights reserved.
//

/*
 //手指触摸屏幕后回调的方法，返回NO则不再进行手势识别，方法触发等
 - (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldReceiveTouch:(UITouch *)touch;
 
 //开始进行手势识别时调用的方法，返回NO则结束，不再触发手势
 - (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer;
 
 //是否支持多手势触发，返回YES，则可以多个手势一起触发方法，返回NO则为互斥
 - (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer;
 
 //下面这个两个方法也是用来控制手势的互斥执行的
 //这个方法返回YES，第一个手势和第二个互斥时，第一个会失效
 - (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRequireFailureOfGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer NS_AVAILABLE_IOS(7_0);
 
 //这个方法返回YES，第一个和第二个互斥时，第二个会失效
 - (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldBeRequiredToFailByGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer NS_AVAILABLE_IOS(7_0);
 
 */


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MMPageView : UIScrollView

@end

NS_ASSUME_NONNULL_END
