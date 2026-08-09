// https://leetcode.com/problems/car-pooling/description/?envType=problem-list-v2&envId=prefix-sum

// There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
// You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.
// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
 

// Example 1:
    // Input: trips = [[2,1,5],[3,3,7]], capacity = 4
    // Output: false
// Example 2:
    // Input: trips = [[2,1,5],[3,3,7]], capacity = 5
    // Output: true
 

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>ans(1001,0);
        for(int i =0;i<trips.size();i++){
            int count = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];
              ans[start]+=count;
              ans[end]-=count;
        }

        int sumCapacity = capacity;
        for(int i =0;i<=1000;i++){
            sumCapacity-=ans[i];
            if(sumCapacity<0){
                return false;
            }
        }

        return true;
    }
};


https://leetcode.com/problems/corporate-flight-bookings/description/?envType=problem-list-v2&envId=prefix-sum

1109. Corporate Flight Bookings
Solved
Medium
Topics
premium lock icon
Companies
There are n flights that are labeled from 1 to n.

You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

// Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.

 

// Example 1:

// Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
// Output: [10,55,45,25,25]
// Explanation:
// Flight labels:        1   2   3   4   5
// Booking 1 reserved:  10  10
// Booking 2 reserved:      20  20
// Booking 3 reserved:      25  25  25  25
// Total seats:         10  55  45  25  25
// Hence, answer = [10,55,45,25,25]
// Example 2:

// Input: bookings = [[1,2,10],[2,2,15]], n = 2
// Output: [10,25]
// Explanation:
// Flight labels:        1   2
// Booking 1 reserved:  10  10
// Booking 2 reserved:      15
// Total seats:         10  25
// Hence, answer = [10,25]


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> book(20002, 0);
        for(int i=0; i<bookings.size(); i++){
            int start = bookings[i][0];
            int end = bookings[i][1];
            int seats = bookings[i][2];
            book[start] += seats;
            book[end+1] -= seats;
        }
        int cap = 0;
        vector<int> ans(n, 0);
        for(int i=1; i<n+1; i++){
            cap += book[i];
            ans[i-1] = cap; 
        }
        return ans;
    }
};

