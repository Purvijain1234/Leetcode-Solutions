/*
Problem Number: 0069
Problem Name: Sqrt(x)

Difficulty: Easy

Topics:
Math, Binary Search

Approach:
Use Binary Search to find the square root.

If mid * mid <= x,
store mid as possible answer
and search on right side.

Otherwise,
search on left side.

To avoid overflow:
use x / mid instead of mid * mid.

Time Complexity:
O(log n)

Space Complexity:
O(1)
*/

class Solution {
public:

    int mySqrt(int x) {

        // Square root of 0 is 0
        if(x == 0) {
            return 0;
        }

        int low = 1;
        int high = x;

        int ans = 0;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            // Avoid overflow
            if(mid <= (x / mid)) {

                ans = mid;

                low = mid + 1;
            }

            else {

                high = mid - 1;
            }
        }

        return ans;
    }
};
