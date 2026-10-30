# AddUserFuncVariable - Создать переменную (добавить переменную в массив переменных и документ)

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_addvariable.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_addintervalvariable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

LPDISPATCH AddUserFuncVariable( BSTR Name, BSTR Expression );

Синтаксис COM:

HRESULT AddUserFuncVariable( BSTR Name, BSTR Expression, IVariable7 * * Result );

Возвращаемое значение:

| \- указатель на интерфейс параметрической переменной [IVariable7](ivariable7.html)  
---|---  
  
Входные параметры:

Name | \- Имя новой переменной,  
---|---  
Expression | \- Выражение.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
