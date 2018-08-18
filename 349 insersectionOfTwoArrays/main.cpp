#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

/*
 *给定两个数组，编写一个函数来计算它们的交集。
 */


int print(vector<int> vec)
{
    for(int e:vec)
        cout << e << " ";
    cout << endl;
}

class Solution {
public:
    /*
     * 时间复杂度：O(nlogn)
     * set以平衡二叉树实现，时间复杂度为O（logn）
     * set集合，键数据不能重复
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        for (int e:nums1)
            set1.insert(e);

        set<int> ret;
        for (int e:nums2){
            if (set1.find(e) != set1.end())
                ret.insert(e);
        }
        return vector<int> (ret.begin(), ret.end());
    }

    /*
     * 不申请两个set了，匹配上，set中即删除
     */
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(),nums1.end());
        /*
        for (int e:nums1)
            set1.insert(e);
        */
        vector<int> ret;
        for (int e:nums2){
            if (set1.find(e) != set1.end()){
                ret.push_back(e);
                set1.erase(e);
            }
        }
        return ret;
    }

    /*
     * 时间复杂度：O(n)
     * unordered_set使得哈希表实现，时间复杂度：O(1)
     */
    vector<int> intersection3(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        /*
        for (int e:nums1)
            set1.insert(e);
        */
        vector<int> ret;
        for (int e:nums2){
            if (set1.find(e) != set1.end()){
                ret.push_back(e);
                set1.erase(e);
            }
        }
        return ret;
    }

    /*
     * 如果输入的数组均为有序数组
     * 时间复杂度：O(nlogn)
     * 使用了二分查找进行数据的查找
     */
    bool binary_find(vector<int> vec, int tar)
    {
        bool isfind = false;
        int left = vec[0];
        int right = vec[vec.size() - 1];
        while (left <= right){
            int mid = (left + right)/2;
            if (vec[mid] > tar){
                right = mid - 1;
            }else if (vec[mid] < tar){
                left = mid + 1;
            }
            else{
                isfind =  true;
                break;
            }
        }
        return isfind;
    }
    bool isexist(vector<int> vec, int tar)
    {
        bool isexist = false;
        for (int e:vec) {
            if (e == tar) {
                isexist = true;
                break;
            }
        }
        return isexist;
    }
    vector<int> intersection4(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        for (int e:nums1){
            if (binary_find(nums2,e)){
                if (!isexist(ret, e))
                    ret.push_back(e);
            }
        }

        return ret;
    }
};

int main() {
    int nums1[] = {3,4,5,5,6,7};
    int nums2[] = {1,2,3,3,5,6,7,8};
    vector<int> vec1(nums1, nums1+sizeof(nums1)/sizeof(nums1[0]));
    vector<int> vec2(nums2, nums2+sizeof(nums2)/sizeof(nums2[0]));

    print(vec1);
    print(vec2);

    Solution s;
    print(s.intersection4(vec1,vec2));

    return 0;
}