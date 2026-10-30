# Performance - Объект является исполнением

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObject ](ispecificationbaseobject.html) > [ISpecificationBaseObject - свойства ](ispecificationbaseobject_props.html) |  Scroll [ [ [ ](ispecificationbaseobject_spcused.html "К следующему разделу")](ispecificationbaseobject_props.html "На уровень выше")](ispecificationbaseobject_isgroupobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobject.html)

Тип данных: BOOL

Синтаксис Automation:

Performance = iObject.Performance | Получить свойство ([* ](1.html))  
---|---  
iObject.Performance = Performance | Установить свойство ([* ](1.html))  
Performance = iObject.GetPerformance() | Получить свойство ([**](2.html))  
iObject.SetPerformance( Performance ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Performance( &Performance ) | Получить свойство  
---|---  
iObject->put_Performance( Performance ) | Установить свойство  
  
Значения свойства:

TRUE | \- Объект является исполнением,  
---|---  
FALSE | \- Объект не является исполнением.  
  
Примечание:

Объекты спецификации, являющиеся исполнением, отличаются от простого объекта наличием суффикса исполнения. Их обозначение должно заканчиваться суффиксом с номером исполнения. Например: -02, -03, -10.

Отображение объектов, являющимися исполнениями зависит от настроек стиля спецификации.

Подразделы:

(отсутствуют)
