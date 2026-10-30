# MakeEncloseContours - Вернуть временную группу контуров, охватывающих точку

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IDrawingContours ](idrawingcontours.html) > [IDrawingContours - методы ](idrawingcontours_methods.html) |  Scroll [ [ [ ](idrawingcontours_makeouterscontours.html "К следующему разделу")](idrawingcontours_methods.html "На уровень выше")](idrawingcontours_addbooleanresultcontours.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingcontours.html)

Синтаксис Automation:

LPDISPATCH MakeEncloseContours( VARIANT Objects, double X, double Y, BOOL ForHatch );

Синтаксис COM:

HRESULT MakeEncloseContours( VARIANT Objects, double X, double Y, BOOL ForHatch, IDrawingGroup * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [IDrawingGroup](idrawinggroup.html).  
---|---  
  
Входные параметры:

Objects | \- cписок объектов в виде SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH,  
---|---  
X, Y | \- точка внутри контура,  
ForHatch | \- признак создания контура для штриховки.  
  
Примечание:

Если список объектов не задан для построения контура, используются все объекты вида:

•При cоздании контуров для штриховки используются объекты со стилем основная и утолщенная, объекты других стилей не учитываются.

•При cоздании простого контура с использованием любых стилей линий.

Версия КОМПАС v22

Подразделы:

(отсутствуют)
