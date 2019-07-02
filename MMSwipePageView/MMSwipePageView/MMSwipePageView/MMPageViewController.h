//
//  MMPageViewController.h
//  MMSwipePageView
//
//  Created by Mikasa on 2019/7/1.
//  Copyright © 2019 Mikasa. All rights reserved.
//

#import "MMBaseViewController.h"

#import "MMPageView.h"
#import "MMPageViewCell.h"


typedef NS_ENUM(NSInteger, MMPageStyle) {
    MMPageStyleMenuTop = 0,// 菜单栏处于顶部
    MMPageStyleMenuMiddle = 1 // 菜单栏处于HeaderView 下方
};

@protocol MMPageViewDataSource <NSObject>

- (NSInteger)pageView:(MMPageView *)pageView numberOfRowsInSection:(NSInteger)section;

- (MMPageViewCell *)pageView:(MMPageView *)pageView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

@optional

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView;


@end


@protocol MMPageViewDelegate <NSObject>

@end

@interface MMPageViewController : MMBaseViewController

@property (nonatomic, strong) MMPageView *pageView;

@property (nonatomic, strong) UIView *menuTitleView;
@property (nonatomic, strong) UIView *headerView;
@property (nonatomic, strong) NSArray<UIViewController *> *containerArray;

/** 页面样式 */
@property (nonatomic, readonly) MMPageStyle style;

@property (nonatomic, weak, nullable) id <MMPageViewDataSource> dataSource;
@property (nonatomic, weak, nullable) id <MMPageViewDelegate> delegate;
@end


