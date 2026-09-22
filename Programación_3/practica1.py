class libro:
    def __init__(self,nombre,autor,isbn,categoria):
        self.nombre=nombre
        self.autor=autor
        self.isbn=isbn
        self.categoria=categoria

libro1=libro("100 años de soledad","Gabriel Garcia Marquez","1000826001","Novela")

print(libro1.nombre)
print(libro1.autor)

class estudiante:
    def __init__(self,nombre,apellido,edad,cedula,estudiante):
        self.nombre=nombre
        self.apellido=apellido
        self.edad=edad
        self.cedula=cedula
        self.estudiante=estudiante

estudiante1=estudiante("Camilo","Perez","25","1065478236","si")

print(estudiante1.nombre)
print("Es estudiante activo: ",estudiante1.estudiante)

class prestamo:
    def __init__(self,libro,estudiante,fecha_inicio,fecha_devolucion):
        self.libro=libro
        self.estudiante=estudiante
        self.fecha_inicio=fecha_inicio
        self.fecha_devolucion=fecha_devolucion

prestamo1=prestamo(libro1,estudiante1,"21/09/2026","05/10/2026")

print(prestamo1.estudiante.nombre)
print(prestamo1.libro.nombre)
print("Prestado desde:",prestamo1.fecha_inicio,"hasta",prestamo1.fecha_devolucion)

