#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Item                                                                 //////////////////////////
{
double weight;
double profit;
double ratio;
};

bool compareItems(const Item& a, const Item& b) {                           //////////////////////////
    return a.ratio > b.ratio;                                               ///////////////////////////
}

 double fractional(Item items[],int n,int sz)                                           
 {
   
   sort(items,items+n,compareItems);                                         /////////////////////////
   double total_val=0.0;
   double curr_weight=0.0;
   if(sz!=0)
   {
     for (int i = 0; i < n; i++) {
        if (curr_weight + items[i].weight <= sz) {                          ///////////////////////                        
            // Add the entire item to the knapsack
            total_val += items[i].profit;
            curr_weight += items[i].weight;
   }
 
 else {
            // Add a fraction of the item to fill the knapsack
            double remainingCapacity = sz - curr_weight;                            /////////////////////////                 
            total_val += (remainingCapacity / items[i].weight) * items[i].profit;
            break; // Knapsack is full
        }
   }
 }
 return total_val;
 }


int main()
{
    int n,size;
    cout<<"enter number of items"<<endl;
    cin>>n;
    cout<<"enter size of knapsack"<<endl;
    cin>>size;
    Item items[n];

    cout<<"enter the weights of elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>items[i].weight; 
   }
    cout<<"enter the profits of elements"<<endl;
    for(int j=0;j<n;j++)
    {
        cin>>items[j].profit;
    }

    cout<<"The profit to weight ratio is"<<endl;
    for(int k=0;k<n;k++)
    {
        items[k].ratio=items[k].profit/items[k].weight;
    }
    for(int j=0;j<n;j++)
    {
        cout<<items[j].ratio<<"\t"<<endl;
    }

    double maxProfit=fractional(items,n,size);
  
    cout << "The maximum value that can be obtained is: " << maxProfit << endl;

}

//o(nlogn)