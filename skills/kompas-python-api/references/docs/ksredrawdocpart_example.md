# ksReDrawDocPart - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pView = OpenView ( 0 ); // Системный вид текущего документа

RectParam rect; // Структура параметров прямоугольника

rect.pBot.x = 100; // Инициализация структуры pBot низ - лево

rect.pBot.y = 100; // pTop верх - право

rect.pTop.x = 200;

rect.pTop.y = 200;

ksReDrawDocPart( &rect, pView ); // Будет перерисована область во всех граф. окнах документа
