# SelectedObjects - Получить массив выделенных объектов в виде SAFEARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Подсветка и выделение объектов ](ba1952824.html) > [Интерфейс ISelectionManager ](iselectionmanager.html) > [ISelectionManager - свойства ](iselectionmanager_props.html) |  Scroll [ [ [ ](iselectionmanager_methods.html "К следующему разделу")](iselectionmanager_props.html "На уровень выше")](iselectionmanager_props.html "К предыдущему разделу")  
---|---  
  
Тип данных: VARIANT типа VT_ARRAY | VT_DISPATCH

[Интерфейс...](iselectionmanager.html)

Синтаксис Automation:

SelectedObjects = Object.SelectedObjects | Получить свойство ([* ](1.html))  
---|---  
SelectedObjects = Object.GetSelectedObjects() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SelectedObjects( &SelectedObjects ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получать массив выделенных объектов. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
