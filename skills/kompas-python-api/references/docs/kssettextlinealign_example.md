# ksSetTextLineAlign - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
if (::OpenStamp()) {

::ColumnNumber(2); // 2-справа

::ksSetTextLineAlign(0);

::TextLine(NEW_LINE, 0, 0 , "1111111");

::CloseStamp();

}
