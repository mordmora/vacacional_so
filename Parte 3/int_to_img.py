#!/usr/bin/env python3
"""
Script para convertir un archivo de enteros a una imagen.
Formato de entrada:
    filas
    columnas
    p1 p2 p3 ...
    p4 p5 p6 ...
"""

import sys
from PIL import Image

def int_to_image(input_file, output_image):
    """
    Convierte un archivo de enteros a una imagen (escala de grises).
    
    Args:
        input_file: Ruta del archivo de entrada
        output_image: Ruta de la imagen de salida
    """
    with open(input_file, 'r') as f:
        # Leer filas y columnas
        filas = int(f.readline().strip())
        columnas = int(f.readline().strip())
        
        # Leer los píxeles
        pixels = []
        for line in f:
            row_pixels = list(map(int, line.strip().split()))
            pixels.extend(row_pixels)
    
    # Crear la imagen
    img = Image.new('L', (columnas, filas))
    img.putdata(pixels)
    
    # Guardar la imagen
    img.save(output_image)
    
    print(f"Imagen creada exitosamente:")
    print(f"  - Filas: {filas}")
    print(f"  - Columnas: {columnas}")
    print(f"  - Archivo de salida: {output_image}")

def main():
    if len(sys.argv) < 2:
        print("Uso: python int_to_img.py <archivo_entrada> [imagen_salida]")
        print("Ejemplo: python int_to_img.py img.txt foto.png")
        sys.exit(1)
    
    input_file = sys.argv[1]
    
    # Si no se especifica imagen de salida, usar output.png
    if len(sys.argv) >= 3:
        output_image = sys.argv[2]
    else:
        output_image = "output.png"
    
    int_to_image(input_file, output_image)

if __name__ == "__main__":
    main()
