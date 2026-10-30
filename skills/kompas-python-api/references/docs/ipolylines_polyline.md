# PolyLine - Пространственная ломаная, заданная по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IPolyLines ](ipolylines.html) > [IPolyLines - свойства ](ipolylines_props.html) |  Scroll [ [ [ ](ipolylines_methods.html "К следующему разделу")](ipolylines_props.html "На уровень выше")](ipolylines_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipolylines.html)

Тип данных: указатель на интерфейс [IPolyLine](ipolyline.html)

Синтаксис Automation:

PolyLine = iObject.PolyLine( Index ); | Получить свойство ([* ](1.html))  
---|---  
PolyLine = iObject.GetPolyLine( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_PolyLine( Index, &PolyLine ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- VT_BSTR - имя объекта, VT_I4 - индекс объекта.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
