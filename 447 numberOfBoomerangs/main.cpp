#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;
/*
 * 给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，
 * 其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
 * 找到所有回旋镖的数量
 */
class Solution {
public:
    /*
     * 时间复杂度：O(n^2)
     * 第一层循环来遍历i的值
     * 第二层循环，要找到所有与i的距离与对应次数
     * 使用unordered_map来保存每种距离的平方与对应次数
     * 次数times大于等于2的则有回旋镖。
     * 第一个点可能性为times，第二个点可能性times - 1，则最终的数量为times * (times - 1)
     */
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int count = 0;
        unordered_map<double,int> m;
        for (int i = 0; i < points.size(); i ++)
        {
            for (int j = 0;j < points.size(); j ++)
            {
                if (j != i)
                {
                    //以距离的平方为键，次数为值
                    double var = pow(points[j].first - points[i].first,2)+pow(points[j].second - points[i].second,2);
                    m[var]++;
                }
            }
            auto iter=m.begin();
            while(iter!=m.end())
            {
                if ((*iter).second >= 2)
                    count += (iter->second) * (iter->second - 1);//第一个点可能性为second，第二个点可能性second - 1
                iter++;
            }
            m.clear();
        }

        return count;
    }
};
int main() {
    pair<int, int> pair1(0,0);
    pair<int, int> pair2(1,0);
    pair<int, int> pair3(-1,0);
    pair<int, int> pair4(0,1);
    pair<int, int> pair5(0,-1);

    vector<pair<int, int>> vec;
    vec.push_back(pair1);
    vec.push_back(pair2);
    vec.push_back(pair3);
    vec.push_back(pair4);
    vec.push_back(pair5);
    Solution s;
    int ret = s.numberOfBoomerangs(vec);
    cout << ret << endl;
    return 0;
}