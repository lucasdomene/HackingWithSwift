import UIKit

var str = "hello, playground"

extension String {
    
    var capitalizedFirst: String {
        guard let firstLetter = first else { return "" }
        return firstLetter.uppercased() + dropFirst()
    }
    
    subscript(i: Int) -> String {
        return String(self[index(startIndex, offsetBy: i)])
    }
    
    func deletingPrefix(_ prefix: String) -> String {
        guard hasPrefix(prefix) else { return self }
        return String(dropFirst(prefix.count))
    }
    
    func deletingSuffix(_ suffix: String) -> String {
        guard hasSuffix(suffix) else { return self }
        return String(dropLast(suffix.count))
    }
    
}

let words = ["hello", "playground"]

print(str[5])
print(str.deletingPrefix("Hello, "))
print(str.deletingSuffix(", playground"))
print(str.capitalizedFirst)
print(words.contains(where: str.contains))

let attributes: [NSAttributedString.Key: Any] = [
    .foregroundColor: UIColor.white,
    .backgroundColor: UIColor.red,
    .font: UIFont.boldSystemFont(ofSize: 36)
]

let attributedString = NSAttributedString(string: str, attributes: attributes)

let mutableAttributedString = NSMutableAttributedString(string: str)
mutableAttributedString.addAttribute(.font, value: UIFont.systemFont(ofSize: 20), range: NSRange(location: 0, length: 5))
mutableAttributedString.addAttribute(.font, value: UIFont.systemFont(ofSize: 40), range: NSRange(location: 7, length: 10))

