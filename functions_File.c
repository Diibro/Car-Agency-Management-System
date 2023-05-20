#include <time.h>
#include <string.h>
struct loginInfo {
    int id;
    char type[20];
    char name[20];
    char password[20];
} loginI;

struct items {
        int id;
        char userName[20];
        char password[20];
        char driverName[20];
        int vehicle_id;
        char remarks[200];
    };
void useUserDashboard();
void useCustomerWorker();
void useDriverDashboard();
void useAdmin();

struct items searchItem(char type[20], int id){
    struct items ITEMS[50];
    struct items item;
    int count = 0;
    FILE *p;
    if(strcmp(type, "user") == 0){
        p = fopen("Files/agencyUsers.txt", "r");
        if(p != NULL){
        while(!feof(p) && count < 50){
            fscanf(p, "%d\t%s\%s", &ITEMS[count].id, ITEMS[count].userName, ITEMS[count].password);
            count++;
        }
        for(count = 0; count < 50; count++){
            if(id == ITEMS[count].id){
                item.id = id;
                strcpy(item.userName, ITEMS[count].userName);
                strcpy(item.password, ITEMS[count].password);
            }
        }
       }
    }else if(strcmp(type, "customerWorker") == 0){
       p = fopen("Files/agencyCustomerWorkers.txt", "r");
       if(p != NULL){
        while(!feof(p) && count < 50){
            fscanf(p, "%d\t%s\%s", &ITEMS[count].id, ITEMS[count].userName, ITEMS[count].password);
            count++;
        }
        for(count = 0; count < 50; count++){
            if(id == ITEMS[count].id){
                item.id = id;
                strcpy(item.userName, ITEMS[count].userName);
                strcpy(item.password, ITEMS[count].password);
            }
        }

       }
    }else if(strcmp(type, "driver") == 0){
        p = fopen("Files/agencyDrivers.txt", "r");
        if(p != NULL){
        while(!feof(p) && count < 50){
            fscanf(p, "%d\t%s\t%s\t%d", &ITEMS[count].id, ITEMS[count].userName, ITEMS[count].password, &ITEMS[count].vehicle_id);
            count++;
        }
        for(count = 0; count < 50; count++){
            if(id == ITEMS[count].id){
                item.id = id;
                strcpy(item.userName, ITEMS[count].userName);
                strcpy(item.password, ITEMS[count].password);
                item.vehicle_id = ITEMS[count].vehicle_id;
            }
        }

       }
    }else if(strcmp(type, "Vehicle") == 0){
        p = fopen("Files/agencyVehicles.txt", "r");
        if(p != NULL){
        while(!feof(p) && count < 50)
            fscanf(p, "%d\%s\t%s", &ITEMS[count].id, ITEMS[count].userName, ITEMS[count].driverName);
            count++;
       }
       for(count = 0; count < 50; count++){
            if(ITEMS[count].id == id){
                item.id = id;
                strcpy(item.userName, ITEMS[count].userName);
                strcpy(item.driverName, ITEMS[count].driverName);
            }
       }
    }

    return item;
}

void registerItem(char type[20]){
    //printf("\e[1;1H\e[2J");
    printf("\e[1;1H\e[2J");
    struct items item;
    FILE *p;
    int count, check = 0;
    if(strcmp(type,"user") == 0){
        p = fopen("Files/agencyUsers.txt", "a");
        printf("Enter the user Id: ");
        scanf("%d", &item.id);
        printf("Enter the user Name: ");
        scanf("%s", item.userName);
        printf("Enter the user Password: ");
        scanf("%s", item.password);
        fprintf(p,"%d\t%s\t%s\n", item.id, item.userName, item.password);
        fclose(p);
        sleep(1);
        printf("\033[0;31m");
        printf("\n\nRegistered successfully\n\n");
        printf("\033[0m");

    }else if(strcmp(type,"customerWorker") == 0){
        p = fopen("Files/agencyCustomerWorkers.txt", "a");
        printf("Enter the Worker Id: ");
        scanf("%d", &item.id);
        printf("Enter the Worker Name: ");
        scanf("%s", item.userName);
        printf("Enter the Worker Password: ");
        scanf("%s", item.password);
        fprintf(p,"%d\t%s\t%s\n", item.id, item.userName, item.password);
        fclose(p);
        sleep(1);
        printf("\033[0;31m");
        printf("\n\nRegistered successfully\n\n");
        printf("\033[0m");
    }else if(strcmp(type,"driver") == 0){
        struct items vehicleI;
        p = fopen("Files/agencyVehicles.txt", "r");
        if(p != NULL){
            struct items temp;
            int c = 0;
            fclose(p);
        }else{

            printf("\n\nNo vehicles current in the system\n\n");
            return;
        }
        p = fopen("Files/agencyDrivers.txt", "a");
        printf("\n\nEnter the Drivers Info:...\n");
        printf("\nEnter the Driver Id: ");
        scanf("%d", &item.id);
        printf("Enter the Driver Name: ");
        scanf("%s", item.userName);
        printf("Enter the Driver Password: ");
        scanf("%s", item.password);
        printf("Enter the Vehicle Id");
        scanf("%d", &item.vehicle_id);
        fprintf(p,"%d\t%s\t%s\t%d\n", item.id, item.userName, item.password,item.vehicle_id);
        fclose(p);
        sleep(1);
        printf("\033[0;33m");
        printf("\n\nRegistered successfully\n\n");
        printf("\033[0m");
    }else if(strcmp(type,"vehicle") == 0){
        p = fopen("Files/agencyVehicles.txt", "a");
        printf("Enter the Vehicle Number: ");
        scanf("%d", &item.id);
        printf("Enter the Vehicle Name: ");
        scanf("%s", item.userName);
        strcpy(item.driverName, "none");
        fprintf(p,"%d\t%s\t%s\n", item.id, item.userName, item.driverName);
        fclose(p);
        sleep(1);
        printf("\e[1;1H\e[2J");
        printf("\n\nRegistered successfully\n\n");
        printf("\033[0m");
    }

}

void loginUser(char type[20],char name[20],char password[20]){
    struct users{
        int id;
        char UserName[20];
        char Userpassword[20];
    } user[50];

    FILE *p;
    int count, check = 0;

    if(strcmp(type, "user") == 0){
        count = 0;
        p = fopen("Files/agencyUsers.txt", "r");
        if(p != NULL){
           while(!feof(p) && count < 50){
                fscanf(p, "%d\t%s\t%s", &user[count].id, user[count].UserName, user[count].Userpassword);
                count++;
            }

            for(count = 0; count < 50; count++){
                if(strcmp(name, user[count].UserName) == 0 && strcmp(password, user[count].Userpassword) == 0){
                check = 1;
                loginI.id = user[count].id;
                strcpy(loginI.name, user[count].UserName);
            }
            }
            if(check == 1){
                useUserDashboard();
            }else{
                printf("\033[0;34m");
                printf("Invalid User information");
                printf("\033[0m");
            }
        }else{
            printf("\033[0;34m");
            printf("No Users already in the system\n");
            printf("\033[0m");
        }
        fclose(p);


    }else if(strcmp(type, "customerWorker") == 0){
        count = 0;
        p = fopen("Files/agencyCustomerWorkers.txt", "r");
        if(p != NULL){
           while(!feof(p) && count < 50){
                fscanf(p, "%d\t%s\t%s", &user[count].id, user[count].UserName, user[count].Userpassword);
                count++;
            }

            for(count = 0; count < 50; count++){
                if(strcmp(name, user[count].UserName) == 0 && strcmp(password, user[count].Userpassword) == 0){
                check = 1;
                loginI.id = user[count].id;
                strcpy(loginI.name, user[count].UserName);
            }
            }
            if(check){
                useCustomerWorker();
            }else{
                printf("\033[0;34m");
                printf("Invalid CustomerWorker information");
                printf("\033[0m");
            }
        }else{
            printf("\033[0;34m");
            printf("No Customer Workers already registered in the system already in the system\n");
            printf("\033[0m");
        }
        fclose(p);
    }else if(strcmp(type, "driver") == 0){
        count = 0;
        p = fopen("Files/agencyDrivers.txt", "r");
        if(p != NULL){
           while(!feof(p) && count < 50){
            int vehicle;
                fscanf(p, "%d\t%s\t%s\t%d", &user[count].id, user[count].UserName, user[count].Userpassword, &vehicle);
                count++;
            }

            for(count = 0; count < 50; count++){
                if(strcmp(name, user[count].UserName) == 0 && strcmp(password, user[count].Userpassword) == 0){
                check = 1;
                loginI.id = user[count].id;
                strcpy(loginI.name, user[count].UserName);
            }
            }
            if(check){
                useDriverDashboard();
            }else{
                printf("\033[0;34m");
                printf("Invalid Driver login information");
                printf("\033[0m");
            }
        }else{
            printf("\033[0;34m");
            printf("No Drivers already registered in the system already in the system\n");
            printf("\033[0m");
        }
        fclose(p);
    }
}


void displayItems(char type[20]){
    FILE *p;
    struct items itemsIn;
    int c = 0;
    if(strcmp(type, "user") == 0){
        p = fopen("Files/agencyUsers.txt", "r");
        if(p != NULL){
            printf("\t\t\t\tID\tusername\n");
            while(!feof(p) && fscanf(p,"%d\t%s\t%s", &itemsIn.id, itemsIn.userName, itemsIn.password) == 3){
                if(itemsIn.id != 0){
                    printf("\t\t\t\t%d\t\t\t%s\n", itemsIn.id, itemsIn.userName);
                }
                c++;
            }

        }else{
            printf("\n\n\nNo users registered with in the system \n");
        }
    }else if(strcmp(type, "customerWorker") == 0){
        p = fopen("Files/agencyCustomerWorkers.txt", "r");
        if(p != NULL){
            printf("\t\t\t\tID\t\t\tusername\n");
            while(!feof(p) && fscanf(p,"%d\t%s\t%s", &itemsIn.id, itemsIn.userName, itemsIn.password) == 3){
                if(itemsIn.id != 0){
                    printf("\t\t\t\t%d\t\t\t%s\n", itemsIn.id, itemsIn.userName);
                }
                c++;
            }

        }else{
            printf("\n\n\nNo users registered with in the system \n");
        }
    }else if(strcmp(type, "driver") == 0){
        p = fopen("Files/agencyDrivers.txt", "r");
        if(p != NULL){
            printf("\t\t\t\tID\t\t\tusername\t\t\tVehicle_ID\n");
            while(!feof(p) && fscanf(p,"%d\t%s\t%s\t%d", &itemsIn.id, itemsIn.userName, itemsIn.password, &itemsIn.vehicle_id) == 4){
                printf("\t\t\t\t%d\t\t\t%s\t\t\t%d", itemsIn.id, itemsIn.userName, itemsIn.vehicle_id);
                c++;
            }

        }else{
            printf("\n\n\nNo Drivers currently registered with in the system \n");
        }
    }else if(strcmp(type, "vehicle") == 0){
        p = fopen("Files/agencyVehicles.txt", "r");
        if(p != NULL){
            printf("\t\tID\t\t\tusername\n");
            while(!feof(p) ){
                if((fscanf(p,"%d\t%s\t%s", &itemsIn.id, itemsIn.userName, itemsIn.driverName) == 3)){
                     printf("\t\t%d\t\t\t%s\t\t%s\n", itemsIn.id, itemsIn.userName, itemsIn.driverName);
                     c++;
                }else{
                    break;
                }

            }
        }else{
            printf("\n\n\nNo users registered with in the system \n");
        }
        fclose(p);
    }
}

void updateItem(char type[20]){
    struct items temp[50];
    FILE *p;
    int count = 0, s_id;
    struct items fetch;
    if(strcmp(type, "user") == 0){
        p = fopen("Files/agencyUsers.txt", "r");
        if(p != NULL){
            while(!feof(p) && count < 50){
                fscanf(p,"%d\t%s\t%s", &temp[count].id, temp[count].userName, temp[count].password);
                count++;
            }
        }
        fclose(p);
        printf("\n\n\tEnter the id of the worker you would like to edit:..");
        scanf("%d", &s_id);
        fetch = searchItem(type, s_id);
        printf("The current information of the searched worker is \n");
        printf("\t\tID\t\tName\t\tPassword\n");
        printf("\t\t==\t\t=====\t\t=======\n");
        printf("\t\t%d\t\t%s\t\t%s\n", fetch.id, fetch.userName, fetch.password);
        printf("\n\nPlease enter the new information for the worker");
        printf("\n\nEnter the new id:...");
        scanf("%d", &fetch.id);
        printf("Enter the new User Name:...");
        scanf("%s", fetch.userName);
        printf("Enter the new password:...");
        scanf("%s", fetch.password);
        for(count = 0; count < 50; count++){
            if(temp[count].id == s_id){
               temp[count].id = fetch.id;
               strcpy(temp[count].userName, fetch.userName);
               strcpy(temp[count].password, fetch.password);
               break;
            }
        }
        p = fopen("Files/agencyUsers.txt", "w");
        for(count = 0; count < 50 && temp[count].id != 0; count++){
            fprintf(p,"%d\t%s\t%s\n", temp[count].id, temp[count].userName, temp[count].password);
        }
        fclose(p);
        sleep(1);
        printf("\n\n The update has been done successfully \n");

    }else if(strcmp(type, "customerWorker") == 0){
        p = fopen("Files/agencyCustomerWorkers.txt", "r");
        if(p != NULL){
            while(!feof(p) && count < 50){
                fscanf(p,"%d\t%s\t%s", &temp[count].id, temp[count].userName, temp[count].password);
                count++;
            }
        }
        fclose(p);
        printf("\n\n\tEnter the id of the worker you would like to edit:..");
        scanf("%d", &s_id);
        fetch = searchItem(type, s_id);
        printf("The current information of the searched worker is \n");
        printf("\t\tID\t\tName\t\tPassword\n");
        printf("\t\t==\t\t=====\t\t=======\n");
        printf("\t\t%d\t\t%s\t\t%s\n", fetch.id, fetch.userName, fetch.password);
        printf("\n\nPlease enter the new information for the worker");
        printf("\n\nEnter the new id:...");
        scanf("%d", &fetch.id);
        printf("Enter the new User Name:...");
        scanf("%s", fetch.userName);
        printf("Enter the new password:...");
        scanf("%s", fetch.password);
        for(count = 0; count < 50; count++){
            if(temp[count].id == s_id){
               temp[count].id = fetch.id;
               strcpy(temp[count].userName, fetch.userName);
               strcpy(temp[count].password, fetch.password);
               break;
            }
        }
        p = fopen("Files/agencyCustomerWorkers.txt", "w");
        for(count = 0; count < 50 && temp[count].id != 0; count++){
            fprintf(p,"%d\t%s\t%s\n", temp[count].id, temp[count].userName, temp[count].password);
        }
        fclose(p);
        sleep(1);
        printf("\n\n The update has been done successfully \n");

    }else if(strcmp(type, "driver") == 0){
        p = fopen("Files/agencyDrivers.txt", "r");
        if(p != NULL){
            while(!feof(p) && count < 50){
                fscanf(p,"%d\t%s\t%s", &temp[count].id, temp[count].userName, temp[count].password);
                count++;
            }
        }
        fclose(p);
        printf("\n\n\tEnter the id of the driver you would like to edit:..");
        scanf("%d", &s_id);
        fetch = searchItem(type, s_id);
        printf("The current information of the searched driver is \n");
        printf("\t\tID\t\tName\t\tPassword\n");
        printf("\t\t==\t\t=====\t\t=======\n");
        printf("\t\t%d\t\t%s\t\t%s\n", fetch.id, fetch.userName, fetch.password);
        printf("\n\nPlease enter the new information for the driver");
        printf("\n\nEnter the new id:...");
        scanf("%d", &fetch.id);
        printf("Enter the new User Name:...");
        scanf("%s", fetch.userName);
        printf("Enter the new password:...");
        scanf("%s", fetch.password);
        for(count = 0; count < 50; count++){
            if(temp[count].id == s_id){
               temp[count].id = fetch.id;
               strcpy(temp[count].userName, fetch.userName);
               strcpy(temp[count].password, fetch.password);
               break;
            }
        }
        p = fopen("Files/agencyDrivers.txt", "w");
        for(count = 0; count < 50 && temp[count].id != 0; count++){
            fprintf(p,"%d\t%s\t%s\n", temp[count].id, temp[count].userName, temp[count].password);
        }
        fclose(p);
        sleep(1);
        printf("\n\n The update has been done successfully \n");

    }else if(strcmp(type, "vehicle") == 0){
        printf("Cannot update the vehicle information with the current version of the system.\n ");
        /*p = fopen("Files/agencyVehicles.txt", "r");
        if(p != NULL){
            while(!feof(p) && count < 50){
                fscanf(p,"%d\t%s\t%s", &temp[count].id, temp[count].userName, temp[count].password);
                count++;
            }
        }
        fclose(p);
        printf("\n\n\tEnter the id of the vehicle you would like to edit:..");
        scanf("%d", &s_id);
        fetch = searchItem(type, s_id);
        printf("The current information of the searched vehicle is \n");
        printf("\t\tID\t\tName\t\tPassword\n");
        printf("\t\t==\t\t=====\t\t=======\n");
        printf("\t\t%d\t\t%s\t\t%s\n", fetch.id, fetch.userName, fetch.password);
        printf("\n\nPlease enter the new information for the vehicle");
        printf("\n\nEnter the new id:...");
        scanf("%d", &fetch.id);
        printf("Enter the new User Name:...");
        scanf("%s", fetch.userName);
        printf("Enter the new password:...");
        scanf("%s", fetch.password);
        for(count = 0; count < 50; count++){
            if(temp[count].id == s_id){
               temp[count].id = fetch.id;
               strcpy(temp[count].userName, fetch.userName);
               strcpy(temp[count].password, fetch.password);
               break;
            }
        }
        p = fopen("Files/agencyVehicles.txt", "w");
        for(count = 0; count < 50 && temp[count].id != 0; count++){
            fprintf(p,"%d\t%s\t%s\n", temp[count].id, temp[count].userName, temp[count].password);
            printf("\n\n Unable to update the vehicle information \n Please contact your IT support Team\n");
        }*/
        fclose(p);
        sleep(1);
        printf("\n\n The update has been done successfully \n");

    }
}


