#include <iostream>

#define BROWN_BOTTLES 0
#define GREEN_BOTTLES 1
#define CLEAR_BOTTLES 2

void func(int*, int*, int*, char*, char*, char*);

int main(int charc, char **argv) { 

    int bin1[3], bin2[3], bin3[3];
    char first_bag, second_bag, third_bag;

    while (
            std::cin >> bin1[BROWN_BOTTLES] >> bin1[GREEN_BOTTLES] >> bin1[CLEAR_BOTTLES]
                     >> bin2[BROWN_BOTTLES] >> bin2[GREEN_BOTTLES] >> bin2[CLEAR_BOTTLES]
                     >> bin3[BROWN_BOTTLES] >> bin3[GREEN_BOTTLES] >> bin3[CLEAR_BOTTLES]
          )
    {
        func(bin1, bin2, bin3, &first_bag, &second_bag, &third_bag);
    }

    return 0;
}

void func(int *arr1, int *arr2, int *arr3, char *f, char *s, char *t)
{
    int min_moves, temp;

    // BCG
    min_moves = arr2[BROWN_BOTTLES] + arr3[BROWN_BOTTLES] +
           arr1[CLEAR_BOTTLES] + arr3[CLEAR_BOTTLES] +
           arr2[GREEN_BOTTLES] + arr1[GREEN_BOTTLES];
    // therefore the order is
    *f = 'B'; *s = 'C'; *t = 'G';

    // check another config
    // BGC
    temp =  arr2[BROWN_BOTTLES] + arr3[BROWN_BOTTLES] +
                arr1[GREEN_BOTTLES] + arr3[GREEN_BOTTLES] +
                arr1[CLEAR_BOTTLES] + arr2[CLEAR_BOTTLES];
    if (temp < min_moves)
    {
        min_moves = temp; 
        *f = 'B'; *s = 'G'; *t = 'C';
    }

    // CBG
    temp = arr2[CLEAR_BOTTLES] + arr3[CLEAR_BOTTLES] +
           arr1[BROWN_BOTTLES] + arr3[BROWN_BOTTLES] +
           arr1[GREEN_BOTTLES] + arr2[GREEN_BOTTLES];
    if (temp < min_moves)
    {
        min_moves = temp;
        *f = 'C'; *s = 'B'; *t = 'G';
    }

    // CGB
    temp = arr2[CLEAR_BOTTLES] + arr3[CLEAR_BOTTLES] +
           arr1[GREEN_BOTTLES] + arr3[GREEN_BOTTLES] +
           arr1[BROWN_BOTTLES] + arr2[BROWN_BOTTLES];
    if (temp < min_moves)
    {
        min_moves = temp;
        *f = 'C'; *s = 'G'; *t = 'B';
    }

    //GBC
    temp = arr2[GREEN_BOTTLES] + arr3[GREEN_BOTTLES] +
           arr1[BROWN_BOTTLES] + arr3[BROWN_BOTTLES] +
           arr1[CLEAR_BOTTLES] + arr2[CLEAR_BOTTLES];

    if (temp < min_moves)
    {
        min_moves = temp;
        *f = 'G'; *s = 'B'; *t = 'C';
    }

    // GCB
    temp = arr2[GREEN_BOTTLES] + arr3[GREEN_BOTTLES] +
           arr1[CLEAR_BOTTLES] + arr3[CLEAR_BOTTLES] +
           arr1[BROWN_BOTTLES] + arr2[BROWN_BOTTLES];
    if (temp < min_moves)
    {
        min_moves = temp;
        *f = 'G'; *s = 'C'; *t = 'B';
    }



    std::cout << *f << *s << *t << ' ' << min_moves << '\n';
    
    

}
