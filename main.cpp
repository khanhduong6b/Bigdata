#include"source.cpp"
int main(){
    string a,b;
    cin>>a>>b;
    EqualLength(a,b);
    BigNum aBigNum,bBigNum;
    //Khoi tao
    MakeNullList(aBigNum);
    MakeNullList(bBigNum);
    //Chuyen doi kieu du lieu string sang Danh sach dac
    Convert(a,aBigNum);
    Convert(b,bBigNum);
    //Xuat 2 so sau khi convert
    // cout<<"\n"<<aBigNum.lastPosition;
    // for (int i=0;i<aBigNum.lastPosition;i++){
    //     cout<<aBigNum.num[i];
    // }
    // cout<<"\n"<<bBigNum.lastPosition;
    // for (int i=0;i<bBigNum.lastPosition;i++){
    //     cout<<bBigNum.num[i];
    // }
    BigNum sum=aBigNum*bBigNum;
    int i;
    for (i=0;i<sum.lastPosition;i++){
        if (sum.num[i]!=0)break;
        
    }
    for (int j=i;j<sum.lastPosition;j++){
        cout<<sum.num[j];
    }
    
    system("pause");
    return 0;
}