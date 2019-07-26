using namespace std;
#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //heights.push_back(0);
        stack<int> pos;
        int t, maxV = 0, i = 0;
        int n = heights.size();
        pos.push(-1);
        while(i < heights.size()){
            // 若遞減
            while (pos.top()!= -1 && heights[i] <= heights[pos.top()] ){
                t = pos.top();
                pos.pop();
                maxV = max(maxV, heights[t]*( i-pos.top()-1 ));
                //pos.pop();
            }
            pos.push(i++);
        }
            
            // 若遞增,表示裡面的值一定是單調遞增且通過所有的長度
            while (pos.top()!= -1){
                t = pos.top();
                pos.pop();
                //int tmp = heights[t]*(n-pos.top()-1);
                maxV = max(maxV, heights[t]*(n-pos.top()-1));
                
            }
                
        
        return maxV;
    }
};

int main(){
    Solution s;
    int a[6] = {2,1,5,6,2,3};
    vector <int> input(a, a+6);
    stack<int> op;
    cout << input[op.top()] << endl;
    //s.largestRectangleArea(input);
    //cout << s.largestRectangleArea(input) << endl;
}