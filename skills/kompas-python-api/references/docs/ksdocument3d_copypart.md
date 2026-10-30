# CopyPart - Создать копию заданного компонента с заданным положением

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_create.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_componentpositioner.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

LPDISPATCH CopyPart (LPDISPATCH sourcePart, LPDISPATCH newPlacement);

Синтаксис COM:

LPPART CopyPart (LPPART sourcePart, LPPLACEMENT newPlacement);

Входные параметры:

sourcePart | \- указатель на интерфейс исходного компонента [ksPart](kspart.html) или [IPart](kspart.html), подлежащего копированию,  
---|---  
newPlacement | \- указатель на интерфейс положения создаваемой копии [ksPlacement](ksplacement.html) или [IPlacement](ksplacement.html).  
  
Возвращаемое значение:

| \- указатель на интерфейс компонента [ksPart](kspart.html) или [IPart](kspart.html).  
---|---  
  
Примечание:

Если не задано положение копии компонента, она создается в начале координат.

Подразделы:

(отсутствуют)
