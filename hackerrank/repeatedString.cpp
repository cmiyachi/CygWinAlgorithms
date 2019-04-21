#include <bits/stdc++.h>

using namespace std;



// Complete the repeatedString function below.
 long repeatedString(string s,  long n) {
    long count = 0;
	for (auto ch: s) {
		if (ch == 'a') {
			count++;
		}
	}
	count *= n / s.size();
	int k = n % s.size();
	if (k != 0) {
		for (int i = 0; i < k; ++i) {
			if (s[i] == 'a') {
				count++;
			}
		}
	}

	return count;
}

int main()
{
   // ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long long result = repeatedString(s, n);

    cout << result << "\n";

   // fout.close();

    return 0;
}
