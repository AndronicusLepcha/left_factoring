#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int arr[100];
int betarr[100];
int idarr=0;
int min=0;
char alpha[100];
int noofbeta=0;
char *gama;

void findBeta(int c,int index,int n,char production[n][100]){
    //printf(production[0]);
    int bid=0;
    for(int i=0;i<c;i++){
        if(index == strlen(production[arr[i]])){ //the production which has no beta will be discarded here only
           // printf("\nno Beta in production --> %s\n",production[arr[i]]);
        }else{
            //printf("\nyes beta in %s\n",production[i]);
            noofbeta++;
            betarr[bid]=i;
        }
    }
    if(noofbeta == 1){
        //printf("\nOnly one ......\n");
        char buff[20];
        //int i=index;
        //printf("index is pointing at %d",i);
        //printf("%d is index\n",i);
        int b=0;
        //printf("\nproduction with beta is at %d \n",betarr[0]);
        //printf("\nproduction with beta is  %s \n",production[betarr[0]]);
        //printf("%d",strlen(production[betarr[0]]));
        while(index != strlen(production[betarr[0]])){
            buff[b]=production[betarr[0]][index];
            b++;
            index=index+1;
        }
        index=0;
        b++;
        buff[b]='\0';
        printf("Beta is %s \n ",buff);
        
    }else{
        //for mutliple beta
        int id=0;
        int bin=index;
        char mbeta[noofbeta][30];
        for(int i=0;i<noofbeta;i++){
            index=bin;
            // printf("curreent prod %s\n",production[betarr[i]]);
            // printf("My index is %d\n",index);
            // printf("pro length %d\n",strlen(production[betarr[i]]));
            
            while(index != strlen(production[betarr[i]])){
                mbeta[i][id]=production[betarr[i]][index];
                id++;
                index=index+1;
            }
            //id++;
            //printf("id is at %d\n",id);
            mbeta[i][id]='\0';
            //printf("%s\n",mbeta[i]);
            id=0;
        }
        index=0;
        for(int i=0;i<noofbeta;i++){
            printf("\nbeta %d %s\n",i,mbeta[i]);
        }
        //first answer
        printf("S->%sS'|%s\n",alpha,gama);
        printf("S'->");
        for(int i=0;i<noofbeta;i++){
           printf("%s|",mbeta[i]);
        }
        printf("\n");
        

        
    }
}

void findalpha(int c,int n,char production[n][100]){ //this function will find the alpha
    int itr=0; 
    int i;
    for(int i=0;i<c;i++){   //c is the total no of production whose indx are in arr
        printf("%d\t",arr[i]);
    }
    // printf("%c\t",production[arr[0]][]);
    int id=0;
    i=0;
    while(i != min && production[arr[0]][id] == production[arr[1]][id] && production[arr[0]][id] == production[arr[2]][id] ){ //since arr starts with 0 index so any prodution with common prefix will get retrieved
        alpha[id]=production[arr[0]][id];
        i++;  
        id++; //this will keep track of till where was the common prefix 
    }
    id++;
    alpha[id]='\0';
    printf("\nAlpha is %s\n",alpha);

    findBeta(c,id-1,n,production); //find beta
}
int findGamma(int n,char production[n][100]){
        char common=production[0][0]; // taking first production first letter as refere 
        min=strlen(production[0]); //initially min length of the production is 1st production only
        
        int count=0;
        for(int i=0;i<n;i++){ //n is the total no of production entered by the user
            if(production[i][0] == common){ //if nay production has in common with any other the take that or add to array
                //char *temp=production[i];
                arr[idarr]=i;   //the index will be added to the array for the future refernces
                idarr++;
                count++;       //total no of production with common prefix
                if(strlen(production[i])<=min){ //if any production is found as min in length that will be updated
                    min=strlen(production[i]);
                }
        }
        else{       //else other are counted as gamma 
               // printf("You are Gamma\n");  
                gama=production[i];       
                printf("gama%s\n",gama);
            }
    }
    printf("min range is %d\n",min); 
    printf("count is %d\n",count);
    return count;        
}

void main(){
    int n;
    printf("Enter the number of production you want to enter ");
    scanf("%d",&n);

    char production[n][100]; //decleration of 2D array pointers

    for(int i=0;i<n; i++){
        scanf("%s",production[i]);
    }

    int c=findGamma(n,production);

    if(c>1){
        findalpha(c,n,production);
    }else{
        printf("no common prefix");
    } 
}