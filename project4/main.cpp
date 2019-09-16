#include "Stack.h"
#include <iostream>
#include <string>
#include <fstream>
//Program will check HTML tags using stacks
int main()
{
  string fileName;
  Stack tags;
  ifstream din;
  //Tags that do not require end tags
  string specialTags[] = {"br", "hr", "img", "input", "meta"};
  char ch = ' ';
  cout << "Enter the name of the HTML file you want to check: " << endl;
  cin >> fileName;
  //Opens the file that the user inputted
  din.open(fileName);
  //Ends program if file failed to open
  if (din.fail())
  {
    return 0;
  }
  //Loops until end of file is reached
  while (!din.eof())
  {
    //Gets single characters from the file
    din.get(ch);
    //Checks if character is start of tag
    if (ch == '<')
    {
      string start = "";
      string end = "";
      din.get(ch);
      //Checks if end tag
      if (ch == '/')
      {
        string top;
        tags.Top(top);
        //Stores tag name in string variable
        while (ch != '>')
        {
          din.get(ch);
          if (ch != '>')
            end += ch;
        }
        //Removes from stack if top tag matches end tag
        if (end == top)
        {
          tags.Pop(end);
          tags.Print();
        }
        //Matching tags not found
        else
        {
          cout << "Tag nesting error" << endl;
          return 0;
        }
      }
      //Start tag
      else
      {
        bool isSpecial = false;
        //Checks if tag has space
        bool space = false;
        //Stores tag name in string variable
        while (ch != '>')
        {
          //Checks if tag has a space with extra attributes
          if (ch == ' ')
            space = true;
          //Characters after space will not be added to the tag name
          if (space)
          {
            din.get(ch);
          }
          else
          {
            start += ch;
            din.get(ch);
          }
        }
        //Checks the tags that do not require an end tag
        for (int i = 0; i < 3; i++)
        {
          if (start == specialTags[i])
            isSpecial = true;
        }
        //Pushes non-special starting tags into the stack
        if (isSpecial == false)
        {
          tags.Push(start);
          tags.Print();
        }
      }
    }
  }
  /*Starting tag is still in stack
  (no matching end tag was found)*/
  if (!tags.IsEmpty())
    cout << "ERROR: " << tags.GetLength() << " missing end tag/s" << endl;
  return 0;
}
