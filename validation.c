#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h" 
#include "validation.h"


/* add all your functions here */




/* Validation function */

/* ==========================================
   VALIDATION LOGIC IMPLEMENTATIONS
   ========================================== */

// Checks if name contains only letters and internal spaces
int valid_name(const char name[])   
{
    int i = 0;
    int len = strlen(name);
    if(len == 0) return 0;

    // Reject names starting or ending with spaces
    if (isspace(name[0]) || isspace(name[len - 1])) return 0;

    while(name[i] != '\0')
    {
        if(!isalpha(name[i]) && !isspace(name[i]))
        {
            return 0; // Invalid character found
        } 
        i++;
    }
    return 1;  
}

// Checks if phone number is exactly 10 digits and completely unique
int valid_phone(const char phone[], AddressBook *addressBook) 
{
    if(strlen(phone) != 10) return 0;  

    for(int i = 0; i < addressBook -> contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].phone, phone) == 0)
        {
            printf("Error: Duplicate phone number found.\n");
            return 0;
        }
    }

    if(phone[0] < '2' || phone[0] > '9')
    {
        printf("Error: Mobile numbers cannot begin with 0 or 1.\n");
        return 0;
    }

    // Check if all characters are identical (spam protection)
    int identical = 1;
    for(int i = 1; i < 10; i++)
    {
        if(!isdigit((unsigned char)phone[i])) return 0;

        if (phone[i] != phone[0]) identical = 0;
    }
    if(identical)
    {
        printf("Error: Invalid repeated character sequence.\n");
        return 0;
    }

    // Reject if any 3 numbers in a row are identical
    if(has_three_consecutive_same(phone))
    {
        printf("Error: Input contains 3 consecutive identical digits.\n");
        return 0;
    }

    return 1;
}


int has_three_consecutive_same(const char str[])
{
    int len = strlen(str);
    if (len < 3) return 0; // Too short to have 3 identical characters

    for (int i = 0; i < len - 2; i++) 
    {
        if (str[i] == str[i + 1] && str[i] == str[i + 2]) 
        {
            return 1; // Match found!
        }
    }
    return 0; // No 3 consecutive identical characters found
}
 

// Custom parser verifying strict email format rules and uniqueness
int valid_email(const char email[], AddressBook *addressBook)  
{
    int at_index = -1;
    int dot_index = -1;
    int len = strlen(email);

    if(len == 0) return 0;

    for(int i = 0; i < len; i++)
    {
        if(isspace(email[i])) return 0;  // Email cannot have spaces
        if(isupper(email[i])) return 0;  // Standardizing to lower case only

        if(email[i] == '@') {
            if (at_index != -1) return 0; // Reject multiple '@' symbols
            at_index = i;
        }
        if(email[i] == '.') {
            dot_index = i; // Track the last dot position
        }
    }

    // Rule: Must contain '@', a '.' after '@', and at least 2 chars for domain extension (e.g., .com)
    if(at_index < 1 || dot_index <= at_index + 1 || dot_index >= len - 2)   
    {
        return 0;
    }

    // Verify uniqueness
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].email, email) == 0)
        {
            printf("Error: Duplicate email address found.\n");
            return 0;
        }
    }
    return 1;
}

/* End of validation function */

