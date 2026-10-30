# ksDirectionTypeEnum - Типы направлений выдавливания

[API интерфейсов. Версия 7](applicate.html) > [Константы API версии 7 ](cj1473974.html) |  Scroll [ [ [ ](ksdocumentformatenum.html "К следующему разделу")](cj1473974.html "На уровень выше")](ksdimtextformatenum.html "К предыдущему разделу")  
---|---  
  
dtNormal | 0 | прямое направление (для тонкой стенки - наружу)  
---|---|---  
dtReverse | 1 | обратное направление (для тонкой стенки - внутрь)  
dtBoth | 2 | в обе стороны  
dtMiddlePlane | 3 | от средней плоскости  
  
Примечание:

1\. При типе направления dtMiddlePlane в методах SetSideParam и GetSideParam параметр depth интерпретируется как общая глубина выдавливания и задается следующим образом:

SetSideParam(TRUE, etBlind, depth, ...)

2\. В API5 соответствует перечислению [Direction_Type](direction_type.html).

Подразделы:

(отсутствуют)
