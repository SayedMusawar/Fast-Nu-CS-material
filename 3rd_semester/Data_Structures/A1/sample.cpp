#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Block {
public:
    int BlockID, WorkDone, PrevKey, CurrKey;
    string Data;
    Block *Next1, *Next2;
    
    Block(int id, string data, int work, int prevKey) 
        : BlockID(id), Data(data), WorkDone(work), PrevKey(prevKey), Next1(nullptr), Next2(nullptr) {
        calculateCurrKey();
    }
    
    void calculateCurrKey() {
        int sum = 0;
        for (char c : Data) {
            sum += (int)c;
        }
        CurrKey = (BlockID * 37 + WorkDone * 19 + sum + PrevKey) % 100000;
    }
};

class BlockChain {
private:
    Block* Head;
    
    // Helper function to find a block by ID using BFS
    Block* findBlock(int blockID) {
        if (!Head) return nullptr;
        
        queue<Block*> q;
        q.push(Head);
        
        while (!q.empty()) {
            Block* current = q.front();
            q.pop();
            
            if (current->BlockID == blockID) {
                return current;
            }
            
            if (current->Next1) q.push(current->Next1);
            if (current->Next2) q.push(current->Next2);
        }
        
        return nullptr;
    }
    
    // Helper function to find all chains from genesis to leaves
    void getAllChains(Block* node, vector<Block*>& currentChain, vector<vector<Block*>>& allChains) {
        if (!node) return;
        
        currentChain.push_back(node);
        
        // If this is a leaf node (no children), add current chain to all chains
        if (!node->Next1 && !node->Next2) {
            allChains.push_back(currentChain);
        } else {
            // Continue with children
            if (node->Next1) {
                getAllChains(node->Next1, currentChain, allChains);
            }
            if (node->Next2) {
                getAllChains(node->Next2, currentChain, allChains);
            }
        }
        
        currentChain.pop_back(); // Backtrack
    }
    
    // Repair function for a single block and its descendants
    void repairFromBlock(Block* block) {
        if (!block) return;
        
        // Recalculate current block's key
        block->calculateCurrKey();
        
        // Recursively repair children
        if (block->Next1) {
            block->Next1->PrevKey = block->CurrKey;
            repairFromBlock(block->Next1);
        }
        if (block->Next2) {
            block->Next2->PrevKey = block->CurrKey;
            repairFromBlock(block->Next2);
        }
    }

public:
    BlockChain() : Head(nullptr) {}
    
    void createGenesisBlock() {
        Head = new Block(1, "", 0, 0);
    }
    
    void addBlock(string data, int work) {
        if (!Head) {
            cout << "No genesis block found. Create genesis block first." << endl;
            return;
        }
        
        // Find the end of the main chain (follow Next1 pointers)
        Block* current = Head;
        while (current->Next1) {
            current = current->Next1;
        }
        
        // Create new block
        Block* newBlock = new Block(current->BlockID + 1, data, work, current->CurrKey);
        current->Next1 = newBlock;
    }
    
    void forkChain(int blockID, string data1, string data2, int work1, int work2) {
        Block* forkPoint = findBlock(blockID);
        if (!forkPoint) {
            cout << "Block with ID " << blockID << " not found." << endl;
            return;
        }
        
        // Create two new blocks
        Block* branch1 = new Block(blockID + 1, data1, work1, forkPoint->CurrKey);
        Block* branch2 = new Block(blockID + 1, data2, work2, forkPoint->CurrKey);
        
        forkPoint->Next1 = branch1;
        forkPoint->Next2 = branch2;
    }
    
    void tamperBlock(int blockID, int newKey) {
        Block* block = findBlock(blockID);
        if (!block) {
            cout << "Block with ID " << blockID << " not found." << endl;
            return;
        }
        
        // Modify the CurrKey (simulate tampering)
        block->CurrKey = newKey;
        cout << "Block " << blockID << " has been tampered with." << endl;
    }
    
    void repairChain(int blockID) {
        Block* block = findBlock(blockID);
        if (!block) {
            cout << "Block with ID " << blockID << " not found." << endl;
            return;
        }
        
        // Repair this block and all subsequent blocks
        repairFromBlock(block);
        cout << "Chain repaired starting from block " << blockID << endl;
    }
    
    void validateChain() {
        if (!Head) {
            cout << "No blockchain exists." << endl;
            return;
        }
        
        queue<Block*> q;
        q.push(Head);
        bool isValid = true;
        
        while (!q.empty()) {
            Block* current = q.front();
            q.pop();
            
            // Check if current block's key matches expected calculation
            int expectedKey = current->CurrKey;
            current->calculateCurrKey();
            
            if (expectedKey != current->CurrKey) {
                cout << "Mismatch found in Block " << current->BlockID 
                     << ": Expected CurrKey=" << current->CurrKey 
                     << ", Found=" << expectedKey << endl;
                isValid = false;
                current->CurrKey = expectedKey; // Restore original for consistency
            }
            
            // Check children's PrevKey
            if (current->Next1) {
                if (current->Next1->PrevKey != current->CurrKey) {
                    cout << "PrevKey mismatch: Block " << current->Next1->BlockID 
                         << " PrevKey=" << current->Next1->PrevKey 
                         << " should be " << current->CurrKey << endl;
                    isValid = false;
                }
                q.push(current->Next1);
            }
            
            if (current->Next2) {
                if (current->Next2->PrevKey != current->CurrKey) {
                    cout << "PrevKey mismatch: Block " << current->Next2->BlockID 
                         << " PrevKey=" << current->Next2->PrevKey 
                         << " should be " << current->CurrKey << endl;
                    isValid = false;
                }
                q.push(current->Next2);
            }
        }
        
        if (isValid) {
            cout << "Blockchain is valid - no tampering detected." << endl;
        }
    }
    
    void consensusRule() {
        if (!Head) {
            cout << "No blockchain exists." << endl;
            return;
        }
        
        vector<vector<Block*>> allChains;
        vector<Block*> currentChain;
        getAllChains(Head, currentChain, allChains);
        
        if (allChains.empty()) {
            cout << "No valid chains found." << endl;
            return;
        }
        
        // Find the winning chain (longest, or highest WorkDone if tied)
        vector<Block*> winningChain = allChains[0];
        int maxLength = winningChain.size();
        int maxWorkDone = 0;
        
        // Calculate work done for first chain
        for (Block* block : winningChain) {
            maxWorkDone += block->WorkDone;
        }
        
        // Compare with other chains
        for (size_t i = 1; i < allChains.size(); i++) {
            int currentLength = allChains[i].size();
            int currentWorkDone = 0;
            
            for (Block* block : allChains[i]) {
                currentWorkDone += block->WorkDone;
            }
            
            if (currentLength > maxLength || 
                (currentLength == maxLength && currentWorkDone > maxWorkDone)) {
                winningChain = allChains[i];
                maxLength = currentLength;
                maxWorkDone = currentWorkDone;
            }
        }
        
        cout << "\n=== WINNING CHAIN (Consensus Rule) ===" << endl;
        cout << "Length: " << maxLength << endl;
        cout << "Total WorkDone: " << maxWorkDone << endl;
        cout << "Chain: ";
        for (size_t i = 0; i < winningChain.size(); i++) {
            cout << winningChain[i]->BlockID;
            if (i < winningChain.size() - 1) cout << " -> ";
        }
        cout << endl;
        
        // Integrity Report
        vector<int> tamperedBlocks;
        for (Block* block : winningChain) {
            int originalKey = block->CurrKey;
            block->calculateCurrKey();
            if (originalKey != block->CurrKey) {
                tamperedBlocks.push_back(block->BlockID);
                block->CurrKey = originalKey; // Restore
            }
        }
        
        if (!tamperedBlocks.empty()) {
            cout << "Integrity Report - Tampered blocks in winning chain: ";
            for (size_t i = 0; i < tamperedBlocks.size(); i++) {
                cout << tamperedBlocks[i];
                if (i < tamperedBlocks.size() - 1) cout << ", ";
            }
            cout << endl;
        } else {
            cout << "Integrity Report - No tampering detected in winning chain." << endl;
        }
    }
    
    void displayAllChains() {
        if (!Head) {
            cout << "No blockchain exists." << endl;
            return;
        }
        
        vector<vector<Block*>> allChains;
        vector<Block*> currentChain;
        getAllChains(Head, currentChain, allChains);
        
        cout << "\n=== ALL CHAINS ===" << endl;
        for (size_t i = 0; i < allChains.size(); i++) {
            cout << "Chain " << (i + 1) << ": ";
            for (size_t j = 0; j < allChains[i].size(); j++) {
                Block* block = allChains[i][j];
                cout << "Block" << block->BlockID << "(Data:'" << block->Data 
                     << "', CurrKey:" << block->CurrKey << ")";
                if (j < allChains[i].size() - 1) cout << " -> ";
            }
            cout << endl;
        }
    }
    
    ~BlockChain() {
        // Cleanup memory (simplified - in real implementation, use proper tree deletion)
        // For demonstration purposes, basic cleanup
        if (Head) {
            queue<Block*> q;
            q.push(Head);
            while (!q.empty()) {
                Block* current = q.front();
                q.pop();
                if (current->Next1) q.push(current->Next1);
                if (current->Next2) q.push(current->Next2);
                delete current;
            }
        }
    }
};

// Demo function to test the blockchain
int main() {
    BlockChain bc;
    
    cout << "=== AAIS' BLOCKCHAIN ADVENTURE ===" << endl;
    
    // Create genesis block
    bc.createGenesisBlock();
    cout << "Genesis block created." << endl;
    
    // Add some blocks
    bc.addBlock("Task1: Collect treasure", 10);
    bc.addBlock("Task2: Solve puzzle", 15);
    bc.addBlock("Task3: Find key", 20);
    
    cout << "\nAdded 3 blocks to the chain." << endl;
    
    // Display current chain
    bc.displayAllChains();
    
    // Create a fork at block 2
    bc.forkChain(2, "Fork1: Alternative puzzle", "Fork2: Secret passage", 12, 18);
    cout << "\nCreated fork at block 2." << endl;
    
    // Display all chains
    bc.displayAllChains();
    
    // Validate the blockchain
    cout << "\n=== VALIDATION ===" << endl;
    bc.validateChain();
    
    // Tamper with a block
    cout << "\n=== TAMPERING SIMULATION ===" << endl;
    bc.tamperBlock(2, 99999);
    
    // Validate again
    bc.validateChain();
    
    // Repair the chain
    cout << "\n=== REPAIR ===" << endl;
    bc.repairChain(2);
    
    // Final validation
    bc.validateChain();
    
    // Apply consensus rule
    cout << "\n=== CONSENSUS RULE ===" << endl;
    bc.consensusRule();
    
    return 0;
}