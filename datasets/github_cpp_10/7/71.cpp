


#include <thrust/iterator/iterator_traits.h>

#include <thrust/detail/backend/cpp/merge.h>
#include <thrust/detail/backend/cpp/detail/insertion_sort.h>

namespace thrust
{
namespace detail
{
namespace backend
{
namespace cpp
{
namespace detail
{





template <typename RandomAccessIterator,
          typename StrictWeakOrdering>
void stable_merge_sort(RandomAccessIterator first,
                       RandomAccessIterator last,
                       StrictWeakOrdering comp)
{
    if (last - first < 32)
    {
        thrust::detail::backend::cpp::detail::insertion_sort(first, last, comp);
    }
    else
    {
        RandomAccessIterator middle = first + (last - first) / 2;

        thrust::detail::backend::cpp::detail::stable_merge_sort(first, middle, comp);
        thrust::detail::backend::cpp::detail::stable_merge_sort(middle,  last, comp);
        thrust::detail::backend::cpp::inplace_merge(first, middle, last, comp);
    }
}






template <typename RandomAccessIterator1,
          typename RandomAccessIterator2,
          typename StrictWeakOrdering>
void stable_merge_sort_by_key(RandomAccessIterator1 first1,
                              RandomAccessIterator1 last1,
                              RandomAccessIterator2 first2,
                              StrictWeakOrdering comp)
{
    if (last1 - first1 <= 32)
    {
        thrust::detail::backend::cpp::detail::insertion_sort_by_key(first1, last1, first2, comp);
    }
    else
    {
        RandomAccessIterator1 middle1 = first1 + (last1 - first1) / 2;
        RandomAccessIterator2 middle2 = first2 + (last1 - first1) / 2;

        thrust::detail::backend::cpp::detail::stable_merge_sort_by_key(first1, middle1, first2,  comp);
        thrust::detail::backend::cpp::detail::stable_merge_sort_by_key(middle1,  last1, middle2, comp);
        thrust::detail::backend::cpp::inplace_merge_by_key(first1, middle1, last1, first2, comp);
    }
}

} 
} 
} 
} 
} 

