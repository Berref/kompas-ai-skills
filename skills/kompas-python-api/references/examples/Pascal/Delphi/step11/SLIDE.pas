unit slide;

interface

uses
  Windows,SysUtils;

Const


  MIN_COMMAND  = 20000;

  END_SLIDE    =  MIN_COMMAND+1;
  LN           =  MIN_COMMAND+2;   // отрисовать линию
  LS           =  MIN_COMMAND+3;   //тип линии и толщина
  SC           =  MIN_COMMAND+4;   //установить текущий цвет
  MA           =  MIN_COMMAND+5;   //позиционирование в точку
  LA           =  MIN_COMMAND+6;   //отрисовать линию и позиционироваться
  AR           =  MIN_COMMAND+7;   //отрисовать дугу по углам
  AR1          =  MIN_COMMAND+8;   //отрисовать дугу по точкам
  SF           =  MIN_COMMAND+9;   //тип и цвет заполнения
  RT           =  MIN_COMMAND+10;  //рисует прямоугольник
  BR           =  MIN_COMMAND+11;  //рисует и заполняет прямоугольник
  TX           =  MIN_COMMAND+12;  //вывести текст
  TS           =  MIN_COMMAND+13;  //тип текста
  MR           =  MIN_COMMAND+14;  //позиционирование в точку в относительных координатах
  LR           =  MIN_COMMAND+15;  //отрисовать линию в относительных координатах
  CR           =  MIN_COMMAND+16;  //отрисовать окружность
  FF           =  MIN_COMMAND+17;  //заполнить область
  DP           =  MIN_COMMAND+18;  //отрисовать ломанную линию
  FP           =  MIN_COMMAND+19;  //заполнить многоугольник
  EL           =  MIN_COMMAND+20;  //рисует эллипс
  PS           =  MIN_COMMAND+21;  //рисует и заполняет сектор
  BC           =  MIN_COMMAND+22;  //установить цвет фона
  GB           =  MIN_COMMAND+23;  // GB gbX, gbY габариты слайда
  MAX_COMMAND  =  MIN_COMMAND+24;

implementation
end.

