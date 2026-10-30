# AddIntervalVariable - Создать интервальную переменную (добавить переменную в массив переменных и документ)

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_adduserfuncvariable.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

LPDISPATCH AddIntervalVariable( BSTR Name, double FirstValue, double SecondValue );

Синтаксис COM:

HRESULT AddIntervalVariable( BSTR Name, double FirstValue, double SecondValue, IVariable7 * * Result );

Возвращаемое значение:

| \- указатель на интерфейс параметрической переменной [IVariable7](ivariable7.html).  
---|---  
  
Входные параметры:

Name | \- Имя новой переменной,  
---|---  
FirstValue | \- Первое значение диапазона,  
SecondValue | \- Второе значение диапазона.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
