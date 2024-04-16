
#include <stdio.h>
#include "Bank_data_base.h"
#define max 100
extern clients arr[max];
extern  int num;

void create_data(void)
{
    int i;
    clients new_client;
    printf("please enter the id of the client[%d]:",num+1);
    fflush(stdin);
    scanf("%d",&new_client.id);
    fflush(stdin);

    for(i=0; i<num; i++)
    {
        if(arr[i].id==new_client.id)
        {
            printf("this id is already reserved:\n");
            fflush(stdin);
            scanf("%d",&new_client.id);
            fflush(stdin);
        }
    }

    printf("please enter the name of the client[%d]:",num+1);
    fflush(stdin);
    gets(new_client.name);
    printf("please enter the money of the client[%d]:",num+1);
    fflush(stdin);
    scanf("%lf",&new_client.money);
    fflush(stdin);
    printf("\n");

    if(new_client.money<=0)
    {
        printf("the money must be positive number:\n");
        fflush(stdin);
        scanf("%lf",&new_client.money);
        fflush(stdin);
    }

    arr[num]=new_client;
    num++;
}
void delete_data(int id_c)
{
    int i,j;
    for(i=0; i<num-1; i++)
    {
        if(arr[i].id==id_c)
        {
            j=i;
            break;
        }
    }
    for(i=j; i<num-1; i++)
    {
        arr[i]=arr[i+1];
    }
    num--;

}
void edit_data(int id_c)
{
    int i,j;
    for(i=0; i<num; i++)
    {
        j=0;
        if(arr[i].id==id_c)
        {

            printf("please enter the new id:");
            fflush(stdin);
            scanf("%d",&arr[i].id);
            fflush(stdin);
            printf("please enter the new name:");
            fflush(stdin);
            gets(arr[i].name);
            fflush(stdin);
            printf("please enter the new money:");
            fflush(stdin);
            scanf("%lf",&arr[i].money);
            fflush(stdin);
            printf("\n");
            j=1;
            break;

        }

    }
    if(j==0)
        printf("wrong id\n");

}
void print_data(int id_c)
{
    int i,j;
    for(i=0; i<num; i++)
    {
        j=0;
        if(arr[i].id==id_c)
        {
            printf("the id of the client is:%d\n",arr[i].id);
            printf("the name of the client is:%s\n",arr[i].name);
            printf("the money of the client is:%lf\n",arr[i].money);
            printf("\n");
            j=1;
            break;
        }
    }
    if(j==0)
        printf("wrong id\n");
}

void transfer_money(int id_d,int id_c,double money)
{
    int i,j;

    for(i=0; i<num; i++)
    {
        if(arr[i].id==id_d)
            break;
    }
    for(j=0; j<num; j++)
    {
        if(arr[j].id==id_c)
            break;
    }
    if(money>arr[j].money)
        printf("the value of money greater than the value of money of the client wanted to transfer from him\n");
    else
    {
        arr[i].money=(arr[i].money)+money;
        arr[j].money=(arr[j].money)-money;
    }

}
