# FindObj - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
{

reference pLine;

LineSeg(0, 0, 50, 50, 1);

LineSeg(50, 50, 70, 20, 1);

pLine = FindObj(20, 20, 5);

LightObj(pLine, 1);

}
