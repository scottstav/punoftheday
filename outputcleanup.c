#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

unsigned int rand_interval(unsigned int min, unsigned int max)
{
    int r;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;

    /* Create equal size buckets all in a row, then fire randomly towards
     * the buckets until you land in one of them. All buckets are equally
     * likely. If you land off the end of the line of buckets, try again. */
    do
    {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    FILE *ifp, *ofp;
    char *mode = "r";

    ifp = fopen("PunOfTheDay", mode);

    if (ifp == NULL) 
    {
          fprintf(stderr, "Can't open input file in.list!\n");
           exit(1);
    }

    ofp = fopen("outputtest.txt", "w");

    if (ofp == NULL)
    {
          fprintf(stderr, "Can't open output file %s!\n", argv[2]);
           exit(1);
    } 
    char *str = malloc(sizeof(char)* 500);
    char *here;
    int iDescriptionCount = 0;//only want the first pun
    int num = (rand() % (10+1-2))+2;
    while (fgets(str, 500, ifp) != NULL)
    {
        here = (strstr(str, "<description>"));
        if(here != NULL)
        {
            iDescriptionCount ++;
            if(iDescriptionCount == num)
            {
                here = here + 13;
                while(*(here) != '&')
                {
                    fprintf(ofp, "%c", *(here));
                    here ++;
                }
            } 
        }
    }
    free(str);

}
