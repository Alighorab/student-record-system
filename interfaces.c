#include "interfaces.h"
#include <stdlib.h>
#include <string.h>

#define safeFree(p) saferFree((void**)&(p))

static studentRecord_t records[MAX_RECORDS];
static char *adminPassword;
static int next_id;

static int generate_id(void)
{
    if (next_id > MAX_RECORDS - 1)
    {
        int i;
        for (i = 0; i < MAX_RECORDS; ++i)
        {
            if (records[i].name == NULL)
                return i;
        }
    }
    else
        return next_id;

    return -1;
}

void saferFree(void **pp)
{
    if (pp != NULL && *pp != NULL) {
        free(*pp);
        *pp = NULL;
    }
}

int add_record(char *name, int year, char *password)
{
    int current_id = generate_id();
    if(current_id == -1)
        return -1;

    records[current_id].name = (char*)malloc(strlen(name)+1);
    strcpy(records[current_id].name,name);

    records[current_id].year = year;

    records[current_id].password = (char*)malloc(strlen(password)+1);
    strcpy(records[current_id].password,password);

    next_id++;
    return current_id;
}

int edit_name(int id, char *name)
{
    if (records[id].name == NULL)
        return 0;
    else if (id < 0)
        return -1;

    safeFree(records[id].name);
    records[id].name = (char*)malloc(strlen(name)+1);
    strcpy(records[id].name,name);
    return 1;
}

int edit_year(int id,int year)
{
    if (records[id].name == NULL)
        return 0;
    else if (id < 0)
        return -1;

    records[id].year = year;
    return 1;
}

int edit_password(int id, char *password)
{
    if (records[id].name == NULL)
        return 0;
    else if (id < 0)
        return -1;

    safeFree(records[id].password);
    records[id].password = (char*)malloc(strlen(password)+1);
    strcpy(records[id].password,password);
}

int remove_record(int id)
{
    if (records[id].name == NULL)
        return 0;
    else if (id < 0)
        return -1;

    safeFree(records[id].name);
    safeFree(records[id].password);
    return 1;
}

int view_record(int id,void (*display)(studentRecord_t))
{
    if (records[id].name == NULL)
        return 0;
    else if (id < 0)
        return -1;

    display(records[id]);
    return 1;
}

void traverse_records(void(*display)(studentRecord_t))
{
    int i;
    studentRecord_t temp;
    for (i = 0; i < MAX_RECORDS; ++i)
    {
        if (records[i].name == NULL)
            continue;
        view_record(i,display);
    }
}

int check_admin_password(char *password)
{
    if (EQ(adminPassword,password))
    {
        return 1;
    }
    return 0;
}

int set_admin_password(char *oldPassword, char *newPassword)
{
    if(adminPassword == NULL)
    {
        adminPassword = (char*)malloc(strlen(newPassword)+1);
        strcpy(adminPassword,newPassword);
        return 1;
    }
    else if(strcmp(oldPassword,newPassword) == 0)
    {
        safeFree(adminPassword);
        adminPassword = (char*)malloc(strlen(newPassword)+1);
        strcpy(adminPassword,newPassword);
        return 1;
    }
    return 0;
}

int check_user_password(int id, char *password)
{
    if (records[id].name == NULL || id < 0)
        return -1;
    else if (EQ(records[id].password,password))
        return 1;
    return 0;
}

