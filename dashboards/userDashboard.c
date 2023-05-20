


void remarks()
{
    struct items item;
    FILE *fp;
    int licenseid,found=0;

    fp=fopen("Files/information.txt","r");
    printf("\t\t\t\t======= ADD Driver Remarks RECORD=======\n\n\n");

    while(fread(&item,sizeof(struct items),1,fp)>0){

        if(item.id==licenseid){

            found=1;
            printf("\n\t\t\t\t DRIVER NAME  : %s",item.userName);
            printf("\n\t\t\t\t VEHICLE ID      : %d",item.vehicle_id);
            printf("\n\t\t\t\t Remarks    :");
            scanf("%s", item.remarks);
            printf("\n\t\t\t______________________________________\n");

         }

    }

    if(!found){
       printf("\n\t\tRecord not found\n");
    }

    fclose(fp);
}

void useUserDashboard()
{
    printf("\e[1;1H\e[2J");
    int choice, cond = 1;
    while(choice){

        printf("\t\t\t=====AGENT INTERFACE SYSTEM=====");
        printf("\n\n\n\t\t\t\t     1. RECORD NEW DRIVER\n");
        printf("\t\t\t\t     0. LOG OUT\n");
        printf("\t\t\t\t    _____________________\n");
        printf("\t\t\t\t     ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                char type[20];
                strcpy(type, "driver");
                registerItem(type);
                break;
            case 0:
                printf("\e[1;1H\e[2J");
                printf("\n\n\nLogging out\n\n");
                sleep(1);
                cond = 0;
                break;
            default :
                printf("\n\t\t\t\t\tEnter a valid number\n\n");
                printf("\t\t\t\tPress any key to continue.......");
                break;
        }

    }
}


