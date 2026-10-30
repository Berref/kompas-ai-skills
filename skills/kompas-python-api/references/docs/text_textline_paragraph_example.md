# Text, TextLine, Paragraph - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Text_Example (void) {

reference p;

// Простой текст

Text (30 , 90, 0, 5, 1, 0, ”Простой текст”);

Text (30 , 80, 0, 5, 1, 0,”Пример... дроби$dЧислитель;Знаменатель$”);

Text (30 , 70, 0, 5, 1, 0, ”Пример... отклонений 20$0.5;-0.3$”);

Text (30 , 60, 0, 5, 1, 0, ”Пример... спецсимвола &32”);

// Структурированный текст

ParagraphParam par;

par.x = 30; par.y = 40; par.ang = 0;

par.hFormat = 0; par.vFormat = 0;

par.height = 25; par.width = 20;

int j=2;

p = Paragraph (&par);

TextLine (NEW_LINE ,0,0 , ”Первая строка”);

//числитель, наклон, высота дроби в 1.5 раза меньше высоты текста

TextLine (NUMERATOR|ITALIC_ON,FRACTION_TYPE ,&j , ”Числитель”);

//знаменатель, утолщение

TextLine (DENOMINATOR|BOLD_ON,0 ,0 , ”Знаменатель”);

//конец дроби, снятие утолщения,снятие наклона

TextLine (END_FRACTION|BOLD_OFF | ITALIC_OFF, 0, 0 , ”4444”);

TextLine (NEW_LINE ,0,0 , ”Вторая строка”);

int tip = 65;

//спецзнак шероховатость

TextLine (SPECIAL_SYMBOL ,SPECIAL, &tip , ”Rz80”);

//конец спецзнака

TextLine (SPECIAL_SYMBOL_END ,0, 0 , ”222”);

EndObj();

}; /* Text_Example */
