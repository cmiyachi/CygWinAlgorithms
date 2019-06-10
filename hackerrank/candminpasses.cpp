#include <bits/stdc++.h>

using namespace std;

// Complete the minimumPasses function below.
long minimumPasses(long m, long w, long p, long n) {
  __int128 candy = 0;
  long passes = LONG_MAX;
  long invest = 0;
  while (candy < n) {
    // number of days of production needed before being able to purchase
    //cout << "p: " << p << " candy: " << candy << " m: " << m << " w: " << w << endl;
    long long prod =
        floor(((long long)p - (long long)candy) / (double)m / (double)w);
    //cout << prod << endl;
    if (prod <= 0) {
      long total_mw = (candy / p) + m + w;
      long half = ceil(total_mw / 2.0);
      if (m > w) {
        m = max(m, half);
        w = total_mw - m;
      } else {
        w = max(w, half);
        m = total_mw - w;
      }
      candy %= p; // when there is money, spend them all
      prod = 1;
    }
    candy += (__int128)prod * (__int128)m * (__int128)w;
    //cout << "candy: " << candy << endl;
    invest += prod;
    passes = min(passes, invest + (long)ceil((n - candy) / (double)(m) / (double)(w)));
    }
    return min(invest, passes);
}

int main(void)
{
		long m = 3, w = 1, p = 2, n = 12;
		cout << minimumPasses(m,w,p, n); 
		
		return 0; 
}
		