#include<iostream>
using namespace std;
class Node{
public:
    int key;
    Node** next;
    Node(int val){
        key = 0;
        next = nullptr;
    }
};
class CloseHashing{
    int size;
    Node** table;
public:
    CloseHashing(int cap){
        size = cap;
        table = new Node*[size];

        for(int i=0;i<size;i++) table[i] = nullptr;
    }
    int hashFunction(int key) { return key % size; }
    void insert(int key){
        int index = hashFunction(key);
        while(table[index] != nullptr && table[index]->key != -1){
            index = (index + 1) % size;
        }
        Node* newNode = new Node(key);
        newNode->key = key;
        table[index] = newNode;
    }
    void deleteKey(int key){
        int index = hashFunction(key);
        while(table[index] != nullptr){
            if(table[index]->key == key){
                table[index]->key = -1; // Mark as deleted
                return;
            }
            index = (index + 1) % size;
        }
    }
    void display(){
        for(int i=0;i<size;i++){
            if(table[i] != nullptr && table[i]->key != -1)
                cout << i << " --> " << table[i]->key << endl;
            else
                cout << i << " --> " << "NULL" << endl;
        }
    }
};
class Hashmap{
    int size;
    Node** table;
public:
    Hashmap(int cap){
        size = cap;
        table = new Node*[size];

        for(int i=0;i<size;i++) table[i] = nullptr;
    }
    int hashFunction(int key) { return key % size; }

    void insert(int key){
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        newNode->key = key;
        newNode->next = nullptr;

        if(table[index] == nullptr){
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while(*(temp->next) != nullptr){
                temp = *(temp->next);
            }
            temp->next = &newNode;
        }
    }
    void deleteKey(int key){
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;
        while(temp != nullptr){
            if(temp->key == key){
                if(prev == nullptr) table[index] = *(temp->next);
                else prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = *(temp->next);
        }
    }
    void display(){
        for(int i=0;i<size;i++){
            cout << i << " -->";
            Node* temp = table[i];
            while(temp != nullptr){
                cout << temp->key << " ";
                temp = *(temp->next);
            }
            cout << endl;
        }
    }
};
int main() {
    CloseHashing ch(10);
    ch.insert(5);
    ch.insert(15);
    ch.insert(25);
    ch.insert(35);
    ch.insert(7);
    ch.insert(17);
    ch.insert(27);
    ch.insert(37);
    ch.insert(8);
    ch.deleteKey(5);
    // ch.display();


    cout<<endl<<endl<<endl;
    Hashmap hm(10);
    hm.insert(5);
    hm.insert(15);
    hm.insert(25);
    hm.insert(35);
    hm.insert(7);
    hm.insert(17);
    hm.insert(27);
    hm.insert(37);
    hm.insert(8);
    hm.display();
    hm.deleteKey(5);
    // hm.display();
    return 0;
}