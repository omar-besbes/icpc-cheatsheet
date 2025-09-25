#include "../utils/template.h"
#include "../../code/strings/KMP.h"

void test(const string& s) {
   auto p = pi(s);
   for (int i = 0; i < sz(s); i++) {
      int maxlen = -1;
      for (int len = 0; len < i + 1; len++) {
         if (s.substr(0, len) == s.substr(i - len + 1, len)) maxlen = len;
      }
      assert(maxlen == p[i]);
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