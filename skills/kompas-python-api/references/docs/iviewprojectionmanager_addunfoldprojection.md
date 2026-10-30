# AddUnfoldProjection - Добавить проекцию отображения - развертка

[API интерфейсов. Версия 7](applicate.html) > [Управление изображением модели](view_managment.html) > [Интерфейс IViewProjectionManager](iviewprojectionmanager.html) > [IViewProjectionManager - методы](iviewprojectionmanager_methods.html) |  Scroll [ [ [ ](iviewprojectionmanager_orientationnormalto.html "К следующему разделу")](iviewprojectionmanager_methods.html "На уровень выше")](iviewprojectionmanager_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](iviewprojectionmanager.html)

Синтаксис Automation:

LPDISPATCH AddUnfoldProjection( VARIANT place );

Синтаксис COM:

HRESULT AddUnfoldProjection( VARIANT place, IViewProjection7 * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс проекции [IViewProjection7](iviewprojection7.html).  
---|---  
  
Входные параметры:

Place | \- динамический массив SAFEARRAY double (VT_ARRAY | VT_R8),  
---|---  
  
Примечания:

В массиве должны лежать 16 элементов, которые представляют собой матрицу размера 4х4.

Подразделы:

(отсутствуют)
