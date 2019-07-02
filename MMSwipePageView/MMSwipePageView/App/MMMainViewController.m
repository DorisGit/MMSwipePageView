//
//  MMMainViewController.m
//  Mikasa
//
//  Created by Mikasa on 2019/5/25.
//  Copyright © 2019 Mikasa. All rights reserved.
//

#import "MMMainViewController.h"
#import "MMTableViewCell.h"

@interface MMMainViewController ()<UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) UITableView *table;
@property (nonatomic, strong) NSDictionary *dict;

@end

@implementation MMMainViewController
- (void)viewDidLoad {
    [super viewDidLoad];
    
    UITableView *table = [UITableView new];
    table.delegate = self;
    table.dataSource = self;
    self.table = table;
    [self.view addSubview:self.table];
    
    self.title = @"功能入口";
    [self.table mas_updateConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(MM_APPLICATION_TOP_BAR_HEIGHT);
        make.left.right.bottom.mas_equalTo(0);
    }];
    
    self.dict = @{@"获取数据":@"getIndexData"};
    
    [self.table registerClass:[MMTableViewCell class] forCellReuseIdentifier:[MMTableViewCell defaultReuseIdentifier]];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dict.allKeys.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    MMTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:[MMTableViewCell defaultReuseIdentifier]];
    cell.textLabel.text = self.dict.allKeys[indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    SEL selector = NSSelectorFromString(self.dict.allValues[indexPath.row]);
    if ([self respondsToSelector:selector]) {
        [self performSelector:selector];
    }
}

- (void)getIndexData {
    
}


@end
