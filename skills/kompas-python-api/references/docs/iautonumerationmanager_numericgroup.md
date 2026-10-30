# NumericGroup - Получить группу нумерации по индексу, имени или объекту, входящему в группу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Автонумерация и сортировка объектов ](bb3107129.html) > [Интерфейс IAutoNumerationManager ](iautonumerationmanager.html) > [IAutoNumerationManager - свойства ](iautonumerationmanager_propd.html) |  Scroll [ [ [ ](iautonumerationmanager_numericgroupscount.html "К следующему разделу")](iautonumerationmanager_propd.html "На уровень выше")](iautonumerationmanager_currentnumericgroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iautonumerationmanager.html)

Тип данных: Указатель на интерфейс [INumericGroup.](inumericgroup.html)

Синтаксис Automation:

NumericGroup= Object.NumericGroup( Index ) | Получить свойство([* ](1.html))  
---|---  
NumericGroup= Object.GetNumericGroup( Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_NumericGroup ( Index, &NumericGroups) | Получить свойство  
---|---  
  
Входные параметры:

VARIANT Index | \- Индекс группы в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс объекта, \- VT_BSTR - имя группы.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
