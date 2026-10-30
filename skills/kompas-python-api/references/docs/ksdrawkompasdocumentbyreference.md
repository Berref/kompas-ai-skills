# ksDrawKompasDocumentByReference - Отрисовать КОМПАС-документ как слайд в присланном окне

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Общие функции ](common_docum_fncts.html) |  Scroll [ [ [ ](ksgetdocumenttypebyname.html "К следующему разделу")](common_docum_fncts.html "На уровень выше")](ksgetdocumenttype.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::DrawKompasDocumentByReference](kompasobject_drawkompasdocumentbyreference.html).

Синтаксис:

int ksDrawKompasDocumentByReference (void *HWindow, reference pDoc);

Входные параметры:

Hwindow | \- несущее окно,  
---|---  
pDoc | \- указатель на документ.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель pdoc = 0, отрисовывается текущий документ.

Подразделы:

(отсутствуют)
