//
//  ViewControllerScreen.swift
//  ViewCode
//
//  Created by lucas.firmo on 4/8/20.
//  Copyright © 2020 lucas.firmo. All rights reserved.
//

import UIKit

protocol CodeView {
    func buildViewHierarchy()
    func setupConstraints()
    func setupAdditionalConfiguration()
    func setupView()
}

extension CodeView {
    func setupView() {
        buildViewHierarchy()
        setupConstraints()
        setupAdditionalConfiguration()
    }
}

final class ViewControllerScreen: UIView {
    
    lazy var button: UIButton = {
        let button = UIButton(frame: .zero)
        button.backgroundColor = .red
        button.setTitle("Fetch", for: .normal)
        button.translatesAutoresizingMaskIntoConstraints = false
        return button
    }()
    
    override init(frame: CGRect = .zero) {
        super.init(frame: frame)
        setupView()
    }
    
    required init?(coder: NSCoder) {
        fatalError()
    }
    
}

extension ViewControllerScreen: CodeView {
    func buildViewHierarchy() {
        addSubview(button)
    }
    
    func setupConstraints() {
        NSLayoutConstraint.activate([
            button.leadingAnchor.constraint(equalTo: leadingAnchor, constant: 15),
            button.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -15),
            button.bottomAnchor.constraint(equalTo: bottomAnchor, constant: -15),
            button.heightAnchor.constraint(equalToConstant: 50),
        ])
    }
    
    func setupAdditionalConfiguration() {
        backgroundColor = .lightGray
    }
}
