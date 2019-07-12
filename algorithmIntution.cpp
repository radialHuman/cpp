// https://www.youtube.com/watch?v=M1lNNFwxUVI&t=1599s

#include <iostream> // cout
#include <string>
#include <vector> //vector
#include <iterator> // istream_iterator
#include <algorithm> // for_each,
#include <numeric> // iota

int custom_operation(int x, int y)
{
   return x*y;
}

int main()
{
        std::vector<int> v1{34,21,54,78,34,12,56,7,89,45,23,5,78,49,17,34,2};

        // for, to iterate over a vector and auto, to assign automatic type
        for (auto i : v1){
            std::cout << i << " ";
        }
        std::cout << std::endl;

        // rbegin, gives the last value of the vector
        std::cout << *v1.begin() <<std::endl; // gives the first value
        std::cout << *v1.end() <<std::endl; // gives the last value
        std::cout << *v1.rbegin() <<std::endl; // r makes the vector reverse
        std::cout << *v1.rend() <<std::endl; // r makes the vector reverse

        // to avoid dereferencing
        std::cout << v1.back() <<std::endl;
        std::cout << v1.front() <<std::endl;

        //minimum and maximum in a vector
        auto min1 = *min_element(begin(v1),end(v1));
        auto max1 = *max_element(begin(v1),end(v1));
        std::cout << min1 << " and " << max1 << std::endl;

        // both in one shot
        auto [min,max] = std::minmax_element(begin(v1),end(v1)); // structural binding (17) like in Python
        std::cout << *min << " and " << *max <<  std::endl;

        // another way of using minmax_element
        auto mnm = std::minmax_element(begin(v1),end(v1));
        std::cout << *mnm.first << " and " << *mnm.second << std::endl;

        // by not mutating the vector
        auto [min2,max2] = std::minmax_element(cbegin(v1),cend(v1));
        std::cout << *min2 << " and " << *max2 <<  std::endl;

        // in cpp 20, begin and end iterators will not be required, the vector can be directly passed as range based

        // iota to create a range
        std::vector<int> v2(10); // initializing a vector wit 10 size
        std::iota(begin(v2),end(v2),2); // number to start with
        std::for_each(v2.begin(), v2.end(), [](int i)->void {std::cout << i <<std::endl;}); // showing out the vector

        // accumulate, default operation is to add everything
        auto sum = std::accumulate(begin(v1), end(v1), 0);
        std::cout << sum << std::endl;

        // accumulate with any other function than the default sum
        auto sum2 = std::accumulate(begin(v1), end(v1), 1 ,custom_operation);
        std::cout << sum2 << std::endl;

}


/*

34 21 54 78 34 12 56 7 89 45 23 5 78 49 17 34 2
34
0
2
201334990
2
34
2 and 89
2 and 89
2 and 89
2 and 89
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
638
770879488

*/