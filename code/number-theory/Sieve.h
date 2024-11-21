const int N = 1e6;
int lpd[N];
vector<int> primes ; 
vector<int> factorize(int n) {
   vector<int> ans;
   while (n != 1) {
      ans.push_back(lpd[n]);
      n/= lpd[n];
   }
   return ans;
}

void sieve(){
   for (int i = 2; i < N; i++) {
      if (lpd[i] == 0) {
        primes.push_back(i) ;
         for (int j = i; j < N; j+= i)
            if (lpd[j] == 0)
               lpd[j] = i;
      }
   }
}

