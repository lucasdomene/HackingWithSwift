//
//  ViewController.swift
//  Project 5
//
//  Created by lucas.firmo on 3/22/20.
//  Copyright © 2020 lucas.firmo. All rights reserved.
//

import UIKit

class ViewController: UITableViewController {

    var allWords = [String]()
    var usedWords = [String]()
    
    enum WordError {
        case none
        case notPossible
        case notOriginal
        case notReal
        
        var title: String? {
            switch self {
            case .none:
                return nil
            case .notPossible:
                return "Word not possible"
            case .notOriginal:
                return "Word already used"
            case .notReal:
                return "Word not recognized"
            }
        }
        
        var message: String? {
            switch self {
            case .none:
                return nil
            case .notPossible:
                return "You can't spell that word using the existing letters."
            case .notOriginal:
                return "Be more original!"
            case .notReal:
                return "You can't just make them up!"
            }
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        setupAddButton()
        loadWords()
        startGame()
    }
    
    func setupAddButton() {
        navigationItem.rightBarButtonItem = UIBarButtonItem(
            barButtonSystemItem: .add,
            target: self,
            action: #selector(promptForAnswer)
        )
    }
    
    func loadWords() {
        if let startWordsURL = Bundle.main.url(forResource: "start",
                                               withExtension: "txt"),
            let startWords = try?  String(contentsOf: startWordsURL) {
            allWords = startWords.components(separatedBy: "\n")
        }
        
        if allWords.isEmpty {
            allWords = ["silkworm"]
        }
    }
    
    func startGame() {
        title = allWords.randomElement()
        usedWords.removeAll(keepingCapacity: true)
        tableView.reloadData()
    }
    
    @objc func promptForAnswer() {
        let alertController = UIAlertController(
            title: "Enter answer",
            message: nil,
            preferredStyle: .alert
        )
        alertController.addTextField()
        
        let submitAction = UIAlertAction(title: "Submit", style: .default) {
            [weak self, weak alertController] _ in
            guard let answer = alertController?.textFields?[0].text else { return }
            self?.submit(answer)
        }
        
        alertController.addAction(submitAction)
        present(alertController, animated: true)
    }
    
    func submit(_ answer: String) {
        let lowerAnswer = answer.lowercased()
        var wordError: WordError = .none
        if  isPossible(word: lowerAnswer, error: &wordError),
            isOriginal(word: lowerAnswer, error: &wordError),
            isReal(word: lowerAnswer, error: &wordError) {
            usedWords.insert(lowerAnswer, at: 0)
            
            let indexPath = IndexPath(item: 0, section: 0)
            tableView.insertRows(at: [indexPath], with: .automatic)
        }
        
        if wordError != .none {
            showErrorAlert(forError: wordError)
        }
    }
    
    func isPossible(word: String, error: inout WordError) -> Bool {
        guard var tempWord = title?.lowercased() else { return false }
        
        for letter in word {
            if let position = tempWord.firstIndex(of: letter) {
                tempWord.remove(at: position)
            } else {
                error = .notPossible
                return false
            }
        }
        
        return true
    }
    
    func isOriginal(word: String, error: inout WordError) -> Bool {
        let contains = usedWords.contains(word)
        
        if contains {
            error = .notOriginal
        }
        
        return !contains
    }
    
    func isReal(word: String, error: inout WordError) -> Bool {
        let checker = UITextChecker()
        let range = NSRange(location: 0, length: word.utf16.count)
        let misspelledRange = checker.rangeOfMisspelledWord(
            in: word,
            range: range,
            startingAt: 0,
            wrap: false,
            language: "en"
        )
        
        let isReal = misspelledRange.location == NSNotFound
        
        if !isReal {
            error = .notReal
        }
        
        return isReal
    }
    
    func showErrorAlert(forError error: WordError) {
        let alertController = UIAlertController(title: error.title,
                                                message: error.message,
                                                preferredStyle: .alert)
        let action = UIAlertAction(title: "OK", style: .default)
        alertController.addAction(action)
        present(alertController, animated: true)
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return usedWords.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "Word", for: indexPath)
        cell.textLabel?.text = usedWords[indexPath.row]
        return cell
    }
    
}
