# Table - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Table_Example (void)

{

reference p;

p = Table ();

LineSeg(50, 50, 90, 50, 1);

LineSeg(50, 40, 90, 40, 1);

LineSeg(50, 30, 90, 30, 1);

LineSeg(50, 50, 50, 30, 1);

LineSeg(70, 50, 70, 30, 1);

LineSeg(90, 50, 90, 30, 1);

Text(52, 48, 0, 5, 1,0, Простой текст); //первая ячейка по точке привязки

ParagraphParam par;

par.x = 72; par.y = 48; //вторая ячейка

par.ang = 0; par.hToleranceat = 0; par.vToleranceat = 0;

par.height = 20; //высота блока форматирования

par.width = 20; //ширина блока форматирования

Paragraph (&par);

int j=2;

TextLine (NEW_LINE, 0, 0, Сложный);

TextLine (NEW_LINE|BOLD_ON, 0, 0, структурированный);

TextLine (NEW_LINE|BOLD_OFF | ITALIC_ON, 0, 0, текст);

EndObj();

EndObj();

};
