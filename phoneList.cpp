#include<iostream>
#include<string>
#include "phoneList.h"

using namespace std;
    
phoneList::phoneList()
{
    head=NULL;
    temp=NULL;
    ptr=NULL;
    ptr1=NULL;
    ptr2=NULL;
    dup=NULL;
}


void phoneList::accept()
{
    int number;
    string gmail;
    string name;
    char ans;
      do
        {
    cout<<"Enter Contact Name : ";
    cin>>name;
    cout<<"Enter Contact Number :";
    cin>>number;
    cout<<"Enter Contact G-Mail :";
    try
    {
    cin>>gmail;
    }
    catch(...)
    {
        cout<<"\nError";
    }
    try
    {
    temp=new phoneUser(name,number,gmail);
    }
    
    catch(...)
    {
        cout<<"\nError in constructing";
    }
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
       ptr=head;
		while(ptr->next!=NULL)
		{
    ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
    }
	    cout<<"Do you want to continue(y/n)?";
    cin>>ans;
}while(ans=='y');

}

void phoneList::display()
{
    ptr=head;
	while(ptr!=NULL)
	{
			cout<<"\n\nName ::\t"<<ptr->name;
			cout<<"\nNumber ::\t+91-"<<ptr->number;
			cout<<"\nG-Mail ::\t"<<ptr->gmail;
			ptr=ptr->next;
	}
}

void phoneList::insert()
    {
        accept();
    }

/*void phoneList::sort()
    {
        phoneBook *i,*j;
        int temp, pos;
        string n;
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=strcmp(i->name,j->name);
                if(temp>0)
                {
                   strcpy(n,i->name);
                   strcpy(i->name,j->name);
                   strcpy(j->name,n);
                }
            }
        }
     
    }

    */

void phoneList::deletecontact(string s)
    {
        int c=0;
        ptr=head;
        while(ptr!=NULL)
        {
            if(s == *(ptr->name))
            {
                c=1;
                break;
            }
            else
            {
                c=2;
            }
            ptr=ptr->next;
        }
        if(c==1 && ptr!=head && ptr->next!=NULL)
        {
            ptr->prev->next=ptr->next;
           ptr->next->prev=ptr->prev;
           delete(ptr);
           ptr = NULL;
           cout<<"Contact deleted successfully\n\n";
        }
        else if(c==1 && ptr==head)
        {
            head=head->next;
            head->prev=NULL;
            delete(ptr);
            ptr = NULL;
           cout<<"Contact deleted successfully\n\n";
        }
        else if(c==1 && ptr->next==NULL)
        {
            ptr->prev->next=NULL;
            ptr->prev=NULL;
            delete(ptr);
            ptr = NULL;
           cout<<"Contact deleted successfully\n\n";
        }
        if(c==2)
        {
            cout<<"Name is not in Phonebook";
        }
    }

void phoneList::deletesamename()
    {
        ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        { 
            if (*(ptr1->name) == *(ptr2->next->name))
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
                dup = NULL;
            } 
            else
            {
                ptr2 = ptr2->next; 
        }
        }
        ptr1 = ptr1->next; 
    } 
    }
void phoneList::deletesamegmail()
    {
        ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        { 
            if (*(ptr1->gmail) == *(ptr2->next->gmail))
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
                dup = NULL;
            } 
            else
            {
                ptr2 = ptr2->next; 
        }
        }
        ptr1 = ptr1->next; 
    } 
    }
void phoneList::deletesamenumber()
    {
     ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        { 
            if (*(ptr1->number) == *(ptr2->next->number))
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else
            {
                ptr2 = ptr2->next; 
        }
        }
        ptr1 = ptr1->next; 
    }    
    }
void phoneList::searchbyname(string na)
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(na == *(ptr->name))
            {
                cout<<"Name Found"<<endl;
                cout<<"Contact Details:\n"<<endl;
        	cout<<"\n\nName ::\t"<<ptr->name;
			cout<<"\nNumber ::\t+91-"<<ptr->number;
			cout<<"\nG-Mail ::\t"<<ptr->gmail;
		        
            }
            ptr=ptr->next;
        }
    }
void phoneList::searchbynumber(int num)
    {
     ptr=head;
        while(ptr!=NULL)
        {
            if(num == *(ptr->number))
            {
                cout<<"Number Found\n"<<endl;
                cout<<"Contact Details:\n"<<endl;
        	cout<<"\n\nName ::\t"<<ptr->name;
			cout<<"\nNumber ::\t+91-"<<ptr->number;
			cout<<"\nG-Mail ::\t"<<ptr->gmail;
		        
            }
            ptr=ptr->next;
        }   
    }
void phoneList::searchbygmail(string gm)
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(gm == *(ptr->gmail))
            {
                cout<<"G-Mail Found\n"<<endl;
                cout<<"Contact Details:\n"<<endl;
        	cout<<"\n\nName ::\t"<<ptr->name;
			cout<<"\nNumber ::\t+91-"<<ptr->number;
			cout<<"\nG-Mail ::\t"<<ptr->gmail;
		        
            }
            ptr=ptr->next;
        }
    }
void phoneList::update(string n)
    {
        char ans;
        int c;
        ptr=head;
        while(ptr!=NULL)
        {
            if(n == *(ptr->name))
            {
                
                do
                {
                    cout<<"\nWhat do you want to Update?\n1.Name\n2.Phone Number\n3.G-Mail\n";
                cin>>c;
                switch(c)
                {
                    case 1:
                    cout<<"Enter new name: ";
                    cin>>*(ptr->name);
                    break;
                    case 2:
                    cout<<"Enter new phone number: ";
                    cin>>*(ptr->number);
                    break;
                    case 3:
                    cout<<"Enter new gmail: ";
                    cin>>*(ptr->gmail);
                    break;
                }
                cout<<"Do you want to continue updating?";
                cin>>ans;
                }while(ans=='y');
            }
            ptr=ptr->next;
        }
    }