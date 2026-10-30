# Item - Получить объект по индексу или строковому обозначению в группе (зависит от правил нумерации)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Автонумерация и сортировка объектов ](bb3107129.html) > [Интерфейс INumericGroup ](inumericgroup.html) > [INumericGroup - свойства ](inumericgroup_props.html) |  Scroll [ [ [ ](inumericgroup_issystem.html "К следующему разделу")](inumericgroup_props.html "На уровень выше")](inumericgroup_count.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inumericgroup.html)

Тип данных: Указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

Item = Object.Item( Index ) | Получить свойство([* ](1.html))  
---|---  
Item = Object.GetItem(Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Item( Index, &Item ) | Получить свойство  
---|---  
  
Входные параметры:

VARIANT Index | \- Индекс объекта в группе. Поддерживаются следующие типы: \- VT_I4 - индекс объекта, \- VT_BSTR - строковое обозначение объекта в группе.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
