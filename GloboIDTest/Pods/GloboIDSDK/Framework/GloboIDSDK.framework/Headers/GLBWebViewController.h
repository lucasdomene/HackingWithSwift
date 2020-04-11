//
//  WebViewController.h
//  globoid-sdk-ios
//
//  Created by Eduardo Rangel on 7/15/15.
//  Copyright © 2015 Globo.com. All rights reserved.
//

#import "GLBErrorManager.h"
#import "GLBGlobals.h"
#import "GloboUser.h"
#import "GloboIDSDK.h"
#import "GLBLoginDelegate.h"

@class GLBWebViewController;

typedef NS_ENUM (NSInteger, FlowURLType) {
    FlowURLTypeLogin,
    FlowURLTypeLoginWithoutSignUp,
    FlowURLTypeLoginFacebook,
    FlowURLTypeRegisterUser,
    FlowURLTypeRestorePassword,
    FlowURLTypePendingActivation,
    FlowURLTypeProvisioning,
    FlowURLTypePrivacyPolicy,
    FlowURLTypeUseTerms
};

@interface GLBWebViewController : UIViewController <WKNavigationDelegate, WKUIDelegate>

@property (nonatomic, copy) void (^onClose)(void);
@property (nonatomic, strong) id <GLBLoginDelegate> delegate;
@property (nonatomic, assign) FlowURLType flowURLType;
@property (nonatomic, strong) NSString *appID;
@property (nonatomic, strong) NSString *serviceID;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *userID;
@property (nonatomic, strong) NSString *facebookCurrentAccessToken;
@property (nonatomic, strong) GloboUser *user;

@end
