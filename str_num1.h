typedef struct number
{
        int n;
        struct number* flag;
} num, *nf;

void get_num(nf* top); //list creation function

void pr_num(nf top); //list traversal function: displays the items on the screen

int ins_num(nf top, int f, int l); //function for inserting an element after an element with a specified info part

nf ins_place_num(nf top, int k, int i); //function of inserting an item to a certain place in the list

nf del_num(nf top, int i); //function for removing an item from a certain place in the list

int del_value_num(nf top, int i, int l); //function for deleting an element with a certain info part

int del_value_all(nf top, int i, int l); //function for deleting all items with a certain info part