#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
  // zmienne
  FILE * pFile;                 //zmienna przechowująca uchwyt do pliku
  int tab[10];                  //tabela wczytywanych danych
  int mat[10][10];              //macierz przechowująca wykres
  int buff;                     //bufor
  short k=0;                    // licznik
  ifstream input("dane.dat");   //otwarcie pliku

  if (input.is_open()){         // sprawdzenie, czy otwarto plik
      while (input>>buff) {     //import danych
      tab[k]=(int)buff;
      //cout<<buff;
      k++;
      }
    } else perror ("Error opening file");

    for (size_t i = 0; i < 10; i++){
      cout << tab[i]<<" ";              //wyświetlenie pobranych danych w konsoli
    }

   pFile = fopen ("index.html","w");      //otwarcie pliku .html
    if (pFile!=NULL)                      //warunek czy otwarty
    {
      //generacja zawartości strony index.html
       fwrite ("<html>\n<head>", sizeof(char), sizeof("<html>\n<head>"), pFile);

          fwrite ("<meta charset=\"utf-8\">", sizeof(char), sizeof("<meta charset=\"utf-8\">"), pFile);
          fwrite ("\n<style type=\"text/css\">\ntable, th, td\n{\nborder-collapse:collapse;\nborder:1px solid black;}",
            sizeof(char), sizeof("<style type=\"text/css\">\ntable, th, td\n{\nborder-collapse:collapse;\nborder:1px solid black;}"), pFile);
          fwrite ("\ntd.data\n{padding: 15px;}", sizeof(char), sizeof("td.data\n{padding: 15px;}"), pFile);
          fwrite ("\ntd.bp1\n{padding: 10px;\nborder: 1px solid white;\nheight: 20px;\nbackground-color : red;}", sizeof(char),
           sizeof("td.bp1\n{padding: 10px;\nborder: 1px solid white;\nheight: 20px;\nbackground-color : red;}"), pFile);
          fwrite ("\ntd.bp0\n{padding: 10px;\nborder: 1px solid white;\nheight: 20px;\nbackground-color: white;}", sizeof(char),
           sizeof("td.bp0\n{padding: 10px;\nborder: 1px solid white;\nheight: 20px;\nbackground-color: white;}"), pFile);
          fwrite ("</style>", sizeof(char), sizeof("</style>"), pFile);
          fwrite ("</head>\n<body>", sizeof(char), sizeof("</head>\n<body>"), pFile);
          fwrite ("<h2 style=\"text-align:center;\">", sizeof(char), sizeof("<h2 style=\"text-align:center;\">"), pFile);
          fwrite ("TECHNOLOGIE INTERNETOWE W INFOSYSTEMACH</h2>", sizeof(char), sizeof("TECHNOLOGIE INTERNETOWE W INFOSYSTEMACH</h2>"), pFile);
          fwrite ("</br></br>", sizeof(char), sizeof("</br></br>"), pFile);
          fwrite ("<h2 style=\"text-align:center;\">Ćwiczenie 1</h2>", sizeof(char), sizeof("<h2 style=\"text-align:center;\">ćwiczenie 1</h2>"), pFile);
          fwrite ("</br></br>", sizeof(char), sizeof("</br></br>"), pFile);
          fwrite ("<p>Autor: BARTŁOMIEJ HORISZNY</p>", sizeof(char), sizeof("<p>Autor: BARTŁOMIEJ HORISZNY</p>"), pFile);
          fwrite ("</br></br>", sizeof(char), sizeof("</br></br>"), pFile);
       fwrite ("</body>\n</html>", sizeof(char), sizeof("</body>\n</html>"), pFile);
          fwrite ("<table >\n<th>Dane w tabeli</th>\n<tr>", sizeof(char), sizeof("<table >\n<th>Dane w tabeli</th>\n<tr>"), pFile);
          fwrite ("<td>Numer próbki:</td>", sizeof(char), sizeof("<td>Numer próbki:</td>"), pFile);
            for (size_t i = 1; i < 11; i++) {
              fprintf(pFile, "<td class=\"data\">%d</td>", i);                  // numerowanie próbek w tabeli
            }
          fwrite ("</tr>\n<tr>\n<td>Wartość:</td>", sizeof(char), sizeof("</tr>\n<tr>\n<td>Wartość:</td>"), pFile);
            for (size_t i = 0; i < 10; i++) {
            fprintf(pFile, "<td class=\"data\">%d</td>", tab[i]);               // wpiswywanie próbek do tabeli
            }
          fwrite ("</tr>\n</table>", sizeof(char), sizeof("</tr>\n</table>"), pFile);

          for (int i=0;i<10;i++){                 //i rzędy           tworzenie zerowej macierzy
              for (int j=0;j<10;j++)              //j kolumny
                mat[i][j]=0;
          }
          for (size_t licz = 0; licz <10; licz++) {
              buff=tab[licz];
            //  cout<<buff;
              for (size_t j = 0; j < 10; j++) {
                for (size_t i = 10; i > (10-buff); i--) {
                    mat[i-1][licz]=1;                         // tworzenie macierzy 0-1 zaleznej od wartości próbek
                }
              }
            }
          fwrite ("</br></br>", sizeof(char), sizeof("</br></br>"), pFile);
          fwrite ("Diagram słupkowy\n<table>", sizeof(char), sizeof("Diagram słupkowy\n<table>"), pFile);
          for (size_t i = 0; i < 10; i++) {
              fwrite ("<tr>", sizeof(char), sizeof("<tr>"), pFile);             // rysowanie diagramu słupkowego
              for (size_t j = 0; j < 10; j++) {
                if (mat[i][j]==1) {
                  fwrite ("<td class=\"bp1\"></td>", sizeof(char), sizeof("<td class=\"bp1\"></td>"), pFile);
                } else fwrite ("<td class=\"bp0\"></td>", sizeof(char), sizeof("<td class=\"bp0\"></td>"), pFile);
              }
              fwrite ("<tr>", sizeof(char), sizeof("<tr>"), pFile);
          }
       fwrite ("</body>\n</html>", sizeof(char), sizeof("</body>\n</html>"), pFile);
      fclose (pFile);
    } else perror ("Error opening file");

      cout<<"\n\nElements of matrix 1 are: \n";                                     // wyświetlenie macierzy
      for (int i=0;i<10;i++){
        cout<<endl;
        for (int j=0;j<10;j++)
        cout<<mat[i][j]<<" ";
        }
  return 0;
}
