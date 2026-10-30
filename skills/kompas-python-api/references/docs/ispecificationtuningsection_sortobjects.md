# SortObjects - Сортировать объекты

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuningSection ](ispecificationtuningsection.html) > [ISpecificationTuningSection - свойства ](ispecificationtuningsection_props.html) |  Scroll [ [ [ ](ispecificationtuningsection_subsectionon.html "К следующему разделу")](ispecificationtuningsection_props.html "На уровень выше")](ispecificationtuningsection_showdocumentcode.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuningsection.html)

Тип данных: BOOL

Синтаксис Automation:

SortObjects = iObject.SortObjects | Получить свойство ([* ](1.html))  
---|---  
iObject.SortObjects = SortObjects | Установить свойство ([* ](1.html))  
SortObjects = iObject.GetSortObjects() | Получить свойство ([**](2.html))  
iObject.SetSortObjects (SortObjects) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SortObjects (&SortObjects) | Получить свойство  
---|---  
iObject->put_SortObjects (SortObjects) | Установить свойство  
  
Значения свойства:

TRUE | \- сортировка объектов внутри раздела производится по предусмотренным стандартом правилам,  
---|---  
FALSE | \- в разделе сортировка объектов не производится.  
  
Примечание:

Позволяет включать и отключать автоматическую сортировку объектов в разделе. Если сортировка выключена, объекты будут добавляться в конец раздела и их можно будет перемещать вверх или вниз.

Подразделы:

(отсутствуют)
