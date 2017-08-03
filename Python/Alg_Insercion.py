#Algoritmo de insercion

import time

file = open('datos1.txt','r')
datos = 1000000
valor = [datos]
n = 0


for cadena in file.readlines():   
    values = cadena.split("\t")
    
    for numero in values:
        valor.append(int(numero))
        if n == datos:
            break
        n = n+1
        
print ("Inicial")
print (time.strftime("%d/%m/%y"))
print (time.strftime("%H:%M:%S"))

for i in range(0, datos-1):
   t = valor[i]
   k = i-1
   while (k >= 0 and valor[k] > t):
       valor[k+1] = valor[k]
       k = k-1
   valor[k+1] = t

print ("Final")  
print (time.strftime("%d/%m/%y"))
print (time.strftime("%H:%M:%S"))

file.close()

