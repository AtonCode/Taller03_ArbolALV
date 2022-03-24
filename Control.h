#ifndef __CONTROL__H__
#define __CONTROL__H__

#include <string>
#include <list>
#include "ArbolAVL.h"

using namespace std;


class Control{

    private:
        ArbolAVL<int> avl;
        list<string> listaComandosTXT;
        list<int> inOrderList;
        list<int> PreOrderList;
        int intData;
    public:
        void uploadFile(string fileName);
        void loadTreeAVL(int inData);
        void fillInOrderList();
        list<int>  getInOrderList();
};


#include "Control.hxx"
#endif