//
//  GLBWebviewUtils.h
//  Pods
//
//  Created by felipe.ramos on 2/16/16.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GLBGlobals.h"

@interface GLBWebviewUtils : NSObject

+ (void)setCookie:(NSString*)name withValue:(NSString *)value forDomain:(NSString *)domain;
+ (void)unsetGLBIDCookieForDomain:(NSString *)domain;
+ (void)setCookie:(NSHTTPCookie*)cookie;
+ (NSHTTPCookie *)buildCookieWithName:(NSString*)name withValue:(NSString *)value forDomain:(NSString *)domain;

@end
