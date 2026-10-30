# IsVariableNameValid - Проверить допустимость создания новой переменной с данным именем

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_moveobjects.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_findobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL IsVariableNameValid( BSTR Name );

Синтаксис COM:

HRESULT IsVariableNameValid( BSTR Name, BOOL * Result );

Входные параметры:

Name | \- имя переменной.  
---|---  
  
Возвращаемое значение:

TRUE | \- переменную с данным именем создать можно,  
---|---  
FALSE | \- переменную с данным именем создать нельзя.  
  
Метод позволяет проверить, можно ли создать переменную с данным именем (проверяются синтаксис имени и наличие в документе переменной с данным именем).

Подразделы:

(отсутствуют)
