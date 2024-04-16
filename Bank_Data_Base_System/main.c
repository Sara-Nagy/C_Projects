#include <stdio.h>
#include <stdlib.h>
#include "Bank_data_base.h"
#define max 100
int num;
clients arr[max];

int main()

{
    int id,n,i,id_;
    double money;
    FILE * f_data;
    if((f_data=fopen("data.txt","rb"))!=NULL)
    {
        while(!feof(f_data))
        {
            if(fread(&arr[num].id,sizeof(arr[num].id),1,f_data)==0)break;
            fread(&arr[num].name,sizeof(arr[num].name),1,f_data);
            fread(&arr[num].money,sizeof(arr[num].money),1,f_data);
            num++;
        }
    }
    fclose(f_data);
    while(1)
    {
        printf("if you want to create new data enter [1]:\n");
        printf("if you want to delete  data enter [2]:\n");
        printf("if you want to edit data enter [3]:\n");
        printf("if you want to transfer money from client to anther enter [4]:\n");
        printf("if you want to print  data enter [5]:\n");
        printf("if you want to exit enter [6]:\n");
        printf("please enter your choice:\n");
        fflush(stdin);
        scanf("%d",&n);
        fflush(stdin);
        if(n>6)
        {
            printf("wrong choice,please enter right choice:\n");
            fflush(stdin);
            scanf("%d",&n);
            fflush(stdin);
        }

        switch(n)
        {
        case 1: if(num>max)
             {
            printf("there is no place to store new data");
            break;
             }
            create_data();
            break;
        case 2:
            printf("please enter the id of the client:");
            fflush(stdin);
            scanf("%d",&id);
            fflush(stdin);
            delete_data(id);
            break;
        case 3:
            printf("please enter the id of the client:");
            fflush(stdin);
            scanf("%d",&id);
            fflush(stdin);
            edit_data(id);
            break;

        case 4:
            printf("please enter the id of the client wanted to transfer to him : \n");
            fflush(stdin);
            scanf("%d",&id);
            fflush(stdin);
            printf("please enter the id of the client wanted to transfer from him : %\n");
            fflush(stdin);
            scanf("%d",&id_);
            fflush(stdin);
            printf("please enter the money:");
            fflush(stdin);
            scanf("%lf",&money);
            fflush(stdin);
            if(money<0)
            {
                printf("the value of money must be positive number");
                break;
            }

            transfer_money(id,id_,money);
            break;


        case 5:
            printf("please enter the id of the client:");
            fflush(stdin);
            scanf("%d",&id);
            fflush(stdin);
            print_data(id);
            break;

        case 6:
            exit(0);
            break;


        }


    f_data=fopen("data.txt","w");
    for(i=0; i<num; i++)
    {
       fwrite(&arr[i].id,sizeof(arr[i].id),1,f_data);
       fwrite(&arr[i].name,sizeof(arr[i].name),1,f_data);
       fwrite(&arr[i].money,sizeof(arr[i].money),1,f_data);

    }
    fclose(f_data);

    }

    return 0;
}

