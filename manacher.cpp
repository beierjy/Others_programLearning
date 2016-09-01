/*素数伴侣
题目描述

题目描述
若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，它们能应用于通信加密。现在密码学会请你设计一个程序，从已有的N（N为偶数）个正整数中挑选出若干对组成“素数伴侣”，挑选方案多种多样，例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能得到一组“素数伴侣”，而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的方案称为“最佳方案”，当然密码学会希望你寻找出“最佳方案”。
输入:
有一个正偶数N（N≤100），表示待挑选的自然数的个数。后面给出具体的数字，范围为[2,30000]。
输出:
输出一个整数K，表示你求得的“最佳方案”组成“素数伴侣”的对数。
 

输入描述:
输入说明
1 输入一个正偶数n
2 输入n个整数


输出描述:
求得的“最佳方案”组成“素数伴侣”的对数。

输入例子:
4
2 5 6 13

输出例子:
2
*/

#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
bool isPrime(int p){
	if (p <= 1)
		return false;
	else{
		static unsigned aPrimeList[] = { // 素数表  
			2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,
          71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,
          149,151,157,163,167,173,179,181,191,193,197,199,211,223,
          227,229,233,239,241,251,257,263,269,271,277,281,283,293 };
		int nListNum = sizeof(aPrimeList) / sizeof(unsigned);
		for (size_t i = 0; i < nListNum; ++i)
		{
			if (p > aPrimeList[i]&& (p % aPrimeList[i]) == 0)
				return false;
		}
		return true;
	}
}

int countPrime(vector<int> ivec){
	int sum_pair = 0;
	if (ivec.size() == 0)
		return 0;
    vector<int> res(ivec.size()+1);
    size_t n = ivec.size();
	for(int i = n -2;i >= 0;i--){
        for(int j = n -1;j > i;j--){
            if(isPrime(ivec[i]+ivec[j])){
                sum_pair = res[i+1]-res[j-1]+res[j+1]+1;
				//未确定是否sum_pair = res[i+1]-res[j]+res[j+1]+1;?
            }
            else
                sum_pair = res[i+1];
            if(sum_pair>res[i])
            	res[i] = sum_pair;
        }  
    }
	for(int i = 0;i < n;i++)
		cout<<res[i]<<"\t";
	return res[0];
}
int main(){
	int n;
	while (cin >> n){
		while (n & 1 == 0){
			cin >> n;
		}
		vector<int> ivec;
		for (int i = 0; i < n; i++){
			int j;
			cin >> j;
			ivec.push_back(j);
		}
		int res = countPrime(ivec);
		cout << res << endl;
	}
	return 0;
}