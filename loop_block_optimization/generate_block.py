#!/usr/env/bin python

import numpy as np

def generate_matrix(name):
    one = np.ones((50,50))
    for x in np.nditer(one, op_flags=['readwrite']):
        x[...] = np.random.randint(10)

    with open(name+".h", "w") as mat_a:
        mat_a.write("unsigned int "+ name +"[] = {\n")
        for i in np.nditer(one):
            mat_a.write(str(i) + ",")
        mat_a.write("};")
        mat_a.close()




if __name__ == '__main__':
    generate_matrix("matrix_a")
    generate_matrix("matrix_b")
