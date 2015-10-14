//
//  main.cpp
//  Proy1Ejercicio1
//
//  Created by Zareek Galvan on 10/7/15.
//  Copyright © 2015 Trisquel Labs. All rights reserved.
//

//Team Members: Armando Galván & Oscar Leal

#include <iostream>
using namespace std;

int arr[500000];
int aux[500000];
long long cont = 0;

void countSwaps (int inicio, int mitad, int fin)
{
    int i = inicio;
    int j = mitad + 1;
    int k = inicio;
    while (i<=mitad && j<=fin)
    {
        if (arr[i] < arr[j])
        {
            aux[k] = arr[i];
            i++;
        }
        else
        {
            aux[k] = arr[j];
            j++;
            cont+= (mitad - i + 1);
        }
        k++;
    }
    if (i>mitad)
    {
        for (int c = k; c <= fin; c++)
        {
            aux[c] = arr[j];
            j++;
        }
    }
    else
    {
        for (int c = k; c <= fin; c++)
        {
            aux[c] = arr[i];
            i++;
        }
    }
    for (int c = inicio; c <= fin; c++)
    {
        arr[c] = aux[c];
    }
}

void merge (int inicio, int fin){
    if (inicio < fin) {
        int mitad = (inicio+fin) / 2;
        merge(inicio, mitad);
        merge(mitad+1, fin);
        countSwaps(inicio, mitad, fin);
    }
}

int main()
{
    while (true)
    {
        int length;
        cin >> length;
        if (length == 0)
        {
            break;
        }
        cont = 0;
        for (int i = 0; i < length; i++){
            cin >> arr[i];
        }
        merge(0,length-1);
        cout << cont << endl;
    }
}