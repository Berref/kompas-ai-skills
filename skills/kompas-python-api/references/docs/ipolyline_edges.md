# Edges - Массив ребер 3D ломаной

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IPolyLine ](ipolyline.html) > [IPolyLine - свойства ](ipolyline_props.html) |  Scroll [ [ [ ](ipolyline_vertexcount.html "К следующему разделу")](ipolyline_props.html "На уровень выше")](ipolyline_closed.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipolyline.html)

Тип данных: VARIANT

Синтаксис Automation:

Edges = iObject.Edges; | Получить свойство ([* ](1.html))  
---|---  
iObject.Edges = Edges; | Установить свойство ([* ](1.html))  
Edges = iObject.GetEdges(); | Получить свойство ([**](2.html))  
iObject.SetEdges( Edges ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Edges( &Edges ); | Получить свойство  
---|---  
iObject->put_Edges( Edges ); | Установить свойство  
  
Примечание.

Свойство позволяет получать массив ребер 3D ломаной. Массив возвращается в виде массива SAFEARRAY рёбер LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
