#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

 vector<int> MultiPrime(int p){
	 vector<int> vec;
	 if (p <= 1){
		 vec.push_back(1);
		 return vec;

	 }
	int aPrimeList[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
		53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
		139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227,
		229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
		331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
		439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557,
		563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
		661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787,
		797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,
		919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009 };
	int nListNum = sizeof(aPrimeList) / sizeof(unsigned);
	for (size_t i = 0; i < nListNum&&p>1; )
	{
		if (p >= aPrimeList[i] && (p % aPrimeList[i]) == 0)
		{
			p = p / aPrimeList[i];
			vec.push_back(aPrimeList[i]);
			continue;
		}
		i++;
	}
	return vec;
}
 list<int> divide(const int& a){
	 int k = a;
	 list<int> res;
	 while (k > 0){
		 int s = k % 10;
		 res.push_front(s);
		 k = k / 10;
	 }
	 return res;
 }
 void print(vector<int> vec){
	 vector<vector<string> > digits = { { " - ", "| |", "   ", "| |", " - " },
	 { "   ", "  |", "   ", "  |", "   " },
	 { " - ", "  |", " - ", "|  ", " - " },
	 { " - ", "  |", " - ", "  |", " - " },
	 { "   ", "| |", " - ", "  |", "   " },
	 { " - ", "|  ", " - ", "  |", " - " },
	 { " - ", "|  ", " - ", "| |", " - " },
	 { " - ", "  |", "   ", "  |", "   " },
	 { " - ", "| |", " - ", "| |", " - " },
	 { " - ", "| |", " - ", "  |", " - " }
	 };
	 vector<string> mul = { " ", " ", "*", " ", " " };
	 for (int i = 0; i < 5; i++){
		 for (int j = 0; j < vec.size(); j++){
			 list<int> slist = divide(vec[j]);
			 for (list<int>::iterator iter = slist.begin(); iter != slist.end(); ++iter){
				 cout << digits[*iter][i];
			 }
			 if (j + 1 != vec.size())
			 cout << mul[i];
		 }
		 cout << endl;
	 }
 }
 int main(){
	 int n;
	 while (cin >> n){
		 vector<int> res = MultiPrime(n);
		 print(res);
		 
	 }
	 //system("pause");
	 return 0;
 }
