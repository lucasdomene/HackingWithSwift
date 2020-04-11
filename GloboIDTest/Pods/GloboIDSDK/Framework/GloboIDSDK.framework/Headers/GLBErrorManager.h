//
//  GLBErrorManager.h
//  Pods
//
//  Created by Leandro Silva on 8/6/15.
//  Copyright © 2015 Globo.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GLBGlobals.h"

typedef NS_ENUM (NSInteger, ErrorType) {
    ErrorTypeCanceledFacebookLogin,
    ErrorTypeFacebookConnection,
    ErrorTypeFetchUser,
    ErrorTypeFlowHealthcheck,
    ErrorTypeLogin,
    ErrorTypeLogout,
    ErrorTypeOfflineInternet,
    ErrorTypePushNotification,
    ErrorTypePushTimeout,
    ErrorTypeRegister,
    ErrorTypeServer,
    ErrorTypeUnknown
};



@interface GLBErrorManager : NSObject

+ (NSError *)errorWithErrorType:(ErrorType)errorType;

@end
