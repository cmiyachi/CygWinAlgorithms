#include <bits/stdc++.h>
	
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
		// Check for the base case. If there are no intervals, return 0
		if (intervals.size() == 0) {
		  return 0;
		}

    vector<int> start(intervals.size()), end(intervals.size()); 
	
    for (int i = 0; i < intervals.size(); i++) {
      start[i] = intervals[i][0];
      end[i] = intervals[i][1];
    }

    // Sort the intervals by end time
	sort(start.begin(), start.end());
	sort(end.begin(), end.end()); 

    // The two pointers in the algorithm: e_ptr and s_ptr.
    int startPointer = 0, endPointer = 0;

    // Variables to keep track of maximum number of rooms used.
    int usedRooms = 0;

    // Iterate over intervals.
    while (startPointer < intervals.size()) {

      // If there is a meeting that has ended by the time the meeting at `start_pointer` starts
      if (start[startPointer] >= end[endPointer]) {
        usedRooms -= 1;
        endPointer += 1;
      }

      // We do this irrespective of whether a room frees up or not.
      // If a room got free, then this used_rooms += 1 wouldn't have any effect. used_rooms would
      // remain the same in that case. If no room was free, then this would increase used_rooms
      usedRooms += 1;
      startPointer += 1;

    }

    return usedRooms;
    }
};

int main(void)
{
	vector<vector<int>> intervals{{0, 30},{5, 10},{15, 20}};
	Solution sol;
	cout << sol.minMeetingRooms(intervals); 
	
	return 0; 
	
}

/**First collect the changes: at what times the number of meetings goes up or down and by how much. Then go through those changes in ascending order and keep track of the current and maximum number of rooms needed.

Solution 1: Using map ... 600 ms **/

int minMeetingRooms4(vector<Interval>& intervals) {
    map<int, int> changes;
    for (auto i : intervals) {
        changes[i.start] += 1;
        changes[i.end] -= 1;
    }
    int rooms = 0, maxrooms = 0;
    for (auto change : changes)
        maxrooms = max(maxrooms, rooms += change.second);
    return maxrooms;
}
// Solution 2: Using vector ... 588 ms

int minMeetingRooms3(vector<Interval>& intervals) {
    vector<pair<int, int>> changes;
    for (auto i : intervals) {
        changes.push_back({i.start, 1});
        changes.push_back({i.end, -1});
    };
    sort(begin(changes), end(changes));
    int rooms = 0, maxrooms = 0;
    for (auto change : changes)
        maxrooms = max(maxrooms, rooms += change.second);
    return maxrooms;
}
/* Solution 3: Using two vectors ... 584 ms

Based on yinfeng.zhang.9's Python solution. Uses separate vectors for start and end times, which ends up consistently being fastest. I'm guessing it's mostly because working with ints is simpler than working with pairs of ints. The initial sorting also needs fewer steps, 2(nlogn) instead of (2n)log(2n), but I think the added merging in the later loop cancels that advantage out.*/

int minMeetingRooms2(vector<Interval>& intervals) {
    vector<int> starts, ends;
    for (auto i : intervals) {
        starts.push_back(i.start);
        ends.push_back(i.end);
    }
    sort(begin(starts), end(starts));
    sort(begin(ends), end(ends));
    int e = 0, rooms = 0, available = 0;
    for (int start : starts) {
        while (ends[e] <= start) {
            ++e;
            ++available;
        }
        available ? --available : ++rooms;
    }
    return rooms;
}