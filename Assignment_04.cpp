//========== Question 1 ==========
#include <iostream>
#include <stdio.h>
#define MAX 6
int stack[MAX];
int top = 0;

using namespace std;

int menu()
{
    int ch;
    cout << "1. Insert" << endl << "2. Delete" << endl << "3. Display" << endl << "4. Quit" << endl;
    cin >> ch;
    return ch;
}

void display()
{
    int i;
    if(top == 0){
        cout << "There's nothing to display" << endl;
        return;
    }
    else{
        cout << "Elements in stack:" << endl;
        for(i = 0; i < top; i++)
            cout << stack[i] << " ";
        cout << endl;
    }
}

void insertS()
{
    int data, i;
    if(top == MAX){
        cout << "Stack overflow" << endl;
        return;
    }
    else{
        cout << "Enter data" << endl;
        cin >> data;
        for(i = top; i > 0; i--)
            stack[i] = stack[i-1];
        stack[0] = data;
        ++top;
        cout << "Data inserted into the stack" << endl;
    }
}

void deleteS()
{
    if(top == 0){
        cout << "There's nothing to delete" << endl;
        return;
    }
    else{
        cout << "..." << stack[top-1] << endl;
        --top;
    }
}

int main()
{
    int ch;
    do{
        ch = menu();
        switch(ch){
            case 1:
                insertS();
                break;
            case 2:
                deleteS();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);

        }
    }while(1);
    return 0;
}

//========== Question 2 ==========
//Comment out Question 1 before uncommenting Question 2
/*#include <iostream>

using namespace std;

struct dlinklist
{
    struct dlinklist* left;
    int data;
    struct dlinklist* right;
};
typedef struct dlinklist Node;
Node* start = NULL;

Node* getNode(int d)
{
    Node* newNode;
    newNode = new Node;
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void createList()
{
    //Intended tree
    //      5
    //    /   \
    //  1       2
    // / \     / \
    //3   4   7   8

    //should print out "3 1 4 5 7 2 8"

    Node* newNode = getNode(5);
    start = newNode;
    newNode->left = getNode(1);
    newNode->left->left = getNode(3);
    newNode->left->right = getNode(4);
    newNode->right = getNode(2);
    newNode->right->left = getNode(7);
    newNode->right->right = getNode(8);
    cout << "Example Tree" << endl;
    cout << "      5" << endl;
    cout << "    /   \\" << endl;
    cout << "  1       2" << endl;
    cout << " / \\     / \\" << endl;
    cout << "3   4   7   8" << endl << endl;
    cout << "Should print out..." << endl;
    cout << "3 1 4 5 7 2 8" << endl << endl;
}

void traverse(Node* position)
{
    if(position == NULL)
        return;

    traverse(position->left);
    cout << position->data << " ";
    traverse(position->right);
}

int main()
{

    createList();
    cout << "traversing..." << endl;
    traverse(start);

    return 0;
}*/
