#include <iostream>
#include <vector>
using  namespace std;
/*
 *给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
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
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     * 申请了额外一块空间来存储数据
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(nums1);
        int i = 0;//[0,m+n)
        int k = 0;//[0,n)
        int p = 0;//[0,m)
        for (; i < m + n && p < m && k < n; i ++)
        {
            if (nums2[k] < nums1[p])
            {
                tmp[i] = nums2[k++];
            } else if (nums2[k] > nums1[p]){
                tmp[i] = nums1[p++];
            } else{
                tmp[i++] = nums1[p++];
                tmp[i] = nums2[k++];
            }
        }
        if (p < m)
        {
            for (; i < m+n; i++)
            {
                tmp[i] = nums1[p++];
            }
        } else if (k < n) {
            for (; i < m+n; i++)
            {
                tmp[i] = nums2[k++];
            }
        }
        nums1=tmp;
    }
    /*
      * 时间复杂度：O(n)
      * 空间复杂度：O(1)
      * 从数组1的末尾开始比较与赋值
      * 若第一轮循环过后
      *     k大于0,说明数组2还有未合并的元素；
      *     j大于0，则不用再合并了（元素即在数组中）
      */
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1;//[0,m+n)
        int j = m - 1;//[0,m)
        int k = n - 1;//[0,n)
        while (j >= 0 && k >= 0)
        {
            nums1[i--] = (nums1[j]>nums2[k] ? nums1[j--] : nums2[k--]);
        }
        while(k >= 0)
        {
            nums1[i--] = nums2[k--];
        }
    }
};

int main(){
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    vector <int> vec1 (nums1, nums1 + sizeof(nums1)/sizeof(nums1[0]));
    vector <int> vec2 (nums2, nums2 + sizeof(nums2)/sizeof(nums2[0]));
    print(vec1);
    Solution s;
    s.merge2(vec1,3,vec2,3);
    print(vec1);
    return 0;
}