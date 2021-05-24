import os
import time
import subprocess
t = time.time()


try:
    subprocess.run(['g++', 'code.cpp', '-o', 'tmp.exe'])
    print('Complied: ', time.time()-t)
except:
    print("ERR")
os.system("tmp.exe < input.txt > tmp.txt")
print('Run: ',time.time()-t)
f = open('output.txt','r').read().strip()
tmp = open('tmp.txt','r').read().strip()
if(f==tmp):
    print("OK")
else:
    print("WA")
