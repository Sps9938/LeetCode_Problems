#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Hash{
    public:
        static const int size =  10;
        // int size;
        vector<pair<int, string>> table[size];
        // vector<list<pair<int, string>>> table;
    // void hashSize(int size){
    //     this->size = size;
    //     table.resize(size);
    // }

    int hashFunction(int key){
        return key % size;
    }

    void insert(int key, string value){
        int hash = hashFunction(key);
        for(auto &it : table[hash]){
            if(it.first == key){
                //update current key with value
                it.second = value;
            }
        }

        table[hash].push_back({key, value});

    }

    //get
    string getValue(int key){
        int hash = hashFunction(key);
        for(auto &it : table[hash]){
            if(it.first == key) return it.second;
        }
        return "Not Found";
    }

    //remove 
    void remove(int key){
        int hash = hashFunction(key);
        
        for(auto it = table[hash].begin(); it != table[hash].end(); it++){
            if(it->first == key){
                table[hash].erase(it);
                return;
            }
        }
    }


    void display(){
        for(auto list : table){
            for(auto it : list){
                cout<<"key= "<<it.first<<" value= "<<it.second<<endl;
            }
        }
    }
};
int main(){
    Hash h1;
    // h1.hashSize(20);
    h1.insert(1, "apple");
    h1.insert(2, "orange");
    h1.insert(42, "pinaple");
    h1.insert(52, "guava");

    // h1.display();

    // cout<<"after removing the one pair"<<endl;
    // h1.remove(42);
    // h1.display();

    cout<<h1.getValue(42);

    return 0;
}