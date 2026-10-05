"""
Taller de NumPy - Programa Integrador con Menú de Opciones
=============================================================
Este programa reúne los 7 ejercicios del taller de NumPy en un menú
interactivo. Cada ejercicio se implementa como una función independiente,
cumpliendo los requisitos indicados en el enunciado (uso de operaciones
vectorizadas, np.array(), .reshape(), slicing, broadcasting, ufuncs,
álgebra lineal, manejo de np.nan y guardado/carga de arrays).
"""

import numpy as np
import os


# -------------------------------------------------------------------------
# Ejercicio 1: Creación y Propiedades de Arrays
# -------------------------------------------------------------------------
def ejercicio_1():
    print("\n--- Ejercicio 1: Creación y Propiedades de Arrays ---")

    # Se crea un array unidimensional con los números del 1 al 10
    array_original = np.array(range(1, 11))
    print("Array original (1D, del 1 al 10):", array_original)

    # Se cambia la forma del array a 2 filas x 5 columnas usando .reshape()
    array_reestructurado = array_original.reshape(2, 5)
    print("Array reestructurado (2x5):\n", array_reestructurado)

    print("Forma (shape) del array reestructurado:", array_reestructurado.shape)
    print("Tamaño total (size) del array reestructurado:", array_reestructurado.size)
    print("Número de dimensiones (ndim) del array reestructurado:", array_reestructurado.ndim)


# -------------------------------------------------------------------------
# Ejercicio 2: Operaciones Básicas entre Arrays
# -------------------------------------------------------------------------
def ejercicio_2():
    print("\n--- Ejercicio 2: Operaciones Básicas entre Arrays ---")

    a = np.array([1, 2, 3, 4, 5])
    b = np.array([10, 20, 30, 40, 50])
    print("Array a:", a)
    print("Array b:", b)

    # Una "operación elemento a elemento" significa que NumPy aplica la
    # operación entre cada par de elementos que ocupan la misma posición
    # en ambos arrays, sin necesidad de escribir un ciclo for: es la base
    # de la vectorización en NumPy.
    suma = a + b
    resta = a - b
    producto = a * b
    suma_total_a = a.sum()

    print("Suma elemento a elemento (a + b):", suma)
    print("Resta elemento a elemento (a - b):", resta)
    print("Producto elemento a elemento (a * b):", producto)
    print("Suma total de los elementos de a:", suma_total_a)


# -------------------------------------------------------------------------
# Ejercicio 3: Indexación y Slicing
# -------------------------------------------------------------------------
def ejercicio_3():
    print("\n--- Ejercicio 3: Indexación y Slicing ---")

    array = np.array(range(0, 20))
    print("Array original (0 a 19):", array)

    # Indexación directa: se accede a un elemento puntual mediante su
    # posición (índice), que en Python comienza en 0.
    quinto_elemento = array[4]
    print("Quinto elemento (índice 4):", quinto_elemento)

    # Slicing: array[inicio:fin] devuelve un subconjunto del array,
    # incluyendo el índice "inicio" y excluyendo el índice "fin".
    subconjunto = array[2:7]
    print("Elementos desde la posición 2 hasta la 6 (array[2:7]):", subconjunto)

    # Slicing con índices negativos: array[-n:] toma los últimos n elementos.
    ultimos_tres = array[-3:]
    print("Últimos tres elementos (array[-3:]):", ultimos_tres)

    # Modificación directa de un elemento mediante indexación.
    array[0] = 100
    print("Array actualizado (posición 0 cambiada a 100):", array)


# -------------------------------------------------------------------------
# Ejercicio 4: Broadcasting y Funciones Universales (ufunc)
# -------------------------------------------------------------------------
def ejercicio_4():
    print("\n--- Ejercicio 4: Broadcasting y Funciones Universales (ufunc) ---")

    matriz = np.array(range(1, 10)).reshape(3, 3)
    print("Matriz original (3x3, valores 1 a 9):\n", matriz)

    # Broadcasting: NumPy "expande" automáticamente el escalar 10 para
    # que pueda sumarse a cada elemento de la matriz, sin necesidad de
    # crear una matriz de 10s explícitamente ni usar ciclos.
    matriz_mas_10 = matriz + 10
    print("Matriz + 10 (usando broadcasting):\n", matriz_mas_10)

    # Función universal (ufunc): np.sqrt aplica la raíz cuadrada a cada
    # elemento del array de forma vectorizada.
    raiz_cuadrada = np.sqrt(matriz)
    print("Raíz cuadrada de cada elemento (np.sqrt):\n", raiz_cuadrada)


# -------------------------------------------------------------------------
# Ejercicio 5: Manipulación de Formas y Álgebra Lineal
# -------------------------------------------------------------------------
def ejercicio_5():
    print("\n--- Ejercicio 5: Manipulación de Formas y Álgebra Lineal ---")

    array = np.array(range(1, 7))
    print("Array original (6 números):", array)

    matriz = array.reshape(3, 2)
    print("Matriz reestructurada (3x2):\n", matriz)

    # El producto punto (matriz @ matriz.T) entre una matriz y su
    # transpuesta multiplica filas por columnas, dando como resultado
    # una matriz cuadrada que resume las relaciones internas entre las
    # filas originales.
    producto_punto = matriz @ matriz.T
    print("Producto punto entre la matriz y su transpuesta:\n", producto_punto)
    print("Dimensiones de la matriz resultante:", producto_punto.shape)


# -------------------------------------------------------------------------
# Ejercicio 6: Manejo de Datos Faltantes
# -------------------------------------------------------------------------
def ejercicio_6():
    print("\n--- Ejercicio 6: Manejo de Datos Faltantes ---")

    array_con_nan = np.array([1.0, 2.0, np.nan, 4.0, np.nan, 6.0])
    print("Array original (con valores NaN):", array_con_nan)

    media_original = np.nanmean(array_con_nan)
    print("Media del array original (ignorando NaN con np.nanmean):", media_original)

    # np.nan_to_num reemplaza los valores NaN por 0 (por defecto).
    array_corregido = np.nan_to_num(array_con_nan)
    print("Array corregido (NaN reemplazados por 0):", array_corregido)

    media_corregida = array_corregido.mean()
    print("Media del array corregido:", media_corregida)

    # Los valores NaN reemplazados por 0 reducen artificialmente la media,
    # ya que 0 sí se cuenta en el promedio, mientras que np.nanmean
    # simplemente ignora las posiciones faltantes al calcular el promedio.
    print(f"Diferencia entre medias: {media_original - media_corregida:.4f} "
          "(la media baja al convertir NaN en 0, porque ahora esos valores "
          "faltantes cuentan como ceros reales en el cálculo).")


# -------------------------------------------------------------------------
# Ejercicio 7: Guardar y Cargar Arrays
# -------------------------------------------------------------------------
def ejercicio_7():
    print("\n--- Ejercicio 7: Guardar y Cargar Arrays ---")

    array_original = np.array([3, 6, 9, 12, 15])
    print("Array a guardar:", array_original)

    ruta_archivo = "datos.npy"
    np.save(ruta_archivo, array_original)
    print(f"Array guardado exitosamente en '{ruta_archivo}'.")

    array_cargado = np.load(ruta_archivo)
    print("Array cargado desde el archivo:", array_cargado)

    verificacion = np.array_equal(array_original, array_cargado)
    print("¿Los datos cargados son iguales a los originales?:", verificacion)

    # Limpieza opcional del archivo generado durante la demostración.
    if os.path.exists(ruta_archivo):
        os.remove(ruta_archivo)


# -------------------------------------------------------------------------
# Programa Integrador con Menú de Opciones
# -------------------------------------------------------------------------
def mostrar_menu():
    print("\n" + "=" * 55)
    print(" TALLER DE NUMPY")
    print("=" * 55)
    print("1. Creación y Propiedades de Arrays")
    print("2. Operaciones Básicas entre Arrays")
    print("3. Indexación y Slicing")
    print("4. Broadcasting y Funciones Universales (ufunc)")
    print("5. Manipulación de Formas y Álgebra Lineal")
    print("6. Manejo de Datos Faltantes")
    print("7. Guardar y Cargar Arrays")
    print("8. Ejecutar TODOS los ejercicios")
    print("0. Salir")
    print("=" * 55)


def main():
    opciones = {
        "1": ejercicio_1,
        "2": ejercicio_2,
        "3": ejercicio_3,
        "4": ejercicio_4,
        "5": ejercicio_5,
        "6": ejercicio_6,
        "7": ejercicio_7,
    }

    while True:
        mostrar_menu()
        eleccion = input("Seleccione una opción: ").strip()

        if eleccion == "0":
            print("Saliendo del programa. ¡Hasta luego!")
            break
        elif eleccion == "8":
            for funcion in opciones.values():
                funcion()
        elif eleccion in opciones:
            opciones[eleccion]()
        else:
            print("Opción no válida. Intente nuevamente.")


if __name__ == "__main__":
    main()
