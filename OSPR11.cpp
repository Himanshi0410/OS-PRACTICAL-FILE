#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n,
int bt[], int wt[],int at[])
{

wt[0] = 0;
int ct=0+bt[0];

for (int i = 1; i < n ; i++ ) {
wt[i] = ct-at[i] ;
ct=ct+bt[i]; }
}

void findTurnAroundTime( int processes[], int n,
int bt[], int wt[], int tat[],int at[])
{
int ct=0;

for (int i = 0; i < n ; i++) {
ct=ct+bt[i];
tat[i] =ct -at[i];
}
}

void findavgTime( int processes[], int n, int bt[],int at[])
{
int wt[n], tat[n], total_wt = 0, total_tat = 0,t=0;

for(int i=0;i<n+1;i++)
{
for(int j=0;j<n-1;j++)
{
if(bt[j]>bt[j+1])
{
t=bt[j];
bt[j]=bt[j+1];
bt[j+1]=t;
t=processes[j];
processes[j]=processes[j+1];
processes[j+1]=t;
t=at[j];
at[j]=at[j+1];
at[j+1]=t;
}
}
for(int j=0;j<n-1;j++)
{
if(j!=0&&at[j]==0&&at[j-1]!=0)
{
t=bt[j];
bt[j]=bt[j-1];
bt[j-1]=t;
t=processes[j];
processes[j]=processes[j-1];
processes[j-1]=t;
t=at[j];
at[j]=at[j-1];
at[j-1]=t;
}
}
}
//Function to find waiting time of all processes
findWaitingTime(processes, n, bt, wt,at);
//Function to find turn around time for all processes
findTurnAroundTime(processes, n, bt, wt, tat,at);
//Display processes along with all details
cout << "Processes "<<"Arrival time"<< " Burst time "
<< " Waiting time " << " Turn around time\n";
// Calculate total waiting time and total turn
// around time
for (int i=0; i<n; i++)
{
total_wt = total_wt + wt[i];
total_tat = total_tat + tat[i];
cout << " " << processes[i] << "\t\t"<<at[i]<<"\t\t" << bt[i] <<"\t "
<< wt[i] <<"\t\t " << tat[i] <<endl;
}
cout << "Average waiting time = "
<< (float)total_wt / (float)n;
cout << "\nAverage turn around time = "
<< (float)total_tat / (float)n;
}

int main()
{
int n;
cout<<"enter no of process u want :-";
cin>>n;
int processes[n];
int burst_time[n];
int arrival_time[n];
for(int i=0;i<n;i++){
processes[i]=i+1; //process id's
cout<<"Enter Burst_time of process no "<<i+1<<" :"; //burst_time
cin>>burst_time[i];
cout<<"Enter Arrival_time of process no"<<i+1<<" :" ; //arrival_time
cin>>arrival_time[i];
}
cout<<"input :- \n";
cout << "Processes "<<"Arrival time"<< " Burst time \n";
for (int i=0; i<n; i++)
{
cout << " " << processes[i] << "\t\t"<<arrival_time[i]<<"\t\t" << burst_time[i] <<"\t "
<<endl;
}
findavgTime(processes, n, burst_time,arrival_time);
return 0;
}
