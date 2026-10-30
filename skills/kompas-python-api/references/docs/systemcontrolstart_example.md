# SystemControlStart - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void SystemControlStart_Example (void)

{

//построить заштрихованный квадрат

LineSeg (20, 30, 70, 30, 1);

LineSeg (70, 30, 70, 80, 1);

LineSeg (70, 80, 20, 80, 1);

LineSeg (20, 80, 20, 30, 1);

//штриховка появится только после возвращения управления библиотеке

SystemControlStart (0);

reference p = Hatch(0, 45, 2, 0, 0, 0);

LineSeg (20, 30, 70, 30, 1);

LineSeg (70, 30, 70, 80, 1);

LineSeg (70, 80, 20, 80, 1);

LineSeg (20, 80, 20, 30, 1);

EndObj();

};
