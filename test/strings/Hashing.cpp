#include "../utils/template.h"
#include "../../code/strings/Hashing.h"

void test(const string& s) {
   auto h = Hashing(s);
   for (int len = 1; len <= sz(s); len++) {
      for (int i = len; i + len < sz(s); i++) {
         auto same = s.substr(0, len) == s.substr(i, len);
         assert(same == h.compare({0, len - 1}, {i, i + len - 1}));
      }
   }
}

void gen(string& s, int idx, int alpha) {
   if (idx == sz(s))
      test(s);
   else {
      for (int i = 0; i < alpha; i++) {
         s[idx] = ('a' + i);
         gen(s, idx + 1, alpha);
      }
   }
}

int main() {
   // test ~3^12 strings
   for (int n = 0; n < 13; n++) {
      string s(n, 'a');
      gen(s, 0, 3);
   }
   // then ~4^10 strings
   for (int n = 0; n < 11; n++) {
      string s(n, 'a');
      gen(s, 0, 4);
   }
   cout << "Tests passed!" << endl;
}