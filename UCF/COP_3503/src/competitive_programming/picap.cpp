
#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int canDo(ll len, vector<int> & arr, int lines) {
   ll cur = len + 1;
   for (auto x : arr) {
      if (cur < x + 1) {
         lines--;
         cur = len + 1;
         if (cur < x + 1) return 0;
      }
      cur -= x + 1;
      if (!lines) return 0;
   }
   return 1;
}

int main() {
   int n, k;
   cin >> n >> k;
   vector<int> arr(n);
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   ll lo = 0;
   ll hi = 987654321;
   hi *= 2;
   ll ans = hi;
   while (lo <= hi) {
      ll mid = (lo + hi) / 2;
      if (canDo(mid, arr, k)) {
         ans = mid;
         hi = mid - 1;
      } else lo = mid + 1;
   }
   cout << ans << endl;
   return 0;
}
