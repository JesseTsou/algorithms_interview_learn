#include <iostream>
#include <vector>
using namespace std;
/*
 *给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 *不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 */
class Solution {
public:
    /*
     * 暴力破解法，时间复杂度O(n^3)
     * 注意：将重复元素被后面的元素替换后，二级下标不能再次后移了
     */
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i ++)
        {
            for (int j = i + 1; j < size; j ++)
            {
                if (nums[j] == nums[i])
                {
                    for (int k = j; k < size - 1; k ++)
                    {
                        nums[k] = nums[k + 1];
                    }
                    size --;
                    j --;
                }
            }
        }
        return size;
    }
    /*
     * 时间复杂度：O(n^2)
     * （k,n]表示不重复的位置
     * 遍历数组，其他的再次遍历，若不重复，则写入k所在位置，k向后移
     * 若重复，则k不变
     */
    int removeDuplicates2(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i ++)
        {
            int k = i + 1;
            int count = 0;
            for (int j = i + 1; j < size; j ++)
            {
                if (nums[j] != nums[i])
                {
                    nums[k ++] = nums[j];
                } else{
                    count ++;
                }
            }
            size -= count;
        }
        return size;
    }
    /*
     * 啊啊啊
     * 注意：数组为排序数组
     * 只需要保证相邻的不重复即可
     * 时间复杂度：O(n)
     */
    int removeDuplicates3(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
        {
            return 0;
        }
        int k = 0;
        for (int i = 0; i < size; i ++)
        {
            if (nums[k] != nums[i])
            {
                nums[++k] = nums[i];
            }
        }
        return k + 1;
    }
};

int print(vector<int> vec, int size)
{
    for (int i = 0; i < size; i ++)
        //for (int i = 0; i < vec.size(); i ++)
        cout << vec[i] << " ";
    cout << endl;
    return 0;
}

int main() {
    int a[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> vecnums(a, a + sizeof(a)/sizeof(a[0]));
    print(vecnums, vecnums.size());
    Solution s;
    int len = s.removeDuplicates3(vecnums);
    print(vecnums, len);
    return 0;
}