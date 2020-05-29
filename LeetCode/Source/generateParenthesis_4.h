class Solution {
public:
    //可以认为 Data 就是递归版本的栈帧，str，lc，rc就是参数。
    //Data::status 就是递归调用返回后，继续执行的指令地址。
    struct Data {
        string str;
        int lc;
        int rc;
        int status; 
    };
    stack<Data> st;
    vector<string> generateParenthesis(int n) {
        n *= 2;
        vector<string> res;
        st.push(Data{"", 0, 0, 0});
        while(st.empty() == false) {
            Data &t = st.top();
            if(t.str.size() == n) {
                res.push_back(t.str);
                st.pop();
                continue;
            }
            if(t.status == 2) {
                st.pop();
                continue;
            }
            if(t.status == 0) {
                if(t.rc + 1 <= t.lc) {
                    st.push(Data{t.str + ")", t.lc, t.rc+1, 0});
                }
                t.status = 1;
                continue;
            }
            if(t.status == 1) {
                if(t.lc+1-t.rc <= n - t.str.size()-1) {
                    st.push(Data{t.str+"(", t.lc+1, t.rc, 0});
                }
                t.status = 2;
                continue;
            }
        }
        return res;
    }
};