/*
    how to use :
    init the Matrix with const int
    when defining the matrix with vector of vector use double brackets .
    usage : 
    const int N = 2 ;
    Matrix<int,2> A ;
    A.d = {{ {{0,1}} , {{1,1}} }} ;

*/

#define rep(i, a, b) for(int i = a; i < (b); ++i) 

template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i, 0, N)   rep(k, 0, N) if (d[i][k]) rep(j, 0, N) {
            a.d[i][j] = (a.d[i][j] + d[i][k] * m.d[k][j])%MOD ;
        }
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        rep(i, 0, N) rep(j, 0, N) {
            ret[i] = (ret[i] + d[i][j] * vec[j])%MOD ;
        }
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i, 0, N) a.d[i][i] = 1;
        while (p) {
            if (p & 1) a = a * b;
            b = b * b;
            p >>= 1;
        }
        return a;
    }
};