#ifndef VALIDATION_H
#define VALIDATION_H

#include "contact.h" // 

// Forward declaration of AddressBook structure to prevent circular dependency
  // typedef struct AddressBook AddressBook;

/* Core validation utilities */

int has_three_consecutive_same(const char str[]);
int valid_name(const char name[]);
int valid_phone(const char phone[], AddressBook *addressBook);
int valid_email(const char email[], AddressBook *addressBook);

#endif
