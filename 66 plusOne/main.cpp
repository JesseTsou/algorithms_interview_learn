#include <iostream>
#include <vector>
using namespace std;

/*
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 */
class Solution {
public:
    /*
     * 从后往前，每一位相加，直至第一位，如果仍然大于10，则需要申请额外空间存放1
     */
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        digits[digits.size() - 1] += 1;
        for (int i = digits.size() - 1; i > 0; i --){
            if (digits[i] >= 10){
                digits[i] %= 10;
                digits[i - 1] += 1;
            }

        }

        if (digits[0] >= 10){
            digits[0] %= 10;
            res.push_back(1);
            for (int i = 0; i < digits.size(); i ++){
                res.push_back(digits[i]);
            }
            return res;
        }
        return digits;
    }
    /*
     * 从后往前，如果+1后，对10取余不为0，说明不需要进位，前边的原样不动即可
     * 如果循环后，没有返回，说明有一个进位，需要在前边插入1
     */
    vector<int> plusOne1(vector<int>& digits) {
        for (int i = digits.size() -1 ; i >= 0; i --){
            digits[i] ++;
            digits[i] %= 10;
            if (digits[i] != 0){
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    vector<int> digits;
    digits.push_back(9);
    digits.push_back(9);
    Solution s;
    vector<int> a = s.plusOne1(digits);
    for (int i = 0; i < a.size(); i ++){
        cout << a[i] << endl;
    }

    return 0;
}
