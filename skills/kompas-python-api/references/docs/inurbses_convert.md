# Convert - Преобразовать кривую в NURBS-кривую и добавить в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс INurbses ](inurbses.html) > [INurbses - методы ](inurbses_methods.html) |  Scroll [ [ [ ](inurbses_pickobjects.html "К следующему разделу")](inurbses_methods.html "На уровень выше")](inurbses_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbses.html)

Синтаксис Automation:

LPDISPATCH Convert( LPDISPATCH * Curve );

Синтаксис COM:

HRESULT Convert( IDrawingObject * Curve,

INurbs ** Result);

Входные параметры:

Curve | \- указатель на интерфейс кривой, которую надо преобразовать в NURBS.  
---|---  
  
Возвращаемое значение:

| \- Указатель на интерфейс NURBS-кривой [INurbs](inurbs.html).  
---|---  
  
Подразделы:

(отсутствуют)
