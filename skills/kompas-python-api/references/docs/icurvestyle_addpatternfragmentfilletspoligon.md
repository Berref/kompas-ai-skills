# AddPatternFragmentFilletsPoligon - Добавить заливку, ограниченную ломаной, заданной полигоном точек

[API интерфейсов. Версия 7](applicate.html) > [Работа со стилями ](be1729661.html) > [Интерфейс ICurveStyle ](icurvestyle.html) > [ICurveStyle - методы ](icurvestyle_methods.html) |  Scroll [ [ [ ](icurvestyle_clearpatterns.html "К следующему разделу")](icurvestyle_methods.html "На уровень выше")](icurvestyle_addpatternfragmentpoligon.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvestyle.html)

Синтаксис Automation:

BOOL AddPatternFragmentFilletsPoligon( long PatternIndex, VARIANT Points );

Синтаксис COM:

HRESULT AddPatternFragmentFilletsPoligon( long PatternIndex, VARIANT Points, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

PatternIndex | \- индекс параметров,  
---|---  
Points | \- безопасный массив 2D точек SAFEARRAY VT_ARRAY | VT_R8, задающих полигон границы заливки.  
  
Подразделы:

(отсутствуют)
