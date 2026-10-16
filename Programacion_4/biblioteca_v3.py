"""
Práctica 3 - Unidad 3: Herencia.
Sistema de préstamo de la biblioteca universitaria (tercera iteración).

Partes incluidas en este archivo:
    B -> Material: clase base abstracta (antes Libro) con dias_prestamo abstracto
    C -> LibroFisico y RecursoDigital: subclases que usan super()
    D -> __str__ y __repr__ en Material, LibroFisico, RecursoDigital, Usuario y Prestamo

(La Parte A es la tabla escrita y la Parte F, la integración con el préstamo,
 queda pendiente para Lizeth.)
"""

from abc import ABC, abstractmethod
from datetime import date, timedelta


# ----------------------------------------------------------------------
# [Parte B] Clase base abstracta
# ----------------------------------------------------------------------
class Material(ABC):
    """
    Material de la biblioteca (libro físico, recurso digital, etc.).

    Es la antigua clase Libro con otro nombre. Contiene todo lo que es común
    a cualquier material y declara como abstracto lo que cada tipo debe
    resolver por su cuenta: cuántos días se puede prestar.
    Al heredar de ABC, no se pueden crear objetos Material "a secas".
    """

    def __init__(self, titulo, autor, isbn, ejemplares_totales, **detalles):
        """
        Parámetros:
            titulo (str): título del material.
            autor (str): nombre del autor.
            isbn (str): código único del material.
            ejemplares_totales (int): copias (o licencias) totales.
            **detalles: datos opcionales con nombre (editorial, anio, categoria...).
        """
        self.titulo = titulo
        self.autor = autor
        self.isbn = isbn
        self.ejemplares_totales = ejemplares_totales
        # Atributo protegido: solo se modifica vía la propiedad `disponibles`.
        self._ejemplares_disponibles = ejemplares_totales
        self.detalles = detalles

    # ---- Propiedad con validación (sin cambios respecto a la Práctica 2) ----
    @property
    def disponibles(self):
        """Getter: devuelve los ejemplares disponibles."""
        return self._ejemplares_disponibles

    @disponibles.setter
    def disponibles(self, valor):
        """Setter: rechaza valores negativos o mayores a ejemplares_totales."""
        if valor < 0 or valor > self.ejemplares_totales:
            raise ValueError(
                f"Valor inválido: debe estar entre 0 y {self.ejemplares_totales}"
            )
        self._ejemplares_disponibles = valor

    # ---- Métodos que usan self (sin cambios respecto a la Práctica 2) ----
    def esta_disponible(self):
        """Devuelve True si queda al menos un ejemplar."""
        return self.disponibles > 0

    def prestar(self):
        """Reduce en 1 los ejemplares disponibles (la validación la hace el setter)."""
        if not self.esta_disponible():
            raise ValueError(f"No hay ejemplares disponibles de {self.titulo}")
        self.disponibles = self.disponibles - 1

    def devolver(self):
        """Aumenta en 1 los ejemplares disponibles (el setter evita pasarse del total)."""
        self.disponibles = self.disponibles + 1

    # ---- Método abstracto: cada subclase está obligada a definirlo ----
    @abstractmethod
    def dias_prestamo(self):
        """Cantidad de días que puede prestarse este material."""

    # ---- [Parte D] Presentación del objeto ----
    def __str__(self):
        """Para personas (lo que usa print)."""
        return f"{self.titulo} - {self.autor}"

    def __repr__(self):
        """Para programadores: muestra cómo volver a construir el objeto."""
        return (f"{type(self).__name__}(titulo={self.titulo!r}, "
                f"autor={self.autor!r}, isbn={self.isbn!r}, "
                f"ejemplares_totales={self.ejemplares_totales!r})")


# ----------------------------------------------------------------------
# [Parte C] Subclases concretas
# ----------------------------------------------------------------------
class LibroFisico(Material):
    """Libro de papel: tiene una ubicación en el estante y se presta 14 días."""

    def __init__(self, titulo, autor, isbn, ejemplares_totales,
                 ubicacion="Sin asignar", **detalles):
        # super() reutiliza el constructor del padre sin copiarlo.
        super().__init__(titulo, autor, isbn, ejemplares_totales, **detalles)
        self.ubicacion = ubicacion

    def dias_prestamo(self):
        """Un libro físico se presta por 14 días."""
        return 14

    # [Parte D] __str__ extiende el del padre en lugar de reescribirlo.
    def __str__(self):
        return f"{super().__str__()} [Fisico, estante {self.ubicacion}]"

    def __repr__(self):
        return (f"{type(self).__name__}(titulo={self.titulo!r}, "
                f"autor={self.autor!r}, isbn={self.isbn!r}, "
                f"ejemplares_totales={self.ejemplares_totales!r}, "
                f"ubicacion={self.ubicacion!r})")


class RecursoDigital(Material):
    """Recurso en línea (e-book): tiene formato y enlace, y se presta 7 días."""

    def __init__(self, titulo, autor, isbn, ejemplares_totales,
                 formato="PDF", url="", **detalles):
        super().__init__(titulo, autor, isbn, ejemplares_totales, **detalles)
        self.formato = formato
        self.url = url

    def dias_prestamo(self):
        """Un recurso digital se presta por 7 días."""
        return 7

    # [Parte D] "Por tu cuenta": __str__ y __repr__ de RecursoDigital.
    def __str__(self):
        return f"{super().__str__()} [Digital, {self.formato}]"

    def __repr__(self):
        return (f"{type(self).__name__}(titulo={self.titulo!r}, "
                f"autor={self.autor!r}, isbn={self.isbn!r}, "
                f"ejemplares_totales={self.ejemplares_totales!r}, "
                f"formato={self.formato!r}, url={self.url!r})")


# ----------------------------------------------------------------------
# Clases de la Práctica 2 (sin cambios, salvo __str__ y __repr__ de la Parte D)
# ----------------------------------------------------------------------
class Usuario:
    """Persona que puede solicitar materiales en préstamo."""

    def __init__(self, nombre, codigo_estudiantil, tipo_usuario="estudiante"):
        self.nombre = nombre
        self.codigo_estudiantil = codigo_estudiantil
        self.tipo_usuario = tipo_usuario

    @staticmethod
    def es_codigo_valido(codigo):
        """True si el código son solo dígitos y tiene 10 caracteres."""
        return codigo.isdigit() and len(codigo) == 10

    # [Parte D] "Por tu cuenta"
    def __str__(self):
        return f"{self.nombre} ({self.tipo_usuario})"

    def __repr__(self):
        return (f"{type(self).__name__}(nombre={self.nombre!r}, "
                f"codigo_estudiantil={self.codigo_estudiantil!r}, "
                f"tipo_usuario={self.tipo_usuario!r})")


class Prestamo:
    """Relaciona un material con un usuario en un periodo de tiempo."""

    def __init__(self, libro, usuario, fecha_prestamo, fecha_devolucion_esperada):
        self.libro = libro
        self.usuario = usuario
        self.fecha_prestamo = fecha_prestamo
        self.fecha_devolucion_esperada = fecha_devolucion_esperada

    @classmethod
    def registrar_hoy(cls, libro, usuario, dias_prestamo=14):
        """Crea un Prestamo con la fecha de hoy.
        (Parte F pendiente: hacer que el plazo lo decida el material.)"""
        hoy = date.today()
        fecha_limite = hoy + timedelta(days=dias_prestamo)
        return cls(libro, usuario, hoy, fecha_limite)

    # [Parte D] "Por tu cuenta"
    def __str__(self):
        return (f"Préstamo de '{self.libro.titulo}' a {self.usuario.nombre}: "
                f"del {self.fecha_prestamo} al {self.fecha_devolucion_esperada}")

    def __repr__(self):
        return (f"{type(self).__name__}(libro={self.libro!r}, "
                f"usuario={self.usuario!r}, "
                f"fecha_prestamo={self.fecha_prestamo!r}, "
                f"fecha_devolucion_esperada={self.fecha_devolucion_esperada!r})")


class ComprobantePrestamo:
    """Comprobante inmutable (__slots__ + propiedades sin setter), sin cambios."""

    __slots__ = ("_libro_titulo", "_usuario_nombre",
                 "_fecha_prestamo", "_fecha_devolucion_esperada")

    def __init__(self, prestamo):
        self._libro_titulo = prestamo.libro.titulo
        self._usuario_nombre = prestamo.usuario.nombre
        self._fecha_prestamo = prestamo.fecha_prestamo
        self._fecha_devolucion_esperada = prestamo.fecha_devolucion_esperada

    @property
    def libro_titulo(self):
        return self._libro_titulo

    @property
    def usuario_nombre(self):
        return self._usuario_nombre

    @property
    def fecha_prestamo(self):
        return self._fecha_prestamo

    @property
    def fecha_devolucion_esperada(self):
        return self._fecha_devolucion_esperada


# ----------------------------------------------------------------------
# Pruebas rápidas
# ----------------------------------------------------------------------
if __name__ == "__main__":
    # Parte B: Material es abstracta, no se puede instanciar
    try:
        m = Material("Cualquiera", "Alguien", "123", 1)
    except TypeError as error:
        print("Error esperado (clase abstracta):", error)

    # Parte C
    fisico = LibroFisico("Clean Code", "Robert C. Martin",
                         "978-0132350884", 2, ubicacion="B-12")
    digital = RecursoDigital("Fluent Python", "Luciano Ramalho",
                             "978-1492056355", 5, formato="EPUB")

    fisico.prestar()
    print(fisico.disponibles, fisico.dias_prestamo())    # 1 14
    print(digital.dias_prestamo())                       # 7
    print(isinstance(fisico, Material), isinstance(fisico, RecursoDigital))  # True False

    # Parte D
    print(fisico)          # Clean Code - Robert C. Martin [Fisico, estante B-12]
    print(repr(fisico))
    print([fisico, digital])   # una lista muestra el __repr__ de cada elemento
    print(digital)
    u1 = Usuario("Camila Ruiz", "1093812345")
    print(u1)              # Camila Ruiz (estudiante)
    print(repr(u1))
    prestamo = Prestamo.registrar_hoy(fisico, u1)
    print(prestamo)
    print(repr(prestamo))
