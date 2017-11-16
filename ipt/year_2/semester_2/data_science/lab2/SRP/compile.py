import py_compile
import glob
import os
path = os.getcwd()
py_files = glob.glob(path + '/*.py')
py_files.remove(path + '/compile.py')
for i in py_files:
    py_compile.compile(i)
