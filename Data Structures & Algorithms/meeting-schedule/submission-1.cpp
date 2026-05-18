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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.end <= b.end;
        });
        
        int end_time = -1;

        for(auto &item:intervals){
            if(end_time == -1){
                end_time = item.end;
            } else{
                int curr_start_time = item.start;
                int curr_end_time = item.end;

                if(curr_start_time < end_time){
                    return false;
                } else{
                    end_time = curr_end_time;
                }
            }
        }
        
        return true;
    }
};
