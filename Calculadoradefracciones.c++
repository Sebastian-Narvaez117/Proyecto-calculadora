/**
 * @file Calculadoradefracciones.c++
 * @author Sebastian Narváez
 * @brief Demostrar con un programa de la calculadora de fracciones la Programacion Orientada a Objetos 
 * @version 0.1
 * @date 2024-02-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
using namespace std;

class Fraccion{
private:
    int numerador ;
    int denominador ;
public:
    //Constructor
     Fraccion(int numerador = 1, int denominador = 1){
        //cout << "Constructor con argumentos" << endl;
        this->numerador = numerador;
        this->denominador = denominador;

    } 

    /*Fraccion(){
        cout << "Constructor sin argumentos" << endl;
        this->numerador = 1;
        this->denominador = 1;    
    }

    Fraccion(int numerador, int denominador){
         cout << "Constructor con argumentos" << endl;
        this->numerador = numerador;
        this->denominador = denominador;

    } */

    //Destructor
    ~Fraccion(){
         cout << "Destructor " << endl;

    }


      Fraccion *Multiplicar(Fraccion *operando){
        int numerador = operando->getNumerador() * this->numerador;
        int denominador = operando->getDenominador() * this->denominador;
        return new Fraccion(numerador, denominador);
    }


    Fraccion *Dividir(Fraccion *operando){
        Fraccion *fInv = operando->Invertir();
        Fraccion *rta = Multiplicar(fInv);
        return Multiplicar(rta);
    }

//moquear : hasta que lo desarrollen solo devolvera estos valores para la suma y resta

       Fraccion *Sumar(Fraccion *operando){
          return new Fraccion (8,12);
    }

        Fraccion *Restar(Fraccion *operando){
          return new Fraccion (8,12);
    }
    




    void Inviertete(){
        int auxiliar = this->numerador;
        this->numerador = this->denominador;
        this->denominador = auxiliar;
    }

    Fraccion *Invertir(){
        Fraccion *clonada = new Fraccion(this->numerador, this->denominador);
        clonada->Invertir();
        return clonada;
    }

    void Simplificate(){
        Fraccion *f = this->Simplificar();
        this->numerador = f->getNumerador();
        this->denominador = f->getDenominador();
        f->~Fraccion();
    }




    Fraccion *Simplificar(){
        Fraccion *fraccionCopia = new Fraccion(this->numerador, this->denominador);
        if (fraccionCopia->denominador == 0){
            fraccionCopia->numerador = 0;
             return fraccionCopia;
        }
        int menor = abs(fraccionCopia->numerador);
        if (menor > abs(fraccionCopia->denominador)){
            menor = abs(fraccionCopia->denominador);
        }

        int i = menor;
        while (i >  1){
            if (fraccionCopia->numerador % i == 0 && fraccionCopia->denominador % i ==0){
                fraccionCopia->numerador = fraccionCopia->numerador / i;
                fraccionCopia->denominador = fraccionCopia->denominador / i;
            }else {
                i--;
            }
        }
        return fraccionCopia;
    }


    float aPuntoflotante(){
        return (float)this->numerador / (float)this->denominador;
    }

    //GETTER/SETTER
    int getNumerador(){
        return this->numerador;
    }

    void setNumerador(int numerador){
        this->numerador = numerador ;
    }

    int getDenominador(){
        return this->denominador;
    }

    void setDenominador(int denominador){
        this->denominador = denominador;
    } 

    string toString(){
        return "[" +to_string(this->numerador) + "/" + to_string(this->denominador) + "]";
    }

};


class Calculadoradefracciones{
private:
    Fraccion *operando1 , *operando2;
    char operacion;

    Fraccion *Multiplicar(){
        return this->operando1->Multiplicar(this->operando2);
    }

    Fraccion *Dividir(){
       return this->operando1->Dividir(this->operando2);

    }

    
    Fraccion *Sumar(){
        return this->operando1->Sumar(this->operando2);
    }


     Fraccion *Restar(){
       return this->operando1->Restar(this->operando2);

    }











public:
    Calculadoradefracciones(Fraccion *operando1 = new Fraccion(1,1), Fraccion *oprenado2 = new Fraccion(1,1)){
         this->operando1 = operando1;
         this->operando2 = operando2;
         char operacion = ',' ;
    }


    /* Calculadoradefracciones(Fraccion *operando1 , Fraccion *oprenado2 ){
         this->operando1 = new Fraccion ();
         this->operando2 = new Fraccion ();

    }

     Calculadoradefracciones(){
         this->operando1 = operando1;
         this->operando2 = operando2;

    }*/

    
    ~Calculadoradefracciones();

    Fraccion *Calcular(char operacion){
        this->operacion = operacion;
        Fraccion *rta;
        switch (this->operacion)
        {
        case '+':{
            rta = this->Sumar();
            break;
        }

        case '-':{
            rta = this->Restar();
            break;
        }
        

        case '*':{
            rta = this->Multiplicar();
            break;
        }

        case '/':{
            rta = this->Dividir();
            break;
        }

        default:
            rta = NULL;
            break;
        }

        return rta;
    }



    Fraccion *getOperando1(){
        return this->operando1;
    }

    void setOperando1(Fraccion *Fraccion){
         this->operando1 = Fraccion;
    }

     Fraccion *getOperando2(){
        return this->operando2;
    }

    void setOperando2(Fraccion *Fraccion){
         this->operando2 = Fraccion;
    }

    void *getOperacion(){
        this->operacion;
    }

    string toString(){
        return this->operando1->toString() + " " + this->operacion + " " + this->operando2->toString();

    }


};

/*Calculadoradefracciones::Calculadoradefracciones(){
   
}

Calculadoradefracciones::~Calculadoradefracciones()
{
}*/

Fraccion *IngresarFracciones(string mensaje);
Calculadoradefracciones *construirCalculadoraFraccion();
char elegiroperacion();


int main(int agrc, char const *argv[]){
    system("@cls || clear");
   
    Calculadoradefracciones *cf = construirCalculadoraFraccion();
    char operacion = elegiroperacion();

    Fraccion *rta= cf->Calcular(operacion);
    cout << cf->toString()<< " = ";
    
    cout<<cf->toString() <<" = " << rta->toString() << "====>" << rta->aPuntoflotante() << endl;
    
    rta = cf->Calcular('/');
    cout<<cf->toString() <<" = " << rta->toString() << "====>" << rta->aPuntoflotante() << endl;

    rta = cf->Calcular('^');
    if(rta == NULL){
        cout << "No existe resulatdo para esa operacion" << cf->getOperacion()<< endl;
    }

    return 0;
}

char elegiroperacion(){
    char operacion;
    cout << "Eliga la operacion que desee : [+ , - , * , / ]";
    cin >> operacion;
    return operacion;
}




Calculadoradefracciones *construirCalculadoraFraccion(){
    Fraccion *f1 = IngresarFracciones("Ingrese la fraccion Nro.1");
    Fraccion *f2 = IngresarFracciones("Ingrese la fraccion Nro.2");
    Calculadoradefracciones *cf = new Calculadoradefracciones(f1, f2);
    return cf;
}


Fraccion *IngresarFracciones(string mensaje){
    int num , deno;
    cout<< mensaje << " : " << endl;
    cout << "Numerador :";
    cin >> num;
    cout << "Denominador :";
    cin >> deno;
    return new Fraccion(num, deno);



}

