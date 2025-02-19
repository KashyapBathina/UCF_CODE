#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
   int n;
   cin >> n;
   vector<ll> vs(n);
   __int128 total = 0;
   for (int i = 0; i < n; i++) {
      cin >> vs[i];
      total += vs[i];
   }

   sort(vs.begin(), vs.end());
   
   __int128 ans = 0;
   __int128 sum = 0;
   for (int i = 0; i < n;) {
      sum += vs[i];
      i++;
      __int128 tans = (i*total) - (sum*n);
      ans = max(ans,tans); 
   }

   ld fans = ans;
   fans /= (n*total);

   cout << setprecision(12) << fixed << fans * 100 << endl;

   return 0;
}
