#!/usr/bin/python -tt

import ctypes
import sys
import time

# The value of a PyIntObject is stored as a long integer. This is true at
# least as of version 2.7.6 of CPython.
VALUE_TYPE = ctypes.c_long

def main():
    pyint3p = id(3) + sys.getsizeof(3) - ctypes.sizeof(VALUE_TYPE)
    three = VALUE_TYPE.from_address(pyint3p)
    print '1 + 1 = 3? {0}.'.format(1 + 1 == 3)
    # Begin unnecessary silliness
    time.sleep(1)
    print 'Reorganizing Peano axioms . . .'
    time.sleep(1)
    print 'Garbage-collecting successor functions . . .'
    time.sleep(1)
    # End unnecessary silliness
    three.value = 2
    print '1 + 1 = 3? {0}!'.format(1 + 1 == 3)

if __name__ == '__main__':
    main()
