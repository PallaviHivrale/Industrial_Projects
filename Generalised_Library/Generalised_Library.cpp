//////////////////////////////////////////////////////////////////////
//   Generalized data structure Library
//////////////////////////////////////////////////////////////////////

/*
-----------------------------------------------------------------------------------------------
    Type                      Name of class for node           Name of class for functionality
-----------------------------------------------------------------------------------------------
    Singly Linear              SinglyLLLnode                       SinglyLLL        Done
    Singly circular            SinglyCLLnode                       SinglyCLL        Done
    Doubly linear              DoublyLLLnode                       DoublyLLL        Done
    Doubly Circular            DoublyCLLnode                       DoublyCLL        Done
-----------------------------------------------------------------------------------------------
*/

#include<iostream>                              
using namespace std;

//////////////////////////////////////////////////////////////////////
//          singly linear linked list using generic approach
//////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at Last position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Delete node at first position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Delete node at last position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Display all the nodes of Linked List
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Count the all the node of Linked List
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> ::Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtpos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at specific position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Delete node at specific position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////
//           doubly linear linked list using generic approach
//////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode<T> *next;
        DoublyLLLnode<T> *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> *first;
        int iCount;

     public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> ::DoublyLLL()
{
    cout<<"Linked list gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>  ::  InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first  = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at Last position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>  :: InsertLast(T  no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at specific position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>  ::  InsertAtPos(T  no, int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    DoublyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if((pos<1) || (pos>this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>  ::  DeleteFirst()
{

    if(this->first == NULL)                 
    {
        return;
    }
    else if(this->first->next == NULL)     
    {
        delete this->first;
        this->first = NULL;
    }
    else                                 
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at Last position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>  ::  DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                 
    {
        return;
    }
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    
    {  
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp ->next;
        temp->next = NULL;
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete the node at specific position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>  ::  DeleteAtPos(int pos)
{
    DoublyLLLnode<T> * temp = NULL;

    int iCnt = 0;

    if((pos<1) || (pos>this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Display nodes
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>  ::  Display()
{
    DoublyLLLnode<T> * temp = NULL;
     
    temp = this->first;
    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to count the nodes
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T>  :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//  Singly Circular Linked List using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;

    public:
        SinglyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Linked list gets created\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
        last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
        this->last->next = this->first;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at Last position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);
    
    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
        this->last->next = this->first;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
        this->last->next = first;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    SinglyCLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete temp;

        this->last->next = this->first;
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at Last position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete this->last;
        this->last = temp;
        
        this->last->next = this->first;
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Display the nodes 
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::Display()
{
    SinglyCLLnode<T> * temp = NULL;

    temp = this->first;

     if (first == NULL)
     {
        return;
     }   

    do
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    } while (temp != first);

}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Count the nodes
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>::Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at specific position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

   
    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);
        temp = this->first;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        
        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at specific position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////
//   Doubly circular linked list using generic approach
//////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode *next;
        DoublyCLLnode *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

     public:
        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyCLL<T> ::DoublyCLL()
{
    cout<<"Linked list gets created\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>  ::  InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first  = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at Last position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>  :: InsertLast(T  no)
{
    DoublyCLLnode<T> *newn = NULL;
    newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at specific position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>  ::  InsertAtPos(T  no, int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    DoublyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if((pos<1) || (pos>this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>  ::  DeleteFirst()
{

    if(this->first == NULL && this->last == NULL)                 
    {
        return;
    }
    else if(this->first == this->last)      
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else                                    
    {
        this->first = this->first->next;
        delete this->first->prev;

        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at Last position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>  ::  DeleteLast()
{
    DoublyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)                 
    {
        return;
    }
    else if(this->first == this->last)      
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else                                    
    {
        this->last = this->last->prev;
        delete this->last->next;
        
        this->last->next = this->first;
        this->first->prev = this->last;
       
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at specific position
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>  ::  DeleteAtPos(int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    DoublyCLLnode<T> *target = NULL;

    int iCnt = 0;

    if((pos<1) || (pos>this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else                
    {
        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        delete target;

        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Display all nodes 
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>  ::  Display()
{
    DoublyCLLnode<T> * temp = NULL;
    temp = this->first;


    if(this->first == NULL)   
    {
        cout << "Linked List is empty\n";
        return;
    }
    cout<<"\nNULL<=>";

    do
    {
        cout << " | " << temp->data << " |<=>";
        temp = temp->next;
    } while(temp != this->first);

}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Count the nodes
//  Author :            Pallavi Kishanrao Hivrale
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>  :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//                  Stack using Generic Approach
///////////////////////////////////////////////////////////////////////


#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();

        void push(T);     
        T pop();
        T peep();
        void Display();
        int Count();
};

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created succesfully...\n";

    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}   

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;    
    return Value;
}

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Queue using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        
        int iCount;

    public:
        Queue();

        void enqueue(T);          
        T dequeue();              
        void Display();
        int Count();
};

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created succesfully...\n";

    this->first = NULL;
    this->last = NULL;

    this->iCount = 0;
}

template <class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }

    this->iCount++;
}

template <class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }

    cout<<"\n";
}

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}


//////////////////////////////////////////////////////////// End Of Library /////////////////////////////////////////////////

int main()
{

    cout<<"\n";
    cout<<"------------Singly Linear Linked List-----------------------\n\n";

    SinglyLLL<int> *sobj1 = new SinglyLLL<int>();

    int iRet = 0;

    sobj1->InsertFirst(51);
    sobj1->InsertFirst(21);
    sobj1->InsertFirst(11);

    sobj1->Display();

    iRet = sobj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj1->InsertLast(101);
    sobj1->InsertLast(111);
    sobj1->InsertLast(121);

    sobj1->Display();

    iRet = sobj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj1->DeleteFirst();
    sobj1->Display();

    iRet = sobj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj1->DeleteLast();

    sobj1->Display();

    iRet = sobj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj1->InsertAtPos(105,4);

    sobj1->Display();

    iRet = sobj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj1->DeleteAtPos(4);

    sobj1->Display();

    iRet = sobj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    ////////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n------------Doubly Linear Linked List-----------------------\n\n";

    DoublyLLL<char>  *dobj1 = new DoublyLLL<char>();

    dobj1->InsertFirst('A');
    dobj1->InsertFirst('B');
    dobj1->InsertFirst('C');

    dobj1->Display();

    cout<<"Number of elements are : "<<dobj1->Count()<<"\n";

    dobj1->InsertLast('X');
    dobj1->InsertLast('Y');
    dobj1->InsertLast('Z');

    dobj1->Display();

    cout<<"Number of elements are : "<<dobj1->Count()<<"\n";

    dobj1->DeleteFirst();

    dobj1->Display();

    cout<<"Number of elements are : "<<dobj1->Count()<<"\n";

    dobj1->DeleteLast();

    dobj1->Display();

    cout<<"Number of elements are : "<<dobj1->Count()<<"\n";

    dobj1->InsertAtPos('$',4);

    dobj1->Display();

    cout<<"Number of elements are : "<<dobj1->Count()<<"\n";

    dobj1->DeleteAtPos(4);

    dobj1->Display();

    cout<<"Number of elements are : "<<dobj1->Count()<<"\n";
    
    ////////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n------------Singly Circuler Linked List-----------------------\n\n";

    SinglyCLL<int> *sobj2 = new SinglyCLL<int>();

    sobj2->InsertFirst(51);
    sobj2->InsertFirst(21);
    sobj2->InsertFirst(11);

    sobj2->Display();
    cout<<"Number of elements are: "<<sobj2->Count()<<"\n";

    sobj2->InsertLast(101);
    sobj2->InsertLast(111);
    sobj2->InsertLast(121);

    sobj2->Display();
    cout<<"Number of elements are: "<<sobj2->Count()<<"\n";

    sobj2->DeleteFirst();

    sobj2->Display();
    cout << "Number of elements are: " << sobj2->Count() << "\n";

    sobj2->DeleteLast();

    sobj2->Display();
    cout << "Number of elements are: " << sobj2->Count() << "\n";

    sobj2->InsertAtPos(105,3);
    sobj2->Display();
    cout << "Number of elements are: " << sobj2->Count() << "\n";

    sobj2->DeleteAtPos(3);
    sobj2->Display();
    cout << "Number of elements are: " << sobj2->Count() << "\n";

    ////////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n------------Doubly Circuler Linked List-----------------------\n\n";

    DoublyCLL<char>  *dobj2 = new DoublyCLL<char>();

    dobj2->InsertFirst('A');
    dobj2->InsertFirst('B');
    dobj2->InsertFirst('C');

    dobj2->Display();

    cout<<"Number of elements are : "<<dobj2->Count()<<"\n";

    dobj2->InsertLast('X');
    dobj2->InsertLast('Y');
    dobj2->InsertLast('Z');

    dobj2->Display();

    cout<<"Number of elements are : "<<dobj2->Count()<<"\n";

    dobj2->DeleteFirst();

    dobj2->Display();

    cout<<"Number of elements are : "<<dobj2->Count()<<"\n";

    dobj2->DeleteLast();

    dobj2->Display();

    cout<<"Number of elements are : "<<dobj2->Count()<<"\n";

    dobj2->InsertAtPos('$',4);

    dobj2->Display();

    cout<<"Number of elements are : "<<dobj2->Count()<<"\n";

    dobj2->DeleteAtPos(4);

    dobj2->Display();

    cout<<"Number of elements are : "<<dobj2->Count()<<"\n";

    delete sobj1;
    delete dobj1;
    delete sobj2;
    delete dobj2;

    ///////////////////////////////////////////////////////////////
    cout<<"\n------------------------Stack-------------------------\n\n";

    Stack<char> *sobj = new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');
    
    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Return value of peep is : "<<sobj->peep()<<"\n";

    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Poped element is : "<<sobj->pop()<<"\n";
    
    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Poped element is : "<<sobj->pop()<<"\n";
    
    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    sobj->push('e');

    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    delete sobj;
    
    ///////////////////////////////////////////////////////////////////

    cout<<"\n------------------------Queue-------------------------\n\n";

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);

    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
}