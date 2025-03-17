#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selsort(int n, int a[]);

int main()
{
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;

    while(1)
    {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("\nEnter array elements: ");
                for(i = 0; i < n; i++)
                {
                    scanf("%d", &a[i]);
                }

                start = clock();
                selsort(n, a);
                end = clock();

                printf("\nSorted array is: ");
                for(i = 0; i < n; i++)
                {
                    printf("%d\t", a[i]);
                }

                printf("\nTime taken to sort %d numbers is %.6f seconds", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                break;

            case 2:
                n = 500;
                while(n <= 14500)
                {
                    for(i = 0; i < n; i++)
                    {
                        a[i] = n - i; // Generate reverse order array
                    }

                    start = clock();
                    selsort(n, a);
                    // Dummy loop to create delay (not very useful, can be omitted)
                    for(j = 0; j < 500000; j++) { temp = 38 / 600; }
                    end = clock();

                    printf("\nTime taken to sort %d numbers is %.6f seconds", n, ((double)(end - start)) / CLOCKS_PER_SEC);

                    n += 1000; // Increase n by 1000 for the next iteration
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }

        getchar(); // To consume the newline character left by scanf
    }

    return 0;
}

void selsort(int n, int a[])
{
    int i, j, t, small, pos;
    for(i = 0; i < n - 1; i++)
    {
        pos = i;
        small = a[i];
        for(j = i + 1; j < n; j++)
        {
            if(a[j] < small)
            {
                small = a[j];
                pos = j;
            }
        }
        // Swap
        t = a[i];
        a[i] = a[pos];
        a[pos] = t;
    }
}
