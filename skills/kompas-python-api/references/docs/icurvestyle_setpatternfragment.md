# SetPatternFragment - Установить фрагмент по геометрии

[API интерфейсов. Версия 7](applicate.html) > [Работа со стилями ](be1729661.html) > [Интерфейс ICurveStyle ](icurvestyle.html) > [ICurveStyle - методы ](icurvestyle_methods.html) |  Scroll [ [ [ ](ihatchstyle.html "К следующему разделу")](icurvestyle_methods.html "На уровень выше")](icurvestyle_loadpatternfragment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvestyle.html)

Синтаксис Automation:

BOOL SetPatternFragment( long PatternIndex, VARIANT Geom );

Синтаксис COM:

HRESULT SetPatternFragment( long PatternIndex, VARIANT Geom, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

PatternIndex | \- индекс образца,  
---|---  
Geom | \- массив объектов SAFEARRAY VT_DISPATCH - VT_ARRAY | VT_DISPATCH.  
  
Подразделы:

(отсутствуют)
