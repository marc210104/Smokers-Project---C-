# Smokers-Project---C-
# This project analyzes the connection between smoking and health conditions using public statistical data. The program is written in C++ and offers tools to query, compare and visualize trends among different smoker profiles.


ENGLISH
-------

Description:
This project analyzes the connection between smoking and health conditions using public statistical data. The program is written in C++ and offers tools to query, compare and visualize trends among different smoker profiles.

Components:
- Source code: Proyecto Version final - Alvaro Cuevas & Marc Ortiz.cpp
- Health data: SaludMundial.txt
- European consumption data: EnquestaNacionalEuropea.txt
- Project report: proyecto - pdf.docx

Features:
1. General consultation by diagnosis and year
2. Personal health self-assessment
3. Psychological self-evaluation
4. Percentage comparison of illnesses over time
5. Most common illness by smoker type
6. Trend analysis of specific illnesses
7. Gender comparison by age group in Europe

Structures:
- `FumadorSalud`: diagnosis, condition, year, percentage
- `FumadorNacionalEuropeo`: type, age group, gender, percentage

How to run:
1. Make sure all .txt files are in the same directory as the executable.
2. Compile using g++:
   g++ -o smokers programa.cpp
3. Run the program:
   ./smokers
4. Follow the menu options to navigate.

ESPAÑOL
-------

Descripción:
Este proyecto analiza la relación entre el tabaquismo y la salud pública utilizando datos estadísticos. El programa está escrito en C++ y permite consultar, comparar y visualizar tendencias de salud asociadas a diferentes tipos de fumadores.

Componentes:
- Código fuente: Proyecto Version final - Alvaro Cuevas & Marc Ortiz.cpp
- Datos de salud: SaludMundial.txt
- Datos de consumo en Europa: EnquestaNacionalEuropea.txt
- Documento de memoria: proyecto - pdf.docx

Funcionalidades:
1. Consulta general por diagnóstico y año
2. Autoevaluación personal según tipo de fumador
3. Autoevaluación psicológica
4. Comparación de porcentajes de enfermedades a lo largo del tiempo
5. Enfermedad más común por tipo de fumador
6. Tendencia temporal de enfermedades específicas
7. Comparación de consumo por género y grupo de edad

Estructuras:
- `FumadorSalud`: diagnóstico, condición, año, porcentaje
- `FumadorNacionalEuropeo`: tipo, grupo de edad, sexo, porcentaje

Cómo usarlo:
1. Asegúrate de tener los archivos .txt en el mismo directorio que el ejecutable.
2. Compila el programa con g++:
   g++ -o fumadores programa.cpp
3. Ejecuta el binario:
   ./fumadores
4. Navega por el menú interactivo para realizar consultas.
