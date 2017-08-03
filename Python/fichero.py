import random
import time

n = 1000000
datos = open('datos1.txt', 'r+')

for contenido in range (n):
    contenido = random.randint(1, 5000)
    datos.write(str(contenido)+"\n")

datos.close()
