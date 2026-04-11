/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;

        for(auto& meeting:intervals) {
            starts.push_back(meeting.start);
            ends.push_back(meeting.end);
        }

        int n = starts.size();
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int s = 0, e = 0;
        int count = 0, ans = 0;
        while(s < n && e < n) {
            if(starts[s] < ends[e]) {
                // an overlapping meeting starts: need a day
                count++;
                s++;
                ans = max(ans, count);
                continue;
            }

            // a meeting should end before starting another meeting:
            // need to decrement the days
            count--;
            e++;
        }

        return ans;
    }
};
