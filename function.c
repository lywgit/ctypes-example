#include <stdio.h>
#include <stdlib.h>


typedef struct network{
    int n;
    double * ptr;
} network;

void say(char * s){
  printf("%s\n", s); fflush(stdout);
}

void hello(){
    printf("hello\n");
}

network * get_net(){
  say("get_net");
  network * net = (network*)malloc(sizeof(network));
  net->n = 0;
  net->ptr = 0;
  return net;
}

void set_net(network *net, int n){
  say("set_net");
  printf("n=%d\n", n); fflush(stdout);
  if (net->ptr) free(net->ptr);
  net->n = n;
  net->ptr = (double*)malloc(n*sizeof(double));
  for (int i=0; i<n; i++ ){
    net->ptr[i] = i;
  }
}

void print_net(network * net){
  if (net->n == 0) {
    printf("net->n = 0\n");
  }
  else{
    for (int i=0; i<net->n; i++){
      printf("%d: %f \n", i, (net->ptr)[i] );
    }
    printf("\n");
  }
}

void free_net(network * net){
  say("free_net");
  if (net->ptr) free(net->ptr);
  free(net);
}
