#include <iostream>
#include <memory>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

class List
{
    struct Node
    {
        int value;
        unique_ptr<Node> next;
        Node(int n, unique_ptr<Node> point = nullptr) : value{n}, next{move(point)} {}
    };

public:
    List() : head{nullptr} {}

    void append(int n);

    template <size_t N>
    void append(int (&ns)[N]);

    void prepend(int n);

    template <size_t N>
    void prepend(int (&ns)[N]);

    int init();

    int pop();

    int shift();

    int size();

    int tail();

    bool has(int n);

private:
    unique_ptr<Node> head;
};

void List::append(int n)
{   
    if (this->head == nullptr)
    {
        this->head = make_unique<Node>(n);
        return;
    }

    auto v = this->head.get();

    while (v->next != nullptr)
        v = v->next.get();

    v->next = make_unique<Node>(n);
}

template <size_t N>
void List::append(int (&ns)[N])
{
  for (const int &n : ns)
    this->append(n);
}

void List::prepend(int n)
{
    this->head = make_unique<Node>(n, move(this->head));
}

template <size_t N>
void List::prepend(int (&ns)[N])
{
  for (int i = 1; i <= N; i++)
    this->prepend(ns[N - i]);
}

int List::size()
{
    int x = 0;
    auto v = this->head.get();

    while (v->next != nullptr)
    {
        v = v->next.get();
        x++;
    }

    return x;
}

int List::init()
{
    if (this->head == nullptr)
        throw invalid_argument("list is empty");

    return this->head->value;
}

int List::pop()
{
  if (this->head == nullptr)
    throw invalid_argument("list is empty");

  auto v = this->head.get();

  while (v->next->next != nullptr)
    v = v->next.get();

  int n = v->next->value;

  v->next = nullptr;

  return n;
}

int List::shift()
{
  if (this->head == nullptr)
    throw invalid_argument("list is empty");

  int n = this->head->value;

  this->head = move(this->head->next);

  return n;
}

int List::tail()
{
    if (this->head == nullptr)
        throw invalid_argument("list is empty");

    auto v = this->head.get();

    while (v->next != nullptr)
        v = v->next.get();

    return v->value;
}

bool List::has(int n)
{
  auto v = this->head.get();

  while (v != nullptr)
  {
    if (v->value == n)
      return 1;
      
    v = v->next.get();
  }

  return 0;
}

int main()
{
    // Test case for List::prepend() & List::append()
    List a;

    // Append & prepend a singular element.
    a.append(2);
    a.prepend(1);

    // Append & prepend an array of elements (integers, in this case)
    int as[] = {3, 4, 5};
    int ps[] = {-2, -1, 0};

    a.append(as);
    a.prepend(ps);

    cout << "Test case for List::append() / List::prepend(): \n"
            "Head of list: " << a.init() << "\n"     // ->  -2
            "Tail of list: " << a.tail() << "\n\n"; //  ->   5


    // Test case for List::has()
    // -> Check, twice, if list contains 2 & 7
    const char* two   = a.has(2) == true ? "Yes" : "No";
    const char* seven = a.has(7) == true ? "Yes" : "No";

    cout << "Test case for List::has(): \n"
            "Has 2? " << two   << "\n"     //  -> Yes
            "Has 7? " << seven << "\n\n"; //   -> No


    // Test case for List::size()
    int x = a.size();

    cout << "Test case for List::size(): \n"
            "Size: " << x << "\n\n"; // -> 8


    // Test case for List::shift()
    int f = a.shift(); // ->   -2

    cout << "Test case for List::shift(): \n"
            "First element that was removed: " << f << "\n\n";  // ->   -2


    // Test case for List::pop()
    int l = a.pop(); // ->      5

    cout << "Test case for List::pop(): \n"
            "Last element that was removed: " << l << "\n\n";   // ->    5


    // Repeat case of init/tail to ensure shift/pop work as intended:
    cout << "Validation: \n"
            "Head: " << a.init() << "\n"    // ->   -1
            "Tail: " << a.tail() << "\n";  //  ->    4
}
