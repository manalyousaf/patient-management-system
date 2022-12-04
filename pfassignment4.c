void updatePatient()
{
    struct patient data = { 0 };//create a structure variable
    int count=0;
    FILE* fp = NULL;
    char NAME[50] = { 0 };
    char CNIC[15] = { 0 };
    char NUM[15] = { 0 };
    char disease[100] = { 0 };
        int id;
        fopen_s(&fp, "patientsystem.bin", "rb+");//open a file for reading and writing in binary mode
        if (fp == NULL)
        {
            printf("File is not opened\n");
            
        }
        else {
            printf("\nEnter ID of patient to update ");
            scanf("%u", &id);
            while (fread(&data, sizeof(data), 1, fp))//read data from file until null value
            {
                if (id == data.ID)
                {
                     count=1;
                    int q;
                    fflush(stdin);
                    printf("\nWhat do you want to update ?");
                   do{
                    printf("\nEnter your option");
                    printf("\n1.Name\n2.CNIC\n3.Number\n4.Disease\n5.Done");
                    printf("\nOption= ");
                    fflush(stdin);
                    scanf("%d", &q);//option
                     if(q==2)
                    	{
						
                        printf("\nEnter new CNIC: ");
                        fflush(stdin);
                        getchar();
                        gets(CNIC);
                        strncpy(data.CNIC, CNIC, sizeof(CNIC));//copy enter cnic into data CNIC
            
                    }
                      else if(q==1)
                    	{
						
                        printf("\nEnter new NAME: ");
						fflush(stdin);
						getchar();  
                        gets(NAME);
                        strncpy(data.NAME, NAME, sizeof(NAME));
        }
                    else if(q==3)
                    	{
                        printf("\nEnter new number: ");
                        fflush(stdin);
                        getchar();
                        gets(NUM);
                        strncpy(data.NUM, NUM, sizeof(NUM));
                    
                    }

                    else if(q==4) 
                    	{
						
                        printf("\nEnter disease: ");
                        fflush(stdin);
                        gets(disease);
                        strncpy(data.disease, CNIC, sizeof(disease));
                    }
                    else if(q==5){
                    	printf("Done");
                    	break;
					}
                    else
                    	{
					
                        printf("\nyou have entered wrong choice: \n ENTER AGAIN ");
                        scanf("%d",&q);
                        
                    }
                    fwrite(&data, sizeof(data), 1, fp);//write updated data in file
                } while(q<=5&&q>=1);
                  printf("\nYour information has been updated successfully");
                
            }
           
            }
            fclose(fp);
            fflush(stdin);
            getchar();
             if (count==0)
            {
            	printf("NO Record found");
			}


        }
       
        choice();
}
void searchPatient()
{
    int found = 0;
    int id = 0;
    struct patient data = { 0 };
    FILE* fp = NULL;
    fopen_s(&fp, "patientsystem.bin", "rb");//open file in read mode
    if (fp == NULL)
    {
        printf("\nFile is not opened\n");
    }
    else{
        printf("\nEnter patient  ID NO to search:");
        fflush(stdin);
        scanf("%u", &id);
        while (fread(&data, sizeof(data), 1, fp))//read data from file
        {
            if (data.ID == id)//if data id match then display on screen
            {
                found = 1;
            printf("\nPatient id = %u\n", data.ID);
            printf("\nPatient name = %s\n", data.NAME);
            printf("\nPatient CNIC = %s\n", data.CNIC);
            printf("\nPatient number = %s\n", data.NUM);
            printf("\nPatient Disease = %s\n", data.disease);
            printf("\nPatient status = %s\n", "patient is admitted");
            
            }
        }
       
        if(found==0)//data id not match
        {
            printf("\nNo Record  Record");
        }
        fclose(fp);
        fflush(stdin);
        getchar();
    }
   
    choice();


}
void display()
{
    int found = 0;
    struct patient data = { 0 };
    FILE* fp = NULL;
    fopen_s(&fp, "patientsystem.bin", "rb");//open a file in read binary mode
    if (fp == NULL)
    {
        printf("File is not opened\n");
        
    }
    else{
        while (fread(&data, sizeof(data), 1, fp))//read data from file 
        {
        	//display all records from file
            printf("\nPatient id = %u\n", data.ID);
            printf("\nPatient name = %s\n", data.NAME);
            printf("\nPatient CNIC = %s\n", data.CNIC);
            printf("\nPatient number = %s\n", data.NUM);
            printf("\nPatient Disease = %s\n", data.disease);
            printf("\nPatient status = %s\n", "patient is admitted");
            found = 1;

        }
        fclose(fp);
        if (!found)
        {
            printf("\nNo Record found");
        }
        fflush(stdin);
        getchar();
    }
    
    choice();
}



