# MultiLayer - Многослойность

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IInsertionObject ](iinsertionobject.html) > [Интерфейс IInsertionFragment ](iinsertionfragment.html) > [IInsertionFragment - свойства ](iinsertionfragment_props.html) |  Scroll [ [ [ ](iinsertionfragment_scale.html "К следующему разделу")](iinsertionfragment_props.html "На уровень выше")](iinsertionfragment_label.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsertionfragment.html)

Тип данных: BOOL.

Значения свойства:

TRUE | \- многослойный объект,  
---|---  
FALSE | \- однослойный объект.  
  
Синтаксис Automation:

MultiLayer = Object.MultiLayer | Получить свойство ([* ](1.html))  
---|---  
Object.MultiLayer = MultiLayer | Установить свойство ([* ](1.html))  
MultiLayer = Object.GetMultiLayer() | Получить свойство ([**](2.html))  
Object.SetMultiLayer( MultiLayer ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_MultiLayer( &MultiLayer ) | Получить свойство  
---|---  
Object.put_MultiLayer( MultiLayer ) | Установить свойство  
  
Примечание:

Свойство позволяет устанавливать и получать признак многослойности объекта.

Подразделы:

(отсутствуют)
