from biblioteca_v3 import (LibroFisico, RecursoDigital, LibroHibrido,
                           Usuario, Prestamo, ComprobantePrestamo)

fisico = LibroFisico("Clean Code", "Robert C. Martin",
                     "978-0132350884", 2, ubicacion="B-12")
digital = RecursoDigital("Fluent Python", "Luciano Ramalho",
                         "978-1492056355", 5, formato="EPUB")
h = LibroHibrido("Python 3 OOP", "Dusty Phillips", "978-1789615852", 3,
                 ubicacion="C-03", formato="PDF")

catalogo = [fisico, digital, h]
u1 = Usuario("Camila Ruiz", "1093812345")

for material in catalogo:
    material.prestar()
    prestamo = Prestamo.registrar_hoy(material, u1)
    print(prestamo)

    comprobante = ComprobantePrestamo(prestamo)
    print(comprobante.libro_titulo)
    