//
//  Person.swift
//  Project10
//
//  Created by lucas.firmo on 3/29/20.
//  Copyright © 2020 lucas.firmo. All rights reserved.
//

import UIKit

class Person: NSObject {
    var name: String
    var image: String
    
    init(name: String, image: String) {
        self.name = name
        self.image = image
    }
}
