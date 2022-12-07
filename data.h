#include <vector>
#include <string>

using std::string;
using std::vector;

class LinkedList;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
    LinkedList *edgeList;
};
