//
//  GLBWebviewInterceptorAction.h
//  
//
//  Created by felipe.ramos on 2/22/16.
//
//

#import <UIKit/UIKit.h>


@interface GLBWebviewInterceptorAction : NSObject

@property (nonatomic, strong) NSString *action;
@property (nonatomic, strong) NSString *serviceID;
@property (nonatomic, strong) NSString *url;

- (instancetype) initWith:(NSString *)action andServiceID:(NSString *)sericeID;

- (instancetype) initWith:(NSString *)action andServiceID:(NSString *)sericeID andURL:(NSString *)url;

@end
