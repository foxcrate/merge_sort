#include <stdio.h>
#include <cs50.h>

void merge_sort(int array[] , int l , int r);
void merge( int array[] , int l , int m , int r );

int main(void){
    int array[] = {2,7,3,1,9,10,6};

    int arr_size = sizeof(array) / sizeof(array[0]);

    printf("before sort: \n");

    for (int i = 0; i < 7; i++)
    {
        printf("%i ",array[i]);
    }

    merge_sort(array , 0, arr_size - 1);
    // merge(array , 0 , 3 , 6);

    printf("\nafter sort: \n");

    for (int i = 0; i < 7; i++)
    {
        printf("%i ",array[i]);
    }    
    

}

void merge( int array[] , int l , int m , int r ){

    int x = m+1 - l ;
    int left_array[x];
    // printf( "x: %i\n" , x );
    
    int y = r - m ;
    int right_array[y];
    // printf( "y: %i\n" , y );

    for (int i = 0 ; i < x ; i++)
        left_array[i] = array[l+i];

    for (int i = 0 ; i < y ; i++)
        right_array[i] = array[m+1+i];
    // printf("\n left array: \n");

    // for (int o = 0; o < x; o++)
    // {
    //     printf("%i ",left_array[o]);
    // }

    // printf("\n right array: \n");

    // for (int p = 0; p < y; p++)
    // {
    //     printf("%i ",right_array[p]);
    // }

    int i=0 , j=0 , k=l;

    while (i < x && j < y)
    {
        if (left_array[i] <= right_array[j]){
            array[k] = left_array[i];
            i++;
        }
        else{
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    
    while(i < x){
        array[k] = left_array[i];
        i++;
        k++;
    }

    while(j < y){
        array[k] = right_array[j];
        j++;
        k++;
    }


}

void merge_sort(int array[] , int l , int r){
    

    if( l < r ){

        int m = l + ( r - l ) / 2;


        merge_sort(array , l , m);
        merge_sort(array , m+1 , r);

        merge(array , l , m , r);

    }

}