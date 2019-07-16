// https://www.youtube.com/watch?v=bFSnXNIsK4A&t=242s

// #include "stdafx.h" // for VS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <map>
#include <chrono> //
#include <functional>
#include <random> // sample



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
    // is_heap
    std::cout << "* Is it a heap or not *\n";
    std::cout << "The vector is a heap : " << std::is_heap(begin(v1), end(v1)) << std::endl;
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

    // suffixes and prefixes to algorithms
    print("*** Suffixes and prefixes to algorithms to modify them ***");
    print("** Stable and is **");
    // stable_sort
    std::cout << "* Stable sort *\n"; // does the same as sort but keeps relative order ??
    v1 = { 3,5,2,5,1,6,7,8,4,6,3,5,3,5,3 };
    std::stable_sort(begin(v1), end(v1));
    show_vector(v1);
    // is_sorted
    std::cout << "* Is it sorted or not sort *\n";
    std::cout << "The vector is sorted: " << std::is_sorted(begin(v1), end(v1)) << std::endl;
    // stable_partition
    std::cout << "* Stable partition *\n"; // does the same as partition but keeps relative order ??
    v1 = { 3,5,2,5,1,6,7,8,4,6,3,5,3,5,3 };
    std::stable_partition(begin(v1), end(v1), [](int i) {return i % 2 == 0; });
    show_vector(v1);
    // is_partitioned
    std::cout << "* Is it partitioned or not *\n";
    std::cout << "The vector is partitioned: " << std::is_partitioned(begin(v1), end(v1), [](int i) {return i % 2 == 0; }) << std::endl;

    // is_sorted_until
    // is_partitioned_until
    // is_heap_until

    // others were not explained ??

    // numeric algorithm
    print("*** Numeric Algorithm ***");
    // count
    std::cout << "* Count of occurances *" << std::endl;
    std::cout << "The number of 3s in the vector is : " << std::count(begin(v1), end(v1), 3) << std::endl;
    // accumulate
    std::cout << "* Accumulate *" << std::endl;
    std::cout << std::accumulate(begin(v1), end(v1), 1, std::multiplies<int>()) << std::endl;

    // reduce
    // it is similar to accumulate, but can accpet no initial value and can be run in parallel
    /*std::cout << "* Reduce *" << std::endl;
    std::cout << std::reduce(begin(v1), end(v1), 1, std::multiplies<int>()) << std::endl;*/

    // transform_reduce
    // takes in a function, applies it to all and then reduces based on the function passed

    // pratial sum
    std::cout << "* Partial sum default *" << std::endl;
    std::partial_sum(v1.begin(), v1.end() , v1.begin());
    for(auto i : v1)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    v1 = { 3,5,2,5,1,6,7,8,4,6,3,5,3,5,3 };
    std::cout << "* Partial sum with plus, same output *" << std::endl;
    std::partial_sum(v1.begin(), v1.end(), v1.begin(), std::plus<int>{});
    for(auto i : v1)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    // scan c++17 ?? parallel
    // std::inclusive_scan(v1.begin(), v1.end(),std::ostream_iterator<int>(std::cout, " "));
    // std::exclusive_scan(v1.begin(), v1.end(),std::ostream_iterator<int>(std::cout, " "));

    // transform_inclusive_scan ??
    // transform_exclusive_scan ??

    // inner_product
    std::cout << "* Inner product *" << std::endl;
    // multiplies all the elements with the corresponding pair and sums them up
    std::cout << "Default Inner product : ";
    std::cout << std::inner_product(begin(v1),end(v1),begin(v1),1) << std::endl;
    // customized using functions as parameters
    std::cout << "Modified inner product with fucntions as arguments : ";
    auto inner_output = std::inner_product(begin(v1),end(v1),begin(v1),1,
                                           std::multiplies<int>(),
                                           std::plus<int>()) ;
    std::cout << inner_output << std::endl;

    // adjacent_difference
    std::cout << "* Adjacent difference *" << std::endl;
    // difference between adjacent elemets in a vector
    std::vector<int> adj_diff_output(15);
    std::adjacent_difference(begin(v1), end(v1), begin(adj_diff_output));
    show_vector(adj_diff_output);

    // sample ??
    // std::cout << " * Random value subset *" << std::endl;
    // std::sample(begin(v1), end(v1), 10);
    // show_vector(v1);

    print("*** Query ***");
    // all_of
    std::cout << "* All of  *\n"; // returns true with empty collection
    std::vector<int> multiples_of_3{3,69,69,69,69,696,3,36,39,69};
    show_vector(multiples_of_3);
    std::cout << "All the numbers in the vector are multiples of 3 : " <<std::all_of(begin(multiples_of_3),end(multiples_of_3), [](int i ){return i%3==0;}) << std::endl;
    // any_of
    std::cout << "* Any of  *\n"; // returns false with empty collection
    std::vector<int> might_contain_2{4,2,3,69,69,69,69,696,3,36,39,69};
    show_vector(might_contain_2);
    std::cout << "Does the vector have 2 in it : " << std::any_of(begin(might_contain_2),end(might_contain_2), [](int i ){return i==2;}) << std::endl;
    // none_of
    std::cout << "* None of  *\n"; // returns true with empty collection
    show_vector(might_contain_2);
    std::cout << "None of the elements are divisible by 7 : " << std::none_of(begin(might_contain_2),end(might_contain_2), [](int i ){return i%7==0;}) << std::endl;

    // equal
    std::cout << "* Equal  *\n"; // size, elements and elemets position all same
    std::cout << "Checking if the vectors are equal in all aspects: " << std::equal(begin(might_contain_2),end(might_contain_2), begin(might_contain_2)) << std::endl;
    // lexicographical_compare
    std::cout << "* Lexicon equal  *\n"; // subset and placement in dictionary
    std::vector<int> might_contain_2_sub(might_contain_2.begin(), might_contain_2.end() - 2); // sub vector creation
    std::cout << "Checking if the first vector is smaller : " << std::lexicographical_compare(begin(might_contain_2),end(might_contain_2), begin(might_contain_2_sub), end(might_contain_2_sub)) << std::endl;
    std::cout << "Checking if the first vector is smaller : " << std::lexicographical_compare(begin(might_contain_2_sub),end(might_contain_2_sub), begin(might_contain_2), end(might_contain_2)) << std::endl;
    // mismatch
    std::cout << "* Mismatch  *\n"; // size, elements and elemets position all same
    std::vector<int> v2{2,4,6,8,10};
    std::cout << "Vector one : ";
    show_vector(v2);
    std::vector<int> v3{2,4,6,9,10};
    std::cout << "Vector two : ";
    show_vector(v3);
    auto [p1,p2] = std::mismatch(begin(v2),end(v2), begin(v3)); // gives a pair of iterators
    std::cout << "First value where the first vector mismatch: " << *p1 << std::endl;
    std::cout << "First value where the second vector mismatch: " << *p2 << std::endl;
    // find
    std::cout << "* Find in unsorted *\n";
    std::vector<int> v4{7,2,5,1,1,3,2,5,2,6,3};
    show_vector(v4);
    std::cout << "Where is 1 present in vector? : " << *std::find(v4.begin(),v4.end(),1) << std::endl;
    std::cout << "Where is 10 present in vector? : " << *std::find(v4.begin(),v4.end(),10) << std::endl; // output ??
    // adjacent_find
    std::cout << "* Adjacent find in unsorted *\n";
    std::cout << "Find if there is a twin together : " << *std::adjacent_find(v4.begin(),v4.end()) << std::endl;
    show_vector(v3);
    std::cout << "Find if there is a twin together : " << *std::adjacent_find(v3.begin(),v3.end()) << std::endl; // output ??
    // equal_range
    std::cout << "* Find in sorted *\n";
    std::sort(begin(v4),end(v4));
    std::cout << "Finding a range for a given numbers" <<std::endl;
    auto equal_range_output = std::equal_range(begin(v4),end(v4),3);
    std::cout << "Number where 3 starts is :" << *equal_range_output.first << std::endl;
    std::cout << "NUmber where 3 ends is :" << *equal_range_output.second << std::endl;
    // lower_bound
    show_vector(v4);
    std::cout << "* Find Lower bound *\n";
    std::cout << "Lower position to insert 2 : "<< *std::lower_bound(begin(v4),end(v4),2) << std::endl;
    // upper_bound
    show_vector(v4);
    std::cout << "* Find Upper bound *\n";
    std::cout << "Upper position to insert 2 : "<< *std::upper_bound(begin(v4),end(v4),2) << std::endl;
    // binary_search
    std::cout << "* Binary search *\n"; // just sayins in it or not, no position returned
    std::cout << "Binary search for 2 : " << std::binary_search(begin(v4),end(v4),2) << std::endl;
    std::cout << "Binary search for 8 : " << std::binary_search(begin(v4),end(v4),8) << std::endl;

    // search ??
    // find_end ??
    // find_first_of ??
    // max_element
    std::cout << "* Maximum value *\n";
    show_vector(v4);
    std::cout << "The maximum number is " << *std::max_element(begin(v4),end(v4)) << std::endl;
    // min_element
    std::cout << "* Minimum value *\n";
    show_vector(v4);
    std::cout << "The Minimum number is " << *std::min_element(begin(v4),end(v4)) << std::endl;
    // minmax_element
    std::cout << "* Maximum and minimum value *\n";
    show_vector(v4);
    auto [min,max] = std::minmax_element(begin(v4),end(v4));
    std::cout << "The minimum and maximum number is " << *min << " " << *max << std::endl;

    //sets
    print("*** Sets ***");
    // set_differences
    std::vector<int> set_1{2,4,1,4,2,5,6,4,4,4};
    std::cout << "The vectors are" << std::endl;
    std::sort(begin(set_1),end(set_1));
    std::vector<int> set_2{3,5,2,5,2,4,2,5,1,7};
    std::sort(begin(set_2),end(set_2));
    std::vector<int> v5(set_1.size()); // empty vector of size of vector
    show_vector(set_1);
    show_vector(set_2);
    std::cout << "The difference from the first one is :" << std::endl;
    std::set_difference(begin(set_1),end(set_1),begin(set_2),end(set_2),v5.begin()); // only whats in set_1 but not in set_2
    show_vector(v5);
    // set_intersection
    std::vector<int> v6(set_1.size());
    std::cout << "The common elements are :" << std::endl;
    std::set_intersection(begin(set_1),end(set_1),begin(set_2),end(set_2),v6.begin()); // only whats in set_1 but not in set_2
    show_vector(v6);
    // set_union
    std::vector<int> v7(set_1.size());
    std::cout << "All the elements are :" << std::endl;
    std::set_union(begin(set_1),end(set_1),begin(set_2),end(set_2),v7.begin()); // only whats in set_1 but not in set_2
    show_vector(v7);
    // set_symmetric_differences
    std::vector<int> v8(set_1.size());
    std::cout << "All the elements, except common ones are :" << std::endl;
    std::set_symmetric_difference(begin(set_1),end(set_1),begin(set_2),end(set_2),v8.begin()); // only whats in set_1 but not in set_2
    show_vector(v8);
    // includes
    std::cout << "If the sets are subsets : " ;
    std::cout << std::includes(begin(set_1),end(set_1),begin(set_2),end(set_2)) << std::endl;
    // merge
    std::vector<int> v9(set_1.size());
    std::cout << "If the sets are merged : " ;
    std::merge(begin(set_1),end(set_1),begin(set_2),end(set_2), v9.begin());
    show_vector(v9);

    // movers
    print("*** Movers ***");











    // to show the cmd display and wait till any key is pressed to disappear
    getchar();


}


/*

* The vector before modifying  *
3 5 2 5 1 6 7 8 4 6 3 5 3 5 3

*** Heap related algorithms ***
8 6 7 5 3 6 5 5 4 1 3 5 3 2 3
* Is it a heap or not *
The vector is a heap : 1
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
* Sorting only an element to see where it would have been if sorted as a whole vector, with unordered before and after e
lements*
3 3 1 2 3 3 4 5 8 5 5 5 6 6 7


*** Partition related algorithms ***
* Partitioning odds and even *
6 4 2 8 6 1 7 5 5 3 3 5 3 5 3
* Elements before partition : 6 4 2 8 6 1 7 5 5 3 3 5 3 5 3
* Elements after partition : 6 4 2 8 6 1 7 5 5 3 3 5 3 5 3


*** Rotating the elements inside the container ***
Before rotating  : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
After rotating with 5 steps  : 6 7 8 9 10 11 12 13 14 15 1 2 3 4 5
* Shuffling the elements inside the container *
14 1 12 11 6 10 9 7 13 15 8 5 3 4 2
* Next order of a vector *
14 1 12 11 6 10 9 7 13 15 8 5 4 2 3
* Previous order of a vector *
14 1 12 11 6 10 9 7 13 15 8 5 3 4 2
* Reverses order of a vector *
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1


*** Suffixes and prefixes to algorithms to modify them ***


** Stable and is **
* Stable sort *
1 2 3 3 3 3 4 5 5 5 5 6 6 7 8
* Is it sorted or not sort *
The vector is sorted: 1
* Stable partition *
2 6 8 4 6 3 5 5 1 7 3 5 3 5 3
* Is it partitioned or not *
The vector is partitioned: 1


*** Numeric Algorithm ***
* Count of occurances *
The number of 3s in the vector is : 4
* Accumulate *
816480000
* Partial sum default *
2 8 16 20 26 29 34 39 40 47 50 55 58 63 66
* Partial sum with plus, same output *
3 8 10 15 16 22 29 37 41 47 50 55 58 63 66
* Inner product *
Default Inner product : 24453
Modified inner product with fucntions as arguments : 1207959552
* Adjacent difference *
3 5 2 5 1 6 7 8 4 6 3 5 3 5 3


*** Query ***
* All of  *
3 69 69 69 69 696 3 36 39 69
All the numbers in the vector are multiples of 3 : 1
* Any of  *
4 2 3 69 69 69 69 696 3 36 39 69
Does the vector have 2 in it : 1
* None of  *
4 2 3 69 69 69 69 696 3 36 39 69
None of the elements are divisible by 7 : 1
* Equal  *
Checking if the vectors are equal in all aspects: 1
* Lexicon equal  *
Checking if the first vector is smaller : 0
Checking if the first vector is smaller : 1
* Mismatch  *
Vector one : 2 4 6 8 10
Vector two : 2 4 6 9 10
First value where the first vector mismatch: 8
First value where the second vector mismatch: 9
* Find in unsorted *
7 2 5 1 1 3 2 5 2 6 3
Where is 1 present in vector? : 1
Where is 10 present in vector? : 1145853256
* Adjacent find in unsorted *
Find if there is a twin together : 1
2 4 6 9 10
Find if there is a twin together : 1146904948
* Find in sorted *
Finding a range for a given numbers
Number where 3 starts is :3
NUmber where 3 ends is :5
1 1 2 2 2 3 3 5 5 6 7
* Find Lower bound *
Lower position to insert 2 : 2
1 1 2 2 2 3 3 5 5 6 7
* Find Upper bound *
Upper position to insert 2 : 3
* Binary search *
Binary search for 2 : 1
Binary search for 8 : 0
* Maximum value *
1 1 2 2 2 3 3 5 5 6 7
The maximum number is 7
* Minimum value *
1 1 2 2 2 3 3 5 5 6 7
The Minimum number is 1
* Maximum and minimum value *
1 1 2 2 2 3 3 5 5 6 7
The minimum and maximum number is 1 7


*** Sets ***
The vectors are
1 2 2 4 4 4 4 4 5 6
1 2 2 2 3 4 5 5 5 7
The difference from the first one is :
4 4 4 4 6 0 0 0 0 0
The common elements are :
1 2 2 4 5 0 0 0 0 0
All the elements are :

*/
