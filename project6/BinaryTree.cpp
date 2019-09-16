#include "BinaryTree.h"
//Implementation of BinaryTree Class
//Constructor function
BinaryTree::BinaryTree()
{
  Root = NULL;
}
void BinaryTree::DestroyHelper(Node * Tree)
{
  //Delete node and its children
  if (Tree != NULL)
  {
    DestroyHelper(Tree->left);
    DestroyHelper(Tree->right);
    delete Tree;
  }
}
//Destructor function
BinaryTree::~BinaryTree()
{
  DestroyHelper(Root);
}
//Methods
//Latitude/Longitude values returned in reference parameters
bool BinaryTree::Search(int houseNum, string streetName, float &lat, float &lon)
{
  //Call SearchHelper
  return (SearchHelper(houseNum, streetName, lat, lon, Root));
}
bool BinaryTree::Insert(Address add)
{
  //Call InsertHelper
  return (InsertHelper(add, Root));
}
bool BinaryTree::Delete(Address add)
{
  //Call DeleteHelper
  return (DeleteHelper(add, Root));
}
//Prints out content of BinaryTree
void BinaryTree::Print()
{
  //Call helper method
  PrintHelper(Root);
  cout << endl;
}
bool BinaryTree::SearchHelper(int houseNum, string streetName, float &lat, float &lon, Node * Tree)
{
  //Address not found
  if (Tree == NULL)
    return false;
  //Address is Found
  else if ((Tree->add1.getHouseNumber() == houseNum) &&
  (Tree->add1.getStreetName() == streetName))
  {
    lat = Tree->add1.getLatitude();
    lon = Tree->add1.getLongitude();
    return true;
  }
  //Case for if street names match
  if (Tree->add1.getStreetName() == streetName)
  {
    if (Tree->add1.getHouseNumber() > houseNum)
      return (SearchHelper(houseNum, streetName, lat, lon, Tree->left));
    else
      return (SearchHelper(houseNum, streetName, lat, lon, Tree->right));
  }
  else if (Tree->add1.getStreetName() > streetName)
    return (SearchHelper(houseNum, streetName, lat, lon, Tree->left));
  else
    return (SearchHelper(houseNum, streetName, lat, lon, Tree->right));
}
//Finds empty spot to insert address
bool BinaryTree::InsertHelper(Address add, Node * &Tree)
{
  //Insert Data
  if (Tree == NULL)
  {
    Tree = new Node;
    Tree->add1 = add;
    Tree->left = NULL;
    Tree->right = NULL;
    return true;
  }
  //Search for insertion position
  //Case if street names match
  if (Tree->add1.getStreetName() == add.getStreetName())
  {
    if (Tree->add1.getHouseNumber() > add.getHouseNumber())
      return (InsertHelper(add, Tree->left));
    else
      return (InsertHelper(add, Tree->right));
  }
  else if (Tree->add1.getStreetName() > add.getStreetName())
    return (InsertHelper(add, Tree->left));
  else
    return (InsertHelper(add, Tree->right));
}
bool BinaryTree::DeleteNode(Node * &Tree)
{
  Node *Temp = Tree;

  // Node has 0 children
  if ((Tree->left == NULL) && (Tree->right == NULL))
    Tree = NULL;

    // Node has 1 child
  else if (Tree->left == NULL)
    Tree = Tree->right;
  else if (Tree->right == NULL)
    Tree = Tree->left;
  // Node has 2 children
  else
  {
     // Find leftmost node in right subtree
     Node *Parent = Tree;
     Temp = Tree->right;
     while (Temp->left != NULL)
     {
       Parent = Temp;
       Temp = Parent->left;
     }

     // Replace deleted data with leftmost value
     if (Parent == Tree)
     Parent->right = Temp->right;
    else
      Parent->left = Temp->right;
    Tree->add1 = Temp->add1;
  }

  // Delete node
  delete Temp;
  return true;
}
//Finds address to delete
bool BinaryTree::DeleteHelper(Address add, Node * &Tree)
{
  if (Tree == NULL)
    return false;
  //Address to be deleted is found
  else if ((Tree->add1.getHouseNumber() == add.getHouseNumber()) &&
  (Tree->add1.getStreetName() == add.getStreetName()))
    return (DeleteNode(Tree));
  //Search for node to delete
  //Case if street names match
  if (Tree->add1.getStreetName() == add.getStreetName())
  {
    if (Tree->add1.getHouseNumber() > add.getHouseNumber())
      return (DeleteHelper(add, Tree->left));
    else
      return (DeleteHelper(add, Tree->right));
  }
  else if (Tree->add1.getStreetName() > add.getStreetName())
    return (DeleteHelper(add, Tree->left));
  else
    return (DeleteHelper(add, Tree->right));
}
void BinaryTree::PrintHelper(Node * Tree)
{
  if (Tree != NULL)
  {
    //Print left subtree
    PrintHelper(Tree->left);
    //Call print method from Address class
    Tree->add1.print();
    //Print right subtree
    PrintHelper(Tree->right);
  }

}
