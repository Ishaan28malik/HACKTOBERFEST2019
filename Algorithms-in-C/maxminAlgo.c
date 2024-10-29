#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n,m;
    printf("Enter the number of virtual Machines  and Number of Tasks: ");
    scanf("%d %d",&n,&m);

    int a[m][n];
    bool visited[m];
    for(int i=0;i<m;i++){
        printf("Enter Times for Task %d\n",i+1);
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            
        }
        visited[i]=false;
    }
    int cnt=0;
    int max_time[n];
    for(int i=0;i<n;i++){
        max_time[i]=0;
    }
    while(cnt < m){
        
        int machine_no=-1;
        int task_no=-1;
        int check_time[m];
        int check_machine[m];
        for(int i=0;i<m;i++){
            if(visited[i]==true){
                check_time[i]=0;
                continue;
            }
            int min=10000;
            for(int j=0;j<n;j++){
                if(min> a[i][j]){
                    printf("Min: %d, a[i][j]: %d\n", min, a[i][j]);
                    min=a[i][j];
                    check_machine[i]=j;
                }
            }
            check_time[i]=min;
        }
        int min=0;
        for(int i=0;i<m;i++){
            if(min< check_time[i]){
                min=check_time[i];
                machine_no=check_machine[i];
                task_no=i;
            }
        }
        visited[task_no]=true;
        max_time[machine_no]=min;
        cnt++;
        printf("Task %d is assigned to Machine %d\n and time is %d\n", task_no+1,machine_no+1,min);
        
        for(int i=0;i<m;i++){
            if(visited[i]==true)continue;
            a[i][machine_no]+=min;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
            if(ans<max_time[i]){
                ans=max_time[i];
            }
    }
    printf("The maximum time required is %d\n",ans);

}