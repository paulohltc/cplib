struct Line{
    ll a, b;
    double x_inter;
    Line(ll a, ll b, double x_inter = inf) : a(a), b(b), x_inter(x_inter){}
    
    bool operator < (double x){
        return x_inter < x;
    }
    ll eval(ll x){
        return a*x + b;
    }
};
 
double intersect(Line x, Line y){
    assert(x.a != y.a);
    return (1.0d * x.b - y.b) / (1.0d * y.a - x.a);
}
 
 
struct CHT{
    deque<Line> lines;
    void insert_right(ll a, ll b){
        while(lines.size() >= 2){
            Line x = lines[lines.size() - 2], y = lines[lines.size() - 1];
            if(intersect(y, {a,b,0}) > intersect(x,y)) break;
            lines.pop_back();
        }
        if(!lines.empty()) lines[lines.size() - 1].x_inter = intersect(lines.back(), {a,b,0});
        lines.push_back(Line(a, b));
    }
    void insert_left(ll a, ll b){
        while(lines.size() >= 2){
            Line x = lines[1], y = lines[0];
            if(intersect(y, {a,b,0}) < intersect(x,y)) break;
            lines.pop_front();
        }
        lines.push_front(Line(a, b));
        if(!lines.empty()) lines.back().x_inter = inf;
        if(lines.size() > 1) lines[0].x_inter = intersect(lines[0], lines[1]);        
    }
    ll qry(ll x){ // todo: fazer two pointers pra ficar linear
        auto lb = lower_bound(begin(lines), end(lines), x);
        return (*lb).eval(x);
    }
    void dbg(){
        for(Line l : lines) 
            cout << l.a << "x + " << l.b << " " << l.x_inter << br;
    }
};
 
