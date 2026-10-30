# MultiSpline3D - Возвращает элемент, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IMultiSplines3D](imultisplines3d.html) > [IMultiSplines3D - свойства](imultisplines3d_propers.html) |  Scroll [ [ [ ](imultisplines3d_methods.html "К следующему разделу")](imultisplines3d_propers.html "На уровень выше")](imultisplines3d_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultisplines3d.html)

Тип данных: Указатель на интерфейс [IMultiSpline3D](imultispline3d.html).

Синтаксис Automation:

MultiSpline3D = Object.MultiSpline3D( Index ) | Получить свойство ([* ](1.html))  
---|---  
MultiSpline3D = Object.GetMultiSpline3D( Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_MultiSpline3D( Index, &MultiSpline3D ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- VT_BSTR - имя объекта, VT_I4 - индекс объекта.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться имя объекта в дереве, индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
