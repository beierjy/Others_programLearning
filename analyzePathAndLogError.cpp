#include<iostream>
#include <string>
#include <utility>
//#include <algorithm>
#include <vector>
using namespace std;

string refinefilename(string str){
	if (str.size() == 0)
		return "";
	string str1 = "";
	string str2 = "";
	for (int i = str.size() - 1, k = 0; i >= 0 && k<16 && str[i] != '\\'; k++, i--){
		str1 += str[i];
	}
	for (int i = str1.size() - 1; i >= 0; i--){
		str2 += str1[i];
	}
	return str2;
}
bool find_i(vector<pair<string, int >> vec, int i){
	if (i < 0 || vec.size() <= 0)
		return false;
	for (int j = 0; j < i; j++){
		if (refinefilename(vec[i].first)==refinefilename(vec[j].first)&&vec[i].second==vec[j].second)
			return true;
	}
	return false;
}
void ErrorLog(vector<pair<string, int> > vec){
	if (vec.size() <= 0)
		return;
	vector< pair< pair<string, int>, int> > mlog;
	for (int i = 0; i < vec.size(); i++){
		string str = "";
		string str1 = "";
		if (i == 0||!find_i(vec,i)){
			str = vec[i].first;
			str1 = refinefilename(str);
			pair<string, int> pa1 = make_pair(str1, vec[i].second);
			pair<pair<string, int>, int> pa2 = make_pair(pa1, 1);
			mlog.push_back(pa2);
		}
		else{
			str = vec[i].first;
			str1 = refinefilename(str);
			pair<string, int> pa1 = make_pair(str1, vec[i].second);
			for (int i = 0; i <mlog.size(); i++){
				if (mlog[i].first == pa1)
					mlog[i].second++;
			}
		}
	}
	int  cnt = 0;
	if (mlog.size() > 8)
		cnt = mlog.size() - 8;
	for (; cnt < mlog.size(); cnt++){
		pair<pair<string, int>, int> pa2 = *(mlog.begin() + cnt);
		pair<string, int> pa1 = pa2.first;
		int a = pa2.second;
		cout << pa1.first << " " << pa1.second << " " << a << " ";
	}
}
int main(){
	vector<pair<string, int> > vec;
	string str;
	int a;
	while (cin >> str >> a){
		vec.push_back(make_pair(str, a));
	}
	for (int i = 0; i < vec.size(); i++){
		cout << vec[i].first << "\t" << vec[i].second << " " << i <<endl;
	}
	ErrorLog(vec);
	system("pause");
	return 0;
}