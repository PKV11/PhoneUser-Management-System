#pragma once

#include<string>
#include "phoneList.h"
using namespace std;

class phoneUser
{
    private:

        int *number;
        string *gmail;
        string *name;
        phoneUser *prev,*next;

    public:

        phoneUser() ;       // Default Constructor
        phoneUser(string n, int r, string g) ;    // Parameterized Constructor
        phoneUser(const phoneUser& p1);          // Copy constructor
        phoneUser& operator=(const phoneUser &p2);   // Assignment Operator
        ~phoneUser();        // Destructor
	    friend class phoneList;  // Friend class needed to access private members of phoneUser in phoneList
                                 // Another alternative is to provide get & set methods so that values for private members can be set and used
};