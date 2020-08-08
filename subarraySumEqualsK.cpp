// Brute force would be to calculate rSum from each index and check if k is reached

// Time Complexity : O(n) 
// Space Complexity : O(n) // hashmap 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: REMEMBER -VE VALUES ALLOWED. MAINTAIN AN RSUM AND SEE IN MAP IF RSUM-K HAS OCCURED BEFORE 

// Your code here along with comments explaining your approach
// 1. Iterate thru array and keep a single rSum variable and maintain number of times that rSum has occured before
// 2. At each num, check if rSum-k has already occured in the past. Implies from that point to curr point, sum = k. Hence increase count

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0)
            return 0;
        unordered_map<int,int> sum;
        int rSum = 0, count=0;
        sum[rSum] = 1;
        for(auto  num: nums){
            rSum += num;
            if(sum.find(rSum-k) != sum.end())
                count += sum[rSum-k];
            sum[rSum]++;
        }
        return count;
    }
};