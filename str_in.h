typedef struct number
{
        int n;
        struct number* flag;
} num, *nf;

void get_num(nf* top); //list creation function

void pr_num(nf top); //list traversal function: displays the items on the screen

void add_in(nf r3, int d); //adds an item to the end of the list

int compare (nf r3, int m); //compare for the existence of the same value in the list

void search_in (nf r1, nf r2, nf r3); //checks lists for matching elements
