#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 *给定四个包含整数的数组列表 A , B , C , D ,
 * 计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
 * 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。
 * 所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
 */
class Solution {
public:
    /*
     * 时间复杂度：O(n^2)
     * 使用unordered_map保存C D各元素的和的次数
     * 再对A B进行循环，查找map，是否有和为0的值
     */
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map1;
        int count = 0;
        for (int i = 0; i < C.size(); i ++)
        {
            for (int j = 0; j < D.size(); j ++)
            {
                map1[C[i] + D[j]] ++;
            }
        }

        for (int i = 0; i < A.size(); i ++)
        {
            for (int j = 0; j < B.size(); j ++)
            {
                int tar = 0 - A[i] - B[j];
                auto iter = map1.find(tar);
                if (iter != map1.end()){
                    count += iter->second;
                }
            }
        }
        return count;
    }
};

int main() {
    int nums1[] = {1,2};
    int nums2[] = {-2,-1};
    int nums3[] = {-1,2};
    int nums4[] = {0,2};
    vector<int>  vec1 (nums1, nums1 + sizeof(nums1)/sizeof(nums1[0]));
    vector<int>  vec2 (nums2, nums2 + sizeof(nums2)/sizeof(nums2[0]));
    vector<int>  vec3 (nums3, nums3 + sizeof(nums3)/sizeof(nums3[0]));
    vector<int>  vec4 (nums4, nums4 + sizeof(nums4)/sizeof(nums4[0]));

    Solution s;
    int ret = s.fourSumCount(vec1,vec2,vec3,vec4);
    cout << ret << endl;
    return 0;
}