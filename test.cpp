#include <iostream>
#include <vector>

using namespace std;


 int main()
 {
  vector<int> my_vector;

  for (int i = 1; i <= 5; i++)
  {
    my_vector.push_back(i*2);
  }

  cout << "Output of begin and end: ";

  for (int i = 0; i < my_vector.size(); i++)
  {
    cout << my_vector[i] << " ";

  }

 }

