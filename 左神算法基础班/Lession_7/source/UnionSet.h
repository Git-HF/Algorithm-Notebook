struct DSU{
    vector<int> data;

    void makeSet(int n){
        data.resize(n);
        for (int i = 0; i < n; i++) data[i] = i;
    };

    bool unionSet(int i, int j){
        int p1 = parent(i);
        int p2 = parent(j);
        if ( p1 != p2 ){
            data[p1] = p2;
        } 
        return p1 != p2;

    };

    int parent(int i){
        int root = i;
        while ( data[root] != root){
            root = data[root];
        }
        return root;

    };
};
