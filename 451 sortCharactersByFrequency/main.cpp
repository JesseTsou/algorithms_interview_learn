#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * 时间复杂度：O(nlogn)
     * 使用vector的下标来表示次数
     * 同一次数在vector的某个元素内
     * 再倒数输出即是所得
     */
    string frequencySort(string s) {
        unordered_map<char,int> map1;
        for (char e:s)
            map1[e] ++;

        vector<string> vec(s.size() + 1, "");
        string res;
        for (auto e:map1)
        {
            vec[e.second].append(e.second, e.first);
        }
        for (int i = vec.size() - 1; i >= 0; i --)
        {
            if (!vec[i].empty())
                res.append(vec[i]);
        }
        return res;
    }
    /*
     * 时间复杂度：O(nlogn)
     * 使用sort，对所得的结果进行排序
     */
    string frequencySort2(string s) {
        unordered_map<char, int> map1;
        for (char e:s)
            map1[e]++;

        vector<pair<char,int>> vec(map1.begin(),map1.end());
        sort(vec.begin(),vec.end(),[](const pair<char,int> &a, const pair<char,int> &b)
        {
            return a.second >= b.second;
        });//使用了匿名函数,比较second，降序排列

        string res;
        for (auto i:vec)
        {
            res.append(i.second, i.first);
        }
        return res;
    }
};

int main() {
    string str = "tree";
    Solution s;
    string str1 = s.frequencySort2(str);
    cout << str1 << endl;
    return 0;
}