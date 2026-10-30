# ResultBodies - Массив тел (SAFEARRAY)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IFeature7 ](ifeature7.html) > [IFeature7 - свойства ](ifeature7_props.html) |  Scroll [ [ [ ](ifeature7_state.html "К следующему разделу")](ifeature7_props.html "На уровень выше")](ifeature7_ownerfeature.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeature7.html)

Тип данных: VARIANT

Значения свойства:

Массив SafeArray типа VT_ARRAY | VT_DISPATCH.  
---  
  
Синтаксис Automation:

ResultBodies = iObject.ResultBodies; | Получить свойство ([* ](1.html))  
---|---  
ResultBodies = iObject.GetResultBodies(); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ResultBodies( &ResultBodies ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Свойство позволяет получить массив SAFEARRAY всех тел, входящих в дерево. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
