# AddVariable - Создать переменную

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_beginedit.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

LPDISPATCH AddVariable( BSTR Name, double Value, BSTR Note );

Синтаксис COM:

HRESULT AddVariable( BSTR Name, double Value, BSTR Note, IVariable7 ** Result );

Входные параметры:

Name | \- имя переменной,  
---|---  
Value | \- значение переменной,  
Note | \- примечание.  
  
Возвращаемое значение:

\- указатель на интерфейс переменной [IVariable7](ivariable7.html).  
---  
  
Метод позволяет добавить переменную в массив переменных и документ.

Подразделы:

(отсутствуют)
