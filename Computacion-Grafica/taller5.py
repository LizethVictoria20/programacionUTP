"""
Taller 5 - Manipulación Avanzada de Arrays con NumPy
=======================================================
Este script resuelve, en orden, los 18 puntos del taller: creación de
vectores, concatenación, estadísticas básicas (mínimo, máximo, longitud,
promedio, media, suma), indexación booleana, moda, ordenamiento y
modificación de elementos específicos.
"""

import numpy as np

print("=" * 60)
print(" TALLER 5: MANIPULACIÓN AVANZADA DE ARRAYS CON NUMPY")
print("=" * 60)

# -------------------------------------------------------------------------
# 1) Crear el vector A
# -------------------------------------------------------------------------
A = np.array([2, 3, 5, 1, 4, 7, 9, 8, 6, 10])
print("\n1) Vector A:", A)
print("\n")

# -------------------------------------------------------------------------
# 2) Crear el vector B con los elementos del 11 al 20
# -------------------------------------------------------------------------
B = np.arange(11, 21)
print("2) Vector B (11 a 20):", B)
print("\n")

# -------------------------------------------------------------------------
# 3) Componer el vector C a partir de A y B en la misma fila
# -------------------------------------------------------------------------
# np.concatenate une los dos vectores uno a continuación del otro,
# formando un único vector fila de 20 elementos.
C = np.concatenate((A, B))
print("3) Vector C = A concatenado con B:", C)
print("\n")

# -------------------------------------------------------------------------
# 4) Valor mínimo de C
# -------------------------------------------------------------------------
minimo_C = np.min(C)
print("4) Valor mínimo de C (np.min):", minimo_C)
print("\n")

# -------------------------------------------------------------------------
# 5) Valor máximo de C
# -------------------------------------------------------------------------
maximo_C = np.max(C)
print("5) Valor máximo de C (np.max):", maximo_C)
print("\n")
# -------------------------------------------------------------------------
# 6) Longitud de C
# -------------------------------------------------------------------------
longitud_C = np.size(C)
print("6) Longitud de C (np.size):", longitud_C)
print("\n")

# -------------------------------------------------------------------------
# 7) Promedio de C usando operaciones elementales (suma y división)
# -------------------------------------------------------------------------
suma_manual = np.sum(C)
promedio_manual = suma_manual / longitud_C
print(f"7) Promedio de C (suma/longitud = {suma_manual}/{longitud_C}):", promedio_manual)
print("\n")

# -------------------------------------------------------------------------
# 8) Promedio de C usando la función propia de NumPy
# -------------------------------------------------------------------------
promedio_np = np.average(C)
print("8) Promedio de C (np.average):", promedio_np)
print("\n")
# -------------------------------------------------------------------------
# 9) Media de C usando la función propia de NumPy
# -------------------------------------------------------------------------
media_np = np.mean(C)
print("9) Media de C (np.mean):", media_np)
print("\n")

# -------------------------------------------------------------------------
# 10) Suma de los elementos de C usando la función propia de NumPy
# -------------------------------------------------------------------------
suma_np = np.sum(C)
print("10) Suma de C (np.sum):", suma_np)
print("\n")

# -------------------------------------------------------------------------
# 11) Vector D: elementos de C mayores que 5
# -------------------------------------------------------------------------
# Indexación booleana: C > 5 genera una máscara de True/False que, al
# aplicarse sobre C, selecciona solo los elementos que cumplen la condición.
D = C[C > 5]
print("11) Vector D (elementos de C > 5):", D)
print("\n")

# -------------------------------------------------------------------------
# 12) Vector E: elementos de C mayores que 5 y menores que 15
# -------------------------------------------------------------------------
E = C[(C > 5) & (C < 15)]
print("12) Vector E (elementos de C > 5 y < 15):", E)
print("\n")

# -------------------------------------------------------------------------
# 13) Cambiar los elementos en las posiciones 5 y 15 de C por 7
# -------------------------------------------------------------------------
print("Vector C antes del cambio:", C)
C[5] = 7
C[15] = 7
print("13) Vector C con las posiciones 5 y 15 cambiadas a 7:", C)
print("\n")

# -------------------------------------------------------------------------
# 14) Moda del vector C
# -------------------------------------------------------------------------
# NumPy no trae una función de moda incorporada, así que se calcula
# contando cuántas veces aparece cada valor único con np.unique(..., return_counts=True)
# y luego se selecciona el valor con mayor frecuencia.
valores_unicos, conteos = np.unique(C, return_counts=True)
moda_C = valores_unicos[np.argmax(conteos)]
frecuencia_moda = conteos.max()
print(f"14) Moda de C: {moda_C} (aparece {frecuencia_moda} veces)")
print("\n")

# -------------------------------------------------------------------------
# 15) Ordenar el vector C de menor a mayor
# -------------------------------------------------------------------------
C = np.sort(C)
print("15) Vector C ordenado de menor a mayor:", C)
print("\n")

# -------------------------------------------------------------------------
# 16) Multiplicar el vector C por 10
# -------------------------------------------------------------------------
C = C * 10
print("16) Vector C multiplicado por 10:", C)
print("\n")

# -------------------------------------------------------------------------
# 17) Cambiar los elementos en las posiciones 6 a 8 de C por 60, 70 y 80
# -------------------------------------------------------------------------
C[6:9] = [60, 70, 80]
print("17) Vector C con las posiciones 6 a 8 cambiadas a 60, 70, 80:", C)
print("\n")

# -------------------------------------------------------------------------
# 18) Cambiar los elementos en las posiciones 14 a 16 de C por 140, 150 y 160
# -------------------------------------------------------------------------
C[14:17] = [140, 150, 160]
print("18) Vector C con las posiciones 14 a 16 cambiadas a 140, 150, 160:", C)
