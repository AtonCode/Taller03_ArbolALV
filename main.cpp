#include iostream
#include "Control.h"

using namespace std;

int main(int argc, char** argv){
    if (argc == 2)
    {
        string file = argv[1];
        uploadFile(file);

    }
    
}