#include <stdio.h>
#include <stdlib.h>

typedef struct network{
    double d;
    double * p_d;
} network;

void hello(){
    printf("hello\n");
}

network * get_net(){
  network * net = malloc(sizeof(network));
  return net;
}

void free_net(network * net){
  free(net);
}

int main(){
    hello();
    network * net = get_net();
    net->d = 10.10;
    printf("net->d: %f \n", net->d);
    free_net(net);
    printf("net->d: %f \n", net->d);
    return 0;
}
