# SetTessellation - Установить параметры триангуляции

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationObject ](iexternaltessellationobject.html) > [IExternalTessellationObject - методы ](iexternaltessellationobject_methods.html) |  Scroll [ [ [ ](iexternaltessellationobject_settextureimage.html "К следующему разделу")](iexternaltessellationobject_methods.html "На уровень выше")](iexternaltessellationobject_setplaces.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationobject.html)

Синтаксис Automation:

BOOL SetTessellation( VARIANT points,

VARIANT indexes,

VARIANT normals,

VARIANT colors );

Синтаксис COM:

HRESULT SetTessellation( VARIANT points,

VARIANT indexes,

VARIANT normals,

VARIANT colors,

BOOL * Result );

Входные параметры:

points | \- массив SafeArray VT_ARRAY | VT_R8 координат точек триангуляционной сетки; координаты в массиве лежат в последовательности x0, y0, z0, x1, y1, z1, ... xi, yi, zi,  
---|---  
indexes | \- массив SafeArray VT_ARRAY | VT_I4 индексов вершин треугольников; по индексу из массива indexes достаются координаты вершин из массива points,  
normals | \- массив SafeArray VT_ARRAY | VT_R8 единичных векторов нормалей для вершин. Если направление нормалей во всех вершинах совпадают, можно добавить направление только одной нормали. Иначе количество нормалей должно быть равно количеству точек в массиве points,  
colors | \- массив цветов в точках. Массив может быть не задан - тип VARIANT-а VT_EMPTY. В этом случае используется цвет, заданный функцией SetAdvancedColor. Может быть задан один цвет - тип VARIANT-а VT_I4. Может быть задан цвет для каждой точки - тип VARIANT-а VT_ARRAY | VT_I4.  
  
Подразделы:

(отсутствуют)
