# ksDrawKompasDocument - Отрисовать документ системы КОМПАС как слайд в присланном окне

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_drawkompasdocumentbyreference.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksdrawbitmapex2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksDrawKompasDocument](ksdrawkompasdocument.html).

Синтаксис Automation:

long ksDrawKompasDocument (long HWindow,

BSTR docFileName);

Входные параметры:

Hwindow | \- несущее окно,  
---|---  
docFileName | \- полное имя файла документа.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Действие метода распространяется также на фрагменты и модели из библиотек. При этом имя файла должно иметь вид "c:\gr\lib1.l3d|детали|литье|фланец",

где

•c:\gr\lib1.l3d - имя файла библиотеки,

•|детали|литье| - разделы, подразделы внутри библиотеки,

•фланец - имя фрагмента или модели.

Подразделы:

(отсутствуют)
