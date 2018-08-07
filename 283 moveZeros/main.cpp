#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*
     * 将非零元素填在前方，后面用零填充
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }
        for (;j < nums.size(); j ++)
        {
            nums[j] = 0;
        }
    }

    /*
     * 记录第一个非零元素位置flag，后继的非零元素与flag后一个（即0）交换
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void moveZeroes2(vector<int>& nums) {
        int flag = -1;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (nums[i] != 0 )
            {
                flag = i;
            } else
                break;
        }

        for (int i = flag + 1; i < nums.size(); i ++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i],nums[++flag]);
            }
        }
    }
    /*
     * 记录第一个最前的一个零值，用后续的非零值与其交换
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void moveZeroes3(vector<int>& nums) {
        int flag = 0;//记录第一个最前的一个零值
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                if (flag != i)
                {
                    swap(nums[flag++], nums[i]);
                } else
                    flag ++;
            }
        }
    }
};
int print(vector<int> val)
{
    for (int e : val)
        cout << e << endl;

    return 0;
}
int main() {
    int nums[] = {0,0,0,0,0,0,5,0};
    vector<int> val(nums, nums + sizeof(nums)/sizeof(nums[0]));
    Solution sl;
    sl.moveZeroes3(val);
    print(val);

    return 0;
}