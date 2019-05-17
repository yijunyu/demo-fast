

#ifndef BX_RADIXSORT_H_HEADER_GUARD
#define BX_RADIXSORT_H_HEADER_GUARD

#include "bx.h"

namespace bx
{
#define BX_RADIXSORT_BITS 11
#define BX_RADIXSORT_HISTOGRAM_SIZE (1<<BX_RADIXSORT_BITS)
#define BX_RADIXSORT_BIT_MASK (BX_RADIXSORT_HISTOGRAM_SIZE-1)

	template <typename Ty>
	void radixSort32(uint32_t* __restrict _keys, uint32_t* __restrict _tempKeys, Ty* __restrict _values, Ty* __restrict _tempValues, uint32_t _size)
	{
		uint32_t* __restrict keys = _keys;
		uint32_t* __restrict tempKeys = _tempKeys;
		Ty* __restrict values = _values;
		Ty* __restrict tempValues = _tempValues;

		uint16_t histogram[BX_RADIXSORT_HISTOGRAM_SIZE];
		uint16_t shift = 0;
		uint32_t pass = 0;
		for (; pass < 3; ++pass)
		{
			memset(histogram, 0, sizeof(uint16_t)*BX_RADIXSORT_HISTOGRAM_SIZE);

			bool sorted = true;
			uint32_t key = keys[0];
			uint32_t prevKey = key;
			for (uint32_t ii = 0; ii < _size; ++ii, prevKey = key)
			{
				key = keys[ii];
				uint16_t index = (key>>shift)&BX_RADIXSORT_BIT_MASK;
				++histogram[index];
				sorted &= prevKey <= key;
			}

			if (sorted)
			{
				goto done;
			}

			uint16_t offset = 0;
			for (uint32_t ii = 0; ii < BX_RADIXSORT_HISTOGRAM_SIZE; ++ii)
			{
				uint16_t count = histogram[ii];
				histogram[ii] = offset;
				offset += count;
			}

			for (uint32_t ii = 0; ii < _size; ++ii)
			{
				uint32_t key = keys[ii];
				uint16_t index = (key>>shift)&BX_RADIXSORT_BIT_MASK;
				uint16_t dest = histogram[index]++;
				tempKeys[dest] = key;
				tempValues[dest] = values[ii];
			}

			uint32_t* swapKeys = tempKeys;
			tempKeys = keys;
			keys = swapKeys;

			Ty* swapValues = tempValues;
			tempValues = values;
			values = swapValues;

			shift += BX_RADIXSORT_BITS;
		}

done:
		if (0 != (pass&1) )
		{
			
			memcpy(_keys, _tempKeys, _size*sizeof(uint32_t) );
			for (uint32_t ii = 0; ii < _size; ++ii)
			{
				_values[ii] = _tempValues[ii];
			}
		}
	}

	template <typename Ty>
	void radixSort64(uint64_t* __restrict _keys, uint64_t* __restrict _tempKeys, Ty* __restrict _values, Ty* __restrict _tempValues, uint32_t _size)
	{
		uint64_t* __restrict keys = _keys;
		uint64_t* __restrict tempKeys = _tempKeys;
		Ty* __restrict values = _values;
		Ty* __restrict tempValues = _tempValues;

		uint16_t histogram[BX_RADIXSORT_HISTOGRAM_SIZE];
		uint16_t shift = 0;
		uint32_t pass = 0;
		for (; pass < 6; ++pass)
		{
			memset(histogram, 0, sizeof(uint16_t)*BX_RADIXSORT_HISTOGRAM_SIZE);

			bool sorted = true;
			uint64_t key = keys[0];
			uint64_t prevKey = key;
			for (uint32_t ii = 0; ii < _size; ++ii, prevKey = key)
			{
				key = keys[ii];
				uint16_t index = (key>>shift)&BX_RADIXSORT_BIT_MASK;
				++histogram[index];
				sorted &= prevKey <= key;
			}

			if (sorted)
			{
				goto done;
			}

			uint16_t offset = 0;
			for (uint32_t ii = 0; ii < BX_RADIXSORT_HISTOGRAM_SIZE; ++ii)
			{
				uint16_t count = histogram[ii];
				histogram[ii] = offset;
				offset += count;
			}

			for (uint32_t ii = 0; ii < _size; ++ii)
			{
				uint64_t key = keys[ii];
				uint16_t index = (key>>shift)&BX_RADIXSORT_BIT_MASK;
				uint16_t dest = histogram[index]++;
				tempKeys[dest] = key;
				tempValues[dest] = values[ii];
			}

			uint64_t* swapKeys = tempKeys;
			tempKeys = keys;
			keys = swapKeys;

			Ty* swapValues = tempValues;
			tempValues = values;
			values = swapValues;

			shift += BX_RADIXSORT_BITS;
		}

done:
		if (0 != (pass&1) )
		{
			
			memcpy(_keys, _tempKeys, _size*sizeof(uint64_t) );
			for (uint32_t ii = 0; ii < _size; ++ii)
			{
				_values[ii] = _tempValues[ii];
			}
		}
	}

#undef BX_RADIXSORT_BITS
#undef BX_RADIXSORT_HISTOGRAM_SIZE
#undef BX_RADIXSORT_BIT_MASK

} 

#endif 
