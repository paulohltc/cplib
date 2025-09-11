template <class InfoType = int32_t, class RangeType = int32_t>
struct ColorUpdate {
public:
    struct Range {
        Range(RangeType _l = 0) : l(_l) {}
        Range(RangeType _l, RangeType _r, InfoType _v) : l(_l), r(_r), v(_v) { }
        RangeType l, r;
        InfoType v;

        bool operator < (const Range &b) const { return l < b.l; }
    };

    vector<Range> erase(RangeType l, RangeType r) {
        vector<Range> ans;
        if(l >= r) return ans;
        auto it = ranges.lower_bound(l);
        if(it != ranges.begin()) {
            it--;
            if(it->r > l) {
                auto cur = *it;
                ranges.erase(it);
                ranges.insert(Range(cur.l, l, cur.v));
                ranges.insert(Range(l, cur.r, cur.v));
            }
        }
        it = ranges.lower_bound(r);
        if(it != ranges.begin()) {
            it--;
            if(it->r > r) {
                auto cur = *it;
                ranges.erase(it);
                ranges.insert(Range(cur.l, r, cur.v));
                ranges.insert(Range(r, cur.r, cur.v));
            }
        }
        for(it = ranges.lower_bound(l); it != ranges.end() && it->l < r; it++) {
            ans.push_back(*it);
        }
        ranges.erase(ranges.lower_bound(l), ranges.lower_bound(r));
        return ans;
    }

    vector<Range> upd(RangeType l, RangeType r, InfoType v) {
        auto ans = erase(l, r);
        ranges.insert(Range(l, r, v));
        return ans;
    }

    bool exists(RangeType x) {
        auto it = ranges.upper_bound(x);
        if(it == ranges.begin()) return false;
        it--;
        return it->l <= x && x < it->r;
    }
private:
    set<Range> ranges;
};
