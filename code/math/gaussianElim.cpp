template<typename T>
struct GaussElim{
    vector<vector<T>> rows;
    vector<int> where;
    vector<bool> hasRow;
    int m, n;
    GaussElim(int vars) : m(vars){
        where.assign(m,-1);
        n = 0;
    }
    void add_eq(vector<T> row){ // colocar o b aqui tb
        rows.push_back(row);
        hasRow.push_back(false);
        n++;
    }
    int status(){
        // 0: no solution, 1: unique, 2: infinite
        for(int i = 0; i < n; i++)
            if(!hasRow[i] && rows[i].back() != T(0)) 
                return 0;
        for(int j = 0; j < m; j++)
            if(where[j] == -1)
                return 2;
        
        return 1;
    }
    int go(){
        int n = rows.size();
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(rows[i][j] != T(0) && !hasRow[i]){
                    where[j] = i;
                    hasRow[i] = 1;
                    break;
                }
            }
            if(where[j] == -1) continue;
            // fix linha where[j]
            T div = rows[where[j]][j];
            for(int k = 0; k <= m; k++)
                rows[where[j]][k] /= div;
            for(int i = 0; i < n; i++){
                if(i == where[j]) continue;
                T mul = -1*rows[i][j];
                for(int k = 0; k <= m; k++)
                    rows[i][k] += mul*rows[where[j]][k];
            }
        }
        return status();
    }
    vector<T> get(){
        // assert status = 1
        vector<T> ret(m);
        for(int i = 0; i < m; i++)
            ret[i] = rows[where[i]].back();
        return ret;
    }
};
