#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <bits/stdc++.h> 

using std::vector;
using std::swap;
using std::sort;

struct Segment {
  int start, end;
};

   
vector<Segment> sort_segment(vector<Segment> &S){
	int n = S.size();
	std::vector<Segment> S1(n);
	std::vector<int> end_points(n);
	std::vector<int> start_points(n);
	
	// assignments of segments endpoint to the end_points array
	for (int i=0; i<n; i++){
		end_points[i] = S[i].end;
		start_points[i] = S[i].start;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if (end_points[j] > end_points[j+1]){
				swap(end_points[j], end_points[j+1]);
				swap(start_points[j], start_points[j+1]);
			}
		}
	}
	for(int i=1; i<=n; i++){
		S1[i-1].start = start_points[i];
		S1[i-1].end = end_points[i];
	}

	return S1;

}
								


vector<int> optimal_points(vector<Segment> &segments) {
  int n = segments.size();
  vector<int> points;
  //write your code here
  int k = 0;
  for (int i=0; i<n; i++){
  	if (segments[i].end != 0){
  		points.push_back(segments[i].end);
  		for(int j=i; j<n; j++){
  			if (segments[j].start <= points[k] && segments[j].end >= points[k]){
  				segments[j].start = 0;
  				segments[j].end = 0;
  			}
  		}
  		k++;
  	}
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  // Testing the sort_segments funtion and printing the value
  std::vector<Segment> S1(n);

  S1 = sort_segment(segments);

  // // printing the segments sorted order based on end points

  // for (size_t i = 0; i < n; ++i) {
  //   std::cout << S1[i].start << " " << S1[i].end << " ";
  // }
  // std::cout<< "\n";






  vector<int> points = optimal_points(S1);


  std::cout << points.size() << "\n";

  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}