#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int print(vector<int> vec)
{
    for(int e:vec)
        cout << e << " ";
    cout << endl;
}

class Solution {
public:
    /*
     * 使用map来存储元素与次数
     * 时间复杂度：O(nlogn)
     * map以平衡二叉树实现，O(logn)
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> map1;
        for (int e:nums1)
            map1[e] ++;

        vector<int> ret;
        for (int e:nums2)
            if(map1[e] > 0){
                ret.push_back(e);
                map1[e] --;
            }
        return ret;
    }

    /*
 * 使用map来存储元素与次数
 * 时间复杂度：O(n)
 * unordered_map以哈希表实现，O(1)
 */
    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map1;
        for (int e:nums1)
            map1[e] ++;

        vector<int> ret;
        for (int e:nums2)
            if(map1[e] > 0){
                ret.push_back(e);
                map1[e] --;
            }
        return ret;
    }
};

int main() {
    int nums1[] = {3,3,4,5,5,6,7};
    int nums2[] = {1,2,3,3,5,6,7,8};
    vector<int> vec1(nums1, nums1+sizeof(nums1)/sizeof(nums1[0]));
    vector<int> vec2(nums2, nums2+sizeof(nums2)/sizeof(nums2[0]));

    print(vec1);
    print(vec2);

    Solution s;
    print(s.intersect2(vec1,vec2));

    return 0;
}