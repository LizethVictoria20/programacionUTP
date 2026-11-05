"""
Práctica 4 - Unidad 4: Polimorfismo e interfaces.
Sistema de préstamo de la biblioteca universitaria (cuarta iteración).

Se conserva sin cambios la jerarquía Material, LibroFisico, RecursoDigital y
LibroHibrido de la Práctica 3, y ComprobantePrestamo de la Práctica 2.

Partes incluidas en este archivo:
    B -> Usuario deja de ser una clase única: jerarquía abstracta
         (Estudiante, Docente, Externo)
    C -> Polimorfismo: la clase Investigador se agrega sin tocar nada más
    D -> Interfaz Notificador (ABC) y dos implementaciones
         (NotificadorConsola y NotificadorCorreo)

    E -> Biblioteca: catálogo, préstamos y un canal de notificación recibido de afuera
    F -> Duck typing y Protocol (ServicioSMS de una librería externa, CanalNotificacion)

(La Parte A son las relaciones y el diagrama de clases, están en el documento de
 respuestas.)
"""

from abc import ABC, abstractmethod
from datetime import date, timedelta
from typing import Protocol, runtime_checkable


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
# [Parte E] Herencia múltiple
# ----------------------------------------------------------------------
class LibroHibrido(LibroFisico, RecursoDigital):
    """Título que llega en papel y en digital a la vez."""

    def dias_prestamo(self):
        """Se aplica el plazo más corto de los dos padres (7 días)."""
        return min(LibroFisico.dias_prestamo(self),
                   RecursoDigital.dias_prestamo(self))

    def __repr__(self):
        return (f"{type(self).__name__}(titulo={self.titulo!r}, "
                f"autor={self.autor!r}, isbn={self.isbn!r}, "
                f"ejemplares_totales={self.ejemplares_totales!r}, "
                f"ubicacion={self.ubicacion!r}, formato={self.formato!r})")


# ----------------------------------------------------------------------
# [Parte B] Jerarquía de usuarios
# ----------------------------------------------------------------------
class Usuario(ABC):
    """
    Persona que puede solicitar materiales en préstamo.

    Nombre y código son comunes a todos. Lo que varía entre tipos de usuario
    (el límite de préstamos y la multa por día) se declara abstracto; calcular
    la multa total es igual para todos y se escribe una sola vez aquí.
    """

    def __init__(self, nombre, codigo_estudiantil):
        self.nombre = nombre
        self.codigo_estudiantil = codigo_estudiantil

    @property
    def tipo(self):
        """Nombre de la clase en minúscula: 'estudiante', 'docente', ..."""
        return type(self).__name__.lower()

    @staticmethod
    def es_codigo_valido(codigo):
        """True si el código son solo dígitos y tiene 10 caracteres (Práctica 2)."""
        return codigo.isdigit() and len(codigo) == 10

    @abstractmethod
    def limite_prestamos(self):
        """Cantidad máxima de préstamos activos al mismo tiempo."""

    @abstractmethod
    def multa_por_dia(self):
        """Valor de la multa (en pesos) por cada día de retraso."""

    def calcular_multa(self, dias_retraso):
        """Multa total: igual para todos los tipos, usa la multa por día de cada uno."""
        return max(0, dias_retraso) * self.multa_por_dia()

    def __str__(self):
        return f"{self.nombre} ({self.tipo})"

    def __repr__(self):
        return (f"{type(self).__name__}(nombre={self.nombre!r}, "
                f"codigo_estudiantil={self.codigo_estudiantil!r})")


class Estudiante(Usuario):
    """Estudiante: 3 préstamos a la vez y $500 de multa por día."""

    def limite_prestamos(self):
        return 3

    def multa_por_dia(self):
        return 500


class Docente(Usuario):
    """Docente: 5 préstamos a la vez y $300 de multa por día."""

    def limite_prestamos(self):
        return 5

    def multa_por_dia(self):
        return 300


class Externo(Usuario):
    """Persona externa a la universidad: 1 préstamo a la vez y $1000 de multa por día."""

    def limite_prestamos(self):
        return 1

    def multa_por_dia(self):
        return 1000


# ----------------------------------------------------------------------
# [Parte C] Polimorfismo: un tipo nuevo sin modificar ninguna otra clase
# ----------------------------------------------------------------------
class Investigador(Usuario):
    """Investigador: 10 préstamos a la vez y sin multa."""

    def limite_prestamos(self):
        return 10

    def multa_por_dia(self):
        return 0


class Prestamo:
    """Relaciona un material con un usuario en un periodo de tiempo."""

    def __init__(self, libro, usuario, fecha_prestamo, fecha_devolucion_esperada):
        self.libro = libro
        self.usuario = usuario
        self.fecha_prestamo = fecha_prestamo
        self.fecha_devolucion_esperada = fecha_devolucion_esperada
        self.fecha_devolucion_real = None

    @property
    def activo(self):
        """True mientras el préstamo no se haya devuelto."""
        return self.fecha_devolucion_real is None

    def dias_retraso(self, fecha_real):
        """Días de retraso respecto a la fecha esperada (0 si llegó a tiempo)."""
        return max(0, (fecha_real - self.fecha_devolucion_esperada).days)

    def registrar_devolucion(self, fecha_real):
        """Guarda la fecha en que realmente se devolvió el material."""
        self.fecha_devolucion_real = fecha_real

    @classmethod
    def registrar_hoy(cls, libro, usuario, dias_prestamo=None):
        """Crea un Prestamo con la fecha de hoy.
        [Parte F] Si no se indica plazo, se lo pregunta al material."""
        hoy = date.today()
        if dias_prestamo is None:
            dias_prestamo = libro.dias_prestamo()
        return cls(libro, usuario, hoy, hoy + timedelta(days=dias_prestamo))

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
# [Parte D] Interfaz para notificar
# ----------------------------------------------------------------------
class Notificador(ABC):
    """Interfaz: solo declara qué se puede hacer, no cómo."""

    @abstractmethod
    def enviar(self, destinatario, mensaje):
        """Envía el mensaje al destinatario."""


class NotificadorConsola(Notificador):
    """Muestra el aviso en la consola."""

    def enviar(self, destinatario, mensaje):
        print(f"[consola] Para {destinatario}: {mensaje}")


class NotificadorCorreo(Notificador):
    """Simula un correo: guarda los mensajes en una bandeja de salida."""

    def __init__(self):
        self.bandeja_salida = []

    def enviar(self, destinatario, mensaje):
        self.bandeja_salida.append((destinatario, mensaje))


# ----------------------------------------------------------------------
# [Parte E] La clase Biblioteca
# ----------------------------------------------------------------------
class Biblioteca:
    """Agrega materiales, compone sus préstamos y usa un canal que recibe de afuera."""

    def __init__(self, nombre, canal):
        self.nombre = nombre
        self._catalogo = {}        
        self._prestamos = []       
        self._canal = canal      

    def agregar_material(self, material):
        self._catalogo[material.isbn] = material

    def prestamos_activos_de(self, usuario):
        return [p for p in self._prestamos
                if p.usuario is usuario and p.activo]

    def prestar(self, isbn, usuario):
        if isbn not in self._catalogo:
            raise ValueError(f"ISBN {isbn} no esta en el catalogo")
        if len(self.prestamos_activos_de(usuario)) >= usuario.limite_prestamos():
            raise ValueError(f"{usuario.nombre} alcanzo su limite")
        material = self._catalogo[isbn]
        material.prestar()
        prestamo = Prestamo.registrar_hoy(material, usuario)
        self._prestamos.append(prestamo)
        self._canal.enviar(usuario.nombre,
                           f"Prestamo de {material.titulo}: devolver el "
                           f"{prestamo.fecha_devolucion_esperada}")
        return prestamo

    def devolver(self, prestamo, fecha_real=None):
        """Registra la devolución, libera el ejemplar y cobra la multa si hay retraso.
        Devuelve el valor de la multa."""
        if fecha_real is None:
            fecha_real = date.today()
        prestamo.registrar_devolucion(fecha_real)
        prestamo.libro.devolver()
        multa = prestamo.usuario.calcular_multa(prestamo.dias_retraso(fecha_real))
        if multa > 0:
            self._canal.enviar(prestamo.usuario.nombre,
                               f"Multa por devolver {prestamo.libro.titulo} "
                               f"con retraso: ${multa}")
        return multa


# ----------------------------------------------------------------------
# [Parte F] Duck typing y Protocol
# ----------------------------------------------------------------------
class ServicioSMS:
    """Simula la clase de una librería externa: no se puede modificar
    ni hacer que herede de Notificador."""

    def __init__(self):
        self.enviados = []

    def enviar(self, destinatario, mensaje):
        self.enviados.append((destinatario, mensaje[:160]))


@runtime_checkable
class CanalNotificacion(Protocol):
    """Describe la forma que debe tener un canal, sin exigir herencia."""

    def enviar(self, destinatario, mensaje): ...


# ----------------------------------------------------------------------
# Pruebas rápidas
# ----------------------------------------------------------------------
if __name__ == "__main__":
    # Parte B: Usuario es abstracta
    try:
        Usuario("Cualquiera", "0000000000")
    except TypeError as error:
        print("Error esperado (usuario abstracto):", error)

    usuarios = [Estudiante("Camila Ruiz", "1093812345"),
                Docente("Luis Mora", "1093800001"),
                Externo("Ana Gil", "1093800002")]

    for u in usuarios:
        print(f"{u}: limite {u.limite_prestamos()}, "
              f"3 dias tarde = ${u.calcular_multa(3)}")

    # Parte C: Investigador funciona en el mismo ciclo sin tocar otras clases
    print("--- Parte C ---")
    usuarios.append(Investigador("Marta Vega", "1093800003"))
    for u in usuarios:
        print(f"{u}: limite {u.limite_prestamos()}, "
              f"3 dias tarde = ${u.calcular_multa(3)}")

    # Parte D: la interfaz no se puede instanciar
    print("--- Parte D ---")
    try:
        Notificador()
    except TypeError as error:
        print("Error esperado (interfaz):", error)

    class NotificadorIncompleto(Notificador):
        pass          # olvida implementar enviar

    try:
        NotificadorIncompleto()
    except TypeError as error:
        print("Error esperado (sin enviar):", error)

    consola = NotificadorConsola()
    consola.enviar("Camila Ruiz", "Prestamo de Clean Code: devolver el 2026-11-16")

    correo = NotificadorCorreo()
    correo.enviar("Camila Ruiz", "Prestamo de Clean Code: devolver el 2026-11-16")
    print(correo.bandeja_salida)

    # Parte E
    print("--- Parte E ---")
    fisico = LibroFisico("Clean Code", "Robert C. Martin",
                         "978-0132350884", 2, ubicacion="B-12")
    digital = RecursoDigital("Fluent Python", "Luciano Ramalho",
                             "978-1492056355", 5, formato="EPUB")
    bib = Biblioteca("Biblioteca Jorge Roa Martinez", NotificadorConsola())
    bib.agregar_material(fisico)
    bib.agregar_material(digital)

    p1 = bib.prestar(fisico.isbn, usuarios[0])    
    p2 = bib.prestar(digital.isbn, usuarios[2])
    try:
        bib.prestar(fisico.isbn, usuarios[2])  
    except ValueError as error:
        print("Error esperado:", error)

    tarde = p1.fecha_devolucion_esperada + timedelta(days=5)
    print(bib.devolver(p1, tarde))              
    print(bib.devolver(p2))       

    # Cambio de canal sin tocar Biblioteca
    correo = NotificadorCorreo()
    bib2 = Biblioteca("Otra biblioteca", correo)
    bib2.agregar_material(fisico)
    bib2.prestar(fisico.isbn, usuarios[1])
    print(correo.bandeja_salida)

    # Parte F
    print("--- Parte F ---")
    sms = ServicioSMS()
    print(isinstance(sms, Notificador))           
    print(isinstance(sms, CanalNotificacion))    
    bib3 = Biblioteca("Otra", sms)         
    bib3.agregar_material(digital)
    bib3.prestar(digital.isbn, usuarios[0])
    print(sms.enviados)
