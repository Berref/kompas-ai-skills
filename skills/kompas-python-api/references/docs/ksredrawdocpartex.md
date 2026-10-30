# ksReDrawDocPartEx - Перерисовка части 2D документа (Листа)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Общие функции ](common_docum_fncts.html) |  Scroll [ [ [ ](print_docum_fncts.html "К следующему разделу")](common_docum_fncts.html "На уровень выше")](ksredrawdocpart.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int LIB_FUNC ksReDrawDocPart (RectParam * rect, reference pView, int ParamType);

Входные параметры:

rect | \- указатель на структуру размеров габаритного прямоугольника [RectParam](structrectparam.html),  
---|---  
pView | \- указатель на вид,  
ParamType | \- признак использования системы координат.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Если ParamType == 0, то используются координаты в системе координат текущей СК вида.

2\. Если ParamType == VIEV_ALLPARAM, то используются координаты в системе координат вида.

3\. Если ParamType == SHEET_ALLPARAM, то используются координаты в системе координат чертежа.

Подразделы:

(отсутствуют)
