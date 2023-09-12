https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
-------------------------------
class DSU {
private: 
    vector<int> parent, size;
    set<int> s;
public:
    DSU(int n){
        for(int i = 0 ; i < n ; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

public:
    int findPar(int node){
        if(parent[node] == node) return node;

        return parent[node] = findPar(parent[node]);
    }

public:
    void join(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return ;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return;
    }
public:
    int num(){
        for(int x: parent) s.insert(findPar(x)); 
        for(int x: parent)cout<<x<<" ";
        return s.size();
    }
};



class Solution {
public:
    map<int,int>r,c;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int idx = 0;
        DSU dsu(n); 
        for(auto x: stones){
                // cout<<idx<<" ";
                if(r.find(x[0]) != r.end())
                dsu.join(idx,r[x[0]]);
                else r[x[0]] = idx;
                if(c.find(x[1]) != c.end())
                dsu.join(idx,c[x[1]]);
                else c[x[1]] = idx;
            
            
            idx++;
        }        
        int num = dsu.num();
        return n - num;
        
    }
};


----------------------------------------------------------------------------------
  https://leetcode.com/problems/number-of-provinces/description/
----------------------------------------------------------------------------------

class Solution {
public:
    int n ; 
    vector<int> parent, size;
    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    void join(int u, int v){
        int p = find(u), q = find(v);
        if(p < q){
            parent[p] = q;
            // size[q] += size[p];
        }
        else{
            swap(p,q);
            parent[p] = q;
            // size[q] += size[p];
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        parent = vector<int>(n);
        size = vector<int>(n,1);
        for(int i = 0 ; i < n ; i++) parent[i] = i;
        // intialized
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j]){
                    join(i,j);
                }
            }
        }
        
        // joining end
        set<int> s;
        for(int x = 0 ; x < n ; x++) s.insert(find(x));
        return s.size();
        // mera ans
        
    }
};


  
