#include <iostream>
#include <string>
using namespace std;

class Stack
{
    struct Node
    {
        Node *prev;
        string s;

        Node(Node *prev, string s) : prev(prev), s(s) {}
    };

    Node *current;
    Node start;

public:
    Stack();

    // 최상단에 새로운 원소를 추가한다.
    void push(string s);

    // 최상단의 원소를 제거하고 반환한다.
    string pop();

    // 최상단의 원소를 반환한다.(제거 x)
    string peek();

    // 스택이 비어있는지의 유무를 반환한다.
    bool is_empty();

    ~Stack();
};

Stack::Stack() : start(NULL, "") { current = &start; }

void Stack::push(string s)
{
    Node *n = new Node(current, s);
    current = n;
}

string Stack::pop()
{
    if (current == &start)
        return "";

    string s = current->s;
    Node *prev = current;
    current = current->prev;

    // Delete popped node
    delete prev;
    return s;
}

string Stack::peek() { return current->s; }

bool Stack::is_empty()
{
    if (current == &start)
        return true;
    return false;
}

Stack::~Stack()
{
    while (current != &start)
    {
        Node *prev = current;
        current = current->prev;
        delete prev;
    }
}
