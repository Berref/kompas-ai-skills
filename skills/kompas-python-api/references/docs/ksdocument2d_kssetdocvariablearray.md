# ksSetDocVariableArray - Заменить значения и, если нужно, комментарии у параметрических переменных графического документа или вставки фрагмента

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Параметрические переменные ](bt1744101.html) |  Scroll [ [ [ ](bt1730260.html "К следующему разделу")](bt1744101.html "На уровень выше")](ksdocument2d_ksgetdimensionvariablename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksSetDocVariableArray](kssetdocvariablearray.html).

Синтаксис Automation:

long ksSetDocVariableArray (long obj,

LPDISPATCH arr,

BOOL setNote);

Входные параметры:

obj | \- указатель на документ или вставку фрагмента,  
---|---  
arr | \- указатель на динамический массив [ksDynamicArray](ksdynamicarray.html) параметрических переменных типа VARIABLE_ARR,  
setNote | признак редактирования комментариев: 0 - комментарии не менять, 1 - комментарии менять.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Смотрите также [ksVariable](ksvariable.html)

Подразделы:

(отсутствуют)
