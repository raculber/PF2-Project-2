
#include <cmath>
#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Stack data node definition
//-----------------------------------------------------------
struct StackNode
{
   string str;
   StackNode *Next;
};

//-----------------------------------------------------------
// Define the Stack class interface
//-----------------------------------------------------------
class Stack
{
 public:
   // Constructors
   Stack();
   Stack(const Stack & stack);
   ~Stack();

   // Methods
   bool IsFull();
   bool IsEmpty();
   void Push(string str);
   void Pop(string &str);
   void Top(string &str);
   int GetLength();
   void Print();

 private:
   StackNode *Head;
   int Length;
};
