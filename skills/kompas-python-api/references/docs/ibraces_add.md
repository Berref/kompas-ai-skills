# Add - Создать фигурную скобку

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IBraces ](ibraces.html) > [IBraces - методы ](ibraces_methods.html) |  Scroll [ [ [ ](ibuildingaxes.html "К следующему разделу")](ibraces_methods.html "На уровень выше")](ibraces_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibraces.html)

Синтаксис Automation:

LPDISPATH Add( );

Синтаксис COM:

HRESULT Add( IBrace** Result);

Возвращаемое значение:

Result | \- Указатель на интерфейс фигурной скобки [IBrace](ibrace.html).  
---|---  
  
Примечание:

Метод позволяет создать новый интерфейс фигурной скобки. После получения нового интерфейса нужно задать параметры фигурной скобки и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
