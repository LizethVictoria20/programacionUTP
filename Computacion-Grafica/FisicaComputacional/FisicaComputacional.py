"""
TALLER 1 - FÍSICA COMPUTACIONAL EN PYTHON

Fórmulas utilizadas:

1. Caída libre:
   t = sqrt((2 * h) / g)

2. Conversión de velocidad:
   m/s = km/h / 3.6
   km/h = m/s * 3.6

3. Desplazamiento:
   s = u*t + (1/2)*a*t^2

4. Suma de vectores:
   [x1 + x2, y1 + y2]

5. Producto escalar:
   A · B = x1*x2 + y1*y2

   cos(angulo) = (A · B) / (|A| * |B|)

6. Lanzamiento de proyectil:

   R = (v^2 * sin(2*angulo)) / g

   H = (v^2 * sin(angulo)^2) / (2*g)

Salvedades y supuestos:

- Gravedad = 9.81 m/s^2
- No se considera resistencia del aire.
- En caída libre el objeto parte del reposo.
- El proyectil sale y cae a la misma altura.
"""

import math


GRAVEDAD = 9.81


# --------------------------------
# 1. CAÍDA LIBRE
# --------------------------------

def caida_libre():

    print("\n--- CAÍDA LIBRE ---")

    altura = float(
        input("Ingrese la altura en metros: ")
    )

    if altura <= 0:
        print("La altura debe ser mayor que cero.")
        return

    tiempo = math.sqrt(
        (2 * altura) / GRAVEDAD
    )

    print(
        "Tiempo de caída:",
        round(tiempo, 2),
        "segundos"
    )


# --------------------------------
# 2. CONVERSIÓN DE VELOCIDAD
# --------------------------------

def convertir_velocidad():

    print("\n--- CONVERSIÓN DE VELOCIDAD ---")

    print("1. km/h a m/s")
    print("2. m/s a km/h")

    opcion = input(
        "Seleccione una opción: "
    )

    velocidad = float(
        input("Ingrese la velocidad: ")
    )

    if velocidad < 0:
        print(
            "La velocidad no puede ser negativa."
        )
        return

    if opcion == "1":

        resultado = velocidad / 3.6

        print(
            round(velocidad, 2),
            "km/h =",
            round(resultado, 2),
            "m/s"
        )

    elif opcion == "2":

        resultado = velocidad * 3.6

        print(
            round(velocidad, 2),
            "m/s =",
            round(resultado, 2),
            "km/h"
        )

    else:
        print("Opción inválida.")


# --------------------------------
# 3. DESPLAZAMIENTO
# --------------------------------

def calcular_desplazamiento():

    print("\n--- DESPLAZAMIENTO ---")

    velocidad = float(
        input("Velocidad inicial en m/s: ")
    )

    aceleracion = float(
        input("Aceleración en m/s²: ")
    )

    tiempo = float(
        input("Tiempo en segundos: ")
    )

    if tiempo < 0:
        print(
            "El tiempo no puede ser negativo."
        )
        return

    desplazamiento = (
        velocidad * tiempo
        + 0.5
        * aceleracion
        * tiempo ** 2
    )

    print(
        "Desplazamiento:",
        round(desplazamiento, 2),
        "metros"
    )


# --------------------------------
# 4. SUMA DE VECTORES
# --------------------------------

def suma_vectores():

    print("\n--- SUMA DE VECTORES ---")

    print("Vector 1")

    x1 = float(input("x1: "))
    y1 = float(input("y1: "))

    print("Vector 2")

    x2 = float(input("x2: "))
    y2 = float(input("y2: "))

    vector1 = [x1, y1]
    vector2 = [x2, y2]

    resultado = [
        vector1[0] + vector2[0],
        vector1[1] + vector2[1]
    ]

    print(
        "Resultado:",
        resultado
    )


# --------------------------------
# 5. PRODUCTO ESCALAR
# --------------------------------

def producto_escalar():

    print("\n--- PRODUCTO ESCALAR ---")

    print("Vector 1")

    x1 = float(input("x1: "))
    y1 = float(input("y1: "))

    print("Vector 2")

    x2 = float(input("x2: "))
    y2 = float(input("y2: "))

    producto = (
        x1 * x2
        + y1 * y2
    )

    magnitud1 = math.sqrt(
        x1 ** 2 + y1 ** 2
    )

    magnitud2 = math.sqrt(
        x2 ** 2 + y2 ** 2
    )

    if magnitud1 == 0 or magnitud2 == 0:

        print(
            "No se puede calcular el ángulo."
        )

        return

    coseno = producto / (
        magnitud1 * magnitud2
    )

    angulo = math.degrees(
        math.acos(coseno)
    )

    print(
        "Producto escalar:",
        round(producto, 2)
    )

    print(
        "Ángulo:",
        round(angulo, 2),
        "grados"
    )


# --------------------------------
# 6. LANZAMIENTO DE PROYECTIL
# --------------------------------

def lanzamiento_proyectil():

    print(
        "\n--- LANZAMIENTO DE PROYECTIL ---"
    )

    velocidad = float(
        input("Velocidad inicial en m/s: ")
    )

    angulo = float(
        input("Ángulo en grados: ")
    )

    if velocidad <= 0:

        print(
            "La velocidad debe ser mayor que cero."
        )

        return

    if angulo <= 0 or angulo >= 90:

        print(
            "El ángulo debe estar entre 0 y 90 grados."
        )

        return

    angulo_rad = math.radians(
        angulo
    )

    alcance = (
        velocidad ** 2
        * math.sin(2 * angulo_rad)
    ) / GRAVEDAD

    altura = (
        velocidad ** 2
        * math.sin(angulo_rad) ** 2
    ) / (2 * GRAVEDAD)

    print(
        "Alcance máximo:",
        round(alcance, 2),
        "metros"
    )

    print(
        "Altura máxima:",
        round(altura, 2),
        "metros"
    )


# --------------------------------
# MENÚ
# --------------------------------

def menu():

    while True:

        print("\n==============================")
        print("     FÍSICA COMPUTACIONAL")
        print("==============================")

        print("1. Caída libre")
        print("2. Conversión de velocidad")
        print("3. Desplazamiento")
        print("4. Suma de vectores")
        print("5. Producto escalar")
        print("6. Lanzamiento de proyectil")
        print("7. Salir")

        print("==============================")

        opcion = input(
            "Seleccione una opción: "
        )

        if opcion == "1":
            caida_libre()

        elif opcion == "2":
            convertir_velocidad()

        elif opcion == "3":
            calcular_desplazamiento()

        elif opcion == "4":
            suma_vectores()

        elif opcion == "5":
            producto_escalar()

        elif opcion == "6":
            lanzamiento_proyectil()

        elif opcion == "7":

            print(
                "Programa finalizado."
            )

            break

        else:

            print(
                "Opción inválida."
            )

menu()
