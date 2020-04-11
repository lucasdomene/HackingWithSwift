//
//  StoryboardUtil.h
//  Pods
//
//  Created by Leandro Silva on 7/29/15.
//  Copyright © 2015 Globo.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "GLBGlobals.h"

@interface GLBStoryboardUtil : NSObject

+ (UIViewController *)viewControllerWithStoryboard:(NSString *)storyboardName controllerName:(NSString *)controllerName;

@end
