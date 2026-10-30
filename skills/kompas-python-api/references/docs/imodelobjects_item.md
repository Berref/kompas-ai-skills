# Item - Объект, заданный по индексу или по имени

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) |  Scroll [ [ [ ](iarcs3d.html "К следующему разделу")](imodelobjects_props.html "На уровень выше")](imodelobjects_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodelobjects.html)

Тип данных: указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

Item = iObject.Item ( Index) | Получить свойство ([* ](1.html))  
---|---  
Item = iObject.GetItem ( Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Item( Index, &Item ) | Получить свойство  
---|---  
  
Входные параметры:

Index ( Variant) | \- VT_BSTR - имя объекта, VT_I4 - индекс объекта.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
