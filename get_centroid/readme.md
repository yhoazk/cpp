Calcule el centroide geom�trico de la mesh de Suzanne. 
El archivo anexo en la actividad `Monkey.vertex` contiene la siguiente informaci�n binaria as�:

- 1 unsigned long (4byte) con el n�mero de v�rtices almacenados en la secuencia.
- N vectores (16byte) con las coordenada del v�rtice como un arreglo float[4]. (x,y,z,w), w=1.0f siempre.

El programa debe imprimir las coordenadas x,y,z del centroide geom�trico calculado en el GPU.
El CPU abre el archivo, carga los datos y los env�a al GPU para su c�mputo, recolecta el resultado y finalmente lo imprime en pantalla.

Centroide=1/N ?_(i=0)^(N-1)�V_i 
D�nde N: N�mero de v�rtices, Vi: cada v�rtice de Suzanne.

