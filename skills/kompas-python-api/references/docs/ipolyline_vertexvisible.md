# VertexVisible - Видимость свободных вершин 3D ломаной

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IPolyLine ](ipolyline.html) > [IPolyLine - свойства ](ipolyline_props.html) |  Scroll [ [ [ ](ipolyline_methods.html "К следующему разделу")](ipolyline_props.html "На уровень выше")](ipolyline_vertexparamsarray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipolyline.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- вершины видимые,  
---|---  
FALSE | \- вершины невидимые.  
  
Синтаксис Automation:

VertexVisible = iObject.VertexVisible; | Получить свойство ([* ](1.html))  
---|---  
iObject.VertexVisible = VertexVisible; | Установить свойство ([* ](1.html))  
VertexVisible = iObject.GetVertexVisible(); | Получить свойство ([**](2.html))  
iObject.SetVertexVisible(VertexVisible); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VertexVisible (&VertexVisible) | Получить свойство  
---|---  
iObject->put_VertexVisible (VertexVisible) | Установить свойство  
  
Примечание.

Свойство позволяет получить/установить видимость свободных вершин 3D ломаной.

Подразделы:

(отсутствуют)
