#include <stdio.h>
#include <time.h>
#include <string.h>
#include <time.h>


#include "functions_File.c"
#include "dashboards/driverDashboard.c"
#include "dashboards/adminDashboard.c"
#include "dashboards/customerSupportDashboard.c"
#include "dashboards/userDashboard.c"





void main(){
    int check, cond = 1, condi = 0;
    //sleep(1);
    printf("\n\n\n\n\t-----\tWelcome to Our Car Agency\t---------- \n");
    printf("\n\tOur Transport Agency hopes to deliver the best services to our customers\n");
    //sleep(1);
    printf("\n\tOur transportation Agency has been in place since 2019 with an \n\t aim to give the best transport services.\n");
    //sleep(1);
    printf("\n\n\t Feel free to contact our support team in case of any problem\n\n");
    //sleep(1);
    printf("\n\tContact details for the CEO \n\tEmail: dushimeconso1234@gmail.com \n\tPhone: +250780795232\n");
    //sleep(1);
    printf("\n\t Would you like to use our platform? \n\t Press 1: to Continue \n\tPress 0: to quit\n\tChoice... ");
    scanf("%d", &condi);
    if(condi){
            while(cond){
            //sleep(3);
            printf("\e[1;1H\e[2J");
            printf("To login to the system: Press 1 \nTo leave a message as a customer: Press 2 \nTo Exit The program press 0 \nYour choice:...");
            scanf("%d", &check);
            getchar();
            if(check == 1){
                printf("Enter Your Login Type:.. ");
                scanf("%s", loginI.type);
                printf("Enter your userName:... ");
                scanf("%s", loginI.name);
                printf("Enter your password:... ");
                scanf("%s", loginI.password);
                if((strcmp(loginI.type, "admin") == 0) || (strcmp(loginI.type, "Admin") == 0) ){
                    if(strcmp(loginI.name, "AgencyAdmin") == 0 && strcmp(loginI.password,"Admin123") == 0){
                        useAdmin();
                    }
                }else{
                    loginUser(loginI.type, loginI.name, loginI.password);
                }

             }else if(check == 2){
                FILE *p;
                char message[256], name[20], phoneNumber[20];
                printf("\e[1;1H\e[2J");
                printf("Hello welcome to our customer section \nWe would love hearing from you. \n");
                //sleep(1);
                printf("\n\nFeel free to write your feed in the following lines:... \n\n");
                printf("Enter you name:... ");
                fgets(name, 20, stdin);
                printf("Enter your phone number:...");
                fgets(phoneNumber, 20, stdin);
                printf("Enter our your feedback and our support team will get back to you \n");
                fgets(message, 256, stdin);
                printf("\n\n\n !!!! Thank you for the feedback we shall get to you soon. Thank you!!!!");

                p = fopen("Files/Customer-Messages.txt", "a");
                fprintf(p, "%s\t%s\t%s \n", name, phoneNumber, message);
                fclose(p);
                //sleep(2);
                cond = 1;

             }else if(check == 0){
                return;
             }else{
                printf("\033[0;31m");
                printf("\nEnter a valid choise please\n");
                printf("\033[0m");
             }
        }
    }else{
        return;
    }

    return;
}


