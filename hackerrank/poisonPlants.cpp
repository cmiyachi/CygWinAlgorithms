#include <bits/stdc++.h>

using namespace std;

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
    int n = p.size();
    vector<int> killer(n,0); // which killed i;
    vector<int> daycount(n,0); // how long i can exist
    vector<int> killcount(n,0); // how many i killed
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && p[st.top()] >= p[i]) {
            st.pop();
        }

        if (st.empty()) {
            killer[i] = -1;
            daycount[i] = -1;
        } else {
            killer[i] = st.top();
            killcount[killer[i]]++;
            daycount[i] += killcount[killer[i]];
            daycount[st.top()]--;
            if (killer[st.top()] >= 0 && daycount[st.top()] <= 0)
                st.pop();
        }

        st.push(i);
    }

    int max = -1;
    for (int i = 0; i < n; ++i)
        if (max < killcount[i]) max = killcount[i];

    return max;
}

int poisonousPlants2(vector<int> p)
{
	deque<int> alive(p.begin(), p.end());
	int days = 0;
	int dead; 
	
	do {
		dead = 0;
		int current = alive[0];
		for (int i = 0; i < alive.size(); i++)
		{
			int this_p = alive[i];
			if  (alive[i] > current) // it's dead
			{
				dead++;
				alive.erase(alive.begin() + i);
				i--; 
			}
			current = this_p; 
		}
		if (dead != 0) days++;
	} while (dead != 0);
	
	return days;
}
int main(void)
{
	vector<int> p{6, 5, 8, 4, 7, 10, 9};
	
	cout << poisonousPlants(p); 
	return 0;
}
