#include <stdio.h>
#include <stdbool.h>

bool is_identity(const short *first, const short *last){
    int n = last - first;
    int dim = 0;
    while (dim*dim < n){
        dim++;
    }
    if(dim*dim != n) return false;
    else {
        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++) {
                if(i == j)
                {
                    if(*(first+i*dim+j) != 1)return false;
                }
                else 
                {
                    if(*(first+i*dim+j) != 0) return false;
                }
            }
        }
        return true;
    }


}


int main() {
    short tab1[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    size_t size = sizeof(tab1)/sizeof(short);
    bool result = is_identity((const short*)tab1, (const short*)tab1+size);
    printf("%d\n", result);
    short tab[2][8] = {{1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1}};
    bool result2 = is_identity((const short*)tab, (const short*)tab+size);
    printf("%d\n", result2);

    return 0;
}