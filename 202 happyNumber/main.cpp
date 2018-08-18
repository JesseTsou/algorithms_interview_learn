#include <iostream>
#include <unordered_set>
using namespace std;
/*
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 一个“快乐数”定义为：
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
 * 然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。
 * 如果可以变为 1，
 * 那么这个数就是快乐数。
 */

class Solution {
public:
    /*
     * 时间复杂度：O(n)
     * 使用unordered_set存储计算结果，若有重复值，则说明，会无限循环，则退出
     */
    bool isHappy(int n) {
        unordered_set<int> set1;
        while (1)
        {
            n = getres(n);
            if (n == 1)
                return true;
            if(set1.find(n) != set1.end()){
                return false;
            }else{
                set1.insert(n);
            }
        }

        return false;
    }

    int getres(int n)
    {
        int res = 0;
        while (n)
        {
            int n1 = n % 10;
            res += n1 * n1;
            n /= 10;
        }
        return res;
    }
};

int main() {
    int num = 191;
    cout << num << endl;
    Solution s;
    if (s.isHappy(num)){
        cout << "is happy num" << endl;
    }else{
        cout << "is not happy num" << endl;
    }
    return 0;
}