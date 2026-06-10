/*
Problem Number: 3282
Problem Name: Reach End of Array With Max Score

LeetCode Link:
https://leetcode.com/problems/reach-end-of-array-with-max-score/

Difficulty: Hard

Topics:
Array, Heap (Priority Queue), Sparse Table,
Range Query (RMQ), Greedy

Approach:
We need to repeatedly choose the subarray
with the maximum value:

max(subarray) - min(subarray)

for k operations.

Optimization:
1. Build Sparse Tables for:
   - Range Maximum Query
   - Range Minimum Query

2. Query:
   max(l,r) and min(l,r)
   in O(1).

3. Use a Max Heap:
   Store intervals and their value.

4. Always pick the interval with the
   largest value.

5. After choosing an interval:
   shrink its right boundary and
   push the new interval back.

Time Complexity:
Building Sparse Table:
O(n log n)

Each Heap Operation:
O(log n)

Total:
O(n log n + k log n)

Space Complexity:
O(n log n)
*/

class Solution {
public:

    using ll = long long;

    vector<vector<int>> stMax;
    vector<vector<int>> stMin;
    vector<int> lg;

    long long maxTotalValue(
        vector<int>& nums,
        int k) {

        int n = nums.size();

        buildSparse(nums);

        auto value =
            [&](int l, int r) -> long long {

            int len = r - l + 1;

            int p = lg[len];

            int mx =
                max(
                    stMax[p][l],
                    stMax[p][r - (1 << p) + 1]
                );

            int mn =
                min(
                    stMin[p][l],
                    stMin[p][r - (1 << p) + 1]
                );

            return 1LL * mx - mn;
        };

        struct Node {

            long long val;
            int l;
            int r;

            bool operator<(const Node& other) const {

                return val < other.val;
            }
        };

        priority_queue<Node> pq;

        for(int l = 0; l < n; l++) {

            pq.push({
                value(l, n - 1),
                l,
                n - 1
            });
        }

        long long ans = 0;

        while(k--) {

            auto cur = pq.top();
            pq.pop();

            ans += cur.val;

            if(cur.r > cur.l) {

                int nr = cur.r - 1;

                pq.push({
                    value(cur.l, nr),
                    cur.l,
                    nr
                });
            }
        }

        return ans;
    }

private:

    void buildSparse(
        vector<int>& nums) {

        int n = nums.size();

        lg.assign(n + 1, 0);

        for(int i = 2; i <= n; i++) {

            lg[i] =
                lg[i / 2] + 1;
        }

        int K = lg[n] + 1;

        stMax.assign(
            K,
            vector<int>(n)
        );

        stMin.assign(
            K,
            vector<int>(n)
        );

        for(int i = 0; i < n; i++) {

            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for(int j = 1; j < K; j++) {

            for(int i = 0;
                i + (1 << j) <= n;
                i++) {

                stMax[j][i] =
                    max(
                        stMax[j - 1][i],
                        stMax[j - 1]
                             [i + (1 << (j - 1))]
                    );

                stMin[j][i] =
                    min(
                        stMin[j - 1][i],
                        stMin[j - 1]
                             [i + (1 << (j - 1))]
                    );
            }
        }
    }
};
