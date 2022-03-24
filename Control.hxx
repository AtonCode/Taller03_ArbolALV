#include "Control.h"
#include <fstream>
#include <ctime>
#include <math.h>
#include <algorithm>

void Control::uploadFile(string fName)
{
    string line;
    ifstream myFile(fName);
    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            this->listaComandosTXT.push_back(line);
        }
    }
    else
    {
        cout << "Fail to open" << endl;
    }
}
void Sistema::fillTree()
{
    if (!this->l.empty())
    {
        int mayor = 0;
        list<string>::iterator it;
        for (it = l.begin(); it != l.end(); it++)
        {
            if ((*it)[0] == 'A' || (*it)[0] == 'a')
            {
                intData = atoi((*it).substr(1, 7).c_str());
                avl.insertar(intData);
            }
            else
            {
                if (!avl.esVacio())
                {
                    avl.valorMax(mayor);
                    avl.eliminar(mayor);
                }
            }
        }
        clock_t end_time = std::clock();
        this->fillInOrderList();
        this->tiempo_arbol = (end_time - init_time) / double(CLOCKS_PER_SEC);
    }
}


    sort(vec.begin(), vec.end());
    list<int>::iterator it = inOrderList.begin();
    set<int>::iterator its = set1.begin();
    deque<int>::iterator itv = vec.begin();
    if (inOrderList.size() == vec.size() && vec.size() == set1.size())
    {

        for (; it != inOrderList.end(); it++, itv++, its++)
        {
            if (*it != *itv && *itv != *its)
                return false;
        }
        return true;
    }
    return false;
}

void Sistema::fillInOrderList()
{
    if (!avl.esVacio())
    {
        avl.inOrdenL(this->inOrderList);
    }
}
list<int> Sistema::getInOrderList()
{
    return this->inOrderList;
}
