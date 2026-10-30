# VertexParamsArray - Массив параметров вершин в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - свойства ](ispline3d_props.html) |  Scroll [ [ [ ](ispline3d_vectordirectionobject.html "К следующему разделу")](ispline3d_props.html "На уровень выше")](ispline3d_vertexparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Тип данных: VARIANT

Значения свойства:

Массив SafeArray типа VT_ARRAY | VT_DISPATCH. |   
---|---  
  
Синтаксис Automation:

VertexParamsArray = iObject.VertexParamsArray; | Получить свойство ([* ](1.html))  
---|---  
VertexParamsArray = iObject.GetVertexParamsArray(); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VertexParamsArray( &VertexParamsArray ) | Получить свойство  
---|---  
  
Примечание.

1\. Свойство доступно только для чтения.

2\. Свойство позволяет получить массив SAFEARRAY параметров всех вершин. Это массив VT_DISPATCH, которые можно преобразовать в интерфейсы ICurveVertexParam.

Подразделы:

(отсутствуют)
