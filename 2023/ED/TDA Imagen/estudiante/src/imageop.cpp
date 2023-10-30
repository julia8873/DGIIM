/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>

#include <cassert>


void Image::Invert(){
    for (int i=0; i<size(); i++)
        set_pixel(i,255-get_pixel(i));
}

void Image::AdjustContrast (byte in1, byte in2, byte out1, byte out2){
    double cte = (out2 - out1) / (in2-in1);

    double valor;

    for(int k=0; k<get_rows() * get_cols(); k++){
        valor = out1 + (cte)*(get_pixel(k) - in1);
        set_pixel(k, round(valor));
    }

}

double Image::Mean(int i, int j, int height, int width) const{

    double suma = 0;

    if(height != 0 and width != 0) {
        for (int fil = i; fil < i + width; fil++)
            for (int col = j; col < j + height; col++)
                suma += get_pixel(fil, col);
        suma /= (width * height);
    }

    return suma;
}

Image Image::Subsample(int factor) const{
    int nrows = floor(rows/factor);
    int ncols = floor(cols/factor);
    Image tmp(nrows, ncols);

    byte value;

    // Iteramos por imagen final
    for(int i = 0; i<nrows; i++){
        for(int j=0; j<ncols; j++){
            value = round(Mean(i*factor, j*factor, factor, factor));
            tmp.set_pixel(i,j,value);
        }
    }

    return tmp;
}

Image Image::Crop(int nrow, int ncol, int height, int width) const{
    Image tmp(height, width);

    for(int i=0; i<height;i++)
        for(int j=0; j<width; j++)
            tmp.set_pixel(i, j, get_pixel(i+nrow, j+ncol));

    return tmp;
}

Image Image::Zoom2X() const{
    int dim = get_rows()*2-1;
    Image tmp(dim, dim);

    // Guardamos los píxeles originales
    int col = get_cols();
    for(int i=0; i<get_rows()*col; i++){
        // Nota: se guardan en los pares y cada vez que se llega al final de la columna,
        //       se tiene que sumar una fila extra de longitud col
        tmp.set_pixel(i*2+(dim-1)*(i/col), get_pixel(i));
    }

    // Recorremos los índices impares
    //  (habrá que interpolar por filas o columnas)
    int i = 1;
    byte value;
    bool por_col;

    while(i < dim*dim){
        if((i/dim) % 2 == 0) por_col = true;  // Interpolamos por columnas
        else por_col = false;                 // Interpolamos por filas

        // Calculamos las respectivas medias (con elementos contiguos o encima y debajo)
        if(por_col)
            value = round((static_cast<double>(tmp.get_pixel(i-1))+static_cast<double>(tmp.get_pixel(i+1)))/2);
        else
            value = round((static_cast<double>(tmp.get_pixel(i-dim) )+static_cast<double>(tmp.get_pixel(i+dim)))/2);

        tmp.set_pixel(i, value);
        i+=2;
    }

    // Interpolamos los índices pares que no se hayan añadido previamente
    i = dim + 1;

    while (i < dim*dim){
        value = round((static_cast<double>(tmp.get_pixel(i-1-dim)) +
                static_cast<double>(tmp.get_pixel(i+1-dim)) +
                static_cast<double>(tmp.get_pixel(i-1+dim)) +
                static_cast<double>(tmp.get_pixel(i+1+dim))
                )/4);

        tmp.set_pixel(i, value);
        if(((i+2) % dim) == 0) i += (dim + 3); // si estamos en el valor "extremo"
        else i+=2;
    }

    return tmp;
}

void Image::ShuffleRows(){

}

bool Image::Iguales(Image &otro) const{

    bool iguales = true;

    if(otro.get_rows() != get_rows() || otro.get_cols() != get_cols())
        iguales = false;
    else{
        int i = 0;
        while((i<get_rows()*get_cols()-1) and iguales){
            if(otro.get_pixel(i) != get_pixel(i)) iguales = false;
            i++;
        }

    }

    return iguales;

}
