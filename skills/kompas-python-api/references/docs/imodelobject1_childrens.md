# Childrens - Потомки объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [3D-объект ](bc2229904.html) > [Интерфейс IModelObject1 ](imodelobject1.html) > [IModelObject1 - свойства ](imodelobject1_props.html) |  Scroll [ [ [ ](imodelobject1_connectedwithinitialembodiment.html "К следующему разделу")](imodelobject1_props.html "На уровень выше")](imodelobject1_bodyparts.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodelobject1.html)

Тип данных: VARIANT

Синтаксис Automation:

Childrens = Object.Childrens( RelType ); | Получить свойство ([* ](1.html))  
---|---  
Childrens = Object.GetChildrens( RelType ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Childrens( RelType, &Childrens ) | Получить свойство  
---|---  
  
Параметры:

ksRelationTypeEnum RelType | \- тип родственных отношений.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Свойство возвращает массив VT_ARRAY | VT_DISPATCH объектов-потомков данного объекта.

Подразделы:

(отсутствуют)
