# CloseDocument - Закрыть документ (чертеж, фрагмент, спецификацию, текстовый документ, деталь, сборку)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Общие функции ](common_docum_fncts.html) |  Scroll [ [ [ ](savedocument.html "К следующему разделу")](common_docum_fncts.html "На уровень выше")](opendocumentw.html "К предыдущему разделу")  
---|---  
  
[Пример...](create_open_close_save_document.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCloseDocument](ksdocument2d_ksclosedocument.html).

Синтаксис:

int CloseDocument (reference sheet);

Входные параметры:

sheet | \- указатель на закрываемый документ.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Если sheet = 0, закрывается текущий документ.

2\. Если документ не сохранен, взводится флаг соответствующей ошибки.

Подразделы:

(отсутствуют)
