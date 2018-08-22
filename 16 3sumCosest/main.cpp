#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
#include <cmath>

using namespace std;
/*
 *给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
 * 使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 */

class Solution {
public:
    /*
     * 时间复杂度：O(n^2)
     * 第一层遍历，第二层采用对撞指针的方法
     * 后两数的和要不断趋近于 target-第一个数
     */
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        //对小于等于三个数的情况作处理
        if (nums.size() <= 3){
            for (int i = 0; i < nums.size(); i ++)
            {
                res += nums[i];
            }
            return res;
        }
        //从小到大排序
        sort(nums.begin(), nums.end());
        //初始值设置为前三个之和，应该是最小值
        int min = abs(target - nums[0] -nums[1] - nums[2]);
        res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i ++)
        {
            //获取差离目标的差值
            int sum = target - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] == sum)
                    return target;
                else{
                    //计算间隔
                    int tmpmin = abs(sum - nums[l] - nums[r]);
                    //若小于原间隔，则记录最小间隔值
                    if (min > tmpmin){
                        min = tmpmin;
                        res = nums[i] + nums[l] + nums[r];
                    }
                    //若后两数之和大于差值，则需要减小，右边界左移
                    if(nums[l] + nums[r] > sum) {
                        r --;
                        while(l < r && nums[r] == nums[r+1])//去重
                            r--;
                    }else{//若后两数之和小于差值，则需要增加，左边界右移
                        l ++;
                        while(l < r && nums[l] == nums[l-1])//去重
                            l++;
                    }
                }
            }

            while(i < nums.size() - 2 && nums[i] == nums[i+1])//去重
                i++;
        }
        return res;
    }
};

int main() {
    //int nums[] = {-1,2,1,-4};
    int nums[] = {1,1,1,1};
    vector<int>  vec (nums, nums + sizeof(nums)/sizeof(nums[0]));

    Solution s;
    int ret = s.threeSumClosest(vec,0);
    cout << ret << endl;
    return 0;
}