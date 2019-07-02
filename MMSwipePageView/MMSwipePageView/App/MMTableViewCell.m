//
//  MMTableViewCell.m
//  MMSwipePageView
//
//  Created by Mikasa on 2019/7/1.
//  Copyright © 2019 Mikasa. All rights reserved.
//

#import "MMTableViewCell.h"

@implementation MMTableViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

+ (NSString *)defaultReuseIdentifier {
    return NSStringFromClass([self class]);
}
@end
