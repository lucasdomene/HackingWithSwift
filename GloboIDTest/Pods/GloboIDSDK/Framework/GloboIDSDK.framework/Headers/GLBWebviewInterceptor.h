//
//  GLBWebviewInterceptor.h
//  Pods
//
//  Created by felipe.ramos on 2/16/16.
//
//

#import <Foundation/Foundation.h>

#import "GloboIDSDK.h"
#import "GLBWebviewUtils.h"
#import "GLBWebviewInterceptorAction.h"


@interface GLBWebviewInterceptorDelegate : NSObject<GloboIDSDKDelegate>

@end


@interface GLBWebviewInterceptor : NSObject

+ (GLBWebviewInterceptorDelegate *) delegateForRedirectURL:(NSString *)redirectURL;

+ (GLBWebviewInterceptorAction *) extractActionFromURL:(NSURL *)url;

+ (void) interceptWebview:(NSString *)glbId
         withExecJSHandler:(void(^)(NSString *javascript))jsHandler
         withCookieHandler:(void(^)(NSString *name, NSString *value, NSString *domain))setCookieHandler;

+ (void) interceptWebview:(NSString *)glbId;

+ (void) setCookieDomains:(NSSet<NSString *> *)domains;

@end


