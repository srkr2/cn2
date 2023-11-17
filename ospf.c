#include<stdio.h>

void main(){
    int graph[50][50],V,i,j,src,flag[50],last[50],dist[50];
    printf("enter no.of vertices: ");
    scanf("%d",&V);
    printf("enter the cost matrix:\n");
    for(i=0;i<V;i++){
        for(j = 0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter source router: ");
    scanf("%d",&src);

    for(i=0;i<V;i++){
        flag[i] = 0;
        last[i] = src;
        dist[i] = graph[src][i];
    }
    flag[src] = 1;

    for(i=0;i<V;i++){
        int v;
        int min = 1000;
        for(int w = 0;w<V;w++){
            if(!flag[w] && dist[w]<min){
                min = dist[w];
                v = w;
            }
        }
        flag[v] = 1;
        for(j = 0;j<V;j++){
            if(!flag[j] && graph[v][j] + dist[v] < dist[j] ){
                dist[j] = graph[v][j]+dist[v];
                last[j] = v;
            }
        }
    }
    for(i=0;i<V;i++){
        printf("%d ==> %d : path taken: %d",src,i,i);
        int w= i;
        while(w != src){
            printf("<-- %d",last[w]);
            w = last[w];
        }
        printf("\nshortest path cost : %d\n",dist[i]);
    }
}