#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 输入为 非空 字符串且只包含数字 1 和 0。
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int sizea = a.size();
        int sizeb = b.size();

        //为了对齐，将两个字符串等长，不足的部分补'0'
        while (sizea > sizeb){
            b = '0' + b;
            sizeb ++;
        }
        while (sizea < sizeb){
            a = '0' + a;
            sizea ++;
        }

        //从后往前遍历，将对应的字符相加
        for (int i = a.size() - 1; i > 0; i --){
            a[i] = a[i] - '0' + b[i];
            if (a[i] >= '2'){//若大于'2'，则需要该位对2取模，下一位加1
                a[i] = (a[i] - '2') % 2 + '0';
                a[i - 1] += 1;
            } 
        }

        //对于第0位要单独处理
        a[0] = a[0] - '0' + b[0];
        if (a[0] >= '2'){
            a[0] = (a[0] - '2') % 2 + '0';
            a = '1' + a;
        }
        return a;
    }

    string addBinary1(string a, string b) {
        string res;
        //为了对齐，反转两个字符串
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int size = max(a.size(), b.size());

        //从前往后，对位相加
        int carry = 0;//进位
        for (int i = 0; i < size; i ++){
            if (i < a.size()){
                carry += (a[i] - '0');
            }
            if (i < b.size()){
                carry += (b[i] - '0');
            }
            res.push_back((carry % 2) + '0');//该位对2取模
            carry /= 2;//进位对2取余
        }
        if (carry){
            res.push_back('1');
        }

        //最终结果，反转回来
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {

    Solution s;
    cout << s.addBinary1("0", "0") << endl;
    return 0;
}
