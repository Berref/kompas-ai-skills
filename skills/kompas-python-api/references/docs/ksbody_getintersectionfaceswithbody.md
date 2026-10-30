# GetIntersectionFacesWithBody - Определить взаимодействующие грани при пересечении данного тела с другим

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [Трехмерное тело (Интерфейсы ksBody, Body) ](ksbody.html) > [IBody - методы ](ksbody_methods.html) |  Scroll [ [ [ ](ksbody_issolid.html "К следующему разделу")](ksbody_methods.html "На уровень выше")](ksbody_getgabarit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbody.html)

Синтаксис Automation:

BOOL GetIntersectionFacesWithBody (LPDISPATCH otherBody, VARIANT * intersectionFaces1,

VARIANT * intersectionFaces2,

VARIANT * connectedFaces1,

VARIANT * connectedFaces2);

Синтаксис COM:

BOOL GetIntersectionFacesWithBody (LPBODY otherBody, VARIANT * intersectionFaces1,

VARIANT * intersectionFaces2,

VARIANT * connectedFaces1,

VARIANT * connectedFaces2).

Входные параметры:

otherBody | \- второе тело.  
---|---  
  
Выходные параметры:

intersectionFaces1 | \- пересекаемые грани первого тела,  
---|---  
intersectionFaces2 | \- пересекаемые грани второго тела,  
connectedFaces1 | \- совпадающие грани первого тела,  
connectedFaces2 | \- совпадающие грани второго тела.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Пересекаемые и совпадающие грани возвращаются в VARIANT-е так:

•Если грань одна, то VARIANT заполняется как VT_DISPATH в автоматизации и VT_UNKNOVN в COM.

•Если граней несколько, то VARIANT заполняется как массив SafeArray типа VT_ARRAY | VT_DISPATH в автоматизации и VT_ARRAY | VT_UNKNOVN в COM.

Количество граней в массивах intersectionFaces1 и intersectionFaces2 совпадают и образуют пары, т.е. грань с индексом i из массива intersectionFaces1 пересекается с гранью i из массива intersectionFaces2.

Одна и та же грань может встречаться в массиве несколько раз, если она пересекается с несколькими гранями.

Так же заполняются и массивы connectedFaces1 и connectedFaces2.

Подразделы:

(отсутствуют)
