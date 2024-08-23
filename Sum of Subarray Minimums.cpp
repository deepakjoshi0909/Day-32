#include <vector>
#include <stack>

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> left(n), right(n);
        std::stack<int> s;
        const int MOD = 1e9 + 7;

        // Calculate left array
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        // Clear the stack to reuse it for right array
        while (!s.empty()) s.pop();

        // Calculate right array
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        // Calculate the sum of minimums
        int result = 0;
        for (int i = 0; i < n; ++i) {
            long long contribution = (long long)arr[i] * left[i] * right[i];
            result = (result + contribution % MOD) % MOD;
        }

        return result;
    }
};
