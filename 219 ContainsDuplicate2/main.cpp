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
     * 使用unordered_set保存滑动窗口（长度[0,k]）
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set1;

        for(int i = 0; i <nums.size(); i ++)
        {
            //有重复则返回
            if (set1.find(nums[i]) != set1.end())
                return true;
            //无重复则保存到set
            set1.insert(nums[i]);
            //set长度大于k，则需要移除前方的
            if (set1.size() > k){
                set1.erase(nums[i - k]);
            }
        }
        return false;
    }
    /*
     * 时间复杂度：O(n)
     * 使用unordered_map保存数组值，以及对应的下标容器
     */
    bool containsNearbyDuplicate2(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> map1;

        for (int i = 0; i < nums.size(); i ++) {
            map1[nums[i]].push_back(i);
        }

        for (unordered_map<int,vector<int>>::iterator iter = map1.begin(); iter != map1.end(); iter ++) {
            if (iter->second.size() >=2){
                sort(iter->second.begin(), iter->second.end());
                for (int i = 0; i < iter->second.size() - 1; i ++) {
                    if (iter->second[i+1] - iter->second[i] <= k )
                        return true;
                }
            }
        }
        return false;
    }
};
int main(){
    int nums[] = {1,2,3,1,2,3};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(nums[0]));
    Solution s;
    if (s.containsNearbyDuplicate2(vec, 2)){
        cout << "is true" << endl;
    }else{
        cout << "is false" << endl;
    }
}