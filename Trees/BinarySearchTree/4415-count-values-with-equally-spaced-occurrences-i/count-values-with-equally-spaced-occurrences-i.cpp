class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int> > mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end()){
                vector<int> temp = mp[nums[i]];
                temp.push_back(i);
                
                mp[nums[i]] = temp;
            }
            else mp[nums[i]] = {i};
        }
        vector<int> candidates;
        for(auto i:mp){
            if(i.second.size()==3) candidates.push_back(i.first);
        }
        int count = 0;
        for(int i=0; i<candidates.size(); i++){
            vector<int> arr = mp[candidates[i]];
            if((arr[1]-arr[0])==(arr[2]-arr[1]))    count++;
        }
        return count;
    }
};