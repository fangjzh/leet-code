#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
int a[3]={0},b[3]={0},c[3]={0},d[3]={0};
int i=0,j=0,k=0,l=0;
a[i++]++;
b[++j]++;
++c[k++];
++d[++l];

cout <<"a[i++]++ = ?" << endl;
cout << "a[0]:" << a[0] << endl;
cout << "a[1]:" << a[1] << endl;
cout << "a[2]:" << a[2] << endl;
cout <<"b[++j]++ = ?" << endl;
cout << "b[0]:" << b[0] << endl;
cout << "b[1]:" << b[1] << endl;
cout << "b[2]:" << b[2] << endl;
cout <<"++c[k++] = ?" << endl;
cout << "c[0]:" << c[0] << endl;
cout << "c[1]:" << c[1] << endl;
cout << "c[2]:" << c[2] << endl;
cout <<"++d[++l] = ?" << endl;
cout << "d[0]:" << d[0] << endl;
cout << "d[1]:" << d[1] << endl;
cout << "d[2]:" << d[2] << endl;
}
