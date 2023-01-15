#pragma once

#include<string>
#include "phoneUser.h"
using namespace std;

class phoneUser;
class phoneList
{
    private:
    phoneUser *head,*temp,*ptr;   
    phoneUser *ptr1, *ptr2, *dup;
    phoneUser *prevn;

    public:
    phoneList();        
    void insert();
    //void sort();
    void deletecontact(string n);
    void deletesamenumber();
    void deletesamename();
    void deletesamegmail();
    void searchbyname(string p);
    void searchbynumber(int n);
    void searchbygmail(string g);
    void accept();
    void display();
    void update(string ch);   

};