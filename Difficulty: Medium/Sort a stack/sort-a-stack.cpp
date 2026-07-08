class Solution {
public:
    void insert(stack<int>& st, int ele) {

        if (st.empty() || st.top() <= ele) {
            st.push(ele);
            return;
        }

        int temp = st.top();
        st.pop();

        insert(st, ele);

        st.push(temp);
    }

    void sortStack(stack<int>& st) {

        if (st.empty())
            return;

        int ele = st.top();
        st.pop();

        sortStack(st);

        insert(st, ele);
    }
};