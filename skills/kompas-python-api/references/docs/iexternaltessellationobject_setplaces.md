# SetPlaces - Установить матрицы для отрисовки объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationObject ](iexternaltessellationobject.html) > [IExternalTessellationObject - методы ](iexternaltessellationobject_methods.html) |  Scroll [ [ [ ](iexternaltessellationobject_settessellation.html "К следующему разделу")](iexternaltessellationobject_methods.html "На уровень выше")](iexternaltessellationobject_setfacetmode.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationobject.html)

Синтаксис Automation:

BOOL SetPlaces( VARIANT places );

Синтаксис COM:

HRESULT SetPlaces( VARIANT places, BOOL * res );

Входные параметры:

places | \- массив SafeArray типа VT_ARRAY | VT_R8. В массиве может быть передана одна или несколько матриц размером 4*4. Если передано несколько матриц, объект будет отрисован столько раз, сколько передано матриц. Используется для многократной отрисовки одинаковых объектов. Матрицы передаются в виде одномерного массива.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
