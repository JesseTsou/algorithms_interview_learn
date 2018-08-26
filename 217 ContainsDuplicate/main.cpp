#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    /*
     * 时间复杂度：O(n)
     * 使用unordered_map保存值与次数
     */
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map1;
        for (int i = 0; i < nums.size(); i ++) {
            map1[nums[i]] ++;
            if (map1[nums[i]] >= 2)
                return true;
        }
        return false;
    }
    /*
     * 对数组进行排序
     * 若相邻有相等的则满足条件
     */
    bool containsDuplicate2(vector<int>& nums) {
        if (nums.empty())
            return false;
        vector<int> temp(nums);
        sort(temp.begin(),temp.end());
        for (int i = 0; i < temp.size() - 1;i++){
            if (temp[i] == temp[i + 1])
                return true;
        }
        return false;
    }
};
int main(){
    int nums[] = {1,2,3,1,2,3};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(nums[0]));
    Solution s;
    if (s.containsDuplicate2(vec)){
        cout << "is true" << endl;
    }else{
        cout << "is false" << endl;
    }
}