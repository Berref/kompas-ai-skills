# BaseObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IView1 ](iview1.html) > [IView1 - свойства ](iview1_props.html) |  Scroll [ [ [ ](iview1_crossed.html "К следующему разделу")](iview1_props.html "На уровень выше")](iview1_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview1.html)

Тип данных: Указатель на интерфейс [IDrawingObject](idrawingobject.html)

Синтаксис Automation:

BaseObject = Object.BaseObject | Получить свойство ([* ](1.html))  
---|---  
Object.BaseObject = BaseObject | Установить свойство ([* ](1.html))  
BaseObject = Object.GetBaseObject() | Получить свойство ([**](2.html))  
Object.SetBaseObject( BaseObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseObject( &BaseObject ) | Получить свойство  
---|---  
Object.put_BaseObject( BaseObject ) | Установить свойство  
  
Примечание:

В зависимости от типа ассоциативного вида нужно указать вспомогательный опорный объект.

Опорный объект требуется при создании следующих видов:

•Вид по стрелке - требуется объект стрелка взгляда.

•Выносной вид - требуется объект обозначение выносного элемента.

•Вид разреза/сечения - требуется объект линия разреза.

Подразделы:

(отсутствуют)
