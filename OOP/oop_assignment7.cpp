#include <iostream>
#include <cstdlib>
#include <list>
#include <iterator>

using namespace std;

template <class T>
class container{
    public: T item,a,b;
 };
 
 
int main(){
  int ch;
  container <int>c;
  list<int> g;
  list <int> :: iterator it; 
  do{
  cout << " 1. Stack Operations\n 2. Push Back\n 3. Pop Back \n 4. Queue Operations\n 5. Push Back\n 6. Push Front\n 7. Pop Front\n 8. Pop Back\n 9. Display"  <<  endl;
  cout << " > Enter your choice : ";
  cin >> ch;
  switch(ch)
  {
      case 2:cout << "Enter value to be inserted: ";
             cin >> c.item;
             g.push_back(c.item);
             break;
      case 3:  g.pop_back();  
      break;
      case 4: cout << " > Queue Operation";
      case 5: cout << " > Enter value to be inserted: ";
             cin >> c.item;
             g.push_back(c.item);
             break;
      case 6: cout << " > Enter value to be inserted: ";
             cin >> c.item;
             g.push_front(c.item);
             break;      
        case 7:  g.pop_front();         break;     
      case 8:  g.pop_back();          break;
      case 9: cout << " > Elements are";
              for(it = g.begin(); it != g.end(); ++it) 
                cout  <<  '\t'  <<  *it; 
                cout  <<  '\n';
              break;
  }
  }while(ch<=9);
  return 0;
}
