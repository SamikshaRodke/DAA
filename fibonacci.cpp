#include <iostream>
using namespace std;

void ittr(int n)                         //itterative call
{
int prev=0;
int curr=1;
int next;
for(int i=0;i<n;i++)                    //add till next=n
{
cout<<prev;
next=prev+curr;
prev=curr;
curr=next;
}
cout<<endl;
}

void rec(int n,int a=0,int b=1)        //recursive call
{

if(n>0)
{
cout<<a;
rec(n-1,b,a+b);                       //call till n>0

}


}

int main()
{
int no,ch;
cout<<"enter a index till you want fibonacci series : \t";
cin>>no;
cout<<"enter choice\t\t 1. non recursive\t\t 2. recursive\n";
cin>>ch;
if(ch==1)
{
cout<<"non-recursive series : ";
ittr(no);
}
else if(ch==2){
cout<<"recursive series : ";
rec(no);
}
return 0;

}










// Time Complexity: O(n) - The iterative approach has a linear time complexity because it calculates Fibonacci numbers from 2 to n sequentially.
// Space Complexity: O(1) - The iterative approach uses a constant amount of space, as it only stores two variables (a and b) for the calculation, regardless of the input value.
// Recursive:

// Time Complexity: O(2^n) - The recursive approach has exponential time complexity because it recalculates Fibonacci numbers for smaller values multiple times, leading to a large number of redundant calculations.
// Space Complexity: O(n) - The recursive approach has linear space complexity because it builds a call stack of size 'n' due to recursive function calls.\
