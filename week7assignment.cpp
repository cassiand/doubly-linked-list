// Cassian
// 10/23/22
// week 7 assignment
// creating a doubly linked list with a menu 


#include <iostream>
using namespace std;

class Link
{
public:
    double dData;                   
    Link* pNext;                    // ptr to next link
    Link* pPrevious;                // ptr to previous link in list
public:
    
    Link(double dd) :                  //constructor
        dData(dd), pNext(NULL), pPrevious(NULL)
    {  }
    
    void displayLink()                 // method to display link
    {
        cout << dData << " ";
    }
    
};  


class DblLinkedList
{
private:
    Link* pFirst;                   // pointer to first 
    Link* pLast;                    // pointer to last 
public:
    
    DblLinkedList() :               // constructor
        pFirst(NULL), pLast(NULL)
    {  }
    
    ~DblLinkedList()            // destructor 
    {
        Link* pCurrent = pFirst;    // start at first link
        while (pCurrent != NULL)     // until end of list
        {
            Link* pOldCur = pCurrent;    // set current link to old link
            pCurrent = pCurrent->pNext;  // move to next link
            delete pOldCur;              // delete old current
        }
    }
    
    bool isEmpty()                     // true if empty
    {
        return pFirst == NULL;
    }
    
    void insertFirst(double dd)        // method to insert at front 
    {
        Link* pNewLink = new Link(dd);  // assign ptr to new link

        if (isEmpty())                 // if list is empty
            pLast = pNewLink;            // then last link = new link
        else
            pFirst->pPrevious = pNewLink; // newLink <-- old first
        pNewLink->pNext = pFirst;       // newLink --> old first
        pFirst = pNewLink;              // first --> newLink
    }
    
    void insertLast(double dd)         // method to insert at end
    {
        Link* pNewLink = new Link(dd);  // make new link
        if (isEmpty())                 // if empty list
            pFirst = pNewLink;           // first = newLink
        else
        {
            pLast->pNext = pNewLink;     // assign old last to new link
            pNewLink->pPrevious = pLast; // old last <-- newLink
        }
        pLast = pNewLink;               // assign new link to last
    }
    
    void deleteFirst()                 // method to delete first node
    {                               
        Link* pTemp = pFirst;           // assign ptr to first
        if (pFirst->pNext == NULL)       // if only one item
            pLast = NULL;                // then last is null
        else
            pFirst->pNext->pPrevious = NULL;  //null <-- old next
        pFirst = pFirst->pNext;         // first --> old next
        delete pTemp;                   // delete old first
    }
    
    void deleteLast()                  //method to remove last node
    {                               
        Link* pTemp = pLast;
        if (pFirst->pNext == NULL)       // if only one item
            pFirst = NULL;               // first --> null
        else
            pLast->pPrevious->pNext = NULL;  // old previous --> null
        pLast = pLast->pPrevious;       // old previous <-- last
        delete pTemp;                   // delete old last
    }
    
    void displayFwd()
    { 
        cout << "List (first-->last): ";
        Link* pCurrent = pFirst;       // start at beginning of list
        while (pCurrent != NULL)        // while its not end of list
        {
            pCurrent->displayLink();    // display current node
            pCurrent = pCurrent->pNext; // then move to next
        }
        cout << endl;
    }
   
    void displayBwd()
    {
        cout << "List (last-->first): ";
        Link* pCurrent = pLast;        // start at end of list
        while (pCurrent != NULL)        //until start of list
        {
            pCurrent->displayLink();    // display current node
            pCurrent = pCurrent->pPrevious; // then move to previous
        }
        cout << endl;
    }
    
};  


int main()
{
    DblLinkedList theList;     // make list obj

    int i = 0;
    while (i < 1)   // infinite loop
    {
        int userChoice;
        cout << "Select a choice:\n1. Insert first node\n2. Insert last node\n3. Delete first node\n4. Delete last node\n5. Display list forward\n6. Display list backwards" << endl;   // print menu options
        cin >> userChoice;  // get choice

        switch (userChoice)     // use switch case block for choices
        {
        case 1:
            double first_node;
            cout << "Enter the value to insert" << endl;
            cin >> first_node;
            theList.insertFirst(first_node);    // call method, insert users # 
            break;

        case 2:
            double last_node;
            cout << "Enter the value to insert" << endl;
            cin >> last_node;
            theList.insertLast(last_node);      // call method, insert users #
            break;

        case 3:
            theList.deleteFirst();      // call method to delete first node
            cout << "The first node has been deleted" << endl;
            break;

        case 4:
            theList.deleteLast();       // call method to delete last node
            cout << "The last node has been deleted" << endl;
            break;

        case 5:
            theList.displayFwd();   // display list fwd
            break;

        case 6:
            theList.displayBwd();   // display list backwards
            break;

        default:
            cout << "Be sure to use an integer like 1, 2, 3, etc. to select a menu option" << endl;
        }
    }

    
    return 0;
}  //end main()
