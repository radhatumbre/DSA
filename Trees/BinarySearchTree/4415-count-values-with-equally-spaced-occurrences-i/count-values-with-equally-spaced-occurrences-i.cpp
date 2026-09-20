class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        int r = 0;
        std::vector<int> freq(100, 0);
        for (int c : nums) {
            freq[c - 1]++;
        }
        for (int i = 0; i < n; i++) {
            int c = nums[i];
            if (freq[c - 1] != 3) continue;
            freq[c - 1] = -1;
            for (int distance = 1; i + (distance * 2) < n; distance++) {
                if (nums[i + distance] == c && nums[i + (distance * 2)] == c) {
                    r++;
                    break;
                }
            }
        }
        return r;
    }
};