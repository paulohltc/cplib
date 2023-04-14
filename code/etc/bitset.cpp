__builtin_popcount(int x);
__builtin_popcountll(ll x);
const int SZ = 1e6;
bitset<SZ> b;
b.reset(); // 00 ... 00
b.set();   // 11 ... 11
b.flip(); 
b._Find_first(); // retorna SZ se nao tiver
b._Find_next(i); 
b.to_ulong();
b.to_string();
b.count();