#ifndef SYSTEM_H
#define SYSTEM_H

#define MAX_RECORDS 4

typedef struct studentRecord
{
    int id;
    char *name;
    int year;
    char *password;
}studentRecord_t;

int add_record(char *name,int year,char *password);
/*
 * Return type: - 0 if system storage is full.
                - New student id if added successfully.
 * Description: Adds new student record to the system.
 * Complexity: O(n)
*/

int edit_name(int id,char *name);
int edit_year(int id,int year);
int edit_password(int id,char *password);
/*
 * Return type: - 0 if id does not exist.
                - -1 if id is out of bound.
                - 1 if edited successfully.
 * Description: Edits student record.
 * Complexity: O(1)
*/

int remove_record(int id);
/*
 * Return type: - 0 if id does not exist.
                - -1 if id is out of bound.
                - 1 if removed successfully.
 * Description: Edits student record.
 * Complexity: O(1)
*/

int view_record(int id,void (*display)(studentRecord_t));
/*
 * Return type: - 0 if id does not exist.
                - -1 if id is out of bound.
                - 1 if viewed successfully.
 * Description: Passing student record of id to display function pointer.
 * Complexity: O(1)
*/

void traverse_records(void(*display)(studentRecord_t));
/*
 * Return type: - 0 if id does not exist.
                - -1 if id is out of bound.
                - 1 if viewed successfully.
 * Description: Passing student records to display function pointer.
 * Complexity: O(n)
*/

int set_admin_password(char *oldPassword, char *newPassword);
/*
 * Return type: - 0 if password is wrong.
                - 1 if password is correct and admin password has been set.
 * Description: Edits admin password.
 * Complexity: O(1)
*/

int check_admin_password(char *password);
/*
 * Return type: - 0 if password is wrong.
                - 1 if password is correct.
 * Description: check the correctness of admin password.
 * Complexity: O(1)
*/

int check_user_password(int id, char *password);
/*
 * Return type: - 0 if password is wrong.
                - 1 if password is correct.
                - -1 if id is out of bound or not existed.
 * Description: check the correctness of user password.
 * Complexity: O(1)
*/



#endif
