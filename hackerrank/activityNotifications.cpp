#include <iostream>
#include <vector>	
#include <string>
#include <array>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

int get_m2(vector<int> & freq, int d); 

// Complete the activityNotifications function below.
int activityNotifications(vector<int> arr, int d) {    
    vector<int> freq(201, 0);
    int num_notification = 0;

    for (int i = 0; i < d; ++i) ++freq[arr[i]];
    for (int i = d; i < arr.size(); ++i) {
        int m2 = get_m2(freq, d);
        if (arr[i] >= m2) num_notification++;
        --freq[arr[i-d]];
        ++freq[arr[i]];
    }
    return num_notification;
}

int get_m2(vector<int> & freq, int d) {
    int m1 = (d + 1) / 2;
    int m2 = m1 + 1;
    int i;

    for (i = 0; i < freq.size(); ++i) {
        if (m1 <= freq[i]) {
            break;
        } else {
            m1 -= freq[i];
            m2 -= freq[i];
        }
    }
    if (d % 2 == 1) return i * 2;        

    int last_i = i;
    for (; i < freq.size(); ++i) {
        if (m2 <= freq[i]) break;
        else m2 -= freq[i]; 
    }
    return last_i + i;
}

int main()
{
	int n, d;
	cin >> n >> d;
	vector<int> expenditure(n);

	for (int i = 0; i < n; i++)
	{
		cin >> expenditure[i];
	}

	int result = activityNotifications(expenditure, d);

	cout << result << "\n";

	return 0;
}