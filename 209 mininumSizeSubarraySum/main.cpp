#include <iostream>
#include <vector>
using namespace std;
/*
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。
 * 如果不存在符合条件的连续子数组，返回 0。
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
     * 时间复杂度：O(n)
     * 使用滑动窗口，一直遍历到数组末尾
     */
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = -1;//[l,r]滑动窗口
        int sum = 0;
        int count = nums.size() + 1;
        while (l < nums.size()){
            if (r + 1 < nums.size() && sum < s){
                sum += nums[++r];
            } else{
                sum -= nums[l++];
            }

            if (sum >= s){
                count = (count < r - l + 1 ? count : r - l + 1);
            }
        }
        if (count == nums.size() + 1)
            count = 0;
        return count;
    }
    /*
     * 时间复杂度：O(n^2)
     * 两次遍历
     */
    int minSubArrayLen2(int s, vector<int>& nums) {
        int len = nums.size() + 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for (int j = i; j < nums.size(); j ++)
            {
                sum += nums[j];
                if (sum >= s){
                    int tmplen = j - i + 1;
                    len = (len < tmplen?len:tmplen);
                    break;
                }
            }
        }
        if (len == nums.size() + 1)
            len = 0;
        return len;
    }
};

int main() {
    int a[] = {2,3,1,2,4,3};
    vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
    print(vec);
    Solution s;
    int len = s.minSubArrayLen2(7,vec);
    cout << len << endl;
    return 0;
}