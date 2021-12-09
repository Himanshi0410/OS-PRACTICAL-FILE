#include<iostream>
using namespace std;
 
void fW_T(int p[], int n,
                          int bt[], int wt[])
{
    
    wt[0] = 0;
 
    
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}
 

void fTA_Time( int p[], int n,
                  int bt[], int wt[], int tat[])
{
   
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 

void fa_T( int p[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
   
    fW_T(p, n, bt, wt);
 
   
    fTA_Time(p, n, bt, wt, tat);
 

    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";
 
    
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
 

int main()
{
  
    int p[] = { 1, 2, 3};
    int n = sizeof p / sizeof p[0];
 
    
    int  b_time[] = {10, 5, 8};
 
    fa_T(p, n,  b_time);
    return 0;
}
