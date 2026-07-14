class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // if(nums.size()==1 && nums[0]!=k)    return false;
        int sum =0;
        map<int,int> mp;
        mp[0] = -1;
        for(int i=0; i<nums.size(); i++){
            sum = (sum+nums[i])%k;
            if(mp.find(sum)!=mp.end()){
                if(i-mp[sum]>1)
                    return true;
            } 
            else   mp[sum] = i;
        }
        return false;
    }
};