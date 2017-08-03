#Algoritmo de Seleccion
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

for i in range(0,datos-1):
  k = i
  t = valor[i]
  
  for j in range(i,datos):
    if valor[j] < t:
      k = j
      t = valor[j]
  valor[k] = valor[i]
  valor[i] = t

print ("Final")  
print (time.strftime("%d/%m/%y"))
print (time.strftime("%H:%M:%S"))

file.close()



