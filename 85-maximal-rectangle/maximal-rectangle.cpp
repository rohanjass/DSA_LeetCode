class Solution {
public:
    int calArea(vector<int> arr){
        int maxArea=0;
        stack<int> st;
        int n=arr.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() &&(i==n || arr[i]<arr[st.top()])){
                int h=arr[st.top()];
                st.pop();
                int w=st.empty()? i:i-st.top()-1;
                maxArea=max(maxArea,h*w);
            }
            st.push(i);
        }
    return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> arr(m,0);
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') arr[j]+=1;
                else arr[j]=0;
            }
            int area=calArea(arr);
            maxArea=max(maxArea,area);
        }
    return maxArea;
    }
};