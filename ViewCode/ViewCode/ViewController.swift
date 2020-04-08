//
//  ViewController.swift
//  ViewCode
//
//  Created by lucas.firmo on 4/8/20.
//  Copyright © 2020 lucas.firmo. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    let screen = ViewControllerScreen()
    
    override func loadView() {
        super.loadView()
        
        self.view = screen
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }

}
