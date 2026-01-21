#!/usr/bin/env python3
"""
Script para convertir una imagen a un archivo de enteros.
Formato de salida:
    filas
    columnas
    p1 p2 p3 ...
    p4 p5 p6 ...
"""

import sys
from PIL import Image

def image_to_int(input_image, output_file):
    """
    Convierte una imagen a un archivo de enteros (escala de grises).
    
    Args:
        input_image: Ruta de la imagen de entrada
        output_file: Ruta del archivo de salida
    """
    # Abrir la imagen y convertirla a escala de grises
    img = Image.open(input_image).convert('L')
    
    # Obtener dimensiones
    width, height = img.size
    filas = height
    columnas = width
    
    # Obtener los píxeles como una lista
    pixels = list(img.getdata())
    
    # Escribir al archivo
    with open(output_file, 'w') as f:
        # Escribir filas
        f.write(f"{filas}\n")
        # Escribir columnas
        f.write(f"{columnas}\n")
        
        # Escribir los píxeles fila por fila
        for i in range(filas):
            row_start = i * columnas
            row_end = row_start + columnas
            row_pixels = pixels[row_start:row_end]
            f.write(' '.join(map(str, row_pixels)) + '\n')
    
    print(f"Imagen convertida exitosamente:")
    print(f"  - Filas: {filas}")
    print(f"  - Columnas: {columnas}")
    print(f"  - Archivo de salida: {output_file}")

def main():
    if len(sys.argv) < 2:
        print("Uso: python img_to_int.py <imagen_entrada> [archivo_salida]")
        print("Ejemplo: python img_to_int.py foto.png img.txt")
        sys.exit(1)
    
    input_image = sys.argv[1]
    
    # Si no se especifica archivo de salida, usar img.txt
    if len(sys.argv) >= 3:
        output_file = sys.argv[2]
    else:
        output_file = "img.txt"
    
    image_to_int(input_image, output_file)

if __name__ == "__main__":
    main()
