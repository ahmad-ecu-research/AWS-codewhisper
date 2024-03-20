 #include <iostream>
#include <fstream>

// structure for singly linked list
struct singlylinkedlist {
    int data;
    singlylinkedlist* next;
    singlylinkedlist* prev;
    singlylinkedlist* head;
    singlylinkedlist* tail;
    singlylinkedlist* current;
    singlylinkedlist* temp;
};

singlylinkedlist* mergesortlists(singlylinkedlist* list1, singlylinkedlist* list2) {
    singlylinkedlist val(0);
    singlylinkedlist* tail = &val;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != nullptr) tail->next = list1;
    if (list2 != nullptr) tail->next = list2;

    return val.next;
}

singlylinkedlist* readlistfromFile(const std::string& filename) {
    std::ifstream input(filename);
    if (!input) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return nullptr;
    }

    int valuesfromlist;
    singlylinkedlist* list = nullptr;

    while (input >> valuesfromlist) {
        singlylinkedlist* node = new singlylinkedlist;
        node->data = valuesfromlist;
        node->next = nullptr;
        node->prev = nullptr;
        node->head = nullptr;
        node->tail = nullptr;

        if (list == nullptr) {
            list = node;
        } else {
            singlylinkedlist* current = list;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
    }

    input.close();
    return list;
}

// function to wriite sorted list to file 
void sortedlistedtoFile(singlylinkedlist* head, string filename)
{
    // function for outputfile validation
    string ofstream out(filename)
    if (!out)
    {
        cout<<"error opening file";
        cout<<endl;
        cout<<"File could not open";
        return;
    }
    // while loop to write into file from head 
    while (head != nullptr)
    {
        out<<head->data;
        head=head->next;
        out<<endl;

    }
    out.close();
}
// free memory from mergedlist
void deallocatedmemory(singlylinkedlist* head)
{
while (sortedlist != NULL) {
    singlylinkedlist * next=sortedlist->next;
    delete sortedlist;
    sortedlist=next;
    }
}

// main function to read from sorted lists 
int main()
{
    singlylinkedlist* list1 = readlistfromFile("list1.txt");
    singlylinkedlist* list2 = readlistfromFile("list2.txt");
    singlylinkedlist* sortedlist = mergesortlists(list1, list2);
    sortedlistedtoFile(sortedlist, "sortedlist.txt");
    
    deallocatedmemory(sortedlist);
    deallocatedmemory(list1);
    deallocatedmemory(list2);
    return 0;
    
}





    



