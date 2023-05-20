//#include "functions_File.c"

void displayReports(char type[20]){
    printf("\e[1;1H\e[2J");
    FILE *p;
    if(strcmp(type, "customerWorker") == 0){
        p = fopen("Files/report.txt", "r");
        if(p != NULL){
            char line[1300];
            while(fgets(line, 1300, p) != NULL){
                printf("%s\n", line);
            }
        }else{
            printf("No reports from this section\n");
        }
    }

}
void manageWorkers(){
    sleep(2);
    printf("\e[1;1H\e[2J");
    char type[20];
    strcpy(type, "user");
    int choice, cond = 1;
    while(cond){
        printf("\n\nPress 1: To record a new worker \nPress 2: To display All Workers register \nPress 3: Update information of a worker \nPress 0: To go back\n\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                registerItem(type);
                break;
            case 2:
                displayItems(type);
                break;
            case 3:
                updateItem(type);
                break;
            case 0:
                cond = 0;
                break;
            default:
                printf("Invalid Choise please");
        }
    }

}
void manageCustomerSupport(){
    //sleep(2);
    printf("\e[1;1H\e[2J");
    char type[20];
    strcpy(type, "customerWorker");
    int choice, cond = 1;
    while(cond){
        printf("\n\nPress 1: To record a new customer worker \nPress 2: To display All Workers register \nPress 3: Update information of a worker \nPress 5: To view Reports \nPress 0: To go back\n\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                registerItem(type);
                break;
            case 2:
                displayItems(type);
                break;
            case 3:
                updateItem(type);
                break;
            case 5:
                displayReports(type);
                break;
            case 0:
                cond = 0;
                break;
            default:
                printf("Invalid Choise please");
        }
    }
}
void manageVehicles(){
     //sleep(2);
    printf("\e[1;1H\e[2J");
    char type[20];
    strcpy(type, "vehicle");
    int choice, cond = 1;
    while(cond){
        printf("\n\nPress 1: To record a new vehicle \nPress 2: To display All vehicles register \nPress 3: Update information of a vehicle \nPress 0: To go back\n\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                registerItem(type);
                break;
            case 2:
                displayItems(type);
                break;
            case 3:
                updateItem(type);
                break;
            case 0:
                cond = 0;
                break;
            default:
                printf("Invalid Choise please");
        }
    }
}
void manageDrivers(){
     sleep(2);
    printf("\e[1;1H\e[2J");
    char type[20];
    strcpy(type, "driver");
    int choice, cond = 1;
    while(cond){
        printf("\n\nPress 1: To display All drivers in the company currently register \nPress 0: To go back\n\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                displayItems(type);
                break;
            case 0:
                cond = 0;
                break;
            default:
                printf("Invalid Choise please");
        }
    }
}


void useAdmin(){
    int choice, cond = 1;
    printf("\e[1;1H\e[2J");
    sleep(2);
    printf("Your are now logged in to the admin DashBoard Welcome \n");
    while(cond){
        sleep(2);
        printf("\e[1;1H\e[2J");
        printf("\n\n\t --- Here is a guide on how to use the admin Dashboard ---\n\n");
        printf("\n\t\tPress 1: To manage Workers \n\t\tPress 2: To manage Customer Support Workers \n\t\tPress 3: To manage the vehicles bought \n\t\tPress 4: To manage all Drivers \n\t\tPress 0 to Log out \n");
        printf("\n\t\tChoice:...");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                manageWorkers();
                break;
            case 2:
                manageCustomerSupport();
                break;
            case 3:
                manageVehicles();
                break;
            case 4:
                manageDrivers();
                break;
            case 0:
                cond = 0;
                sleep(2);
                printf("\e[1;1H\e[2J");
                printf("\n\n\n\n\t\t\t\tYou have been logout!!\n");
                break;
            default:
                printf("Invalid Choice");

        }

        }
}


