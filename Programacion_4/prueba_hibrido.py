from biblioteca_v3 import LibroHibrido

h = LibroHibrido("Python 3 OOP", "Dusty Phillips", "978-1789615852", 3,
                 ubicacion="C-03", formato="PDF")

print(h)
print(h.dias_prestamo())
print([c.__name__ for c in LibroHibrido.__mro__])
print(repr(h))
