#include<iostream>
#include<string>
#include "phoneUser.h"

       phoneUser::phoneUser()        // Default Constructor
        {
            number = new int;
            gmail = new std::string;
            name = new std::string;
        }

        phoneUser::phoneUser(std::string n, int r, std::string g)     // Parameterized Constructor
        {
            try
            {
                number = new int;
                gmail = new std::string;
                name = new std::string;
                *name = n;
                *gmail = g;
                *number = r;
                next=NULL;
                prev=NULL;
            }
            catch(...)
            {
                cout<<"\nError in constructing";
            }
    }

    phoneUser::phoneUser(const phoneUser& p1)          // Copy constructor
    {
        name = new std::string;
        *name = *(p1.name);
        gmail = new std::string;
        *gmail = *(p1.gmail);
        number = new int;
        *number = *(p1.number);
        prev = p1.prev;
        next = p1.next;
    }

    phoneUser& phoneUser::operator=(const phoneUser &p2)   // Assignment Operator
    {
        this->name = new std::string;
        *(this->name) = *(p2.name);
        this->gmail = new std::string;
        *(this->gmail) = *(p2.gmail);
        this->number = new int;
        *(this->number) = *(p2.number);
        return *this;
    }

    phoneUser::~phoneUser()        // Destructor
    {
        delete name, gmail, number, prev, next;
    }

