//
//  GLBPhone.h
//  Pods
//
//  Created by Eduardo Rangel on 12/14/15.
//
//

#import <Foundation/Foundation.h>
#import "GLBGlobals.h"

@interface GLBPhone : NSObject

@property (nonatomic, strong) NSNumber *areaCode;
@property (nonatomic, strong) NSNumber *phoneNumber;
@property (nonatomic) BOOL confirmed;
@property (nonatomic) BOOL has;

- (instancetype)initWithCoder:(NSCoder *)decoder;
- (void)encodeWithCoder:(NSCoder *)encoder;

@end
