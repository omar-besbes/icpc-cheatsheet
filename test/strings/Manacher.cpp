#include "../utils/template.h"
#include "../../code/strings/Manacher.h"

void test(const string& s) {
   auto p = Manacher(s).p;
   string t = "$" + s + "^";
   for (int z = 0; z < 2; z++)
      for (int i = 1; i <= sz(s); i++) {
         int maxlen = z;
         while (t[i - maxlen - !z] == t[i + maxlen]) maxlen++;
         assert(maxlen == p[z][i - 1]);
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