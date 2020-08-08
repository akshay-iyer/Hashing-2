// Brute force would be to calculate rSum from each index and check if 0 is reached

// Time Complexity : O(n) 
// Space Complexity : O(n) // hashmap 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: COUNT NUMBER OF EVEN CHARS AND INCLUDE 1 ODD CHAR IF PRESENT FOR CENTER ELEMENT

// [***] BEWARE: CASES LIKE CCC; HERE COUNT 2 IN THE EVEN PASS AND THEN COUNT 1 IN THE ODD PASS

// Your code here along with comments explaining your approach
// 1. Maintain a map of counts of each char
// 2. Even Pass:  Iterate thru the map and see max even count which can be extracted from the number
// 3. Odd Pass: Find, if exists, just one odd char and break

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==0)
            return 0;
        unordered_map<char, int> tracker;
        int len = 0;
        for(auto c: s){
            tracker[c]++;
        }
        // checking for all even chars
        for(auto itr: tracker){
            if(itr.second%2 == 0){
                len += itr.second;
                itr.second = 0;
            }
            // for cases like ccc
            else if(itr.second>1){
                len += itr.second-1;
                itr.second=1;
            }
        }
        // checking for just one odd char
        for(auto itr: tracker){
            if(itr.second%2 != 0){
                len++;
                break;
            }
        }
        return len;
    }
};