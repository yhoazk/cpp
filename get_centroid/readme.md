Calcule el centroide geometrico de la mesh de Suzanne. 
El archivo anexo en la actividad `Monkey.vertex` contiene la siguiente informacion binaria asi:

- 1 unsigned long (4byte) con el numero de vertices almacenados en la secuencia.
- N vectores (16byte) con las coordenada del vertice como un arreglo float[4]. (x,y,z,w), w=1.0f siempre.

El programa debe imprimir las coordenadas x,y,z del centroide geometrico calculado en el GPU.
El CPU abre el archivo, carga los datos y los envia al GPU para su computo, recolecta el resultado y finalmente lo imprime en pantalla.

Centroide=1/N ?_(i=0)^(N-1)�V_i 
Donde N: Numero de vertices, Vi: cada vertice de Suzanne.

