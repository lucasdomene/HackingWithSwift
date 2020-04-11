//
//  GloboIDSDK.h
//  Pods
//
//  Created by Eduardo Rangel on 6/23/15.
//  Copyright © 2015 Globo.com. All rights reserved.
//

#import "GloboUser.h"
#import <WebKit/WebKit.h>

# pragma ------------------------------------------------------------
# pragma mark GloboIDSDKDelegate

/*!
 @brief      It must be implemented by the <i>ViewController</i> from where the <i>GloboID SDK</i> will be shown.
 @discussion These are the <i>GloboID SDK</i> callbacks.
 */
@protocol GloboIDSDKDelegate <NSObject>
@required


# pragma ------------------------------------------------------------
# pragma mark Login

/*!
 @brief      The callback for the method <i>loginWithServiceID:viewController:</i> when the login is successful.
 @param      globoUser The logged user.
 */
- (void)globoUserDidLogin:(GloboUser *)globoUser;

@optional

/*!
 @brief      The callback for the method <i>loginWithServiceID:viewController:</i> when the user cancels the login.
 */
- (void)globoUserDidCancelLogin;


/*!
 @brief      The callback for the method <i>loginWithServiceID:viewController:</i> when the login fails.
 @param      viewController The initial <i>ViewController</i> of <i>GloboID SDK</i>.
 @param      error          The error returned when the login fails.
 */
- (void)loginDidFailWithViewController:(UIViewController *)viewController error:(NSError *)error;


# pragma ------------------------------------------------------------
# pragma mark Logout

/*!
 @brief      The callback for the method <i>logoutWithViewController:</i> when the user will logout.
 @param      globoUser The user that will logout.
 */
- (void)globoUserWillLogout:(GloboUser *)globoUser;


/*!
 @brief      The callback for the method <i>logoutWithViewController:</i> when the logout is successful.
 */
- (void)globoUserDidLogout;


/*!
 @brief      The callback for the method <i>logoutWithViewController:</i> when the logout fails.
 @param      error The error returned when the logout fails.
 */
- (void)logoutDidFailWithError:(NSError *)error;


# pragma ------------------------------------------------------------
# pragma mark User Authorization

/*!
 @brief      The callback for the <i>checkUser:authorizationForServiceID:</i> method.
 @param      globoUser         The user that has been authorized for a specific <i>Globo.com</i>'s service
 @param      hasBeenAuthorized <i>YES</i> if the user is authorized to access the specific <i>Globo.com</i>'s service ID passed to the <i>checkUser:authorizationForServiceID:</i> method.
 */
- (void)globoUser:(GloboUser *)globoUser hasBeenAuthorized:(BOOL)hasBeenAuthorized __deprecated_msg("use isLoggedUserAuthorizedForServiceID:completion:, which has its own callback, to check if the user is authorized for a service");;

@end

@protocol GloboIDUserTracingDelegate;
@class GloboIDUserAttribute;

# pragma ------------------------------------------------------------
# pragma mark - GloboIDSDK Class

@interface GloboIDSDK : NSObject

/*! 
 @brief     It must be set by the <i>ViewController</i> that implements <i>GloboIDSDKDelegate</i>.
 */
@property (nonatomic, strong) id <GloboIDSDKDelegate> delegate;


# pragma ------------------------------------------------------------
# pragma mark Singleton

/*!
 @brief     The <i>GloboIDSDK</i> Singleton.
 */
+ (instancetype)sharedManager;


# pragma ------------------------------------------------------------
# pragma mark AppDelegate

/*!
 @brief      It should be the return of the <i>AppDelegate's application:didFinishLaunchingWithOptions:</i> method from <i>Globo.com's</i> client application.
             Receives the same parameters of this method.
 @discussion Example: <b>return [GloboIDSDK application:application didFinishLaunchingWithOptions:launchOptions];</b>
 @param      application   The <i>application</i> parameter from the <i>AppDelegate's application:didFinishLaunchingWithOptions:</i> method.
 @param      launchOptions The <i>launchOptions</i> parameter from the <i>AppDelegate's application:didFinishLaunchingWithOptions:</i> method.
 @param      appID <i>Globo.com's</i> client application identifier. It is recommended to be the Bundle Identifier as standard.
 @return     BOOL Returns <i>YES</i> if the Facebook settings in the <i>plist</i> file has been done correctly.
 */
+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions appID:(NSString *)appID __deprecated_msg("use application:didFinishLaunchingWithOptions:appID:googleClientID:googleAppID:gcmSenderID instead");

/*!
 @brief      It should be the return of the <i>AppDelegate's application:didFinishLaunchingWithOptions:</i> method from <i>Globo.com's</i> client application.
 Receives the same parameters of this method.
 @discussion Example: <b>return [GloboIDSDK application:application didFinishLaunchingWithOptions:launchOptions];</b>
 @param      application   The <i>application</i> parameter from the <i>AppDelegate's application:didFinishLaunchingWithOptions:</i> method.
 @param      launchOptions The <i>launchOptions</i> parameter from the <i>AppDelegate's application:didFinishLaunchingWithOptions:</i> method.
 @param      appID <i>Globo.com's</i> client application identifier. It is recommended to be the Bundle Identifier as standard.
 @param      googleClientID The Client ID provided by Google for the application. It is the CLIENT_ID value in the GoogleService-Info.plist file.
 @return     BOOL Returns <i>YES</i> if the Facebook settings in the <i>plist</i> file has been done correctly.
 */
+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions appID:(NSString *)appID googleClientID:(NSString *)googleClientID __deprecated_msg("use application:didFinishLaunchingWithOptions:appID:googleClientID:googleAppID:gcmSenderID instead");

/*!
 @brief      It should be the return of the <i>AppDelegate's application:didFinishLaunchingWithOptions:</i> method from <i>Globo.com's</i> client application.
 Receives the same parameters of this method.
 @discussion Example: <b>return [GloboIDSDK application:application didFinishLaunchingWithOptions:launchOptions];</b>
 @param      application   The <i>application</i> parameter from the <i>AppDelegate's application:didFinishLaunchingWithOptions:</i> method.
 @param      launchOptions The <i>launchOptions</i> parameter from the <i>AppDelegate's application:didFinishLaunchingWithOptions:</i> method.
 @param      appID <i>Globo.com's</i> client application identifier. It is recommended to be the Bundle Identifier as standard.
 @param      googleClientID The Client ID provided by Google for the application. It is the CLIENT_ID value in the GoogleService-Info.plist file.
 @param      googleAppID The App ID provided by Google for the application. It is the GOOGLE_APP_ID value in the GoogleService-Info.plist file.
 @param      gcmSenderID The GCM Sender ID provided by Google for the application. It is the GCM_SENDER_ID value in the GoogleService-Info.plist file.
 @return     BOOL Returns <i>YES</i> if the Facebook settings in the <i>plist</i> file has been done correctly.
 */
+ (BOOL)application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
              appID:(NSString *)appID
     googleClientID:(NSString *)googleClientID
        googleAppID:(NSString *)googleAppID
        gcmSenderID:(NSString *)gcmSenderID;

/*!
 @brief      It should be the return of the <i>AppDelegate's application:openURL:sourceApplication:annotation:</i> method from <i>Globo.com's</i> client application.
             Receives the same parameters of this method.
 @discussion Example: <b>return [GloboIDSDK application:application openURL:url sourceApplication:sourceApplication annotation:annotation];</b>
 @param      application       The <i>application</i> parameter from the <i>AppDelegate's application:openURL:sourceApplication:annotation:</i> method.
 @param      openURL           The <i>openURL</i> parameter from the <i>AppDelegate's application:openURL:sourceApplication:annotation:</i> method.
 @param      sourceApplication The <i>sourceApplication</i> parameter from the <i>AppDelegate's application:openURL:sourceApplication:annotation:</i> method.
 @param      annotation        The <i>annotation</i> parameter from the <i>AppDelegate's application:openURL:sourceApplication:annotation:</i> method.
 @return     BOOL Returns <i>YES</i> if the Facebook settings in the <i>plist</i> file has been done correctly.
 */
+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation __deprecated;

+ (BOOL)application:(UIApplication *)app
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;


# pragma ------------------------------------------------------------
# pragma mark Login

/*!
 @brief      Starts the <i>GloboID SDK's</i> login flow.
 @discussion Receives the <i>AppID</i> and the <i>ServiceID</i> parameters from <i>Globo.com's</i> client application and the <i>ViewController</i> from where the <i>GloboID SDK</i> will be shown.
 @param      serviceID <i>Globo.com's</i> client application service identifier.
 @param      viewController The <i>ViewController</i> from where the <i>GloboID SDK</i> will be shown.
 */
- (void)loginWithServiceID:(NSString *)serviceID viewController:(UIViewController *)viewController;

/*!
 @brief      Starts the <i>GloboID SDK's</i> login flow without the option to sign up.
 @discussion Receives the <i>ServiceID</i> parameter from <i>Globo.com's</i> client application and the <i>ViewController</i> from where the <i>GloboID SDK</i> will be shown.
 @param      serviceID <i>Globo.com's</i> client application service identifier.
 @param      viewController The <i>ViewController</i> from where the <i>GloboID SDK</i> will be shown.
 */
- (void)loginHiddingSignUpWithServiceID:(NSString *)serviceID viewController:(UIViewController *)viewController;

- (void)loginWithServiceID:(int)serviceID email:(NSString *)email password:(NSString *)password viewController:(UIViewController *)viewController  __deprecated_msg("use loginWithServiceID:viewController: instead");


/// Starts the sign in flow.
/// @param serviceID client application service identifier.
/// @param viewController the view controller from which the flow will start.
/// @param hideSignUp determines if the sign up button will be shown.
/// @param hideSocialButtons determines if the social buttons will be shown.
- (void)loginWithServiceID:(NSString *)serviceID
            viewController:(UIViewController *)viewController
                hideSignUp:(BOOL)hideSignUp
         hideSocialButtons:(BOOL)hideSocialButtons;

# pragma ------------------------------------------------------------
# pragma mark Sign Up

/*!
 @brief      Starts the <i>GloboID SDK's</i> sign up flow.
 @discussion Receives the the <i>ServiceID</i> parameters from <i>Globo.com's</i> client application and the <i>ViewController</i> from where the <i>GloboID SDK</i> will be shown.
 @param      serviceID <i>Globo.com's</i> client application service identifier.
 @param      viewController The <i>ViewController</i> from where the <i>GloboID SDK</i> will be shown.
 */
- (void)signUpWithServiceID:(NSString *)serviceID viewController:(UIViewController *)viewController;


/// Starts the sign up flow.
/// @param serviceID client application service identifier.
/// @param viewController the view controller from which the flow will start.
/// @param hideSocialButtons determines if the social buttons will be shown.
- (void)signUpWithServiceID:(NSString *)serviceID
             viewController:(UIViewController *)viewController
          hideSocialButtons:(BOOL)hideSocialButtons;
# pragma ------------------------------------------------------------
# pragma mark Logout

/*!
 @brief      It logs the user out of <i>GloboID SDK</i>.
 @discussion This method deletes the <i>user</i> registered on the device.
 */
- (void)logout;


/*!
 @brief      It logs the user out of <i>GloboID SDK</i>.
 @discussion This method deletes the <i>user</i> registered on the device.
 @param      viewController The <i>ViewController</i> from where the <i>GloboID SDK</i> will be shown.
 */
- (void)logoutWithViewController:(UIViewController *)viewController;

- (void)logoutSilently;

# pragma ------------------------------------------------------------
# pragma mark Sessions and Cross Login

/*!
 * @brief   Starts the cross-authentication flow.
 * @param   serviceID  The <i>Globo.com</i>'s service ID to cross-login the user.
 */
- (void)activateRemoteDeviceWithServiceID:(NSString *)serviceID viewController:(UIViewController *)viewController;

/*!
 * @brief   Wait for network event (by mDNS) with user code and start the cross authentication flow.
 */
- (void)startRemoteDeviceDiscovery;

/*!
 * @brief   Stops cross authentication listeners.
 */
- (void)stopRemoteDeviceDiscovery;

- (void) showSessionsViewFrom:(UIViewController *)viewController;

# pragma ------------------------------------------------------------
# pragma mark User Authorization

/*!
 @brief      It checks if the logged user is authorized to access a specific <i>Globo.com</i>'s service.
 @discussion You should implement the <i>user:hasBeenAuthorized:</i> method from <i>GloboIDSDKDelegate</i>. That's the callback for this method.
 @param      serviceID  The <i>Globo.com</i>'s service ID for verification.
 */
- (void)checkLoggedGloboUserAuthorizationForServiceID:(NSString *)serviceID __deprecated_msg("use isLoggedUserAuthorizedForServiceID:completion: instead");

/*!
 @brief      It checks if the user is authorized to access a specific <i>Globo.com</i>'s service.
 @discussion You should implement the <i>user:hasBeenAuthorized:</i> method from <i>GloboIDSDKDelegate</i>. That's the callback for this method.
 @param      globoUser  The user to be checked the authorization.
 @param      serviceID  The <i>Globo.com</i>'s service ID for verification.
 */
- (void)checkGloboUser:(GloboUser *)globoUser authorizationForServiceID:(NSString *)serviceID __deprecated_msg("use isLoggedUserAuthorizedForServiceID:completion: instead");


/*!
 @brief      It checks if the logged is authorized to access a specific <i>Globo.com</i>'s service.
 @param      serviceID  The <i>Globo.com</i>'s service ID for verification.
 @param      callback   A callback function with a boolean value that says if user is logged or not
 */
- (void)checkLoggedUserAuthorizationForServiceID:(NSString *)serviceID withCallback:(void (^)(BOOL isAuthorized))callback __deprecated_msg("use isLoggedUserAuthorizedForServiceID:completion: instead");;


/*!
 @brief      Verifies if the logged user status is pending.
 @param      callback   A callback function with a boolean value that says if user is pending or not and an error that informs any error that may occurs.
 */
- (void)isLoggedUserPendingWithCompletion:(void (^)(BOOL pending, NSError *error))completion;

/*!
 @brief      Verifies if the logged user is authorized to access a specific service.
 @param      serviceID  The service ID for verification.
 @param      callback   A callback function with a boolean value that says if user is authorized or not and an error that informs any error that may occurs.
 */
- (void)isLoggedUserAuthorizedForServiceID:(NSString *)serviceID completion:(void (^)(BOOL authorized, NSError *error))completion;

# pragma ------------------------------------------------------------
# pragma mark User Data Enhancement

/*!
 @brief      Checks if a given `GloboUser` has missing data fields among a set of fields.
 @param      user                The `GloboUser` which `requiredData` should be verified.
 @param      requiredData        The data fields to verify whether the user has or not.
 @param      completionHandler   A completion block with a boolean value that informs whether the user has any missing data among `requiredData` and an error that informs any error that may occurs.
 */
- (void)checkMissingDataForUser:(GloboUser *)user requiredData:(NSSet<NSNumber *> *)requiredData completion:(void (^)(BOOL hasMissingData, NSError *error))completionHandler;

/*!
 @brief      Request any missing data field from a given `GloboUser`.
 @param      viewController      The UIViewController from where the GloboID SDK will be shown.
 @param      user                The `GloboUser` which `requiredData` should be requested.
 @param      requiredData        The data fields to be requested if missing.
 @param      completionHandler   A completion block with a boolean value that informs whether the user has fulfilled the requested data and an error that informs any error that may occurs.
 */
- (void)requestMissingDataWithViewController:(UIViewController *)viewController user:(GloboUser *)user requiredData:(NSSet<NSNumber *> *)requiredData serviceID:(NSString *) serviceID completion:(void (^)(BOOL success, NSError *error))completionHandler;

# pragma ------------------------------------------------------------
# pragma mark WebviewInterceptor

- (void)interceptWKWebview:(WKWebView *)webview;

- (void)interceptUIWebview:(UIWebView *)webview;

- (void)interceptWebviewForDomains:(NSSet<NSString *> *)domains;

- (BOOL)intercept:(NSURLRequest *)request viewController:(UIViewController *)viewController;

# pragma ------------------------------------------------------------
# pragma mark Configuration

/*!
@brief      Configures the request timeouts for every HTTP Request.
@param      timeout The timeout in seconds.
*/

+ (void)configureRequestTimeout:(NSTimeInterval) timeout NS_SWIFT_NAME(configureRequestTimeout(with:));

# pragma ------------------------------------------------------------
# pragma mark User Tracing

/*!
@brief      Registers the user tracing delegate to be informed of any user actions occurring in the SDK.
@param      tracingDelegate The implementation of <i>GloboIDUserTracingDelegate</i> which will be informed of the actions executed in the SDK.
*/

+ (void)registerUserTracingDelegate:(id<GloboIDUserTracingDelegate>) tracingDelegate NS_SWIFT_NAME(registerUserTracingDelegate(_:));

/*!
@brief      Unregisters the user tracing delegate.
*/
+ (void)unregisterUserTracingDelegate;

# pragma ------------------------------------------------------------
# pragma mark User Attributes


/// Gets the current user's attributes
/// @param completion The completion block to be called after the execution
- (void)getUserAttributesWithCompletion:(void (^ _Nonnull)(NSArray<GloboIDUserAttribute *> * _Nullable attributes, NSError * _Nullable error))completion;


/// Saves an user attribute.
/// @param clientID The client ID responsible for the attribute
/// @param attribute The attribute to be saved
/// @param completion The completion block to be called after the execution
- (void)saveUserAttributeWithClientID:(NSString * _Nonnull)clientID
                            attribute:(GloboIDUserAttribute * _Nonnull)attribute
                           completion:(void (^ _Nonnull)(NSError * _Nullable error ))completion;

# pragma ------------------------------------------------------------
# pragma mark  Information

/*!
 @brief      Returns the current AppID.
 */
- (NSString *)currentAppID;


/*!
 @brief      Returns the logged GloboUser.
 */
- (GloboUser *)loggedGloboUser __deprecated_msg("use loggedUserWithCompletion: instead");


/*!
 @brief      Returns the GLBID of logged GloboUser.
 */
- (NSString *)loggedGloboUserGLBID __deprecated_msg("use loggedUserWithCompletion: instead");

/*!
 @brief      It checks if the user is logged in using <i>GloboID SDK</i>.
 @discussion It searches the <i>user</i> registered on the device.
 @return     BOOL Returns <i>YES</i> if the user is logged in.
 */
- (BOOL)isGloboUserLogged __deprecated_msg("use isUserLoggedWithCompletion: instead");

/*!
 @brief      Verifies if there is a user logged, validating the session on the server.
 @param      completion   A completion block with a boolean value that says if there is a user logged or not and an error that informs any error that may occurs.
 */
- (void)isUserLoggedWithCompletion:(void (^)(BOOL isUserLogged, NSError *error))completion;

/*!
 @brief      Fetches the current logged user data, if any, validating the session on the server.
 @param      completion   A completion block with the logged user, if any, and an error that informs any error that may occurs.
 */
- (void)loggedUserWithCompletion:(void (^)(GloboUser* globoUser, NSError *error))completion;

@end
