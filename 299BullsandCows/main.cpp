#include <iostream>
#include <string>
#include <vector>
#include<sstream>
using  namespace std;

/*
 * 你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：
    你写出一个秘密数字，并请朋友猜这个数字是多少。
    朋友每猜测一次，你就会给他一个提示，告诉他的猜测数字中有多少位属于数字和确切位置都猜对了（称为“Bulls”, 公牛），有多少位属于数字猜对了但是位置不对（称为“Cows”, 奶牛）。
    朋友根据提示继续猜，直到猜出秘密数字。
    请写出一个根据秘密数字和朋友的猜测数返回提示的函数，返回字符串的格式为 xAyB ，x 和 y 都是数字，A 表示公牛，用 B 表示奶牛。
    xA 表示有 x 位数字出现在秘密数字中，且位置都与秘密数字一致。
    yB 表示有 y 位数字出现在秘密数字中，但位置与秘密数字不一致。
    请注意秘密数字和朋友的猜测数都可能含有重复数字，每位数字只能统计一次。
 */

class Solution {
public:
    /*
     * 遍历字符串，若每一位都相等，则相等的个位即A的个数
     * 若有不相等的，则统计两个字符串各数字的个数（用map存储），最后将个数最小的相加即B的个数
     * 时间复杂度O(n)
     * 空间复杂度O(1)
     */
    string getHint(string secret, string guess) {
        int smap[10] = {0};
        int gmap[10] = {0};
        int A = 0, B = 0;
        for (int i = 0; i < guess.size(); i ++){
            if (secret[i] == guess[i]){
                A ++;
            }else{
                smap[secret[i] - '0'] ++;
                gmap[guess[i] - '0'] ++;
            }
        }
        for (int i = 0; i < 10; i ++){
            B += smap[i] < gmap[i] ? smap[i] : gmap[i];
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
    /*
     * 当同位置元素相同时，A++
     * 当同位置元素不同时，用一个map保存两个数字,secret中出现过的加一，guess中出现的减一，则下次判断同一个map中的值的大小，可知之前对方中是否出现过
    */
    string getHint2(string secret, string guess) {
        int map[10] = {0};
        int A = 0, B = 0;
        int s = 0, g = 0;
        for (int i = 0; i < guess.size(); i ++){
            s = secret[i] - '0';
            g = guess[i] - '0';
            if (s == g){
                A ++;
            }else{
                if (map[s] < 0) B ++;//小于0时，说明之前guess出现过，则B++
                if (map[g] > 0) B ++;//大于0时，说明之前secret出现过，则B++
                map[s] ++;
                map[g] --;
            }
        }

        return to_string(A) + "A" + to_string(B) + "B";
    }
};

int main() {
    Solution s;
    return 0;
}