// https://www.youtube.com/watch?v=bFSnXNIsK4A&t=242s

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <map>
#include <chrono>
#include <functional>
#include <random>


// creating a template to print out anything using print instead of std::cout << ... << std::endl; as a title for the output
template <class T>
T print(T a)
{
	std::cout << std::endl << std::endl;
	std::cout << a << std::endl;
	return "";
}

void show_vector(std::vector<int> v1)
{
	std::for_each(v1.begin(), v1.end(), [](int i) -> void { std::cout << i << " "; });
	std::cout << std::endl;
}

int main()
{
	// for_each has a problem of mutating 
	std::vector<int> v1{ 3,5,2,5,1,6,7,8,4,6,3,5,3,5,3 };
	std::cout << "* The vector before modifying  *" << std::endl;
	std::for_each(v1.begin(), v1.end(), [](int i) -> void { std::cout << i << " "; });
	// for cant be replaced with for_each in all cases

	// heap algorithms
	print("*** Heap related algorithms ***");
	// make_heap
	std::make_heap(begin(v1), end(v1)); // use a vector to convert into heap to make getting the maximum value easy task
	show_vector(v1);
	// add to heap
	std::cout << "* Adding a 10 to the heap *" << std::endl;
	v1.push_back(10); // add some number to the vector made from heap
	std::push_heap(begin(v1), end(v1)); // push it to the right position in heap
	show_vector(v1);
	std::cout << "* Adding a 0 to the heap *" << std::endl;
	v1.push_back(0);
	std::push_heap(begin(v1), end(v1)); 
	show_vector(v1);
	//removing element from heap
	// it swaps the top most with the last element, then rearranges and makes it a new heap 
	std::pop_heap(begin(v1), end(v1));
	v1.pop_back();
	std::cout << "* Removing an element from the heap *" << std::endl;
	show_vector(v1);

	// sorting algorithms
	print("*** Sort related algorithms ***");
	// sort
	std::cout << "* Sorting a vector *" << std::endl;
	std::sort(begin(v1), end(v1));
	show_vector(v1);
	std::cout << "* Sorting only a part of the vector *" << std::endl;
	v1 = { 3,5,2,5,1,6,7,8,4,6,3,5,3,5,3 }; // redefining the vector since it is now sorted
	//partial_sort
	std::partial_sort(begin(v1), begin(v1)+10 ,end(v1));
	show_vector(v1);
	std::cout << "* Sorting only a part of the vector in descending manner *" << std::endl;
	v1 = { 3,5,2,5,1,6,7,8,4,6,3,5,3,5,3 };
	std::partial_sort(begin(v1), begin(v1) + 10, end(v1), [](int i, int j) {return(i > j); });
	show_vector(v1);
	// nth_element
	std::cout << "* Sorting only an element to see where it would have been if sorted as a whole vector, with unordered before and after elements*" << std::endl;
	std::nth_element(begin(v1), begin(v1) + 5, end(v1));
	show_vector(v1);
	// sort_heap ??
	// inplace_merge ??

	// partitioning algorithms
	print("*** Partition related algorithms ***");
	v1 = { 3,5,2,5,1,6,7,8,4,6,3,5,3,5,3 };
	std::cout << "* Partitioning odds and even *" << std::
		endl;
	std::partition(begin(v1), end(v1), [](int i) {return(i % 2 == 0); });
	show_vector(v1);
	// partition point
	auto p_p = std::partition_point(begin(v1), end(v1), [](int i) {return(i % 2 == 0); });
	std::cout << "* Elements before partition : ";
	show_vector(v1);
	std::cout << "* Elements after partition : ";
	show_vector(v1);

	// other algorithms that move elements inside the container
	// rotate
	std::iota(begin(v1), end(v1), 1);
	print("*** Rotating the elements inside the container ***");
	std::cout << "Before rotating  : ";
	show_vector(v1);
	std::cout << "After rotating with 5 steps  : ";
	std::rotate(begin(v1), begin(v1)+5 ,end(v1));
	show_vector(v1);
	// shuffle
	std::cout << "* Shuffling the elements inside the container *" << std::endl;
	std::iota(begin(v1), end(v1), 1);
	auto rng = std::default_random_engine{}; // required for function pass in shuffle parameter
	std::shuffle(begin(v1), end(v1), rng);
	show_vector(v1);
	// next_permutation
	std::cout << "* Next order of a vector *" << std::endl;
	std::next_permutation(begin(v1), end(v1));
	show_vector(v1);
	// prev_permutation
	std::cout << "* Previous order of a vector *" << std::endl;
	std::prev_permutation(begin(v1), end(v1));
	show_vector(v1);
	// reverse
	std::iota(begin(v1), end(v1), 1);
	std::cout << "* Reverses order of a vector *" << std::endl;
	std::reverse(begin(v1), end(v1));
	show_vector(v1);





	
	
	// to show the cmd display and wait till any key is pressed to disappear
	getchar();

	
}


/*
* The vector before modifying  *
3 5 2 5 1 6 7 8 4 6 3 5 3 5 3

*** Heap related algorithms ***
8 6 7 5 3 6 5 5 4 1 3 5 3 2 3
* Adding a 10 to the heap *
10 8 7 6 3 6 5 5 4 1 3 5 3 2 3 5
* Adding a 0 to the heap *
10 8 7 6 3 6 5 5 4 1 3 5 3 2 3 5 0
* Removing an element from the heap *
8 6 7 5 3 6 5 5 4 1 3 5 3 2 3 0


*** Sort related algorithms ***
* Sorting a vector *
0 1 2 3 3 3 3 4 5 5 5 5 6 6 7 8
* Sorting only a part of the vector *
1 2 3 3 3 3 4 5 5 5 8 7 6 6 5
* Sorting only a part of the vector in descending manner *
8 7 6 6 5 5 5 5 4 3 1 2 3 3 3
* Sorting only an element to see where it would have been if sorted as a whole vector, with unordered before and after elements*
1 2 3 3 3 3 4 5 5 5 5 6 6 7 8


*** Partition related algorithms ***
* Partitioning odds and even *
6 4 2 8 6 1 7 5 5 3 3 5 3 5 3
* Elements before partition : 6 4 2 8 6 1 7 5 5 3 3 5 3 5 3
* Elements after partition : 6 4 2 8 6 1 7 5 5 3 3 5 3 5 3


*** Rotating the elements inside the container ***
Before rotating  : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
After rotating with 5 steps  : 6 7 8 9 10 11 12 13 14 15 1 2 3 4 5
* Shuffling the elements inside the container *
5 1 4 2 14 8 15 12 13 9 6 3 10 11 7
* Next order of a vector *
5 1 4 2 14 8 15 12 13 9 6 3 11 7 10
* Previous order of a vector *
5 1 4 2 14 8 15 12 13 9 6 3 10 11 7
* Reverses order of a vector *
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

*/