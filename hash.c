int isSubset_simple_method(int arr1[], int arr2[], int m, int n) {

    int i = 0; 
    int j = 0; 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            if(arr2[i] == arr1[j]) 
                break; 
        } 

        /* If the above inner loop was 
        not broken at all then arr2[i] 
        is not present in arr1[] */
        if (j == m) 
            return 0; 
    } 

 
    elements of arr2[] are present 
    in arr1[] */
    return 1; 
}

int isSubset_hash_method( int arr1[], int arr2[], int m, int n ) {

    HashTable H;
    Position P;
    int i;
    int j = 0;
    int CurrentSize;

    H = InitializeTable( CurrentSize = 19 );

    //Note: We don't need to call rehash since the number 
    //of elements in arr1 is lees than half of CurretSize
    //and it guarantees there always will be an empty spot.
    for( i = 0; i < m; i++ )
    {
       Insert( arr1[i], H );
    }
    
    for( j = 0; j < n; j++ ) {
        if (!contains( arr2[j], H ) )
            return 0;
    }
    return 1;
}
