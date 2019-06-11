#include <stdio.h>
#include <string.h>

#define ARG 0x00

void err_msg(int err);
void sort_str(char* _data[], int _len);

int main(int argc, char* argv[]){
    int v;

    if(argc<2)
        err_msg(ARG);
    else{
        printf("Before Sorting : \n");
        for(v=1;v<argc;v++)
            printf("%d). %s\n",v,argv[v]);

        sort_str(argv,argc);

        printf("\nAfter Sorted : \n");
        for(v=1;v<argc;v++)
            printf("%d). %s\n",v,argv[v]);
    }
    return 0;
}

void err_msg(int err){
    if(err==ARG){
        printf("ERROR. Please specify the argument!\n");
        printf("Example : sort_name \"Robert\" \"John\" \"Smith\"");
    }
}
void sort_str(char *_data[], int _len){
    char *tmp;
    int x,y;

    for(x=1;x<_len;x++){
        for(y=1;y<_len;y++){
            if(strcmp(_data[y],&_data[x])>0){
                strcpy(&tmp,&_data[x]);
                strcpy(&_data[x],&_data[y]);
                strcpy(&_data[y],&tmp);
            }
        }
    }
}
