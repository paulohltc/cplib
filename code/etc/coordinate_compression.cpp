template<typename T> // vlw g
struct CoordinateCompression {
  vector<T> v;
  void push(const T& a) { v.push_back(a); }
  int build() {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    return (int)v.size();
  }
  int operator[](const T& a) const {
    auto it = lower_bound(begin(v), end(v), a);
    return int(it - begin(v));
  }
};