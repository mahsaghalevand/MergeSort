
/**
 * @file mergeSort.cpp
 *
 * @author <a href="mailto:mahsa081997@gmail.com">Mahsa Ghalevand</a>
 * @date Sep 19, 2018
 */

#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& theVector, int start, int end);
void merge(vector<int>& theVector, int start, int middle, int end);

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
  int i = start;
  int j = middle+1;

  while (i <= middle &&  j <= end)
  {
    if (theVector.at(i) > theVector.at(j))
    {
      merge.push_back(theVector.at(j));
      j++;
    }

    else if (theVector.at(i) <= theVector.at(j))
    {
      merge.push_back(theVector.at(i));
      i++;
    }

    if (i > middle && j <= end)
    {
      while (j <= end)
      {
        merge.push_back(theVector.at(j));
        j++;
      }
      break;
    }

    if (i <= middle && j > end)
    {
      while (i <= middle)
      {
        merge.push_back(theVector.at(i));
        i++;
      }
      break;
    }
  }

  vector<int>::iterator it1 = merge.begin();
  vector<int>::iterator it2  = theVector.begin() + start;
  for(; it1 != merge.end(); it1++ , it2++)
    *it2 = *it1;



}
