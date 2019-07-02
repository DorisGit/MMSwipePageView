//
//  MMTableView.m
//  MMSwipePageView
//
//  Created by Mikasa on 2019/7/2.
//  Copyright © 2019 Mikasa. All rights reserved.
//

#import "MMTableView.h"

@interface MMTableView ()<UIGestureRecognizerDelegate>

@end

@implementation MMTableView

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer {
    return YES;
}

@end
