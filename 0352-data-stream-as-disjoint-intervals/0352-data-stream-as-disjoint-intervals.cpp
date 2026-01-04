// LeetCode 352 - Data Stream as Disjoint Intervals
// https://leetcode.com/problems/data-stream-as-disjoint-intervals/
// Author: muteeba4266

#include <vector>
#include <set>

using namespace std;

class SummaryRanges {
private:
    struct Interval {
        int start, end;
        bool operator<(const Interval& other) const {
            return start < other.start;
        }
    };
    set<Interval> intervals;

public:

    void addNum(int value) {
        auto it = intervals.lower_bound({value, value});
        int start = value, end = value;

        if (it != intervals.begin()) {
            auto prev = std::prev(it);
            if (prev->end >= value) return;
            if (prev->end + 1 == value) {
                start = prev->start;
                intervals.erase(prev);
            }
        }

        if (it != intervals.end()) {
            if (it->start == value + 1) {
                end = it->end;
                intervals.erase(it);
            }
        }

        intervals.insert({start, end});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (const auto& interval : intervals) {
            result.push_back({interval.start, interval.end});
        }
        return result;
    }
};

