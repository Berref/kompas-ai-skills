# SetControlExpression - Установить выражение в контрол

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IProcessWithVariables ](iprocesswithvariables.html) > [IProcessWithVariables - методы ](iprocesswithvariables_methods.html) |  Scroll [ [ [ ](iprocesswithvariables_updateexpressionscontrols.html "К следующему разделу")](iprocesswithvariables_methods.html "На уровень выше")](iprocesswithvariables_getcontrolvariablename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocesswithvariables.html)

Синтаксис Automation:

BOOL SetControlExpression( IPropertyControl * Control, BSTR VariableName, BSTR Expression );

Синтаксис COM:

HRESULT SetControlExpression( IPropertyControl * Control, BSTR VariableName, BSTR Expression, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Control | \- Указатель на интерфейс [IPropertyControl](ipropertycontrol.html),  
---|---  
VariableName | \- Имя переменной,  
Expression | \- Выражение.  
  
Подразделы:

(отсутствуют)
