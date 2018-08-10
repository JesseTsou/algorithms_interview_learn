#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*
     * [0,k)表示不为val的数组元素
     * 遍历数组，当不等于目标值时，填入当前值
     * 等于目标值时，跳过
     * 即 将非目标值放入数组前面
     */
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != val) {
                if (i != k)
                    //swap(nums[i],nums[k++]);
                    nums[k++]=nums[i];
                else
                    k++;
            }
        }
        return k;
    }
    /*
     * 遍历数组，如果是目标值，则从数组最后的值替换到该位置，直到不为目标值
     * 如果不是目标值，则跳过
     */
    int removeElement2(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; )
        {
            if (nums[i] == val)
                nums[i] = nums[--size];
            else
                i ++;
        }
        return size;
    }
};
int print(vector<int> vec, int size)
{
    for (int i = 0; i < size; i ++)
        cout << vec[i] << " ";
    cout << endl;
    return 0;
}
int main() {
    int a[] = {1,2,3,4,5,7,3,7,7,7,7,7,7,7,7,4,5,6,7,8};
    vector<int> vecnums(a, a + sizeof(a)/sizeof(a[0]));
    print(vecnums, vecnums.size());
    Solution s;
    int len = s.removeElement2(vecnums, 7);
    print(vecnums, len);

    return 0;
}