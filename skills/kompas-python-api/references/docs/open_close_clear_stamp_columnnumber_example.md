# Пример задания штампа

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Stamp_Example (void)

{

if (OpenStamp())

{

ColumnNumber(2);

TextLine (NEW_LINE, 0, 0, 1К11.00.00.021);

ColumnNumber(1);

TextLine (NEW_LINE, 0, 0, Крестовина);

CloseStamp();

}

ClearStamp(2); //очистить вторую графу

};
