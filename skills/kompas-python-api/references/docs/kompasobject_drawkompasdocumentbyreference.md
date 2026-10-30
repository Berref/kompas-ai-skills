# ksDrawKompasDocumentByReference - Отрисовать КОМПАС-документ как слайд в присланном окне

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksdrawkompastext.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksdrawkompasdocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksDrawKompasDocumentByReference](ksdrawkompasdocumentbyreference.html).

Синтаксис Automation:

long ksDrawKompasDocumentByReference (long HWindow, long pDoc);

Входной параметр:

Hwindow | \- несущее окно,  
---|---  
pDoc | \- указатель на документ.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если pDoc = 0, отрисовывается текущий документ.

Подразделы:

(отсутствуют)
