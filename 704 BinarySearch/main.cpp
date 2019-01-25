#include <iostream>
#include <vector>
using namespace std;
/*
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */
int print(vector<int >vec)
{
    for(int e:vec)
        cout << e << " ";
    cout << endl;
    return 0;
}
class Solution {
public:
    /*
     * 时间复杂度：O(logn)
     * 空间复杂度：O(1)
     * 思路：二分查找法，在有序数组中，将整个数组的中间位置与目标值作比较，若大于目标值，则中间往前部分子表继续与目标值作比较；
     * 若小于目标值，则中间往后部分子表继续与目标值作比较；
     * 若等于目标值，则该位置即所要查找的位置。重复以上过程，直到找到目标值位置，或者数组查找完也没有找到目标位置。c
     */
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid;
        int ret = -1;
        while(low <= high)
        {
            mid = (high + low)/2;
            if (target > nums[mid])
                low = mid + 1;
            else if (target < nums[mid])
                high = mid - 1;
            else
            {
                ret = mid;
                break;
            }
        }
        return ret;
    }
};
int main() {
    int a[]= {-1,0,3,5,9,12};
    vector <int> vec (a, a + sizeof(a)/sizeof(a[0]));
    print(vec);
    Solution s;
    cout<< s.search(vec,9) << endl;
    return 0;
}