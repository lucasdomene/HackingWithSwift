//
//  GLBGlobals.h
//  Pods
//
//  Created by Eduardo Rangel on 7/8/15.
//  Copyright © 2015 Globo.com. All rights reserved.
//

#import <Foundation/Foundation.h>

# pragma ------------------------------------------------------------
# pragma mark VERSION

extern NSString * const kGeneralSDKVersion;


# pragma ------------------------------------------------------------
# pragma mark - FAKE VALUES

extern NSString * const kFakeFacebookAppExpiration;


# pragma ------------------------------------------------------------
# pragma mark - GENERAL

extern NSString * const kGeneralEmpty;
extern NSString * const kGeneralSDKGLBID;
extern NSString * const kGeneralErrorDomain;


# pragma ------------------------------------------------------------
# pragma mark - MODELS

extern NSString * const kModelUserEmail;
extern NSString * const kModelUserGender;
extern NSString * const kModelUserGLBID;
extern NSString * const kModelUserID;
extern NSString * const kModelUserName;
extern NSString * const kModelUserPhone;
extern NSString * const kModelUserPhotoURL;
extern NSString * const kModelUserBirthdate;
extern NSString * const kModelUserGloboId;

extern NSString * const kModelPhoneAreaCode;
extern NSString * const kModelPhoneConfirmed;
extern NSString * const kModelPhoneHas;
extern NSString * const kModelPhoneNumber;


# pragma ------------------------------------------------------------
# pragma mark - PARAMETERS

extern NSString * const kParameterHeaderGLBID;


# pragma ------------------------------------------------------------
# pragma mark - REGEX

extern NSString * const kRegexWebView;
extern NSString * const kRegexGLBIDCookie;


# pragma ------------------------------------------------------------
# pragma mark - STORYBOARD

extern NSString * const kMainStoryboard;
extern NSString * const kWebViewController;


# pragma ------------------------------------------------------------
# pragma mark - WEB VIEW INTERCEPTOR

extern NSString * const kWVInterceptionCookie;
extern NSString * const kWVInterceptionActionLogin;
extern NSString * const kWVInterceptionActionLogout;


# pragma ------------------------------------------------------------
# pragma mark - URLS

extern NSString * const kURLBase64CharacterSet;
extern NSString * const kURLFlowLoginFacebookFragment;

extern NSString * const kURLFragmentAppID;
extern NSString * const kURLFragmentActionLogin;
extern NSString * const kURLFragmentActionRegistration;
extern NSString * const kURLFragmentEmail;
extern NSString * const kURLFragmentLogin;
extern NSString * const kURLFragmentName;
extern NSString * const kURLFragmentRegistration;
extern NSString * const kURLFragmentServiceID;
extern NSString * const kURLFragmentTermsOfUser;


# pragma ------------------------------------------------------------
# pragma mark - @interface

@interface GLBGlobals : NSObject

+ (instancetype)sharedGlobals;

@end
