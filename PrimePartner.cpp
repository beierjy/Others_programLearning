/*��������
��Ŀ����

��Ŀ����
�������������ĺ�Ϊ����������������������֮Ϊ���������¡�����2��5��6��13��������Ӧ����ͨ�ż��ܡ���������ѧ���������һ�����򣬴����е�N��NΪż����������������ѡ�����ɶ���ɡ��������¡�����ѡ�������ֶ�����������4����������2��5��6��13�������5��6��Ϊһ����ֻ�ܵõ�һ�顰�������¡�������2��5��6��13���齫�õ����顰�������¡�������ɡ��������¡����ķ�����Ϊ����ѷ���������Ȼ����ѧ��ϣ����Ѱ�ҳ�����ѷ�������
����:
��һ����ż��N��N��100������ʾ����ѡ����Ȼ���ĸ��������������������֣���ΧΪ[2,30000]��
���:
���һ������K����ʾ����õġ���ѷ�������ɡ��������¡��Ķ�����
 

��������:
����˵��
1 ����һ����ż��n
2 ����n������


�������:
��õġ���ѷ�������ɡ��������¡��Ķ�����

��������:
4
2 5 6 13

�������:
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
		static unsigned aPrimeList[] = { // ������  
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
				//δȷ���Ƿ�sum_pair = res[i+1]-res[j]+res[j+1]+1;?
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