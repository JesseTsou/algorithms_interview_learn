#include <iostream>
using namespace std;

/*
 *假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 */
class Solution {
public:
    /*
     * 动态规划
     * 第1阶：1种方法（1）
     * 第2阶：2种方法（1+1、0+2）
     * 第3阶：在第1阶爬两级或者在第二阶爬一级，即前两个之和
     * 。。。
     * 综上，f(n) = f(n-1) + f(n-2)
     */
    /*
     * 滚动数组
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int climbStairs(int n) {
        int a = 0, b = 0, c = 1;
        for (int i = 1; i <= n; i ++){
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
    /*
     * 递归
     * 时间复杂度：O(2^n)
     * 空间复杂度：O(n)
     * 重复计算太多了，不能通过
     */
    int climbStairs2(int n){
        if (n == 1){
            return 1;
        }
        if (n == 2){
            return 2;
        }

        return climbStairs2(n - 1) + climbStairs2(n - 2);
    }
};

int main() {

    Solution s;
    cout << s.climbStairs2(50) << endl;
    return 0;
}
