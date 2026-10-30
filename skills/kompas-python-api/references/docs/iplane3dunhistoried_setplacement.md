# SetPlacement - Установить положение плоскости

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IPlane3D ](iplane3d.html) > [IPlane3D - свойства ](iplane3d_props.html) > [Интерфейс IPlane3DTangentToFace ](iplane3dtangenttoface.html) > [ Интерфейс IPlane3DUnhistoried](iplane3dunhistoried.html) > [IPlane3DUnhistoried - методы](iplane3dunhistoried_methods.html) |  Scroll [ [ [ ](irestoredsurface.html "К следующему разделу")](iplane3dunhistoried_methods.html "На уровень выше")](iplane3dunhistoried_getplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplane3dunhistoried.html)

Синтаксис Automation:

BOOL SetPlacement( VARIANT Place );

Синтаксис COM:

HRESULT SetPlacement( VARIANT Place, BOOL * Result );

Входные параметры

Place - Матрица, задающая положение плоскости.

Примечание:

Элементы матрицы передаются в виде одномерного массива из 16 элементов SafeAttray типа (VT_ARRAY | VT_R8).

Матрица имеет размер 4х4.

Подразделы:

(отсутствуют)
