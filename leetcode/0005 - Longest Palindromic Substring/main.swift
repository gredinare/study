class Solution {
    func longestPalindrome(_ s: String) -> String {

        let firstIndex = s.startIndex
        let lastIndex = s.index(before: s.endIndex)

        var palindrome = ""

        print("first index: \(s[firstIndex]) \(firstIndex)")
        print("last  index: \(s[lastIndex]) \(lastIndex)")
        print()

        var index = s.startIndex
        
        while index <= lastIndex {
            print("char: \(s[index]) - index: \(index)")

            var nextIndex = index
            var isSameChar = true

            while (nextIndex <= s.endIndex && isSameChar) {
                print("char index: \(s[index]) \(index)")
                print("char next : \(s[nextIndex]) \(nextIndex)")
                
                let tempIndex = s.index(after: nextIndex)
                let isSame = tempIndex <= lastIndex && s[tempIndex] == s[index]

                if (isSame) {
                    nextIndex = s.index(after: nextIndex)
                } else {
                    isSameChar = false
                }
            }

            var left = index
            var right = nextIndex

            var excededLimit = false

            while !excededLimit {
                if (s[left] != s[right]) {
                    excededLimit = true
                } else {
                    let tempPalindrome = s[left...right]

                    if(tempPalindrome.count > palindrome.count) {
                        palindrome = String(tempPalindrome)
                    }

                    if (left > firstIndex && right < lastIndex) {
                        left = s.index(before: left)
                        right = s.index(after: right)
                    } else {
                        excededLimit = true
                    }
                }
            }

            index = s.index(after: nextIndex)
            print()
        }
        return palindrome
    }
}

let sol = Solution()
let test = sol.longestPalindrome("AAABCCDIHJHIDDEFGHIIJ")

print(test)