# BaseObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - свойства ](iassociationview_props.html) |  Scroll [ [ [ ](iassociationview_baseview.html "К следующему разделу")](iassociationview_props.html "На уровень выше")](iassociationview_isassociationobjectsvisible.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Тип данных: указатель на интерфейс [IDrawingObject](idrawingobject.html)

Синтаксис Automation:

BaseObject = Object.BaseObject | Получить свойство ([* ](1.html))  
---|---  
Object.BaseObject = BaseObject | Установить свойство ([* ](1.html))  
BaseObject = Object.GetBaseObject() | Получить свойство ([**](2.html))  
Object.SetBaseObject( BaseObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseObject( &BaseObject ) | Получить свойство,  
---|---  
Object.put_BaseObject( BaseObject ) | Установить свойство.  
  
Примечание:

В зависимости от типа ассоциативного вида нужно указать вспомогательный опорный объект.

Опорный объект требуется при создании следующих видов:

•Вид по стрелке - требуется объект Стрелка взгляда,

•Выносной вид - требуется объект Обозначение выносного элемента,

•Вид разрез/сечение - требуется объект Линия разреза.

Подразделы:

(отсутствуют)
