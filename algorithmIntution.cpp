// https://www.youtube.com/watch?v=M1lNNFwxUVI&t=1599s

#include <iostream> // cout
#include <string>
#include <vector> //vector
#include <iterator> // istream_iterator
#include <algorithm> // for_each,
#include <numeric> // iota, inclusive_scan
#include <map>
#include <chrono> // timing
#include <cmath> // sqrt
#include <functional>
//#include <execution> // // available in full version of c++17

// creating a template to print out anything using print instead of std::cout << ... << std::endl; as a title for the output
template <class T>
T print(T a)
{
    std::cout << std::endl << std::endl;
    std::cout << a << std::endl ;
}


int custom_operation(int x, int y)
{
   return x*y;
}

int main()
{

    // time capturing
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
//        std::chrono::duration<double, std::milli> m = t2 - t1; // or this can be "autoed"
    auto m = t2 - t1;
    std::cout << "Time difference is : \n" << m.count() << std::endl;


    // for, to iterate over a vector and auto, to assign automatic type
    std::vector<int> v1{34,21,54,78,34,12,56,7,89,45,23,5,78,49,17,34,2};
    print("Displaying the vector created using for and auto");
    for (auto i : v1)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // rbegin, gives the last value of the vector
    print("Begining and end element display - Version 1");
    std::cout << *v1.begin() <<std::endl; // gives the first value
    std::cout << *v1.end() <<std::endl; // gives the last value
    std::cout << *v1.rbegin() <<std::endl; // r makes the vector reverse
    std::cout << *v1.rend() <<std::endl; // r makes the vector reverse

    // to avoid dereferencing
    print("Begining and end element display - Version 2");
    std::cout << v1.back() <<std::endl;
    std::cout << v1.front() <<std::endl;

    //minimum and maximum in a vector
    print("Minimum and maximum in a vector -  Version 1");
    auto min1 = *min_element(begin(v1),end(v1));
    auto max1 = *max_element(begin(v1),end(v1));
    std::cout << min1 << " and " << max1 << std::endl;

    // both in one shot
    print("Minimum and maximum in a vector -  Version 2");
    auto [min,max] = std::minmax_element(begin(v1),end(v1)); // structural binding (17) like in Python
    std::cout << *min << " and " << *max <<  std::endl;

    // another way of using minmax_element
    print("Minimum and maximum in a vector -  Version 3");
    auto mnm = std::minmax_element(begin(v1),end(v1));
    std::cout << *mnm.first << " and " << *mnm.second << std::endl;

    // by not mutating the vector
    print("Minimum and maximum in a vector -  Version 4 (no mutation)");
    auto [min2,max2] = std::minmax_element(cbegin(v1),cend(v1));
    std::cout << *min2 << " and " << *max2 <<  std::endl;

    // in cpp 20, begin and end iterators will not be required, the vector can be directly passed as range based

    // iota to create a range
    print("Creating and filling vector with a range of numbers");
    std::vector<int> v2(10); // initializing a vector wit 10 size
    std::iota(begin(v2),end(v2),2); // number to start with
    std::for_each(v2.begin(), v2.end(), [](int i)->void {std::cout << i <<std::endl;}); // showing out the vector

    // accumulate, default operation is to add everything
    print("Sum finding using accumulate");
    auto sum = std::accumulate(begin(v1), end(v1), 0);
    std::cout << sum << std::endl;

    // accumulate with any other function than the default sum
    print("Product finding using accumulate with custom function");
    auto pro1 = std::accumulate(begin(v1), end(v1), 1 ,custom_operation);
    std::cout << pro1 << std::endl;

    // using inbuilt functions to find product
    print("Product finding using accumulate with inbuilt function");
    auto pro2 = std::accumulate(begin(v1), end(v1), 1 ,std::multiplies{});
    std::cout << pro2 << std::endl;
    print("Product finding using accumulate with inbuilt function, with identity value as 0");
    auto pro3 = std::accumulate(begin(v1), end(v1), 0 ,std::multiplies{}); // 0 is the first value, identity value
    std::cout << pro3 << std::endl;
    print("Product finding using accumulate with inbuilt function, of a sub vector");
    auto pro4 = std::accumulate(begin(v1)+10, end(v1), 1 ,std::multiplies{}); // sub listing
    std::cout << pro4 << std::endl;

    // similar to accumulate, there is reduce
    // auto pro5 = std::reduce(cbegin(v1), cend(v1), 1, std::multiplies{}); // available in full version of c++17
    // std::cout << pro5 << std::endl;

    // count of a number in a vector
    print("Number count");
    auto c1 = std::count(begin(v1), end(v1), 34 );
    std::cout << c1 << std::endl;

    // finding if a number exists
    print("Number presence");
    auto f1 = std::any_of(begin(v1), end(v1), [](auto e){return e==34;}); // lambda function
    std::cout << f1 << std::endl;

    // adjacent difference
    print("Finding maximum difference between adjacent numbers post sorting");
    std::sort(begin(v1),end(v1)); // sorting the original vector
    std::vector<int> d(v1.size()); // creating a new vector with the size of the sorted one
    std::adjacent_difference(begin(v1), end(v1), begin(d)); // finding the differences
    std::cout << *std::max_element(cbegin(d)+1, cend(d)) << std::endl; // since the difference will have one element less, +1

    // displaying differences
    print("Displaying the differenced vector");
    std::for_each(d.begin(), d.end(), [](int i)->void {std::cout << i <<" ";});
    std::cout << std::endl;

    // finding root mean square
    print("Using accumulate and lambdas for finding root mean square");
    std::cout << sqrt(std::accumulate(begin(v1), end(v1), 0.0,
            [](double partialSum, double element){
        return partialSum + element * element;
    })) << std::endl;

    // inner_product, takes in two lists and performs a transform and a fold operation
    print("Using inner_product for finding root mean square, where default transform is product and default reduce is addition");
    std::cout << sqrt(std::inner_product(begin(v1), end(v1), begin(v1), 0.0)) << std::endl;

    print("Using inner_product for finding root mean square, where custom transform and reduce lambda functions");
    std::vector<int> v3{34,71,54,78,34,12,56,7,1,34,9,5,78,39,17,34,23};
    std::cout << std::max(0,std::inner_product(begin(v1), end(v1), begin(v3),0,
            [](auto a, auto b){return(std::max(a,b));},
            [](auto a, auto b){return(a-b/4);}
            )) << std::endl;

    // since inner_product is not intuitive, we get transform_reduce in c++17
    // cant use it now as the compiler doesn support the parallelism stuff
//    print("Transform_reduce example");
//    std::vector<int> v4{1,2,3,4,5};
//    std::vector<int> v5{3,7,1,8,3};
//    std::cout << std::transform_reduce(...)

    std::vector<int> v4{1,2,3,4,5};
    std::vector<int> v5(5,0);
    print("Partial sum");
    // not working
//    std::partial_sum(cbegin(v4),cend(v4),cbegin(v5));
//    std::inclusive_sum
// 
}

/*

Time difference is :
0


Displaying the vector created using for and auto
34 21 54 78 34 12 56 7 89 45 23 5 78 49 17 34 2


Begining and end element display - Version 1
34
0
2
201391534


Begining and end element display - Version 2
2
34


Minimum and maximum in a vector -  Version 1
2 and 89


Minimum and maximum in a vector -  Version 2
2 and 89


Minimum and maximum in a vector -  Version 3
2 and 89


Minimum and maximum in a vector -  Version 4 (no mutation)
2 and 89


Creating and filling vector with a range of numbers
2
3
4
5
6
7
8
9
10
11


Sum finding using accumulate
638


Product finding using accumulate with custom function
770879488


Product finding using accumulate with inbuilt function
770879488


Product finding using accumulate with inbuilt function, with identity value as 0
0


Product finding using accumulate with inbuilt function, of a sub vector
508096680


Number count
3


Number presence
1


Finding maximum difference between adjacent numbers post sorting
22


Displaying the differenced vector
2 3 2 5 5 4 2 11 0 0 11 4 5 2 22 0 11


Using accumulate and lambdas for finding root mean square
188.457


Using inner_product for finding root mean square, where default transform is product and default reduce is addition
188.457


Using inner_product for finding root mean square, where custom transform and reduce lambda functions
84


Partial sum

*/
