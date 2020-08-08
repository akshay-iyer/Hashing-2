// Brute force would be to calculate rSum from each index and check if 0 is reached

// Time Complexity : O(n) 
// Space Complexity : O(n) // hashmap 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: MAINTAIN RSUM FOR EACH INDEX AND SEE IF SAME RSUM REACHED IN THE PAST. 

// Your code here along with comments explaining your approach
// 1. Add 1 for each 1 and subtract 1 for 0
// 2. Iterate thru array and keep a single rSum variable and maintain earliest index that rSum has occured before
// 3. At each num, check if rSum has already occured in the past. Implies from that point to curr point, there are equal 0s and 1s

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int rSum=0, maxLen=0;
        unordered_map<int,int> sum;
        sum[0] = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0)
                rSum--;
            else
                rSum++;
            if(sum.find(rSum) != sum.end())
                maxLen = max(maxLen, i-sum[rSum]);
            else
                sum[rSum] = i;
        }
        return maxLen;
    }
};