import matplotlib.pyplot as plt
import numpy as np
# mas = []
# mas2 = []
# with open("C:\\Users\\olegg\\CLionProjects\\lab2nd\\cmake-build-debug\\file.txt", "r") as file:
#     str = file.readline()
#     while True:
#         pair = file.readline()
#         print(pair)
#         if not pair:
#             break
#         if not pair[1]:
#             str = pair
#         else:
#             pair = pair.split()
#             mas.append(pair[0])
#             mas2.append(pair[1])
# mas = list(map(int, mas))
# mas2 = list(map(float, mas2))
# plt.plot(mas, mas2)
# plt.title("sort")
# plt.ylabel('time')
# plt.xlabel('data')
# plt.show()
#

def function(n,k):
    mas=[]
    mas2=[]
    with open("C:\\Users\\olegg\\CLionProjects\\lab2nd\\cmake-build-debug\\file.txt", "r") as file:
        for i in range(k):
            pair = file.readline()
        str = file.readline()
        for i in range(n):
            pair = file.readline()
            pair = pair.split()
            mas.append(pair[0])
            mas2.append(pair[1])
    mas = np.asarray(list(map(int, mas)))
    mas2 = np.asarray(list(map(float, mas2)))
    return mas, mas2, str

#

def function2(n,k):
    mas=[]
    mas2=[]
    with open("C:\\Users\\olegg\\CLionProjects\\lab2nd\\cmake-build-debug\\file2.txt", "r") as file:
        for i in range(k):
            pair = file.readline()
        str = file.readline()
        for i in range(n):
            pair = file.readline()
            pair = pair.split()
            mas.append(pair[0])
            mas2.append(pair[1])
    mas = np.asarray(list(map(int, mas)))
    mas2 = np.asarray(list(map(float, mas2)))
    return mas, mas2, str
n = 10;
mas1, mas2, str1 = function2(n,0)
mas3, mas4, str2 = function2(n, n+1)
mas5, mas6, str3 = function2(n, 2*(n+1))
mas11, mas12, str11 = function(n,0)
mas13, mas14, str12 = function(n, n+1)
mas15, mas16, str13 = function(n, 2*(n+1))
plt.figure()
plt.subplot(1,2,1)
plt.plot(mas1, mas2,'.-b', label= str1)
plt.plot(mas3, mas4,'.-r', label= str2)
plt.plot(mas5, mas6,'.-g', label= str3)
plt.legend()
plt.title("List sorts")
plt.ylabel('Time')
plt.xlabel('Data')
plt.subplot(1,2,2)
plt.plot(mas11, mas12,'.-b', label= str11)
plt.plot(mas13, mas14,'.-r', label= str12)
plt.plot(mas15, mas16,'.-g', label= str13)
plt.legend()
plt.title("Array sorts")
plt.ylabel('Time')
plt.xlabel('Data')
plt.show()
