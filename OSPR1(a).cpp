#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
int x,y;
x=int fork();
cout<<"\n x = "<<x;
y=fork();
cout<<"\n y = "<<y;
cout<<"\n HELLO"<<endl;
return 0;
}
