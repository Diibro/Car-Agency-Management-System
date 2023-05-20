
void paymentprogress();
void displayRemarks();
void recordJourney();



 struct journey {
    int driver_id;
    char driver[20];
    int distance;
    int price;
    int commission;

};
void paymentprogress(){
    FILE *p;
    int current_commission = 0, count = 0;
    char date[20];
    struct journey info;
    p = fopen("Files/drivers_payments.txt","r");

    if(p==NULL){

        printf("system erro\n");
        return;
    }else{
        while(!feof(p) && fscanf(p, "%d\t%s\t%d\t%d\t%d", &info.driver_id, info.driver, &info.distance, &info.price, &info.commission) == 5){

            if(info.driver_id == loginI.id){
                current_commission += info.commission;
                count += info.distance;
            }
        }
        printf("\t\t\t\t======= PAYMENT PROGRESS=======\n\n\n");
        printf("\t\t\t\t Journeys made:.. %d km\n", count);
        printf("\t\t\t\t Current Payment:.. %d Rwf\n", current_commission);
        printf("\t\t\t\t___________\n\n");
    }

  }

void useDriverDashboard()
{
    printf("\e[1;1H\e[2J");
    int choice, cond = 1;
    while(cond){

    printf("\t\t\t=====DRIVER MANAGEMENT SYTEM=====\n");
    printf("\t\t\t\t     1. RECORD A NEW JOURNEY\n");
    printf("\t\t\t\t     2. CHECK PAYMENT PROGRESS\n");
    printf("\t\t\t\t     0. LOG OUT\n");
    printf("\t\t\t\t    _____________________\n");
    printf("\t\t\t\t     ");
    scanf("%d",&choice);

   switch(choice){
     case 1:
        printf("\e[1;1H\e[2J");
        recordJourney();
        break;

     case 2:
         printf("\e[1;1H\e[2J");
         paymentprogress();
          printf("\t\t\t\t  press any key to exit..... \n");
         break;
    case 0:
        printf("\e[1;1H\e[2J");
        printf("\n\n\nLogging out\n\n");
        sleep(1);
        cond = 0;
        break;
     default :
         printf("\e[1;1H\e[2J");
         getchar();
         printf("\n\t\t\t\t\tEnter a valid number\n\n");
         printf("\t\t\t\tPress any key to continue.......");
         getchar();
         break;
        }

        }
     }


void displayRemarks(){

    printf("You have the following remarks");
  }

void recordJourney(){
    printf("\e[1;1H\e[2J");
    struct journey new_j;
    FILE *p;
    printf("\nFill in the following information to record a new journey made: \n\n");
    printf("Enter distance reading from Distance meter:... ");
    scanf("%d", &new_j.distance);
    printf("Enter the amount paid in Rwf:...");
    scanf("%d", &new_j.price);
    new_j.commission = (new_j.price * 20)/100;
    strcpy(new_j.driver, loginI.name);
    new_j.driver_id = loginI.id;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", t);
    p = fopen("Files/drivers_payments.txt", "a");

    if(p != NULL){
        fprintf(p, "%d\t%s\t%d\t%d\t%d\n",new_j.driver_id, new_j.driver, new_j.distance, new_j.price, new_j.commission);
        printf("The journey has been recorded successfully\n");
    }else{
        printf("\e[1;1H\e[2J");
        printf("System Error");
    }
    fclose(p);
  }
