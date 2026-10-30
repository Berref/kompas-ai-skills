# VectorDirectionObject - Направляющий объект вектора в точке сопряжения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - свойства ](ispline3d_props.html) |  Scroll [ [ [ ](ispline3d_vectororientation.html "К следующему разделу")](ispline3d_props.html "На уровень выше")](ispline3d_vertexparamsarray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html).

Синтаксис Automation:

VectorDirectionObject = Object.VectorDirectionObject( PointIndex, VectorIndex ); | Получить свойство ([* ](1.html))  
---|---  
Object.VectorDirectionObject( PointIndex, VectorIndex ) = VectorDirectionObject; | Установить свойство ([* ](1.html))  
VectorDirectionObject = Object.GetVectorDirectionObject( PointIndex, VectorIndex ); | Получить свойство ([**](2.html))  
Object.SetVectorDirectionObject( PointIndex, VectorIndex, VectorDirectionObject ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_VectorDirectionObject( PointIndex, VectorIndex, &VectorDirectionObject ) | Получить свойство  
---|---  
Object.put_VectorDirectionObject( PointIndex, VectorIndex, VectorDirectionObject ) | Установить свойство  
  
Входные параметры:

long PointIndex | \- индекс точки.  
---|---  
VectorIndex | \- cпособ создания сопряжения в заданной вершине сплайна из перечисления [ksTransitionVectorIndexEnum](kstransitionvectorindexenum.html).  
  
Подразделы:

(отсутствуют)
