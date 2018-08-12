#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 *给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 */
class Solution {
public:
    /*
     * 使用暴力解法
     * 时间复杂度：O(n^2)
     */
    vector<int> twoSum_n2(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i ++)
        {
            for(int j = i + 1; j < nums.size(); j ++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        throw;
    }
    /*
     * 两遍hash
     *使用hash map来存储键值对，然后再搜索target - val是否存在
     * unordered_map 在C++ 11被引标准库，而hash_map没有，建议使用unordered_map
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    vector<int> twoSum_map1(vector<int>& nums, int target) {
        unordered_map<int,int> mymap;
        vector<int>  ret;
        for(int i = 0; i < nums.size(); i ++)
        {
            mymap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i ++)
        {
            int sec = target - nums[i];
            if (mymap.find(sec) != mymap.end() && i != mymap[sec] )
            {
                ret.push_back(i);
                ret.push_back(mymap[sec]);
                return ret;
            }
        }
        throw;
    }
    /*
     * 一遍hash
     * 只使用一次循环，先进行查询再插入数值
     * 时间复杂度：O（n）
     * 空间复杂度：O(n)
     */
    vector<int> twoSum_map2(vector<int>& nums, int target) {
        unordered_map<int,int> mymap;
        vector<int>  ret;

        for (int i = 0; i < nums.size(); i ++)
        {
            int sec = target - nums[i];
            if (mymap.find(sec) != mymap.end() && i != mymap[sec] )
            {
                ret.push_back(mymap[sec]);
                ret.push_back(i);
                return ret;
            }
            mymap[nums[i]] = i;
        }
        throw;
    }
};
int main() {
    int nums[] = {3,2,4};
    vector<int>  val (nums, nums + sizeof(nums)/sizeof(nums[0]));

    Solution sl;
    vector<int> ret;
    ret = sl.twoSum_n2(val, 6);
    cout << ret[0] << "," << ret[1] << endl;

    ret = sl.twoSum_map1(val, 6);

    cout << ret[0] << "," << ret[1] << endl;

    ret = sl.twoSum_map2(val, 6);

    cout << ret[0] << "," << ret[1] << endl;

    return 0;
}