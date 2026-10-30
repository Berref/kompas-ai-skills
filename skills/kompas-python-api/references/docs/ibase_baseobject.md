# BaseObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс IBase ](ibase.html) > [IBase - свойства ](ibase_props.html) |  Scroll [ [ [ ](ibase_branchx.html "К следующему разделу")](ibase_props.html "На уровень выше")](ibase_autosorted.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibase.html)

Тип данных: указатель на интерфейс [IDrawingObject](idrawingobject.html)

Синтаксис Automation:

BaseObject = Object.BaseObject | Получить свойство([* ](1.html))  
---|---  
Object.BaseObject = BaseObject | Установить свойство ([* ](1.html))  
BaseObject = Object.GetBaseObject() | Получить свойство ([**](2.html))  
Object.SetBaseObject( BaseObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseObject( &BaseObject ) | Получить свойство  
---|---  
Object.put_BaseObject( BaseObject ) | Установить свойство  
  
Примечание:

После указания базового объекта все устанавливаемые объекту координаты положения знака на поверхности будут проецироваться на базовый объект или его продолжение.

Подразделы:

(отсутствуют)
