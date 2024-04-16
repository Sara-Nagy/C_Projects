
#include<stdio.h>
#include"clinic_system.h"

extern int counter;
extern client arr[];
extern int reservation[];
void Add_New_Client()
{
  client client_new;
  int i;
	if (counter>number_of_client)
	{
		printf("there is no space for new  patient");
	}
	else
	{
		printf("please enter the ID of the  patient:");
		scanf("%i",&client_new.id);
		for(i=0;i<=counter;i++)
		{
			if (arr[i].id==client_new.id)
			{
				printf("this ID is already reserved.\nplease enter anther ID:");
				scanf("%i",&client_new.id);
				break;
			}
		}
		printf("please enter the name of the patient:");
		fflush(stdin);
		gets(client_new.name);
		fflush(stdin);

		printf("please enter the age of the  patient:");
		scanf("%i",&client_new.age);

		printf("please enter the gender of the reservation:");
		fflush(stdin);
		gets(client_new.gender);
		fflush(stdin);

		client_new.reserve[0]='\0';
        client_new.num=0;
		arr[counter]=client_new;
		counter++;
	}
}

void Edit_Client(int id)
{
    int i,index=-1;
	for(i=0;i<=counter;i++)
	{
		if(arr[i].id==id)
		{
			index=i;
			break;
		}
	}
	if(index==-1)
	{
		printf("Wrong ID ");
	}
	 else
	 {
		 printf("please enter the new ID :");
		 scanf("%i",&arr[index].id);
		 printf("please enter new age:");
		 scanf("%i",&arr[index].age);
		 printf("please enter the new name:");
		 fflush(stdin);
		 gets(arr[index].name);
		 fflush(stdin);
		 printf("please enter the gender of the EDIT in information:");
		 fflush(stdin);
		 gets(arr[index].gender);
		 fflush(stdin);
	 }
}

void Reserve_Slot(int id)
{
	int i,index;
	if(reservation[0]==1&&reservation[1]==1&&reservation[2]==1&&reservation[3]==1&&reservation[4]==1)
	{
		printf("there is no avaibale slots");
	}
	else

		{
			printf("the avaibale slots are:\n");

			 if(reservation[0]==0)
			 {
				 printf("2 to 2:30 pm  number: 1\n");
			 }

			 if(reservation[1]==0)
			 {
				 printf("2:30 to 3 pm  number: 2\n");
			 }

			 if(reservation[2]==0)
			 {
				 printf("3 to 3:30 pm  number: 3\n");
			 }

			 if(reservation[3]==0)
			 {
				 printf("4 to 4:30 pm  number: 4\n");
			 }

			 if(reservation[4]==0)
			 {
				 printf("4:30 to 5 pm  number: 5\n");
			 }

	for(i=0;i<=counter;i++)
	{
		if(arr[i].id==id)
		{
			index=i;
			break;
		}
	}

	printf("please enter the desired slot \n");
	fflush(stdin);
	gets(arr[index].reserve);
	fflush(stdin);
	printf("please enter the number of slot:");
	scanf("%i",&arr[index].num);


	for(i=1;i<=5;i++)
	{
		if(arr[index].num==i)
		{
			reservation[i-1]=1;
			break;
		}
	}

		}
}

void Cancel_Slot(int id)
{
	int i,index=-1;
	for(i=0;i<=counter;i++)
	{
		if(arr[i].id==id)
		{
			index=i;
		}
	}

  if(index==-1)
  {
      printf("wrong id\n");
  }
  else
  {
   arr[index].reserve[0]='\0';
   reservation[(arr[index].num)-1]=0;
   arr[index].num=0;
  }

}

void Print_Information_Client(int id)
{
	int i,index=-1;
	for(i=0;i<=counter;i++)
	{
		if(arr[i].id==id)
		{
			index=i;
		}
	}
	if(index==-1)
    {
        printf("wrong id\n");
    }
    else
    {
	printf("the ID of the patient is :%d\n",arr[index].id);
	printf("the name of the patient is :%s\n",arr[index].name);
	printf("the age of the patient is :%d\n",arr[index].age);
	printf("the gender of  create the information of the patient is :%s\n",arr[index].gender);
	printf("the slot of the patient is :%s\n",arr[index].reserve);
    }

}
void Show_Reservation()
{
	int i;
	for(i=0;i<=counter;i++)
	{
		if(arr[i].num!=0)
		{
			printf("the reservation of the patient with ID : %d  is : %s\n",arr[i].id,arr[i].reserve);
		}
	}


}

