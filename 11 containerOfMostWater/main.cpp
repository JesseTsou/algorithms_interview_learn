#include <iostream>
#include <vector>
using namespace std;
/*
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，
 * 使得它们与 x 轴共同构成的容器可以容纳最多的水。
 */
int print(vector<int> vec)
{
    for (int e:vec)
        cout << e << " ";
    cout << endl;
    return 0;
}
class Solution {
public:
    /*
     * 暴力解法：
     * 时间复杂度：O(n^2)
     */
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int ret = 0;
        int h = 0;
        for (int i = 0; i < height.size(); i ++)
        {
            for (int j = i + 1; j <height.size(); j ++ )
            {
                h =(height[i] <= height[j] ? height[i] : height[j]);
                ret = (j - i) * h;
                if (maxA < ret){
                    maxA = ret;
                }
            }
        }
        return maxA;
    }
    /*
     * 左右索引，对撞指针
     * 单次遍历
     * 时间复杂度：O(n)
     * 注意，下标移动的条件是总是取较大的一边
     */
    int maxArea2(vector<int>& height) {
        int maxA = 0;
        int ret = 0;
        int h = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r)
        {
            h =(height[l] <= height[r] ? height[l] : height[r]);
            ret = (r - l) * h;
            if (maxA < ret){
                maxA = ret;
            }
            //如果height[left] < height[right]，那么left右移，找到一个比height[left]大的值。
            // 反之，则right左移。同时需要保持跟踪最大
            height[l] < height[r] ? l ++: r --;

        }
        return maxA;
    }
};

int main() {
    int a[] = {1,8,6,2,5,4,8,3,7};
    vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
    print(vec);
    Solution s;
    int max = s.maxArea2(vec);
    cout << max << endl;
    return 0;
}