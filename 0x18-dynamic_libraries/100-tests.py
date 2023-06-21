import random
import ctypes

# Load the dynamic library
cops = ctypes.CDLL('./100-operations.so')

# Define the argument and return types for each function
cops.add.argtypes = (ctypes.c_int, ctypes.c_int)
cops.add.restype = ctypes.c_int

cops.sub.argtypes = (ctypes.c_int, ctypes.c_int)
cops.sub.restype = ctypes.c_int

cops.mul.argtypes = (ctypes.c_int, ctypes.c_int)
cops.mul.restype = ctypes.c_int

cops.divide.argtypes = (ctypes.c_int, ctypes.c_int)
cops.divide.restype = ctypes.c_int

cops.mod.argtypes = (ctypes.c_int, ctypes.c_int)
cops.mod.restype = ctypes.c_int

# Generate random integers
a = random.randint(-111, 111)
b = random.randint(-111, 111)

# Call the C functions from the dynamic library
print("{} + {} = {}".format(a, b, cops.add(a, b)))
print("{} - {} = {}".format(a, b, cops.sub(a, b)))
print("{} x {} = {}".format(a, b, cops.mul(a, b)))
print("{} / {} = {}".format(a, b, cops.divide(a, b)))
print("{} % {} = {}".format(a, b, cops.mod(a, b)))
