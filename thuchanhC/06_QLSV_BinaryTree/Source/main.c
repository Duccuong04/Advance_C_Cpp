#include <stdio.h>
#include "../Header/CSV_Reader.h"
#include "../Header/User_List.h"

int main() {
    
    Node *nameList = NULL;
    Node *phoneList = NULL;

    readCSV(DATABASE_PATH, &nameList, &phoneList);

   print_list(nameList, "Name List");
   print_list(phoneList, "Phone List");

  free_list(nameList);
  free_list(phoneList);

    return 0;
}
