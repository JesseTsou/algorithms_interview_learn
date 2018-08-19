#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;
class Solution {
public:
    /*
     * 时间复杂度：O(n)
     * 两个map，分别代表s与t的对应关系
     */
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map1;//s:char->t:char
        unordered_map<char,char> map2;//t:char->s:char

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i ++)
        {
            if (map1[s[i]] == 0 && map2[t[i]] == 0){
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }else{
                if (map1[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
    /*
     * 时间复杂度：O(n)
     * 使用数组又实现了以上一遍
     * map会有冗余操作
     */
    bool isIsomorphic2(string s, string t) {
        int m[256] = {0};//s:char->t:char
        int n[256] = {0};//t:char->s:char

        for (int i = 0; i <s.size(); i ++){
            if (m[s[i]] == 0 && n[t[i]] == 0){
                m[s[i]] = t[i];
                n[t[i]] = s[i];
            }else{
                if (m[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
    /*
     * 时间复杂度：O(n)
     * 第二个数组表示t中元素是否出现过，避免重复
     */
    bool isIsomorphic3(string s, string t) {
        int m[256] = {0};//s:char->t:char
        bool n[256];     //t中元素是否出现过
        memset(m,-1, sizeof(m));
        memset(n,false, sizeof(n));

        for (int i = 0; i <s.size(); i ++){
            if (m[s[i]] == -1){
                if (n[t[i]] == true)
                    return false;
                m[s[i]] = t[i];
                n[t[i]] = true;
            }else{
                if (m[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};

int main() {
    string str1 = "egg";
    string str2 = "abb";
    Solution s;
    if (s.isIsomorphic3(str1,str2)){
        cout << "is isomorphic" << endl;
    }else{
        cout << "is not isomorphic" << endl;
    }
    return 0;
}