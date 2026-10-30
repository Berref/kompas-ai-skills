# Rough - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Rough_Example (void)

{

reference p;

RoughParam roughPar;

memset (&roughPar, 0, sizeof (RoughParam));

//заполним параметры шероховатости

roughPar.rPar.type=0; // без обработки

roughPar.rPar.around=0;

roughPar.rPar.x = 50; roughPar.rPar.y = 50; // опорная точка

roughPar.rPar.ang = 90; // угол наклона оси знака

roughPar.rPar.cText0=1; // строк над знаком

roughPar.rPar.cText1=0; // строк над полкой

roughPar.rPar.cText2=0; // строк под полкой

roughPar.rPar.cText3=0; // строк под полкой

// массив неопределенной длины строк текста

roughPar.rPar.pText =CreateArray (CHAR_STR_ARR, 0);

AddArrayItem (roughPar.rPar.pText, -1, 6,3, 4);

//параметры выносной полки

roughPar.shPar.psh = 0; // полки нет

roughPar.shPar.ang = 130; // угол наклона ножки

roughPar.shPar.length= 20; // длина ножки

p = Rough (&roughPar); // шероховатость

};
