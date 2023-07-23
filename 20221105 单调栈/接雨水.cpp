#include <bits/stdc++.h>

using namespace std;

// LeetCode
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        vector<int> left_max(n);
        vector<int> right_max(n);

        left_max[0] = height[0];
        for (int i = 1; i < n; ++i)
            left_max[i] = max(left_max[i - 1], height[i]);

        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
            right_max[i] = max(right_max[i + 1], height[i]);

        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += min(left_max[i], right_max[i]) - height[i];
        return ans;
    }
};

int main()
{
    int n;
    vector<int> height;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", &t);
        height.push_back(t);
    }

    printf("%d\n", Solution().trap(height));
    return 0;
}
