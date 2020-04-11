//
//  GLBObjectUtils.h
//  Pods
//
//  Created by Leandro Silva on 10/29/15.
//
//

#import <Foundation/Foundation.h>

@interface GLBObjectUtils : NSObject

+ (id)build:(NSString *)className withData:(NSData *)data andClassNames:(NSDictionary*)classNames;
+ (NSString *)formatNumbers:(NSArray *)numbers;

@end
