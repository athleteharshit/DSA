#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

// Points:
// * two type of map is availble ordered and unordered
// * ordered map opreation time complexity O(logN), this is implement over Balence BST jiska diff 1 hota h, and key is sorted ordered
// * unordered map opreation time complexity O(N) approx, this is implement over array/hashtable/bucket table
// * ordered map using hashing to store data
// * two type of hashing
// * load factor = number of element/total number of size of map
// * load factor >= 0.7 (it's good for map)

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// Problem: check linkedlist is circular
bool hasCycle(ListNode *head)
{
    map<ListNode *, bool> obj;

    ListNode *tem = head;

    while (tem != NULL)
    {
        if (obj[tem] == false)
        {
            obj[tem] = true;
        }
        else
        {
            return true;
        }
        tem = tem->next;
    }

    return false;
}

int main()
{

    // create unordered map
    unordered_map<string, int> mapping;

    // create pair
    pair<string, int> p;
    p.first = "a";
    p.second = 21;
    pair<string, int> q("b", 22);
    pair<string, int> r = {"c", 23};

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping["d"] = 24;

    cout << "Size of: " << mapping.size() << endl;
    cout << "Check d: " << mapping["e"] << endl;
    cout << "Size of: " << mapping.size() << endl;


    for(auto i: mapping) {
        cout << mapping[i.first] << endl;
    }

    return 0;
}
