#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

bool isdivide(int c){
    int tag = 0;
    int a = c;
    for(int i = 0;i < 8;i++){
        if(((a & 1)== 0)&&(tag == 1)){
            return false;
        }
        else if(((a&1) == 1)&&(tag==0)){
            tag=1;
            a=a>>1;//注意这里要进行赋值
        }
        else{
            a=a>>1;
        }
    }
    return true;    
}

bool ismask(int a,int b,int c,int d){
    if(!((a>=0&&a<=255)&&(b>=0&&b<=255)&&(c>=0&&c<=255)&&(d>=0&&d<=255)))
        return false;
	if(a==255&&b==255&&c==255&&d==255)
        return false;
    if(a!=255){
        if(isdivide(a)&&b==0&&c==0&&d==0)
            return true;
        else return false;
    }
    else if(b!=255){
        if(isdivide(b)&&c==0&&d==0)
            return true;
        else
            return false;
    }
    else if(c!=255){
        if(isdivide(c)&&d==0)
            return true;
        else
            return false;
    }
    else if(d!=255){
        if(isdivide(d))
            return true;
        else
            return false;
    }
    return true;
}
int analysis(string str,vector<int>& vec){
    if(str.size()<=0){
       vec[5]++;
        return 0;
    }
    vector<string> svec;
    for(int i = 0;i < str.size();i++){
         string str1="";
        if(str[i]== '.'||str[i]=='~'){
            break;
        }
        while(str[i]!='.'&&str[i]!='~'&&i<str.size()){
            str1+=str[i];
            i++;
        }
        svec.push_back(str1);
    }
    if(svec.size() != 8) {
        vec[5]++;
        return 0;
    }
    vector<int> ivec;
    for(int i =0;i< 8;i++){
       int tmp = atoi(svec[i].c_str());
        ivec.push_back(tmp);
    }
	 
    if(ismask(ivec[4],ivec[5],ivec[6],ivec[7])){
        if(ivec[0]>=1 && ivec[0]<= 126){
            vec[0]++;
			/*for(int i =0;i< 8;i++){
					cout<< ivec[i]<<"\t";
			
    }
			cout<<endl;*/
            if(ivec[0] == 10)
                vec[6]++;
			return 1;
        }
        else if(ivec[0]>=128&&ivec[0]<=191){
            vec[1]++;
			
            if(ivec[0]==172&&ivec[1]>=16&&ivec[1]<=31)
                vec[6]++;
			return 1;
        }
        else if(ivec[0]>=192&&ivec[0]<=223){
            vec[2]++;
            if(ivec[0]==192&&ivec[1]==168)
                vec[6]++;
			return 1;
        }
        else if(ivec[0]>=224&&ivec[0]<=239){
            vec[3]++;
			return 1;
		}
        else if(ivec[0]>=240&&ivec[0]<=255){
            vec[4]++;
			return 1;
		}
        else{
            vec[5]++;
			return 1;
		}
    }
    else{
        vec[5]++;
		return 0;
	}
}
int main(){
	//cout<<isdivide(149)<<endl;
    string str;
    vector<int> vec;
    for(int i = 0;i<=6;i++){
        vec.push_back(0);
    }
	int i = 0;
    while(cin>>str){
		i++;
		analysis(str,vec); 
    }
    for(int i = 0;i<=6;i++){
        cout<<vec[i]<<" ";
    }
	cout<<i<<endl;
	system("pause");
    return 0;
}