class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixsum(nums.size(), 0);
        int sum =0;
        for(int i=nums.size()-1; i>=0; i--){
            prefixsum[i] = sum;
            sum += nums[i];
        }

        sum =0;
        for(int i=0; i<nums.size(); i++){
            if(sum==prefixsum[i])   return i;
            sum += nums[i];
        }
        return -1;
    }
};