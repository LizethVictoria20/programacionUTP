"""
Practica 1 - Unidad 1: Fundamentos
Sistema de prestamo de la biblioteca universitaria.

Este modulo define tres clases relacionadas entre si:
- Libro: representa un libro fisico de la biblioteca.
- Estudiante: representa a la persona que puede pedir libros prestados.
- Prestamo: relaciona un Libro con un Estudiante en una fecha determinada.
"""


class Libro:
    """Representa un libro fisico disponible en la biblioteca."""

    def __init__(self, nombre, autor, isbn, categoria):
        """
        Crea un nuevo libro.

        Parametros:
            nombre (str): titulo del libro.
            autor (str): nombre del autor.
            isbn (str): codigo unico que identifica al libro.
            categoria (str): genero o categoria (ej. "Novela").
        """
        self.nombre = nombre
        self.autor = autor
        self.isbn = isbn
        self.categoria = categoria


class Estudiante:
    """Representa a la persona que puede solicitar libros en prestamo."""

    def __init__(self, nombre, apellido, edad, cedula, activo):
        """
        Crea un nuevo estudiante.

        Parametros:
            nombre (str): nombre del estudiante.
            apellido (str): apellido del estudiante.
            edad (int): edad del estudiante.
            cedula (str): numero de identificacion.
            activo (bool): True si el estudiante puede pedir prestamos.
        """
        self.nombre = nombre
        self.apellido = apellido
        self.edad = edad
        self.cedula = cedula
        self.activo = activo


class Prestamo:
    """
    Relaciona un Libro con un Estudiante en un momento dado.

    Nota: 'libro' y 'estudiante' guardan el objeto completo (no solo
    su nombre), por eso se puede acceder a sus atributos a traves del
    prestamo, por ejemplo: prestamo1.libro.autor
    """

    def __init__(self, libro, estudiante, fecha_inicio, fecha_devolucion):
        """
        Crea un nuevo registro de prestamo.

        Parametros:
            libro (Libro): objeto Libro que se presta.
            estudiante (Estudiante): objeto Estudiante que lo solicita.
            fecha_inicio (str): fecha en que se realiza el prestamo.
            fecha_devolucion (str): fecha limite para devolverlo.
        """
        self.libro = libro
        self.estudiante = estudiante
        self.fecha_inicio = fecha_inicio
        self.fecha_devolucion = fecha_devolucion


# --------------------------------------------------------------------
# Ejemplo de uso
# --------------------------------------------------------------------
if __name__ == "__main__":
    # Creamos un objeto (instancia) a partir de la clase Libro
    libro1 = Libro(
        nombre="100 años de soledad",
        autor="Gabriel Garcia Marquez",
        isbn="1000826001",
        categoria="Novela",
    )
    print(libro1.nombre)
    print(libro1.autor)

    # Creamos un objeto a partir de la clase Estudiante
    estudiante1 = Estudiante(
        nombre="Camilo",
        apellido="Perez",
        edad=25,
        cedula="1065478236",
        activo=True,
    )
    print(estudiante1.nombre)
    print("Es estudiante activo:", estudiante1.activo)

    # Creamos un objeto Prestamo que relaciona a libro1 con estudiante1
    prestamo1 = Prestamo(
        libro=libro1,
        estudiante=estudiante1,
        fecha_inicio="21/09/2026",
        fecha_devolucion="05/10/2026",
    )
    print(prestamo1.estudiante.nombre)
    print(prestamo1.libro.nombre)
    print("Prestado desde:", prestamo1.fecha_inicio, "hasta", prestamo1.fecha_devolucion)
