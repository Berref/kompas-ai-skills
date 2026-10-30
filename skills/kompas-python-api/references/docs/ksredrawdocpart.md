# ksReDrawDocPart - Перерисовать часть графического документа

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Общие функции ](common_docum_fncts.html) |  Scroll [ [ [ ](ksredrawdocpartex.html "К следующему разделу")](common_docum_fncts.html "На уровень выше")](kssheetsetupdlgw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksredrawdocpart_example.html)

Синтаксис:

int ksReDrawDocPart (RectParam * rect, reference pView);

Входные параметры:

rect | [\- указатель на структуру размеров габаритного прямоугольника ](structrectparam.html)[RectParam](structrectparam.html),  
---|---  
pView | \- указатель на вид.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- при выходе из диалога по отмене.  
  
Примечание:

Координаты габаритного прямоугольника определяются в виде pView. Функция перерисовывает часть вида во всех графических окнах документа, которому принадлежит данный вид.

Подразделы:

(отсутствуют)
