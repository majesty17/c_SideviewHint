#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

    int border_size;//=5;
    int color_size;//=5;
    int gap_size;//=border_size-color_size;

    //step 1: read game data from file
    char *file_name="c:\\game1.txt";
    FILE *fd=fopen(file_name,"r");
    if(!fd){
        printf("打开文件失败！\n");
        return -1;
    }
    else{
        printf("打开文件成功。\n");
    }

    char buffer[128];
    fscanf(fd,"%s",buffer);
    border_size=buffer[0]-'0';
    color_size=buffer[1]-'0';
    gap_size=border_size-color_size;


    char** mat=(char**)malloc(sizeof(char*)*border_size);
    char** limit=(char**)malloc(sizeof(char*)*4);
    int i=0;
    for(i=0;i<border_size;i++){
        mat[i]=(char*)malloc(border_size*sizeof(char));
        memset(mat[i],'0',sizeof(char)*border_size);
    }

    for(i=0;i<4;i++){
        limit[i]=(char*)malloc(sizeof(char)*border_size);
        fscanf(fd,"%s",limit[i]);
    }
    fclose(fd);


    //step 2:计算
    printGame(border_size,color_size,limit,mat);




    //step 99: 释放
    for(i=0;i<border_size;i++){
        free(mat[i]);//=(int*)malloc(sizeof(int)*border_size);
    }
    free(mat);//=(int**)malloc(sizeof(int*)*border_size);
    return 0;
}

void printGame(int bs,int cs,char **limit,char **mat){
    int i,j;
    printf("====== Game detail ======\n");
    printf("Board Size: %d\n",bs);
    printf("Color Size: %d\n",cs);
    printf(" %s\n",limit[0]);
    for(i=0;i<bs;i++){
        printf("%c",limit[2][i]);
        printf("%s",mat[i]);
        printf("%c\n",limit[3][i]);
    }
    printf(" %s\n",limit[1]);
    printf("====== Game end ======\n");
}

int validGame(int bs,int cs,char **limit,char **mat){
    int i,j;
    //line valid


    //limit valid
    //0
    for(i=0;i<bs;i++){
        if(mat[0][i]=='_'){
            continue;
        }

    }
    return 0;
}



