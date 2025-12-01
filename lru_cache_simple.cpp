#include <iostream>
using namespace std;

/* Simple LRU using fixed array for keys and recency list.
   Operations are O(capacity) but simple for student-level. */
struct LRU {
    int cap;
    int keys[100], vals[100], used; // keys[0] = most recent
    LRU(int c){ cap=c; used=0; for(int i=0;i<100;i++) keys[i]=-1; }
    int get(int k){
        for(int i=0;i<used;i++) if(keys[i]==k){
            int v=vals[i];
            // move to front
            for(int j=i;j>0;j--){ keys[j]=keys[j-1]; vals[j]=vals[j-1]; }
            keys[0]=k; vals[0]=v;
            return v;
        }
        return -1;
    }
    void put(int k, int v){
        for(int i=0;i<used;i++) if(keys[i]==k){
            for(int j=i;j>0;j--){ keys[j]=keys[j-1]; vals[j]=vals[j-1]; }
            keys[0]=k; vals[0]=v; return;
        }
        if(used < cap){ // insert front
            for(int j=used;j>0;j--){ keys[j]=keys[j-1]; vals[j]=vals[j-1]; }
            keys[0]=k; vals[0]=v; used++;
        } else {
            // evict least recent (end)
            for(int j=cap-1;j>0;j--){ keys[j]=keys[j-1]; vals[j]=vals[j-1]; }
            keys[0]=k; vals[0]=v;
        }
    }
};

int main(){
    LRU cache(2);
    cache.put(1,10); cache.put(2,20);
    cout<<cache.get(1)<<"\n"; // 10
    cache.put(3,30); // evicts 2
    cout<<cache.get(2)<<"\n"; // -1
}
