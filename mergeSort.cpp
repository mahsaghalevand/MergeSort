
/**
 * @file mergeSort.cpp
 *
 * @author <a href="mailto:mahsa081997@gmail.com">Mahsa Ghalevand</a>
 * @date Sep 19, 2018
 */

#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>&, int, int);
void merge(vector<int>&, int start, int middle, int end);

int main()
{
  int number, numbers, start, end;
  vector<int> v;
  vector<int>::iterator it;

  cout << "How many numbers are there ?" << endl;
  cin >> numbers;
  v.reserve(numbers);
  cout << "enter numbers" << endl;
  for (int i = 0; i < numbers; i++)
  {
    cin >> number;
    v.push_back(number);
  }

  start = 0;
  end = (numbers - 1);
  mergeSort(v, start, end);

  cout << "sort :" << endl;
  for (it = v.begin(); it != v.end(); it++)
    cout << *it << "\t";

  return 0;
}

void mergeSort(vector<int> &theVector, int start, int end)
{
  int middle = (start + end) / 2;
  if (end - start == 0)
    return;

  mergeSort(theVector, start, middle);
  mergeSort(theVector, middle + 1, end);
  merge(theVector, start, middle, end);
}

void merge(vector<int>&theVector, int start, int middle, int end)
{
  vector<int> merge;
  int i = 0;
  int j = 1;

  while ((start+i) <= middle && (middle + j) <= end)
  {
    if (theVector.at(start + i) > theVector.at(middle + j))
    {
      merge.push_back(theVector.at(middle + j));
      j++;
    }

    else if (theVector.at(start + i) <= theVector.at(middle + j))
    {
      merge.push_back(theVector.at(start + i));
      i++;
    }

    if ((start + i) > middle && (middle + j) <= end)
    {
      while ((middle + j) <= end)
      {
        merge.push_back(theVector.at(middle + j));
        j++;
      }
      break;
    }

    if (i <= middle && (middle + j) > end)
    {
      while ((start+i) <= middle)
      {
        merge.push_back(theVector.at(start + i));
        i++;
      }
      break;
    }
  }

  vector<int>::iterator it1 = merge.begin();
  vector<int>::iterator it2  = theVector.begin() + start;

  while(it1 != merge.end())
  {
    *it2 = *it1;
    it1++;
    it2++;
  }

}
