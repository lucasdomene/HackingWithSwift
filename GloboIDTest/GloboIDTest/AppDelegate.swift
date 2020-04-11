//
//  AppDelegate.swift
//  GloboIDTest
//
//  Created by lucas.firmo on 4/8/20.
//  Copyright © 2020 lucas.firmo. All rights reserved.
//

import UIKit
import GloboIDSDK

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        return GloboIDSDK.application(application,
                                      didFinishLaunchingWithOptions: launchOptions,
                                      appID: "domene.GloboIDTest",
                                      googleClientID: "609490452886-4ueeh66u2frpt8lif5pcl7tl4uqe4sh0.apps.googleusercontent.com",
                                      googleAppID: "1:609490452886:ios:4bd72858a066cd9dcd1db7",
                                      gcmSenderID: "609490452886")
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }


}

