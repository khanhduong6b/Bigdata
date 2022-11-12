#include"header.h"
void MakeNullList(BigNum &L){
    L.lastPosition=0;
}
void EqualLength(string &a,string &b){
    
    while (a.length()>b.length()){
        b='0'+b;
    }
    while (a.length()<b.length()){
        a='0'+a;
    }
}
void Convert(string a, BigNum &b){
    b.num.assign(b.lastPosition,0);
    for (int i=0;i<a.length();i++)
        {
            int temp=(int) a[i] -48; //ASCII
            b.num.push_back(temp);
            b.lastPosition++;          
        }
}
BigNum operator+(BigNum a,BigNum b){
    BigNum sum;    
    sum.lastPosition=a.lastPosition+1;
    sum.num.assign(sum.lastPosition,0);
    int aLength=a.lastPosition-1;
    int bLength=b.lastPosition-1;
    int sumLength=sum.lastPosition-1;
    int temp=0;
    //cout<<aLength<<" "<<bLength<<" "<<sumLength<<"\n";
    do { 
        if (aLength>=0)
        sum.num[sumLength]=a.num[aLength--]+b.num[bLength--]+temp;
        else sum.num[sumLength]=temp;
        if (sum.num[sumLength]>=10) {
            sum.num[sumLength]%=10;
            temp=1;
        } else temp=0;
        sumLength--;
    } while (sumLength>=0);
    return sum;
}
BigNum operator* (BigNum a, BigNum b)
{
    BigNum product;
    int len=a.lastPosition+b.lastPosition+1;   
    vector<vector<int>> temp(b.lastPosition); 
    // Nhan tung hang
    int index=0;
    for (int i=b.lastPosition-1;i>=0;i--){
        int t=0;
        while (t<index){
            temp[index].push_back(0);
            t++;
        }     
        int nho=0,so=0;
        for (int j=a.lastPosition-1;j>=0;j--)
        {
            so=a.num[j]*b.num[i]+nho;
            temp[index].push_back(so%10);
            nho=so/10;
        }
        if(nho>0) temp[index].push_back(nho);
        while (temp[index].size()<len)
            temp[index].push_back(0);
            reverse(temp[index].begin(),temp[index].end());
        index++;
    }
    // Cong cac hang lai voi nhau
    int nho=0;
    string ans="";
    for (int j=temp[0].size()-1;j>=0;j--)
    {
        int so=nho;
        for (int i=0;i<temp.size();i++)
        so+=temp[i][j];
        ans=char(so%10+'0')+ans;
        nho=so/10;
    }
    if (nho>0) ans=char(nho+'0') +ans;
    while (ans[0]=='0') ans.erase(ans.begin());
    //cout<<ans<<"\n";
    product.lastPosition=ans.length();
    Convert(ans,product);
    return product;
}
