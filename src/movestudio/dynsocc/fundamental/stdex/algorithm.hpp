#ifndef DYNSOCC_FUNDAMENTAL_STDEX_ALGORITHM_HPP_
#define DYNSOCC_FUNDAMENTAL_STDEX_ALGORITHM_HPP_
#include <assert.h>
#include <string.h>
#include <string>
#include <algorithm>
#include "stdex.h"

namespace dynsocc
{
    class algorithm
    {
    public: 
        template <typename T>
        static int binary_search(T* arr_sorted_asc, int nBegin, int nEnd, T val, int& nFound)
        {
            int nL = nBegin;
            int nR = nEnd-1;
            int nMid;
            nFound = -1;
            T valMid;
            while (nL <= nR && (nFound < 0))
            {
                nMid = (nL + nR) / 2;
                valMid = arr_sorted_asc[nMid];

                if (valMid == val)
                {
                    nFound = nMid;
                }
                else if (valMid < val)
                {
                    nL = nMid + 1;
                }
                else 
                {
                    nR = nMid - 1;
                }
            }

            return 0;
        }

        template <typename T>
        static int binary_search(T* arr_sorted_asc, int nBegin, int nEnd, T val, int& nFoundBegin, int& nFoundEnd)
        {
            // Find every 
            int nL = nBegin;
            int nR = nEnd-1;
            int nMid = (nL + nR) / 2;
            int nFound = -1;
            nFoundBegin = -1;
            nFoundEnd = nFoundBegin -1;
            T valMid;

            // The 1st location 
            while (nL <= nR && (nFound < 0))
            {
                nMid = (nL + nR) / 2;
                valMid = arr_sorted_asc[nMid];

                if (valMid == val)
                {
                    nFound = nMid;
                }
                else if (valMid < val)
                {
                    nL = nMid + 1;
                }
                else 
                {
                    nR = nMid - 1;
                }
            }

            if (nFound >=0)
            {
                nFoundBegin = nFound;
                nFoundEnd = nFound;


                while (nFoundBegin > nBegin && arr_sorted_asc[nFoundBegin-1] == val)  { nFoundBegin--;}
                while (nFoundEnd < nEnd-1 && arr_sorted_asc[nFoundEnd+1] == val ) { nFoundEnd++;}
            }
            
            return 0;
        }

        
        template<typename T>
        static int insert_into_sorted_asc(T* parr, int nBegin, int &nEnd, T val, int& nPos)
        {
            // Pre-Requisite: parr is sorted asc (every i: p[i] <= p[i+1])
            // This function does not validate pre-requisite condition 
           
            // Find the 1st position (smallest) where 
            //      parr[pos] < val
            nPos = 0;
            while (nPos < nEnd && parr[nPos] >= val) { nPos++; }

            // Starting from nPos+1, move everything forward
            for (int i=nEnd; i> nPos;i--)
            {
                parr[i] = parr[i-1];
            }

            // Insert at nPos
            parr[nPos] = val;
            nEnd++;
            return 0;
        }

        template<typename T>
        static int insert_into_sorted_desc(T* parr, int nBegin, int &nEnd, T val, int& nPos)
        {
            // Pre-requisite: parr is sorted desc (p[i] >= p[i+1], every i)
            // If the pre-requisite condition is not meet => the result will incorrect, 
            // This function does not validate pre-requisite condition.

            // Find the 1st position where val >= p[loc]
            nPos = nBegin;

            while (nPos < nEnd && (val < parr[nPos]))
            {
                nPos++;
            }

            // Starting from nPos+1, move everything forward 1step
            for (int i=nEnd;i>nPos;i--)
            {
                parr[i] = parr[i-1];
            }

            // Insert 
            parr[nPos] = val;
            nEnd++;
            return 0;
        }

        template<typename T>
        static int remove_element(T* parr, int nBegin, int &nEnd, int removeIndex);

        template<typename T>
        static int remove_element(T* parr, T* parr2, int nBegin, int& nEnd, int removeIndex);

        template<typename T>
        static int remove_elements(T* parr, int nBegin, int &nEnd, int startIndex, int removeIndex);

        template<typename T>
        static int remove_elements(T* parr, T* parr2, int nBegin, int& nEnd, int startIndex, int endIndex);
        
        /*==================================================
         * Remove Elements
         *    Array to be removed: parr.
         *          [nBegin; nEnd): Workign range index for parr.
         *    
         *       premove_indexes: array-containning Index to remove
         *          premove_indexes[i] = index-of-parr to remove
         *       
         *==================================================*/
        template<typename T>
        static int remove_elements(T* parr, int nBegin, int &nEnd, int* premove_indexes, int nRemoveStart, int nRemoveEnd);

        template<typename T>
        static int remove_elements(T* parr, T* parr2, int nBegin, int &nEnd, int* prm_indexes, int nRemoveStart, int nRemoveEnd)
        {
            // Validate 
            for (int i = nRemoveStart; i < nRemoveEnd; ++i)
            {
                if (prm_indexes[i] < nBegin || prm_indexes[i] >= nEnd)
                {
                    // Invalid data
                    return 1;
                }
            }

            int nRemove = nRemoveEnd - nRemoveStart;
            int* premove = (int*)malloc(sizeof(int)*nRemove);

            memcpy(premove, prm_indexes + nRemoveStart, nRemove * sizeof(int));
            std::sort(premove, premove + nRemove);

            // Remove from largest position first, then go on.
            for (int i = nRemove - 1; i >= 0; i--)
            {
                for (int j = premove[i]; j < nEnd; j++)
                {
                    parr[j] = parr[j + 1];
                    parr2[j] = parr2[j + 1];
                }

                nEnd--;
            }

            return 0;
        }
    
		template<typename T>
		static int find_location_in_sorted_order(T* parr, int nBegin, int nEnd, T val, int& nPos)
		{
			// Pre-Requisite: parr is sorted asc (every i: p[i] <= p[i+1])
			// This function does not validate pre-requisite condition 

			// Find the 1st position (smallest) where 
			//      parr[pos] < val
			nPos = 0;
			while (nPos < nEnd && parr[nPos] >= val) { nPos++; }
			return 0;
		}

		template<typename T>
		static int insert(T* parr, int nBegin, int& nEnd, T val, int nPos)
		{
			assert(nPos < nEnd && nPos >= 0);

			// Starting from nPos+1, move everything forward
			for (int i = nEnd; i > nPos; i--)
			{
				parr[i] = parr[i - 1];
			}

			// Insert at nPos
			parr[nPos] = val;
			nEnd++;
			return 0;
		}

        // AssignerValue(destitation, source): destination = source
        template<typename T, typename AssignerValue>
        static int insert(T* parr, int nBegin, int& nEnd, T val, AssignerValue op_assign, int nPos)
        {
            assert(nPos < nEnd && nPos >= 0);

            // Starting from nPos+1, move everything forward
            for (int i = nEnd; i > nPos; i--)
            {
                op_assign(parr[i], parr[i - 1]); // parr[i] = parr[i - 1]
            }

            // Insert at nPos
            op_assign(parr[nPos], val); // parr[nPos] = val
            nEnd++;
            return 0;
        }

        template<typename T>
        static int equality_score(T* parr1, int n1, T* parr2, int n2);

        template<typename T1, typename T2> 
        static int put_map(T1 key, T2 value, T1* p_sorted_keys, T2* pvalue, int keycount);

        /*========================================
            AssignValue(T2 dest, T2 source): dest = source
         *========================================*/
        template<typename T1, typename T2, typename AssignerValue> 
        static int put_map(T1 key, T2 value, T1* p_sorted_keys, T2* pvalue, AssignerValue op_assign, int keycount);

        template<typename T1, typename T2> 
        static int get_map(T1 key, T2& value, T1* p_sorted_keys, T2* pvalue, int keycount);

        template<typename T1, typename T2, typename AssignerValue> 
        static int get_map(T1 key, T2& value, T1* p_sorted_keys, T2* pvalue, AssignerValue op_assign, int keycount);

        template<typename T>
        static std::string new_vertex(T vertex, T* pV, int& nVertex, T* pEdgeL, T* pEdgeR, int& nEdge);

        template<typename T>
        static std::string new_edge(T startVertex, T endVertex, T* pV, int& nVertex, T* pEdgeL, T* pEdgeR, int& nEdge);

        template<typename T>
        static std::string delete_edge(T startVertex, T endVertex, T* pV, int& nVertex, T* pEdgeL, T* pEdgeR, int& nEdge);

        
	};
}

#include "algorithm.ipp"

#endif