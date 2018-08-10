#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     *时间复杂度：O(n)
     * 相同数值，记录重复次数，大于2则不赋值
     * 不同数值，次数重置
     */
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;

        int k = 0;
        int time = 0;
        int val = nums[0];
        int count = 0;
        for (int i = 0; i < size; i ++)
        {
            if (val == nums[i])
            {
                time ++;
                if (time <= 2)
                {
                    nums[k++] = nums[i];
                } else
                    count ++;
            } else {
                time = 1;
                nums[k] = nums[i];
                val = nums[k++];
            }
        }
        return size - count;
    }

    /*
     * 优化了一些冗余操作
     * 直接从遍历从第二个数开始
     */
    int removeDuplicates2(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;

        int k = 1;
        int time = 1;
        int val = nums[0];
        for (int i = 1; i < size; i ++)
        {
            if (val == nums[i])
            {
                if (time < 2)
                {
                    time ++;
                    nums[k++] = nums[i];
                }
            } else {
                time = 1;
                nums[k] = nums[i];
                val = nums[k++];
            }
        }
        return k;
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
    int len = s.removeDuplicates(vecnums);
    print(vecnums, len);
    return 0;
}