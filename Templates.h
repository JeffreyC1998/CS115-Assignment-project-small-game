#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
using namespace std;


template <typename T>
  T max (const T& a, const T& b, const T& c);
template <typename T>
  T median (const T& a, const T& b, const T& c);
template <typename T>
  T sum (const T& a, const T& b, const T& c);
template <typename T>
  T max (const T array[], unsigned int count);
template <typename T>
  T sum (const T array[], unsigned int count);
 



template <typename T>
T max (const T& a, const T& b, const T& c)
{
  if(a > b && a > c)
    return a;
  else if(b > c && b > a)
    return b;
  else if(c > b && c > a)
    return c;
}

template <typename T>
T median (const T& a, const T& b, const T& c)
{
  if(a <= b && a >= c)
    return a;
  else if(a <= c && a >= b)
    return a;
  else if(b <= a && b >= c)
    return b;
  else if(b <= c && b >= a)
    return b;
  else if(c <= a && c >= b)
    return c;
  else if(c <= b && c >= a)
    return c;
}

template <typename T>
T sum (const T& a, const T& b, const T& c)
{
  T sum_num;
  sum_num = a + b + c;
}

template <typename T>
T max (const T array[], unsigned int count)
{
  if(count >= 1)
    {
      T temp = 0;
      for(int i = 0;i < count;i++)
	{
	  if(array[i] > temp)
	    {
	      temp = array[i];
	    }
	}
      return temp;
    }
  else
    cout << "error!" << endl;
}

template <typename T>
T sum (const T array[], unsigned int count)
{
  if(count >= 1)
    {
      T sum = 0;
      for(int i = 0; i < count; i++)
	{
	  sum = sum + array[i];
	}
    }
  else
    cout << "error!" << endl;
}


#endif
