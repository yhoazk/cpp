Calcule el centroide geométrico de la mesh de Suzanne. 
El archivo anexo en la actividad `Monkey.vertex` contiene la siguiente información binaria así:

- 1 unsigned long (4byte) con el número de vértices almacenados en la secuencia.
- N vectores (16byte) con las coordenada del vértice como un arreglo float[4]. (x,y,z,w), w=1.0f siempre.

El programa debe imprimir las coordenadas x,y,z del centroide geométrico calculado en el GPU.
El CPU abre el archivo, carga los datos y los envía al GPU para su cómputo, recolecta el resultado y finalmente lo imprime en pantalla.

Centroide=1/N ?_(i=0)^(N-1)¦V_i 
Dónde N: Número de vértices, Vi: cada vértice de Suzanne.

