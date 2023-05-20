#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
//#include<conio.h>

struct customer
{
    char custName[20],phone[20],message[256];

}customer;


void CreateReport()
{
    FILE *ptr = fopen("Files/report.txt", "a");

    if (ptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nWELCOME TO THE CREATE A REPORT MENU");
    printf("\n-----------------------------------");

    printf("\nEnter the title of the report: ");
    char title[100];
    fgets(title, sizeof(title), stdin);

    printf("Enter the author of the report: ");
    char author[100];
    fgets(author, sizeof(author), stdin);

    printf("Enter the content of the report: ");
    char content[1000];
    fgets(content, sizeof(content), stdin);

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[100];
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", t);

    fprintf(ptr, "\nDate: %s\nTitle: %sAuthor: %sContent: %s\n", date, title, author, content);

    fclose(ptr);
}

void ViewReport()
{
    FILE *ptr = fopen("Files/report.txt", "r");

    if (ptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nLIST OF REPORTS:");
    printf("\n----------------");

    char line[1000];
    while (fgets(line, sizeof(line), ptr) != NULL) {
        printf("%s", line);
    }

    fclose(ptr);
}

void SearchReportByDate()
{
    FILE *ptr = fopen("Files/report.txt", "r");

    if (ptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nSEARCH REPORT BY DATE:");
    printf("\n----------------------");

    char search_date[100];
    printf("\nEnter the date in YYYY-MM-DD format: ");
    fgets(search_date, sizeof(search_date), stdin);

    char line[1000];
    int found = 0;

    while (fgets(line, sizeof(line), ptr) != NULL) {
        if (strstr(line, search_date) != NULL) {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found) {
        printf("No reports found for the given date.\n");
    }

    fclose(ptr);
}

void DeleteReport()
{
    FILE *ptr, *temp;
    ptr = fopen("Files/report.txt", "r");
    temp = fopen("Files/temp.txt", "w");
    if (ptr == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char title[100];
    printf("Enter the title of the report you want to delete: ");
    fgets(title, sizeof(title), stdin);

    int found = 0;
    char line[1000];
    while (fgets(line, sizeof(line), ptr)) {
        if (strstr(line, title) == NULL) {
            fputs(line, temp);
        } else {
            found = 1;
        }
    }

    fclose(ptr);
    fclose(temp);
    remove("Files/report.txt");
    rename("Files/temp.txt", "report.txt");

    if (found) {
        printf("Report '%s' has been deleted.\n", title);
    } else {
        printf("Report '%s' was not found.\n", title);
    }
}
/*void DisplayCustInfo()
{
    FILE *ptr;
    ptr=fopen("Files/cust.txt","r");

    if (ptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nWELCOME TO THE DISPLAY CUSTOMER INFORMATION MENU");
    printf("\n------------------------------------------------\n");

    printf("\nEnter the customer ID: ");
    int search_id;
    scanf("%d", &search_id);

    int found = 0;
    while (fscanf(ptr, "%d\t%s\t%s\t%s", &customer.id2, customer.custName, customer.userName, customer.pw2) != EOF) {
        if (customer.id2 == search_id) {
            printf("\nCustomer ID: %d", customer.id2);
            printf("\nCustomer Name: %s", customer.custName);
            printf("\nUsername: %s", customer.userName);
            printf("\nPassword: %s", customer.pw2);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nCustomer not found.");
    }

    fclose(ptr);
}*/

//char custName[20],phone[20],message[256];
void DisplayRequests()
{
    FILE *ptr = fopen("Files/Customer-Messages.txt", "r");
//remember to create a file called requests.txt to avoid the program crashing
    if (ptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nLIST OF CUSTOMER REQUESTS:");
    printf("\n--------------------------\n");
    char line[400];
    while (!feof(ptr))
    {
        fgets(line, 400, ptr);
        printf("%s\n", line);
    }

    fclose(ptr);
}
/*void AcceptRequest()
{
    FILE *ptr = fopen("Files/Customer-Messages.txt", "r+");
    if (ptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int id;
    printf("Enter the request ID to accept/deny: ");
    scanf("%d", &id);
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_CONTENT_LEN 1000
#define MAX_STATUS_LEN 20

    struct request //reqs;
{
    int id;
    char date[20];
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char content[MAX_CONTENT_LEN];
    char status[MAX_STATUS_LEN];
}reqs;

    int found = 0;
    while (fread(&reqs, sizeof(reqs), 1, ptr)) {
        if (reqs.id == id) {
            printf("Request found!\n");
            printf("Title: %s", reqs.title);
            printf("Author: %s", reqs.author);
            printf("Content: %s", reqs.content);

            printf("Do you want to accept or deny the request? (1 = accept, 0 = deny): ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                strcpy(reqs.status, "accepted");
            } else {
                strcpy(reqs.status, "denied");
            }

            fseek(ptr, -sizeof(reqs), SEEK_CUR);
            fwrite(&reqs, sizeof(reqs), 1, ptr);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Request not found!\n");
    } else {
        printf("Request updated successfully!\n");
    }

    fclose(ptr);
}*/

void useCustomerWorker() {
    printf("\e[1;1H\e[2J");
    sleep(1);
    FILE *fp;

    int choice;
    do {
        system("cls");
        printf("\nMAIN MENU\n");
        printf("1. Create Report\n");
        printf("2. View Report\n");
        printf("3. Search Report by Date\n");
        printf("4. Delete Report\n");
        //printf("5. Display Customer Info\n");
        printf("5. Display Requests\n");
        //printf("6. Accept/Deny Request\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                CreateReport();
                break;
            case 2:
                ViewReport();
                break;
            case 3:
                SearchReportByDate();
                break;
            case 4:
                DeleteReport();
                break;
            //case 5:
                //DisplayCustInfo();
                //break;
            case 5:
                DisplayRequests();
                break;
           // case 6:
               // AcceptRequest();
               // break;
            case 0:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

        printf("Press enter to continue...");
        getchar();
        system("cls");
    } while (choice != 0);

    return;
}


