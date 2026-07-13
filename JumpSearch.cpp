#include <iostream>
#include <cmath>
#include <cstddef>

// Return value when target is not found
constexpr std::ptrdiff_t NOT_FOUND = -1;

/*
 * Jump Search
 *
 * PRECONDITION:
 * - Array must be sorted in ascending order.
 *
 * PARAMETERS:
 * - array  : Pointer to the first element of the array
 * - size   : Number of elements in the array
 * - target : Value to search for
 *
 * RETURNS:
 * - Index of target if found
 * - NOT_FOUND (-1) otherwise
 */
std::ptrdiff_t jumpSearch(const int* array,
                          std::size_t size,
                          int target)
{
    // Handle invalid input
    if (array == nullptr || size == 0)
    {
        return NOT_FOUND;
    }

    // Compute optimal jump size
    std::size_t jump =
        static_cast<std::size_t>(std::sqrt(size));

    // Safety for very small arrays
    if (jump == 0)
    {
        jump = 1;
    }

    std::size_t prev = 0;
    std::size_t pos  = 0;

    // Jump through blocks
    while (pos < size)
    {
        if (array[pos] == target)
        {
            return static_cast<std::ptrdiff_t>(pos);
        }

        if (array[pos] > target)
        {
            break;
        }

        prev = pos;
        pos += jump;
    }

    // Determine end of block safely
    std::size_t end =
        (jump > size - prev)
            ? size
            : prev + jump;

    // Linear search within identified block
    for (std::size_t i = prev; i < end; ++i)
    {
        if (array[i] == target)
        {
            return static_cast<std::ptrdiff_t>(i);
        }
    }

    return NOT_FOUND;
}

int main()
{
    int array[] =
    {
        2, 3, 4, 5, 6, 7,
        8, 9, 10, 11, 12, 13
    };

    std::size_t size = std::size(array);

    int target = 15;

    std::ptrdiff_t index =
        jumpSearch(array, size, target);

    if (index == NOT_FOUND)
    {
        std::cout << "Element "
                  << target
                  << " not found.\n";
    }
    else
    {
        std::cout << "Element "
                  << target
                  << " found at index "
                  << index
                  << '\n';
    }

    return 0;
}