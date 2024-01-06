#include <iostream>

using namespace std;

//Comment out question 1 before uncommenting question 2

//========== Question 1 ==========
struct slinklist
{
    int data;
    struct slinklist* next;
};
typedef struct slinklist Node;
Node* start = NULL;

Node* getNode()
{
    int d;
    Node* newNode;
    newNode = new Node;
    cout << "Enter an integer" << endl;
    cin >> d;
    newNode->data = d;
    newNode->next = NULL;
    return newNode;
}

void createList(int n)
{
    int i;
    Node* newNode;
    Node* temp;
    for(i = 0; i < n; i++){
       newNode = getNode();
       if(start == NULL){
           start = newNode;
       }
       else{
            temp = start;
       while(temp->next != NULL){
            temp = temp->next;
       }
       temp->next = newNode;
       }
    }
}

int countNode(Node* start)
{
    if(start == NULL)
        return 0;
    else
        return (1 + countNode(start->next));
}

void insterAtMid(int h)
{
    Node* newNode;
    Node* temp;
    Node* pre;
    int pos, nodectr, ctr = 1;
    newNode = getNode();
    pos = h;
    nodectr = countNode(start);
    if(pos > 1 && pos < nodectr){
        temp = pre = start;
        while(ctr < pos){
            pre = temp;
            temp = temp->next;
            ctr++;
        }
        pre->next = newNode;
        newNode->next = temp;
    }
    else{
        cout << "not a middle spot" << endl;
    }
}

void deleteAtMid(int h)
{
    int ctr = 1, pos, nodectr;
    Node* temp;
    Node* pre;
    if(start == NULL){
        cout << "empty list" << endl;
        return;
    }
    else{
        pos = h;
        nodectr = countNode(start);
        if(pos > nodectr){
            cout << "node doesn't exist" << endl;
        }
        if(pos > 1 && pos < nodectr){
            temp = pre = start;
            while(ctr < pos){
                pre = temp;
                temp = temp->next;
                ctr++;
            }
            pre->next = temp->next;
            free(temp);
            cout << "node deleted" << endl;
        }
        else{
            cout << "invalid position" << endl;
        }
    }
}

void traverse()
{
    Node* temp;
    temp = start;

    if(start == NULL){
        cout << "empty list" << endl;
    }
    else{
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

int main()
{
    int numOfNodes, half;

    cout << "How long would you like the list to be?" << endl;
    cin >> numOfNodes;
    if(numOfNodes%2 == 0)
        half = numOfNodes/2;
    else
        half = (numOfNodes/2)+1;

    createList(numOfNodes);
    traverse();
    deleteAtMid(half);
    traverse();
    insterAtMid(half);
    traverse();

    return 0;
}


//========== Question 2 ==========
/*struct dlinklist
{
    struct dlinklist* left;
    int data;
    struct dlinklist* right;
};
typedef struct dlinklist Node;
Node* start = NULL;

Node* getNode()
{
    int d;
    Node* newNode;
    newNode = new Node;
    cout << "Enter an integer" << endl;
    cin >> d;
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void createList(int n)
{
    int i;
    Node* newNode;
    Node* temp;
    for(i = 0; i < n; i++){
        newNode = getNode();
        if(start == NULL){
            start = newNode;
        }
        else{
            temp = start;
            while(temp->right)
                temp = temp->right;
            temp->right = newNode;
            newNode->left = temp;
        }
    }
}

int countNode(Node* start)
{
    if(start == NULL)
        return 0;
    else
        return (1 + countNode(start->right));
}

void insterAtBeg()
{
    Node* newNode = getNode();
    if(start == NULL){
        start = newNode;
    }
    else{
        newNode->right = start;
        start->left = newNode;
        start = newNode;
    }
}

void deleteAtEnd()
{
    Node* temp;
    if(start == NULL){
        cout << "     " << endl;
    }
    else{
        temp = start;
        while(temp->right){
            temp = temp->right;
        }
        temp->left->right = NULL;
        free(temp);

    }
}

void traverse()
{
    Node* temp;
    temp = start;

    if(start == NULL){
        cout << "empty list" << endl;
    }
    else{
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
    cout << endl;
}

int main()
{
    int numOfNodes, half;

    cout << "How long would you like the list to be?" << endl;
    cin >> numOfNodes;

    if(numOfNodes%2 == 0)
        half = numOfNodes/2;
    else
        half = (numOfNodes/2)+1;

    createList(numOfNodes);
    traverse();
    deleteAtEnd();
    traverse();
    insterAtBeg();
    traverse();

    return 0;
}*/
