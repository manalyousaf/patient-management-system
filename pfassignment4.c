#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
struct patient //structure decleration
	{
		//structure members
	    unsigned int ID;
	    char NAME[50];
	    char CNIC[15];
	    char NUM[15];
	    char disease[100];
	    char isAdmitted;
	} data;
void choice();
void addPatient();
void deletePatient();
int main()
{
   
    choice();//call a function
    return 0;

}
void choice()
{
    int choice;
    printf("\n\t\t\tMENU\t\t\t");
    printf("\n1. Add Patient");
    printf("\n2. Search Patient");
    printf("\n3. Display All Patient");
    printf("\n4. Delete Patient");
    printf("\n5. Update Patient");
    printf("\n6. EXit");
    printf(" \nEnter your Choice");
    scanf_s("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        printf("\nAdding a Patient\n");
        addPatient();
        break;
    }
    case 2:
    {
        printf("\nSearching a Patient\n");
        searchPatient();
        
        break;
    }
    case 3:
    {
        printf("\nDisplaying All Patient\n");
        display();
       
        break;
    }
    case 4:
    {
        printf("\nDeleting a Patient\n");
        deletePatient();
       
        break;
    }
    case 5:
    {
        printf("\nUpdating a Patient\n");
        updatePatient();
        
        break;
    }
    case 6:
    {
        printf("\nExiting");
          exit(EXIT_FAILURE);
    }
    default:
    {
        printf("\nInvalid Choice");
        
    }
    }
}



void addPatient()
{
    struct patient data = { 0 };
    FILE* fp = NULL;
    int validation = 0;
    fopen_s(&fp, "patientsystem.bin", "ab+");//open and create a file
    if (fp == NULL)
    {
        printf("File is not opened\n");
       
    }
    else{
        printf("\nEnter your Details below:");
        printf("\nPatient ID  = ");
        fflush(stdin);
        scanf("%u", &data.ID);
         printf("\nPatient  Name  = ");
            fflush(stdin);
            getchar();
            gets(data.NAME);
            printf("\nPatient CNIC  = ");
            fflush(stdin);
            getchar();
            gets(data.CNIC);
            printf("\nPatient number  = ");
            fflush(stdin);
            getchar();
            gets(data.NUM);
             printf("\nPatient Disease  = ");
            fflush(stdin);
            gets(data.disease);
        fwrite(&data, sizeof(data), 1, fp);//write data on file
        fclose(fp);
    }
    
    choice();
}
void deletePatient()
{
    int found = 0;
    int Delete = 0;
    struct patient data = { 0 };
    FILE* fp = NULL;
    FILE* temp = NULL;
        fopen_s(&fp, "patientsystem.bin", "rb");//open binary file in read mode
    if (fp == NULL)
    {
        printf("File is not opened\n");
       
    }
    else{
        fopen_s(&temp, "temp.bin", "wb");//open binary file in write mode
        if (temp == NULL)
        {
            fclose(fp);
            printf("File is not opened\n");
           
            
        }
        else{
            printf("\nEnter patient ID NO. for delete:");
            scanf("%d", &Delete);
            while (fread(&data, sizeof(data), 1, fp))//loop continue until return null value
            {
                if (data.ID != Delete)
                {
                    fwrite(&data, sizeof(data), 1, temp);//write in file if data id not match
                }
                else
                {
                    found = 1;
                }
            }
            
            fclose(fp);
            fclose(temp);
            remove("patientsystem.bin");//delete file
            rename("temp.bin", "patientsystem.bin");//rename file
           if(found==1) {
		    printf("\nRecord deleted successfully.....");
			}
			else
			{
			
			  printf("\nRecord not found");
		}
        }
       
    }
   
    choice();
}