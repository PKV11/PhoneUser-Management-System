
//Some Learnings: Pointer to Class members(Function), function overloading(constructor), copy constructor, assignment operator, Exception Handling, Memory Allocation
#include <iostream>
#include<string>
#include "phoneList.h"
#include "phoneUser.h"
using namespace std;

int main()
{
    string n;
    string nam;
    string name;
    int number;
    string gmail;

    phoneList d1;
    char ans;
    int ch,a;
    void(phoneList::*deleteUser)(string) = NULL;    // Function Pointer Declaration
    
    cout<<"**************                                PHONEBOOK                          ********************";
    cout<<"\n\nEnter Your Name: ";
    cin>>name;
    cout<<"\n\n****************   Welcome "<<name<<"   ****************\n\n";
    cout<<"\n\n\nLet's create User phonebook "<<name<<"  \n\n";
    d1.accept();
    //d1.sort();
    do
    {
    cout<<"\n\n\n\n1) Display Phonebook\n2) Insert New Contact\n3) Update Existing Contact Details\n4) Delete Contact\n5) Delete Re-Occuring Names\n6) Delete Re-Occuring Numbers\n7) Search\n";
    cin>>ch;
    switch(ch)
    {
    case 2:
    d1.insert();
   // d1.sort();
    break;
    
    case 1:
    // d1.sort();
    d1.display();
    break;
    case 3:
    
        cout<<"\n\nEnter target name: \n";
        cin>>n;
    d1.update(n);
    //d1.sort();
    break;
    case 4:
    cout<<"\nEnter target name: \n";
    cin>>name;
    deleteUser = &phoneList::deletecontact;
    (d1.*deleteUser)(n);
    break;
     case 5:
    d1.deletesamename();
    d1.display();
    break;
    case 6:
    d1.deletesamenumber();
    d1.display();
    break;
    case 7:
    do
    {
    cout<<"1.Search by name\n2.Search by number\n3.Search by gmail";
    cin>>a;
    switch(a)
    {
        case 1:
        cout<<"Enter target name\n";
        cin>>name;
        d1.searchbyname(name);
        break;
        case 2:
        cout<<"Enter target name\n";
        cin>>number;
        d1.searchbynumber(number);
        break;
        case 3:
        cout<<"Enter target name\n";
        cin>>gmail;
        d1.searchbygmail(gmail);
        break;
        default:cout<<"\nIncorrect Input\n";
    }
    cout<<"o you want to continue searching?";
    cin>>ans;
}while(ans=='y');

    break;
    case 8:d1.deletesamegmail();
    d1.display();
    break;
    default:cout<<"\nIncorrect Input\n";
    }
    cout<<"\n\nDo you want to continue operations?";
    cin>>ans;
}while(ans=='y');
return 0;
}
