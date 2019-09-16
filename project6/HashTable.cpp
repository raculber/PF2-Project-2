#include "HashTable.h"
//Implementation of HashTable Class
//Constructors and Deconstructor
HashTable::HashTable(int size)
{
  Size = size;
  Table = new List[Size];
}
//Copy Constructor
HashTable::HashTable(const HashTable &hash)
{
  Size = hash.Size;
  Table = new List[Size];
}
//Deconstructor
HashTable::~HashTable()
{
  Size = 0;
  delete [] Table;
}
//Insert Method
bool HashTable::Insert(int numKey, string nameKey, Address add)
{
  //Hash index
  int index = Hash(numKey, nameKey);
  return Table[index].Insert(add);
}
//Search Method
bool HashTable::Search(int numKey, string nameKey, float &lat, float &lon)
{
  //HashIndex
  int index = Hash(numKey, nameKey);
  return Table[index].Search(numKey, nameKey, lat, lon);
}
bool HashTable::Delete(int numKey, string nameKey, Address add)
{
  //Hash index
  int index = Hash(numKey, nameKey);
  return Table[index].Delete(add);
}
//Hash function
int HashTable::Hash(int numKey, string nameKey)
{
  int num = numKey;
  for (int i = 0; i < nameKey.length(); i++)
  {
    num = (num*(i+1)+(nameKey[i])) % Size;
  }
  return num;
}
void HashTable::Print()
{
  for(int i = 0; i < Size; i++)
    Table[i].Print();
}
