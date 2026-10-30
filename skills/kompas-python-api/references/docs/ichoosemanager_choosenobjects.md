# ChoosenObjects - Получить массив выделенных объектов в виде SAFEARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Подсветка и выделение объектов ](ba1952824.html) > [Интерфейс IChooseManager ](ichoosemanager.html) > [IChooseManager - свойства ](ichoosemanager_props.html) |  Scroll [ [ [ ](ichoosemanager_currentmanagertype.html "К следующему разделу")](ichoosemanager_props.html "На уровень выше")](ichoosemanager_choosecolor.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ichoosemanager.html)

Тип данных: VARIANT типа VT_ARRAY | VT_DISPATCH

Синтаксис Automation:

ChoosenObjects = Object.ChoosenObjects | Получить свойство ([* ](1.html))  
---|---  
ChoosenObjects = Object.GetChoosenObjects() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ChoosenObjects( &ChoosenObjects ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получать массив выделенных объектов. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
