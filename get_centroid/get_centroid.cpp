#include <iostream>
#include <fstream>



struct vertex
{
    float x,y,z,w;
};

/**
 * Function to get the centroid of an array of vertex.
 * The formula to get the centroid is:
 *  C = (1/n) *( sum(vertex))
 */

vertex get_centroid(vertex* pVertex, size_t vertex_count )
{
    vertex sum = {0,0,0,0};
    for(unsigned int i = 0; i<vertex_count; i++)
    {
        sum.x += pVertex[i].x;
        sum.y += pVertex[i].y;
        sum.z += pVertex[i].z;
        sum.w += pVertex[i].w;
    }
    sum.x /=(float) vertex_count;
    sum.y /=(float) vertex_count;
    sum.z /=(float) vertex_count;
    sum.w /=(float) vertex_count;
    return(sum);
}



int main (void)
{
    std::   ifstream monkey("Monkey.vertex", std::ios::binary | std::ios::in);
    if(!(monkey.is_open()))
    {
        std::cout << "Error: Unable to open the Monkey file" << std::endl;
        exit(1);
    }
    
    uint32_t vertex_count = 0;
    monkey.read((char*)&vertex_count, sizeof(unsigned int32_t));
    vertex* pVertex = new vertex[vertex_count];

    monkey.read((char*)pVertex, vertex_count * sizeof(vertex));
    // http://en.cppreference.com/w/cpp/io/manip <- print in hex reference
    std::cout << "Vertex Count read: " << std::hex << "0x" << vertex_count << std::endl;
    vertex centroid = get_centroid(pVertex, vertex_count);
    std::cout << "Monkey centroid: " << centroid.x << ", " << centroid.y << ", " << centroid.z << ", " << centroid.w << std::endl;

    delete[] pVertex;
    return 0;
}



