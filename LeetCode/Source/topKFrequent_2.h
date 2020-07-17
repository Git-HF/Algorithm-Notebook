class Solution {
public:
    int partition(vector<pair<int,int>> &a,int l, int r){
        swap(a[l],a[l+rand()%(r-l+1)]); //随机化
        int j=l,pivot=a[l].second;
        for(int i=l+1;i<=r;i++)
            if(a[i].second>pivot)     //大的放前，小的放后
                swap(a[i],a[++j]);
        swap(a[l],a[j]);
        return j;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ma;
        vector<int> res;
        for(int i:nums)
            ma[i]++;
        vector<pair<int,int>> ve(ma.begin(),ma.end());
        int left=0,right=ve.size()-1;
        int m=k-1;
        while(left<=right){
            int index=partition(ve,left,right);
            if(index==m)    
                break;
            else if(index<m)
                left=index+1;
            else if(index>m)
                right=index-1;
        }
        for(int i=0;i<k;i++)
            res.push_back(ve[i].first);
        return res;
    }
};