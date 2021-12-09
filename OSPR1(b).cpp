#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;
int main(){
int x;
x=fork();
if(x==0){
execlp("Users/hemav/Desktop/OS","OSPR2",NULL);
}
else{
wait(NULL);
cout<<"Child completed\n";
}
return(0);
}

