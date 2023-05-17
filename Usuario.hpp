#include <iostream>
#include <cstring>
#ifndef USUARIO_H
#define USUARIO_H
using namespace std;
class Usuario
{
private:
    string contra;
    string nombre;
    string username;
    int edad;

public:
//Constructor
    Usuario(string _nombre, int _edad, string _username, string _contra){
        this->nombre = _nombre;
        this->edad = _edad;
        this->username = _username;
        this->contra = _contra;
    }
//Getters y Setters
    string getNombre(){
        return this->nombre;
    }
    int getEdad(){
        return this->edad;
    }
    string getUser(){
        return this->username;
    }
    string getContra(){
        return this->contra;
    }
    void setNombre(string _nombre){
        this->nombre = _nombre;
    }
    void setEdad(int _edad){
        this->edad = _edad;
    }
    void setUsername(string _username){
        this->username = _username;
    }
    void setContra(string _contra){
        this->contra = _contra;
    }
};

#endif