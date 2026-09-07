#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "validation.h"  

/* Menu Driven functions */

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
   
	// Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

/* 1. create contacts */

void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */

     if(addressBook->contactCount >= MAX_CONTACTS) 
     {
        printf("\nError: Address Book array storage limit reached!\n");
        return;
    }

    char temp_name[50];
    char temp_phone[20];
    char temp_email[50];

    printf("\n *** Create contact ***\n");
    
    // Validate Name
    printf("Enter name: ");
    scanf(" %[^\n]", temp_name);
    
    if(!valid_name(temp_name)) 
    {
        printf("Invalid name format! Use alphabets and spaces only.\n");
        return;
    }
    else
    {
        strcpy(addressBook->contacts[addressBook->contactCount].name, temp_name);
    }

    // Validate Phone
    printf("Enter 10-digit number: ");
    scanf(" %s", temp_phone);
    if (!valid_phone(temp_phone, addressBook)) {
        printf("Invalid number entry or number already exists!\n");
        return;
    }
    else
    {
        strcpy(addressBook->contacts[addressBook->contactCount].phone, temp_phone);
    }

    // Validate Email
    printf("Enter email: ");
    scanf(" %s", temp_email);
    if (!valid_email(temp_email, addressBook)) {
        printf("Invalid email entry or email already exists!\n");
        return;
    }
    else
    {
        strcpy(addressBook->contacts[addressBook->contactCount].email, temp_email);
    }
    addressBook -> contactCount++;    

    printf("Success: Contact added.!\n");
} 

// end of create contacts function


/* 2. search contacts */

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice;
    printf("\n");
    printf("*** Search contacts ***\n ");
    printf("1. Search by Name\n ");
    printf("2. Search by Number\n ");
    printf("3. Search by Email\n ");
    printf("\n");
    printf("Enter your choice for searching: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1 :  // search by name
                 
            char name[50];
            printf("Enter the name to search : ");
            scanf(" %[^\n]", name);

            for(int i = 0; i < addressBook ->contactCount; i++)
            {
                if(strcmp(name, addressBook -> contacts[i].name) == 0)
                {
                    printf("Found -> Contact %d: %s | %s | %s\n", i+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    return i;
                }
            }
            break;
            /* end of case 1 */

        case 2 : // search by number
            char num[20];
            printf("Enter the number to search : ");
            scanf(" %s", num);

            for(int i = 0; i < addressBook ->contactCount; i++)
            {
                if(strcmp(num, addressBook -> contacts[i].phone) == 0)
                {
                    printf("Found -> Contact %d: %s | %s | %s\n", i+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    return i;                
                }
            }
            break;
            /* end of case 2 */

        case 3 :  // search by email
            char email[50];
            printf("Enter the email to search : ");
            scanf(" %[^\n]", email);

            for(int i = 0; i < addressBook ->contactCount; i++)
            {
                if(strcmp(email, addressBook -> contacts[i].email) == 0)
                {
                    printf("Found -> Contact %d: %s | %s | %s\n", i+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    return i;
                }
            }
            break;

        default : printf("Invalid menu choice. please enter correct choice\n"); 
    }
    printf("\n\nSystem Notification: Profile search record not available...\n");
    return -1;
}                 /* end of case 3 */


/* 3. Edit contacts */

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int ret = searchContact(addressBook);
    if (ret == -1) return;
    
    printf("\n");
    printf("*** Edit contacts ***\n ");
    printf("1. Modify Name\n ");
    printf("2. Modify Number\n ");
    printf("3. Modify Email\n ");
    printf("\n");
    printf("Enter your choice for modification: ");
    int choice = 0;
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1 :  // edit by name

            char name[50];
            printf("\n");
            printf("Enter the name to be modifed:");
            scanf(" %[^\n]", name);

            /*  validation code */

            if (valid_name(name))
            {
                strcpy(addressBook -> contacts[ret].name, name);
                printf("Name updated successfully.\n");
            } 
            else 
            {
                printf("Verification Alert: invalid characters. update failed.\n");
            }
            break;

        case 2 :  // edit by Phone

            char phone[20];
            printf("\n");
            printf("Enter the number to modify :");
            scanf(" %[^\n]", phone);

            /*  validation code */

            if(valid_phone(phone, addressBook)) 
            {
                strcpy(addressBook->contacts[ret].phone, phone);
                printf("Phone number updated successfully.\n");
            } 
            else 
            {
                printf("Verification Alert: update failed. please try after some time.\n");
            }
            break;
    
        case 3 :  // edit by email

            char email[50];
            printf("\n");
            printf("Enter the email to modify:");
            scanf(" %[^\n]", email);

            /*  validation code */

                if(valid_phone(email, addressBook)) 
                {
                    strcpy(addressBook->contacts[ret].email, email);
                    printf("Email updated successfully.\n");
                } 
                else
                {
                    printf("Verification Alert: update failed. please try after some time.\n");
                }
                break;

        default :   printf("Update failed. try after some time.\n ");
                    break;
    }
    printf(" -- updated Details --\n");
    printf("Name: %s, Phone: %s, Email: %s\n", addressBook -> contacts[ret].name, addressBook -> contacts[ret].phone, addressBook -> contacts[ret].email);

}  // end of EDIT function

/* 4. Delete contacts */

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */

    int ret = searchContact(addressBook);
        if (ret == -1) return;

    
    for(int i = ret; i < addressBook -> contactCount; i++)
    {
        addressBook -> contacts[i] = addressBook -> contacts[i + 1];
    }
    addressBook -> contactCount--;

    printf("Operation Completed: record safely deleted.\n");

} // end of EDIT function

/* 5. Lis all contacts */

void listContacts(AddressBook *addressBook) 
{
    if(addressBook->contactCount == 0) 
    {
        printf("\nSystem State Alert: Active database is empty.\n");
        return;
    }
    // Sort contacts based on the chosen criteria
    printf("\n *** List contacts ***\n ");
    printf("1. Sort by Name\n ");
    printf("2. Sort by Number\n ");
    printf("3. Sort by Email\n ");
    printf("\n");
    
    int sortchoice;
    printf("Enter your choice for sorting: ");
    scanf("%d", &sortchoice);
    printf("\n");

    switch(sortchoice)
    {
        case 1 :

            for(int i = 0; i <= addressBook -> contactCount - 1; i++)
            {
                for(int j = i + 1; j < addressBook -> contactCount; j++)
                {
                    if(strcmp(addressBook -> contacts[i].name, addressBook -> contacts[j].name) > 0)
                    {
                        Contact temp = addressBook -> contacts[i];
                        addressBook -> contacts[i] = addressBook -> contacts[j];
                        addressBook -> contacts[j] = temp; 
                    }
                }
            }
            break;
        
        case 2 :

            for(int i = 0; i <= addressBook -> contactCount - 1; i++)
            {
                for(int j = i + 1; j < addressBook -> contactCount; j++)
                {
                    if(strcmp(addressBook -> contacts[i].phone, addressBook -> contacts[j].phone) > 0)
                    {
                        Contact temp = addressBook -> contacts[i];
                        addressBook -> contacts[i] = addressBook -> contacts[j];
                        addressBook -> contacts[j] = temp; 
                    }
                }
            } break;
            
        case 3 :

            for(int i = 0; i <= addressBook -> contactCount - 1; i++)
            {
                for(int j = i + 1; j < addressBook -> contactCount; j++)
                {
                    if(strcmp(addressBook -> contacts[i].email, addressBook -> contacts[j].email) > 0)
                    {
                        Contact temp = addressBook -> contacts[i];
                        addressBook -> contacts[i] = addressBook -> contacts[j];
                        addressBook -> contacts[j] = temp; 
                    }
                }
            } break;
        
        default :   printf("Invalid choice. please enter correct choice and try again after some time.\n");
    }
    
    printf("\n");

    printf("\n--- Core Directory Profiles ---\n");

    for(int i = 0; i < addressBook -> contactCount; i++)
    {
        printf("%d. Name: %-20s | Phone: %-12s | Email: %-25s\n",i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        printf("\n");
    }
}

/* 6. Save and exit contacts */

void saveAndExit(AddressBook *addressBook)
{
    char confirm;
    
    printf("\nAre you sure you want to save changes and exit? (y/n): ");
    scanf(" %c", &confirm);
    
    if (confirm == 'y' || confirm == 'Y')
    {
        printf("Syncing records... Please do not close the terminal.\n");
        saveContactsToFile(addressBook);

        printf("All changes safely saved. Goodbye!\n");
        exit(EXIT_SUCCESS);
    }
     else
     {
        printf("Exit canceled. Returning to Menu.\n");
     }
}

/*  END of MENU driven functions */
