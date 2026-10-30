# AddIntervalVariable - Создать интервальную переменную (добавить переменную в массив переменных и документ)

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument3D1 ](ikompasdocument3d1.html) > [IKompasDocument3D1 - методы ](ikompasdocument3d1_methods.html) |  Scroll [ [ [ ](ikompasdocument3d1_adduserfuncvariable.html "К следующему разделу")](ikompasdocument3d1_methods.html "На уровень выше")](ikompasdocument3d1_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d1.html)

Синтаксис Automation:

LPDISPATCH AddIntervalVariable( BSTR Name, double FirstValue, double SecondValue );

Синтаксис COM:

HRESULT AddIntervalVariable( BSTR Name, double FirstValue, double SecondValue, IVariable7 * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс переменной [IVariable7](ivariable7.html).  
---|---  
  
Входные параметры:

Name | \- Имя новой переменной,  
---|---  
FirstValue | \- первое граничное значение диапазона,  
SecondValue | \- второе граничное значение диапазона.  
  
Примечание:

Для новой переменной можно получить интерфейс интервальной переменной [IIntervalVariable](iintervalvariable.html).

Версия: Компас v20

Подразделы:

(отсутствуют)
