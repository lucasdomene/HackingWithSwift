//
//  DetailViewController.swift
//  Project1
//
//  Created by lucas.firmo on 3/21/20.
//  Copyright © 2020 lucas.firmo. All rights reserved.
//

import UIKit

class DetailViewController: UIViewController {

    @IBOutlet var imageView: UIImageView!
    
    var selectedImage: String?
    var numberOfPictures: Int?
    var pictureIndex: Int?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        setImage()
        setTitle()
        addShareButton()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        navigationController?.hidesBarsOnTap = true
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        navigationController?.hidesBarsOnTap = false
    }
    
    func setImage() {
        if let selectedImage = selectedImage {
            imageView.image = UIImage(named: selectedImage)
        }
    }
    
    func setTitle() {
        if let numberOfPictures = numberOfPictures,
            let pictureIndex = pictureIndex {
            title = "\(pictureIndex) of \(numberOfPictures)"
        }
    }
    
    func addShareButton() {
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .action, target: self, action: #selector(shareTapped))
    }
    
    @objc
    func shareTapped() {
        guard let image = imageView.image?.jpegData(compressionQuality: 0.8) else {
            return
        }
        
        let viewController = UIActivityViewController(activityItems: [image], applicationActivities: [])
        viewController.popoverPresentationController?.barButtonItem = navigationItem.rightBarButtonItem
        present(viewController, animated: true)
    }
}
