#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity: O(n) We traverse the array once, where n is the size of the array. Each prefix sum operation and hashmap lookup is O(1) on average.

// Space Complexity: O(n) In the worst case, all prefix sums are distinct and stored in the hashmap, so space grows linearly with input size.

class Solution {
public:
    // Function to find count of subarrays with sum equal to k using prefix sums and hashmap
    int subarraySum(vector<int>& arr, int k) {
        // Size of the array
        int n = arr.size();

        // Map to store frequency of prefix sums
        unordered_map<int, int> prefixSumCount;

        // Initialize prefix sum and count of subarrays
        int prefixSum = 0;
        int count = 0;

        // Base case: prefix sum 0 has occurred once
        prefixSumCount[0] = 1;

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // Add current element to prefix sum
            prefixSum += arr[i];

            // Calculate the prefix sum that needs to be removed
            int remove = prefixSum - k;

            // If this prefix sum has been seen before,
            // add its count to the result
            if (prefixSumCount.find(remove) != prefixSumCount.end()) {
                count += prefixSumCount[remove];
            }

            // Update the frequency of the current prefix sum
            prefixSumCount[prefixSum]++;
        }

        // Return the total count of subarrays
        return count;
    }
};

int main() {
    // Input array
    vector<int> arr = {3, 1, 2, 4};

    // Target sum
    int k = 6;

    // Create Solution object
    Solution sol;

    // Call function and store result
    int result = sol.subarraySum(arr, k);

    // Print the count of subarrays
    cout << "The number of subarrays is: " << result << "\n";

    return 0;
}
