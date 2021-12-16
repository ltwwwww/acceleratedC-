// //四分位数
// #include <iostream>
// #include <algorithm>
// #include <vector>

// using std::vector;
// using std::sort;
// using std::cin;
// using std::cout; 
// using std::endl;

// int main(){
//     cout << "Please enter a series of numbers: ";
//     double x;
//     vector<double> num;
//     while(cin >> x){
//         num.push_back(x);
//     }
//     sort(num.begin(), num.end());
//     typedef vector<double>::size_type vec_sz;

//     vec_sz size = num.size();
//     vec_sz mid = size / 2;
    
//     double median = size % 2 == 0 ? (num[mid] + num[mid - 1]) / 2 : num[mid];

//     vec_sz halfsz = size % 2 == 0 ? size / 2 : (size - 1) / 2;
//     vec_sz halfmid = halfsz / 2;

//     double lowmid = halfsz % 2 == 0 ? (num[halfmid] + num[halfmid - 1]) / 2 : num[halfmid];
//     double upmid = 0;
//     if(size % 2 == 0)
//         upmid = halfsz % 2 == 0 ? (num[halfsz + halfmid] + num[halfsz + halfmid - 1]) / 2
//                                         : num[halfsz + halfmid];
//     else
//         upmid = halfsz % 2 == 0 ? (num[halfsz + halfmid + 1] + num[halfsz + halfmid]) / 2
//                                         : num[halfsz + halfmid + 1];
//     cout << "quater : " << lowmid << " " << median << " " << upmid << endl;
//     return 0;
// }
#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::copy;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <iterator>

int quartiles(vector<int>& someInts)
{
  sort(someInts.begin(), someInts.end());

  int quarter = someInts.size() / 4;
  int remainder = someInts.size() % 4;

  if (quarter == 0) 
  {
    cout << "Vector is smaller than 4 elements." << endl;
    return 1;
  }

  int start = someInts.size();

  for (int i = 0; i < 4; i++, remainder--) 
  {
    stringstream result;
    int quarterSize = remainder > 0 ? quarter + 1 : quarter;
    int stop = start - quarterSize;
    vector<int>::const_iterator first = someInts.begin() + stop;
    vector<int>::const_iterator last = someInts.begin() + start;
    copy(first, last, std::ostream_iterator<int>(result, " "));
    cout << "Quarter " << std::to_string(i + 1) << ": " + result.str() << endl;
    start -= quarterSize;
  }

  return 0;
}

int main()
{
  vector<int> someInts = { 10, 12, 5, 8, 13, 25, 1, 121, 85, 99, 120, 180, 75, 205, 16, 22, 99, 16 };

  return quartiles(someInts);
}