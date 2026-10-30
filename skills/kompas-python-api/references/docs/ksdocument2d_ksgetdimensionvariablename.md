# ksGetDimensionVariableName - Получить имя параметрической переменной, связанной с размером

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Параметрические переменные ](bt1744101.html) |  Scroll [ [ [ ](ksdocument2d_kssetdocvariablearray.html "К следующему разделу")](bt1744101.html "На уровень выше")](ksdocument2d_ksgetdocvariablearray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetDimensionVariableName](ksgetdimensionvariablename.html).

Синтаксис Automation:

BSTR ksGetDimensionVariableName (long dimObj);

Входной параметр:

dimObj | \- указатель на размер.  
---|---  
  
Возвращаемое значение:

строка с именем переменной | \- если размеру поставлена в соответствие переменная,  
---|---  
пустая строка | \- если размеру не поставлена в соответствие переменная или в случае неудачи.  
  
Подразделы:

(отсутствуют)
