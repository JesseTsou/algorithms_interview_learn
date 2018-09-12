#include <iostream>
#include <vector>

using namespace std;

/*
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 必须原地修改，只允许使用额外常数空间。
 */

class Solution {
public:
    /*
     * 时间复杂度：O(n)
     * 找到下一个更大序列，可以理解为将数字序列想像成由这些数字序列组成的一个数字，要找到相同数字组合的下一个更大数字。
     * 从序列的右边开始遍历，找到第一个相邻的数字序列[i,i+1]满足i+1的值大于i的值，那么从i到数字序列结尾就需要重新排列了。
     * 比如说[1,2,3,4,5,6,1]，第一个满足上述条件的是5与6，需要将5到结尾的序列重新排列。
     * 这里需要注意的是如果满足上述条件，[i+1,nums.size() -1]区间必定是一个降序序列。
     * 重新排列是为了找到最近的较大值，我们需要在[i+1,nums.size() -1]的区间找到最小的比nums[i]大的值，然后与nums[i]进行交换。
     * 由于该区间是降序序列，从后往前遍历第一个比nums[i]大的位置即是我们要找的。
     * 上述例子[1,2,3,4,5,6,1]，6是最小的比5大的值，需要与5交换：[1,2,3,4,6,5,1]
     * 交换以后，得到的序列并不是“下一个”更大的序列，还需要将[i+1,nums.size() -1]进行反转，将较小的数移至高位，才能得到满足条件的序列。
     * 上述例子，将[1,2,3,4,6,5,1]中的[5,1]进行反转，得到序列[1,2,3,4,6,1,5]，即最终结果。
     * 特殊地，若找不到第一个相邻的数字序列[i,i+1]满足i+1的值大于i的值，即本身序列是个降序序列，则需要将整个序列整体反转。
     */
    void nextPermutation(vector<int>& nums) {
        int tmp = 0;
        int i = 0;
        //找到第一个相邻的数字序列[i,i+1]满足i+1的值大于i的值
        for(i = nums.size() - 2; i >=  0; i --){
            if (nums[i] < nums[i + 1]){
                break;
            }
        }

        if (i >= 0){
            int j = 0;
            //从后往前遍历第一个比nums[i]大的位置
            for (j = nums.size() - 1; j >= 0; j --){
                if (nums[j] > nums[i]){
                    break;
                }
            }
            swap(nums, i, j);
        }
        //反转序列
        revert(nums, i + 1);

        return;
    }
private:
    int swap(vector<int>& nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        return 0;
    }

    int revert(vector<int> & nums, int start)
    {
        int i = start;
        int j = nums.size() - 1;

        while(i < j){
            swap(nums,i,j);
            i ++;
            j --;
        }
        return 0;
    }
};


int print(vector<int> vec)
{
    for (auto e:vec)
        cout <<  e << " ";
    cout << endl;

    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(1);

    print(nums);

    Solution s;
    s.nextPermutation(nums);

    print(nums);

    return 0;
}