# Direction_Type - Типы направлений выдавливания

[Структуры параметров и константы](3d_define.html) > [Константы ](bk1803360.html) > [Прочие ](bk1944694.html) > [3D ](bk1944689.html) |  Scroll [ [ [ ](kscontour3dbuildingtypetypeenum.html "К следующему разделу")](bk1944689.html "На уровень выше")](kslinebuildingtype.html "К предыдущему разделу")  
---|---  
  
dtNormal | 0 | прямое направление (для тонкой стенки - наружу)  
---|---|---  
dtReverse | 1 | обратное направление (для тонкой стенки - внутрь)  
dtBoth | 2 | в обе стороны  
dtMiddlePlane | 3 | от средней плоскости  
  
Примечание:

1\. При типе направления dtMiddlePlane в методах SetSideParam и GetSideParam параметр depth интерпретируется как общая глубина выдавливания и задается следующим образом:

SetSideParam(TRUE, etBlind, depth,...)

2\. В API7 соответствует перечислению [ksDirectionTypeEnum](ksdirectiontypeenum.html).

Подразделы:

(отсутствуют)
