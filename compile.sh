
gcc -c -fPIC function.c
g++ -c -fPIC wrapper.cpp

g++ -shared -Wl,-install_name,libtest.so -o libtest.so function.o wrapper.o # for mac
# g++ -shared -Wl,-soname,libtest.so -o libtest.so function.o wrapper.o 
