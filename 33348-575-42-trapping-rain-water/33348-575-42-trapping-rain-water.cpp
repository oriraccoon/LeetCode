#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int answer = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();

                if (stk.empty()) {
                    break;
                }

                int distance = i - stk.top() - 1;
                int boundedHeight = min(height[i], height[stk.top()]) - height[top];
                answer += distance * boundedHeight;
            }

            stk.push(i);
        }

        return answer;
    }
};