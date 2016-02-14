/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Faça uma função chamada filtroConvolucao (protótipo livre) que deve receber como
 * parâmetros uma matriz correspondente a uma imagem original, um matriz correspon-
 * dente a um kernel, e um ponteiro duplo para uma matriz que receberá o resultado da
 * filtragem: a imagem filtrada.
 * A função deverá alocar dinamicamente a imagem filtrada e não deve permitir que a
 * função altere os valores da imagem original nem do kernel (use o qualificador const).
 * Para tanto assuma as seguintes simplificações: uma imagem é representada como uma
 * matriz n × m, na qual cada posição da matriz representa a intensidade de cinza de um
 * pixel variando na faixa [0; 255], para qual 0 representa a cor preta e 255 representa
 * a cor branca; um kernel pode ser representado por uma matriz quadrada de valores reais.
 * A imagem original deve ser passada como um ponteiro simples (use const). Por-
 * tanto lembre-se de especificar o número de linhas e colunas da imagem original. A
 * função deverá retornar um ponteiro nulo, caso a alocação dinâmica falhe, ou o endereço
 * da memória alocada para a image filtrada, caso contrário. Mas o mais importante é
 * que a image filtrada deve ser retornada como um parâmetro da função, utilizando-se
 * ponteiros duplos. O seu tamanho (linhas e colunas) também deve ser retornado via
 * parâmetros (passagem por referência).
 */

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::bad_alloc;

// Prototypes
void convolution_filter(const double *kernel, const double *Ii, int h, int w, double **Io, int *ho, int *wo);

int main(int argc, char const *argv[]) {
    // Create low_pass kernel
    double low_pass[3][3] = {{1/9.0, 1/9.0, 1/9.0}, {1/9.0, 1/9.0, 1/9.0}, {1/9.0, 1/9.0, 1/9.0}};
    // Create high_pass kernel
    double high_pass[3][3] = {{-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1}};
    // Create laplacian kernel
    double laplacian[3][3] = {{1, -2, 1}, {-2, 5, -2}, {1, -2, 1}};
    // Create example image
    double img1[3][3] = {{0, 0, 0}, {255, 255, 255}, {0, 0, 0}};
    // Create new image var
    double *img2;
    // Create size vars
    int h = 3, w = 3, ho, wo;

    // Print original image
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cout << img1[i][j] << (j == w - 1 ? "\n" : " ");
    cout << endl;

    // Low Pass
    cout << "Low Pass" << endl;
    convolution_filter(*low_pass, *img1, h, w, &img2, &ho, &wo);
    for (int i = 0; i < ho; i++)
        for (int j = 0; j < wo; j++)
            cout << *(img2+i*w+j) << (j == w - 1 ? "\n" : " ");
    cout << endl;
    delete[] img2;

    // High Pass
    cout << "High Pass" << endl;
    convolution_filter(*high_pass, *img1, h, w, &img2, &ho, &wo);
    for (int i = 0; i < ho; i++)
        for (int j = 0; j < wo; j++)
            cout << *(img2+i*w+j) << (j == w - 1 ? "\n" : " ");
    cout << endl;
    delete[] img2;

    // Laplacian
    cout << "Laplacian" << endl;
    convolution_filter(*laplacian, *img1, h, w, &img2, &ho, &wo);
    for (int i = 0; i < ho; i++)
        for (int j = 0; j < wo; j++)
            cout << *(img2+i*w+j) << (j == w - 1 ? "\n" : " ");
    cout << endl;
    delete[] img2;

    return EXIT_SUCCESS;
}

void convolution_filter(const double *kernel, const double *Ii, int h, int w, double **Io, int *ho, int *wo) {
    try {
        *Io = new double[h*w];
    }catch (const bad_alloc & e) {
        cerr << "[convolution_filter()]: bad_alloc caught:" << e.what() << "\n";
        Io = nullptr, *ho = 0, *wo = 0;
        return;
    }

    // Set new image size
    *ho = h - 2, *wo = w - 2;

    for (int i = 1; i < h-1; i++) {
        for (int j = 1; j < w-1; j++) {
            // Set new image using kernel
            *(*Io+(i-1)*w+j-1) = *(Ii+(i-1)*w+j-1) * (*(kernel)) +
                                 *(Ii+(i-1)*w+j) * (*(kernel+1)) +
                                 *(Ii+(i-1)*w+j+1) * (*(kernel+2)) +
                                 *(Ii+i*w+j-1) * (*(kernel+3)) +
                                 *(Ii+i*w+j) * (*(kernel+4)) +
                                 *(Ii+i*w+j+1) * (*(kernel+5)) +
                                 *(Ii+(i+1)*w+j-1) * (*(kernel+6)) +
                                 *(Ii+(i+1)*w+j) * (*(kernel+7)) +
                                 *(Ii+(i+1)*w+j+1) * (*(kernel+8));
            // Limits [0, 255] verification
            *(*Io+(i-1)*w+j-1) = *(*Io+(i-1)*w+j-1) > 255 ? 255 : *(*Io+(i-1)*w+j-1) < 0 ? 0 : *(*Io+(i-1)*w+j-1);
        }
    }
}
