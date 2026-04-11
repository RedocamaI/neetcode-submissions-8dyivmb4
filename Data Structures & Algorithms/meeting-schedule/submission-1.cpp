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
    static bool comp(Interval& a, Interval& b) {
        if(a.start < b.start)
            return true;
        
        return a.end < b.end;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int n = intervals.size();
        for(int i=1;i<n;i++) {
            if(intervals[i-1].end > intervals[i].start)
                return false;
        }

        return true;
    }
};
