# MtrForIGES - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double commonArray[2][2]; // матрица 2*2 поворота,

//умноженная предварительно на масштаб

double moveArray[2]; // матрица сдвига умноженная предварительно на масштаб

// заполним матрицы

commonArray[0][0] = 2.0;

commonArray[0][1] = 0.0;

commonArray[1][0] = 0.0;

commonArray[1][1] = -2.0;

moveArray[0] = 20.0; // сдвиг по X

moveArray[1] = 0.0; // сдвиг по Y

LineSeg(0, 0, 10, 10, 1);

//создание матрицы трансформации - симметрия по Х и с масштабом 2 и сдвиг на 10мм

if (::MtrForIGES(commonArray, moveArray)) {

LineSeg(0, 0, 10, 10, 1);

DeleteMtr();

}
