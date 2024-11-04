// Rabin Karp
/*
Some Big Prime Numbers:
37'139'213
const ll MOD1 = 131'807'699; -> Big Prime Number for hash 1
const ll MOD1 = 127'065'427; -> Big Prime Number for hash 2
const ll base = 127;         -> Random number larger than the Alphabet
*/
const ll base = 997;
const ll mod[] ={1000000007, 1000000009};
const int MXSZ = 1e6+2;
ll pot[2][MXSZ];
// Lembrar de chamar BUILDPOTS!!!!!
// getkey eh INCLUSIVO
void buildPots(){
  pot[0][0] = 1;
  pot[1][0] = 1;
  for(int j = 0; j < 2; j++)
    for(int i = 1; i < MXSZ; i++)
      pot[j][i] = (pot[j][i-1]*base) % mod[j];
}
class RabinKarp{
public:
  string s;
  int sz;
  vector<ll> h[2];
  RabinKarp(){}
  RabinKarp(const string& str): s(str){
    sz = str.size();
    h[0].resize(sz+1);
    h[1].resize(sz+1);
    h[0][0] = s[0], h[1][0] = s[0]; 
    for(int j = 0; j < 2; j++)
      for(int i = 1; i < sz; i++)
        h[j][i] = ((h[j][i-1]*base)+s[i])%mod[j];
  }
  ll getKey(int l, int r){
    ll x = h[0][r], y = h[1][r];
    if(l > 0){
      x = (((x - pot[0][r-l+1]*h[0][l-1])%mod[0] + mod[0])%mod[0]);
      y = (((y - pot[1][r-l+1]*h[1][l-1])%mod[1] + mod[1])%mod[1]);
    } 
    return (x<<32LL)|y;
  }
};
// hash de buildpots pra baixo: 97523f3c3aa5a2f0ae00021355eb26036f231e731b032edfdb6bd96153886ca7