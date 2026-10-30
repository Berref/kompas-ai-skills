# AddPatternFragmentPoligon - Добавить полигон точек

[API интерфейсов. Версия 7](applicate.html) > [Работа со стилями ](be1729661.html) > [Интерфейс ICurveStyle ](icurvestyle.html) > [ICurveStyle - методы ](icurvestyle_methods.html) |  Scroll [ [ [ ](icurvestyle_addpatternfragmentfilletspoligon.html "К следующему разделу")](icurvestyle_methods.html "На уровень выше")](icurvestyle_addpattern.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvestyle.html)

Синтаксис Automation:

BOOL AddPatternFragmentPoligon( long PatternIndex, VARIANT Points );

Синтаксис COM:

HRESULT AddPatternFragmentPoligon( long PatternIndex, VARIANT Points, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

PatternIndex | \- индекс параметров,  
---|---  
Points | \- безопасный массив 2D точек SAFEARRAY VT_ARRAY | VT_R8.  
  
Подразделы:

(отсутствуют)
