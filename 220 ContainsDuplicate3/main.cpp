#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
 * 给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，
 * 使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。
 */
class Solution {
public:
    /*
     * 时间复杂度：O(nlogn)
     * 使用multiset来保存值，用其当作滑动的窗口，若set长度大于k，则移除前面的数据，始终保持k的大小
     */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0 )
            return false;
        multiset<long long> set1;
        for (int i = 0; i < nums.size(); i ++){
            if (i > k)
                set1.erase(set1.find(nums[i - k - 1]));
            //|num[i] - num[j]| <= t即 num[i] - t <= num[j] <= t + nums[i]
            //lower_bound表示找到set1中第一个不小于参数中值的位置
            //注意:使用long long 64位整型，因为使用int有可能溢出
            auto iter = set1.lower_bound((long long)nums[i] - (long long)t);
            if (iter != set1.end() && *iter - (long long)nums[i] <= (long long)t)
                return true;
            set1.insert(nums[i]);
        }
        return false;
    }
};

int main(){
    //int nums[] = {1,5,9,1,5,9};
    int nums[] = {-2147483648,-2147483647};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(nums[0]));
    Solution s;
    //if (s.containsNearbyAlmostDuplicate(vec, 2,3)){
    if (s.containsNearbyAlmostDuplicate(vec, 3,3)){
        cout << "is true" << endl;
    }else{
        cout << "is false" << endl;
    }
}