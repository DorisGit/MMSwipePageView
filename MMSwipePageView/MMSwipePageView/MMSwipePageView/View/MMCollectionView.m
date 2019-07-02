//
//  MMCollectionView.m
//  MMSwipePageView
//
//  Created by Mikasa on 2019/7/2.
//  Copyright © 2019 Mikasa. All rights reserved.
//

#import "MMCollectionView.h"

@interface MMCollectionView ()<UIGestureRecognizerDelegate>

@end

@implementation MMCollectionView

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer {
    return YES;
}

@end
