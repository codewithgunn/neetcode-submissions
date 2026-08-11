#include <string>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max-heap storing pair: {count, character}
        priority_queue<pair<int, char>> maxHeap;
        
        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});
        
        string result = "";
        
        while (!maxHeap.empty()) {
            auto [count1, char1] = maxHeap.top();
            maxHeap.pop();
            
            int n = result.length();
            
            // Check if adding char1 creates three identical consecutive characters
            if (n >= 2 && result[n - 1] == char1 && result[n - 2] == char1) {
                // We can't use char1; check if we have a second choice
                if (maxHeap.empty()) {
                    break; // No other characters available, stop building
                }
                
                auto [count2, char2] = maxHeap.top();
                maxHeap.pop();
                
                // Append the second most frequent character
                result.push_back(char2);
                count2--;
                
                // Push char2 back if it still has remaining count
                if (count2 > 0) {
                    maxHeap.push({count2, char2});
                }
                
                // Push char1 back since we didn't use it in this turn
                maxHeap.push({count1, char1});
            } else {
                // Safe to append char1
                result.push_back(char1);
                count1--;
                
                if (count1 > 0) {
                    maxHeap.push({count1, char1});
                }
            }
        }
        
        return result;
    }
};