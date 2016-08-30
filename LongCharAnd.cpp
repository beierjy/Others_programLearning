#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isvalid = true;
string addCore(string str1, string str2){
	if (str1.size() == 0)
		return str2;
	if (str2.size() == 0)
		return str1;
	if (str1.size() == 0 && str2.size() == 0)
	{
		isvalid = false;
		return str1;
	}
	int len1 = str1.size() - 1;
	int len2 = str2.size() - 1;
	int len = 0;
	if (len1>len2)
		len = len1 + 1;
	else
		len = len2 + 1;
	string res(len + 1, '0');
	int car = 0;
	while (len1 >= 0 || len2 >= 0){
		if ((len1 >= 0 && !isdigit(str1[len1])) || (len2 >= 0 && !isdigit(str2[len2])))
		{
			isvalid = false;
			return res;
		}
		int sum = 0;
		if (len1 >= 0 && len2 >= 0)
			sum = (str1[len1--] - '0') + (str2[len2--] - '0') + car;
		else if (len1 >= 0)
			sum = (str1[len1--] - '0') + car;
		else
			sum = (str2[len2--] - '0') + car;
		if (sum / 10 > 0){
			car = sum / 10;
			sum = sum % 10;
		}
		else{
			car = 0;
		}
		res[len--] = sum + '0';

	}
	if (car>0){
		res[len] = car + '0';
		return res;
	}
	else
		return &res[1];
}
string minusCore(string str1, string str2){
	if (str1.size() == 0)
		return str2;
	if (str2.size() == 0)
		return str1;
	if (str1.size() == 0 && str2.size() == 0)
	{
		isvalid = false;
		return str1;
	}
	int len1 = str1.size()-1;
	int len2 = str2.size()-1;
	int len = 0;
	if (len1 > len2)
		len = len1+1;
	else
		len = len2+1;
	string res(len, '0');
	len--;
	int car = 0;
	while (len1 >= 0 || len2 >= 0){
		if ((len1 >= 0 && !isdigit(str1[len1])) || (len2 >= 0 && !isdigit(str2[len2])))
		{
			isvalid = false;
			return res;
		}
		int minus = 0;
		if (len1 >= 0 && len2 >= 0){
			minus = str1[len1--] - str2[len2--] - car;
		}
		else if (len1 >= 0){
			minus = str1[len1--] - '0' - car;
		}
		if (minus >= 0){
			car = 0;
		}
		else if (minus < 0 && len1 > 0){
			minus = minus + 10;
			car = 1;
		}
		res[len--] = minus + '0';
	}
	return res;
}
string interface(string str1, string str2){
	string res;
	string str11, str22;
	string tmp;
	switch (str1[0]){
	case '+':{
		switch (str2[0])
		{
		case'+':
			str11 = &(str1[1]);
			str22 = &(str2[1]);
			tmp = addCore(str11, str22);
			break;
		case '-':{
			int len1 = str1.size();
			int len2 = str2.size();
			string tmp1 = &(str1[1]);
			string tmp2 = &(str2[1]);
			if ((len1 == len2) && (tmp1 < tmp2) || (len1 < len2)){
					res.push_back('-');
					str11 = &(str2[1]);
					str22 = &(str1[1]);
			}
			else{
				str11 = &(str1[1]);
				str22 = &(str2[1]);
			}
			tmp = minusCore(str11, str22);
			break;
		}
		default:
			str11 = &(str1[1]);
			str22 = &(str2[0]);
			tmp = addCore(str11, str22);
			break;
		}
		break;
	}
	case '-':{
		switch (str2[0])
		{
		case'-':
			str11 = &(str1[1]);
			str22 = &(str2[1]);
			res.push_back('-');
			tmp = addCore(str11, str22);
			break;
		case '+':{
			int len1 = str1.size()-1;
			int len2 = str2.size()-1;
			string tmp1 = &(str1[1]);
			string tmp2 = &(str2[1]);
			if (((len1 == len2) && (tmp1 > tmp2))||(len1>len2)){
					res.push_back('-');
					str11 = &(str1[1]);
					str22 = &(str2[1]);
				}
			else
			{
				str11 = &(str2[1]);
				str22 = &(str1[1]);	
			}
			tmp = minusCore(str11, str22);
			break;
		}
		default:
		{
			int len1 = str1.size() - 1;
			int len2 = str2.size();
			string tmp1 = &(str1[1]);
			string tmp2 = &(str2[0]);
			if (((len1 == len2) && (tmp1 > tmp2)) || (len1>len2)){
				res.push_back('-');
				str11 = &(str1[1]);
				str22 = &(str2[0]);
			}
			else
			{
				str11 = &(str2[0]);
				str22 = &(str1[1]);
			}
			tmp = minusCore(str11, str22);
			break;
		}
		}
		break;
	}
	default:
	{
		switch (str2[0])
		{
		case'+':
			str11 = &(str1[0]);
			str22 = &(str2[1]);
			tmp = addCore(str11, str22);
			break;
		case '-':{
			int len1 = str1.size();
			int len2 = str2.size()-1;
			string tmp1 = &(str1[0]);
			string tmp2 = &(str2[1]);
			if ((len1 == len2) && (tmp1 < tmp2) || (len1 < len2)){
				res.push_back('-');
				str11 = &(str2[1]);
				str22 = &(str1[0]);
			}
			else{
				str11 = &(str1[0]);
				str22 = &(str2[1]);
			}
			tmp = minusCore(str11, str22);
			break;
		}
		default:
			str11 = &(str1[0]);
			str22 = &(str2[0]);
			tmp = addCore(str11, str22);
			break;
		}
		break;
	}
	}
	int i = 0;
	while ((i < tmp.size() - 1) && tmp[i] == '0')
		i++;
	for (; i < tmp.size(); ++i){
			res.push_back(tmp[i]);
	}
		return res;
}
int main(){
	string str1;
	string str2;
	while (cin >> str1 >> str2){
		isvalid = true;
		string res = interface(str1, str2);
		if (isvalid)
			cout << res << endl;
		else
			cout << "invalid number" << endl;
	}
	return 0;
}