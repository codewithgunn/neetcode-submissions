class Solution:
    def validPalindrome(self, s: str) -> bool:
        # Helper function to check if a substring is a standard palindrome
        def is_palindrome(l: int, r: int) -> bool:
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True

        left, right = 0, len(s) - 1

        while left < right:
            if s[left] != s[right]:
                # On mismatch, try deleting s[left] OR s[right]
                return is_palindrome(left + 1, right) or is_palindrome(left, right - 1)
            
            left += 1
            right -= 1

        return True