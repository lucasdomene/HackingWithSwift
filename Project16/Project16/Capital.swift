//
//  Capital.swift
//  Project16
//
//  Created by lucas.firmo on 4/4/20.
//  Copyright © 2020 lucas.firmo. All rights reserved.
//

import Foundation
import MapKit

class Capital: NSObject, MKAnnotation {
    
    var title: String?
    var coordinate: CLLocationCoordinate2D
    var info: String
    
    init(title: String,
         coordinate: CLLocationCoordinate2D,
         info: String) {
        self.title = title
        self.coordinate = coordinate
        self.info = info
    }
    
}
