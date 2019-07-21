// https://stackoverflow.com/questions/1615813/how-to-use-c-classes-with-ctypes
// exposing C++ to C to python

#include <iostream>


// C struct & functions
extern "C" {
typedef struct network network;
network * get_net();
void set_net(network *, int);
void print_net(network *);
void free_net(network *);

}

// C++ wrapper class using C strtuct & functoins above
// keeping an internal pointer of C structure
// (hope this will keep it in memory)
class Network{
  public:
    Network();
    ~Network();
    void w_get_net()     { _net = get_net(); };
    void w_free_net()    { free_net(_net);   };
    void w_set_net(int n){ set_net(_net, n); };
    void w_print_net()   { print_net(_net);  };
  private:
    network * _net;
};

Network::Network(){
  printf("[Network]\n");
  w_get_net();
}
Network::~Network(){
  printf("[~Network]\n");
  w_free_net();
}

// interface function for python (ctypes). arguement and return must be C type
// but content can be C++
extern "C" {

void * create_Network(){
  Network * net = new Network;
  void * net_v = static_cast<void*>(net);
  printf("net / net_v: %p / %p \n", net, net_v); fflush(stdout);
  return net_v;
};

void delete_Network(void * net_v){
  Network * net = static_cast<Network*>(net_v);
  printf("net / net_v: %p / %p \n", net, net_v); fflush(stdout);
  delete net;
};

void set_Network(void * net_v, int n){
  Network * net = static_cast<Network*>(net_v);
  net->w_set_net(n);
};

void print_Network(void * net_v, int n){
  Network * net = static_cast<Network*>(net_v);
  net->w_print_net();
};

}
