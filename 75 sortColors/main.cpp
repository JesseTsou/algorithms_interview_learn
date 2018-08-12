#include <iostream>
#include <vector>

using namespace std;

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
     * 两趟遍历
     * 第一趟取出0 1 2 的个数
     * 第二趟重写数组
     */
    void sortColors(vector<int>& nums) {
            int num1 = 0, num2 = 0, num3 = 0;
            for (int i = 0; i < nums.size(); i ++)
            {
                if (nums[i] == 0)
                    num1 ++;
                if (nums[i] == 1)
                    num2 ++;
                if (nums[i] == 2)
                    num3 ++;
            }
            for (int i = 0; i < num1; i ++)
            {
                nums[i] = 0;
            }
            for (int i = num1; i < num1+ num2; i ++)
            {
                nums[i] = 1;
            }
            for (int i = num1 + num2; i < nums.size(); i ++)
            {
                nums[i] = 2;
            }
    }
    /*
     * 修改上述方法，用数组来存储个数
     */
    void sortColors2(vector<int>& nums) {
        int record[3] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            record[nums[i]] ++;
        }
        int k = 0;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < record[i]; j++) {
                nums[k++] = i;
            }
        }
    }
    /*
     * 时间复杂度：O(n)
     * 一次循环
     * [0,zero)存储0
     * （two,size-1]存储2
     * [zero,two]存储1
     * 注意变量定义范围
     */
    void sortColors3(vector<int>& nums) {
        int zero = 0;
        int two = nums.size() - 1;
        for (int i = 0; i <= two; )
        { ;
            if (nums[i] == 0)
            {
                swap(nums[zero++], nums[i++]);
            } else if (nums[i] == 2){
                swap(nums[two--],nums[i]);
            } else if (nums[i] == 1)
                i ++;
        }
    }
};

int main() {
    //int a[]= {1,2,0,0,2,1,2,0,1};
    int a[]= {2,0,1};
    vector <int> vec (a, a + sizeof(a)/sizeof(a[0]));
    print(vec);
    Solution s;
    s.sortColors2(vec);
    print(vec);
    return 0;
}