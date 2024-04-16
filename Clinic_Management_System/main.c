#include<stdio.h>
#include"clinic_system.h"
client arr[number_of_client];
int counter;
int reservation[number_of_slots]={0};
/*
2 to 2:30 pm  is reservation[0]
2:30 to 3 pm  is reservation[1]
3 to 3:30 pm  is reservation[2]
4 to 4:30 pm  is reservation[3]
4:30 to 5 pm  is reservation[4]
*/
int main()
{   int num_mode,num_admin,num_user;
    int password,id_patient,count=0;
while(1)
{
    printf("hello\nif you want the admin mode :please enter number[1]:\n");
	printf("if you want the user mode : please enter number [2]:\n");
	scanf("%d",&num_mode);
	if(num_mode==1)
	{
		do
		{
			printf("please enter the password:\n");
		    scanf("%d",&password);
			if(password==1234)
			{
				break;
			}
			count++;
		}while(count<3);

		if(count==3)
		{
			printf("wrong password for 3 times");
			exit(1);
		}
		else
		{

		printf("hello admin \n");
		printf("if you want to create new information of the patient[%i] please enter number :1\n",counter+1);
		printf("if you want to edit the information of a patient please enter number :2\n");
		printf("if you to reserve a slot with the docter please enter number :3\n");
		printf("if you to cancel the reservation please enter number :4\n");
		scanf("%i",&num_admin);

		switch(num_admin)
		{
			case 1:
			   Add_New_Client();
			   break;
			case 2:
			   printf("please enter the ID of the patient :");
			   scanf("%i",&id_patient);
			   Edit_Client(id_patient);
			  break;
			case 3:
                printf("please enter the ID of the patient :");
			   scanf("%i",&id_patient);
                Reserve_Slot(id_patient);
				break;
            case 4:
			printf("please enter the ID of the patient :");
			 scanf("%i",&id_patient);
            Cancel_Slot(id_patient);
				break;
		}

	}
	}
	else if(num_mode==2)
	{
       printf("hello user\n");
	   printf("if you want to show patient information please enter number :1\n");
	   printf("if you want to show all reservation with patients id pleae enter number :2\n");
	   scanf("%d",&num_user);
	   switch(num_user)
	   {
		   case 1:
		   printf("please enter the id of the patient");
		   scanf("%i",&id_patient);
		   Print_Information_Client(id_patient);
		   break;
		   case 2:
		   Show_Reservation();
		   break;

	   }
	}
	else
	{
    printf("wrong choose");
	}
}

    return 0;
}
