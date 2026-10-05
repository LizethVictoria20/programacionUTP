"""
Práctica 2 - Unidad 2: Encapsulamiento y manejo de datos.
Sistema de préstamo de la biblioteca universitaria (segunda iteración).

Partes incluidas en este archivo:
    B -> propiedad `disponibles` en Libro (con validación)
    C -> constructores flexibles (valor por defecto y **detalles)
    D -> métodos con self: esta_disponible(), prestar(), devolver()
    E -> @classmethod Prestamo.registrar_hoy y @staticmethod Usuario.es_codigo_valido



"""

from datetime import date, timedelta


class Libro:
    """Representa un libro de la biblioteca con su inventario protegido."""

    def __init__(self, titulo, autor, isbn, ejemplares_totales, **detalles):
        """
        Crea un nuevo libro.

        Parámetros:
            titulo (str): título del libro.
            autor (str): nombre del autor.
            isbn (str): código único del libro.
            ejemplares_totales (int): cantidad total de copias.
            **detalles: datos opcionales con nombre (editorial, anio, categoria...).
                        [Parte C] Se agrupan en un diccionario.
        """
        self.titulo = titulo
        self.autor = autor
        self.isbn = isbn
        self.ejemplares_totales = ejemplares_totales
        # [Parte B] Atributo protegido: solo se modifica vía la propiedad `disponibles`.
        self._ejemplares_disponibles = ejemplares_totales
        # [Parte C] Diccionario con los datos opcionales.
        self.detalles = detalles

    # ---------------- [Parte B] Propiedad con validación ----------------
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

    # ---------------- [Parte D] Métodos que usan self ----------------
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


class Usuario:
    """Persona que puede solicitar libros en préstamo."""

    def __init__(self, nombre, codigo_estudiantil, tipo_usuario="estudiante"):
        """
        Parámetros:
            nombre (str): nombre del usuario.
            codigo_estudiantil (str): código de 10 dígitos.
            tipo_usuario (str): por defecto "estudiante".  [Parte C]
        """
        self.nombre = nombre
        self.codigo_estudiantil = codigo_estudiantil
        self.tipo_usuario = tipo_usuario

    # ---------------- [Parte E] Validador estático ----------------
    @staticmethod
    def es_codigo_valido(codigo):
        """True si el código son solo dígitos y tiene 10 caracteres.
        No necesita un objeto Usuario, por eso es @staticmethod."""
        return codigo.isdigit() and len(codigo) == 10


class Prestamo:
    """Relaciona un Libro con un Usuario en un periodo de tiempo."""

    def __init__(self, libro, usuario, fecha_prestamo, fecha_devolucion_esperada):
        self.libro = libro
        self.usuario = usuario
        self.fecha_prestamo = fecha_prestamo
        self.fecha_devolucion_esperada = fecha_devolucion_esperada
        # [Extra 2] Un préstamo nuevo siempre empieza sin devolver.
        self.devuelto = False

    
    # ---------------- [Parte E] Constructor alternativo ----------------
    @classmethod
    def registrar_hoy(cls, libro, usuario, dias_prestamo=14):
        """Crea un Prestamo con la fecha de hoy y devolución en `dias_prestamo` días.
        Usa `cls` (no `Prestamo`) para que funcione también con subclases."""
        hoy = date.today()
        fecha_limite = hoy + timedelta(days=dias_prestamo)
        return cls(libro, usuario, hoy, fecha_limite)


# ----------------------------------------------------------------------
# No repite validaciones: reutiliza lo que ya hacen Libro, Usuario y Prestamo.
# ----------------------------------------------------------------------
class Biblioteca:
    """Guarda los registros de libros, usuarios y préstamos y coordina las acciones."""

    def __init__(self):
        self.libros = []      # lista de objetos Libro
        self.usuarios = []    # lista de objetos Usuario
        self.prestamos = []   # lista de objetos Prestamo

    def registrar_libro(self, libro):
        """Agrega un Libro al registro."""
        self.libros.append(libro)

    def registrar_usuario(self, usuario):
        """Agrega un Usuario al registro, validando su código con el método estático."""
        if not Usuario.es_codigo_valido(usuario.codigo_estudiantil):
            raise ValueError(f"Código estudiantil inválido: {usuario.codigo_estudiantil}")
        self.usuarios.append(usuario)

    def buscar_libro(self, isbn):
        """Devuelve el Libro con ese ISBN o lanza ValueError si no existe."""
        for libro in self.libros:
            if libro.isbn == isbn:
                return libro
        raise ValueError(f"No existe un libro con ISBN {isbn}")

    def buscar_usuario(self, codigo):
        """Devuelve el Usuario con ese código o lanza ValueError si no existe."""
        for usuario in self.usuarios:
            if usuario.codigo_estudiantil == codigo:
                return usuario
        raise ValueError(f"No existe un usuario con código {codigo}")

    def prestar_libro(self, isbn, codigo, dias_prestamo=14):
        """Presta un libro: baja el inventario (Libro.prestar) y crea el Prestamo."""
        libro = self.buscar_libro(isbn)
        usuario = self.buscar_usuario(codigo)
        libro.prestar()
        prestamo = Prestamo.registrar_hoy(libro, usuario, dias_prestamo)
        self.prestamos.append(prestamo)
        return prestamo

    def devolver_libro(self, isbn, codigo):
        """Cierra el préstamo abierto de ese usuario y libro, y sube el inventario."""
        for prestamo in self.prestamos:
            if (not prestamo.devuelto
                    and prestamo.libro.isbn == isbn
                    and prestamo.usuario.codigo_estudiantil == codigo):
                prestamo.cerrar()          # Extra 2
                prestamo.libro.devolver()  # Parte D
                return prestamo
        raise ValueError("No hay un préstamo abierto con esos datos")

    def listar_prestamos(self, solo_abiertos=False):
        """Devuelve la lista de préstamos (opcionalmente solo los no devueltos)."""
        if solo_abiertos:
            return [p for p in self.prestamos if not p.devuelto]
        return list(self.prestamos)


# ----------------------------------------------------------------------
# Pruebas rápidas 
# ----------------------------------------------------------------------
if __name__ == "__main__":
    # Parte B
    libro_1 = Libro("Fluent Python", "Luciano Ramalho", "978-1492056355", 3)
    libro_1.disponibles = 2
    print(libro_1.disponibles)  # 2
    try:
        libro_1.disponibles = 10
    except ValueError as error:
        print("Error esperado:", error)

    # Parte C
    u1 = Usuario("Camila Ruiz", "1093812345")
    libro_2 = Libro("Clean Code", "Robert C. Martin", "978-0132350884", 2,
                    editorial="Prentice Hall", anio=2008)
    print(u1.tipo_usuario)    # estudiante
    print(libro_2.detalles)   # {'editorial': 'Prentice Hall', 'anio': 2008}

    # Parte D
    libro_1.prestar()
    print(libro_1.disponibles)  # 1
    libro_1.devolver()
    print(libro_1.disponibles)  # 2

    # Parte E
    prestamo_1 = Prestamo.registrar_hoy(libro_1, u1)
    print(prestamo_1.fecha_devolucion_esperada)
    print(Usuario.es_codigo_valido("1093812345"))  # True
    print(Usuario.es_codigo_valido("abc"))         # False

    # [Extra 2] Estado del préstamo
    print(prestamo_1.devuelto)         # False
    print(prestamo_1.esta_vencido())   # False (vence en 14 días)
    prestamo_1.cerrar()
    print(prestamo_1.devuelto)         # True

    