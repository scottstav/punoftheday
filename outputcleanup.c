#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
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
    while (fgets(str, 500, ifp) != NULL)
    {
        here = (strstr(str, "<description>"));
        if(here != NULL)
        {
            iDescriptionCount ++;
            if(iDescriptionCount == 2)
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

}
