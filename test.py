from ctypes import *

libc = cdll.LoadLibrary("libtest.so")
libc.hello()

libc.create_Network.restype = c_void_p
Np = libc.create_Network();
Np = c_void_p(Np)
print("python: ",hex(Np.value))
libc.print_Network(Np)
libc.set_Network(Np, 300)
libc.print_Network(Np)
libc.set_Network(Np, 5)
libc.print_Network(Np)


libc.delete_Network(Np)
