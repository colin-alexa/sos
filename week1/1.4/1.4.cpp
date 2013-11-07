#include <iostream>
#include <istream>
#include <fstream>
using namespace std;


bool startswith(string text, string substring){
 if (substring.length() <= text.length() && (text.substr(0,substring.length()) == substring))
  return true;
 else
  return false;
}

string lstrip(string text, string unwanted){
 if (startswith(text, unwanted))
  return text.substr(unwanted.length(),text.length());
 else
  return text;
}

string include(ifstream * file){
 string output;
 output = "";
 
 while (true){
  string line;
  getline(*file, line);
  if (startswith(line, "#include ")){
   ifstream m;
   m.open(lstrip(line, "#include ").c_str());
   string tmp;
   if (m.is_open())
    tmp = include(&m);
   else
    tmp = "--ERROR--";

   if(!file->eof())
    output = output + tmp + "\n";
   else
    return output + tmp;
  } else {
   if(!file->eof())
    output = output + line + "\n";
   else
    return output + line;
    
  }
 }
 return output;
}

int main () {
  ifstream f1;
  f1.open("file1.cpp");

  ofstream f2;
  f2.open("file1.ins");
  f2 << include(&f1);
  f1.close();
  f2.close();

  cout << "done." << endl;

  return 0;
}

