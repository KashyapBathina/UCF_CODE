
#include <bits/stdc++.h>

using namespace std;

int main() {

   // Read in the number of dictionary words
   int n;
   cin >> n;
   vector<string> words(n);

   // Read in the dictionary
   for (int i = 0; i < n; i++) {
      cin >> words[i];
   }

   // Read in the number of query words
   int q;
   cin >> q;

   // Read in the queries
   while (q--) {
      string s;
      cin >> s;
      int ans = 0;

      // Check if the word is in the dictionary
      for (int i = 0; i < n && !ans; i++) {
         if (s == words[i]) {
            ans = 1;
         }             
      }

      // Check if the word is a combination of 2 words
      for (int i = 0; i < n && !ans; i++) {
         for (int j = 0; j < n && !ans; j++) {
            if (s == words[i] + words[j]) {
               ans = 2;
            }
         }
      }

      // Print the answer
      cout << ans << "\n";
   }

   // Exit
   return 0;
}
