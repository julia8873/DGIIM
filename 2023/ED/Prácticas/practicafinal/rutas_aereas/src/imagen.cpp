
#include "imagen.h"
#include "imagenES.h"

#include <cassert>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/***************************************************************************************************/

void Imagen::Copy(const Imagen & I){
    if(this!=&I){
        Borrar();
        nf=I.nf;
        nc=I.nc;

        // Reservar memoria
        datos=new Pixel*[nf];
        for(int i=0;i<nf;i++){
            datos[i]=new Pixel[nc];
        }

        // Rellenar datos
        for(int i=0;i<nf;i++){
            for(int j=0;j<nc;j++){
                datos[i][j]=I.datos[i][j];
            }
        }
    }
}

/***************************************************************************************************/

void Imagen::Borrar(){
    if(datos!=NULL){
        for(int i=0;i<nf;i++)
            delete[] datos[i];
        delete[] datos;
        datos=NULL;
        nf=0;
        nc=0;
    }
}

/***************************************************************************************************/

Imagen::Imagen(){
    datos=NULL;
    nf=0;
    nc=0;
}

/***************************************************************************************************/

Imagen::Imagen(const Imagen &I){
    Copy(I);
}

/***************************************************************************************************/

Imagen::Imagen(int f,int c){
    nf = f;
    nc = c;
    datos = new Pixel*[nf];
    for (int i=0;i<nf;i++){
        datos[i]=new Pixel[nc];
        for (int j=0;j<nc;j++){
            datos[i][j].r=255;
            datos[i][j].g=255;
            datos[i][j].b=255;
            datos[i][j].transparencia=255;
        }
    }


}

/***************************************************************************************************/

Imagen::~Imagen(){
    Borrar();
}

/***************************************************************************************************/

Imagen & Imagen::operator =(const Imagen & I){
    Copy(I);
    return *this;
}

/***************************************************************************************************/

Pixel & Imagen::operator()(int i,int j){
    assert(i>=0 && i<nf && j>=0 && j<nc);
    return datos[i][j];
}

/***************************************************************************************************/

const Pixel & Imagen::operator()(int i,int j)const{
    assert(i>=0 && i<nf && j>=0 && j<nc);
    return datos[i][j];
}

/***************************************************************************************************/

void Imagen::Escribir(const char * nombre){
    unsigned char * aux = new unsigned char [nf*nc*3];
    unsigned char * m = new unsigned char [nf*nc];

    int total = nf*nc*3;
    for (int i=0;i<total;i+=3){
        int posi = i /(nc*3);
        int posj = (i%(nc*3))/3;

        aux[i]=datos[posi][posj].r;
        aux[i+1]=datos[posi][posj].g;
        aux[i+2]=datos[posi][posj].b;
        m[i/3]=datos[posi][posj].transparencia;

    }

    if (!EscribirImagenPPM (nombre, aux,nf,nc)){
        cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
    }
    delete[]aux;
    string n_aux = "mascara_";
    n_aux =n_aux+nombre;
    size_t found =n_aux.find(".ppm");
    if (found!=string::npos){
        n_aux =n_aux.substr(0,found);
    }
    n_aux =n_aux+".pgm";


    if (!EscribirImagenPGM (n_aux.c_str(), m,nf,nc)){
        cerr<<"Ha habido un problema en la escritura de "<<n_aux<<endl;
    }
    delete []m;

}

/***************************************************************************************************/

void Imagen::Leer(const char * nombre,const string &nombremascara){
    int f,c;
    unsigned char * aux,*aux_mask ;

    LeerTipoImagen(nombre, f, c);
    aux = new unsigned char [f*c*3];

    LeerImagenPPM (nombre, f,c,aux);

    if (nombremascara!=""){
        int fm,cm;
        LeerTipoImagen(nombremascara.c_str(), fm, cm);
        aux_mask = new unsigned char [fm*cm];
        LeerImagenPGM(nombremascara.c_str(), fm,cm,aux_mask);
    }
    else{
        aux_mask=0;
    }

    Imagen I(f,c);
    int total = f*c*3;
    for (int i=0;i<total;i+=3){
        int posi = i /(c*3);
        int posj = (i%(c*3))/3;
        //   cout<<posi<<" " <<posj<<endl;
        I.datos[posi][posj].r=aux[i];
        I.datos[posi][posj].g=aux[i+1];
        I.datos[posi][posj].b=aux[i+2];
        if (aux_mask!=0)
            I.datos[posi][posj].transparencia=aux_mask[i/3];
        else
            I.datos[posi][posj].transparencia=255;
    }

    *this = I;
    if (aux_mask!=0) delete[]aux_mask;
    delete []aux;

}

/***************************************************************************************************/

void Imagen::LimpiarTransp(){
    for(int i=0; i<nf; i++){
        for(int j=0; j<nc; j++){
            datos[i][j].transparencia = 0;
        }
    }
}

/***************************************************************************************************/

void Imagen::PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado){
    //assert(nf>=posi+I.nf && nc>=posj+I.nc);

    for (int i=0;i<I.nf;i++)
        for (int j=0;j<I.nc;j++)
            if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
                if (I.datos[i][j].transparencia!=0){
                    if (tippegado==OPACO)
                        datos[i+posi][j+posj]=I.datos[i][j];
                    else{
                        datos[i+posi][j+posj].r=(datos[i+posi][j+posj].r+I.datos[i][j].r)/2;
                        datos[i+posi][j+posj].g=(datos[i+posi][j+posj].r+I.datos[i][j].g)/2;
                        datos[i+posi][j+posj].b=(datos[i+posi][j+posj].r+I.datos[i][j].b)/2;
                    }

                }
            }

}

/***************************************************************************************************/

Imagen Imagen::ExtraerImagen(int i, int j, int h, int w){
    Imagen tmp(h,w);

    for(int fil=i; fil<i+h; fil++)
        for(int col=j; col<j+w; col++)
            tmp.datos[fil-i][col-j] = datos[fil][col];

    return tmp;
}

/***************************************************************************************************/
