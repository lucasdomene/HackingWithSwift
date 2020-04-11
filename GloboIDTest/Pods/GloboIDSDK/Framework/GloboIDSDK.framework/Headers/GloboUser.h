//
//  GIDUser.h
//  Pods
//
//  Created by Eduardo Rangel on 6/29/15.
//  Copyright © 2015 Globo.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GLBGlobals.h"
#import "GLBPhone.h"

@interface GloboUser : NSObject

@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *gender;
@property (nonatomic, copy) NSString *glbID;
@property (nonatomic) NSNumber *id_;
@property (nonatomic, readonly, getter=id_) NSNumber *userId;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *photoURL;
@property (nonatomic, strong) GLBPhone *phone;
@property (nonatomic, copy) NSDate *birthdate;
@property (nonatomic, copy) NSString *globoId;


- (instancetype)initWithCoder:(NSCoder *)decoder;
- (void)encodeWithCoder:(NSCoder *)encoder;

@end
