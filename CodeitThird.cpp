#include <cstdio>
using namespace std;

const int Max_N=401;
int perm [Max_N];
int starting_perm [Max_N];
int prices_indexs[Max_N][Max_N];
int prices_numbers[Max_N][Max_N];
int best_changing [1000][2];
int the_best_number_of_chenging;
int the_best_price;
int current_price=0;
int current_number_of_chenging;
int current_changing [1000][2];
int N,type_for_index,type_for_number;
FILE* in;
FILE* out;

int main(){
    in = fopen("sorting.in", "rt");
    out = fopen("sorting.out", "wt");
    fscanf(in, "%d", &N);
    for(int counter=0; counter<N; counter++)
    {
        fscanf(in, " %d", &starting_perm[counter]);
    }
    fscanf(in, "%d", &type_for_index);
    for(int y=0; y<N; y++)
    {
        for(int x=0; x<N; x++)
        {
            fscanf(in, " %d", &prices_indexs[x][y]);
        }
    }
    fscanf(in, "%d", &type_for_index);
    for(int y=0; y<N; y++)
    {
        for(int x=0; x<N; x++)
        {
            fscanf(in, " %d", &prices_numbers[x][y]);
        }
    }
    for(int counter=0;counter<N;counter++){
    perm [counter]=starting_perm[counter];
    }
    bool need_i_to_continue=true;
    int swaping_first,swaping_second;
    for(int counter=0; counter<N; counter++)
    {
        while(need_i_to_continue==true)
        {
            if(perm[counter]==counter+1)
            {
                need_i_to_continue=false;
            }
            else
            {
                the_best_number_of_chenging++;
                swaping_first=perm[counter];
                swaping_second=perm[swaping_first-1];
                best_changing[the_best_number_of_chenging][0]=counter+1;
                best_changing[the_best_number_of_chenging][1]=swaping_first ;
                the_best_price+=prices_indexs[counter][swaping_first-1]+prices_numbers[swaping_first-1][swaping_second-1];
                perm[counter]=swaping_second;
                perm[swaping_first-1]=swaping_first;
            }
        }
        need_i_to_continue=true;
    }



    for(int counter=0;counter<N;counter++){
    perm [counter]=starting_perm[counter];
    }
    need_i_to_continue=true;
    current_number_of_chenging=0;
    int i,j;
       for (i = 0; i < N-1; i++){
       for (j = 0; j < N-i-1; j++){
           if (perm[j] > perm[j+1]){
              swaping_first=perm[j];
              swaping_second=perm[j+1];
              current_changing[current_number_of_chenging][0]=j+1;
              current_changing[current_number_of_chenging][1]=j+2;
              current_price+=prices_indexs[j][j+1]+prices_numbers[perm[j]][perm[j+1]];
              perm[j]=swaping_second;
              perm[j+1]=swaping_first;
              current_number_of_chenging++;
           }
       }
       }
       fprintf(out,"%d %d",current_price,the_best_price);
       if(current_price<the_best_price){
       the_best_price=current_price;
       for(int counter=0;counter<current_number_of_chenging;counter++){
       best_changing[counter][0]=current_changing[counter][0];
       best_changing[counter][1]=current_changing[counter][1];
       }
       the_best_number_of_chenging=current_number_of_chenging;
       }
    fprintf(out, "%d\n",the_best_number_of_chenging);
    for(int counter=1; counter<=the_best_number_of_chenging; counter++)
    {
        fprintf(out, "%d %d\n",best_changing[counter][0],best_changing[counter][1]);
    }
    return 0;
    }
