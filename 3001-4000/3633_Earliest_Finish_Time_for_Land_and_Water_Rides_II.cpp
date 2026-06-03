/*
Problem Number: 3633
Problem Name: Earliest Finish Time for Land and Water Rides

LeetCode Link:
https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides/

Difficulty: Medium

Topics:
Array, Binary Search, Sorting, Prefix Minimums

Approach:
Instead of checking every pair of rides O(n × m),
sort rides by start time and preprocess:

1. Prefix minimum duration
   - For rides already available when the first ride finishes.

2. Suffix minimum (start time + duration)
   - For rides that have not started yet.

For each finish time of the first ride:
- Find the last ride already open using Binary Search.
- Compute the minimum finish time among:
    • already open rides
    • future rides

Take the minimum answer over:
- Land → Water
- Water → Land

Time Complexity:
O((n + m) log(n + m))

Space Complexity:
O(n + m)
*/

class Solution {
public:

    long long earliestFinishTime(
        vector<int>& landStartTime,
        vector<int>& landDuration,
        vector<int>& waterStartTime,
        vector<int>& waterDuration) {

        auto buildAndQuery =
            [&](const vector<int>& start,
                const vector<int>& dur,
                const vector<long long>& queries) -> long long {

            int n = start.size();

            vector<pair<int, int>> rides(n);

            for(int i = 0; i < n; i++) {
                rides[i] = {start[i], dur[i]};
            }

            sort(rides.begin(), rides.end());

            vector<int> starts(n);

            vector<long long> prefMinDur(n);

            vector<long long> suffMinOpenPlusDur(n);

            // Build prefix minimum duration
            for(int i = 0; i < n; i++) {

                starts[i] = rides[i].first;

                if(i == 0) {
                    prefMinDur[i] = rides[i].second;
                }

                else {
                    prefMinDur[i] =
                        min(prefMinDur[i - 1],
                            (long long)rides[i].second);
                }
            }

            // Build suffix minimum (start + duration)
            for(int i = n - 1; i >= 0; i--) {

                long long value =
                    (long long)rides[i].first +
                    rides[i].second;

                if(i == n - 1) {
                    suffMinOpenPlusDur[i] = value;
                }

                else {
                    suffMinOpenPlusDur[i] =
                        min(suffMinOpenPlusDur[i + 1],
                            value);
                }
            }

            long long best = LLONG_MAX;

            for(long long finishTime : queries) {

                int idx =
                    upper_bound(
                        starts.begin(),
                        starts.end(),
                        finishTime)
                    - starts.begin();

                long long current = LLONG_MAX;

                // Already available rides
                if(idx > 0) {

                    current =
                        min(current,
                            finishTime +
                            prefMinDur[idx - 1]);
                }

                // Future rides
                if(idx < n) {

                    current =
                        min(current,
                            suffMinOpenPlusDur[idx]);
                }

                best = min(best, current);
            }

            return best;
        };

        int n = landStartTime.size();
        int m = waterStartTime.size();

        // Land → Water
        vector<long long> landFinish(n);

        for(int i = 0; i < n; i++) {

            landFinish[i] =
                (long long)landStartTime[i] +
                landDuration[i];
        }

        long long ans1 =
            buildAndQuery(
                waterStartTime,
                waterDuration,
                landFinish);

        // Water → Land
        vector<long long> waterFinish(m);

        for(int j = 0; j < m; j++) {

            waterFinish[j] =
                (long long)waterStartTime[j] +
                waterDuration[j];
        }

        long long ans2 =
            buildAndQuery(
                landStartTime,
                landDuration,
                waterFinish);

        return min(ans1, ans2);
    }
};
