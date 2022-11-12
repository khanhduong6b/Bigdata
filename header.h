#include <algorithm>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
struct BigNum{
    vector<int> num;
    int lastPosition; 
};
void EqualLength(string &a,string &b);
void MakeNullList(BigNum &L);
void Convert(string a, BigNum &b);
//Phep Cong
BigNum operator+(BigNum a,BigNum b);
//Phep Nhan
BigNum operator* (BigNum a, BigNum b);
void fix(vector<int> &number);