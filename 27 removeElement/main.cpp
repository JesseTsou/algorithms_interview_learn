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
    int len = s.removeElement(vecnums, 7);
    print(vecnums, len);

    return 0;
}