# DrawPosition - Показывать позицию

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObject ](ispecificationbaseobject.html) > [ISpecificationBaseObject - свойства ](ispecificationbaseobject_props.html) |  Scroll [ [ [ ](ispecificationbaseobject_editsourceobject.html "К следующему разделу")](ispecificationbaseobject_props.html "На уровень выше")](ispecificationbaseobject_draw.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobject.html)

Тип данных: BOOL

Синтаксис Automation:

DrawPosition = iObject.DrawPosition | Получить свойство ([* ](1.html))  
---|---  
iObject.DrawPosition = DrawPosition | Установить свойство ([* ](1.html))  
DrawPosition = iObject.GetDrawPosition() | Получить свойство ([**](2.html))  
iObject.SetDrawPosition( DrawPosition ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DrawPosition( &DrawPosition ) | Получить свойство  
---|---  
iObject->put_DrawPosition( DrawPosition ) | Установить свойство  
  
Значения свойства:

TRUE | \- в колонке "Позиция" объекта отображается ее содержимое,  
---|---  
FALSE | \- колонка "Позиция" будет показываться пустой.  
  
Примечание:

Свойство позволяет скрыть номер позиции объекта в спецификации.

Подразделы:

(отсутствуют)
