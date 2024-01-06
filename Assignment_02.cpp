#include <iostream>
#include <vector>

using namespace std;

// Functions for Question 4
vector<int> BinaryK(int k)
{
    vector<int> K;
    int tmp = k,
        i = 0;
    while(tmp > 0){
        K.push_back(tmp % 2);
        tmp = (tmp-K[i])/2;
        i++;
    }
    return K;
}
int ModularExpo(int a, vector<int> K, int n)
{
    if(n == 1)
        return 0;

    int b = 1;
    if(K.size() == 0)
        return b;

    int A = a;
    if(K[0] == 1)
        b = a;

    for(int i = 1; i <= K.size()-1; i++){
        A = (A*A) % n;
        if(K[i] == 1)
            b = (A*b) % n;
    }

    return b;
}

int main()
{
    //Question 1
    /*
    int* array;
    int size;
    cout << "Enter the desired array length" << endl;
    cin >> size;
    array = new int[size];

    cout << "Fill the array with integers..." << endl;
    for(int i = 0; i < size; i++)
        cin >> array[i];
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    cout << "Sorting time" << endl;
    int temp;
    int minJ = 1;
    bool swap = false;

    if(size > 1){
        for(int i = 0; i < size-1; i++){
            minJ = i;
            for(int j = i+1; j < size; j++){
                if(array[j] < array[minJ])
                    minJ = j;
                    swap = true;
            }
            if(swap){
                temp = array[i];
                array[i] = array[minJ];
                array[minJ] = temp;
                swap = false;
            }
            minJ = i+1;
        }
        for(int i = 0; i < size; i++){
            cout << array[i] << " ";
    }
    }
    else
        cout << "No need to sort an array of size " << size << endl;
        */

    //Question 2
    /*
    int a, b;
    cout << "Enter the first integer" << endl;
    cin >> a;
    cout << "Enter the second integer" << endl;
    cin >> b;

    int s = 0,
        old_s = 1,
        t = 1,
        old_t = 0,
        r = b,
        old_r = a,
        q, temp;

    while(r != 0){
        q = old_r / r;
        temp = old_r;
        old_r = r;
        r = temp - (q * r);
        temp = old_s;
        old_s = s;
        s = temp - (q * s);
        temp = old_t;
        old_t = t;
        t = temp - (q * t);
    }
    cout << "GCD: " << old_r << endl;
    */

    //Question 3
    /*
    int* array;
    int size;
    cout << "Enter the desired array length" << endl;
    cin >> size;
    while(size < 2){
        cout << "Pick a size that's greater than 1" << endl;
        cin >> size;
    }
    array = new int[size];

    cout << "Fill the array with integers..." << endl;
    for(int i = 0; i < size; i++)
        cin >> array[i];
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    cout << "Finding the two max integers time" << endl;
    int maxOne = array[0], maxTwo = 0;

    for(int i = 1; i < size; i++){
        if(array[i] > maxOne)
            maxOne = array[i];
        else if(array[i] > maxTwo){
            maxTwo = array[i];
        }
    }

    cout << maxOne << " and " << maxTwo << endl;
    */

    //Question 4
    /*
    int a, k, n;
    cout << "Enter for a" << endl;
    cin >> a;
    cout << "Enter for k" << endl;
    cin >> k;
    cout << "Enter for n" << endl;
    cin >> n;

    vector<int> array = BinaryK(k);
    cout << endl << ModularExpo(a, array, n) << endl;
    */

    return 0;
}
