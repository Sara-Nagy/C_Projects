
#ifndef clinic
#define clinic
#define number_of_client 50 // can be changed
#define number_of_slots 5 // can be changed
typedef struct client
{
    char name[60];
	int age;
	char gender[15];
	int id;
	char reserve[15];
	int num;
}client;



void Add_New_Client();
/*
name:Add_New_Client.
job:create information to new client.
get:nothing.
return:nothing.
*/
void Edit_Client(int id);
/*
name:Edit_Client.
job:change information of a client.
get:int number(the id of the client).
return:nothing.
*/
void Reserve_Slot(int id);
/*
name: Reserve_slot.
job:reserve a desired slot for a client.
get:int number(the id of the client).
return:nothing.
*/
void Cancel_Slot(int id);
/*
name: Cancel_Slot.
job:cancel the slot for a client.
get:int number(the id of the client).
return:nothing.
*/
void Print_Information_Client(int id);
/*
name:Print_Information_Client.
job:show the information of a client.
get:int number(the id of the client).
return:nothing.
*/
void Show_Reservation();
/*
name:Show_Reservation.
job:show all reservation of the day.
get:nothing.
return:nothing.
*/


#endif // clinic
