#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;

struct coords
{
  long long point;
  char role;
  long long actualIndex;
};
void print_vector(vector<int> a)
{
  for (auto x : a)
  {
    std::cout << x << " ";
  }
}

void print(vector<coords> a)
{
  for (auto x : a)
  {
    std::cout << "start:" << x.point << ", role:" << x.role << "\n";
  }
}

bool compareFunc(coords a, coords b)
{
  if (a.point == b.point)
  {
    if (a.role == 'l')
    {
      return true;
    }
    else if (b.role == 'l')
    {
      return false;
    }
    else if (a.role == 'p')
    {
      return true;
    }
    else if (b.role == 'p')
    {
      return false;
    }
    else if (a.role == 'r')
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (a.point < b.point)
  {
    return true;
  }
  else
  {
    return false;
  }
}

vector<long long> fast_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points)
{
  vector<long long> cnt(points.size());
  vector<coords> all_points;
  for (long long unsigned int i = 0; i < starts.size(); i++)
  {
    coords c;
    c.point = starts[i];
    c.role = 'l';
    all_points.push_back(c);
  }
  for (long long unsigned int i = 0; i < ends.size(); i++)
  {
    coords c;
    c.point = ends[i];
    c.role = 'r';
    all_points.push_back(c);
  }
  for (long long unsigned int i = 0; i < points.size(); i++)
  {
    coords c;
    c.point = points[i];
    c.role = 'p';
    c.actualIndex = i;
    all_points.push_back(c);
  }
  std::sort(all_points.begin(), all_points.end(), compareFunc);
  print(all_points);
  long long segments = 0;
  for (long long unsigned int i = 0; i < all_points.size(); i++)
  {
    if (all_points[i].role == 'l')
    {
      segments++;
    }
    else if (all_points[i].role == 'p')
    {
      cnt[all_points[i].actualIndex] = segments;
    }
    else
    {
      segments--;
    }
  }
  return cnt;
}
vector<long long> naive_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points)
{
  vector<long long> cnt(points.size());
  for (long long unsigned int i = 0; i < points.size(); i++)
  {
    for (long long unsigned int j = 0; j < starts.size(); j++)
    {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main()
{
  while (true){
    long long n, m;
    n = 1 + rand() % 10;
    m = 1 + rand() % 10;

    vector<long long> starts(n), ends(n);
    for (long long unsigned int i = 0; i < starts.size(); i++)
    {
      starts[i] = rand() % 10;
      ends[i] = starts[i] + rand() % 10;
    }
    vector<long long> points(m);
    for (long long unsigned int i = 0; i < points.size(); i++)
    {
      points[i] = rand() % 10;
    }
    //use fast_count_segments
    vector<long long> cnt_fast = fast_count_segments(starts, ends, points);
    vector<long long> cnt_naive = naive_count_segments(starts,ends, points);
    for (long long unsigned int i = 0; i < cnt_naive.size(); i++)
    {
      if (cnt_fast[i] == cnt_naive[i])
        std::cout << "OK!!!" << "\n";
      else{
        std::cout << "n : " << n << " m : " << m << "\n";
        std::cout << "Segments : \n";
        for(int i=0; i<n; i++){
          
          std::cout << starts[i] << " " << ends[i] << "\n";
        }
        std::cout << "\n Points : \n";
        for(int i=0; i<n; i++){
          std::cout << points[i] << " ";
        }
        std::cout << "\n Naive : ";
        for (int i=0; i<n; i++){
          std::cout << cnt_naive[i] << " ";
        }
        std::cout << "\n Fast : ";
        for (int i=0; i<n; i++){
          std::cout << cnt_fast[i] << " ";
        }
        std::cout<< "\n";
        break;

      }
    }
  }
}
