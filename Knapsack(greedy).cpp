
#include <iostream>

using namespace std;

struct items{
    int index;
    double profit;
    double weight;
    double pw ;
};

void sort(struct items a[],int n){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i].pw > a[j].pw){
                
                double temp = a[i].pw;
                a[i].pw = a[j].pw;
                a[j].pw = temp;
                
            }
        }
    }
    
    cout<<"Sorted List";
   for(int i=0 ; i< n ; i++){
       cout<<"PW ratio : "<< a[i].pw<<"\t";
    }
    
}

void knapsack(struct items a[],int w,int n){
    double total_profit = 0;
    int x[n];
    double wgt = (double)w;
    
    sort(a,n);
    
    for(int i=0 ; i<n; i++){
        if(a[i].weight<= wgt){
            x[i] = 1.0;
            total_profit += a[i].profit;
            wgt -= a[i].weight;
        }
        else{
            x[i] = wgt/a[i].weight;
            total_profit += x[i]*a[i].profit;
            break;
        }
    }
    cout<<"Total Profit: "<<total_profit;
}

int main()
{
    int n,w;
    cout<<"Enter the number of items";
    cin>>n;
    cout<<"Enter the weight of knapsack";
    cin>>w;
    
    struct items a[n];
    for(int i=0 ; i< n ; i++){
        cout<<"Enter Profit for"<<i+1;
        cin>>a[i].profit;
        cout<<"Enter weight for"<<i+1;
        cin>>a[i].weight;
        a[i].pw = a[i].profit/a[i].weight;
    }
    
    
    
    knapsack(a,w,n);
    
    return 0;
}
