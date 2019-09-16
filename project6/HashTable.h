#include "List.h"
//Header file for HashTable Class
class HashTable
{
public:
  //Constructors and Deconstructor
  HashTable(int size);
  HashTable(const HashTable &hash);
  ~HashTable();
  bool Insert(int numKey, string nameKey, Address add);
  bool Search(int numKey, string nameKey, float &lat, float &lon);
  bool Delete(int numKey, string nameKey, Address add);
  int Hash(int numKey, string nameKey);
  //Print contents of HashTable
  void Print();
private:
  //Private data
  int Size;
  List *Table;
};
