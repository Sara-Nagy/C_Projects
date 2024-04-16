
#ifndef BANK_DATA_BASE_H_INCLUDED
#define BANK_DATA_BASE_H_INCLUDED
typedef struct client  ///store the data of the clients
{
    int id;
    char name[50];
    double money;
}clients;


void create_data(void);
/**
name:create_data.
receive:nothing.
return:nothing.
job:create new data for a client.
**/
void delete_data(int id_c);
/**
name:edit data.
receive:the id of the client .
return:nothing.
job:edit the data of a client.
**/
void edit_data(int id_c);
/**
name:edit_data.
receive:the id of the client.
return:nothing.
job:edit the data of a client.
**/
void transfer_money(int id_d,int id_c,double money);
/**
name:transfer money.
receive:1-the id of the client wanted to transfer money to him.
        2-the id of the client wanted to transfer money from him.
        3-the value of money wanted to be transfered.
return:nothing.
job:transfer money from a client to anther.
**/
void print_data(int id_c);
/**
name:print_data.
receive:the id of the client.
return:nothig.
job:print the data of a client.
**/

#endif // BANK_DATA_BASE_H_INCLUDED
