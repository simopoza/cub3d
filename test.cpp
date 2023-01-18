#include <iostream>
#include <vector>
#include <limits>
#include <cstddef>
#include <type_traits>
#include <unistd.h>

/*unsigned long long getTotalSystemMemory()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages page_size;
}*/

using namespace std;

template < class a >
void fun (a  = 5) {}

int main()
{
    vector<long> vec;
    cout << vec.max_size() << '\n';
    cout << numeric_limits<ptrdiff_t>::max()  << '\n';
}

//chofi 3elach