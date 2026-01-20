#include<iostream>
using namespace std;
class Block{
public:
    int BlockID, WorkDone, PrevKey, CurrKey;
    string data;
    Block *next1, *next2;
    Block(int id,string d,int work,int prev) : BlockID(id), data(d), WorkDone(work), PrevKey(prev), next1(NULL), next2(NULL) {
        int sum = 0;
        for(char c: data) sum+= (int)c;
        CurrKey = (BlockID * 27 + WorkDone * 19 +sum + PrevKey) % 100000;
    }
};
class BlockChain{
private:
    Block *Head;
public:
    BlockChain() : Head(NULL) {}
    void createGenesisBlock() {
        Head = new Block(1,"",0,0);
    }

    void addBlock(string data, int work) {
        if(Head == NULL) {
            createGenesisBlock();
            return;
        }
        Block *temp = Head;
        while(temp->next1 != NULL) temp = temp->next1;
        Block *newBlock = new Block(temp->BlockID + 1,data,work, temp->CurrKey);
        temp->next1 = newBlock;
    }

    void forkChain(int blockID, string data1, string data2, int work1,int work2) {
        Block *temp = Head;
        while(temp != NULL && temp->BlockID != blockID) temp = temp->next1;

        if(temp == NULL) {
            cout<<"Block not found"<<endl;
            return;
        }
        temp->next1 = new Block(blockID + 1,data1, work1, temp->CurrKey);
        temp->next2 = new Block(blockID + 1,data2, work2, temp->CurrKey);
    }

    void tamperBlock(int blockID, int newKey) {
        Block *temp = Head;
        while(temp != NULL) {
            if(temp->BlockID == blockID) {
                temp->CurrKey = newKey;
                return;
            }
            temp = temp->next1;
        }

        if(temp == NULL || temp->BlockID != blockID) {
            cout<<"Block not found"<<endl;
            return;
        }
        temp->CurrKey = newKey;
    }

    void repairChain(int blockID) {
        Block *temp = Head;
        while(temp != NULL && temp->BlockID != blockID) temp = temp->next1;

        if(temp == NULL) return;
    }

    void validateChain() {

    }

    void consensusRule() {

    }

    void displayAllChains() {
        Block *temp = Head;
        while(temp != NULL) {
            cout<<"Block "<<temp->BlockID<<", data "<<temp->data<<", key: "<<temp->CurrKey;

            if(temp->next2 != NULL) cout<<"Fork to block: "<<temp->next2->BlockID;

            cout<<endl;
            temp = temp->next1;
        }

        temp = Head;
        while(temp != NULL) {
            if(temp->next2 != NULL) {
                cout<<"Fork from block "<<temp->BlockID<<":"<<endl;
                Block *fork = temp->next2;
                while(fork != NULL) {
                    cout<<" Block "<<fork->BlockID<<" Data: "<<fork->data<<", Key: "<<fork->CurrKey<<endl;

                    fork = fork->next1;
                }
            }
            temp = temp->next1;
        }
    }
};

int main() {
    BlockChain B1;
    
    B1.createGenesisBlock();
    B1.addBlock("Task 1", 10);
    B1.addBlock("Task 2", 20);
    
    B1.forkChain(2, "Fork A", "Fork B", 15, 25);
    
    B1.displayAllChains();
    B1.validateChain();
    
    B1.tamperBlock(2, 99999);
    B1.validateChain();
    
    B1.repairChain(2);
    B1.validateChain();
    
    B1.consensusRule();
    
    return 0;
}