//
//  DetailViewController.swift
//  Project7
//
//  Created by lucas.firmo on 3/28/20.
//  Copyright © 2020 lucas.firmo. All rights reserved.
//

import UIKit
import WebKit

class DetailViewController: UIViewController {

    var webView: WKWebView!
    var detailItem: Petition?

    override func loadView() {
        webView = WKWebView()
        view = webView
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        load()
    }
    
    private func load() {
        guard let detailItem = detailItem else { return }
        
        let html = """
        <html>
            <head>
                <meta name="viewport" content="width=devide-with, initial-scale=1">
                <style> body { font-size: 150%; } </style>
            </head>
            <body>
                \(detailItem.body)
            </body>
        </html>
        """
        
        webView.loadHTMLString(html, baseURL: nil)
    }
    
}
