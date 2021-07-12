#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int RobotCoinCollection(std::vector<std::vector<int>>& C){

    int n, m;

    n = C.size();
    m = C[0].size();

    int F[n][m];

    F[0][0] = C[0][0];
    F[1][1] = C[1][1];

    int ii, jj;

    for(jj=2; jj<=m-1; jj++){
        F[1][jj] = F[1][jj-1] + C[1][jj];
    }

    for(ii=2; ii<=n-1; ii++){
        F[ii][1] = F[ii-1][1] + C[ii][0];

            for(jj=2; jj<=m-1; jj++){
                F[ii][jj] = max(F[ii-1][jj], F[ii][jj-1]) + C[ii][jj];
            }
    }

    return F[n][m];

}

int main(){
    cout << "Lista 06 - Questao 01 - Letra e" << endl;

    /*std::vector<std::vector<int>> C({{0, 0, 0, 0, 1, 0},
                                     {0, 1, 0, 1, 0, 0},
                                     {0, 0, 0, 1, 0, 1},
                                     {0, 0, 1, 0, 0, 1},
                                     {1, 0, 0, 0, 1, 0}}); */

    std::vector<std::vector<int>> C({ {0, 1, 2},
                                      {0, 1, 1},
                                      {0, 0, 1}});

    cout << "Numero de moedas coletadas: " << RobotCoinCollection(C) << endl;

}

