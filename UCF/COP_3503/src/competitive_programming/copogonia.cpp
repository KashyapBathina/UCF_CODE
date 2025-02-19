
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using ld = long double;
using vd = vector<ld>;
using vvd = vector<vd>;
using vi = vector<int>;
using vvi = vector<vi>;

pll getDelta(vpll & arr, int index) {
   pll res;
   res.first = arr[index + 1].first - arr[index].first;
   res.second = arr[index + 1].second - arr[index].second;
   return res;
}

int go(vvd & g, vvi & ex, ld m) {
   int ans =  1000000001;
   int n = g.size();
   int k = ex.size();
   
   // Try all combinations of edges to use
   for (int mask = 1; mask < (1<<k); mask++) {
      // Store the distances without shortcuts
      vvd dist1(n, vd(n, m + 1));
      for (int i = 0; i < n; i++) {
         for (int j = -1; j <= 1; j++) {
            int ii = (j+i+n)%n;
            dist1[i][ii] = g[i][ii];
         }
      }

      // The the answer for this mask also add the extra edges
      int tans = 0;
      for (int i = 0; i < k; i++) {
         if ((mask>>i)&1) {
            int a = ex[i][0]-1;
            int b = ex[i][1]-1;
            tans += ex[i][2];
            dist1[a][b] = g[a][b];
            dist1[b][a] = g[b][a];
         }
      }

      // Floyds
      for (int i = 0; i < n; i++) {
         for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
               dist1[ii][jj] = min(dist1[ii][jj], dist1[ii][i] + dist1[i][jj]);
            }
         }
      }

      // Check if the dists are not good
      int good = 1;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (dist1[i][j] > m) good = 0;
         }
      }
      if (good) ans = min(ans, tans);
   }
   
   return ans;
}


int main() {
   int n, k, m;
   cin >> n >> k >> m;

   // Make the pairs of distances
   vvd dists_pair(n, vd(n));

   // Read in all the points
   vpll pts(n);
   for (int i = 0; i < n; i++) {
      cin >> pts[i].first >> pts[i].second;
   }
   pts.push_back(pts[0]);
   pts.push_back(pts[1]);
   pts.push_back(pts[2]);
   
   // Store all the distance pairs for use later
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         ll dx = pts[i].first - pts[j].first;
         ll dy = pts[i].second - pts[j].second;
         dists_pair[i][j] = sqrt(dx * dx + dy * dy);
      }
   }

   // Store the extra edges
   vvi extra(k, vi(3));
   for (int i = 0; i < k; i++)
      for (int j = 0; j < 3; j++)
          cin >> extra[i][j]; 

   // Find answer
   cout << go(dists_pair, extra, m) << endl;

   return 0;
}

