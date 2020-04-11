//
//  GLBLoginDelegate.h
//  globoid-sdk-ios
//
//  Created by Cristiano Matte on 16/03/17.
//  Copyright © 2017 globo.com. All rights reserved.
//

@protocol GLBLoginDelegate <NSObject>

@required
- (void)didLoginWithUser:(GloboUser *)globoUser;
- (void)didCancelLogin;
- (void)loginDidFailWithError:(NSError *)error viewController:(UIViewController *)viewController;
- (void)didLogout;

@optional
- (void)didFinishPendingActivation;
- (void)startLoginWithEmail:(NSString *)email;

@end
