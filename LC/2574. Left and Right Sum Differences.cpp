class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> prefixsum(nums.size(),0);
        int sum =0;
         for(int i=nums.size()-1; i>=0; i--){
            prefixsum[i] = sum;
            sum += nums[i];
        }
        sum =0;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            ans.push_back(abs(sum-prefixsum[i]));
            sum += nums[i];
        }
        return ans;
    }
};