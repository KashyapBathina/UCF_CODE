
#include <bits/stdc++.h>

using namespace std;

int main() {
   int n, m;
   cin >> n >> m;
   
   // 2D cumulative sum array
   vector<vector<int>> s(n+1, vector<int>(m+1));

   int ans = 0;

   // Read in the grid
   for (int i = 0; i < n; i++) {
      // Read the row
      string line;
      cin >> line;

      // Fill the cumulative sum array
      for (int j = 0; j < m; j++) {
         s[i+1][j+1] = line[j]-'0' + s[i][j+1] + s[i+1][j] - s[i][j];
      
         // Look for an answer ending at this location
         for (int ii = 0; ii <= i; ii++) {
            for (int jj = 0; jj <= j;jj++) {
               int amt = (i+1-ii)*(j+1-jj);
               if (s[i+1][j+1] - s[ii][j+1] - s[i+1][jj] + s[ii][jj] == amt) ans = max(ans, amt);
            }
         }
      }
   }

   // Print the best area found
   cout << ans << endl;

   return 0;
}
