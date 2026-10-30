# VectorOrientation - Направление вектора в точке сопряжения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - свойства ](ispline3d_props.html) |  Scroll [ [ [ ](ispline3d_methods.html "К следующему разделу")](ispline3d_props.html "На уровень выше")](ispline3d_vectordirectionobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Тип данных: BOOL

Синтаксис Automation:

VectorOrientation = Object.VectorOrientation( PointIndex, VectorIndex ); | Получить свойство ([* ](1.html))  
---|---  
Object.VectorOrientation( PointIndex, VectorIndex ) = VectorOrientation; | Установить свойство ([* ](1.html))  
VectorOrientation = Object.GetVectorOrientation( PointIndex, VectorIndex ); | Получить свойство ([**](2.html))  
Object.SetVectorOrientation( PointIndex, VectorIndex, VectorOrientation ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_VectorOrientation( PointIndex, VectorIndex, &VectorOrientation ) | Получить свойство  
---|---  
Object.put_VectorOrientation( PointIndex, VectorIndex, VectorOrientation ) | Установить свойство  
  
Входные параметры:

long PointIndex | \- индекс точки.  
---|---  
VectorIndex | \- cпособ создания сопряжения в заданной вершине сплайна из перечисления [ksTransitionVectorIndexEnum](kstransitionvectorindexenum.html).  
  
В Компас 18.1 удалены свойства:

•SplineTangent

•TangentCurve

•VectorLenght

Подразделы:

(отсутствуют)
