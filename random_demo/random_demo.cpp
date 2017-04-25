/*
 * Demo for the random library.
 * */
#include <iostream>
#include <random>
#include <string>

using namespace std;



string py_sha = "#!/usr/bin/env python\n\nimport matplotlib.pyplot as plt\n";
string py_bdy = "plt.hist(data)\nplt.show()\n";
/* Generate a random generator  */
default_random_engine def_eng;

normal_distribution<double> uniform_dist(0.0,1.0);



int main(int argc, char* argv[])
{
    int no_samples;
    //cout << "test:" << argc << endl;

    //cout << "argv[1]:" << argv[1] << endl;
    cin >> no_samples;
    //cout << no_samples << endl;
    cout << py_sha;
    cout << "data = [ " ;
    while(no_samples--)
    {
        cout << uniform_dist(def_eng);
        if(no_samples > 0)
            cout << ", ";
    }
    cout << "] " << endl;
    cout << py_bdy;
    return 0;
}

