#include <bits/stdc++.h>
using namespace std;


class MyCalendarTwo 
{
    map<int, int> mp; // key: time; val: +1 if start, -1 if end
public:
    bool book(int start, int end) 
    {
        mp[start]++;
        mp[end]--;
        int booked = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) 
        {
            booked += it->second;
            if (booked == 3) 
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
 /*Approach #1: Brute Force [Accepted]
Intuition

Maintain a list of bookings and a list of double bookings. When booking a new event [start, end), if it conflicts with a double booking, it will have a triple booking and be invalid. Otherwise, parts that overlap the calendar will be a double booking.

Algorithm

Evidently, two events [s1, e1) and [s2, e2) do not conflict if and only if one of them starts after the other one ends: either e1 <= s2 OR e2 <= s1. By De Morgan's laws, this means the events conflict when s1 < e2 AND s2 < e1.

If our event conflicts with a double booking, it's invalid. Otherwise, we add conflicts with the calendar to our double bookings, and add the event to our calendar.

*/

int main(void)
{
	MyCalendarTwo MyCalendar; 
	cout << MyCalendar.book(10, 20) << endl; // returns true
	cout << MyCalendar.book(50, 60)<< endl; // returns true
	cout << MyCalendar.book(10, 40)<< endl; // returns true
	cout << MyCalendar.book(5, 15)<< endl; // returns false
	cout << MyCalendar.book(5, 10)<< endl; // returns true
	cout << MyCalendar.book(25, 55)<< endl; // returns true
	return 0;
}