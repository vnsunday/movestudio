template<typename T>
int dynsocc::algorithm::remove_element(T* parr, T* parr2, int nBegin, int& nEnd, int removeIndex) {
    if (removeIndex >= nBegin && removeIndex < nEnd) {
        for (int i = removeIndex; i < nEnd - 1; ++i) {
            parr[i] = parr[i + 1];
            parr2[i] = parr2[i + 1];
        }
        nEnd--;
        return EXOK;
    }
    return 1;
}

template<typename T>
int dynsocc::algorithm::remove_elements(T* parr, int nBegin, int &nEnd, int startIndex, int removeIndex) {

    return 0;
}

template<typename T>
int dynsocc::algorithm::remove_elements(T* parr, int nBegin, int &nEnd, int* premove_indexes, int nRemoveStart, int nRemoveEnd)
{
    // Validate 
    for (int i=nRemoveStart;i<nRemoveEnd;++i) {
        if (premove_indexes[i] < nBegin || premove_indexes[i] >= nEnd)
        {
            // Invalid data
            return 1;
        }
    }

    int nRemove = nRemoveEnd - nRemoveStart;
    int* premove = (int*)malloc(sizeof(int)*nRemove);

    memcpy(premove, premove_indexes + nRemoveStart, nRemove*sizeof(int));
    std::sort(premove, premove+nRemove);

    // Remove from largest position first, then go on.
    for (int i=nRemove-1;i>=0;i--)
    {
        for (int j=premove[i];j<nEnd;j++)
        {
            parr[j] = parr[j+1];
        }
        nEnd--;
    }

    return 0;
}

template<typename T>
int dynsocc::algorithm::remove_elements(T* parr, T* parr2, int nBegin, int& nEnd, int startIndex, int endIndex)
{
    return EXOK;
}


template<typename T1, typename T2> 
int dynsocc::algorithm::put_map(T1 key, T2 value, T1* p_sorted_keys, T2* pvalue, int keycount) {

    int nFound = -1;
    
    /* Existing Keys */
    if (algorithm::binary_search(p_sorted_keys, 0, keycount, key, nFound) == EXOK && 
            nFound >= 0) {
        // Override - Update existing value
        pvalue[nFound] = value;
    }
    // Add New 
    else {
        int index;
        int valuecount = keycount;
        insert_into_sorted_desc(p_sorted_keys, 0, keycount, key, index);
        insert(pvalue, 0, valuecount, value, index);
    }

    return EXOK;
}

template<typename T1, typename T2, typename AssignerValue> 
int dynsocc::algorithm::put_map(T1 key, T2 value, T1* p_sorted_keys, T2* pvalue, AssignerValue op_assign, int keycount) {
    int nFound = -1;
    
    /* Existing Keys */
    if (algorithm::binary_search(p_sorted_keys, 0, keycount, key, nFound) == EXOK && 
            nFound >= 0) {
        // Override - Update existing value
        op_assign(pvalue[nFound], value); // pvalue[nfound]=value
    }
    // Add New 
    else {
        int index;
        int valuecount = keycount;
        insert_into_sorted_desc(p_sorted_keys, 0, keycount, key, index);
        insert(pvalue, 0, valuecount, value, index);
    }

    return EXOK;
}

template<typename T1, typename T2> 
int dynsocc::algorithm::get_map(T1 key, T2& value, T1* p_sorted_keys, T2* pvalue, int keycount) {

    int nFound = -1;

    /* Existing Keys */
    if (algorithm::binary_search(p_sorted_keys, 0, keycount, key, nFound) == EXOK && 
            nFound >= 0) {
        // Override - Update existing value
        value = pvalue[nFound];

        return EXOK;
    }

    return 1; // Not-Found
}

template<typename T1, typename T2, typename AssignerValue> 
int dynsocc::algorithm::get_map(T1 key, T2& value, T1* p_sorted_keys, T2* pvalue, AssignerValue op_assign, int keycount) {
    int nFound = -1;

    /* Existing Keys */
    if (algorithm::binary_search(p_sorted_keys, 0, keycount, key, nFound) == EXOK && 
            nFound >= 0) {
        // Override - Update existing value
        op_assign(value, pvalue[nFound]); // value = pvalue[nfound]

        return EXOK;
    }

    return 1; // Not-Found
}

template<typename T>
std::string dynsocc::algorithm::new_vertex(T vertex, T* pV, int& nVertex, T* pEdgeL, T* pEdgeR, int& nEdge) {

    int nFound = 0;
    int nPos;
    if (algorithm::binary_search(pV, 0, nVertex, vertex, nFound) == EXOK) {
        return "Vertex duplicated."; // Failed
    }

    algorithm::insert_into_sorted_asc(pV, 0, nVertex, vertex, nPos);
    return EXSOK;
}

template<typename T>
std::string dynsocc::algorithm::new_edge(T startVertex, T endVertex, T* pV, int& nVertex, T* pEdgeL, T* pEdgeR, int& nEdge) {

    /*==================================================
        NE1. Duplicated? => Failed
        NE2. AddNew 
        NE3. 

        Note: Preconditions. pVertex(pV) and pEdge are Pair-sorted-ASC <=> Sorted by (pv[i], pEdge[j])
            => pVertex are sorted ASC 
     *==================================================*/
    int nFound = 0;
    int nPos;
    int nIdxL;
    int nIdxR;

    // NE1. Duplicated 
    if (algorithm::binary_search(pEdgeL, 0, nEdge, startVertex, nIdxL, nIdxR) == EXOK) {
        for (int i=nIdxR; i<= nIdxR; i++) {
            if (pEdgeR[i] == endVertex) {
                return "Duplicated Edge"; 
            }
        }
    }

    // NE2. AddNew
    if (algorithm::find_location_in_sorted_order(pEdgeR, nIdxL, nIdxR, endVertex, nPos) == EXOK) {
        int nEdgeR = nEdge;
        algorithm::insert(pEdgeL, 0, nEdge, startVertex, nPos);
        algorithm::insert(pEdgeR, 0, nEdgeR, endVertex, nPos);
    }

    return EXSOK;
}

template<typename T>
std::string dynsocc::algorithm::delete_edge(T startVertex, T endVertex, T* pV, int& nVertex, T* pEdgeL, T* pEdgeR, int& nEdge) {
    /*==================================================
     * 
     *==================================================*/

    return EXSOK;
}


