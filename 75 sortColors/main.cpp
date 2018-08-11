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

    void sortColors2(vector<int>& nums) {
    }
};

int main() {
    int a[]= {1,2,0,0,2,1,2,0,1};
    vector <int> vec (a, a + sizeof(a)/sizeof(a[0]));
    print(vec);
    Solution s;
    s.sortColors(vec);
    print(vec);
    return 0;
}