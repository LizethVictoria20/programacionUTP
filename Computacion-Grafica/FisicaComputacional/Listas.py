"""
TALLER 2 - PROGRAMACIÓN EN PYTHON

Temas:
- Funciones
- Estructuras de control
- Listas
- Tuplas
- Diccionarios
- Map
- Lambda
- Ciclos
- Manejo de cadenas

El programa contiene:

1. Calculadora básica
2. Filtrado de números pares
3. Conversión Celsius a Fahrenheit
4. Sistema de calificaciones
5. Conteo de palabras
6. Búsqueda de elementos
7. Validación de paréntesis
8. Ordenamiento de personas
9. Generador de contraseñas
10. Agenda telefónica
11. Salir
"""

import random
import string


# ----------------------------------
# 1. CALCULADORA
# ----------------------------------

def sumar(a, b):
    return a + b


def restar(a, b):
    return a - b


def multiplicar(a, b):
    return a * b


def dividir(a, b):

    if b == 0:
        return None

    return a / b


def calculadora():

    print("\n--- CALCULADORA ---")

    numero1 = float(
        input("Primer número: ")
    )

    numero2 = float(
        input("Segundo número: ")
    )

    print("1. Sumar")
    print("2. Restar")
    print("3. Multiplicar")
    print("4. Dividir")

    opcion = input(
        "Seleccione una operación: "
    )

    if opcion == "1":
        resultado = sumar(
            numero1,
            numero2
        )

    elif opcion == "2":
        resultado = restar(
            numero1,
            numero2
        )

    elif opcion == "3":
        resultado = multiplicar(
            numero1,
            numero2
        )

    elif opcion == "4":

        resultado = dividir(
            numero1,
            numero2
        )

        if resultado is None:

            print(
                "No se puede dividir entre cero."
            )

            return

    else:

        print("Opción inválida.")
        return

    print(
        "Resultado:",
        resultado
    )


# ----------------------------------
# 2. FILTRAR NÚMEROS PARES
# ----------------------------------

def filtrar_pares(lista):

    pares = []

    for numero in lista:

        if numero % 2 == 0:
            pares.append(numero)

    return pares


def opcion_filtrar_pares():

    print(
        "\n--- FILTRAR NÚMEROS PARES ---"
    )

    texto = input(
        "Ingrese números separados por espacios: "
    )

    numeros = []

    for numero in texto.split():

        numeros.append(
            int(numero)
        )

    pares = filtrar_pares(
        numeros
    )

    print(
        "Números pares:",
        pares
    )


# ----------------------------------
# 3. CELSIUS A FAHRENHEIT
# ----------------------------------

def convertir_temperaturas():

    print(
        "\n--- CELSIUS A FAHRENHEIT ---"
    )

    texto = input(
        "Ingrese temperaturas separadas por espacios: "
    )

    temperaturas = []

    for valor in texto.split():

        temperaturas.append(
            float(valor)
        )

    fahrenheit = list(
        map(
            lambda c: c * 9 / 5 + 32,
            temperaturas
        )
    )

    print(
        "Temperaturas en Fahrenheit:",
        fahrenheit
    )


# ----------------------------------
# 4. CALIFICACIONES
# ----------------------------------

def convertir_calificaciones(lista):

    letras = []

    for nota in lista:

        if nota >= 90:
            letras.append("A")

        elif nota >= 80:
            letras.append("B")

        elif nota >= 70:
            letras.append("C")

        elif nota >= 60:
            letras.append("D")

        else:
            letras.append("F")

    return letras


def sistema_calificaciones():

    print(
        "\n--- SISTEMA DE CALIFICACIONES ---"
    )

    texto = input(
        "Ingrese notas separadas por espacios: "
    )

    notas = []

    for valor in texto.split():

        nota = float(valor)

        if nota < 0 or nota > 100:

            print(
                "Las notas deben estar entre 0 y 100."
            )

            return

        notas.append(
            nota
        )

    resultado = convertir_calificaciones(
        notas
    )

    print(
        "Calificaciones:",
        resultado
    )


# ----------------------------------
# 5. CONTEO DE PALABRAS
# ----------------------------------

def contar_palabras(texto):

    texto = texto.lower()

    for signo in string.punctuation:

        texto = texto.replace(
            signo,
            ""
        )

    palabras = texto.split()

    conteo = {}

    for palabra in palabras:

        if palabra in conteo:

            conteo[palabra] += 1

        else:

            conteo[palabra] = 1

    return conteo


def opcion_contar_palabras():

    print(
        "\n--- CONTEO DE PALABRAS ---"
    )

    texto = input(
        "Ingrese una frase: "
    )

    resultado = contar_palabras(
        texto
    )

    for palabra in resultado:

        print(
            palabra,
            ":",
            resultado[palabra]
        )


# ----------------------------------
# 6. BÚSQUEDA
# ----------------------------------

def buscar_elemento(lista, elemento):

    for i in range(
        len(lista)
    ):

        if lista[i] == elemento:

            return i

    return -1


def opcion_busqueda():

    print(
        "\n--- BÚSQUEDA EN LISTA ---"
    )

    texto = input(
        "Ingrese elementos separados por espacios: "
    )

    lista = texto.split()

    elemento = input(
        "Elemento que desea buscar: "
    )

    posicion = buscar_elemento(
        lista,
        elemento
    )

    if posicion == -1:

        print(
            "El elemento no está en la lista."
        )

    else:

        print(
            "El elemento está en el índice:",
            posicion
        )


# ----------------------------------
# 7. PARÉNTESIS
# ----------------------------------

def validar_parentesis(cadena):

    contador = 0

    for caracter in cadena:

        if caracter == "(":

            contador += 1

        elif caracter == ")":

            contador -= 1

        else:

            return False

        if contador < 0:

            return False

    return contador == 0


def opcion_parentesis():

    print(
        "\n--- VALIDACIÓN DE PARÉNTESIS ---"
    )

    cadena = input(
        "Ingrese los paréntesis: "
    )

    if validar_parentesis(
        cadena
    ):

        print(
            "La secuencia es válida."
        )

    else:

        print(
            "La secuencia no es válida."
        )


# ----------------------------------
# 8. ORDENAMIENTO
# ----------------------------------

def ordenar_personas(personas):

    return sorted(
        personas,
        key=lambda persona: (
            persona[1],
            persona[0]
        )
    )


def opcion_ordenamiento():

    print(
        "\n--- ORDENAMIENTO ---"
    )

    personas = []

    cantidad = int(
        input(
            "¿Cuántas personas desea ingresar?: "
        )
    )

    for i in range(
        cantidad
    ):

        print(
            "\nPersona",
            i + 1
        )

        nombre = input(
            "Nombre: "
        )

        edad = int(
            input("Edad: ")
        )

        personas.append(
            (nombre, edad)
        )

    resultado = ordenar_personas(
        personas
    )

    print(
        "\nLista ordenada:"
    )

    for persona in resultado:

        print(
            persona
        )


# ----------------------------------
# 9. CONTRASEÑAS
# ----------------------------------

def generar_contrasena(longitud):

    caracteres = (
        string.ascii_letters
        + string.digits
        + string.punctuation
    )

    contrasena = ""

    for i in range(
        longitud
    ):

        contrasena += random.choice(
            caracteres
        )

    return contrasena


def opcion_contrasena():

    print(
        "\n--- GENERADOR DE CONTRASEÑAS ---"
    )

    longitud = int(
        input(
            "Longitud de la contraseña: "
        )
    )

    if longitud <= 0:

        print(
            "La longitud debe ser mayor que cero."
        )

        return

    contrasena = generar_contrasena(
        longitud
    )

    print(
        "Contraseña generada:",
        contrasena
    )


# ----------------------------------
# 10. AGENDA TELEFÓNICA
# ----------------------------------

agenda = {}


def agregar_contacto():

    nombre = input(
        "Nombre: "
    )

    telefono = input(
        "Teléfono: "
    )

    agenda[nombre] = telefono

    print(
        "Contacto agregado."
    )


def buscar_contacto():

    nombre = input(
        "Nombre del contacto: "
    )

    if nombre in agenda:

        print(
            "Teléfono:",
            agenda[nombre]
        )

    else:

        print(
            "Contacto no encontrado."
        )


def eliminar_contacto():

    nombre = input(
        "Contacto que desea eliminar: "
    )

    if nombre in agenda:

        del agenda[nombre]

        print(
            "Contacto eliminado."
        )

    else:

        print(
            "Contacto no encontrado."
        )


def mostrar_contactos():

    if len(agenda) == 0:

        print(
            "La agenda está vacía."
        )

        return

    print(
        "\n--- CONTACTOS ---"
    )

    for nombre in agenda:

        print(
            nombre,
            ":",
            agenda[nombre]
        )


def agenda_telefonica():

    while True:

        print(
            "\n--- AGENDA TELEFÓNICA ---"
        )

        print("1. Agregar contacto")
        print("2. Buscar contacto")
        print("3. Eliminar contacto")
        print("4. Mostrar contactos")
        print("5. Volver")

        opcion = input(
            "Seleccione una opción: "
        )

        if opcion == "1":

            agregar_contacto()

        elif opcion == "2":

            buscar_contacto()

        elif opcion == "3":

            eliminar_contacto()

        elif opcion == "4":

            mostrar_contactos()

        elif opcion == "5":

            break

        else:

            print(
                "Opción inválida."
            )


# ----------------------------------
# MENÚ PRINCIPAL
# ----------------------------------

def menu():

    while True:

        print("\n==================================")
        print("        TALLER DE PYTHON")
        print("==================================")

        print("1. Calculadora")
        print("2. Filtrar números pares")
        print("3. Celsius a Fahrenheit")
        print("4. Sistema de calificaciones")
        print("5. Conteo de palabras")
        print("6. Buscar elemento")
        print("7. Validar paréntesis")
        print("8. Ordenar personas")
        print("9. Generar contraseña")
        print("10. Agenda telefónica")
        print("11. Salir")

        print("==================================")

        opcion = input(
            "Seleccione una opción: "
        )

        if opcion == "1":

            calculadora()

        elif opcion == "2":

            opcion_filtrar_pares()

        elif opcion == "3":

            convertir_temperaturas()

        elif opcion == "4":

            sistema_calificaciones()

        elif opcion == "5":

            opcion_contar_palabras()

        elif opcion == "6":

            opcion_busqueda()

        elif opcion == "7":

            opcion_parentesis()

        elif opcion == "8":

            opcion_ordenamiento()

        elif opcion == "9":

            opcion_contrasena()

        elif opcion == "10":

            agenda_telefonica()

        elif opcion == "11":

            print(
                "Programa finalizado."
            )

            break

        else:

            print(
                "Opción inválida."
            )

menu()
