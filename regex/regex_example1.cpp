#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char* argv[]){
  regex integer("(\\+|-)?[[:digit:]]+");
  string input = {};
  /* Evaluate input as long as its an integer */
  while(true){
    cout << "\nGive an integer\n";
    cin >> input;
    /* the cin implements the boolean() operator, this sohuld return !false if cin has an error*/
    /* The cin, cout implement the fail method */
    if(!cin) break;  
    /* Same as  */
    if(cin.fail()){
      cout << "fail, we will never reach this point" << endl;
      cin.clear(); // clean error flags
      cin.ignore(999, '\n'); // ignore 999 chars until a \n appers

      /* Also */
    }

    if(input == "q") break;

    if(regex_match(input, integer)){
      cout << "int";
    } else {
      cout << "Invalid shit";
    }
  }

  int i;
  while(!(cin >> i)){
    cin.clear();
    cin.ignore(999,'\n');
    cout << "ffffuuu give an int to exit" << endl;
  }

  exit(0);
}
