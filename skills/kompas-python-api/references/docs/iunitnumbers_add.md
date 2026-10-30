# Add - Создать номер узла

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IUnitNumbers ](iunitnumbers.html) > [IUnitNumbers - методы ](iunitnumbers_methods.html) |  Scroll [ [ [ ](imarknodes.html "К следующему разделу")](iunitnumbers_methods.html "На уровень выше")](iunitnumbers_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunitnumbers.html)

Синтаксис Automation:

LPDISPATH Add( );

Синтаксис COM:

HRESULT Add( IUnitNumber** Result);

Возвращаемое значение:

Result | \- Указатель на интерфейс номера узла [IUnitNumber](iunitnumber.html).  
---|---  
  
Примечание:

Метод позволяет создать новый интерфейс номера узла. После получения нового интерфейса нужно задать параметры номера узла и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
