void perc_down(int arr[], unsigned int i, unsigned int n )
{
    unsigned int child;
    int tmp;
    for( tmp=arr[i]; i*2+1<n; i=child )
    {
        child = i*2+1;
        if( ( child != n ) && ( arr[child+1] > arr[child] ) > 0 )
            child++;
        if( tmp < arr[child] ) {
            arr[i] = arr[child];
            arr[child] = tmp;
           }
        else
            break;
    
    }
}

void swap (int *s1, int *s2) {
    int temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void HeapSort(int arr[], int n ) {
    int i;
    for( i=n/2; i>=0; i-- )
        perc_down (arr, i, n );

    for( i=n-1; i>0; i-- )
    {
        swap( &arr[0], &arr[i] );

        perc_down(arr, 0, i-1 );
    }
}
