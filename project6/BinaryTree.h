#include "Address.h"
#include <iostream>
#include <fstream>
using namespace std;
//Interface for BinaryTree Class
class Node
{
  public:
    Address add1;
    Node *left;
    Node *right;
};
class BinaryTree
{
public:
  //Constructor and Deconstructor
  BinaryTree();
  ~BinaryTree();
  //Methods
  bool Search(int houseNum, string streetName, float &lat, float &lon);
  bool Insert(Address add);
  bool Delete(Address add);
  void Print();
private:
  //Helper Methods
  bool SearchHelper(int houseNum, string streetName, float &lat, float &lon, Node * Tree);
  bool InsertHelper(Address add, Node * &Tree);
  bool DeleteNode(Node * &Tree);
  bool DeleteHelper(Address add, Node * &Tree);
  void DestroyHelper(Node * Tree);
  void PrintHelper(Node * Tree);
  //Points to root of tree
  Node *Root;
};
