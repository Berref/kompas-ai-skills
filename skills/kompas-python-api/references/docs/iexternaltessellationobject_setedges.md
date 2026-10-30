# SetEdges - Установить ребра сетки

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationObject ](iexternaltessellationobject.html) > [IExternalTessellationObject - методы ](iexternaltessellationobject_methods.html) |  Scroll [ [ [ ](iexternaltessellationobject_setedgecolors.html "К следующему разделу")](iexternaltessellationobject_methods.html "На уровень выше")](iexternaltessellationobject_setadvancedcolor.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationobject.html)

Синтаксис Automation:

BOOL SetEdges( VARIANT points,

VARIANT edges,

VARIANT colors );

Синтаксис COM:

HRESULT SetEdges( VARIANT points,

VARIANT edges,

VARIANT colors,

BOOL * res );

Входные параметры:

points | \- массив SafeArray VT_ARRAY | VT_R8 координат вершин. Если массив координат уже задан функцией SetTessellation, то нужно передать пустой Variant VT_ARRAY | VT_R8,  
---|---  
edges | \- массив SafeArray типа VT_ARRAY | VT_I4 индексов координат вершин,  
colors | \- массив цветов. Массив может быть не задан - тип VARIANT-а VT_EMPTY. В этом случае используется цвет, заданный функцией SetAdvancedColor. Может быть задан один цвет - тип VARIANT-а VT_I4. Может быть задан цвет для каждой точки - тип VARIANT-а VT_ARRAY | VT_I4.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

1\. Массив ребер может содержать одно или несколько ребер. Каждое ребро может иметь две или более вершины.

2\. Для описания ребер используется последовательность:

[ [count0, i00, i01, ...] - первое ребро

[count1, i10, i11, ...] - второе ребро

...

[counti, ii0, ii1, ...]] - i-тое ребро,

где count0, count1, counti - количество вершин в ребре, i00, i01, i10, i11, ii0, ii1 - индексы координат точек из массива points.

Подразделы:

(отсутствуют)
