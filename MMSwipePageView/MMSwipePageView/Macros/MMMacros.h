//
//  MMMacros.h
//  Mikasa
//
//  Created by Mikasa on 2019/5/25.
//  Copyright © 2019 Mikasa. All rights reserved.
//

#ifndef MMMacros_h
#define MMMacros_h

/// 存储应用版本的key
#define MMApplicationVersionKey   @"SBApplicationVersionKey"
/// 应用名称
#define MM_APP_NAME    ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleName"])
/// 应用版本号
#define MM_APP_VERSION ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])
/// 应用build
#define MM_APP_BUILD   ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"])

// 输出日志 (格式: [时间] [哪个方法] [哪行] [输出内容])
#ifdef DEBUG
#define NSLog(format, ...)  printf("\n[%s] %s [第%d行] 💕 %s\n", __TIME__, __FUNCTION__, __LINE__, [[NSString stringWithFormat:format, ##__VA_ARGS__] UTF8String]);
#else

#define NSLog(format, ...)

#endif
// 打印方法
#define MMLogFunc NSLog(@"%s", __func__)
// 打印请求错误信息
#define MMLogError(error) NSLog(@"Error: %@", error)
// 销毁打印
#define MMDealloc NSLog(@"\n =========+++ %@  销毁了 +++======== \n",[self class])

#define MMLogLastError(db) NSLog(@"lastError: %@, lastErrorCode: %d, lastErrorMessage: %@", [db lastError], [db lastErrorCode], [db lastErrorMessage]);

/// 类型相关
#define MM_IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define MM_IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define MM_IS_RETINA ([[UIScreen mainScreen] scale] >= 2.0)

/// 屏幕尺寸相关
#define MM_SCREEN_WIDTH  ([[UIScreen mainScreen] bounds].size.width)
#define MM_SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define MM_SCREEN_BOUNDS ([[UIScreen mainScreen] bounds])
#define MM_SCREEN_MAX_LENGTH (MAX(MM_SCREEN_WIDTH, MM_SCREEN_HEIGHT))
#define MM_SCREEN_MIN_LENGTH (MIN(MM_SCREEN_WIDTH, MM_SCREEN_HEIGHT))

/// 手机类型相关
#define MM_IS_IPHONE_4_OR_LESS  (MM_IS_IPHONE && MM_SCREEN_MAX_LENGTH  < 568.0)
#define MM_IS_IPHONE_5          (MM_IS_IPHONE && MM_SCREEN_MAX_LENGTH == 568.0)
#define MM_IS_IPHONE_6          (MM_IS_IPHONE && MM_SCREEN_MAX_LENGTH == 667.0)
#define MM_IS_IPHONE_6P         (MM_IS_IPHONE && MM_SCREEN_MAX_LENGTH == 736.0)
#define MM_IS_IPHONE_X          (MM_IS_IPHONE && MM_SCREEN_MAX_LENGTH == 812.0)

/// 导航条高度
#define MM_APPLICATION_TOP_BAR_HEIGHT (MM_IS_IPHONE_X?88.0f:64.0f)
/// tabBar高度
#define MM_APPLICATION_TAB_BAR_HEIGHT (MM_IS_IPHONE_X?83.0f:49.0f)
/// 工具条高度 (常见的高度)
#define MM_APPLICATION_TOOL_BAR_HEIGHT_44  44.0f
#define MM_APPLICATION_TOOL_BAR_HEIGHT_49  49.0f
/// 状态栏高度
#define MM_APPLICATION_STATUS_BAR_HEIGHT (MM_IS_IPHONE_X?44:20.0f)


///------
/// iOS Version
///------
#define MMIOSVersion ([[[UIDevice currentDevice] systemVersion] floatValue])

#define MM_iOS7_VERSTION_LATER ([UIDevice currentDevice].systemVersion.floatValue >= 7.0)
#define MM_iOS8_VERSTION_LATER ([UIDevice currentDevice].systemVersion.floatValue >= 8.0)
#define MM_iOS9_VERSTION_LATER ([UIDevice currentDevice].systemVersion.floatValue >= 9.0)
#define MM_iOS10_VERSTION_LATER ([UIDevice currentDevice].systemVersion.floatValue >= 10.0)

#define MM_SYSTEM_VERSION_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define MM_SYSTEM_VERSION_GREATER_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define MM_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define MM_SYSTEM_VERSION_LESS_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define MM_SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)


// KVO获取监听对象的属性 有自动提示
// 宏里面的#，会自动把后面的参数变成c语言的字符串
#define MMKeyPath(objc,keyPath) @(((void)objc.keyPath ,#keyPath))

// 颜色
#define MMColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
// 颜色+透明度
#define MMColorAlpha(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
// 随机色
#define MMRandomColor MMColor(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))
// 根据rgbValue获取对应的颜色
#define MMColorFromRGB(__rgbValue) [UIColor colorWithRed:((float)((__rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((__rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(__rgbValue & 0xFF))/255.0 alpha:1.0]

#define MMColorFromRGBAlpha(rgbValue, a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]


// AppCaches 文件夹路径
#define MMCachesDirectory [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]
// App DocumentDirectory 文件夹路径
#define MMDocumentDirectory [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES) lastObject]

// 系统放大倍数
#define MMScale [[UIScreen mainScreen] scale]

// 设置图片
#define MMImageNamed(__imageName) [UIImage imageNamed:__imageName]

/// 根据hex 获取颜色
#define MMColorFroMMexString(__hexString__) ([UIColor colorFroMMexString:__hexString__])

//  通知中心
#define MMNotificationCenter [NSNotificationCenter defaultCenter]


/// 全局细下滑线颜色 以及分割线颜色
#define MMGlobalBottomLineColor     [UIColor colorFroMMexString:@"#D9D9D9"]

// 是否为空对象
#define MMObjectIsNil(__object)  ((nil == __object) || [__object isKindOfClass:[NSNull class]])

// 字符串为空
#define MMStringIsEmpty(__string) ((__string.length == 0) || MMObjectIsNil(__string))

// 字符串不为空
#define MMStringIsNotEmpty(__string)  (!MMStringIsEmpty(__string))

// 数组为空
#define MMArrayIsEmpty(__array) ((MMObjectIsNil(__array)) || (__array.count==0))

/// 适配iPhone X + iOS 11
#define  MMAdjustsScrollViewInsets_Never(__scrollView)\
do {\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"")\
if ([__scrollView respondsToSelector:NSSelectorFromString(@"setContentInsetAdjustmentBehavior:")]) {\
NSMethodSignature *signature = [UIScrollView instanceMethodSignatureForSelector:@selector(setContentInsetAdjustmentBehavior:)];\
NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];\
NSInteger argument = 2;\
invocation.target = __scrollView;\
invocation.selector = @selector(setContentInsetAdjustmentBehavior:);\
[invocation setArgument:&argument atIndex:2];\
[invocation retainArguments];\
[invocation invoke];\
}\
_Pragma("clang diagnostic pop")\
} while (0)

/// AppDelegate
#define MMSharedAppDelegate ((AppDelegate *)[UIApplication sharedApplication].delegate)

#endif /* MMMacros_h */
